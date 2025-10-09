/*
*/

#ifndef __TRANING_H__
#define __TRANING_H__
#define PRINTVALUES(__val1__,__val2__,__fmt1__,__fmt2__) (printf("(%03d):VAL1="__fmt1__",VAL2="__fmt2__"\n",__LINE__,__val1__,__val2__))
typedef unsigned char       BYTE,*PBYTE;
typedef unsigned int        UINT,*PUINT;
typedef unsigned long int   ULONG,*PULONG;
typedef struct {
    int     iVal1[9];       // 整数型配列
                            // ４バイト
    int     *piVal2;        // 整数型
    BYTE    bVal1[13];      // 文字型配列（文字列）
                            // ３バイト
    ULONG   ulVal1;         // 符号なし文字型配列
}STRUC,*PSTRUC;
#endif
