
#include <iostream>
#include <vector>
#include <algorithm> // Для std::swap

// 1. Сортировка выбором
void selectionSort(std::vector<int>& arr) {
  int n = arr.size();
  // Проходим по всему массиву
  for (int i = 0; i < n - 1; ++i) {
    // Находим индекс минимального элемента в оставшейся части массива
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    // Меняем местами текущий элемент с минимальным, если нужно
    if (minIndex != i) {
      std::swap(arr[i], arr[minIndex]);
    }
  }
}

// 2. Сортировка обменом (пузырьковая сортировка)
void bubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  // Повторяем проход по массиву n-1 раз
  for (int i = 0; i < n - 1; ++i) {
    // Флаг, чтобы проверить, были ли обмены в этой итерации
    bool swapped = false;
    // Проходим по массиву до n-i-1 (последние i элементов уже отсортированы)
    for (int j = 0; j < n - i - 1; ++j) {
      // Если текущий элемент больше следующего, меняем их местами
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    // Если обменов не было, массив отсортирован
    if (!swapped) {
      break;
    }
  }
}

// 3. Сортировка вставками
void insertionSort(std::vector<int>& arr) {
  int n = arr.size();
  // Начинаем с второго элемента (первый считается отсортированным)
  for (int i = 1; i < n; ++i) {
    int key = arr[i]; // Текущий элемент, который нужно вставить
    int j = i - 1;    // Индекс предыдущего элемента

    // Перемещаем элементы, которые больше key, вправо
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    // Вставляем key на правильное место
    arr[j + 1] = key;
  }
}

// 4. Сортировка слиянием (Вспомогательные функции)
void merge(std::vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> L(n1);
  std::vector<int> R(n2);

  for (int i = 0; i < n1; ++i) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; ++j) {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  while (i < n1) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  while (j < n2) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}

void mergeSortHelper(std::vector<int>& arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2; // Избегаем переполнения
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

void mergeSort(std::vector<int>& arr) {
  mergeSortHelper(arr, 0, arr.size() - 1);
}

// 5. Сортировка Шелла
void shellSort(std::vector<int>& arr) {
  int n = arr.size();
  // Уменьшаем промежуток между элементами
  for (int gap = n / 2; gap > 0; gap /= 2) {
    // Сортируем элементы с данным промежутком
    for (int i = gap; i < n; ++i) {
      int temp = arr[i];
      int j = i;
      // Перемещаем элементы, которые больше temp, вправо
      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        j -= gap;
      }
      // Вставляем temp на правильное место
      arr[j] = temp;
    }
  }
}

// 6. Быстрая сортировка (Вспомогательные функции)
int partition(std::vector<int>& arr, int low, int high) {
  int pivot = arr[high]; // Выбираем последний элемент как опорный
  int i = (low - 1);    // Индекс меньшего элемента

  for (int j = low; j <= high - 1; ++j) {
    // Если текущий элемент меньше или равен опорному
    if (arr[j] <= pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quickSortHelper(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    // Находим опорный элемент, так чтобы элементы меньше него были слева, а больше - справа
    int pi = partition(arr, low, high);

    // Рекурсивно сортируем элементы до и после опорного
    quickSortHelper(arr, low, pi - 1);
    quickSortHelper(arr, pi + 1, high);
  }
}

void quickSort(std::vector<int>& arr) {
  quickSortHelper(arr, 0, arr.size() - 1);
}

// 7. Пирамидальная сортировка (Вспомогательные функции)
void heapify(std::vector<int>& arr, int n, int i) {
  int largest = i;   // Инициализируем наибольший элемент как корень
  int left = 2 * i + 1;  // Левый дочерний элемент
  int right = 2 * i + 2; // Правый дочерний элемент

  // Если левый дочерний элемент больше корня
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  // Если правый дочерний элемент больше, чем наибольший элемент
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  // Если наибольший элемент не корень
  if (largest != i) {
    std::swap(arr[i], arr[largest]);

    // Рекурсивно преобразуем в кучу поддерево
    heapify(arr, n, largest);
  }
}

void heapSort(std::vector<int>& arr) {
  int n = arr.size();

  // Построение кучи (перегруппировка массива)
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(arr, n, i);
  }

  // Один за другим извлекаем элементы из кучи
  for (int i = n - 1; i > 0; --i) {
    // Перемещаем текущий корень в конец
    std::swap(arr[0], arr[i]);

    // Вызываем heapify на уменьшенной куче
    heapify(arr, i, 0);
  }
}
// 8. Последовательный поиск
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Возвращаем индекс, если элемент найден
        }
    }
    return -1; // Возвращаем -1, если элемент не найден
}

