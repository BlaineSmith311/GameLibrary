/***************************************************
 * Name: Blaine Smith, (Lane Campbell)
 * Project: Game Library
 * File: library.h
 * Description:
 * Declares the Library class which manages
 * a list of Game objects using std::list.
 ***************************************************/

#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>
#include "game.h"

using namespace std;

/***************************************************
 * Class: Library
 * Description:
 * Handles all operations on the game list,
 * including insertion, deletion, searching,
 * loading, saving, and displaying games.
 ***************************************************/

class Library {
private:

    list<Game> games;
    string sort_by = "title";

public:

    Library() = default;

    void set_sort_by(string attribute); 
    
    void insert_sorted(string title, string publisher, string genre, float hoursPlayed, float price, int year);
    
    void read_file(string filename);
    void write_file(string filename);

    void find_genre(string genre);
    void find_game(string search);

    void delete_game(string title, int year);

    void print();
};

#endif