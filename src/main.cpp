#include <iostream>
#include <windows.h>
#include <SDL.h>
#include "Menu/Menu.h"

// Window size
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BUTTON_WIDTH 340
#define BUTTON_HEIGHT 50

// shits dont work
void test1() { std::cout << "exercice 1" << std::endl; }
void test2() { std::cout << "exercice 2" << std::endl; }
void test3() { std::cout << "exercice 3" << std::endl; }

int main(int argc, char* args[]) {
    // INITIALIZE
    Menu* menu = new Menu(
        "tp3 poo - ynov aix",
        std::vector<std::string>{"roy pierre", "borello benjamin"},
        std::vector<std::function<void(void)>>{test1, test2, test3, test1, test3}
    );
    bool running = true;



    // MAIN LOOP
    while (running) {
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

        menu->run();
    }

    // CLEAN UP
    delete menu;
    SDL_Quit();
    return 0;
}
