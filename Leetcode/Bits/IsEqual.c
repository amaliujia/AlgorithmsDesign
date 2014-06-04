/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
/*
 * xor means noting in common, x ^ y == 0 means x is equal to y. Then neg it, we can get answer.
 */
    return !(x ^ y);
}
