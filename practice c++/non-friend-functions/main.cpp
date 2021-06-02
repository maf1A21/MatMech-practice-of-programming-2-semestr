#include <iostream>
using namespace std;

class A
{
private:
  int a;
  double b;
  char c;
  long long d;
public:
  A(int x, double y, char t, long long z): a(x),b(y),c(t), d(z) {}
};

class B
{
public:
  B(int x, double y, char t, long long z):  a1(x), b1(y), c1(t), d1(z){}
  int a1;
  double b1;
  char c1;
  long long d1;
};

int get_a(A& real)
{
  void* tmp = &real;
  B* fake = static_cast<B*>(tmp);
  return fake->a1;
}

double get_b(A& real)
{
  void* tmp = &real;
  B* fake = static_cast<B*>(tmp);
  return fake->b1;
}

char get_c(A& real)
{
  void* tmp = &real;
  B* fake = static_cast<B*>(tmp);
  return fake->c1;
}

long long get_d(A& real)
{
  void* tmp = &real;
  B* fake = static_cast<B*>(tmp);
  return fake->d1;
}

void put_a(A & real, int x)
{
  void* tmp = &real;
  B* fake = static_cast<B*>(tmp);
  fake->a1 = x;
}

void put_b(A & real, double x)
{
  void* tmp = &real;
  B* fake = static_cast<B*>(tmp);
  fake->b1 = x;
}

void put_c(A & real, char x)
{
  void* tmp = &real;
  B* fake = static_cast<B*>(tmp);
  fake->c1 = x;
}

void put_d(A & real, long long x)
{
  void* tmp = &real;
  B* fake = static_cast<B*>(tmp);
  fake->d1 = x;
}

int main()
{
  A test(1, 2.5, 'g', 100);

  put_a(test, -1);
  put_b(test, -1.5);
  put_c(test, 'q');
  put_d(test, 2000000);

  cout << get_a(test) << endl;
  cout << get_b(test) << endl;
  cout << get_c(test) << endl;
  cout << get_d(test) << endl;

  return 0;
}
