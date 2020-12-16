/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/5 17:02
*/
//
#include <Windows.h>
#include <stdio.h>
#include "BASE.h"
#include <conio.h>
#include <stdbool.h>

//��ʾȫ�ֵĴ�����
HANDLE std_win_handle = 0;
/**
 * ��ȡ��׼��������
 */
void setWinHandle(){
    if(std_win_handle == 0){
        std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    }
}
/**
 * ˫�������ݣ������ٵ���
 *�����µĿ���̨������
        HANDLE  hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//������̿�����������д����
        FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
);
//�����µĿ���̨������
HANDLE  hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//������̿�����������д����
        FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
);
static _Bool flag = true;
if(flag){
std_win_handle = hOutBuf;
SetConsoleActiveScreenBuffer(std_win_handle);
flag = false;
}
else{
std_win_handle = hOutput;
SetConsoleActiveScreenBuffer(std_win_handle);
flag = true;
}
 */
void setTitle(char* title)
{
    SetConsoleTitle(title);
}
//���ô��ڳߴ���Ҫʹ�� setWindowInfo ʵ�֣�����Ҫ����ľ��
void setWinSize(int width, int height) {
    SMALL_RECT rect = {0,0,width-1,height-1};//���ڴ�С����
    COORD coord = {width,height};//������������
    setWinHandle();//
    SetConsoleScreenBufferSize(std_win_handle,coord);//���û�����
    SetConsoleWindowInfo(std_win_handle,TRUE,&rect);//���ô����С
}

void setConsorPosition(int x, int y) {
    COORD pos = {x,y};
    setWinHandle();
    SetConsoleCursorPosition(std_win_handle,pos);
}
/**
 * ��ɫ����������ʮ����������ָ�� -- ��һ��
��Ӧ�ڱ������ڶ�����Ӧ��ǰ����ÿ������
����Ϊ�����κ�ֵ:

    0 = ��ɫ       8 = ��ɫ
    1 = ��ɫ       9 = ����ɫ
    2 = ��ɫ       A = ����ɫ
    3 = ǳ��ɫ     B = ��ǳ��ɫ
    4 = ��ɫ       C = ����ɫ
    5 = ��ɫ       D = ����ɫ
    6 = ��ɫ       E = ����ɫ
    7 = ��ɫ       F = ����ɫ
 * @param color ��ɫ
 */
void setColor(int color) {
    setWinHandle();
    SetConsoleTextAttribute(std_win_handle,color);
}

void drawHLine(int x, int y, int color, int letter, int length) {
    setConsorPosition(x,y);
    setColor(color);
    int i;
    for(i=0;i<length;i++)
    {
        printf("%c",letter);
    }
}

void drawVLine(int x, int y, int color, int letter, int length) {
    setConsorPosition(x,y);
    setColor(color);
    int i;
    for(i=0;i<length;i++)
    {
        printf("%c",letter);
        setConsorPosition(x,++y);
    }
}

void printText(char* txt, int size) {
    char format[30] = "%-";
    char sizebuf[100];
    itoa(size,sizebuf,100);
    strcat(format,sizebuf);
    strcat(format,"s");
    printf(format,txt);
}

void fillText(int x, int y, int color, int letter, int width, int height) {
    setWinHandle();
    DWORD relen;//�ò������ո�ʽ��
    for(int i = 0;i<height;i++)
    {
        COORD coord ={x,y++};
        FillConsoleOutputAttribute(std_win_handle,color,width,coord,&relen);
        FillConsoleOutputCharacterA(std_win_handle,letter,width,coord,&relen);
    }
}

char readChar() {
    char rech; //���ص��ַ�
    if(kbhit())
    {
        rech = getch();
    }
    return rech;
}
/**
 * ���ع��
 */
void disableCurrsor() {
    CONSOLE_CURSOR_INFO cursor_info;
    cursor_info.bVisible = FALSE;
    cursor_info.dwSize = 1;
    SetConsoleCursorInfo(std_win_handle,&cursor_info);
}

