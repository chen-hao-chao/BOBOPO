#include "Stripe.h"

void Stripe::setting(float x, float y, int _r, int _g, int _b){
    r=_r;
    g=_g;
    b=_b;
    position_x1=x;
    position_y1=y;
}
void Stripe::run(){
    cur++;if(cur==10) cur=0;
    if(t){
        al_play_sample_instance(sound);
        if(height<HEIGHT){height+=3;}
        if(r<245) r+=10;
        if(b<245) b+=10;
    }
}
void Stripe::restore(){
    if(height>=0.5){height-=0.5;}
    if(r>=105) r-=5;//bad
    if(b>=105) b-=5;
}
void Stripe::draw(){
    al_draw_filled_rectangle(position_x1, position_y1, position_x1+width, position_y1-height, al_map_rgb(r,g,b));
    al_draw_bitmap_region(base,20*cur,0,20,20,position_x1+5, position_y1+8,0);
}
void Stripe::set_sound(const char *buffer){
    sample = al_load_sample(buffer);
    sound = al_create_sample_instance(sample);
}
