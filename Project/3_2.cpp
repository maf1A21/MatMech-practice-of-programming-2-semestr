static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) == 4, "int must be 4 bytes");

constexpr int calculate (const int x)
{
  return x * sizeof(int);  
}

int main()
{
  constexp int sz = calculate(20);
  static_assert (sz < 10 , "Size is too big");
  
	return 0;
}
