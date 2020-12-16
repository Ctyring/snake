/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/6 10:31
     描述：控制面板的声明文件
*/
//

#ifndef SNAKE_CONTROLPANEL_H
#define SNAKE_CONTROLPANEL_H
#include "panel.h"
/**
 * 定义外部控制预处理
 */
typedef  struct conpanel_operator{
    void (*view_game)();//展示游戏面板
    void (*view_setting_panel)();//展示设置面板
    void (*start_game)();//开始游戏
}conpanel_operator;
/**
 * 声明控制面板的实现文件
 */
void drawControlPanel();
void control_panel_key_bind();
/**
 * 设置控制面板的处理函数
 * @program op 相关操作
 */
void setconPanelOperator(conpanel_operator* op);
/**
 * 修改游戏中的数据
 * @param score 分数
 * @param len 长度
 * @param speed 速度
 */
void setGameInfo(int score, int len , double speed);
void viewpanelByselected(int len);
#endif //SNAKE_CONTROLPANEL_H
