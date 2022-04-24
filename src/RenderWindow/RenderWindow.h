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

class RenderWindow {
public:
    /**
     * @brief Constructor, nothing special here
     * @param title     The title of the window
     * @param width     The width of the window
     * @param height    The of the window
     */
    RenderWindow(const std::string title, const int& width, const int& height);

    /**
     * @brief: Destructor
     * Destroys following:
     *  - The window
     *  - The renderer
     *  - All buttons
     *  - All texts
     */
    ~RenderWindow();

    /**
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
     * @brief Create a Text and store it in the vector of texts for future displaying
     * @param text
     * @param x, y
     * @param size
     * @param color
     */
    void createText(std::string text, int x, int y, int size, Color* color);

    /**
     * @brief Prepare rendering of all the buttons and texts created before.
     * Sort of main loop
     * @warning The buttons are displayed before text.
     * @warning Buttons and text are displayed in the order they were created.
     */
    void run();

    /**
     * @brief return a reference to the renderer of the window
     * @return SDL_Renderer*&
     * @warning The returned value isn't a const and can be modified.
     */
    SDL_Renderer*& getRenderer();

    /**
     * @brief retrieve the mouse position relative to the focus window
     * @param x
     * @param y
     */
    void getMousePosition(int& x, int& y) const;

    void updateButtons() const;

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    std::vector<Button*> _buttons;
    std::vector<Text*> _texts;

    /**
     * @brief Init all SDL shits
     */
    void _initSDL();

    /**
     * @brief Clear everything on screen and put black screen
     */
    void _clear();

    /**
     * @brief Call SDL_RenderPresent(this->_renderer);
     * Has for effect to display everithing on pre rendered before (cf. this->run())
     */
    void _display();
};

