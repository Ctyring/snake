/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/13 23:05
     ��������������˵���ļ�
*/
//

#ifndef MAIN_C_SETTINGPANEL_H
#define MAIN_C_SETTINGPANEL_H
#include "..\common\BASE.h"
#include "keyhander.h"
#include "..\model\GameData.h"
typedef struct _setting_data{
    int snake_x;//С�߳�ʼx����
    int snake_y;//С�߳�ʼy����
    int snake_color;//С����ɫ
    double snake_speed;//С�ߵ��ٶ�
    int snake_lenth;//С�߳�ʼ����
    int map_width;//��ͼ���
    int map_height;//��ͼ�߶�
    snakeDirection direction;//С��Ĭ�ϵ��ƶ�����
}Setting;
void drawSettingpanel();
Setting* getSettingData();
#endif //MAIN_C_SETTINGPANEL_H
