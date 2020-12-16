/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/6 10:31
     描述：控制面板的实现文件
*/
//

#include "controlpanel.h"
#include "keyhander.h"
#include <string.h>
Panel * controlpanel = NULL;
/**
 * 全局控制面板操作
 */
conpanel_operator*  conpanel_op = NULL;
/**
 * 定义在控制面板中要展示的组件
 */
 Textview conviews[] =
         {
        {5,2,0xE,0x0,8,"分数：0",0},
        {5,5,0xE,0x0,8,"长度：0",0},
        {5,8,0xE,0x0,8,"秒/格：0",0},
        {5,11,0x0,0xE,8,"游戏",1},
        {5,14,0xE,0x0,8,"设置",1}
 };
 /**
  * 根据被选中的组件绘制面板
  * @param len
  */
void viewpanelByselected(int len) {
    if (NULL != conpanel_op) {
        int queryID = Selctedview(conviews, len, controlpanel->bgcolor);
        Textview* v = &conviews[queryID];
        if (strcmp(v->txt, "游戏") == 0) {
            if (conpanel_op->view_setting_panel != NULL) {
                conpanel_op->view_game();
            }
        }
        else if (strcmp(v->txt, "设置") == 0) {
            if (conpanel_op->view_setting_panel != NULL) {
                conpanel_op->view_setting_panel();
            }
        }
    }
}

void callpanel_view(int len) {
     if (NULL != conpanel_op) {
         int selectID = Selctedview(conviews,len, controlpanel->bgcolor);
         if (selectID > -1) {
             Textview *v = &conviews[selectID];
             if (strcmp(v->txt, "游戏")) {
                 if (conpanel_op->view_game != NULL) {
                     conpanel_op->view_game();
                 }
             } else {
                 strcmp(v->txt, "设置");
                 {
                     if (conpanel_op->view_setting_panel != NULL) {
                         conpanel_op->view_setting_panel();
                     }
                 }
             }
         }
     }
 }
void* control_panel_up_handler(char v){
    int len = sizeof(conviews)/sizeof(Textview);
    changeview(conviews,len,controlpanel->bgcolor,controlpanel->color,0);
    drawViews(controlpanel,conviews,len);
    viewpanelByselected(len);
 }
void* control_panel_down_handler(char v){
   int len = sizeof(conviews)/sizeof(Textview);
   changeview(conviews,len,controlpanel->bgcolor,controlpanel->color,1);
   drawViews(controlpanel,conviews,len);
   viewpanelByselected(len);
}

void* enter_key_press(char v){
    setConsorPosition(18,12);
    if(conpanel_op!=NULL && conpanel_op->start_game!= NULL){
    int len = sizeof(conviews)/sizeof(Textview);
    int selectID = Selctedview(conviews,len,controlpanel->bgcolor);
         if(selectID == 3){
             conpanel_op->start_game();
         }
    conpanel_op->start_game();
     }
 }
//控制面板的实现
void drawControlPanel() {
    if(controlpanel == NULL){
        controlpanel = panelInit();
        controlpanel->x = 2;
        controlpanel->y = 2;
        controlpanel->width = 18;
        controlpanel->height = 18;
        controlpanel->color = 0xE;
        controlpanel->bgcolor = 0x0;
    }
    drawpanel(controlpanel);
    int view_len = sizeof(conviews)/sizeof(Textview);
    drawViews(controlpanel,conviews,view_len);//绘制组件
}

void control_panel_key_bind() {
    defaulthandler hander = {control_panel_up_handler,control_panel_down_handler};
    KeyMapping mappings [] = {
            {13,enter_key_press}
    };
    int len = sizeof(mappings)/sizeof(KeyMapping);
    keyhandleroperator(&hander,mappings,len);
}

void setconPanelOperator(conpanel_operator *op) {
    conpanel_op = op;
}

void setGameInfo(int score, int len, double speed) {
    char score_str[100];
    sprintf(score_str,"分数：%d",score);
    strcpy(conviews[0].txt,score_str);
    char len_str[100];
    sprintf(len_str,"长度：%d",len);
    strcpy(conviews[1].txt,len_str);
    char speed_str[100];
    sprintf(speed_str,"秒/格：%.2lf",speed);
    strcpy(conviews[2].txt,speed_str);
    drawControlPanel();
}
