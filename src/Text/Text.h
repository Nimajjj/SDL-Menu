//
// Created by Ben on 23/04/2022.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SDL.h>
#include "../Color/Color.h"

/**
 * @def Text
 * @brief The Text class
 *
 * This class is used to create text objects and draw them.
 *
 * @author Ben
 * @version 1.0
 * @date 23/04/2022
 */
class Text {
public:
    /**
     * @def Text(std::string text, int x, int y, int size, Color* color)
     * @brief Construct a new Text object
     *
     * @param text The text to display
     * @param x, y The position of the text
     * @param size The size of the font
     * @param color The color of the text
     */
    Text(std::string text, int x, int y, int size, Color* color);

    /**
     * @def ~Text()
     * @brief Destroy the Text object
     */
    ~Text() = default;

    /**
     * @def draw(SDL_Renderer** _renderer)
     * @brief Draw the text
     *
     * @param renderer The renderer to draw the text to
     */
    void draw(SDL_Renderer** _renderer);

private:
    int _x, _y;
    int _fontSize;
    Color* _color;
    std::string _text;
    std::vector<int[5][5]> _font;
    std::map<char, std::vector<std::vector<int>>> _charMap; // char, vector of vectors of ints


    /**
     * @def _initAscii()
     * @brief init ascii matrix
     * I should certainly do it in an other way but anyway
     */
    void _initAscii();
};

/**
* [
 * [0, 1, 1, 1, 0],
 * [1, 0, 0, 0, 1],
 * [1, 1, 1, 1, 1],
 * [1, 0, 0, 0, 1],
 * [1, 0, 0, 0, 1],
 * ]
*/