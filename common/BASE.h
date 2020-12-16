/*   创建者 ：CTY
     QQ：173479693
     时间：2020/10/5 17:02
     描述：基本功能文件
 */
//

#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
/**
 * 设置窗口的标题
 * @param title title 标题内容
 */
void setTitle(char* title);
/**
 * 窗体大小设置
 * @param width 宽度
 * @param height 高度
 */
void setWinSize(int width,int height);
/**
 * 设置控制台中光标位置
 * @param x
 * @param y
 */
void setConsorPosition(int x,int y);
/**
 * 设置窗体中的颜色
 * @param color 颜色
 */
void setColor(int color);
/**
 * 绘制横线
 * @param x 坐标
 * @param y 坐标
 * @param color 颜色
 * @param letter 绘制字符
 * @param length 绘制长度
 */
void drawHLine(int x,int y,int color,int letter,int length);
/**
 * 绘制竖线
 * @param x 坐标
 * @param y 坐标
 * @param color 颜色
 * @param letter 绘制字符
 * @param length 绘制长度
 */
void drawVLine(int x,int y,int color,int letter,int length);
/**
 * 文本输出
 * @param txt 文本
 * @param size 长度
 */
void printText(char* txt,int size);
/**
 * 字符填充
 * @param x 坐标
 * @param y 坐标
 * @param color 颜色
 * @param letter 字符
 * @param width 宽度
 * @param height 高度
 */
void fillText(int x,int y, int color,int letter,int width,int height);
/**
 * 从键盘读取一个字符
 * @return
 */
char readChar();
void disableCurrsor();
#endif // BASE_H_INCLUDED
