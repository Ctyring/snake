/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/5 17:02
*/
//
#include <Windows.h>
#include <stdio.h>
#include "BASE.h"
#include <conio.h>
#include <stdbool.h>

//表示全局的窗体句柄
HANDLE std_win_handle = 0;
/**
 * 获取标准的输出句柄
 */
void setWinHandle(){
    if(std_win_handle == 0){
        std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    }
}
/**
 * 双缓冲内容，后期再调整
 *创建新的控制台缓冲区
        HANDLE  hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,//定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
);
//创建新的控制台缓冲区
HANDLE  hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,//定义缓冲区可共享写权限
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
//设置窗口尺寸需要使用 setWindowInfo 实现，还需要窗体的句柄
void setWinSize(int width, int height) {
    SMALL_RECT rect = {0,0,width-1,height-1};//窗口大小区域
    COORD coord = {width,height};//缓冲区的区域
    setWinHandle();//
    SetConsoleScreenBufferSize(std_win_handle,coord);//设置缓冲区
    SetConsoleWindowInfo(std_win_handle,TRUE,&rect);//设置窗体大小
}

void setConsorPosition(int x, int y) {
    COORD pos = {x,y};
    setWinHandle();
    SetConsoleCursorPosition(std_win_handle,pos);
}
/**
 * 颜色属性由两个十六进制数字指定 -- 第一个
对应于背景，第二个对应于前景。每个数字
可以为以下任何值:

    0 = 黑色       8 = 灰色
    1 = 蓝色       9 = 淡蓝色
    2 = 绿色       A = 淡绿色
    3 = 浅绿色     B = 淡浅绿色
    4 = 红色       C = 淡红色
    5 = 紫色       D = 淡紫色
    6 = 黄色       E = 淡黄色
    7 = 白色       F = 亮白色
 * @param color 颜色
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
    DWORD relen;//用不到，凑格式；
    for(int i = 0;i<height;i++)
    {
        COORD coord ={x,y++};
        FillConsoleOutputAttribute(std_win_handle,color,width,coord,&relen);
        FillConsoleOutputCharacterA(std_win_handle,letter,width,coord,&relen);
    }
}

char readChar() {
    char rech; //返回的字符
    if(kbhit())
    {
        rech = getch();
    }
    return rech;
}
/**
 * 隐藏光标
 */
void disableCurrsor() {
    CONSOLE_CURSOR_INFO cursor_info;
    cursor_info.bVisible = FALSE;
    cursor_info.dwSize = 1;
    SetConsoleCursorInfo(std_win_handle,&cursor_info);
}

