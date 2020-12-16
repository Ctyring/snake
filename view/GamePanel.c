/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/15 19:33
     ��������������ʵ���ļ�
*/
//

#include "GamePanel.h"
#include "panel.h"
#include "../model/GameData.h"
#include "keyhander.h"
/**
 * ��ʾ��Ϸ���
 */
Panel* game_panel = NULL;
/**
 * ʹ���ⲿ�ļ��е�ȫ�ֱ���
 */
extern GameData* gameData;
/**
 * ��Ϸ���ĳ�ʼ��
 */
void init_ganmepanel(){
    game_panel = panelInit();
    game_panel->x = 20;
    game_panel->y = 2;
    game_panel->width = 36;
    game_panel->height = 18;
    game_panel->color = 0x0;
    game_panel->bgcolor = 0xF;
}

void drawGameData(){
    //ʳ��Ļ���
    int food_x = game_panel->x + gameData->food->x * 2 + 1;//���x���� + ����x����*2
    int food_y = game_panel->y + gameData->food->y + 1;
    setConsorPosition(food_x,food_y);
    setColor(game_panel->bgcolor << 4|gameData->food->color);
    printText("��",2);
    //С�ߵĻ���
    SnakeNode* loop;
    for(loop = gameData->snake;loop != NULL; loop = loop->next){
        int node_x = game_panel->x + loop->x *2 + 1;
        int node_y = game_panel->y + loop->y + 1;
        setConsorPosition(node_x,node_y);
        setColor(game_panel->bgcolor << 4|loop->color);
        printText("��",2);
    }
}
/**
 * ��Ϸ���Ļ���
 */
void draw_game_panel() {
    init_ganmepanel();
    if(NULL != game_panel){
        drawpanel(game_panel);
        if(NULL != gameData){
            drawGameData();
        }
    }
}
/**
 * ���������
 * @param key
 * @return
 */
void* gamepanel_up(char key){
    if(gameData->direction != S_DOWN){
        gameData->direction = S_UP;
    }
}
void* gamepanel_down(char key){
    if(gameData->direction != S_UP){
        gameData->direction = S_DOWN;
    }
}
void* gamepanel_left(char key){
    if(gameData->direction != S_RIGHT){
        gameData->direction = S_LEFT;
    }
}
void* gamepanel_right(char key){
    if(gameData->direction != S_LEFT){
        gameData->direction = S_RIGHT;
    }
}
/**
 * ��Ϸ���İ�������
 */
void gamePanelKeyhandler() {
    defaulthandler handler = {gamepanel_up,gamepanel_down,gamepanel_left,gamepanel_right};
    keyhandleroperator(&handler,NULL,0);
}

