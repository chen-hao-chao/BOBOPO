#include "GameWindow.h"

int main(void){
    GameWindow *Game= new GameWindow();
    Game->game_play();
    delete Game;
    return 0;
}
