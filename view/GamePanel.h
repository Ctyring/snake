/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/15 19:33
     描述：游戏面板的声明文件
*/
//

#ifndef MAIN_C_GAMEPANEL_H
#define MAIN_C_GAMEPANEL_H
#include "panel.h"
#include "..\model\GameData.h"
#include <windows.h>
#include <wincon.h>
void draw_game_panel();
/**
 *游戏面板的按键处理
 */
void gamePanelKeyhandler();
#endif //MAIN_C_GAMEPANEL_H
