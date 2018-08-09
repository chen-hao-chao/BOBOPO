#include "GameWindow.h"

void GameWindow::clean(){
    if(Page == PAGE_MENU){
        ani_set.clear();
    }
    else if(Page == PAGE_START){
        ani_set.clear();
        stp_set.clear();
        delete panel;
        delete recorder;
    }
    else if(Page == PAGE_STORE){
        delete gashapon;
    }
    else if(Page == PAGE_COLLECTION){
        tre_set.clear();
    }
    else if(Page == PAGE_ESCAPE){
        ani_set.clear();
    }
}

void GameWindow::reset_countdown(){
    logo=al_load_bitmap("./image/logo.png");
    count_down_cur=0;
    Page=PAGE_COUNTDOWN;
}

void GameWindow::reset_menu(){
    clean();

    ///Control selector
    PG_MENU_control_selector=0;
    for(int i=0;i<3;i++) PG_MENU_control_bar[i]=false;

    ///Animation
    char buffer[70];
    for(int i=0;i<PG_MENU_ANI_SIZE;i++){
        Animation_obj *p=new Animation_obj;
        sprintf(buffer, "./image/Page_menu/%s.png", PG_MENU_ANI_filename[i]);
        p->set_img(buffer);
        p->set_max_cur(PG_MENU_ANI_max_cur[i]);
        p->set_size(PG_MENU_ANI_width[i],PG_MENU_ANI_height[i]);
        p->set_position(PG_MENU_ANI_position_x[i],PG_MENU_ANI_position_y[i]);
        ani_set.push_back(p);
    }
    ani_set[2]->flip_run();ani_set[3]->flip_run();
    ani_set[1]->flip_botton_trigger();ani_set[2]->flip_botton_trigger();ani_set[3]->flip_botton_trigger();
    Page=PAGE_MENU;
    to_menu=false;
}

void GameWindow::reset_start(){
    clean();

    ///Animation
    char buffer[70];
    for(int i=0;i<PG_START_ANI_SIZE;i++){
        Animation_obj *p=new Animation_obj;
        sprintf(buffer, "./image/Page_start/%s.png", PG_START_ANI_filename[i]);
        p->set_img(buffer);
        p->set_max_cur(PG_START_ANI_max_cur[i]);
        p->set_size(PG_START_ANI_width[i],PG_START_ANI_height[i]);
        p->set_position(PG_START_ANI_position_x[i],PG_START_ANI_position_y[i]);
        ani_set.push_back(p);
    }
    for(int i=0;i<3;i++) ani_set[i]->flip_appear();

    ///Panel
    panel=new Panel;
    for(int i=0;i<14;i++) al_attach_sample_instance_to_mixer(panel->get_si(i),al_get_default_mixer());

    ///Stripe
    for(int i=0;i<PG_START_STP_SIZE;i++){
        Stripe *p=new Stripe;
        sprintf(buffer, "./music/%s.wav", PG_START_STP_filename[i]);
        p->set_sound(buffer);
        p->setting(PG_START_STP_position_x[i],PG_START_STP_position_y[i],100,255,100);
        al_attach_sample_instance_to_mixer(p->get_si(),al_get_default_mixer());
        stp_set.push_back(p);
    }

    ///Recorder
    recorder=new Recorder;
    for(int i=0;i<2;i++) al_attach_sample_instance_to_mixer(recorder->get_si(i),al_get_default_mixer());

    count_down_cur=0;
    Page=PAGE_START;
    to_start=false;
}

void GameWindow::reset_store(){
    clean();
    ///Gashapon
    gashapon=new Gashapon;

    Page=PAGE_STORE;
    to_store=false;
}

