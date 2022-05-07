//
// Created by Ben on 23/04/2022.
//

#include "Text.h"

Text::Text(std::string text, int x, int y, int size, Color* color) :
    _text(text),
    _x(x),
    _y(y),
    _fontSize(size),
    _color(color)
{
    _initAscii();
}

void Text::draw(SDL_Renderer** _renderer) {
    for (unsigned i = 0; i < _text.length(); i++) {
        if (!_charMap.count(_text[i])) { break; }   // if _charMap don't handle a character
        for (unsigned y = 0; y < 5; y++) {
            for (unsigned x = 0; x < 5; x++) {
                if (_charMap[_text[i]][y][x] != 1) continue;
                int xPos = (x * _fontSize) + (i * (5 * _fontSize + 5)) + _x;
                int yPos = y * _fontSize + _y;

                auto rect = new SDL_Rect{xPos, yPos, _fontSize, _fontSize};
                SDL_SetRenderDrawColor( *_renderer, _color->r, _color->g, _color->b, _color->a );
                SDL_RenderFillRect(*_renderer, rect);
                delete rect;
            }
        }
    }
}


void Text::_initAscii() {
    std::vector<std::vector<int>> space {
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 } };
    std::vector<std::vector<int>> tiret {
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 } };

    std::vector<std::vector<int>> p {
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 0 } };
    std::vector<std::vector<int>> o {
        { 0, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 0 } };
    std::vector<std::vector<int>> y {
        { 1, 0, 0, 0, 1 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 1, 0, 0, 0, 0 } };
    std::vector<std::vector<int>> n {
        { 1, 0, 0, 0, 1 },
        { 1, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1 },
        { 1, 0, 0, 1, 1 },
        { 1, 0, 0, 0, 1 } };
    std::vector<std::vector<int>> v {
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0 } };
    std::vector<std::vector<int>> a {
        { 0, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 } };
    std::vector<std::vector<int>> b {
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 0 } };
    std::vector<std::vector<int>> l {
        { 1, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1 } };
    std::vector<std::vector<int>> j {
        { 1, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 1, 0, 1, 0, 0 },
        { 1, 1, 1, 0, 0 } };
    std::vector<std::vector<int>> m {
        { 1, 0, 0, 0, 1 },
        { 1, 1, 0, 1, 1 },
        { 1, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 1 } };
    std::vector<std::vector<int>> t {
        { 1, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 } };
    std::vector<std::vector<int>> e {
        { 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1 } };
    std::vector<std::vector<int>> x {
        { 1, 0, 0, 0, 1 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 1, 0, 0, 0, 1 } };
    std::vector<std::vector<int>> r {
        { 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 0, 0, 1, 0 },
        { 1, 0, 0, 0, 1 } };
    std::vector<std::vector<int>> c {
        { 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1 } };
    std::vector<std::vector<int>> i {
        { 0, 1, 1, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 1, 1, 1, 0 } };

    std::vector<std::vector<int>> n1 {
        { 0, 0, 1, 0, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 1, 1, 1, 0 } };
    std::vector<std::vector<int>> n2 {
        { 0, 0, 1, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 1, 1, 1, 0 } };
    std::vector<std::vector<int>> n3 {
        { 0, 1, 1, 1, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 1, 1, 0, 0 } };
    std::vector<std::vector<int>> n4 {
        { 0, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 0, 0, 1, 0 } };
    std::vector<std::vector<int>> n5 {
        { 0, 1, 1, 1, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 1, 1, 0, 0 } };

    // MISC //
    this->_charMap[' '] = space;
    this->_charMap['-'] = tiret;

    // LETTERS //
    this->_charMap['p'] = p;
    this->_charMap['o'] = o;
    this->_charMap['y'] = y;
    this->_charMap['n'] = n;
    this->_charMap['v'] = v;
    this->_charMap['a'] = a;
    this->_charMap['b'] = b;
    this->_charMap['l'] = l;
    this->_charMap['j'] = j;
    this->_charMap['m'] = m;
    this->_charMap['t'] = t;
    this->_charMap['e'] = e;
    this->_charMap['x'] = x;
    this->_charMap['r'] = r;
    this->_charMap['c'] = c;
    this->_charMap['i'] = i;

    // NUMBERS //
    this->_charMap['1'] = n1;
    this->_charMap['2'] = n2;
    this->_charMap['3'] = n3;
    this->_charMap['4'] = n4;
    this->_charMap['5'] = n5;

}
