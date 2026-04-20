#include <iostream>
#include <Windows.h>
#include <string>

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

void remove_dynamic_array_head(int** arr, int& logical_size, int& actual_size)
{
    if ((logical_size - 1) > (actual_size / 3)) {
        for (int i = 1; i < logical_size; ++i) {
            (*arr)[i - 1] = (*arr)[i];
        }
        --logical_size;
    }
    else if (logical_size > 1) {
        int new_actual_size = actual_size / 3;
        int* new_arr = new int[new_actual_size];
        for (int i = 1; i < logical_size; ++i) {
            new_arr[i - 1] = (*arr)[i];
        }

        delete[](*arr);
        *arr = new_arr;
        actual_size = new_actual_size;
        --logical_size;
    }
    else {
        --logical_size;
    }
}

void task_4_03()
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

    std::string answer;
    while (answer != "нет") {
        std::cout << "Удалить первый элемент? ";
        std::cin >> answer;
        if (answer == "да") {
            if (logical_size == 0) {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
                break;
            }

            remove_dynamic_array_head(&arr, logical_size, actual_size);

            std::cout << "Динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
        }
    }

    if (answer == "нет") {
        std::cout << "Спасибо! Ваш динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);
    }

    delete[] arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    task_4_03();
}