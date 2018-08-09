#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <time.h>
#include "Global.h"

#define G_POSITION_X 250
#define G_POSITION_Y 90
#define F_POSITION_X 300
#define F_POSITION_Y 430
#define G_WIDTH 300
#define G_HEIGHT 300
#define F_WIDTH 200
#define F_HEIGHT 82
#define G_MAX_CUR 8
#define F_MAX_CUR 5

using namespace std;

class Gashapon{
    public:
        Gashapon(){
            srand(time(NULL));
            gashapon_cur=0;
            gashapon_max_cur=G_MAX_CUR;
            frame_cur=0;
            frame_max_cur=F_MAX_CUR;
            state=0;
            treasure=0;
            img_gashapon=al_load_bitmap("./image/Page_store/Gashapon.png");
            img_frame=al_load_bitmap("./image/Page_store/frame.png");
            font = al_load_ttf_font("WORD.ttf",9,0);
        }
        ~Gashapon(){
            al_destroy_bitmap(img_frame);
            al_destroy_bitmap(img_gashapon);
            al_destroy_font(font);
        }
        void run();
        void draw();
        void next_state(int);
        void flip_treasure(){treasure=rand()%PG_COLLECTION_TRE_SIZE;}
        int get_state(){return state;}
        int get_treasure(){return treasure;}

    private:
        int gashapon_cur, gashapon_max_cur;
        int frame_cur, frame_max_cur;
        int state;
        int treasure;
        ALLEGRO_BITMAP *img_gashapon, *img_frame;
        ALLEGRO_FONT *font;
};
