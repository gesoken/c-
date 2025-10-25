#include <iostream>
#include <vector>

using namespace std;

// Функция поиска Фибоначчи
int fibonacciSearch(const vector<int>& arr, int target) {
    int n = arr.size();  // Размер массива

    // Инициализируем числа Фибоначчи
    int fibMMm2 = 0;  // (m-2)'th число Фибоначчи
    int fibMMm1 = 1;  // (m-1)'th число Фибоначчи
    int fibM = fibMMm2 + fibMMm1;  // m'th число Фибоначчи

    // Находим наименьшее число Фибоначчи, большее или равное размеру массива
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Отмечаем диапазон, который нужно сократить с каждой итерацией
    int offset = -1;

    // Пока есть элементы для проверки
    while (fibM > 1) {
        // Вычисляем индекс i
        int i = min(offset + fibMMm2, n - 1);

        // Если target больше значения в индексе i
        if (arr[i] < target) {
            // Сдвигаем числа Фибоначчи на два шага
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;  // Обновляем offset
        }

        // Если target меньше значения в индексе i
        else if (arr[i] > target) {
            // Сдвигаем числа Фибоначчи на один шаг
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        // Если target равен значению в индексе i
        else {
            return i;  // Возвращаем индекс i
        }
    }

    // Если остается один элемент для проверки
    if (fibMMm1 && arr[offset + 1] == target) {
        return offset + 1;  // Возвращаем индекс offset + 1
    }

    // Если элемент не найден
    return -1;  // Возвращаем -1
}

int main() {
    vector<int> arr = { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100, 235 };
    int target = 85;

    int result = fibonacciSearch(arr, target);

    if (result == -1) {
        cout << "Элемент не найден в массиве" << endl;
    }
    else {
        cout << "Элемент найден по индексу: " << result << endl;
    }

    return 0;
}