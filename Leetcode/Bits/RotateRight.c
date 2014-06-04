/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
    int xright = x >> n;
    int ncom = 0x21 + ~n;
    int xleft = x << ncom;
    int mask = ~(((1 << n) + ~0x00) << ncom);
    xright &= mask;
    return xleft | xright;
}
