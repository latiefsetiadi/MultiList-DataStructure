#include "pustaka.h"

void CreateEmpty(List *L)
{
    L->first=NULL;
    L->last=NULL;
}

///Fungsi untuk alokasi
addressBar AlokasiBaris(char x[100])
{
    addressBar p;
    p=(addressBar)malloc(sizeof(ElmnBar));
    if(p!=NULL)
    {
        strcpy(p->jenis_pemain,x);
        p->NextBar=NULL;
        p->prevBar=NULL;
        p->Kol=NULL;
    }
    return p;
}

addressKol AlokasiKolom(char x[100])
{
    addressKol p;
    p=(addressKol)malloc(sizeof(ElmnKol));
    if(p!=NULL)
    {
        strcpy(p->nama_pemain,x);
        p->NextKol=NULL;
        p->prevKOl=NULL;
    }
    return p;
}

///Fungsi untuk mencari alamat
addressBar SearchBar(List L,char x[100])
{
    addressBar p=L.first;
    int ketemu=0;
    while((p!=NULL)&&(ketemu==0))
    {
        if(strcmp(x,p->jenis_pemain)==0)
        {
            ketemu=1;
        }
        else{
            p=p->NextBar;
        }
    }
    return p;
}

addressKol seacrhKol(addressBar br,char x[100])
{
    addressKol kolom=br->Kol;
    int ketemu=0;
    while((kolom!=NULL)&&(ketemu==0))
    {
        if(strcmp(x,kolom->nama_pemain)==0)
        {
            ketemu=1;
        }
        else{
           kolom=kolom->NextKol;
        }
    }
    return kolom;
}

///Fungsi untuk menambah nilai
void addFirstBar(List *L,char x[100])
{
    addressBar p;
    p=AlokasiBaris(x);
    if(p!=NULL)
    {
        if(L->first==NULL)
        {
            L->first=p;
            L->last=p;
        }
        else{
        p->NextBar=L->first;
        L->first->prevBar=p;
        L->first=p;
        }
    }
}

void addFirstKol(addressBar p,char x[100])
{
    addressKol kolom;
    kolom=AlokasiKolom(x);
    if(p->Kol==NULL)
    {
        p->Kol=kolom;
        p->lastKol=kolom;
    }
    else{
        kolom->NextKol=p->Kol;
        p->Kol=kolom;
        kolom->NextKol->prevKOl=kolom;
        kolom->prevKOl=p;
    }
}

void addLastBar(List *L,char x[100])
{
    addressBar p;
    p=AlokasiBaris(x);

    if(L->first==NULL)
    {
        addFirstBar(L,x);
    }
    else
    {
        L->last->NextBar=p;
        p->prevBar=L->last;
        L->last=p;
    }
}

void addLastKol(addressBar p,char x[100])
{
    addressKol kolom;
    kolom=AlokasiKolom(x);
    if(p->Kol==NULL)
    {
        addFirstKol(p,x);
    }
    else{
        p->lastKol->NextKol=kolom;
        kolom->prevKOl=p->lastKol;
        p->lastKol=kolom;
    }
}

void addAfterBar(List *L,addressBar aft,char x[100])
{
    addressBar p;
    p=AlokasiBaris(x);
    if(aft==L->last)
    {
        addLastBar(L,x);
    }
    else{
    aft->NextBar->prevBar=p;
    p->NextBar=aft->NextBar;
    p->prevBar=aft;
    aft->NextBar=p;
    }

}

void addAfterKol(addressBar bar,addressKol aftkol,char x[100])
{
    addressKol p;
    p=AlokasiKolom(x);
    if(aftkol==bar->lastKol)
    {
        addLastKol(bar,x);
    }
    else{
    aftkol->NextKol->prevKOl=p;
    p->NextKol=aftkol->NextKol;
    p->prevKOl=aftkol;
    aftkol->NextKol=p;
    }
}


