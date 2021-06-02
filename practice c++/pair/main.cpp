#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair
{
  T first;
  V second;
public:
  Pair(): first(0), second(0){}
  Pair (T a, V b): first(a), second(b){}
  Pair(Pair<T,V> const& p);

  T get_first()
  {
    return first;
  }
  V get_second()
  {
    return second;
  }
  void set_first(T a)
  {
    first = a;
  }
  void set_second (V b)
  {
    second = b;
  }
  void set(T a, V b)
  {
    first = a, second = b;
  }
  void print()
  {
    cout << first << endl << second;
  }
  bool operator==(const Pair<T,V> p);
};

template <typename T, typename V>
Pair<T,V>::Pair(Pair<T,V> const& p)
{
  first = p.first;
  second = p.second;
}

template <typename T, typename V>
bool Pair<T,V>::operator==(const Pair<T,V> p)
{
  return (first == p.first) && (second == p.second);
}


int main()
{
  Pair <int, char> test(-1, 'a');
  Pair <int, char> test2 = test;
  test2.set(2, 'b');

  if (test == test2)
  {
    return 0;
  }

  cout << test2.get_first() << endl << test2.get_second() << endl;
  test.print();
  return 0;
}
