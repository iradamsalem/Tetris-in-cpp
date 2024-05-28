#pragma once
#include <iostream>
#include "Point.h"

// Constants defining initial positions of players
#define P1_FIRST_POINT_X 18
#define P1_FIRST_POINT_Y 3
#define P2_FIRST_POINT_X 88
#define P2_FIRST_POINT_Y 3

using namespace std;

class Player
{
private:
    // Constants defining the dimensions of the game board
    static constexpr int GAME_WIDTH = 18;
    static constexpr int GAME_HEIGHT = 12;

    // Constants defining the minimum coordinates for the game board
    static constexpr int MIN_X = 10;
    static constexpr int MIN_Y = 3;

    // Point representing the starting index for each player
    Point indextobegin;

    // 2D array representing the game board
    Point board[20][14];

    // Point representing the first point for the player's shape
    Point firstpoint;

    // Variable to store the type of the new shape
    int newshape = 0;

    int score=0;

public:
    // Function to get the current first point
    Point getpoint() const;

    // Function to set the first point for a new shape
    void set(const Point& p);

    // Function to print the game board for a player
    void printBoard(int p);

    // Function to check if a movement is valid for a given shape and player
    int checkMovement(const Point& p1, const Point& p2, const Point& p3, const Point& p4, int player);

    // Function to update the game board when a shape is taken by a player
    void updateTaken(const Point& p1, const Point& p2, const Point& p3, const Point& p4, int player);

    // Function to initialize the game board
    void setBoard();

    // Function to set a new shape for the player
    void setNewShape();

    // Function to get the type of the new shape
    int getNewShape() const;

    // Function to set the first point based on the player
    void setfirstpoint(int p);

    // Function to print the last state of the game board for a player
    void printLastBoard(int p);

    // Function to check if the game is over for a player
    int checkGameOver() const;

    void resetBoard();

    void setscore() { score+=4; };
    int getscore()const { return score; };
};
