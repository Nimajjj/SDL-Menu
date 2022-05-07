//
// Created by Ben on 23/04/2022.
//
#include "RenderWindow.h"

// CONSTRUCTOR //
RenderWindow::RenderWindow(const std::string title, const int& width, const int& height)
        : _window(nullptr), _renderer(nullptr)
{
    _initSDL();
    this->_window = SDL_CreateWindow(
            title.c_str(),              // .c_str() converts string to char*
            SDL_WINDOWPOS_UNDEFINED,    // x position
            SDL_WINDOWPOS_UNDEFINED,    // y position
            width,                      // width
            height,                     // height
            SDL_WINDOW_SHOWN            // flags
    );

    if (this->_window == nullptr) { std::cout << "_window failed to init: " << SDL_GetError() << std::endl; }

    this->_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}


// DESTRUCTOR //
RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);

    for (auto text : this->_texts) {
        delete text;
    }

    for (auto button : this->_buttons) {
        delete button;
    }

}


// MAIN LOOPS METHODS //
void RenderWindow::run() {
    this->_clear();

    for (auto bt : this->_buttons) {
        bt->draw(&_renderer);
    }

    for (auto txt : this->_texts) {
        txt->draw(&_renderer);
    }

    this->_display();
}


// MANAGE SHITS //
void RenderWindow::createButton(const std::string* text, const int& x, const int& y, const int& w, const int& h, const Color& fill, std::function<void(void)> onClick) {
    _buttons.push_back(new Button(*text, new SDL_Rect{x, y, w, h}, fill, onClick));
}

void RenderWindow::createText(std::string text, int x, int y, int size, Color* color) {
    _texts.push_back(new Text(text, x, y, size, color));
}

void RenderWindow::updateButtons(bool click) const {
    for (auto bt : _buttons) {
        int x, y;
        this->getMousePosition(x, y);
        bt->update(x, y, click);
    }
}


// GETTERS //
SDL_Renderer*& RenderWindow::getRenderer() { return this->_renderer; }

void RenderWindow::getMousePosition(int& x, int& y) const { SDL_GetMouseState(&x, &y); }


// PRIVATE METHODS //
void RenderWindow::_initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) > 0) { std::cout << "SDL_Init HAS FAILED: " << SDL_GetError() << std::endl; }
}

void RenderWindow::_clear() {
    SDL_SetRenderDrawColor( _renderer, 0, 0, 0, 255 );
    SDL_RenderClear(this->_renderer);
}

void RenderWindow::_display() {
    SDL_RenderPresent(this->_renderer);
}
