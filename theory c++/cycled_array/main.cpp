#include <iostream>
using namespace std;

struct CycledArray
{
  int* data;
  size_t size;
  CycledArray(size_t n = 0)
  {size = n; data = new int[size];}
  ~CycledArray()
  {delete[] data;}
  CycledArray(const CycledArray& A);
  const CycledArray& operator = (const CycledArray& A);
  int& operator [](int i);
  friend ostream & operator<<(ostream& out, const CycledArray& A);
};

CycledArray::CycledArray(const CycledArray& A)
{
  size = A.size;
  data = new int[size];
  for (int i = 0; i < size; ++i)
  {
    data[i] = A.data[i];
  }
}

 const CycledArray & CycledArray::operator=(const CycledArray& A)
{
    if (data)
    {
      delete[] data;
    }

    size = A.size;
    data = new int[size];
    for (int i = 0; i < size; ++i)
    {
      data[i] = A.data[i];
    }
    return *this;
}

 int& CycledArray::operator[](int i)
 {
   if (i < 0)
   {
     throw ("Wrong index");
   }

   return (data[i % size]);
 }

ostream & operator<<(ostream& out, CycledArray& A)
{
  for (int i = 0; i < A.size; ++i)
  {
    out << A[i] << " ";
  }
  return out;
}

int main()
{
  cout << "hELLO , WORLD!";
  return 0;
}
