// pragma once is a header guard to prevent multiple inclusions of the same header file
#pragma once

// Including necessary header files
#include "game.h"
#include "Point.h"
#include <cmath>

// Define the mathematical constant PI for use in calculations
#define M_PI 3.14159265358979323846264338327950288

// Class definition for 'shape'
class shape
{
private:
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    Point lastpoint[20];

public:
    // Function to set the points of the shape
    void set(const Point& p, int ind);

    // Function to print the shape
    void printshape() const;

    // Function to delete the shape
    void deleteshape() const;

    // Function to handle movement of the shape based on user input
    void movement(char input, Player& player, int p);

    // Function to rotate the shape by a specified angle
    void rotateS(float angleInDegrees, Player& player, int p);
};
