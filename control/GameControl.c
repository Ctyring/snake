/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/15 19:45
     描述：游戏控制器的定义
*/
//

#include <synchapi.h>
#include "GameControl.h"
#include <time.h>
/**
 * 全局的游戏数据
 */
GameData* gameData = NULL;

void positionBydirection(int *x, int *y);

void freshfoodInfo();

void resetgame();
void snakeMove(){
    //9,0 9,1 9,2(蛇头)
    int x;
    int y;
    positionBydirection(&x, &y);
    //2、从最后一节开始依次获取前一节身体坐标（第一节身体依旧是原来坐标）
    SnakeNode* loop = NULL;
    for(loop = gameData->snaketail;loop->prev != NULL; loop = loop->prev){
        loop->x = loop->prev->x;
        loop->y = loop->prev->y;
    }
    //3、设置最新的坐标给最新的身体
    gameData->snake->x = x;
    gameData->snake->y = y;
}

void positionBydirection(int *x, int *y) {
    (*x) = gameData->snake->x;
    (*y) = gameData->snake->y;//1、获取最新坐标
    switch (gameData->direction) {
        case S_UP:
            (*y)--;
            if((*y) < 0){
                (*y) = gameData->map_height;
            }
            break;
        case S_DOWN:
            (*y)++;
            if((*y) > gameData->map_height){
                (*y) = 0;
            }
            break;
        case S_LEFT:
            (*x)--;
            if((*x) < 0){
                (*x) = gameData->map_width;
            }
            break;
        case S_RIGHT:
            (*x)++;
            if((*x) > gameData->map_width){
                (*x) = 0;
            }
            break;
        default:
            break;
    }
}

/**
 * 小蛇捕食食物
 */
void eatFood(){
    if(gameData->snake->x == gameData->food->x && gameData->snake->y == gameData->food->y){
        SnakeNode* node = (SnakeNode*)malloc(sizeof(SnakeNode));
        node->prev = NULL;
        int x = gameData->snake->x;
        int y = gameData->snake->y;
        positionBydirection(&x, &y);
        node->x = x;
        node->y = y;
        node->color = gameData->food->color;
        node->next = gameData->snake;
        gameData->snake->prev = node;
        gameData->snake = node;
        gameData->score += 10;
        if(gameData->score > 0 && gameData->score % 20 && gameData->speed > 0.05){
            gameData->speed -= 0.01;
        }
        gameData->len ++;
        setGameInfo(gameData->score,gameData->len,gameData->speed);
        //修改食物的坐标以及颜色
        freshfoodInfo();
    }
}
void startgame(){
    setGameInfo(gameData->score,gameData->len,gameData->speed);
    for(;checkDead()==0;){
        gamePanelKeyhandler();
        eatFood();
        snakeMove();
        draw_game_panel();
        int s_time = gameData->speed*1000;
        Sleep(s_time);
    }
    setConsorPosition(30,10);
    setColor(0x4F);
    printText("小蛇死亡！",100);
    resetgame();
    getchar();
}
/**
 * 小蛇的初始化
 */
void snake_init(Setting* set){
    int i = 0;
    for(i=set->snake_lenth-1;i>=0;i--){
        SnakeNode* node = (SnakeNode*)malloc(sizeof(SnakeNode));
        node->x = i;
        node->y = set->snake_y;
        node->color = set->snake_color;
        node->next = NULL;
        node->prev = NULL;
        if(gameData->snake == NULL){
            gameData->snake = node;
            gameData->snaketail = node;
        }
        else{
            //尾巴的下一节拼接到当前节点
            gameData->snaketail->next = node;
            //当前节点的上一节拼接到尾巴上
            node->prev = gameData->snaketail;
            //当前节点设置为尾巴
            gameData->snaketail = node;
        }
    }
}
void gameIntial(){
    srand(time(NULL));
    Setting* setting = getSettingData();
    if(NULL == gameData){
        gameData = (GameData*)malloc(sizeof(GameData));
        memset(gameData,0,sizeof(GameData));
        gameData->snake = NULL;
        gameData->snaketail = NULL;
        gameData->food = NULL;
    }
    gameData->map_width = setting->map_width;
    gameData->map_height = setting->map_height;
    gameData->len = setting->snake_lenth;
    gameData->direction = setting->direction;
    if(NULL == gameData->snake){
        snake_init(setting);
    }
    if(NULL == gameData->food){
        gameData->food = (Food*)malloc(sizeof(Food));
        freshfoodInfo();
    }
    gameData->score = 0;
    gameData->speed = setting->snake_speed;
}

void freshfoodInfo() {
    gameData->food->x = rand() % gameData->map_width;
    gameData->food->y = rand()%gameData->map_height;
    gameData->food->color = rand()%0xF;
}

void readygame() {
    setTitle("贪吃蛇");
    setWinSize(60,27);
    disableCurrsor();
    gameIntial();
    drawControlPanel();
    draw_game_panel();
    conpanel_operator control_op = {
            draw_game_panel,
            drawSettingpanel,
            startgame
    };
    setconPanelOperator(&control_op);
    for(;;){
        control_panel_key_bind();
        Sleep(100);
    }
}

_Bool checkDead() {
    SnakeNode* loop = NULL;
    for(loop = gameData->snake->next; loop != NULL;loop = loop->next){
        if(loop->x == gameData->snake->x && loop->y == gameData->snake->y){
            return 1;
        }
    }
    return 0;
}
/**
 * 重新开始游戏
 */
void resetgame(){
    //小蛇的数据释放
    SnakeNode* loop = NULL;
    for(loop = gameData->snaketail->prev;loop!=NULL;loop=loop->prev){
        free(loop->next);
        loop->next = NULL;
    }
    //处理头的释放
    free(gameData->snake);
    gameData->snake = NULL;
    gameData->snaketail = NULL;
    //重置游戏数据
    Setting* setting = getSettingData();
    gameData->len = setting->snake_lenth;
    gameData->speed = setting->snake_speed;
    gameData->direction = setting->direction;
    gameData->score = 0;
    freshfoodInfo();
    snake_init(setting);
}
