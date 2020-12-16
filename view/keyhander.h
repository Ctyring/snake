/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/6 21:27
     �������¼�����������Ͷ���
*/
//

#ifndef SNAKE_KEYHANDER_H
#define SNAKE_KEYHANDER_H
/**
 * ����ṹ����Ĭ�ϵķ�����
 */
typedef struct default_key_handler{
    void* (*up)(char);//�Ϸ���
    void* (*down)(char);//�·���
    void* (*left)(char);//����
    void* (*right)(char);//�ҷ���
}defaulthandler;
/**
 * �����λ����
 */
typedef struct keymapping{
    char key;
    void* (*keyhandler)(char);//��λ��Ӧ�Ĵ���
}KeyMapping;
/**
 * �ⲿ���õİ���������
 * @param handler Ĭ�ϰ�������
 * @param maps ���ⰴ������
 * @param len �����ĳ���
 */
void keyhandleroperator(defaulthandler* handler,KeyMapping* maps,int len);
#endif //SNAKE_KEYHANDER_H
