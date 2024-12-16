//#include <stdio.h>              //Laba 6
//#include <stdlib.h>
//#include <time.h>
//
//// Функция для безопасного ввода целого числа
//int input_int(const char *prompt) {
//    int value;
//    char c;
//    while (1) {
//        printf("%s", prompt);
//        if (scanf("%d%c", &value, &c) == 2 && c == '\n') {
//            return value;
//        } else {
//            printf("Ошибка ввода. Попробуйте снова.\n");
//            while (getchar() != '\n'); // Очистка буфера ввода
//        }
//    }
//}
//
//// Функция для случайного заполнения массива или матрицы
//void fill_random(int *arr, int size) {
//    for (int i = 0; i < size; i++) {
//        arr[i] = rand() % 201 - 100; // Генерация случайных чисел в диапазоне [-100, 100]
//    }
//}
//
//// Функция для сортировки методом Шелла
//void shell_sort(int *arr, int size) {
//    for (int gap = size / 2; gap > 0; gap /= 2) {
//        for (int i = gap; i < size; i++) {
//            int temp = arr[i];
//            int j;
//            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
//                arr[j] = arr[j - gap];
//            }
//            arr[j] = temp;
//        }
//    }
//}
//
//// Задача 1: сортировка элементов после первого положительного методом Шелла
//void task1_sort_after_first_positive(int *arr, int size) {
//    int first_positive_index = -1;
//
//    for (int i = 0; i < size; i++) {
//        if (arr[i] > 0) {
//            first_positive_index = i;
//            break;
//        }
//    }
//
//    if (first_positive_index != -1 && first_positive_index + 1 < size) {
//        shell_sort(arr + first_positive_index + 1, size - first_positive_index - 1);
//    }
//}
//
//// Функция для вычисления произведения отрицательных элементов в строке
//int product_of_negatives(int *row, int size) {
//    int product = 1;
//    int has_negative = 0;
//
//    for (int i = 0; i < size; i++) {
//        if (row[i] < 0) {
//            product *= row[i];
//            has_negative = 1;
//        }
//    }
//
//    return has_negative ? product : 0;
//}
//
//// Функция для слияния двух подмассивов
//void merge(int **matrix, int *products, int left, int mid, int right) {
//    int left_size = mid - left + 1;
//    int right_size = right - mid;
//
//    int **left_matrix = malloc(left_size * sizeof(int *));
//    int *left_products = malloc(left_size * sizeof(int));
//
//    int **right_matrix = malloc(right_size * sizeof(int *));
//    int *right_products = malloc(right_size * sizeof(int));
//
//    for (int i = 0; i < left_size; i++) {
//        left_matrix[i] = matrix[left + i];
//        left_products[i] = products[left + i];
//    }
//
//    for (int i = 0; i < right_size; i++) {
//        right_matrix[i] = matrix[mid + 1 + i];
//        right_products[i] = products[mid + 1 + i];
//    }
//
//    int i = 0, j = 0, k = left;
//    while (i < left_size && j < right_size) {
//        if (left_products[i] <= right_products[j]) {
//            matrix[k] = left_matrix[i];
//            products[k] = left_products[i];
//            i++;
//        } else {
//            matrix[k] = right_matrix[j];
//            products[k] = right_products[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < left_size) {
//        matrix[k] = left_matrix[i];
//        products[k] = left_products[i];
//        i++;
//        k++;
//    }
//
//    while (j < right_size) {
//        matrix[k] = right_matrix[j];
//        products[k] = right_products[j];
//        j++;
//        k++;
//    }
//
//    free(left_matrix);
//    free(right_matrix);
//    free(left_products);
//    free(right_products);
//}
//
//// Функция сортировки строк матрицы методом слияния
//void merge_sort_rows(int **matrix, int *products, int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//
//        merge_sort_rows(matrix, products, left, mid);
//        merge_sort_rows(matrix, products, mid + 1, right);
//
//        merge(matrix, products, left, mid, right);
//    }
//}
//
//// Задача 2: сортировка строк матрицы по возрастанию произведения отрицательных элементов
//void task2_sort_rows_by_negative_product(int **matrix, int rows, int cols) {
//    int *products = malloc(rows * sizeof(int));
//
//    for (int i = 0; i < rows; i++) {
//        products[i] = product_of_negatives(matrix[i], cols);
//    }
//
//    merge_sort_rows(matrix, products, 0, rows - 1);
//
//    free(products);
//}
//
//int main() {
//    srand(time(NULL)); // Инициализация генератора случайных чисел
//
//    // Пример выполнения задачи 1
//    int n = input_int("Введите размер массива: ");
//
//    int *arr = malloc(n * sizeof(int));
//
//    if (input_int("Введите 1 для случайного ввода или 0 для ручного ввода: ")) {
//        fill_random(arr, n);
//        printf("Случайно сгенерированный массив: ");
//        for (int i = 0; i < n; i++) {
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
//    } else {
//        printf("Введите элементы массива: ");
//        for (int i = 0; i < n; i++) {
//            arr[i] = input_int("");
//        }
//    }
//
//    task1_sort_after_first_positive(arr, n);
//
//    printf("Массив после сортировки элементов после первого положительного: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    free(arr);
//
//    // Пример выполнения задачи 2
//    int rows = input_int("\nВведите количество строк матрицы: ");
//    int cols = input_int("Введите количество столбцов матрицы: ");
//
//    int **matrix = malloc(rows * sizeof(int *));
//    for (int i = 0; i < rows; i++) {
//        matrix[i] = malloc(cols * sizeof(int));
//    }
//
//    if (input_int("Введите 1 для случайного ввода или 0 для ручного ввода: ")) {
//        for (int i = 0; i < rows; i++) {
//            fill_random(matrix[i], cols);
//        }
//        printf("Случайно сгенерированная матрица:\n");
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                printf("%d ", matrix[i][j]);
//            }
//            printf("\n");
//        }
//    } else {
//        printf("Введите элементы матрицы:\n");
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                matrix[i][j] = input_int("");
//            }
//        }
//    }
//
//    task2_sort_rows_by_negative_product(matrix, rows, cols);
//
//    printf("Матрица после сортировки строк по произведению отрицательных элементов:\n");
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            printf("%d ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//
//    for (int i = 0; i < rows; i++) {
//        free(matrix[i]);
//    }
//    free(matrix);
//
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>

// Функция для преобразования регистра символов
void toggle_case(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str -= 32; // Преобразование в заглавную букву
        } else if (*str >= 'A' && *str <= 'Z') {
            *str += 32; // Преобразование в строчную букву
        }
        str++;
    }
}

