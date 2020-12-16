/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/15 19:45
     描述：游戏控制器的声明
*/
//

#ifndef MAIN_C_GAMECONTROL_H
#define MAIN_C_GAMECONTROL_H
#include "../model/GameData.h"
#include "../view/controlpanel.h"
#include "../view/GamePanel.h"
#include "../view/SettingPanel.h"
/**
 * 预处理处理游戏的相关数据
 */
void readygame();
/**
 * 小蛇死亡判定函数
 * @return 1为死亡，游戏结束
 */
_Bool checkDead();
#endif //MAIN_C_GAMECONTROL_H