///Fungsi menghapus nilai
void DelFirstBar(List *L,char *x)
{
    if((L->first!=NULL)&&(L->last!=NULL))
    {
    addressBar p=FIRST(*L);
    if(p->Kol!=NULL)
    {
        addressKol kolom=p->Kol;
        addressKol del;
        while(kolom!=NULL)
        {
        del=kolom;
        p->Kol=p->Kol->NextKol;
        kolom=kolom->NextKol;
        del->NextKol=NULL;
        del->prevKOl=NULL;
        free(del);
        }
    }
    if(L->first==L->last)
    {
        strcpy(x,L->first->jenis_pemain);
        CreateEmpty(L);
    }
    else{
    strcpy(x,p->jenis_pemain);
    FIRST(*L)=L->first->NextBar;
    p->NextBar=NULL;
    p->prevBar=NULL;
    free(p);
    }
}
else{
    printf("Baris Kosong\n");
}
}

void DelFirstKol(addressBar bar,char *x)
{
    if(bar->Kol!=NULL)
    {
    addressKol kolom=bar->Kol;
    if((bar->Kol==NULL)&&(bar->lastKol==NULL))
    {
        printf("kolom kosong\n");
    }
    else{
        if(bar->Kol==bar->lastKol)
        {
            strcpy(x,bar->Kol->nama_pemain);
            bar->Kol=NULL;
            bar->lastKol=NULL;
        }
        else{
        strcpy(x,bar->Kol->nama_pemain);
        kolom->NextKol->prevKOl=bar;
        bar->Kol=bar->Kol->NextKol;
        kolom->NextKol=NULL;
        kolom->prevKOl=NULL;
        free(kolom);
        }
    }
    }
    else{
        printf("kolom kosong\n");
    }
}

void DelLastBar(List *L,char *x)
{
    if((L->first!=NULL)&&(L->last!=NULL))
    {
    addressBar p=L->last;
    if(L->last->Kol!=NULL)
    {
        addressKol kolom=L->last->Kol;
        addressKol del;
        while(kolom!=NULL)
        {
            del=kolom;
            L->last->Kol=L->last->Kol->NextKol;
            kolom=kolom->NextKol;
            del->NextKol=NULL;
            del->prevKOl=NULL;
            free(del);
        }
    }
    if(L->first==L->last)
    {
        strcpy(x,L->last->jenis_pemain);
        CreateEmpty(L);
    }
    else{
    strcpy(x,L->last->jenis_pemain);
    p->NextBar=NULL;
    L->last=L->last->prevBar;
    L->last->NextBar=NULL;
    p->prevBar=NULL;
    free(p);
    }
    }

    else{
        printf("Baris kosong\n");
    }
}

void DelLastKol(addressBar p,char *x)
{
    addressKol kolom;
    if((p->Kol==NULL)&&(p->lastKol==NULL))
    {
        printf("Kolom kosong\n");
    }
    else{
        if(p->Kol==p->lastKol)
        {
            strcpy(x,p->Kol->nama_pemain);
            p->Kol=NULL;
            p->lastKol=NULL;
        }
        else{
        kolom=p->lastKol;
        strcpy(x,kolom->nama_pemain);
        p->lastKol=p->lastKol->prevKOl;
        p->lastKol->NextKol=NULL;
        kolom->NextKol=NULL;
        kolom->prevKOl=NULL;
        free(kolom);
        }
    }

}

void DelPositionBar(List *L,char cari[100],char *x)
{
    addressBar p=SearchBar(*L,cari);
    if(p==L->first)
    {
        DelFirstBar(L,x);
    }
    else if(p==L->last)
    {
        DelLastBar(L,x);
    }
    else{
    strcpy(x,p->jenis_pemain);
    p->prevBar->NextBar=p->NextBar;
    p->NextBar->prevBar=p->prevBar;
    free(p);
    }
}

void DelPositionKol(addressBar p,char cari[100],char *x)
{
    addressKol srch=seacrhKol(p,cari);
    if(p->Kol==NULL)
    {
        printf("Kolom kosong\n");
    }
    else{
        if(srch==p->Kol)
        {
            DelFirstKol(p,x);
        }
        else if(srch==p->lastKol)
        {
            DelLastKol(p,x);
        }
        else{
        strcpy(x,srch->nama_pemain);
        srch->prevKOl->NextKol=srch->NextKol;
        srch->NextKol->prevKOl=srch->prevKOl;
        free(srch);
        }
    }
}

int nbElmtKol(List L)
{
    addressBar bar=L.first;
    addressKol kolom;
    int sum=0;
    while(bar!=NULL)
    {
        kolom=bar->Kol;
        while(kolom!=NULL)
        {
            sum++;
            kolom=kolom->NextKol;
        }
        bar=bar->NextBar;
    }
    return sum;
}

