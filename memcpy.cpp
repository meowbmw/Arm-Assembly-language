void *memcpy(void *dest, const void *src, uint32_t n) {
    // 将 dest 和 src 转换为无符号字符指针，以便逐字节复制
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    // 如果源地址和目标地址相同，直接返回目标地址
    if (d == s) {
        return dest;
    }

    // 如果 dest 在 src 的后面，且两者有重叠部分，则从后往前复制
    if (d > s && d < s + n) {
        // 从后往前复制
        d += n;  
        // add x3, x3, w2
        // w2 zero extend to 64bit
        // 
        s += n;
        while (n--) {
            *(--d) = *(--s);
        }
    } else {
        // 否则，从前往后复制
        while (n--) {
            *d++ = *s++;
            // precondition s in x3 and d in x4
            // ldrb  w5, [x3] // 因为是从地址里读，所以要用x，
            // add x3,x3,#1 //因为是地址，所以一定是用x
            // strb w5,[x4]
            // add x4,x4,#1
        }
    }

    return dest;
}
