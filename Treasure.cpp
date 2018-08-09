#include "Treasure.h"

void Treasure::animate(){
    cur++;
    if(cur==max_cur){cur=0;}
}
void Treasure::draw(bool display){
    if(display) al_draw_bitmap_region(img1,cur*width,0,width,height,position_x,position_y,0);
    else al_draw_bitmap(img2,position_x,position_y,0);
}
void Treasure::set_position(float x, float y){
    position_x=x;
    position_y=y;
}
void Treasure::set_size(float w, float h){
    width=w;
    height=h;
}
void Treasure::set_max_cur(int mc){
    max_cur=mc;
}
void Treasure::set_img(const char *name1, const char *name2){
    img1=al_load_bitmap(name1);
    img2=al_load_bitmap(name2);
}
