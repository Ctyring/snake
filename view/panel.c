/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/5 19:05
*/
//
#include "panel.h"
//����ʼ��
Panel* panelInit(){
    Panel* panel = (Panel*)malloc(sizeof(Panel));//ǿ��ת������
    memset(panel,0,sizeof(Panel));//��ʼ������
    panel->width = 30;
    panel->height = 12;
    panel->hLetter = '-';
    panel->vLetter = '|';
    panel->color = 0x9;
    panel->bgcolor = 0xE;
    return panel;
}
//������
void drawpanel(Panel* panel) {
    //��������
    fillText(panel->x ,panel->y,panel->bgcolor<<4|panel->color,' ',panel->width,panel->height);
    //���߻���
    drawVLine(panel->x,panel->y,panel->bgcolor<<4|panel->color,panel->vLetter,panel->height);
    drawVLine(panel->x+panel->width-1,panel->y,panel->bgcolor<<4|panel->color,panel->vLetter,panel->height);
    //���߻���
    drawHLine(panel->x,panel->y,panel->bgcolor<<4|panel->color,panel->hLetter,panel->width);
    drawHLine(panel->x,panel->y+panel->height,panel->bgcolor<<4|panel->color,panel->hLetter,panel->width);
}
//��ʾ���
void drawViews(Panel *panel, Textview *views, int len) {
    for(int i = 0;i<len;i++)
    {
        Textview* v = views+i;//��ȡ��i�������ָ��
        int x = panel->x + v->x;
        int y = panel->y + v->y;
        setConsorPosition(x,y);
        setColor(v->bgcolor<<4|v->color);
        printText(v->txt,v->size);
    }
}
//���ұ�ѡ�����
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
//�ı䱻ѡ�����
void changeview(Textview* view, int len, int color, int bgcolor, _Bool  up_or_down) {
    //��ǰ����һ����ѡ��
    int selctid = Selctedview(view, len, color);
    selctid = selctid > -1 ? selctid : 0;
    //�޸ĵ�ǰ��ѡ������ĵ���ɫ
    Textview *selectview = view + selctid;
    selectview->color = bgcolor;
    selectview->bgcolor = color;
    //������һ����ѡ�е����
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
        //�޸���һ����ѡ���������ɫ
        nextSelected->color = color;
        nextSelected->bgcolor = bgcolor;
    }
}
