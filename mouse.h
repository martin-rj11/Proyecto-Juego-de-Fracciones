class boton
{

public:
int xi,yi,yf,xf,b;
int xm,ym;
int tx,ty;
void *parche;
char *imagen;

void posicion(int a, int b, int c, int d)
{xi=a; yi=b; xf=c; yf=d; b=1; xm=0;ym=0; tx=0; ty=0;
parche=malloc(imagesize(xi,yi,xf+tx,yf+ty));
//rectangle(xi,yi,xf,yf);
}

int prueba(void)
{
    if(mousex()>xi&&mousex()<xf&&mousey()>yi&&mousey()<yf&&ismouseclick(WM_LBUTTONDOWN))
      {clearmouseclick(WM_LBUTTONDOWN);return 1; }
    else if(!mousex()>xi||!mousex()<xf) {return 0;}
}

int prueba(char p[50])
{
    if(mousex()>xi&&mousex()<xf&&mousey()>yi&&mousey()<yf&&ismouseclick(WM_LBUTTONDOWN))
    {clearmouseclick(WM_LBUTTONDOWN); readimagefile(p,xi,yi,xf,yf);return 1; }
    else if(!mousex()>xi||!mousex()<xf){ return 0;}
}

void estado(char nom[50], char nom2[50])
{    imagen=nom;
     if(mousex()>xi&&mousex()<xf&&mousey()>yi&&mousey()<yf)
           {readimagefile(nom2,xi,yi,xf,yf);}
     else  {readimagefile(nom,xi,yi,xf,yf);}
}

void estado(char *nom, char *nom2,int xi1, int yi1, int xf1, int yf1)
{
     if(mousex()>xi&&mousex()<xf&&mousey()>yi&&mousey()<yf)
          {readimagefile(nom2,xi1,yi1,xf1,yf1);}
     else {readimagefile(nom,xi,yi,xf,yf);}

}


int arrastrar(void)
{   int d;
    if(b){b=0; getimage(xi+xm,yi+ym, (xf+xm)+tx,(yf+ym)+ty, parche);}
    readimagefile(imagen, xi+xm,yi+ym, (xf+xm)+tx,(yf+ym)+ty);
    if(ismouseclick(WM_LBUTTONDOWN))
          {Sleep(2);putimage(xm+xi,ym+yi,parche,0); xm=mousex(); ym=mousey();xm-=xi;ym-=yi;  b=1;d=1;}
    if(ismouseclick(WM_LBUTTONUP))
          {b=1;clearmouseclick(WM_LBUTTONDOWN);clearmouseclick(WM_LBUTTONUP);d=0;}
return d;
}


};
