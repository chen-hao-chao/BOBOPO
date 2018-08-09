#include "Global.h"

///PAGE_MENU Animation
const int PG_MENU_ANI_SIZE=6;
const int PG_MENU_ANI_max_cur[]={9,8,8,8,10,10};
const float PG_MENU_ANI_width[]={300,200,200,200,109,109};
const float PG_MENU_ANI_height[]={290,247,247,247,150,150};
const float PG_MENU_ANI_position_x[]={250,60,300,540,570,120};
const float PG_MENU_ANI_position_y[]={50,400,400,400,120,120};
const char PG_MENU_ANI_filename[][20]={"bobopo","disc","disc","disc","volume","volume2"};
bool PG_MENU_control_bar[]={false,false,false};
int PG_MENU_control_selector=0;

///PAGE_START Animation
const int PG_START_ANI_SIZE=6;
const int PG_START_ANI_max_cur[]={10,10,10,32,32,32};
const float PG_START_ANI_width[]={100,100,100,100,100,100};
const float PG_START_ANI_height[]={100,100,100,100,100,100};
const float PG_START_ANI_position_x[]={430,510,600,430,510,600};
const float PG_START_ANI_position_y[]={50,150,260,50,150,260};
const char PG_START_ANI_filename[][20]={"circle","circle","circle","boo1","boo2","boo3"};

///PAGE_START Stripe
const int PG_START_STP_SIZE=5;
const float PG_START_STP_position_x[]={100,150,200,250,300};
const float PG_START_STP_position_y[]={145,145,145,145,145};
const char PG_START_STP_filename[][20]={"s1","s2","s3","s4","s5"};

///PAGE_ESCAPE Animation
const int PG_ESCAPE_ANI_SIZE=3;
const int PG_ESCAPE_ANI_max_cur[]={10,10,10};
const float PG_ESCAPE_ANI_width[]={20,20,20};
const float PG_ESCAPE_ANI_height[]={20,20,20};
const float PG_ESCAPE_ANI_position_x[]={330,330,330};
const float PG_ESCAPE_ANI_position_y[]={215,275,335};
const char PG_ESCAPE_ANI_filename[][20]={"ball","ball","ball"};
bool PG_ESCAPE_control_bar[]={false,false,false};
int PG_ESCAPE_control_selector=0;

///PAGE_COLLECTION Treasure
const int PG_COLLECTION_TRE_SIZE=4;
const int PG_COLLECTION_TRE_max_cur[]={6,6,6,6};
const float PG_COLLECTION_TRE_width[]={120,140,93,120};
const float PG_COLLECTION_TRE_height[]={103,67,120,100};
const float PG_COLLECTION_TRE_position_x[]={220,420,220,430};
const float PG_COLLECTION_TRE_position_y[]={130,160,330,360};
const char PG_COLLECTION_TRE_filename[][20]={"Teeth_get","Teeth","Gun_get","Gun","Hand_get","Hand","Spider_get","Spider"};
