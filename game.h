/***************************************************
 * Name: Blaine Smith, (Lane Campbell)
 * Project: Game Library
 * File: game.h
 * Description:
 * Defines the Game struct used to store
 * information about each game.
 ***************************************************/
#ifndef GAME_H
#define GAME_H

#include <string>
using namespace std;

/***************************************************
 * Struct: Game
 * Description:
 * Represents a single game with attributes:
 * title, publisher, genre, hours played,
 * price, and release year.
 ***************************************************/

struct Game {
    string title;
    string publisher;
    string genre;
    float hoursPlayed;
    float price;
    int year;
};

#endif