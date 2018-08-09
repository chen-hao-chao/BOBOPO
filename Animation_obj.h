#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Animation_obj{
    public:
        Animation_obj(){
            max_cur=0;
            cur=0;
            dir=1;
            appear=true;
            run=true;
            botton_trigger=false;
            stop_mode=false;
        }
        ~Animation_obj(){al_destroy_bitmap(img);}
        void animate();
        void draw();
        void set_position(float, float);
        void set_max_cur(int);
        void set_img(const char *);
        void set_size(float, float);
        void flip_appear(){appear=!appear;}
        void flip_run(){run=!run;}
        void flip_dir(){dir*=-1;}
        void flip_stop_mode(){stop_mode=!stop_mode;}
        void flip_botton_trigger(){botton_trigger=!botton_trigger;}
        void reset(){cur=0;}

    private:
        int max_cur, cur;
        int dir;
        bool appear, run, botton_trigger, stop_mode;
        float width, height;
        float position_x, position_y;
        ALLEGRO_BITMAP *img;
};
