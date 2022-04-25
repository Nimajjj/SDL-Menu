#include <iostream>
#include <windows.h>
#include <SDL.h>
#include "RenderWindow/RenderWindow.h"

// Window size
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BUTTON_WIDTH 340
#define BUTTON_HEIGHT 50

// shits dont work
void test1() {
    if(AllocConsole()) {
        freopen("CONOUT$", "w", stdout);
        SetConsoleTitle("Debug Console");
    }

    std::cout << "Hello World!" << std::endl;
}
void test2() { std::cout << "exercice 2" << std::endl; }
void test3() { std::cout << "exercice 3" << std::endl; }

int main(int argc, char* args[]) {
    // INITIALIZE
    auto master = new RenderWindow("Menu SDL v0.1", WINDOW_WIDTH, WINDOW_HEIGHT);
    bool running = true;

    master->createText("ynov aix - tp3 poo", 50, 15, 5, new Color(255, 255, 0));
    master->createText("roy pierre", 50, 50, 5, new Color(0, 255, 255));
    master->createText("borello benjamin", 50, 80, 5, new Color(255, 0, 255));

    master->createButton(new std::string("exercice 1"), 50, 150, BUTTON_WIDTH, BUTTON_HEIGHT, Color(50, 50, 50), test1);
    master->createButton(new std::string("exercice 2"), 50, 250, BUTTON_WIDTH, BUTTON_HEIGHT, Color(50, 50, 50), test2);
    master->createButton(new std::string("exercice 3"), 50, 350, BUTTON_WIDTH, BUTTON_HEIGHT, Color(50, 50, 50), test3);

    // MAIN LOOP
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    master->updateButtons();
                default:
                    break;
            }
        }

        master->run();
    }

    // CLEAN UP
    delete master;
    SDL_Quit();
    return 0;
}
