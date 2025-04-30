1/* Problem 2.30 */

#include <assert.h>

/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y) {
  int sum = x + y;
  return !(( x > 0 && y > 0 && sum <= 0) || ( x < 0 && y < 0 && sum >= 0));
}

int main() {

  assert(tadd_ok(0x80000000, 0xffffffff) == 0);
  assert(tadd_ok(0x80000000, 0x00000000) == 1);
  assert(tadd_ok(0x00000000, 0xffffffff) == 1);
  assert(tadd_ok(0x00000000, 0x00000000) == 1);
  assert(tadd_ok(0xffffffff, 0xffffffff) == 1);
  assert(tadd_ok(0x80000000, 0x80000000) == 0);
  assert(tadd_ok(0x7fffffff, 0x7fffffff) == 0);

  return 0;

}
