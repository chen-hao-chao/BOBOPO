#include "Recorder.h"

void Recorder::run(){
    if(start){
        if(re_play){
            period++;
            if(period==300){re_play=false;index=0;cur=0;}
        }
        else{
            if(period&&!_empty){
                cur++;
                if(cur==event[index]){//std::cout<<event[index];
                    if(beat[index]==BEAT_SLIGHT){al_stop_sample_instance(sound_slight);al_play_sample_instance(sound_slight);}
                    else if(beat[index]==BEAT_STRONG){al_stop_sample_instance(sound_strong);al_play_sample_instance(sound_strong);}
                    index++;
                }
                if(cur==period){
                    cur=0;
                    index=0;
                }
            }
        }
    }
}
void Recorder::buttom_control(int order){
    if(order == START_STOP){
        start=!start;
    }
    else if(order == RECORD){
        event.clear();
        beat.clear();
        period=0;
        index=0;
        cur=0;
        re_play=true;
        _empty=true;
    }
    else if(order == RECORD_OVER){
        re_play=false;
    }
    else if(order == BEAT_SLIGHT){
        if(re_play&&start){
            _empty=false;
            event.push_back(period);
            beat.push_back(BEAT_SLIGHT);
        }
    }
    else if(order == BEAT_STRONG){
        if(re_play&&start){
            _empty=false;
            event.push_back(period);
            beat.push_back(BEAT_STRONG);
        }
    }
}
ALLEGRO_SAMPLE_INSTANCE *Recorder::get_si(int n){
    if(n==0) return sound_strong;
    else if(n==1) return sound_slight;
}
void Recorder::draw(){
    if(start) al_draw_filled_circle(500,450,10,al_map_rgb(255,100,100));
    if(!re_play) al_draw_filled_circle(550,450,10,al_map_rgb(100,255,100));
    if(re_play) al_draw_filled_circle(600,450,10,al_map_rgb(100,255,100));
}
