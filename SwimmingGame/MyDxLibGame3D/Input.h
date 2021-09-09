#pragma once
#include "Dxlib.h"

extern int Key[];                   // キーが押されているフレーム数を格納する

extern int Button;

/// <summary>
/// 「何フレーム押されているか」を計算する
/// </summary>
int UpdateKey();