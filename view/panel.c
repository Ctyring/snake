/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/5 19:05
*/
//
#include "panel.h"
//面板初始化
Panel* panelInit(){
    Panel* panel = (Panel*)malloc(sizeof(Panel));//强制转换类型
    memset(panel,0,sizeof(Panel));//初始化函数
    panel->width = 30;
    panel->height = 12;
    panel->hLetter = '-';
    panel->vLetter = '|';
    panel->color = 0x9;
    panel->bgcolor = 0xE;
    return panel;
}
//面板绘制
void drawpanel(Panel* panel) {
    //背景绘制
    fillText(panel->x ,panel->y,panel->bgcolor<<4|panel->color,' ',panel->width,panel->height);
    //横线绘制
    drawVLine(panel->x,panel->y,panel->bgcolor<<4|panel->color,panel->vLetter,panel->height);
    drawVLine(panel->x+panel->width-1,panel->y,panel->bgcolor<<4|panel->color,panel->vLetter,panel->height);
    //竖线绘制
    drawHLine(panel->x,panel->y,panel->bgcolor<<4|panel->color,panel->hLetter,panel->width);
    drawHLine(panel->x,panel->y+panel->height,panel->bgcolor<<4|panel->color,panel->hLetter,panel->width);
}
//显示组件
void drawViews(Panel *panel, Textview *views, int len) {
    for(int i = 0;i<len;i++)
    {
        Textview* v = views+i;//获取第i个组件的指针
        int x = panel->x + v->x;
        int y = panel->y + v->y;
        setConsorPosition(x,y);
        setColor(v->bgcolor<<4|v->color);
        printText(v->txt,v->size);
    }
}
//查找被选中组件
int Selctedview(Textview *view, int len, int color) {
    int i;
    for( i = 0; i < len;i++)
    {
        Textview* v = view + i;
        if(v->color == color){
            return i;
        }
    }
    return -1;
}
//改变被选中组件
void changeview(Textview* view, int len, int color, int bgcolor, _Bool  up_or_down) {
    //当前是哪一个被选中
    int selctid = Selctedview(view, len, color);
    selctid = selctid > -1 ? selctid : 0;
    //修改当前被选中组件的的颜色
    Textview *selectview = view + selctid;
    selectview->color = bgcolor;
    selectview->bgcolor = color;
    //查找下一个被选中的组件
    Textview *nextSelected = NULL;
    if (up_or_down) {
        for (int i = selctid + 1; i < len + selctid; i++) {
            Textview *v = view + (i % len);
            if (v->selecable) {
                nextSelected = v;
                break;
            }
        }
    } else {
        for (int i = selctid + len - 1; i > 0; i--) {
            Textview *v = view + (i % len);
            if (v->selecable == 1) {
                nextSelected = v;
                break;
            }
        }
    }

    if (nextSelected != NULL) {
        //修改下一个被选中组件的颜色
        nextSelected->color = color;
        nextSelected->bgcolor = bgcolor;
    }
}