void GameWindow::reset_collection(){
    clean();

    ///Treasure
    char buffer1[70];
    char buffer2[70];
    for(int i=0;i<PG_COLLECTION_TRE_SIZE*2;i+=2){
        Treasure *p=new Treasure;
        sprintf(buffer1, "./image/Page_collection/%s.png", PG_COLLECTION_TRE_filename[i]);
        sprintf(buffer2, "./image/Page_collection/%s.png", PG_COLLECTION_TRE_filename[i+1]);
        p->set_img(buffer1,buffer2);
        p->set_max_cur(PG_COLLECTION_TRE_max_cur[i/2]);
        p->set_size(PG_COLLECTION_TRE_width[i/2],PG_COLLECTION_TRE_height[i/2]);
        p->set_position(PG_COLLECTION_TRE_position_x[i/2],PG_COLLECTION_TRE_position_y[i/2]);
        tre_set.push_back(p);
    }

    Page=PAGE_COLLECTION;
    to_collection=false;
}
void GameWindow::reset_escape(){
    clean();
    back_page=Page;

    ///Control selector
    PG_ESCAPE_control_selector=0;
    for(int i=0;i<2;i++) PG_ESCAPE_control_bar[i]=false;

    ///Animation
    char buffer[70];
    for(int i=0;i<PG_ESCAPE_ANI_SIZE;i++){
        Animation_obj *p=new Animation_obj;
        sprintf(buffer, "./image/Page_escape/%s.png", PG_ESCAPE_ANI_filename[i]);
        p->set_img(buffer);
        p->set_max_cur(PG_ESCAPE_ANI_max_cur[i]);
        p->set_size(PG_ESCAPE_ANI_width[i],PG_ESCAPE_ANI_height[i]);
        p->set_position(PG_ESCAPE_ANI_position_x[i],PG_ESCAPE_ANI_position_y[i]);
        p->flip_appear();
        ani_set.push_back(p);
    }
    ani_set[0]->flip_appear();
    Page=PAGE_ESCAPE;
    to_escape=false;
}

