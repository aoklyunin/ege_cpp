#include <iostream>
#include <fstream>

// главный метод программы
int main() {
    // открываем файл
    std::ifstream myfile;
    // бинарник собирается в отдельной папке, поэтому относительный путь такой
    // можно вместо этого закинуть файл куда-нибудь на диск и указать полный путь
    myfile.open("../problem24/24.txt");
    // читаем строку файла
    std::string in;
    myfile >> in;
    // закрываем файл
    myfile.close();


    // кол-во подряд идущих различных отличных от соседей символов
    // изначально длина такой последовательности равна 1
    int cnt = 1;
    // масимальная длина тоде равна 1
    int maxCnt = 1;
    // перебираем все индексы, кроме последнего, потому что
    // будем сравнивать пары
    for (int i = 0; i < in.length() - 1; i++) {
        // если текущий символ отличается от следующего
        if (in[i] != in[i + 1]) {
            // увеличиваем количество на 1
            cnt++;
        } else { // если текущий символ такой же, как и следующий
            // если количество подряд идущих различных символов
            // больше максимального
            if (cnt > maxCnt) {
                // сохраняем новое максимальное количество
                maxCnt = cnt;
            }
            // сбрасываем кол-во подряд идущих различных символов
            cnt = 1;
        }
    }
    // !не забудьте проверить последнее количество различных символов
    // потому что последний символ мог тоже отличаться, и тогда
    // внутри цикла проверку длины его последовательности с максимальной
    // выполнена не будет, ведь она срабатывает только
    // если мы встречаем первый повторяющийся символ
    if (cnt > maxCnt) {
        // сохраняем новое максимальное количество
        maxCnt = cnt;
    }
    // выводим максимальное количество
    std::cout << maxCnt << std::endl;


    return 0;
}

