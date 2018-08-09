#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include <fstream>
#include <string>

#include "Global.h"
#include "Animation_obj.h"
#include "Panel.h"
#include "Stripe.h"
#include "Gashapon.h"
#include "Recorder.h"
#include "Treasure.h"

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 600

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

#define PAGE_MENU 10
#define PAGE_START 11
#define PAGE_STORE 12
#define PAGE_COLLECTION 13
#define PAGE_ESCAPE 14
#define PAGE_COUNTDOWN 15

// clock rate
const float FPS = 33;

class GameWindow
{
public:
    GameWindow(){game_setting();}
    ~GameWindow(){game_destroy();}
    void game_setting();
    void game_play();
    int game_run();
    void draw_running_map();
    void game_destroy();
    void show_err_msg(int msg);
    int process_event();
    void reset_menu();
    void reset_start();
    void reset_store();
    void reset_collection();
    void reset_escape();
    void reset_countdown();
    void draw_menu_text();
    void renew_money_display();
    void clean();

private:
    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *esc;
    ALLEGRO_BITMAP *logo;

    ALLEGRO_DISPLAY* display;
    ALLEGRO_FONT *font;
    ALLEGRO_FONT *s_font;

    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer;

    ALLEGRO_SAMPLE *sample;
    ALLEGRO_SAMPLE_INSTANCE *sound_scratch1;
    ALLEGRO_SAMPLE_INSTANCE *sound_scratch2;
    ALLEGRO_SAMPLE_INSTANCE *sound_scratch3;
    ALLEGRO_SAMPLE_INSTANCE *sound_select;

    int Page;
    int back_page;
    int count_down_cur;
    int money;
    char str[20];

    fstream file;
    std::vector<Animation_obj*> ani_set;
    std::vector<Stripe*> stp_set;
    std::vector<Treasure*> tre_set;
    std::vector<bool> style;
    Panel *panel;
    Gashapon *gashapon;
    Recorder *recorder;

    bool to_menu = false;
    bool to_start = false;
    bool to_store = false;
    bool to_collection = false;
    bool to_escape = false;
};
