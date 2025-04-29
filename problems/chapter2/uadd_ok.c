/* Problem 2.27 */
#include <stdio.h>
#include <assert.h>


/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y) {
  unsigned sum = x + y;
  return sum >= x && sum >= y;
}

int main() {
  assert(uadd_ok(0xfffffffa, 0xffffff00) == 0);
  assert(uadd_ok(0x00000000, 0xffffff00) == 1);
  assert(uadd_ok(0xffffffff, 0x00000000) == 1);
  assert(uadd_ok(0xffffffff, 0xffffffff) == 0);
  
  return 0;
}
