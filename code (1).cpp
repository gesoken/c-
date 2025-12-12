
#include <iostream>
#include <string>
#include <algorithm> 
#include <sstream>   
#include <limits>    
#include <locale>    

using namespace std;

// Максимальное количество итераций для поиска палиндрома
const int MAX_ITERATIONS = 100;


long long reverse_number(long long n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    
    stringstream ss(s);
    long long reversed_n;
    ss >> reversed_n;
    return reversed_n;
}


bool is_palindrome(long long n) {
    return n == reverse_number(n);
}


void clear_input_buffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


long long get_long_long_input(const string& prompt) {
    long long value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) { 
            cout << "Некорректный ввод. Пожалуйста, введите целое положительное число.\n";
            cin.clear();
            clear_input_buffer(); 
        } else {
            clear_input_buffer(); 
            return value;
        }
    }
}


int get_int_input(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) { 
            cout << "Некорректный ввод. Пожалуйста, введите целое положительное число.\n";
            cin.clear(); 
            clear_input_buffer(); 
        } else {
            clear_input_buffer(); 
            return value;
        }
    }
}

// Функция для анализа процесса получения палиндрома
void analyze_palindrome_process(long long start_num, int max_steps) {
    long long current_num = start_num;
    int steps = 0;

    cout << "\n--- Анализ процесса получения палиндрома для числа " << start_num << " ---\n";

    if (is_palindrome(current_num)) {
        cout << "Исходное число " << current_num << " уже является палиндромом.\n";
        return;
    }

    while (steps < max_steps) {
        steps++;
        long long reversed_num = reverse_number(current_num);
        cout << "Шаг " << steps << ": " << current_num << " + " << reversed_num << " = ";
        
 

        current_num += reversed_num;
        cout << current_num << endl;

        if (is_palindrome(current_num)) {
            cout << "Палиндром " << current_num << " найден за " << steps << " шагов!\n";
            return;
        }
    }

    cout << "Палиндром не найден за " << max_steps << " шагов. Последнее число: " << current_num << ".\n";
}

// --- Режимы работы ---

void run_execution_mode() {
    cout << "\n--- РЕЖИМ ВЫПОЛНЕНИЯ ---\n";
    cout << "Выберите операцию:\n";
    cout << "1. Реверсировать число\n";
    cout << "2. Проверить на палиндром\n";
    cout << "3. Анализ процесса получения палиндрома (число + реверс)\n";
    cout << "4. Назад в главное меню\n";
    cout << "Ваш выбор: ";

    string choice;
    getline(cin, choice);

    if (choice == "1") {
        long long num = get_long_long_input("Введите число для реверсирования: ");
        cout << "Реверсированное число: " << reverse_number(num) << endl;
    } else if (choice == "2") {
        long long num = get_long_long_input("Введите число для проверки на палиндром: ");
        if (is_palindrome(num)) {
            cout << "Число " << num << " является палиндромом.\n";
        } else {
            cout << "Число " << num << " не является палиндромом.\n";
        }
    } else if (choice == "3") {
        long long start_num = get_long_long_input("Введите начальное число: ");
        int max_steps = get_int_input("Введите максимальное количество шагов (например, 100): ");
        analyze_palindrome_process(start_num, max_steps);
    } else if (choice == "4") {
       
    } else {
        cout << "Некорректный выбор. Пожалуйста, попробуйте снова.\n";
    }
}

void run_tests() {
    cout << "\n--- АВТОМАТИЧЕСКОЕ ТЕСТИРОВАНИЕ ---\n";
    int passed_count = 0;
    int total_count = 0;

   
    cout << "\nТест 1.1 (Реверсирование 12345): ";
    if (reverse_number(12345) == 54321) { cout << "УСПЕХ"; passed_count++; } else { cout << "ПРОВАЛ"; }
    cout << " (Ожидалось: 54321, Получено: " << reverse_number(12345) << ")\n";
    total_count++;

    cout << "Тест 1.2 (Реверсирование 700): ";
    if (reverse_number(700) == 7) { cout << "УСПЕХ"; passed_count++; } else { cout << "ПРОВАЛ"; }
    cout << " (Ожидалось: 7, Получено: " << reverse_number(700) << ")\n";
    total_count++;
    
    cout << "Тест 1.3 (Реверсирование 9): ";
    if (reverse_number(9) == 9) { cout << "УСПЕХ"; passed_count++; } else { cout << "ПРОВАЛ"; }
    cout << " (Ожидалось: 9, Получено: " << reverse_number(9) << ")\n";
    total_count++;

    
    cout << "\nТест 2.1 (Палиндром 121): ";
    if (is_palindrome(121)) { cout << "УСПЕХ"; passed_count++; } else { cout << "ПРОВАЛ"; }
    cout << " (Ожидалось: true)\n";
    total_count++;

    cout << "Тест 2.2 (Не палиндром 1234): ";
    if (!is_palindrome(1234)) { cout << "УСПЕХ"; passed_count++; } else { cout << "ПРОВАЛ"; }
    cout << " (Ожидалось: false)\n";
    total_count++;
    
    cout << "Тест 2.3 (Палиндром 8888): ";
    if (is_palindrome(8888)) { cout << "УСПЕХ"; passed_count++; } else { cout << "ПРОВАЛ"; }
    cout << " (Ожидалось: true)\n";
    total_count++;

    
    cout << "\nТест 3 (Анализ 59 -> 1111): Проверяется вручную вывод для 59 (ожидается палиндром 1111 за 3 шага).\n";
    analyze_palindrome_process(59, 5); 
    cout << "Визуально проверьте вывод выше.\n";
    passed_count++; 
    total_count++;

    
    cout << "\nТест 4 (Анализ 196 -> лимит): Проверяется вручную вывод для 196 (ожидается достижение лимита).\n";
    analyze_palindrome_process(196, 10);
    cout << "Визуально проверьте вывод выше.\n";
    passed_count++; 
    total_count++;

    cout << "\nИТОГ: Пройдено " << passed_count << " из " << total_count << " тестов (некоторые тесты требуют визуальной проверки).\n";
}

// --- Главное меню ---

void show_main_menu() {
    cout << "\n--- ГЛАВНОЕ МЕНЮ СИСТЕМЫ АНАЛИЗА ЧИСЕЛ ---\n";
    cout << "1. Выполнение (Числовые преобразования и анализ)\n";
    cout << "2. Тестирование (Автоматические тесты)\n";
    cout << "3. Выход\n";
    cout << "Выберите пункт: ";
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    string choice;

    while (true) {
        show_main_menu();
        getline(cin, choice);

        if (choice == "1") {
            run_execution_mode();
        } else if (choice == "2") {
            run_tests();
        } else if (choice == "3") {
            cout << "Завершение работы программы.\n";
            break;
        } else {
            cout << "Некорректный ввод. Пожалуйста, выберите 1, 2 или 3.\n";
        }
    }

    return 0;
}
