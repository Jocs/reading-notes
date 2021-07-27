#include <stdio.h>

/* getbits: get n bits from position p */

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned getRemovedBits(unsigned x, int p, int n) {
  return ((x >> (p + 1)) << (p + 1)) | (~(~0 << (p + 1 - n)) & x);
}

unsigned getReversedNBit(unsigned x, int p, int n) {
  return ((~x) >> (p + 1 - n) << (p + 1 - n)) & ~(~0 << (p + 1));
}

unsigned setBits(unsigned x, int p, int n, unsigned y) {
  return ((x >> (p + 1)) << (p + 1)) | (~(~0 << (p + 1 - n)) & x) | ((~(~0 << n) & y) << (p+1-n));
}

unsigned invert(unsigned x, int p, int n) {
  return getRemovedBits(x, p, n) | getReversedNBit(x, p, n);
}

int wordLength(void) {
  int i;
  unsigned v = (unsigned) ~0;
  for (i = 1; (v = v >> 1) > 0; ++i)
    ;

  return i;
}

unsigned rightrot(unsigned x, int n) {
  return (x >> n) | (x << (wordLength() - n));
}

int bitCount(unsigned x) {
  int count = 0;
  while (x != 0) {
    count++;
    x &= (x - 1);
  }

  return count;
}

int main() {
  unsigned result = bitCount(0b11101);
  printf("the word length is: %d", wordLength());
  printf("the result is: %x\n", result);
}
