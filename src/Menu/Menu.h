//
// Created by Ben on 25/04/2022.
//
#pragma once
#include <string>
#include <vector>
#include <functional>
#include <random>
#include <time.h>
#include "../RenderWindow/RenderWindow.h"
#include "../Text/Text.h"

/**
 * @def randRange(min, max)
 * @brief return a random number between min and max
 *
 * @warning they're absolutly 0 securities, don't try to break the program cause you will succeed
 *
 * @param min, max the range of the random number
 * @return int the random number
 */
#define randRange(min, max) (rand() % (max - min + 1) + min)

/**
 * @def Menu
 * @brief Menu class, create a window with a menu
 * each button is link to a given function
 *
 */
class Menu {
public:
    /**
     * @def Menu(std::string title, std::vector<std::string> buttons, std::vector<std::function<void()>> functions)
     * @brief Construct a new Menu object
     *
     * @param title         Title of the window + title of the menu
     * @param subTitles     All the sub titles of the menu are draw below the title
     * @param exoFunctions  Each given function will create a button with the following name : "exercice " + i
     */
    Menu(std::string title, std::vector<std::string> subTitles, std::vector<std::function<void(void)>> exoFunctions);
    ~Menu();

    /**
     * @def run()
     * @brief draw the menu
     */
    void run();

    /**
     * @def updateButtons()
     * @brief call _onClick for each button if mouse is over them.
     * To call during the event loop.
     */
    void updateButtons(bool click);

private:
    RenderWindow* _renderWindow;
};
