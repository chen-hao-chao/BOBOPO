#include <vector>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 300
#define RESOLUTION 5
#define DEGREE 15
#define BALANCE_R 20
#define BALANCE_G 220
#define BALANCE_B 20
#define PANEL_POSITION_X 80
#define PANEL_POSITION_Y 230

using namespace std;


class square_point{
    public:
        square_point(){}
        ~square_point(){}
        void setting(int _r,int _g,int _b,float _x,float _y, int _s){r=_r;g=_g;b=_b;x=_x;y=_y;_size=_s;}
        void draw(){al_draw_filled_rectangle(x,y,x+_size,y+_size,al_map_rgb(r,g,b));}
        void lighten(){
            if(r<235) r+=20;
            if(g<235) g+=20;
            if(b<235) b+=20;
        }
        void to_yello(){r=230;g=230;b=100;}
        void to_blue(){r=30;g=200;b=255;}
        void color_balance(){
            if(r>BALANCE_R){r--;}
            if(r<BALANCE_R){r++;}
            if(g>BALANCE_G){g--;}
            if(g<BALANCE_G){g++;}
            if(b>BALANCE_B){b--;}
            if(b<BALANCE_B){b++;}
        }


    private:
        int r,g,b;//color
        float x,y;//position
        int _size;//length of each side
};

class Panel{
    public:
        Panel(){
            _size=SIZE;
            for(int i=PANEL_POSITION_X;i<_size+PANEL_POSITION_X;i+=RESOLUTION){
                for(int j=PANEL_POSITION_Y;j<_size+PANEL_POSITION_Y;j+=RESOLUTION){
                    square_point sp;
                    sp.setting(BALANCE_R,BALANCE_G,BALANCE_B,i,j,RESOLUTION);
                    vec.push_back(sp);
                }
            }
            _width=SIZE/RESOLUTION;
            srand(time(NULL));
            circle=al_load_bitmap("./image/Page_start/c1.png");
            sample = al_load_sample("./music/C1.wav");
            sound_c = al_create_sample_instance(sample);
            sample = al_load_sample("./music/D1.wav");
            sound_d = al_create_sample_instance(sample);
            sample = al_load_sample("./music/E1.wav");
            sound_e = al_create_sample_instance(sample);
            sample = al_load_sample("./music/F1.wav");
            sound_f = al_create_sample_instance(sample);
            sample = al_load_sample("./music/G1.wav");
            sound_g = al_create_sample_instance(sample);
            sample = al_load_sample("./music/A1.wav");
            sound_a = al_create_sample_instance(sample);
            sample = al_load_sample("./music/B1.wav");
            sound_b = al_create_sample_instance(sample);
            sample = al_load_sample("./music/C.wav");
            sound_c1 = al_create_sample_instance(sample);
            sample = al_load_sample("./music/D.wav");
            sound_d1 = al_create_sample_instance(sample);
            sample = al_load_sample("./music/E.wav");
            sound_e1 = al_create_sample_instance(sample);
            sample = al_load_sample("./music/F.wav");
            sound_f1 = al_create_sample_instance(sample);
            sample = al_load_sample("./music/G.wav");
            sound_g1 = al_create_sample_instance(sample);
            sample = al_load_sample("./music/A.wav");
            sound_a1 = al_create_sample_instance(sample);
            sample = al_load_sample("./music/B.wav");
            sound_b1 = al_create_sample_instance(sample);
        }
        ~Panel(){
            vec.clear();
            al_destroy_bitmap(circle);
            al_destroy_sample(sample);
            al_destroy_sample_instance(sound_c);
            al_destroy_sample_instance(sound_d);
            al_destroy_sample_instance(sound_e);
            al_destroy_sample_instance(sound_f);
            al_destroy_sample_instance(sound_g);
            al_destroy_sample_instance(sound_a);
            al_destroy_sample_instance(sound_b);
            al_destroy_sample_instance(sound_c1);
            al_destroy_sample_instance(sound_d1);
            al_destroy_sample_instance(sound_e1);
            al_destroy_sample_instance(sound_f1);
            al_destroy_sample_instance(sound_g1);
            al_destroy_sample_instance(sound_a1);
            al_destroy_sample_instance(sound_b1);
        }
        void draw();
        void _transform(int);
        void _restore();
        void noises();
        ALLEGRO_SAMPLE_INSTANCE *get_si(int);

    private:
        ALLEGRO_BITMAP *circle = NULL;
        int _width;
        int _size;
        vector<square_point> vec;
        ALLEGRO_SAMPLE *sample;
        ALLEGRO_SAMPLE_INSTANCE *sound_c,*sound_d,*sound_e,*sound_f,*sound_g,*sound_a,*sound_b;
        ALLEGRO_SAMPLE_INSTANCE *sound_c1,*sound_d1,*sound_e1,*sound_f1,*sound_g1,*sound_a1,*sound_b1;
};
