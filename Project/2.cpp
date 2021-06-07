#include <iostream>
using namespace std;

void print(const char* str)
{
  if (str) // проверяем строку на нулевой указатель
    cout << str;
  else
  {
    cerr << "null parameter"; // сообщение об ошибке
  }
}
