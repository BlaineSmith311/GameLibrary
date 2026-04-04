/***************************************************
 * Name: Blaine Smith, (Lane Campbell)
 * Project: Game Library
 * Class: (CSCI325)
 * Date: April 3, 2026
 * File: main.cpp
 * Description:
 * This file contains the main driver for the Game
 * Library program. It provides a menu-driven
 * interface that allows the user to add, delete,
 * search, display, load, and save games.
 ***************************************************/

#include <iostream>
#include "library.h"

using namespace std;

/***************************************************
 * Function: main
 * Description:
 * Runs the main program loop using a menu system.
 * Processes user input and calls appropriate
 * library functions.
 ***************************************************/

int main() {
    Library lib;
    string sort_by = "title";

    string filename = "games.txt";
    lib.read_file(filename);

    bool run = true;

    while (run) 
    {
        int choice;

        cout << "\n--- Game Library ---\n";
        cout << "1. Add Game\n";
        cout << "2. Show All Games\n";
        cout << "3. Search by Genre\n";
        cout << "4. Search by Title\n";
        cout << "5. Delete Game\n";
        cout << "6. Sort Library by Attribute\n";
        cout << "7. Exit\n";
        cout << "--------------------\n";
        cout << "Choice: ";

        if (!(cin >> choice)) 
        { 
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            cin.clear(); // clear cin
            cin.ignore(1000, '\n'); // discard bad input
            continue;
        }

        cin.ignore(1000, '\n'); // discard leftover newline

        switch (choice) 
        {
            case 1: 
            { 
                Game g;
                cout << "Enter title: ";
                getline(cin, g.title);
                cout << "Enter publisher: ";
                getline(cin, g.publisher);
                cout << "Enter genre: ";
                getline(cin, g.genre);
                cout << "Enter hours played: ";
                cin >> g.hoursPlayed;
                cout << "Enter price: ";
                cin >> g.price;
                cout << "Enter year: ";
                cin >> g.year;
                cin.ignore(1000, '\n'); // clear newline after numbers
                lib.insert_sorted(g.title, g.publisher, g.genre, g.hoursPlayed, g.price, g.year);
                break;
            }

            case 2: // Show All Games
            {
                lib.print();
                break;
            }

            case 3: 
            { 
                string genre;
                cout << "Enter genre to search: ";
                getline(cin, genre);
                lib.find_genre(genre);
                break;
            }

            case 4: 
            { 
                string search;
                cout << "Enter title to search: ";
                getline(cin, search);
                lib.find_game(search);
                break;
            }

            case 5: 
            { 
                string title;
                int year;
                cout << "Enter title of game to delete: ";
                getline(cin, title);
                cout << "Enter year of game to delete: ";
                cin >> year;
                cin.ignore(1000, '\n'); // clear newline
                lib.delete_game(title, year);
                break;
            }

            case 6: 
            {
                cout << "Set library sort by (title, publisher, genre, hours played, price, year): ";
                getline(cin, sort_by);
                lib.set_sort_by(sort_by);
                break;
            }

            case 7: 
            {
                cout << "Exiting.\n";
                run = false;
                break;
            }

            default:
            {
                cout << "Choice out of range. Please enter a number between 1 and 7.\n";
                break;
            }
        }
    }

    return 0;
}