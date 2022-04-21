#include <iostream>


// декларируем метод хода второго игрока
bool player2(int l, int r, int step);

// ход Пети, результат отвечает на вопрос, удовлетворяется ли
// требование задачи,
// l - кол-во камней в первой куче, r - во второй, step - номер хода
bool player1(int l, int r, int step) {
    // если это первый ход Пети, тогда Ваня пока что
    // не сделал ни одного хода
    if (step == 1) {
        // выигрышная стратегия подразумевает, что
        // при любом поведении Вани требование  задачи должно быть удовлетворено,
        // если говорится, что тсратегия есть, значит,
        // нам подойдёт, если условие задачи выполнится в случае
        // хотя бы одного хода, поэтому используем ИЛИ
        return player2(l + 1, r, step) ||
               player2(l, r + 1, step) ||
               player2(l * 2, r, step) ||
               player2(l, r * 2, step);
    } else { // если это второй ход Пети, т.е. Ваня сделал уже один ход
        // если Ваня при этом победил,
        if (l + r >= 77)
            // требование задачи не выполнено
            return false;

        // каким-то своим ходом Петя может выиграть,
        // то условие задачи будет выполнено, поэтому ИЛИ
        return player2(l + 1, r, step) ||
               player2(l, r + 1, step) ||
               player2(l * 2, r, step) ||
               player2(l, r * 2, step);
    }
}

// ход Вани, результат отвечает на вопрос, удовлетворяется ли
// требование задачи,
// l - кол-во камней в первой куче, r - во второй,  step - номер хода
bool player2(int l, int r, int step) {
    // обработка состояния игры после хода Пети
    // если Петя сделал первый ход
    if (step == 1) {
        // если он при этом победил,
        if (l + r >= 77)
            // требование задачи не выполнено
            return false;

        // разные ходы Вани
        // нам нужно, чтобы при любом ходе Вани Петя победил, т.е.
        // требование задачи было выполнено, поэтому используем И
        return player1(l + 1, r, step + 1) &&
               player1(l, r + 1, step + 1) &&
               player1(l * 2, r, step + 1) &&
               player1(l, r * 2, step + 1);
    } else { // если Петя сделал второй ход
        // он должен победить
        return l + r >= 77;
    }
}



// главный метод программы
int main() {
    // перебираем кол-во камней во второй куче
    for (int s = 1; s < 69; s++) {
        // запускаем обработку первого шага Пети, если
        // нас устраивает результат,
        if (player1(7, s, 1)) {
            // выводим кол-во камней во второй куче
            std::cout << s << std::endl;
        }
    }
    return 0;
}


