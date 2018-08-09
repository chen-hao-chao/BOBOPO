#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>

class Treasure{
    public:
        Treasure(){
            img1=nullptr;
            img2=nullptr;
            max_cur=0;
            cur=0;
        }
        ~Treasure(){
            al_destroy_bitmap(img1);
            al_destroy_bitmap(img2);
        }
        void draw(bool);
        void animate();
        void set_position(float,float);
        void set_size(float,float);
        void set_max_cur(int);
        void set_img(const char *,const char *);

    private:
        int max_cur, cur;
        float width, height;
        float position_x, position_y;
        ALLEGRO_BITMAP *img1,*img2;
};
