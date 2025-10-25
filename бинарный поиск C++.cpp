#include <iostream>
#include <vector>

using namespace std;

// Функция бинарного поиска
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;                   // Левая граница поиска (индекс первого элемента)
    int right = arr.size() - 1;    // Правая граница поиска (индекс последнего элемента)

    // Пока левая граница не станет больше правой
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Вычисляем индекс середины (защита от переполнения)

        // Если элемент в середине равен целевому значению
        if (arr[mid] == target) {
            return mid;  // Возвращаем индекс найденного элемента
        }

        // Если целевое значение меньше, чем элемент в середине
        if (arr[mid] > target) {
            right = mid - 1;  // Сдвигаем правую границу влево
        }
        // Если целевое значение больше, чем элемент в середине
        else {
            left = mid + 1;   // Сдвигаем левую границу вправо
        }
    }

    // Если целевое значение не найдено
    return -1;  // Возвращаем -1, чтобы показать, что элемент не найден
}

int main() {
    vector<int> arr = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int target = 23;

    int result = binarySearch(arr, target);

    if (result == -1) {
        cout << "Элемент не найден в массиве" << endl;
    }
    else {
        cout << "Элемент найден по индексу: " << result << endl;
    }

    return 0;
}