void GameWindow::game_setting(){

    ///initialize
    if (!al_init()) show_err_msg(-1);

    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

    if(timer == NULL) show_err_msg(-1);
    if(display == NULL || event_queue == NULL) show_err_msg(-1);

    ///addons
    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event
    al_reserve_samples(1);

    ///load fonts
    font = al_load_ttf_font("WORD.ttf",12,0); // load normal font
    s_font = al_load_ttf_font("WORD.ttf",9,0); //load small font

    ///registor
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    ///load things for PAGE_MANU.
    icon = al_load_bitmap("./icon.png");
    esc=al_load_bitmap("./image/ESC.png");
    al_set_display_icon(display, icon);
    reset_countdown();

    ///file
    file.open("./style.txt",ios::in);
    file>>money;
    for(int i=0;i<4;i++){bool b;file>>b;style.push_back(b);}
    renew_money_display();
    file.close();

    ///Sound
    sample = al_load_sample("./music/scratch1.wav");
    sound_scratch1 = al_create_sample_instance(sample);
    al_attach_sample_instance_to_mixer(sound_scratch1,al_get_default_mixer());
    sample = al_load_sample("./music/scratch2.wav");
    sound_scratch2 = al_create_sample_instance(sample);
    al_attach_sample_instance_to_mixer(sound_scratch2,al_get_default_mixer());
    sample = al_load_sample("./music/scratch3.wav");
    sound_scratch3 = al_create_sample_instance(sample);
    al_attach_sample_instance_to_mixer(sound_scratch3,al_get_default_mixer());
    sample = al_load_sample("./music/select.wav");
    sound_select = al_create_sample_instance(sample);
    al_attach_sample_instance_to_mixer(sound_select,al_get_default_mixer());

    ///Timer
    al_start_timer(timer);
}
void GameWindow::game_play(){//play->run
    int msg;
    msg = -1;

    while(msg != GAME_EXIT){
        msg = game_run();
    }
    show_err_msg(msg);
}
int GameWindow::game_run(){
    int error = GAME_CONTINUE;
    if (!al_is_event_queue_empty(event_queue)) error = process_event();
    return error;
}
void GameWindow::show_err_msg(int msg){
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}
void GameWindow::game_destroy(){
    file.open("style.txt", ios::out);
    file<<money<<"\n";
    for(auto e:style) file<<e<<" ";
    file.close();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(s_font);
    al_destroy_timer(timer);
    al_destroy_bitmap(icon);
    al_destroy_bitmap(esc);
    al_destroy_bitmap(logo);
    al_destroy_sample(sample);
    al_destroy_sample_instance(sound_scratch1);
    al_destroy_sample_instance(sound_scratch2);
    al_destroy_sample_instance(sound_scratch3);
    al_destroy_sample_instance(sound_select);
}
int GameWindow::process_event(){

    int instruction = GAME_CONTINUE;
    al_wait_for_event(event_queue, &event);

    if(event.type == ALLEGRO_EVENT_TIMER){
        if(Page == PAGE_MENU){
            for(int i=0;i<PG_MENU_ANI_SIZE;i++) ani_set[i]->animate();
        }
        else if(Page == PAGE_ESCAPE){
            for(int i=0;i<PG_ESCAPE_ANI_SIZE;i++) ani_set[i]->animate();
        }
        else if(Page == PAGE_START){
            for(int i=0;i<PG_START_ANI_SIZE;i++) ani_set[i]->animate();
            panel->_restore();
            recorder->run();
            count_down_cur++;
            if(count_down_cur==40){
                panel->noises();
                count_down_cur=0;
            }
            for(int i=0;i<PG_START_STP_SIZE;i++){
                if(stp_set[i]->get_state()) stp_set[i]->run();
                else stp_set[i]->restore();
            }
        }
        else if(Page == PAGE_STORE){
            gashapon->run();
        }
        else if(Page == PAGE_COLLECTION){
            for(int i=0;i<PG_COLLECTION_TRE_SIZE;i++) tre_set[i]->animate();
        }
        else if(Page == PAGE_COUNTDOWN){
            count_down_cur++;
            if(count_down_cur==60) to_menu=true;
        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        return GAME_EXIT;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN){
        if(Page == PAGE_MENU){
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_RIGHT:
                    PG_MENU_control_selector++;
                    ani_set[PG_MENU_control_selector]->flip_run();
                    ani_set[PG_MENU_control_selector]->reset();
                    if(PG_MENU_control_selector==3){PG_MENU_control_selector=0;}
                    ani_set[1+PG_MENU_control_selector]->flip_run();
                    al_play_sample_instance(sound_select);
                    break;
                case ALLEGRO_KEY_LEFT:
                    PG_MENU_control_selector--;
                    ani_set[2+PG_MENU_control_selector]->flip_run();
                    ani_set[2+PG_MENU_control_selector]->reset();
                    if(PG_MENU_control_selector==-1){PG_MENU_control_selector=2;}
                    ani_set[1+PG_MENU_control_selector]->flip_run();
                    al_play_sample_instance(sound_select);
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    return GAME_EXIT;
                    break;
                case ALLEGRO_KEY_ENTER:
                    if(PG_MENU_control_selector==0) to_start=true;
                    else if(PG_MENU_control_selector==1) to_store=true;
                    else if(PG_MENU_control_selector==2) to_collection=true;
            }
        }
        else if(Page == PAGE_ESCAPE){
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_UP:
                    ani_set[PG_ESCAPE_control_selector]->flip_appear();
                    PG_ESCAPE_control_selector--;
                    if(PG_ESCAPE_control_selector==-1){PG_ESCAPE_control_selector=2;}
                    ani_set[PG_ESCAPE_control_selector]->flip_appear();
                    break;
                case ALLEGRO_KEY_DOWN:
                    ani_set[PG_ESCAPE_control_selector]->flip_appear();
                    PG_ESCAPE_control_selector++;
                    if(PG_ESCAPE_control_selector==3){PG_ESCAPE_control_selector=0;}
                    ani_set[PG_ESCAPE_control_selector]->flip_appear();
                    break;
                case ALLEGRO_KEY_ENTER:
                    if(PG_ESCAPE_control_selector==0) to_menu=true;
                    else if(PG_ESCAPE_control_selector==1){
                        if(back_page == PAGE_START) to_start=true;
                        else if(back_page == PAGE_STORE) to_store=true;
                        else if(back_page == PAGE_COLLECTION) to_collection=true;
                    }
                    else if(PG_ESCAPE_control_selector==2){
                        return GAME_EXIT;
                    }
                    break;
            }
        }
        else if(Page == PAGE_START){
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_Y:
                    ani_set[3]->flip_dir();
                    ani_set[0]->flip_appear();
                    al_play_sample_instance(sound_scratch1);
                    break;
                case ALLEGRO_KEY_U:
                    ani_set[4]->flip_dir();
                    ani_set[1]->flip_appear();
                    al_play_sample_instance(sound_scratch2);
                    break;
                case ALLEGRO_KEY_I:
                    ani_set[5]->flip_dir();
                    ani_set[2]->flip_appear();
                    al_play_sample_instance(sound_scratch3);
                    break;
                case ALLEGRO_KEY_A:
                    panel->_transform(0);
                    break;
                case ALLEGRO_KEY_S:
                    panel->_transform(1);
                    break;
                case ALLEGRO_KEY_D:
                    panel->_transform(2);
                    break;
                case ALLEGRO_KEY_F:
                    panel->_transform(3);
                    break;
                case ALLEGRO_KEY_G:
                    panel->_transform(4);
                    break;
                case ALLEGRO_KEY_H:
                    panel->_transform(5);
                    break;
                case ALLEGRO_KEY_J:
                    panel->_transform(6);
                    break;
                case ALLEGRO_KEY_Z:
                    panel->_transform(7);
                    break;
                case ALLEGRO_KEY_X:
                    panel->_transform(8);
                    break;
                case ALLEGRO_KEY_C:
                    panel->_transform(9);
                    break;
                case ALLEGRO_KEY_V:
                    panel->_transform(10);
                    break;
                case ALLEGRO_KEY_B:
                    panel->_transform(11);
                    break;
                case ALLEGRO_KEY_N:
                    panel->_transform(12);
                    break;
                case ALLEGRO_KEY_M:
                    panel->_transform(13);
                    break;
                case ALLEGRO_KEY_Q:
                    stp_set[0]->trigger();
                    break;
                case ALLEGRO_KEY_W:
                    stp_set[1]->trigger();
                    break;
                case ALLEGRO_KEY_E:
                    stp_set[2]->trigger();
                    break;
                case ALLEGRO_KEY_R:
                    stp_set[3]->trigger();
                    break;
                case ALLEGRO_KEY_T:
                    stp_set[4]->trigger();
                    break;
                case ALLEGRO_KEY_K:
                    recorder->buttom_control(0);
                    break;
                case ALLEGRO_KEY_L:
                    recorder->buttom_control(1);
                    break;
                case ALLEGRO_KEY_P:
                    recorder->buttom_control(2);
                    break;
                case ALLEGRO_KEY_O:
                    recorder->buttom_control(3);
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    to_escape=true;
                    break;
            }
        }
        else if(Page == PAGE_STORE){
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_ENTER:
                    if(gashapon->get_state()==0||gashapon->get_state()==3){
                        gashapon->next_state(money);
                        if(money>=5&&gashapon->get_state()==1){
                            money-=5;
                            renew_money_display();
                            gashapon->flip_treasure();
                            style[gashapon->get_treasure()]=true;
                        }
                    }
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    to_escape=true;
                    break;
            }
        }
        else if(Page == PAGE_COLLECTION){
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    to_escape=true;
                    break;
            }
        }
    }
    else if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(Page == PAGE_MENU){
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_RIGHT:
                    al_stop_sample_instance(sound_select);
                    break;
                case ALLEGRO_KEY_LEFT:
                    al_stop_sample_instance(sound_select);
                    break;
            }
        }
        else if(Page == PAGE_START){
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_Y:
                    ani_set[3]->flip_dir();
                    ani_set[0]->flip_appear();
                    al_stop_sample_instance(sound_scratch1);
                    break;
                case ALLEGRO_KEY_U:
                    ani_set[4]->flip_dir();
                    ani_set[1]->flip_appear();
                    al_stop_sample_instance(sound_scratch2);
                    break;
                case ALLEGRO_KEY_I:
                    ani_set[5]->flip_dir();
                    ani_set[2]->flip_appear();
                    al_stop_sample_instance(sound_scratch3);
                    break;
                case ALLEGRO_KEY_Q:
                    stp_set[0]->trigger();
                    break;
                case ALLEGRO_KEY_W:
                    stp_set[1]->trigger();
                    break;
                case ALLEGRO_KEY_E:
                    stp_set[2]->trigger();
                    break;
                case ALLEGRO_KEY_R:
                    stp_set[3]->trigger();
                    break;
                case ALLEGRO_KEY_T:
                    stp_set[4]->trigger();
                    break;
                case ALLEGRO_KEY_O:
                    recorder->buttom_control(4);
                    break;
            }
        }
    }
    draw_running_map();
    return instruction;
}

