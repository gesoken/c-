#include <iostream>
#include <vector>

using namespace std;

// Функция сортировки Шелла
void shellSort(vector<int>& arr) {
    int n = arr.size();  // Получаем размер массива

    // Определяем начальный шаг (gap) - обычно половина размера массива
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Внешний цикл: уменьшаем шаг (gap) вдвое на каждой итерации
        for (int i = gap; i < n; i++) {
            // Внутренний цикл: сортируем элементы с шагом gap
            int temp = arr[i];  // Запоминаем текущий элемент
            int j = i;          // Индекс текущего элемента

            // Пока не достигнем начала массива и элемент с шагом gap больше текущего элемента
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];  // Сдвигаем элемент на шаг gap вправо
                j -= gap;              // Переходим к предыдущему элементу с шагом gap
            }

            arr[j] = temp;  // Вставляем текущий элемент на правильное место
        }
    }
}

int main() {
    vector<int> arr = { 12, 34, 54, 2, 3, 43, 56, 78, 8, 5, 4, 3 };
    int n = arr.size();

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}