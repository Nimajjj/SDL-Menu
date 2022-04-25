//
// Created by Ben on 25/04/2022.
//
#pragma once
#include <string>
#include <vector>
#include <functional>
#include <random>
#include "../RenderWindow/RenderWindow.h"
#include "../Text/Text.h"

#define randRange(min, max) (rand() % (max - min + 1) + min)

/**
 * @def Menu
 * @brief Menu class
 *
 */
class Menu {
public:
    Menu(std::string title, std::vector<std::string> subTitles, std::vector<std::function<void(void)>> exoFunctions);
    ~Menu();

    void run();
    void updateButtons();

private:
    RenderWindow* _renderWindow;
};
