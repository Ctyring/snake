/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/14 12:56
     ������
*/
//

#include "SettingPanel.h"
#include "panel.h"
#include <string.h>
Panel* Settingpanel = NULL;
Textview Settingpanel_views[] = {
        {5,2,0xF,0x0,100,"�������֣���/�أ�����",0},
        {5,4,0xF,0x0,100,"��   Ч����/�أ�����",0},
        {5,6,0xF,0x0,100,"С�߳�ʼ���ȣ�3",0},
        {5,8,0xF,0x0,100,"�ٶȣ���",0},
        {5,10,0xF,0x0,100,"������0xF",0},
};
/**
 * ��Ϸ��������Ϣ
 */
Setting* setting_data = NULL;
/**
 * �������ĳ�ʼ������
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
 * �����������
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
