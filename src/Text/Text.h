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


class Text {
public:
    Text(std::string text, int x, int y, int size, Color* color);
    ~Text() = default;

    void draw(SDL_Renderer** _renderer);

private:
    int _x, _y;
    int _fontSize;
    Color* _color;
    std::string _text;
    std::vector<int[5][5]> _font;
    std::map<char, std::vector<std::vector<int>>> _charMap; // char, vector of vectors of ints

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