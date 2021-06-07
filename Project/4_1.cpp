#include <iostream>
using namespace std;

int main()
{
  try
  {
    throw -1;
    cout << "That never prints";
  }
  catch (int a)
  {
    cerr << "we caught a walue = " << a;
  }
   return 0;
}
