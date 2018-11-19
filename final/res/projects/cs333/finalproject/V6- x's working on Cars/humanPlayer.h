
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <string>

#include "game.h"

/**
 * This class represents the structure of a single HumanPlayer.
 * This includes both the interface (public and private) and
 * attributes (private member data).
 */
class HumanPlayer {
    public:
        HumanPlayer ();

        /**
         * Get the human player's next move for this game.
         *
         * @param game current {Game} state
         * @param x column for next bite
         * @param y row for next bite
         */
        void getMove (Game& game, int& x, int& y);

};

#endif
