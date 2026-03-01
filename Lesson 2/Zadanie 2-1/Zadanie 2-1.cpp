#include <iostream>
#include <windows.h>


long long fibonache(int nomer)
{
    if (nomer == 0)
        return 0;
    if (nomer == 1)
        return 1;
    return fibonache(nomer - 1) + fibonache(nomer - 2);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int userInput = 0;
    std::cout << "Введите число: ";
    std::cin >> userInput;
    std::cout << "Числа Фибоначчи: ";
    for (int i = 0; i < userInput; i++)
    {
        long long fib = fibonache(i);
        std::cout << fib << ' ';
    }
    std::cout << std::endl;
}