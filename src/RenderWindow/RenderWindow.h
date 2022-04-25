//
// Created by Ben on 23/04/2022.
//
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <SDL.h>
#include <SDL_image.h>
#include "../Button/Button.h"
#include "../Text/Text.h"

/**
 * @def RenderWindow
 * @brief The RenderWindow class
 *
 * This class is used to create a window and draw objects to it.
 *
 * @author Ben
 * @version 1.0
 * @date 23/04/2022
 */
class RenderWindow {
public:
    /**
     * @def RenderWindow(const std::string title, const int& width, const int& height)
     * @brief Constructor, nothing special here
     * @param title     The title of the window
     * @param width     The width of the window
     * @param height    The of the window
     */
    RenderWindow(const std::string title, const int& width, const int& height);

    /**
     * @def ~RenderWindow()
     * @brief: Destructor
     * Destroys following:
     *  - The window
     *  - The renderer
     *  - All buttons
     *  - All texts
     */
    ~RenderWindow();

    /**
     * @briefcreateButton(const std::string* text, const int& x, const int& y, const int& w, const int& h, const Color& fill, std::function<void(void)> onClick);
     * @brief Create a Button and store it in the vector of buttons for future displaying.
     * A text can be added to the button and is automatically centered on x and y axis.
     * @warning The button is not displayed until the display function is called.
     * @warning The button can be shorter than the text. That don't produce any bug, the result is simply ugly.
     * @param text  The text to be displayed on the button.
     * @param x, y  The position of the button.
     * @param w, h  The width and height of the button.
     * @param fill  The color which fill of the button.
     * @param onClick
     */
    void createButton(const std::string* text, const int& x, const int& y, const int& w, const int& h, const Color& fill, std::function<void(void)> onClick);

    /**
     * @def createText(std::string text, int x, int y, int size, Color* color)
     * @brief Create a Text and store it in the vector of texts for future displaying
     * @param text
     * @param x, y
     * @param size
     * @param color
     */
    void createText(std::string text, int x, int y, int size, Color* color);

    /**
     * @def run()
     * @brief Prepare rendering of all the buttons and texts created before.
     * Sort of main loop
     * @warning The buttons are displayed before text.
     * @warning Buttons and text are displayed in the order they were created.
     */
    void run();

    /**
     * @def getRenderer()
     * @brief return a reference to the renderer of the window
     * @return SDL_Renderer*&
     * @warning The returned value isn't a const and can be modified.
     */
    SDL_Renderer*& getRenderer();

    /**
     * @def getMousePosition(int& x, int& y) const
     * @brief retrieve the mouse position relative to the focus window
     * @param x
     * @param y
     */
    void getMousePosition(int& x, int& y) const;

    /**
     * @def updateButtons()
     * @brief call _onClick for each button if mouse is over them.
     * To call during the event loop.
     */
    void updateButtons() const;

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    std::vector<Button*> _buttons;
    std::vector<Text*> _texts;

    /**
     * @def _initSDL()
     * @brief Init all SDL shits
     */
    void _initSDL();

    /**
     * @def _clear()
     * @brief Clear everything on screen and put black screen
     */
    void _clear();

    /**
     * @def _display()
     * @brief Call SDL_RenderPresent(this->_renderer);
     * Has for effect to display everithing on pre rendered before (cf. this->run())
     */
    void _display();
};

