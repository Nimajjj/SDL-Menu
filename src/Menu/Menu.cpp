//
// Created by Ben on 25/04/2022.
//

#include "Menu.h"

Menu::Menu(std::string title, std::vector<std::string> subTitles, std::vector<std::function<void(void)>> exoFunctions) {
    srand(time(NULL));
    _renderWindow = new RenderWindow(title, 640, 544);
    auto color = new Color(255, 255, 255);
    _renderWindow->createText(title, 30, 10, 5, color);
    delete color;

    int min = 150;
    int max = 250;
    for (int i = 0; i < subTitles.size(); i++) {
        _renderWindow->createText(
                subTitles[i],
                30,
                (50 + (i * 30)),
                5,
                new Color(randRange(min, max), randRange(min, max), randRange(min, max))
        );
    }

    for (int i = 0; i < exoFunctions.size(); i++) {
        auto text = new std::string("exercice " + std::to_string(i + 1));
        _renderWindow->createButton(
                text,
                50,
                (150 + (i * 75)),
                340,
                50,
                Color(50, 50, 50),
                exoFunctions[i]
        );
        delete text;
    }
}

Menu::~Menu() {
    delete _renderWindow;
}

void Menu::run(){
    _renderWindow->run();
}

void Menu::updateButtons(bool click) {
    _renderWindow->updateButtons(click);
}