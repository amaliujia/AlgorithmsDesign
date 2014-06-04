/*byteswap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    int noffset = n << 3;
    int moffset = m << 3;
    int nr = (x >> noffset) & 0xff;
    int mr = (x >> moffset) & 0xff;
    x = x & (~(0xff << noffset));
    x = x | (mr << noffset);
    x = x & (~(0xff << moffset));
    x = x | (nr << moffset);
    return x;
}
