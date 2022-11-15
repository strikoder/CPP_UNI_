#include <bits/stdc++.h>
#include <windows.h>
#include<mmsystem.h>
#include "RpgGame.h"
using namespace std;
// add AI
// add projectile animation

/*

           /   :.
          /     \\
       ,;/,      ::
   ___:c/.(      ||
 ,'  _|:)>>>--,-'B)>   >>------>
(  '---'\--'` _,'||
 `--.    \ ,-'   ;;
     |    \|    //
     |     \   ;'
     |_____|\,'
     :     :
     |  ,  |
     | : \ :
     | | : :
     | | | |
     | | |_`.
     '--`
                        ___  ________
                        \  \/ /  ___/
                         \   /\___ \
                          \_//____  >
                                  \/

                                                -----------------------------------------
                                                |                   ^                   |
                                                |                  / \                  |
                                                |                 / ^ \                 |
                                                |                / / \ \                |
                                                |               / / ^ \ \               |
                                                |              / / / \ \ \              |
                                                |             | |  \ /  | |             |
                                                |             | |  |V|  | |             |
                                                |             / /  |||  \ \             |
                                                |            | |   |||   | |            |
                                                |            | |   |||   | |            |
                                                |            / |   |||   | \            |
                                                |    ___    |  /   |||   \  |    ___    |
                                                |    \  \__ | |    |||    | | __/  /    |
                                                \     \  _ `' |    |||    | `' _  /     /
                                                 \     \ \`_  |    |||    |  _'/ /     /
                                                  \     \ \ `.'    |||    `.' / /     /
                                                   \     \ \       |||       / /     /
                                                    \     \ \      |||      / /     /
                                                     \     \ \     |||     / /     /
                                                      \     \ \    |||    / /     /
                                                       \     \ \   |||   / /     /
                                                        \     \ \  |||  / /     /
                                                         \     \ \ ||| / /     /
                                                          \     \ \|||/ /     /
                                                           \    (========)   /
                                                            \      |\|      /
                                                             \     |\|     /
                                                              \    |\|    /
                                                               \   (I)   /
                                                                \   U   /
                                                                 \     /
                                                                  \   /
                                                                   \ /
                                                                    V

*/



int main()
{
    PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //for generating a new number each time
    unsigned seed = time(0);
    srand(seed);


    RPG newgame;
    newgame.launchTheGame();

    return 0;
}
