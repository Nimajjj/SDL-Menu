//
// Created by Ben on 23/04/2022.
//
#pragma once
#include <string>
#include <functional>
#include <SDL.h>
#include "../Color/Color.h"
#include "../Text/Text.h"

/**
 * @def Button
 *
 * @brief The Button class is a button that can be clicked and has a text label.
 */
class Button {
public:
    Button(const std::string& text, const SDL_Rect* rect, const Color& fill, std::function<void(void)> onClick);
    ~Button();

    /**
     * @def draw(SDL_Renderer** _renderer)
     *
     * @brief Draws the button to the screen
     *
     * @param renderer The renderer to draw to
     */
    void draw(SDL_Renderer** _renderer) const;

    /**
     * @def update(const int& x, const int& y)
     *
     * @brief Call the _onClick function if the mouse is over the button.
     * This methods should be called in the main loop -> event loop.
     *
     * @param x The x position of the mouse
     * @param y The y position of the mouse
     */
    void update(const int& x, const int& y);

private:
    const std::string _text;
    const SDL_Rect* _rect;
    const Color _fillColor;
    const std::function<void(void)> _onClick;
};
