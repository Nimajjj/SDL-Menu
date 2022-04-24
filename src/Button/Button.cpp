//
// Created by Ben on 23/04/2022.
//
#include "Button.h"

// CONSTRUCTOR
Button::Button(const std::string& text, const SDL_Rect* rect, const Color& fill, std::function<void(void)> onClick):
    _text(text),
    _rect(rect),
    _fillColor(fill),
    _onClick(onClick)
{}

// DESTUCTOR
Button::~Button() {
    delete _rect;
}

// DRAW
void Button::draw(SDL_Renderer** _renderer) const {
    SDL_SetRenderDrawColor(
            *_renderer,
            _fillColor.r,
            _fillColor.g,
            _fillColor.b,
            _fillColor.a
    );
    SDL_RenderFillRect(*_renderer, _rect);

    // I am sorry for this ...
    int fontSize = 5;
    int letterSize = fontSize * 5;
    int textLength = _text.length();
    int textWidth = (letterSize * textLength) + (5 * (textLength - 1));
    int textHeight = fontSize * 5;

    int posX = _rect->x + ((_rect->w - textWidth) / 2 );
    int posY = _rect->y + ((_rect->h - textHeight) / 2);
    auto btText = new Text(_text, posX, posY, fontSize, new Color(255, 255, 255));
    btText->draw(_renderer);
}

void Button::update(const int& x, const int& y) {
    if (x >= _rect->x && x <= _rect->x + _rect->w && y >= _rect->y && y <= _rect->y + _rect->h) {
        _onClick();
    }
}