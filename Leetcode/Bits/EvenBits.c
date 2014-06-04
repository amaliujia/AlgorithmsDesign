/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    int result = 0x55;
    result <<= 8;
    result |= 0x55;
    result <<= 8;
    result |= 0x55;
    result <<= 8;
    result |= 0x55;
    return result;
}
