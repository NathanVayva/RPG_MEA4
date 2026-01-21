#include "utilitaire.hpp"

int sign(int x) {
    return (x > 0) - (x < 0);
}

char getch() {
    char buf = 0;
    struct termios old = {0};

    // Sauvegarde de l'état du terminal
    if (tcgetattr(STDIN_FILENO, &old) < 0)
        perror("tcgetattr");

    struct termios newt = old;

    // Désactivation du mode canonique et de l'écho
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN]  = 1;
    newt.c_cc[VTIME] = 0;

    // Application immédiate
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) < 0)
        perror("tcsetattr");

    // Lecture d'un caractère
    if (read(STDIN_FILENO, &buf, 1) < 0)
        perror("read");

    // Restauration du terminal
    if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0)
        perror("tcsetattr");

    return buf;
}
