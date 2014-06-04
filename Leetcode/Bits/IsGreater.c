/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    int xsign = (x >> 0x1f) & 0x01;
    int ysign = (y >> 0x1f) & 0x01;
    int var1 = ~(x + (~y + 1)) + 1;
    int var2 = ((var1 >> 0x1f) & 0x01) & (var1 >> 0x1f);
    return ((!xsign) & ysign) | (var2 & (!(xsign ^ ysign)));
}
