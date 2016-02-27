#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Postion {
		size_t ret_x;
		size_t ret_y;
} Pos;

Pos convertZValue2Pos(int order_of_curve, int z_value) {
	size_t total_position = 1;
	size_t ret_z_value = 0;
	size_t ret_x = 0, ret_y = 0;
	Pos ret;
	int i;

	for (i = 0; i < order_of_curve; i++) {
		total_position *= 4;
	}
	ret_z_value = total_position - 1 - z_value;

	for (i = sizeof(size_t) * 8 - 1; i >= 0; i--) {
		if (i % 2 == 0) {
			ret_y <<= 1;
			ret_y |= ((ret_z_value >> i) & 0x1);
		} else {
			ret_x <<= 1;
			ret_x |= ((ret_z_value >> i) & 0x1);
		}
	}

	ret.ret_x = ret_x;
	ret.ret_y = ret_y;
	return ret;
}

int main(int argc, char ** argv){
	char c;
	int order_of_curve, z_value;
	Pos ret;

	while ((c = getopt(argc, argv, "n:i:")) != EOF) {
		switch (c) {
			case 'n':
				order_of_curve = atoi(optarg);
				break;
			case 'i':
				z_value = atoi(optarg);
				break;
			default:
				break;
		}
	}

	ret = convertZValue2Pos(order_of_curve, z_value);
	printf("%zu %zu\n", ret.ret_x, ret.ret_y);
  return 0;
}
