#include <iostream>

#include "Engine.h"

int main(int argc, char** argv)
{
    bool bRestart = true;

    do {
        Engine engine = Engine();
        engine.run(&bRestart);
    } while (bRestart);

    int i = 0;
    std::cout << "\nPress Enter to Continue...";
    std::cin >> i;
}
