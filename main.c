#include "pustaka.h"
int main()
{
    ///NAMA : Latief Setiadi
    ///NIM  : A11.2018.11376
    List L;
    char x[100];
    char y[100];
    int pilih,plh;
    char input[100];
    addressKol kol;
    int keluar=0;
    int klr=0;
    int ulang;
    addressBar p;
    char cari[100];
    char cari2[100];
    CreateEmpty(&L);
    while(keluar==0)
    {
        printf("1.Input Baris\n");
        printf("2.Input Kolom\n");
        printf("3.Delete Baris\n");
        printf("4.Delete Kolom\n");
        printf("5.Cetak kolom\n");
        printf("6.Delete All\n");
        printf(" : "); scanf("%d",&pilih);
        switch(pilih){
            case 1: while(klr==0) ///Input baris
                    {
                    system("cls");
                    printf("1.Input Depan Baris\n");
                    printf("2.Input Belakang Baris\n");
                    printf("3.Input Position Baris\n");
                    printf("4.Cetak Baris\n");
                    printf("5.Kembali ke menu awal\n");
                    printf(" : "); scanf("%d",&plh);
                    if(plh==1)
                    {
                        printf("Silahkan input : "); fflush(stdin); gets(input);
                        addFirstBar(&L,input);
                    }
                    else if(plh==2)
                    {
                        printf("Silahkan input : "); fflush(stdin); gets(input);
                        addLastBar(&L,input);
                    }
                    else if(plh==3){
                        up:
                        print_baris(L);
                        printf("pilih baris untuk disisipkan : "); fflush(stdin); gets(cari);
                        p=SearchBar(L,cari);
                        if(p==NULL)
                        {
                            printf("Tidak diketahui, Silahkan ulangi\n");
                            fflush(stdin);
                            goto up;
                        }
                        else{
                            if((L.first==NULL)&&(L.last==NULL))
                            {
                                printf("Silahkan input : "); gets(input);
                                addFirstBar(&L,input);
                            }
                            else{
                                printf("Silahkan input : "); gets(input);
                                addAfterBar(&L,p,input);
                            }
                        }
                    }
                    else if(plh==4)
                    {
                        print_baris(L);
                        system("pause");
                    }
                    else if(plh==5)
                    {
                        klr=1;
                    }
                    else{
                        printf("Input tidak diketahui,silahkan ulangi\n");
                        fflush(stdin);
                        system("pause");
                    }
                    }
                   system("cls");
                    klr=0;
                    break;

           case 2: while(klr==0) ///Input Kolom
                    {
                    system("cls");
                    printf("1.Input Depan Kolom\n");
                    printf("2.Input Belakang Kolom\n");
                    printf("3.Input Position kolom\n");
                    printf("4.Input (tidak boleh ada yang sama)\n");
                    printf("5.Cetak \n");
                    printf("6.Kembali ke menu awal\n");
                    printf(" : "); scanf("%d",&plh);
                    if(plh==1)
                    {
                        up2:
                        print_baris(L);
                        printf("Silahkan pilih baris yang mau di input :"); fflush(stdin); gets(cari);
                        p=SearchBar(L,cari);
                        if(p==NULL)
                        {
                            printf("Tidak diketahui,silahkan ulangi\n");
                            fflush(stdin);
                            goto up2;
                        }
                        printf("Silahkan input : "); fflush(stdin); gets(input);
                        addFirstKol(p,input);
                    }
                    else if(plh==2)
                    {
                        up3:
                        print_baris(L);
                        printf("pilih baris untuk diisi kolom :"); fflush(stdin); gets(cari);
                        p=SearchBar(L,cari);
                        if(p==NULL)
                        {
                            printf("Tidak diketahui,silahkan ulangi\n");
                            fflush(stdin);
                            goto up3;
                        }
                        printf("Silahkan input : "); fflush(stdin); gets(input);
                        addLastKol(p,input);
                    }
                    else if(plh==3){
                        up4:
                        puts("");
                        print_baris(L);
                        printf("\npilih baris untuk diisi kolom : "); fflush(stdin); gets(cari2);
                        p=SearchBar(L,cari2);
                        if(p==NULL)
                        {
                            printf("Tidak diketahui,silahkan ulangi\n");
                            fflush(stdin);
                            goto up4;
                        }
                        printf("%s : ",p->jenis_pemain);
                        printKol(p);
                        if(p->Kol==NULL)
                        {
                            printf("silahkan input : "); fflush(stdin); gets(input);
                            addFirstKol(p,input);
                        }
                        else{
                        printf("\npilih kolom yang mau disisipkan : "); fflush(stdin);gets(cari);
                        kol=seacrhKol(p,cari);
                        printf("Silahkan input : ");fflush(stdin); gets(input);
                        addAfterKol(p,kol,input);
                        }
                    }
                    else if(plh==4)
                    {

                        printf("Masukan pemain :"); fflush(stdin); gets(input);
                        ulang=cek(L,input);
                        if(ulang!=1)
                        {
                            addFirstKol(L.first,input);
                            printf("Berhasil ditambahkan\n");
                        }
                        Print_All(L);
                        system("pause");

                    }
                    else if(plh==5)
                    {
                        Print_All(L);
                        system("pause");
                    }
                    else if(plh==6)
                    {
                        klr=1;
                    }
                    else{
                        printf("Input tidak diketahui,silahkan ulangi\n");
                        fflush(stdin);
                        system("pause");
                    }
                    }
                    system("cls");
                    klr=0;
                    break;

           case 3:  while(klr==0) ///Delete Baris
                    {
                    system("cls");
                    printf("1.Delete Depan Baris\n");
                    printf("2.Delete Belakang Baris\n");
                    printf("3.Delete Position Baris\n");
                    printf("4.Cetak \n");
                    printf("5.Kembali ke menu awal\n");
                    printf(" : "); scanf("%d",&plh);
                    if(plh==1)
                    {
                        //fflush(stdin);
                        DelFirstBar(&L,&x);
                        printf("Yang dihapus adalah : %s \n",x);
                        fflush(stdin);
                        system("pause");
                    }
                    else if(plh==2)
                    {
                        DelLastBar(&L,&x);
                        printf("Yang dihapus adalah : %s \n",x);
                        fflush(stdin);
                        system("pause");
                    }
                    else if(plh==3)
                    {
                        print_baris(L);
                        printf("pilih baris yang mau dihapus :"); fflush(stdin); gets(cari);
                        DelPositionBar(&L,cari,&x);
                        printf("Yang dihapus adalah : %s\n",x);
                        fflush(stdin);
                        system("pause");
                    }

                    else if(plh==4)
                    {
                        print_baris(L);
                        system("pause");
                    }
                    else if(plh==5)
                    {
                        klr=1;
                    }
                    else{
                        printf("Input tidak diketahui,silahkan ulangi\n");
                        fflush(stdin);
                        system("pause");
                    }
                    }
                   system("cls");
                    klr=0;
                    break;
            case 4:  while(klr==0) ///Delete kolom
                    {
                   system("cls");
                    printf("1.Delete Depan Kolom\n");
                    printf("2.Delete Belakang Kolom\n");
                    printf("3.Delete Position Kolom\n");
                    printf("4.Delete berdasarkan input\n");
                    printf("5.Cetak \n");
                    printf("6.Kembali ke menu awal\n");
                    printf(" : "); scanf("%d",&plh);
                    if(plh==1)
                    {
                        print_baris(L);
                        printf("pilih baris : "); fflush(stdin); gets(cari);
                        p=SearchBar(L,cari);
                        DelFirstKol(p,&x);
                        printf("Yang dihapus adalah : %s \n",x);
                        system("pause");
                    }
                    else if(plh==2)
                    {
                        print_baris(L);
                        printf("pilih baris : "); fflush(stdin); gets(cari);
                        p=SearchBar(L,cari);
                        DelLastKol(p,&x);
                        printf("Yang dihapus adalah : %s \n",x);
                        system("pause");
                    }
                    else if(plh==3)
                    {
                        print_baris(L);
                        printf("pilih baris : "); fflush(stdin); gets(cari);
                        p=SearchBar(L,cari);
                        printKol(p);
                        printf("Pilih kolom yang dihapus : "); fflush(stdin); gets(input);
                        DelPositionKol(p,input,&x);
                        printf("Yang dihapus adalah : %s \n",x);
                        system("pause");
                    }
                    else if(plh==4)
                    {
                        Print_All(L);
                        printf("Pilih pemain yang mau dihapus : "); fflush(stdin); gets(input);
                        DelPositionKolinput(&L,input,&x);
                        printf("%s berhasil dihapus\n",x);
                    }
                    else if(plh==5)
                    {
                        Print_All(L);
                        system("pause");
                    }
                    else if(plh==6)
                    {
                        klr=1;
                    }
                    else{
                        printf("Input tidak diketahui,silahkan ulangi\n");
                        fflush(stdin);
                        system("pause");
                    }
                    }
                    system("cls");
                    klr=0;
                    break;

            case 5: Print_All(L);
                    puts("");
                    printf("Masukan baris yang mau diprint kolom :"); fflush(stdin); gets(input);
                    p=SearchBar(L,input);
                    printf("%s : ",p->jenis_pemain);
                    printKol(p);
                    puts("");
                    system("pause");
                    system("cls");
                    break;

            case 6: DelAll(&L);
                    system("pause");
                    system("cls");
        }

    }
//    addFirstBar(&L,"CB");
//    addFirstBar(&L,"BK");
//    addFirstBar(&L,"Striker");
//   addFirstKol(FIRST(L),"Ahmad");
//   addFirstKol(FIRST(L),"Wahyu");
//   addFirstKol(FIRST(L),"Bayu");
//   addLastKol(FIRST(L),"Latif");
//   DelFirstBar(&L,&x);
//    printKol(FIRST(L));
    //printf("pilih : "); fflush(stdin);gets(cari);
//    p=SearchBar(L.first,"BK");
//   kol=seacrhKol(p,"Bayu");
//   addAfterKol(kol,"latif");
//    int x=strcmp("wahyu","wahyu");
//    printf("%d\n",x);
//    print(L);
//     printKol(NextBar(FIRST(L)));

    //SearchBar(L,"BK");
    return 0;
}
