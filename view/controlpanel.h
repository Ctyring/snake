/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/6 10:31
     �������������������ļ�
*/
//

#ifndef SNAKE_CONTROLPANEL_H
#define SNAKE_CONTROLPANEL_H
#include "panel.h"
/**
 * �����ⲿ����Ԥ����
 */
typedef  struct conpanel_operator{
    void (*view_game)();//չʾ��Ϸ���
    void (*view_setting_panel)();//չʾ�������
    void (*start_game)();//��ʼ��Ϸ
}conpanel_operator;
/**
 * ������������ʵ���ļ�
 */
void drawControlPanel();
void control_panel_key_bind();
/**
 * ���ÿ������Ĵ�����
 * @program op ��ز���
 */
void setconPanelOperator(conpanel_operator* op);
/**
 * �޸���Ϸ�е�����
 * @param score ����
 * @param len ����
 * @param speed �ٶ�
 */
void setGameInfo(int score, int len , double speed);
void viewpanelByselected(int len);
#endif //SNAKE_CONTROLPANEL_H
