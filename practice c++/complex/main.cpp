#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
  double re;
  double im;

public:
  Complex(): re{0}, im{0} {}
  Complex(double a, double b = 0)
  {
    re = a;
    im = b;
  }
  Complex (const Complex &z)
  {
    re = z.re;
    im = z.im;
  }
  ~Complex() {}
  double abs();
  Complex conjugate();
  Complex& operator = (Complex &z);
  Complex& operator += (Complex &z);
  Complex& operator -= (Complex &z);
  Complex operator + (Complex &z);
  Complex operator - (Complex &z);
  Complex operator * (Complex &z);
  Complex operator / (Complex &z);
  bool operator == (Complex &z);
  bool operator != (Complex &z);
  friend istream& operator>> (istream &in, Complex &z);
  friend ostream& operator<< (ostream &out, const Complex &z);
};

double Complex::abs()
{
  return sqrt(re * re - im * im);
}

Complex Complex::conjugate()
{
  Complex c(re, -im);
  return c;
}

Complex& Complex::operator = (Complex &z)
{
  re = z.re;
  im = z.im;
  return *this;
}

Complex& Complex::operator += (Complex &z)
{
  re += z.re;
  im += z.im;
  return *this;
}

Complex& Complex::operator -= (Complex &z)
{
  re -= z.re;
  im -= z.im;
  return *this;
}

Complex Complex::operator + (Complex &z)
{

  return Complex(re + z.re, im + z.im);
}

Complex Complex::operator - (Complex &z)
{
  return Complex (re - z.re, im - z.im);
}
// (a + bi) * (x + yi) = ax + ayi +bix - by
Complex Complex::operator * (Complex &z)
{

  return Complex (re * z.re - im * z.im, re * z.im + im * z.re);
}

Complex Complex::operator / (Complex &z)
{
  Complex temp;
  double r = z.re * z.re + z.im * z.im;
  temp.re = (re * z.re + im * z.im) / r;
  temp.re = (im * z.re - re * z.im) / r;
  return temp;
}

bool Complex::operator==(Complex &z)
{
  if ((this->re == z.re) && (this->im == z.im))
  {
    return 1;
  }
  return 0;
}

bool Complex::operator!=(Complex &z)
{
  if ((this->re != z.re) || (this->im != z.im))
  {
    return 1;
  }
  return 0;
}

istream& operator>>(istream &in, Complex &z)
{
  in >> z.re >> z.im;
  return in;
}

ostream& operator<<(ostream &out, const Complex &z)
{
  out << z.re << "," << z.im;
  return out;
}

int main()
{

  Complex a (5, 2);
    Complex b (3, -3);

    cout << "a = " << a << "; b =" << b << endl;

    a += b;

    cout << "a = " << a << "; b =" << b << endl;

    Complex c = a + b;

    cout << c << endl;
    cout << a + b << endl;
    cout << a * b << endl;
  return 0;
}
