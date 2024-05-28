// pragma once is a header guard to prevent multiple inclusions of the same header file
#pragma once

// Including necessary header files
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <process.h> 
#include "Player.h"
#include "gameConfig.h"
#include "shape.h"
#include "Point.h"
#include <cstdlib>
#include <ctime>

// Constants for player starting points
#define P1_FIRST_POINT_X 18
#define P1_FIRST_POINT_Y 3
#define P2_FIRST_POINT_X 88
#define P2_FIRST_POINT_Y 3

// ANSI color escape sequences for console text color
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"

// Using the standard namespace
using namespace std;

// Function declarations

// Function to display the main menu and get the user's choice
void menu(int& check);

// Function to print the main menu
void printMenu();

// Function to print game instructions
void printInstructions();

// Function to set the cursor position on the console
void gotoxy(int x, int y);

// Function to start the game
void startGame();

// Function to check if a key press corresponds to a player action
int isPlayer(char pressed);
