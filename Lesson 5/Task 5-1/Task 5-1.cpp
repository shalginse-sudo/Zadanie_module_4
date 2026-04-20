
#include <iostream>
#include <Windows.h>

int find_pyramid_element_parent_idx(int curr_pos)
{
    return ((curr_pos + 1) / 2) - 1;
}

void print_pyramid_element(int* arr, int curr_pos)
{
    if (curr_pos == 0) {
        std::cout << "0 root " << arr[curr_pos] << std::endl;
    }
    else {
        std::cout << static_cast<int>(std::log(curr_pos + 1) / std::log(2)) << ' ';
        std::cout << (curr_pos % 2 ? "left" : "right");
        std::cout << "(" << arr[find_pyramid_element_parent_idx(curr_pos)] << ") ";
        std::cout << arr[curr_pos] << std::endl;
    }
}

void print_pyramid(int* arr, int size)
{
    int curr_pos = 0;
    while (curr_pos < size) {
        print_pyramid_element(arr, curr_pos++);
    }
}

void task_5_01()
{
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    int* arr = new int[size];

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    print_pyramid(arr, size);

    delete[] arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    task_5_01();
}