#include <iostream>
#include <string>
#include <stack>
using namespace std;

int OperationPriority(string s)
{
  switch (s[0])
  {
    case '(': return 1;
    case '-': return 2;
    case '+': return 2;
    case '/': return 3;
    case '*': return 3;
  }
  defaut:
  {
    cerr << "Error";
    return 0;
  }
}

bool IsOperation(string s)
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

string RPN_converter(string expression)
{
  expression += " ";
  string expression_out{};
  stack <string> stack{};
  string temp_str{};

  for (int i = 0; i < expression.length(); ++i)
  {

    if (expression[i] != ' ')
    {
      temp_str.push_back(expression[i]);
    }

    else if (!IsOperation(temp_str))
    {
      expression_out += temp_str + " ";
      temp_str = {};
    }

    else if (IsOperation(temp_str))
    {
      if ((stack.empty()) || (OperationPriority(stack.top()) < OperationPriority(temp_str)))
      {
        stack.push(temp_str);
        temp_str = {};
      }

      else
      {
        while (!(stack.empty() || OperationPriority(stack.top()) < OperationPriority(temp_str)))
        {
            expression_out += stack.top() + " ";
            stack.pop();
        }
        stack.push(temp_str);
        temp_str = {};
      }

    }

    else if (temp_str == "(")
    {
      stack.push(temp_str);
      temp_str = {};
    }

    else if (temp_str == ")")
    {
      while (stack.top() != "(")
      {
        expression_out += stack.top();
        stack.pop();
      }
      stack.pop();
      temp_str = {};
    }
  }

  while (!stack.empty())
  {
    expression_out += stack.top();
    stack.pop();
    expression_out += " ";
  }

  return expression_out;
}

int main()
{
  string s;
  getline(cin, s);
  cout << RPN_converter(s);
  return 0;
}
