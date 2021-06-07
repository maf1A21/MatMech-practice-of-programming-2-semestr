#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter a number: ";
    double a;
    cin >> a;

    try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
    {
        // Если пользователь ввел отрицательное число, то выбрасывается исключение
        if (a < 0.0)
            throw "Can not take sqrt of negative number"; // выбрасывается исключение типа const char*

        // Если пользователь ввел положительное число, то выполняется операция и выводится результат
        cout << "The sqrt of " << a << " is " << sqrt(a) << '\n';
    }
    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
}
