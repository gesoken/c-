#include <iostream>
#include <vector>

using namespace std;

// Функция для просеивания вниз (heapify) - восстановление свойства кучи
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;   // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;   // Левый потомок
    int right = 2 * i + 2;  // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый потомок больше корня
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Меняем местами корень и наибольший элемент

        // Рекурсивно вызываем heapify для затронутого поддерева
        heapify(arr, n, largest);
    }
}

// Функция пирамидальной сортировки
void heapSort(vector<int>& arr) {
    int n = arr.size();  // Получаем размер массива

    // Строим max-кучу (max-heap)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Извлекаем элементы из кучи один за другим
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Меняем местами корень (максимальный элемент) с последним элементом

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}