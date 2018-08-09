#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#define WIDTH 30
#define HEIGHT 90

class Stripe{
    public:
        Stripe(){
            cur=0;
            width=WIDTH;
            height=0;
            position_x1=0;
            position_y1=0;
            r=255;g=255;b=255;
            t=false;
            base=al_load_bitmap("./image/Page_start/ball.png");
        }
        ~Stripe(){
            al_destroy_bitmap(base);
            al_destroy_sample(sample);
            al_destroy_sample_instance(sound);
        }
        void trigger(){t=!t;}
        void setting(float,float,int,int,int);
        void run();
        void restore();
        void draw();
        void set_sound(const char *);
        bool get_state(){return t;}
        ALLEGRO_SAMPLE_INSTANCE *get_si(){return sound;}

    private:
        int cur;
        float width,height;
        float position_x1,position_y1;
        int r,g,b;
        bool t;
        ALLEGRO_BITMAP *base;
        ALLEGRO_SAMPLE *sample;
        ALLEGRO_SAMPLE_INSTANCE *sound;
};
