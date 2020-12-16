/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/6 21:27
     描述：事件处理的声明和定义
*/
//

#ifndef SNAKE_KEYHANDER_H
#define SNAKE_KEYHANDER_H
/**
 * 定义结构处理默认的方向量
 */
typedef struct default_key_handler{
    void* (*up)(char);//上方向
    void* (*down)(char);//下方向
    void* (*left)(char);//左方向
    void* (*right)(char);//右方向
}defaulthandler;
/**
 * 特殊键位处理
 */
typedef struct keymapping{
    char key;
    void* (*keyhandler)(char);//键位对应的处理
}KeyMapping;
/**
 * 外部调用的按键处理函数
 * @param handler 默认按键处理
 * @param maps 特殊按键处理
 * @param len 处理集的长度
 */
void keyhandleroperator(defaulthandler* handler,KeyMapping* maps,int len);
#endif //SNAKE_KEYHANDER_H
