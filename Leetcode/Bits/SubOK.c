/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
    int negy = ~y + 1;
    int sum = x + negy;
    return !( ((x ^ y) >> 0x1f) & ((sum ^ x) >> 0x1f) );
}
