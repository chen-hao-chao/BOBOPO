#include "Gashapon.h"

void Gashapon::run(){
    if(state==1){
        gashapon_cur++;
        if(gashapon_cur==gashapon_max_cur-1){
            state=2;

        }
    }
    else if(state==2){
        frame_cur++;
        if(frame_cur==frame_max_cur-1){
            state=3;
        }
    }
}
void Gashapon::draw(){
    al_draw_bitmap_region(img_gashapon,gashapon_cur*G_WIDTH,0,G_WIDTH,G_HEIGHT,G_POSITION_X,G_POSITION_Y,0);
    if(state==2||state==3){
        al_draw_bitmap_region(img_frame,frame_cur*F_WIDTH,0,F_WIDTH,F_HEIGHT,F_POSITION_X,F_POSITION_Y,0);
        if(treasure==0) al_draw_text(font,al_map_rgb(100,255,100),400,465,ALLEGRO_ALIGN_CENTER,"Teeth");
        else if(treasure==1) al_draw_text(font,al_map_rgb(100,255,100),400,465,ALLEGRO_ALIGN_CENTER,"Gun");
        else if(treasure==2) al_draw_text(font,al_map_rgb(100,255,100),400,465,ALLEGRO_ALIGN_CENTER,"Hand");
        else if(treasure==3) al_draw_text(font,al_map_rgb(100,255,100),400,465,ALLEGRO_ALIGN_CENTER,"Spider");
    }
}
void Gashapon::next_state(int money){
    if(state==0){if(money>=5)state++;}
    else if(state==3){state=0;}
    gashapon_cur=0;
    frame_cur=0;
}
