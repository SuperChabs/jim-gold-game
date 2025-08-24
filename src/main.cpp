#include "game.h"
#include <iostream>

int main() {
    // Створення та запуск гри
    Game game(1080, 720, "Sigma Game.com.pidoras");

    try {
        game.Run();
    } catch (const std::exception& e) {
        std::cerr << "Game error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
