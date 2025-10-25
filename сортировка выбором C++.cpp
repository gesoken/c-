#include <iostream>
#include <vector>

using namespace std;

// Функция сортировки выбором
void selectionSort(vector<int>& arr) {
    // n - размер массива
    int n = arr.size();

    // Внешний цикл: проходим по всем элементам массива (кроме последнего)
    for (int i = 0; i < n - 1; i++) {
        // Предполагаем, что текущий элемент (arr[i]) - минимальный
        int min_index = i;

        // Внутренний цикл: ищем минимальный элемент в оставшейся (неотсортированной) части массива
        for (int j = i + 1; j < n; j++) {
            // Если нашли элемент меньше, чем текущий минимальный
            if (arr[j] < arr[min_index]) {
                // Запоминаем индекс нового минимального элемента
                min_index = j;
            }
        }

        // Если индекс минимального элемента изменился (то есть мы нашли меньший элемент)
        if (min_index != i) {
            // Меняем местами текущий элемент (arr[i]) и минимальный элемент (arr[min_index])
            swap(arr[i], arr[min_index]);
        }
    }
}

int main() {
    vector<int> arr = { 64, 25, 12, 22, 11 };
    int n = arr.size();

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}