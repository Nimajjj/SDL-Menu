//
// Created by Ben on 23/04/2022.
//
#pragma once

struct Color {
    double r, g, b, a;

    Color() : r(0), g(0), b(0), a(1) {}
    Color(double r, double g, double b, double a = 1) : r(r), g(g), b(b), a(a) {}
    ~Color() = default;
};
