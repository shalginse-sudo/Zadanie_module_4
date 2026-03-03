#include <iostream>
#include <windows.h>

// функция для обмена двух элементов ()
void swap(int& a, int& b) {
    int per = a;
    a = b;
    b = per;
}

// выполнение быстрого выбора пивота и разделения массива
int partition(int* arr, int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;    // Индекс меньшего элемента

    for (int j = low; j <= high - 1; ++j) 
    {
        if (arr[j] < pivot)
        { 
            i++;              
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// рекурсивная функция быстрой сортировки
void quickSort(int* arr, int low, int high) 
{
    if (low < high) 
    {
        int piv = partition(arr, low, high); // Определяем позицию пивота

        // Рекурсивно сортируем две части массива
        quickSort(arr, low, piv - 1); 
        quickSort(arr, piv + 1, high); 
    }
}

void quick_sort(int* arr, int size) 
{
    quickSort(arr, 0, size - 1);
}

void printArray(const int* arr, int size) 
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[] = { 7, 2, 1, 6, 8, 5, 3, 4 };
    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "Исходный массив: ";
    printArray(array, size);
    std::cout << std::endl;

    quick_sort(array, size);

    std::cout << "Отсортированный массив: ";
    printArray(array, size);
    std::cout << std::endl;
}
