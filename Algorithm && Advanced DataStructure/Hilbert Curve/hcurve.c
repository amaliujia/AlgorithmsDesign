#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdarg.h>


typedef struct coordinate{
  int x;
  int y;
}cor;

void rotate(int n, int tx, int ty, int *x, int *y) {
  int t;
  if (ty == 0) {
    if(tx == 1) {
      *x = n - 1 - *x;
      *y = n - 1 - *y;
    }

    t = *x;
    *x = *y;
    *y = t;
  }
}

void order2coordinate(int n, int order, int *x, int *y) {
    int tx, ty, s, t = order;
    cor c;

    *x = 0;
    *y = 0;

    for (s = 1; s < n; s *= 2) {
      tx = 1 & (t / 2);
      ty = 1 & (t ^ tx);

      rotate(s, tx, ty, x, y);
      *x += s * tx;
      *y += s * ty;
      t /= 4;
    }
}

/*--------Place holder for q2-------*/
int main(int argc, char ** argv){
  char c;
	int order_of_curve, total_position = 1, n = 1;
  FILE *output;
  int x, y, i;

	while ((c = getopt(argc, argv, "n:")) != EOF) {
		switch (c) {
			case 'n':
				order_of_curve = atoi(optarg);
				break;
			default:
				break;
		}
	}

  for (i = 0; i < order_of_curve; i++) {
		total_position *= 4;
    n *= 2;
	}

  output = fopen("hpoint.dat", "w");
  for (i = 0; i < total_position; i++) {
      order2coordinate(n, i, &x, &y);
      fprintf(output, "%d %d\n", x, y);
  }
  fclose(output);

  return 0;
}
