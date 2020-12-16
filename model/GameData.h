/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/18 9:10
     ������
*/
//

#ifndef MAIN_C_GAMEDATA_H
#define MAIN_C_GAMEDATA_H
/**
 * ������ṹ
 */
typedef struct _snake_node{
    int x;//���������x
    int y;//���������y
    int color;//��ʾ�������ɫ
    struct _snake_node* next;
    struct _snake_node* prev;
}SnakeNode;
/**
 * ʳ��Ľṹ
 */
typedef struct _food{
    int x;//ʳ���x
    int y;//ʳ���y
    int color;//ʳ�����ɫ
}Food;
/**
 * С���ƶ�����
 */
typedef enum _snake_direction{
    S_UP = 'w',//�Ϸ���
    S_DOWN = 's',//��
    S_LEFT = 'a',//��
    S_RIGHT = 'd'//��
}snakeDirection;
/**
 * ��Ϸ����
 */
typedef struct _game_data {
    int score;//�÷�
    int len;//����
    double speed;//�ٶ�
    SnakeNode *snake;//С��
    SnakeNode *snaketail;//С�ߵ�β��
    Food * food;//ʳ��
    snakeDirection direction;//��ǰ�ƶ�����
    int map_width;//��ͼ�ĸ߶�
    int map_height;//��ͼ�Ŀ��
}GameData;
#endif //MAIN_C_GAMEDATA_H
