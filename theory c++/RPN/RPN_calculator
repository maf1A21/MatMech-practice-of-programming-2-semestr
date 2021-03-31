#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool IsOperation(const string s)
{
  if (s.length() > 1)
    return 0;
  switch (s[0])
  {
    case '+':
    case '-':
    case '*':
    case '/':
    return true;
  default:
    return false;
  }
}

int Calculate_from_RPN (string expression)
{
  expression += " ";
  stack <int> rpn_machine;
  string temp_str{};
  int var1{}, var2{}, res = 0;
  for (int i = 0; i < expression.length(); ++i)
  {
    if (expression[i] != ' ')
    {
      temp_str.push_back(expression[i]);
    }
    else
    {
      if (!IsOperation(temp_str))
      {
        rpn_machine.push(stoi(temp_str));
      }

      if (IsOperation(temp_str))
      {
        var2 = rpn_machine.top();
        rpn_machine.pop();
        var1 = rpn_machine.top();
        rpn_machine.pop();
        switch (temp_str[0])
        {
          case '+': res = var1 + var2; break;
          case '-': res = var1 - var2; break;
          case '*': res = var1 * var2; break;
          case '/': res = var1 / var2; break;
        default:
          cerr << "Smth went wrong(";
        }
        rpn_machine.push(res);
      }

      temp_str = "";
      var1 = 0;
      var2 = 0;
      res = 0;
    }
  }
  return rpn_machine.top();
}

int main()
{
  string expression;
  getline(cin, expression);
  cout << Calculate_from_RPN(expression);
  return 0;
}
