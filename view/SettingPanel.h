/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/13 23:05
     描述：设置面板的说明文件
*/
//

#ifndef MAIN_C_SETTINGPANEL_H
#define MAIN_C_SETTINGPANEL_H
#include "..\common\BASE.h"
#include "keyhander.h"
#include "..\model\GameData.h"
typedef struct _setting_data{
    int snake_x;//小蛇初始x坐标
    int snake_y;//小蛇初始y坐标
    int snake_color;//小蛇颜色
    double snake_speed;//小蛇的速度
    int snake_lenth;//小蛇初始长度
    int map_width;//地图宽度
    int map_height;//地图高度
    snakeDirection direction;//小蛇默认的移动方向
}Setting;
void drawSettingpanel();
Setting* getSettingData();
#endif //MAIN_C_SETTINGPANEL_H
