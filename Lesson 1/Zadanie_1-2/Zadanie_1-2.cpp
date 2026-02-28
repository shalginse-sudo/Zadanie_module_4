#include <iostream>
#include <windows.h>


int func(int mas[], int size, int zhach)
{
    int left = 0;
    int right = size;
    while (left < right)
    {
        int a = left + (right - left) / 2;
        if (mas[a] <= zhach)
        {
            left = a + 1;
        }
        else { right = a; }
    }
    int rez = size - left;
    return rez;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int mas[]{ 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(mas) / sizeof(mas[0]);
    int start = 0;

    std::cout << "Введите точку отсчета: ";
    std::cin >> start;
    std::cout << "Количество элементов в массиве, больших чем " << start << ": " << func(mas, size, start);
    std::cout << std::endl;
}

