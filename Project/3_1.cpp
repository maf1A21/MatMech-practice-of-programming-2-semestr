#include <iostream>
#include <cassert>
using namespace std;

struct Triangle
{
  double a = 1;
  double b = 1;
  double c = 1;
};

void set_Triangle(Triangle* tr, double x, double y, double z)
{
  assert ((x > 0) && (y > 0) && (z > 0)); // проверка 1
  assert ((2 * max(x,y,z) < x + y + z) && ("Can't build the triangle because of the rule about the max side")); // проверка 2
  //по умолчанию C-style строка всегда true, а false && true = false. Удобный способ вывести сообщение
  tr->a = x;
  tr->b = y;
  tr->c = z;
}
