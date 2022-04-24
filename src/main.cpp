#include <iostream>
#include <windows.h>
#include <SDL.h>
#include "RenderWindow/RenderWindow.h"
#include "Text/Text.h"

// Window size
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BUTTON_WIDTH 340
#define BUTTON_HEIGHT 50

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

    master->createButton(new std::string("exercice 1"), 100, 50, BUTTON_WIDTH, BUTTON_HEIGHT, Color(50, 50, 50, 255), test1);
    master->createButton(new std::string("exercice 2"), 100, 150, BUTTON_WIDTH, BUTTON_HEIGHT, Color(50, 50, 50, 255), test2);
    master->createButton(new std::string("exercice 3"), 100, 250, BUTTON_WIDTH, BUTTON_HEIGHT, Color(50, 50, 50, 255), test3);

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
