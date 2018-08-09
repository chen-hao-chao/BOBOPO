#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <vector>
#include <iostream>

#define BEAT_SLIGHT 0
#define BEAT_STRONG 1
#define START_STOP 2
#define RECORD 3
#define RECORD_OVER 4

class Recorder{
    public:
        Recorder(){
            period=0;
            index=0;
            cur=0;
            event.clear();
            re_play=false;
            start=false;
            _empty=true;

            sample = al_load_sample("./music/dong.wav");
            sound_strong = al_create_sample_instance(sample);
            sample = al_load_sample("./music/ding.wav");
            sound_slight = al_create_sample_instance(sample);
        }
        ~Recorder(){
            al_destroy_sample(sample);
            al_destroy_sample_instance(sound_strong);
            al_destroy_sample_instance(sound_slight);
        }
        void run();
        void draw();
        void buttom_control(int);
        ALLEGRO_SAMPLE_INSTANCE *get_si(int);

    private:
        int period;
        int index;
        int cur;
        std::vector<int> event;
        std::vector<bool> beat;
        bool re_play;
        bool start;
        bool _empty;
        ALLEGRO_SAMPLE *sample;
        ALLEGRO_SAMPLE_INSTANCE *sound_strong;
        ALLEGRO_SAMPLE_INSTANCE *sound_slight;
};
