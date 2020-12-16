/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/5 19:05
     ��������������ļ�
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
    int width;//���
    int height;//�߶�
    char hLetter;//�����ַ�
    char vLetter;//�����ַ�
    int color;//ǰ��ɫ
    int bgcolor;//����ɫ
}Panel;
/**
 * �����������Ҫ�����
 */
typedef struct base_text_view{
    int x; //����
    int y; //����
    int color; //ǰ��ɫ
    int bgcolor; //����ɫ
    int size; //��ʾ���
    char txt[100]; //��ʾ�ַ�
    _Bool selecable;//�Ƿ����ѡ��: 0����ѡ��Ĭ�ϣ���1���Ա�ѡ��
}Textview;
/**
 * ����ʼ��
 * @return
 */
Panel* panelInit();
/**
 * �����ƺ���
 * @param panel ��Ҫ�����Ƶĺ���
 */
void drawpanel(Panel* panel);
/**
 * չʾ����Ļ��ƺ���
 * @param panel ���
 * @param views ���
 * @param len ����
 */
void drawViews(Panel* panel,Textview* views,int len);
/**
 * ��ѯѡ�е����
 * @param view �������
 * @param len �������
 * @param color ѡ��״̬��ɫ
 * @return ����ѡ��������±�
 */
int Selctedview(Textview* view,int len,int color);
/**
 * �л�ѡ��������� ˵����ѡ�е���ɫ�뱳��ɫ������෴
 * @param view �������
 * @param len ����
 * @param color ��ѡ�к����ɫ
 * @param bgcolor ѡ�к�ı���ɫ
 * @param up_or_down ���ϻ�����
 */
void changeview(Textview* view,int len,int color,int bgcolor, _Bool up_or_down);
#endif //SNAKE_PANEL_H