// 9. Бинарный поиск (массив должен быть отсортирован)
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Избегаем переполнения
        if (arr[mid] == target) {
            return mid; // Возвращаем индекс, если элемент найден
        } else if (arr[mid] < target) {
            left = mid + 1; // Ищем в правой половине
        } else {
            right = mid - 1; // Ищем в левой половине
        }
    }
    return -1; // Возвращаем -1, если элемент не найден
}

// 10. Интерполирующий поиск (массив должен быть отсортирован и равномерно распределен)
int interpolationSearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        // Рассчитываем предполагаемую позицию
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);

        if (arr[pos] == target) {
            return pos; // Возвращаем индекс, если элемент найден
        } else if (arr[pos] < target) {
            left = pos + 1; // Ищем в правой половине
        } else {
            right = pos - 1; // Ищем в левой половине
        }
    }
    return -1; // Возвращаем -1, если элемент не найден
}

// 11. Поиск Фибоначчи (массив должен быть отсортирован)
int fibonacciSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();
    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

    // Находим наименьшее число Фибоначчи, большее или равное n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Отмечаем диапазон от начала до конца
    int offset = -1;

    // Пока число Фибоначчи больше 1
    while (fibM > 1) {
        // Проверяем, является ли fibMMm2 допустимым местоположением
        int i = std::min(offset + fibMMm2, n - 1);

        // Если target больше значения в индексе fibMMm2,
        // обрезаем подмассив от offset до i
        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        // Если target меньше значения в индексе fibMMm2,
        // обрезаем подмассив после i + 1
        else if (arr[i] > target) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        // Элемент найден
        else {
            return i;
        }
    }

    // Если необходимо сравнить последний элемент:
    if (fibMMm1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    // Элемент не найден.
    return -1;
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  std::vector<int> arr2 = arr; // создаем копию для каждого алгоритма

  std::cout << "Исходный массив: ";
  for (int x : arr) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  selectionSort(arr2);
  std::cout << "Сортировка выбором: ";
  for (int x : arr2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
    arr2 = arr; // reset array

  bubbleSort(arr2);
  std::cout << "Пузырьковая сортировка: ";
  for (int x : arr2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
    arr2 = arr; // reset array

  insertionSort(arr2);
  std::cout << "Сортировка вставками: ";
  for (int x : arr2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
      arr2 = arr; // reset array
  mergeSort(arr2);
  std::cout << "Сортировка слиянием: ";
  for (int x : arr2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  arr2 = arr; // reset array
  shellSort(arr2);
  std::cout << "Сортировка Шелла: ";
  for (int x : arr2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  arr2 = arr; // reset array
  quickSort(arr2);
  std::cout << "Быстрая сортировка: ";
  for (int x : arr2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
    arr2 = arr; // reset array
  heapSort(arr2);
  std::cout << "Пирамидальная сортировка: ";
  for (int x : arr2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

   // Последовательный поиск
    int target = 22;
    int index = linearSearch(arr, target);
    std::cout << "Последовательный поиск " << target << ": индекс " << index << std::endl;

   // Перед бинарным поиском необходимо отсортировать массив
    std::vector<int> sortedArr = {11, 12, 22, 25, 34, 64, 90};
    target = 22;
    index = binarySearch(sortedArr, target);
    std::cout << "Бинарный поиск " << target << ": индекс " << index << std::endl;

    // Интерполирующий поиск
    target = 22;
    index = interpolationSearch(sortedArr, target);
    std::cout << "Интерполирующий поиск " << target << ": индекс " << index << std::endl;

    // Поиск Фибоначчи
    target = 22;
    index = fibonacciSearch(sortedArr, target);
    std::cout << "Поиск Фибоначчи " << target << ": индекс " << index << std::endl;
    return 0;
}
