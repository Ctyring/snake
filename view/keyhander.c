/*   ������ ��CTY
     QQ��173479693
     ʱ�䣺2020/10/6 21:27
     ������
*/
//
#include "..\common\BASE.h"
#include "keyhander.h"
#include <string.h>
/**
 * �ⲿ���õİ���������
 * @param handler Ĭ�ϰ�������
 * @param maps ���ⰴ������
 * @param len �����ĳ���
 */
void keyhandleroperator(defaulthandler *handler, KeyMapping *maps, int len) {
    char recivekey = 0;
    recivekey = readChar();
    if(recivekey!=0){
        //���水������
        if(recivekey==0xffffffe0)
        {
            recivekey = readChar();
        }
        if(handler != NULL) {
            switch (recivekey) {
                case 'w'://�� 0x48
                case 0x48:
                    if (handler->up != NULL) {
                        handler->up('w');
                    }
                    break;
                case 's'://�� 0x50
                case 0x50:
                    if (handler->down != NULL) {
                        handler->down('s');
                    }
                    break;
                case 'a'://�� 0x4b
                case 0x4b:
                if (handler->left != NULL) {
                        handler->left('a');
                    }
                    break;
                case 'd'://�� 0x4d
                case 0x4d:
                    if (handler->right != NULL) {
                        handler->right('d');
                    }
                    break;
            }
        }
        //���ⰴ��ӳ��
        if(maps != NULL && len > 0){
            int i;
            for(i = 0;i < len;i++){
                KeyMapping* mapping = maps + i;
                if(mapping->key == recivekey){
                    if(mapping->keyhandler != NULL){
                        mapping->keyhandler(recivekey);
                    }
                }
            }
        }
    }
}
