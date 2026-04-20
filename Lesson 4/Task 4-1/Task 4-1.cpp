#include <iostream>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    for (int i = 0; i < actual_size; ++i) {
        if (i != 0) {
            std::cout << ' ';
        }
        if (i < logical_size) {
            std::cout << arr[i];
        }
        else {
            std::cout << '_';
        }
    }
    std::cout << std::endl;
}

void task_4_01()
{
    int actual_size;
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;

    int logical_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!";
        return;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    task_4_01();
}