void GameWindow::draw_running_map(){
    if(Page == PAGE_MENU){
        if(to_start){
            reset_start();
        }
        else if(to_store){
            reset_store();
        }
        else if(to_collection){
            reset_collection();
        }
        else{
            for(int i=0;i<PG_MENU_ANI_SIZE;i++) ani_set[i]->draw();
            draw_menu_text();
        }
    }
    else if(Page == PAGE_START){
        if(to_escape){
            reset_escape();
        }
        else{
            al_draw_bitmap(esc,10,10,0);
            for(int i=0;i<PG_START_ANI_SIZE;i++) ani_set[i]->draw();
            for(int i=0;i<PG_START_STP_SIZE;i++) stp_set[i]->draw();
            panel->draw();
            recorder->draw();
        }
    }
    else if(Page == PAGE_STORE){
        if(to_escape){
            reset_escape();
        }
        else{
            al_draw_bitmap(esc,10,10,0);
            gashapon->draw();
            al_draw_rounded_rectangle(590,28,730,50,5,5,al_map_rgb(100,255,100),1);
            al_draw_text(font,al_map_rgb(100,255,100),600,33,0,"coins");
            al_draw_text(font,al_map_rgb(100,255,100),700,33,0,str);
            if(gashapon->get_state()==0){//the "get" icon
                if(money>=5){
                    al_draw_text(font,al_map_rgb(100,255,100),406,458,ALLEGRO_ALIGN_CENTER,"get");
                    al_draw_rounded_rectangle(360,450,450,480,17,17,al_map_rgb(100,255,100),2);
                }
                else{
                    al_draw_text(font,al_map_rgb(100,100,100),406,458,ALLEGRO_ALIGN_CENTER,"get");
                    al_draw_rounded_rectangle(360,450,450,480,17,17,al_map_rgb(100,100,100),2);
                }
            }
        }
    }
    else if(Page == PAGE_COLLECTION){
        if(to_escape){
            reset_escape();
        }
        else{
            al_draw_bitmap(esc,10,10,0);
            for(int i=0;i<PG_COLLECTION_TRE_SIZE;i++) tre_set[i]->draw(style[i]);
        }
    }
    else if(Page == PAGE_ESCAPE){
        if(to_start){
            reset_start();
        }
        else if(to_store){
            reset_store();
        }
        else if(to_collection){
            reset_collection();
        }
        else if(to_menu){
            reset_menu();
        }
        for(int i=0;i<PG_ESCAPE_ANI_SIZE;i++) ani_set[i]->draw();
        al_draw_text(font, al_map_rgb(100,255,100), 400, 220, ALLEGRO_ALIGN_CENTER,"MENU");
        al_draw_text(font, al_map_rgb(100,255,100), 400, 280, ALLEGRO_ALIGN_CENTER,"BACK");
        al_draw_text(font, al_map_rgb(100,255,100), 400, 340, ALLEGRO_ALIGN_CENTER,"EXIT");
    }
    else if(Page == PAGE_COUNTDOWN){
        if(to_menu){
            reset_menu();
        }
        else{
            if(count_down_cur<18) al_draw_bitmap_region(logo,count_down_cur*200,0,200,200,300,200,0);
        }
    }
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
}
void GameWindow::draw_menu_text(){
    if(PG_MENU_control_selector==0) al_draw_text(font, al_map_rgb(210,255,210), 165, 370, ALLEGRO_ALIGN_CENTER,"START");
    if(PG_MENU_control_selector==1) al_draw_text(font, al_map_rgb(210,255,210), 405, 370, ALLEGRO_ALIGN_CENTER,"STORE");
    if(PG_MENU_control_selector==2) al_draw_text(font, al_map_rgb(210,255,210), 645, 370, ALLEGRO_ALIGN_CENTER,"COLLECTIONS");
}
void GameWindow::renew_money_display(){
    if(money>0){
        int m1=money;
        int m2=money;
        int power;
        for(power=0;m1!=0;power++){m1/=10;}
        for(int i=power-1;i>=0;i--){str[i]=(m2%10)+'0';m2/=10;}
        str[power]='\0';
    }
    else{
        str[0]='0';
        str[1]='\0';
    }
}
