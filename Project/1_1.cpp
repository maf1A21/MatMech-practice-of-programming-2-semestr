#include <iostream>
using namespace std;

int Find_letter_pos(const char* str, char c)
{
  for (size_t i = 0; size < strlen(str); ++i)
  {
    if (str[i] == c)
      return pos;
  }
  return -1; // ничего не говорит
}

struct Date_of_birth
{
  int day;
  int month;
  int year;
  Date_of_birth(int a, int b, int c)
  {
    if (( a < 1) || (a > 31) || ( b < 1) || (b > 12) || (c > 2021)) // понятно, что не все случаи, но для примера хватит
    {return -1;} // не-а, это конструктор, никаких return!
    day = a;
    month = b;
    year = c;
  }
}
