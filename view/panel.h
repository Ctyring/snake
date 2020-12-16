/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/5 19:05
     描述：操作面板文件
*/
//

#ifndef SNAKE_PANEL_H
#define SNAKE_PANEL_H
#include <mem.h>
#include "../common/BASE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct base_panel{
    int x;
    int y;
    int width;//宽度
    int height;//高度
    char hLetter;//横线字符
    char vLetter;//竖线字符
    int color;//前景色
    int bgcolor;//背景色
}Panel;
/**
 * 定义面板中需要的组件
 */
typedef struct base_text_view{
    int x; //坐标
    int y; //坐标
    int color; //前景色
    int bgcolor; //背景色
    int size; //显示宽度
    char txt[100]; //显示字符
    _Bool selecable;//是否可以选择: 0不可选择（默认），1可以被选择
}Textview;
/**
 * 面板初始化
 * @return
 */
Panel* panelInit();
/**
 * 面板绘制函数
 * @param panel 需要被绘制的函数
 */
void drawpanel(Panel* panel);
/**
 * 展示组件的绘制函数
 * @param panel 面板
 * @param views 组件
 * @param len 长度
 */
void drawViews(Panel* panel,Textview* views,int len);
/**
 * 查询选中的组件
 * @param view 组件集合
 * @param len 组件个数
 * @param color 选中状态颜色
 * @return 返回选中组件的下标
 */
int Selctedview(Textview* view,int len,int color);
/**
 * 切换选中组件函数 说明：选中的颜色与背景色与面板相反
 * @param view 所有组件
 * @param len 长度
 * @param color 被选中后的颜色
 * @param bgcolor 选中后的背景色
 * @param up_or_down 向上或向下
 */
void changeview(Textview* view,int len,int color,int bgcolor, _Bool up_or_down);
#endif //SNAKE_PANEL_H
