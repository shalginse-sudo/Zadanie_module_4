#include <iostream>
#include <windows.h>


long long* memo; // Указатель на динамическую память для хранения чисел Фибоначчи

long long fibonache(int nomer)
{
    // Если значение уже вычислено, возвращаем его из памяти
    if (memo[nomer] != -1)
        return memo[nomer];

    // Вычисляем новое значение и сохраняем в память
    if (nomer == 0)
        memo[nomer] = 0;
    else if (nomer == 1)
        memo[nomer] = 1;
    else
        memo[nomer] = fibonache(nomer - 1) + fibonache(nomer - 2);

    return memo[nomer];
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int userInput = 0;
    std::cout << "Введите число: ";
    std::cin >> userInput;

    // Создаём динамический массив нужного размера
    memo = new long long[userInput];

    // Инициализация всех элементов массива значениями "-1"
    for (int i = 0; i < userInput; i++) 
    {
        memo[i] = -1;
    }

    std::cout << "Числа Фибоначчи: ";
    for (int i = 0; i < userInput; i++)
    {
        long long fib = fibonache(i);
        std::cout << fib << ' ';
    }
    std::cout << std::endl;

    delete[] memo;

    return 0;
}