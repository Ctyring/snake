/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/6 10:31
     ��������������ʵ���ļ�
*/
//

#include "controlpanel.h"
#include "keyhander.h"
#include <string.h>
Panel * controlpanel = NULL;
/**
 * ȫ�ֿ���������
 */
conpanel_operator*  conpanel_op = NULL;
/**
 * �����ڿ��������Ҫչʾ�����
 */
 Textview conviews[] =
         {
        {5,2,0xE,0x0,8,"������0",0},
        {5,5,0xE,0x0,8,"���ȣ�0",0},
        {5,8,0xE,0x0,8,"��/��0",0},
        {5,11,0x0,0xE,8,"��Ϸ",1},
        {5,14,0xE,0x0,8,"����",1}
 };
 /**
  * ���ݱ�ѡ�е�����������
  * @param len
  */
void viewpanelByselected(int len) {
    if (NULL != conpanel_op) {
        int queryID = Selctedview(conviews, len, controlpanel->bgcolor);
        Textview* v = &conviews[queryID];
        if (strcmp(v->txt, "��Ϸ") == 0) {
            if (conpanel_op->view_setting_panel != NULL) {
                conpanel_op->view_game();
            }
        }
        else if (strcmp(v->txt, "����") == 0) {
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
             if (strcmp(v->txt, "��Ϸ")) {
                 if (conpanel_op->view_game != NULL) {
                     conpanel_op->view_game();
                 }
             } else {
                 strcmp(v->txt, "����");
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
//��������ʵ��
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
    drawViews(controlpanel,conviews,view_len);//�������
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
    sprintf(score_str,"������%d",score);
    strcpy(conviews[0].txt,score_str);
    char len_str[100];
    sprintf(len_str,"���ȣ�%d",len);
    strcpy(conviews[1].txt,len_str);
    char speed_str[100];
    sprintf(speed_str,"��/��%.2lf",speed);
    strcpy(conviews[2].txt,speed_str);
    drawControlPanel();
}
