#include <iostream>

// главный метод программы
int main() {
    // кол-во нужных нам чисел
    int cnt = 0;
    // максимальное число
    int max = -1;

    // перебираем все зхначения интервала
    // !обязательно поставьте <=! иначе последнее число не учтётся
    for (int i = 1016; i <= 7937; i++) {
        // если число нам подходит
        if (i % 3 == 0 && i % 7 != 0 && i % 17 != 0 && i % 19 != 0 && i % 27 != 0) {
            // увеличиваем кол-во на 1
            cnt++;
            // сохраняем число в максимум, т.к. перебор
            // идёт в сторону возрастания, то последнее подходящее
            // число и будет максимальным
            max = i;
        }
    }
    // выводим результат
    std::cout<< cnt << " " << max << std::endl;
    return 0;
}

