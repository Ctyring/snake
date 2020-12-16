/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/18 9:10
     描述：
*/
//

#ifndef MAIN_C_GAMEDATA_H
#define MAIN_C_GAMEDATA_H
/**
 * 蛇身体结构
 */
typedef struct _snake_node{
    int x;//本节身体的x
    int y;//本节身体的y
    int color;//表示身体的颜色
    struct _snake_node* next;
    struct _snake_node* prev;
}SnakeNode;
/**
 * 食物的结构
 */
typedef struct _food{
    int x;//食物的x
    int y;//食物的y
    int color;//食物的颜色
}Food;
/**
 * 小蛇移动方向
 */
typedef enum _snake_direction{
    S_UP = 'w',//上方向
    S_DOWN = 's',//下
    S_LEFT = 'a',//左
    S_RIGHT = 'd'//右
}snakeDirection;
/**
 * 游戏数据
 */
typedef struct _game_data {
    int score;//得分
    int len;//长度
    double speed;//速度
    SnakeNode *snake;//小蛇
    SnakeNode *snaketail;//小蛇的尾巴
    Food * food;//食物
    snakeDirection direction;//当前移动方向
    int map_width;//地图的高度
    int map_height;//地图的宽度
}GameData;
#endif //MAIN_C_GAMEDATA_H
