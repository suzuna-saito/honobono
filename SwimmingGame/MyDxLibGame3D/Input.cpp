#include "Input.h"

int Key[256];
int Button;


int UpdateKey()
{
    char tmpKey[256];          // 現在のキーの入力状態を格納する
    GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る

    int tmpButton = GetJoypadInputState(DX_INPUT_PAD1);//使用するパッドを指定する;;

    for (int i = 0; i < 256; i++)
    {
        if (tmpKey[i] != 0 || tmpButton != 0) // i番のキーコードに対応するキーが押されていたら
        {
            Key[i]++;       // 加算
            Button++;
        }
        else                // 押されていなければ
        {
            Key[i] = 0;     // 0にする
            Button = 0;
        }
    }

    return 0;
}