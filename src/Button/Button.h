//
// Created by Ben on 23/04/2022.
//
#pragma once
#include <string>
#include <functional>
#include <SDL.h>
#include "../Color/Color.h"
#include "../Text/Text.h"

class Button {
public:
    Button(const std::string& text, const SDL_Rect* rect, const Color& fill, std::function<void(void)> onClick);
    ~Button();

    void draw(SDL_Renderer** _renderer) const;
    void update(const int& x, const int& y);

private:
    const std::string _text;
    const SDL_Rect* _rect;
    const Color _fillColor;
    const std::function<void(void)> _onClick;
};