void printKol(addressBar p)
{
    addressKol kolom=p->Kol;
    if(p->Kol==NULL)
    {
        printf("Kolom kosong\n");
    }
    else{
        while(kolom!=NULL)
        {
            printf("%s, ",kolom->nama_pemain);
            kolom=kolom->NextKol;
        }
    }
}

void print_baris(List L)
{
    addressBar p;
    p=L.first;
    while(p!=NULL)
    {
        printf("%s\n",p->jenis_pemain);
        p=p->NextBar;
    }
}
int cek(List L,char x[100])
{
    addressBar p=L.first;
    int ulang=0;
    addressKol kolom;
    int ketemu=0;
    while((p!=NULL)&&(ketemu==0))
    {
        kolom=p->Kol;//first dari kolom
        while(kolom!=NULL)
        {
            if(strcmpi(x,kolom->nama_pemain)==0)
            {
                ketemu=1;
            }
            kolom=kolom->NextKol;
        }
        p=p->NextBar;
    }

    if(ketemu==1)
    {
        printf("Tidak boleh ada nama yang sama");
        return ketemu;
    }
}
void DelFirstbar(List *L)
{
    if((L->first!=NULL)&&(L->last!=NULL))
    {
    addressBar p=FIRST(*L);
    if(p->Kol!=NULL)
    {
        addressKol kolom=p->Kol;
        addressKol del;
        while(kolom!=NULL)
        {
        del=kolom;
        p->Kol=p->Kol->NextKol;
        kolom=kolom->NextKol;
        del->NextKol=NULL;
        del->prevKOl=NULL;
        free(del);
        }
    }
    if(L->first==L->last)
    {
        //strcpy(x,L->first->jenis_pemain);
        CreateEmpty(L);
    }
    else{
    //strcpy(x,p->jenis_pemain);
    FIRST(*L)=L->first->NextBar;
    p->NextBar=NULL;
    p->prevBar=NULL;
    free(p);
    }
}
}
void DelAll(List *L)
{
    addressBar p=L->first;
    while(p!=NULL)
    {
        DelFirstbar(L);
        p=p->NextBar;
    }
    CreateEmpty(L);
    if((L->first==NULL)&&(L->last==NULL))
    {
        printf("Sukses dihapus");
    }
}
void Print_All(List L)
{
    addressBar p;
    addressKol k;
    p=L.first;
    while(p!=NULL)
    {
        printf("%s : ",p->jenis_pemain);
        k=p->Kol;
        while(k!=NULL)
        {
            printf("%s, ",k->nama_pemain);
            k=k->NextKol;
        }
        printf("\n");
        p=p->NextBar;
    }
}

void Print_AllKolom(List L)
{
    addressBar p;
    addressKol k;
    p=L.first;
    while(p!=NULL)
    {
        //printf("%s : ",p->jenis_pemain);
        k=p->Kol;
        while(k!=NULL)
        {
            printf("%s, ",k->nama_pemain);
            k=k->NextKol;
        }
        printf("\n");
        p=p->NextBar;
    }
}

addressBar cekbar(List L,char x[100])
{
    addressBar p=L.first;
    int ulang=0;
    addressKol kolom;
    int ketemu=0;
    while((p!=NULL)&&(ketemu==0))
    {
        kolom=p->Kol;
        while(kolom!=NULL)
        {
            if(strcmpi(x,kolom->nama_pemain)==0)
            {
                ketemu=1;
            }
            kolom=kolom->NextKol;
        }

        p=p->NextBar;
    }
    return p->prevBar;

}
void DelPositionKolinput(List *L,char cari[100],char *x)
{
    addressBar p=cekbar(*L,cari);
    addressKol srch=seacrhKol(p,cari);
    if(p->Kol==NULL)
    {
        printf("Kolom kosong\n");
    }
    else{
        if(srch==p->Kol)
        {
            DelFirstKol(p,x);
        }
        else if(srch==p->lastKol)
        {
            DelLastKol(p,x);
        }
        else{
        strcpy(x,srch->nama_pemain);
        srch->prevKOl->NextKol=srch->NextKol;
        srch->NextKol->prevKOl=srch->prevKOl;
        free(srch);
        }
    }
}


