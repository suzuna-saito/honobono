#include "Input.h"

int Key[256];
int Button;


int UpdateKey()
{
    char tmpKey[256];          // ���݂̃L�[�̓��͏�Ԃ��i�[����
    GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

    int tmpButton = GetJoypadInputState(DX_INPUT_PAD1);//�g�p����p�b�h���w�肷��;;

    for (int i = 0; i < 256; i++)
    {
        if (tmpKey[i] != 0 || tmpButton != 0) // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
        {
            Key[i]++;       // ���Z
            Button++;
        }
        else                // ������Ă��Ȃ����
        {
            Key[i] = 0;     // 0�ɂ���
            Button = 0;
        }
    }

    return 0;
}