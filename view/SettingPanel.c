/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/14 12:56
     描述：
*/
//

#include "SettingPanel.h"
#include "panel.h"
#include <string.h>
Panel* Settingpanel = NULL;
Textview Settingpanel_views[] = {
        {5,2,0xF,0x0,100,"背景音乐（开/关）：开",0},
        {5,4,0xF,0x0,100,"音   效（开/关）：开",0},
        {5,6,0xF,0x0,100,"小蛇初始长度：3",0},
        {5,8,0xF,0x0,100,"速度：开",0},
        {5,10,0xF,0x0,100,"背景：0xF",0},
};
/**
 * 游戏的设置信息
 */
Setting* setting_data = NULL;
/**
 * 设置面板的初始化函数
 */
void Setting_init();
void Setting_panel_init(){
    if(Settingpanel == NULL){
        Settingpanel = panelInit();}
        Setting_init();
        Settingpanel->x = 20;
        Settingpanel->y = 2;
        Settingpanel->width = 36;
        Settingpanel->height = 18;
        Settingpanel->bgcolor = 0x0;
        Settingpanel->color = 0xF;
    }
void Setting_init(){
    if(NULL == setting_data){
        setting_data = (Setting*)malloc(sizeof(Setting));
        memset(setting_data,0,sizeof(Setting));
        setting_data->map_width = 16;
        setting_data->map_height = 16;
        setting_data->snake_x = 2;
        setting_data->snake_y = 9;
        setting_data->snake_color = 0xC;
        setting_data->snake_lenth = 3;
        setting_data->snake_speed = 0.3;
        setting_data->direction = S_RIGHT;
    }
}
/**
 * 绘制设置面板
 */
void drawSettingpanel() {
    Setting_panel_init();
    if(NULL != Settingpanel){
        drawpanel(Settingpanel);
        int len = sizeof(Settingpanel_views)/sizeof(Textview);
        drawViews(Settingpanel,Settingpanel_views,len);
    }
}

Setting *getSettingData() {
    if(setting_data == NULL){
        Setting_init();
    }
    return setting_data;
}
