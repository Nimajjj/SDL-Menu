#include <iostream>
#include <SDL.h>
#include "Menu/Menu.h"

// shits dont work
void test1() { std::cout << "exercice 1" << std::endl; }
void test2() { std::cout << "exercice 2" << std::endl; }
void test3() { std::cout << "exercice 3" << std::endl; }

int main(int argc, char* args[]) {
    // INITIALIZE
    Menu* menu = new Menu(
        "tp3 poo - ynov aix",   // title
        std::vector<std::string>{"roy pierre", "borello benjamin"}, // subtitle
        std::vector<std::function<void(void)>>{ // exercices functions
            test1,
            test2,
            test3,
            test1,
            test3
        }
    );
    bool running = true;

    // MAIN LOOP
    while (running) {
        // EVENTS
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    menu->updateButtons();
                default:
                    break;
            }
        }

        // DRAW
        menu->run();
    }

    // CLEAN UP
    delete menu;
    SDL_Quit();
    return 0;
}
