#include "humanPlayer.h"
#include <iostream>
#include <string>

using namespace std;

/**
 *
 */
HumanPlayer::HumanPlayer() {

}

/**
 *
 */
void HumanPlayer::getMove (Game& game, int& column, int& row) {

    cin >> column >> row;

    if (cin.fail()) {
        cin.clear();
        std::string junk;
        getline(cin, junk); // discard rest of this input line
    }
}

