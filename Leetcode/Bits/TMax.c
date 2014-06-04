/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
/*
 *  if we need 0111, we can use 1000 - 1 to get the anwser.
 */
    int result = 0x01;
    result <<= 0x1f;
    return result + ~0x00;
}
