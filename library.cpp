/***************************************************
 * Name: Blaine Smith, (Lane Campbell)
 * Project: Game Library
 * File: library.cpp
 * Description:
 * Implements all member functions of the
 * Library class.
 ***************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "library.h"
#include "game.h"

using namespace std;

void Library::set_sort_by(string attribute) 
{
    sort_by = attribute;
}

/***************************************************
 * Function: insert_sorted
 * Description:
 * Inserts a game into the list in alphabetical
 * order based on the game title.
 * Parameters:
 *   Game g - game to insert
 * Returns:
 *   void
 ***************************************************/

void Library::insert_sorted(string title, string publisher, string genre, float hoursPlayed, float price, int year) 
{
    Game new_game{title, publisher, genre, hoursPlayed, price, year};

    auto it = games.begin();

    auto compare = [this](const Game &a, const Game &b) 
    {
        if (sort_by == "title") // descend aplphabetically
        {
            return a.title < b.title;
        } 
        else if (sort_by == "publisher") // descend aplphabetically
        {
            return a.publisher < b.publisher;
        } 
        else if (sort_by == "genre") // descend aplphabetically
        {
            return a.genre < b.genre;
        } 
        else if (sort_by == "hours played") // ascend from greatest to least
        {
            return a.hoursPlayed > b.hoursPlayed;
        } 
        else if (sort_by == "price") // descend from greatest to least
        {
            return a.price > b.price;
        } 
        else if (sort_by == "year") // descend from newest to oldest
        {
            return a.year > b.year;
        }
        return a.title < b.title; // worst case scenario it just defaults to title sorting
    };

    while (it != games.end() && compare(*it, new_game)) 
    {
        ++it;
    }

    games.insert(it, new_game);

    write_file("games.txt"); // save changes to file after insertion
}

void Library::read_file(string filename) 
{
    ifstream input(filename);
    if (!input) 
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string title, publisher, genre;
    float hoursPlayed, price;
    int year;

    while (getline(input, title))
    {
        getline(input, publisher);
        getline(input, genre);
        input >> hoursPlayed >> price >> year;
        input.ignore(); // Ignore the newline character
        insert_sorted(title, publisher, genre, hoursPlayed, price, year);
    }

    input.close();
}

void Library::write_file(string filename) 
{
    ofstream output(filename);
    if (!output) 
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto &g : games) 
    {
        output << g.title << "\n" 
               << g.publisher << "\n" 
               << g.genre << "\n" 
               << g.hoursPlayed << "\n" 
               << g.price << "\n" 
               << g.year << "\n";
    }

    output.close();
}

/***************************************************
 * Function: find_genre
 * Description:
 * Displays all games that match a given genre.
 * Parameters:
 *   string genre - genre to search for
 * Returns:
 *   void
 ***************************************************/

void Library::find_genre(string genre) 
{
    cout << setw(30) << "Title" 
         << setw(20) << "Publisher" 
         << setw(15) << "Genre" 
         << setw(15) << "Hours Played" 
         << setw(10) << "Price" 
         << setw(10) << "Year" << "\n";
    cout << "\n";

    for (const auto &g : games) 
    {
        if (g.genre == genre) 
        {
            cout << setw(30) << g.title 
                 << setw(20) << g.publisher 
                 << setw(15) << g.genre 
                 << setw(15) << g.hoursPlayed 
                 << setw(10) << g.price 
                 << setw(10) << g.year << "\n";
        }
    }
}

/***************************************************
 * Function: find_game
 * Description:
 * Searches for games containing a given string
 * in the title and displays matching results.
 * Parameters:
 *   string title - search term
 * Returns:
 *   void
 ***************************************************/

void Library::find_game(string search) 
{
    cout << setw(30) << "Title" 
         << setw(20) << "Publisher" 
         << setw(15) << "Genre" 
         << setw(15) << "Hours Played" 
         << setw(10) << "Price" 
         << setw(10) << "Year" << "\n";
    cout << "\n";

    for (const auto &g : games) 
    {
        if (g.title.find(search) != string::npos) 
        {
            cout << setw(30) << g.title 
             << setw(20) << g.publisher 
             << setw(15) << g.genre 
             << setw(15) << g.hoursPlayed 
             << setw(10) << g.price 
             << setw(10) << g.year << "\n";
        }
    }
}

/***************************************************
 * Function: delete_game
 * Description:
 * Removes a game from the list using title
 * and release year.
 * Parameters:
 *   string title - game title
 *   int year - release year
 * Returns:
 *   void
 ***************************************************/

void Library::delete_game(string title, int year) 
{
    for (auto it = games.begin(); it != games.end(); ++it) 
    {
        if (it->title == title && it->year == year) 
        {
            games.erase(it);
            cout << "Deleted: " << title << " (" << year << ")\n";
            write_file("games.txt"); // save changes to file after deletion
            return;
        }
    }
    cout << "Game not found: " << title << " (" << year << ")\n";
}

/***************************************************
 * Function: print
 * Description:
 * Displays all games in the library in a
 * formatted manner.
 * Returns:
 *   void
 ***************************************************/

// Print all games
void Library::print() 
{
    games.clear(); // clear the list to avoid duplicates when printing after insertion
    read_file("games.txt"); // re-read the file to populate the list with current data

    cout << setw(30) << "Title" 
         << setw(20) << "Publisher" 
         << setw(15) << "Genre" 
         << setw(15) << "Hours Played" 
         << setw(10) << "Price" 
         << setw(10) << "Year" << "\n";
    cout << "\n";

    for (const auto &g : games)
    {
        cout << setw(30) << g.title 
             << setw(20) << g.publisher 
             << setw(15) << g.genre 
             << setw(15) << g.hoursPlayed 
             << setw(10) << g.price 
             << setw(10) << g.year << "\n";
    }
}

/***************************************************
 * Function: load
 * Description:
 * Loads game data from a file into the list.
 * Parameters:
 *   string filename - file to read from
 * Returns:
 *   void
 ***************************************************/

 /***************************************************
 * Function: save
 * Description:
 * Writes all game data from the list to a file.
 * Parameters:
 *   string filename - file to write to
 * Returns:
 *   void
 ***************************************************/

 /***************************************************
 * Function: push_back
 * Description:
 * Adds a game to the end of the list.
 * Parameters:
 *   Game g - game to add
 * Returns:
 *   void
 ***************************************************/