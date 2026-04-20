
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

void append_to_dynamic_array(int** arr, int& logical_size, int& actual_size, int add_el)
{
    if (logical_size == actual_size) {
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];
        for (int i = 0; i < actual_size; ++i) {
            new_arr[i] = (*arr)[i];
        }
        new_arr[actual_size] = add_el;

        delete[](*arr);
        *arr = new_arr;
        logical_size = actual_size + 1;
        actual_size = new_actual_size;
    }
    else {
        (*arr)[logical_size] = add_el;
        ++logical_size;
    }
}

void task_4_02()
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

    int add_el = -1;
    while (true) {
        std::cout << "Введите элемент для добавления: ";
        std::cin >> add_el;
        if (add_el == 0) {
            break;
        }
        append_to_dynamic_array(&arr, logical_size, actual_size, add_el);

        std::cout << "Динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);
    }
    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    task_4_02();
}