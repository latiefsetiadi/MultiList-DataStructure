#ifndef PUSTAKA_H_INCLUDED
#define PUSTAKA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct tElmnKol *addressKol;
typedef struct tElmnKol{
    char nama_pemain[100];
    addressKol NextKol;
    addressKol prevKOl;
}ElmnKol;

typedef struct tElmnbar *addressBar;
typedef struct tElmnbar
{
    char jenis_pemain[50];
    addressKol Kol;
    addressKol lastKol;
    addressBar prevBar;
    addressBar NextBar;
}ElmnBar;

typedef struct
{
    addressBar first;
    addressBar last;
}List;

#define FIRST(L) (L).first
#define INFOBaris(P) (P)->jenis_pemain
#define NextBar(P) (P)->NextBar
#define FIRSTKOL(P) (P)->Kol

#define InfoKol(P) (P)->Kol->nama_pemain
#define NextKol(P) (P)->Kol->NextKol
#endif // PUSTAKA_H_INCLUDED
