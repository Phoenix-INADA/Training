#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "training.h"

// 静的領域変数 宣言
static STRUC st1[] = {
    {{0x10101010,0x11111111,0x12121212,0x13131313,0x14141414,0x15151515,0x16161616,0x17171717,0x18181818},
        (int*)0x0123456789ABCDEF,"1234567890123",0xFFFFFFFF11111111},
    {{0x20202020,0x21212121,0x22222222,0x23232323,0x24242424,0x25252525,0x26262626,0x27272727,0x28282828},
        (int*)0xFEDCBA9876543210,"ABCDEFGHIJKLM",0x22222222FFFFFFFF},
    {{0x30303030,0x31313131,0x32323232,0x33333333,0x34343434,0x35353535,0x36363636,0x37373737,0x38383838},
        (int*)0xFFFFFFFFFFFFFFFF,"abcdefghijklm",0x3333333333333333},
};

/*
  ステップ１  整数型変数とポインタ　＋ 関数呼び出し
*/
static UINT  Func1(UINT uiVal1,PUINT puiVal2) {
    // 関数コール時のメモリ配置（スタック）を確認

    // パラメータのアドレス値を確認
    PRINTVALUES(&uiVal1,&puiVal2,"%p","%p");
    // パラメータの値を確認
    PRINTVALUES(uiVal1,puiVal2,"%u","%p");
    // ポインタアドレスにパラメータ値を代入
    *puiVal2 = uiVal1;
    // パラメータ値＋１でリターン
    return (uiVal1+1);
}
/*
  主制御処理
*/
int main(int argc,char **argv)
{
    // デバッガでコマンドラインパラメータの設定状況を確認

    // 符号なし４バイト変数を定義
    UINT  uiVal1=0,uiVal2=0;
    // 構造体ポインタを定義して配列番号１のアドレスを設定
    PSTRUC pst = &st1[1];
 
    // 整数変数の初期値を確認
    PRINTVALUES(uiVal1,uiVal2,"%u","%u");
    // 整数変数のアドレス値を確認
    PRINTVALUES(&uiVal1,&uiVal2,"%p","%p");
 
    // 確認用関数をコール
    uiVal1 = Func1(5,&uiVal2);
    
    // 関数コール後の状態を確認
    // 整数変数の値を確認
    PRINTVALUES(uiVal1,uiVal2,"%u","%u");

    // 構造体配列のサイズと構造体ポインタのサイズを確認
    PRINTVALUES(sizeof(st1),sizeof(pst),"%lu","%lu");
    // 構造体の先頭アドレス値と、ポインタに格納されているアドレス値を確認
    PRINTVALUES(st1,pst,"%p","%p");
    // デバッガで構造体のパディングを確認
    // 構造体の先頭アドレス値と、ポインタに格納されているアドレス値の差と
    // 構造体のサイズを確認
    PRINTVALUES((ULONG)pst-(ULONG)st1,sizeof(STRUC),"%lu","%lu");
    // ポインタ変数による構造体の代入を確認
    st1[0] = *pst;
    // ポインタ変数値のインクリメント実行
    pst++;
    // セットされたポインタ変数の値と、iVal1[0] の値を確認
    PRINTVALUES(pst,pst->iVal1[0],"%p","%d");
    // ポインタと配列の関係を確認
    pst->piVal2 = &pst->iVal1[5];
    pst[0].piVal2[-5] = 0x78563412;
    // セットされたポインタ変数の値と、－５相対値の値を確認
    PRINTVALUES(pst->piVal2,pst->iVal1[0],"%p","%X");

    return 0;
}
