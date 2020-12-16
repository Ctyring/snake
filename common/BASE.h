/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/5 17:02
     ���������������ļ�
 */
//

#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
/**
 * ���ô��ڵı���
 * @param title title ��������
 */
void setTitle(char* title);
/**
 * �����С����
 * @param width ���
 * @param height �߶�
 */
void setWinSize(int width,int height);
/**
 * ���ÿ���̨�й��λ��
 * @param x
 * @param y
 */
void setConsorPosition(int x,int y);
/**
 * ���ô����е���ɫ
 * @param color ��ɫ
 */
void setColor(int color);
/**
 * ���ƺ���
 * @param x ����
 * @param y ����
 * @param color ��ɫ
 * @param letter �����ַ�
 * @param length ���Ƴ���
 */
void drawHLine(int x,int y,int color,int letter,int length);
/**
 * ��������
 * @param x ����
 * @param y ����
 * @param color ��ɫ
 * @param letter �����ַ�
 * @param length ���Ƴ���
 */
void drawVLine(int x,int y,int color,int letter,int length);
/**
 * �ı����
 * @param txt �ı�
 * @param size ����
 */
void printText(char* txt,int size);
/**
 * �ַ����
 * @param x ����
 * @param y ����
 * @param color ��ɫ
 * @param letter �ַ�
 * @param width ���
 * @param height �߶�
 */
void fillText(int x,int y, int color,int letter,int width,int height);
/**
 * �Ӽ��̶�ȡһ���ַ�
 * @return
 */
char readChar();
void disableCurrsor();
#endif // BASE_H_INCLUDED
