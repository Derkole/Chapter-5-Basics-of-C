#include <iostream>
#include <string>

int main()
{
    // Ввод оклада, % выполнение плана, нарушений
    std::cout << "Введите базовый оклад: ";
    float salary{};
    std::cin >> salary;

    std::cout << "Введите выполнение плана (%): ";
    int plan{};
    std::cin >> plan;

    std::cout << "Имеются ли дисциплинарные нарушения (1 - да, 0 - нет): ";
    bool violations{};
    std::cin >> violations;

    /* Инициализация переменных prize_no(нет премии), prize_yes(есть премия)
    tax(налог), size && size2(цифры для вычислений)*/
    std::string prize_no;
    float prize_yes{};
    float tax{salary * 0.13f};
    constexpr int size{100};
    constexpr int size2{90};

    // Проверка по дисцип. нарушениям, если есть= премии нет, если нет=премия есть(20% или 10%)
    if (violations) {prize_no = "Премия отменяется из-за дисциплинарных нарушений"; prize_yes = 0.0f;}
    else 
    { if (plan > size) { prize_yes = salary * 0.20f;} 
    else if (plan >= size2) {prize_yes = salary * 0.10f;} 
    else {prize_yes = 0.0f;}
    }

    // Инициализация выражением final(итоговой зарплаты)
    float final{salary - tax + prize_yes};

    // Вывод salary(оклад), tax(налог), final(итоговой зарплаты), а так же проверка и вывод по премии(prize_no, prize_yes)
    std::cout << "Базовый оклад: " << salary << '\n';
    if (violations) {std::cout << "Премия: " << prize_no << '\n';}
    else {std::cout << "Премия: " << prize_yes << '\n';}
    std::cout << "Налог: " << tax << '\n';
    std::cout << "Итоговая зарплата: " << final << '\n';

    return 0;
}