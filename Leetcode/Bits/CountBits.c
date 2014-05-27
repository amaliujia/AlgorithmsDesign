// Divide and Conque, O(logn)time
// Count ones of a integer in banary 
int howManyBits(int x) {
    int inter, inter2, inter3;

    int mask = 0x55;
    mask <<= 8;
    mask |= 0x55;
    mask <<= 8;
    mask |= 0x55;
    mask <<= 8;
    mask |= 0x55;

    inter = x & mask;
    inter2 = (x >> 0x01) & mask;
    inter3 = inter + inter2;

    mask = 0x33;
    mask <<= 8;
    mask |= 0x33;
    mask <<= 8;
    mask |= 0x33;
    mask <<= 8;
    mask |= 0x33;

    inter = inter3 & mask;
    inter2 = (inter3 >> 0x02) & mask;
    inter3 = inter + inter2;

    mask = 0x0f;
    mask <<= 8;
    mask |= 0x0f;
    mask <<= 8;
    mask |= 0x0f;
    mask <<= 8;
    mask |= 0x0f;

    inter = inter3 & mask;
    inter2 = (inter3 >> 0x04) & mask;
    inter3 = inter + inter2;

    mask = 0x00;
    mask <<= 16;
    mask |= 0xff;
    mask <<= 16;
    mask |= 0xff;

    inter = inter3 & mask;
    inter2 = (inter3 >> 0x08) & mask;
    inter3 = inter + inter2;

    mask = 0x00;
    mask |= 0xff;
    mask <<= 8;
    mask |=0xff;

    inter = inter3 & mask;
    inter2 = (inter3 >> 16) & mask;
    inter3 = inter + inter2;

    return inter3;
}
