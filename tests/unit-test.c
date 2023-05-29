#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

// Функция для сравнения двух строк и вывода результата теста
void assert_str(char *expected, char *actual, char *test_name) {
    if (strcmp(expected, actual) == 0) {
        printf("[PASSED] %s\n", test_name);
    } else {
        printf("[FAILED] %s\n", test_name);
        printf("  Expected: %s\n", expected);
        printf("  Actual:   %s\n", actual);
    }
}

// Функция для сравнения двух чисел и вывода результата теста
void assert_int(int expected, int actual, char *test_name) {
    if (expected == actual) {
        printf("[PASSED] %s\n", test_name);
    } else {
        printf("[FAILED] %s\n", test_name);
        printf("  Expected: %d\n", expected);
        printf("  Actual:   %d\n", actual);
    }
}

// Тестируем функцию ft_itoa
void test_ft_itoa() {
    char *result = ft_itoa(1234);
    assert_str("1234", result, "Test ft_itoa with positive number");
    free(result);
    
    result = ft_itoa(-5678);
    assert_str("-5678", result, "Test ft_itoa with negative number");
    free(result);
    
    result = ft_itoa(0);
    assert_str("0", result, "Test ft_itoa with zero");
    free(result);
    
    result = ft_itoa(2147483647);
    assert_str("2147483647", result, "Test ft_itoa with maximum positive int value");
    free(result);
    
    result = ft_itoa(-2147483648);
    assert_str("-2147483648", result, "Test ft_itoa with minimum negative int value");
    free(result);
}

// Тестируем функцию ft_strlen
void test_ft_strlen() {
    int length = ft_strlen("Hello");
    assert_int(5, length, "Test ft_strlen with a string");
    
    length = ft_strlen("");
    assert_int(0, length, "Test ft_strlen with an empty string");
}

// Тестируем функцию ft_putnbr_fd
void test_ft_putnbr_fd() {
    int stdout_fd = dup(STDOUT_FILENO); // сохраняем стандартный вывод
    int pipe_fd[2];
    pipe(pipe_fd); // создаем канал для перенаправления вывода
    
    dup2(pipe_fd[1], STDOUT_FILENO); // перенаправляем стандартный вывод в канал
    
    ft_putnbr_fd(1234, STDOUT_FILENO);
    close(pipe_fd[1]); // закрываем дескриптор для записи в канал
    
    char buffer[255];
    read(pipe_fd[0], buffer, sizeof(buffer)); // считываем данные из канала
    close(pipe_fd[0]); // закрываем дескриптор для чтения из канала
    
    dup2(stdout_fd, STDOUT_FILENO); // восстанавливаем стандартный вывод
    
    assert_str("1234", buffer, "Test ft_putnbr_fd");
}

// Тестируем функцию ft_putstr
void test_ft_putstr() {
    int stdout_fd = dup(STDOUT_FILENO); // сохраняем стандартный вывод
    int pipe_fd[2];
    pipe(pipe_fd); // создаем канал для перенаправления вывода
    
    dup2(pipe_fd[1], STDOUT_FILENO); // перенаправляем стандартный вывод в канал
    
    ft_putstr("Hello, world!");
    close(pipe_fd[1]); // закрываем дескриптор для записи в канал
    
    char buffer[255];
    read(pipe_fd[0], buffer, sizeof(buffer)); // считываем данные из канала
    close(pipe_fd[0]); // закрываем дескриптор для чтения из канала
    
    dup2(stdout_fd, STDOUT_FILENO); // восстанавливаем стандартный вывод
    
    assert_str("Hello, world!", buffer, "Test ft_putstr");
}

// Тестируем функцию ft_strcmp
void test_ft_strcmp() {
    int result = ft_strcmp("Hello", "Hello");
    assert_int(0, result, "Test ft_strcmp with equal strings");
    
    result = ft_strcmp("Hello", "World");
    assert_int(-1, result, "Test ft_strcmp with different strings");
    
    result = ft_strcmp("Hello", "Hel");
    assert_int(1, result, "Test ft_strcmp with different lengths");
}

// Тестируем функцию ft_strdup
void test_ft_strdup() {
    char *result = ft_strdup("Hello, world!");
    assert_str("Hello, world!", result, "Test ft_strdup");
    free(result);
}

// Тестируем функцию get_next_line
void test_get_next_line() {
    int fd = open("test.txt", O_RDONLY);
    char *line = NULL;

    int ret = get_next_line(fd, &line);
    assert_str("Line 1", line, "Test get_next_line with line 1");
    free(line);

    ret = get_next_line(fd, &line);
    assert_str("Line 2", line, "Test get_next_line with line 2");
    free(line);

    ret = get_next_line(fd, &line);
    assert_str("Line 3", line, "Test get_next_line with line 3");
    free(line);

    ret = get_next_line(fd, &line);
    assert_str("Line 4", line, "Test get_next_line with line 4");
    free(line);

    ret = get_next_line(fd, &line);
    assert_str("", line, "Test get_next_line with end of file");
    free(line);

    close(fd);
}

int main() {
    test_ft_itoa();
    test_ft_strlen();
    test_ft_putnbr_fd();
    test_ft_putstr();
    test_ft_strcmp();
    test_ft_strdup();
    test_get_next_line();

    return 0;
}
