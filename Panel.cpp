#include "Panel.h"

void Panel::draw(){
    for(auto e:vec){
        e.draw();
    }
    al_draw_bitmap(circle,PANEL_POSITION_X,PANEL_POSITION_Y,0);
}
void Panel::noises(){
    for(int i=0;i<_width;i++){
        int r=rand()%(_width*_width);
        vec[r].to_yello();
    }
    for(int i=0;i<_width;i++){
        int r=rand()%(_width*_width);
        vec[r].to_blue();
    }
}

void Panel::_transform(int n){
    int target_i,target_j;
    for(int i=0;i<2;i++){
        if(i==1) target_i=rand()%_width;
        else target_j=rand()%_width;
    }
    int degree=target_i%DEGREE;
    for(int i=0;i<=_width;i++){
        for(int j=0;j<=_width;j++){
            for(int k=degree;k>0;k--){
                if(i-target_i<k&&i-target_i>(k*-1)&&j-target_j<k&&j-target_j>(k*-1)) vec[i*_width+j].lighten();
            }
        }
    }
    switch(n){
        case 0: al_stop_sample_instance(sound_c);al_play_sample_instance(sound_c); break;
        case 1: al_stop_sample_instance(sound_d);al_play_sample_instance(sound_d); break;
        case 2: al_stop_sample_instance(sound_e);al_play_sample_instance(sound_e); break;
        case 3: al_stop_sample_instance(sound_f);al_play_sample_instance(sound_f); break;
        case 4: al_stop_sample_instance(sound_g);al_play_sample_instance(sound_g); break;
        case 5: al_stop_sample_instance(sound_a);al_play_sample_instance(sound_a); break;
        case 6: al_stop_sample_instance(sound_b);al_play_sample_instance(sound_b); break;
        case 7: al_stop_sample_instance(sound_c1);al_play_sample_instance(sound_c1); break;
        case 8: al_stop_sample_instance(sound_d1);al_play_sample_instance(sound_d1); break;
        case 9: al_stop_sample_instance(sound_e1);al_play_sample_instance(sound_e1); break;
        case 10: al_stop_sample_instance(sound_f1);al_play_sample_instance(sound_f1); break;
        case 11: al_stop_sample_instance(sound_g1);al_play_sample_instance(sound_g1); break;
        case 12: al_stop_sample_instance(sound_a1);al_play_sample_instance(sound_a1); break;
        case 13: al_stop_sample_instance(sound_b1);al_play_sample_instance(sound_b1); break;
    }
}
void Panel::_restore(){
    for(int i=0;i<_width*_width;i++){
        vec[i].color_balance();
    }
}
ALLEGRO_SAMPLE_INSTANCE *Panel::get_si(int n){
    switch(n){
        case 0: return sound_c; break;
        case 1: return sound_d; break;
        case 2: return sound_e; break;
        case 3: return sound_f; break;
        case 4: return sound_g; break;
        case 5: return sound_a; break;
        case 6: return sound_b; break;
        case 7: return sound_c1; break;
        case 8: return sound_d1; break;
        case 9: return sound_e1; break;
        case 10: return sound_f1; break;
        case 11: return sound_g1; break;
        case 12: return sound_a1; break;
        case 13: return sound_b1; break;
    }
}
