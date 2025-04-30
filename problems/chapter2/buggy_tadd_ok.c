/* problem 2.31 */

#include <stdio.h>
#include <assert.h>

/* Determine whether arguments can be added without overflow */
/* WARNING: This code is buggy. */
int tadd_ok(int x, int y) {
  int sum = x + y;
  return (sum - x == y) && (sum - y == x);
}

int main() {
  printf("%d\n", tadd_ok(0x80000000,0x80000000)); // this will return true
  printf("%x\n", (int)(0x80000000 + 0x80000000)); // because this sum is zero due to overflow
  printf("%x\n", (int)(0x80000000 + 0x80000000) - (int)(0x80000000)); // the negation of TMin is TMin because of overflow

  /* Therefore, sum - x == y is true in this case which should not be correct */

  /* Correction: two's complement addition form an abelian group so sum - x ((x + y) - x) is also going to evaluate to y regardless of overflow */

  return 0;
}

