#include "Animation_obj.h"

void Animation_obj::animate(){
    if(run){
        if(dir==1){
            cur++;
            if(cur==max_cur){
                if(botton_trigger&&!stop_mode){cur=1;}
                else if(stop_mode&&!botton_trigger){cur=max_cur-1;run=false;}
                else{cur=0;}
            }
        }
        else{
            cur--;
            if(cur==-1){
                cur=max_cur-1;
            }
        }
    }
}
void Animation_obj::draw(){
    if(appear)al_draw_bitmap_region(img,cur*width,0,width,height,position_x,position_y,0);
}
void Animation_obj::set_max_cur(int m){
    max_cur=m;
}
void Animation_obj::set_img(const char *buffer){
    img=al_load_bitmap(buffer);
}
void Animation_obj::set_size(float w, float h){
    width=w;
    height=h;
}
void Animation_obj::set_position(float x, float y){
    position_x=x;
    position_y=y;
}