// Функция для ввода строки с динамическим выделением памяти
char* input_string(const char *prompt) {
    char *str = NULL;
    size_t size = 0;
    size_t len = 0;
    char c;

    printf("%s", prompt);
    while ((c = getchar()) != '\n') {
        if (len + 1 >= size) {
            size = size ? size * 2 : 16; // Увеличение размера буфера
            str = realloc(str, size);
        }
        str[len++] = c;
    }

    if (str) {
        str[len] = '\0'; // Завершающий нуль
    }

    return str;
}

// Функция для проверки строки: содержит ли только буквы
int is_alpha_string(const char *str) {
    while (*str) {
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))) {
            return 0; // Если найден неалфавитный символ, возвращаем 0
        }
        str++;
    }
    return 1; // Если строка содержит только буквы, возвращаем 1
}

// Функция для безопасного ввода строки, проверяющей, что строка состоит только из букв
char* input_valid_string(const char *prompt) {
    char *str = NULL;
    while (1) {
        str = input_string(prompt);
        if (str && str[0] != '\0' && is_alpha_string(str)) {
            return str; // Возврат строки, если она непустая и содержит только буквы
        }
        printf("Ошибка ввода. Попробуйте снова:\n");
        free(str); // Освобождаем память, если ввод некорректен
    }
}

int main() {
    char *(*input)(const char*) = input_valid_string; // Указатель на функцию с проверкой
    void (*process)(char*) = toggle_case;            // Указатель на функцию обработки строки

    // Ввод строки с проверкой
    char *str = input("Введите строку (латиница): ");

    // Преобразование регистра
    process(str);

    // Вывод результата
    printf("Преобразованная строка: %s\n", str);

    // Освобождение памяти
    free(str);

    return 0;
}

