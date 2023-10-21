#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "mouse.h"
#include <windows.h>

using namespace std;

char botones_A[20][80]={"botones\\continuar.jpg",
                      "botones\\continuar_r.jpg",
                      "botones\\nino.jpg",
                      "botones\\nino_r.jpg",
                      "botones\\nina.jpg",
                      "botones\\nina_r.jpg",
                      "botones\\spikeb.jpg",
                      "botones\\spikeb_r.jpg",
                      "botones\\robinb.jpg",
                      "botones\\robinb_r.jpg",
                      "botones\\edb.jpg",
                      "botones\\edb_r.jpg",
                      "botones\\dorisb.jpg",
                      "botones\\dorisb_r.jpg",
                      "botones\\memphisb.jpg",
                      "botones\\memphisb_r.jpg",
                      "botones\\aquab.jpg",
                      "botones\\aquab_r.jpg"};

char botones_M[20][80]={"botones_m\\jugar.jpg",
                        "botones_m\\jugar_r.jpg",
                        "botones_m\\tips.jpg",
                        "botones_m\\tips_r.jpg",
                        "botones_m\\acerca.jpg",
                        "botones_m\\acerca_r.jpg",
                        "botones_m\\salir.jpg",
                        "botones_m\\salir_r.jpg",
                        "botones_m\\mast.jpg",
                        "botones_m\\mast_r.jpg",
                        "botones_m\\flecha.jpg",
                        "botones_m\\flecha_r.jpg",
                        "botones_m\\regresar.jpg",
                        "botones_m\\regresar_r.jpg",
                        "botones_m\\x.jpg",
                        "botones_m\\x_r.jpg"};

char botones_J[10][50]={"botones_j\\num1.jpg",
                        "botones_j\\num1_r.jpg",
                        "botones_j\\num2.jpg",
                        "botones_j\\num2_r.jpg",
                        "botones_j\\mom.jpg",
                        "botones_j\\mom_r.jpg",
                        "botones_j\\opf.jpg",
                        "botones_j\\opf_r.jpg"};

char corazon[4][50]={"corazon\\corazon3.jpg",
                     "corazon\\corazon2.jpg",
                     "corazon\\corazon1.jpg"};

char menu[10][80]={"menu_p\\menu.jpg",
                   "menu_p\\nivel.jpg",
                   "menu_p\\tips.jpg",
                   "menu_p\\tips2.jpg",
                   "menu_p\\tips3.jpg",
                   "menu_p\\acerca-de.jpg",
                   "menu_p\\est.jpg",
                   "menu_p\\rect.jpg"};

char juego_m [20][80]={"juego_a\\juego_1.jpg",
                       "juego_a\\N1.jpg",
                       "juego_a\\N2.jpg",
                       "juego_a\\N3.jpg",
                       "juego_a\\N4.jpg",
                       "juego_a\\N5.jpg",
                       "juego_a\\N6.jpg",
                       "juego_a\\N7.jpg",
                       "juego_a\\N8.jpg",
                       "juego_a\\N9.jpg",
                       "juego_a\\juego_2.jpg",
                       "juego_a\\numerador.jpg",
                       "juego_a\\denominador.jpg",
                       "juego_a\\mas.jpg",
                       "juego_a\\menos.jpg",
                       "juego_a\\juego_2r.jpg"};

char numeros_j[15][80]={"numeros\\num0.jpg",
                        "numeros\\num1.jpg",
                        "numeros\\num2.jpg",
                        "numeros\\num3.jpg",
                        "numeros\\num4.jpg",
                        "numeros\\num5.jpg",
                        "numeros\\num6.jpg",
                        "numeros\\num7.jpg",
                        "numeros\\num8.jpg",
                        "numeros\\num9.jpg",
                        "numeros\\num10.jpg"};

char numeros_j2[8][80]={"numeros_v\\vida_n0.jpg",
                        "numeros_v\\vida_n1.jpg",
                        "numeros_v\\vida_n2.jpg",
                        "numeros_v\\vida_n3.jpg",
                        "numeros_v\\vida_n4.jpg",
                        "numeros_v\\vida_n5.jpg",
                        "numeros_v\\vida_n6.jpg",};

char avatar[15][100]={"imagenes\\FONDO_P.jpg",
                      "imagenes\\pezM1.jpg",
                      "imagenes\\pezM2.jpg",
                      "imagenes\\pezM3.jpg",
                      "imagenes\\pezF1.jpg",
                      "imagenes\\pezF2.jpg",
                      "imagenes\\pezF3.jpg",
                      "imagenes\\FONDO2.jpg",
                      "imagenes\\juego.jpg",
                      "imagenes\\fondo_juego.jpg"};

char avatar2[15][80]={"imagenes2\\bienvenido.jpg",
                      "imagenes2\\bienvenida.jpg",
                      "imagenes2\\spike.jpg",
                      "imagenes2\\robin.jpg",
                      "imagenes2\\ed.jpg",
                      "imagenes2\\doris.jpg",
                      "imagenes2\\memphis.jpg",
                      "imagenes2\\aqua.jpg",
                      "imagenes2\\pantalla_i.jpg"};

char audio[20][100]={"sonido\\avatar.wav",
                    "sonido\\select2.wav",
                    "sonido\\menu.wav",
                    "sonido\\nivel.wav",
                    "sonido\\tips.wav",
                    "sonido\\acerca.wav",
                    "sonido\\select.wav",
                    "sonido\\puntosmas.wav",
                    "sonido\\vidaextra.wav",
                    "sonido\\vidamenos.wav",
                    "sonido\\perder.wav",
                    "sonido\\juego.wav",
                    "sonido\\inicio.wav",
                    "sonido\\ganar.wav",
                    "sonido\\salir.wav",
                    "sonido\\juego2.wav"};

class usuario
{
    int alias;
    char genero;
    void elegir_avatar(void);
    void elegir_alias(void);
public:
    char *imagen;
    int total,pez,puntaje,vida;
    usuario(void){vida=3;puntaje=0;total=0;}
    void reproducir(char* audio, int c);
    void imprime_imagen(char *im, int xi, int yi, int xf, int yf);
    void elegir_perfil(void);
    void ver_perfil(void);
    friend void inicializar(usuario I);
};
void inicializar(usuario I)
    {
        initwindow(800,600,"Mar de Fracciones",280,50);
        setbkcolor(3);setcolor(15);settextstyle(4,0,4);
    }

class juego : public usuario
{
    int *numerador, *numerador2, *denom, *denom2, *mayor, *mayor2,*com;
    char *num, *num2;
    char nivel(void);
    char nivel2(void);
    char menu_p(void);
    void generar_frac(void);
    void comparar_fracc(void);
    void operaciones_fracc(void);
public:
    int t,n,r,num_j;
    juego(void){t=0; num_j=0;}
    void vacia (void) {for(int i=0;i<30;i++) {num[i]='\0';num2[i]='\0';}}
    void iniciar(void);
    int captura_f(int x, int y, int c, char *a);
    void imprime_f(int x, int y, char *a, int res);
    void guardar_puntaje(void);
    friend void ver_puntaje(juego B);
};

void ver_puntaje(juego B)
{
    char p[3], jg[3];
    boton S[2]; S[0].posicion(600,450,720,522);
    itoa(B.num_j,jg,10);B.imprime_imagen(menu[7],500,270,660,325);
    outtextxy(570,285,jg);
    itoa(B.t,p,10);B.imprime_imagen(menu[7],460,200,620,255);
    outtextxy(530,215,p);
    while(true)
    {
     S[0].estado(botones_M[10],botones_M[11]);
     if(S[0].prueba()){break;}
    }
}

int main()
{
usuario P;
juego O;
inicializar(P);
O.iniciar();
ver_puntaje(O);
}

void juego::generar_frac(void)
{
    n=0;r=1;
    numerador=new int [10];
    numerador2=new int [10];
    denom=new int[10];
    denom2=new int[10];
    for (int t=0;t<10;t++)
    {
        numerador[t]=1+rand()%9;
        numerador2[t]=1+rand()%9;
        denom[t]=1+rand()%9;
        denom2[t]=1+rand()%9;
    }
}
void juego::comparar_fracc(void)
{
    mayor=new int [10];
    mayor2=new int [10];
    com=new int [10];
    for(int t=0;t<10;t++)
    {
        //nivel 1
        if(t<5)
        {
        if(numerador[t]>=numerador2[t]){mayor[t]=numerador[t];}
        else{mayor[t]=numerador2[t];}
        }
        //nivel 2
        mayor[t]=denom2[t]*numerador[t];//Fracc 1
        mayor2[t]=denom[t]*numerador2[t];//Fracc 2
        if(mayor[t]>mayor2[t]){com[t]=mayor[t];} //Comparacion de totales
        else{com[t]=mayor2[t];}
    }
}
void juego::operaciones_fracc(void)
{
    mayor=new int [10];
    mayor2= new int [10];
    for(int t=0;t<10;t++)
    {
        if(t<5)
        {
        mayor[t]=(numerador[t]*denom2[t])+(numerador2[t]*denom[t]);
        mayor2[t]=denom[t]*denom2[t];
        }
        else{
        mayor[t]=(numerador[t]*denom2[t])-(numerador2[t]*denom[t]);
        mayor2[t]=denom[t]*denom2[t];}
    }
}
void juego::guardar_puntaje(void)
{
    t+=total;
}
int juego::captura_f(int x, int y, int c, char *a)
{
    int i=0;
    outtextxy(x,y,"      "); vacia();
    while(true)
    {
    for(i=0;(a[i]=getch())!=13; )
    {
        if (a[i]==8&&i>=0)
         {setcolor(c);
          outtextxy(strlen(a)+x,y,a);a[i]='\0';i--;a[i]='\0';
          setcolor(15);outtextxy(strlen(a)+x,y,a);}
    else {setcolor(15);outtextxy(strlen(a)+x,y,a);i++;}
    }
    a[i]='\0'; return(atoi(a));
    }
}

void juego::imprime_f(int x, int y, char *a, int res)
{
    itoa(res,a,10);
    setcolor(15);
    outtextxy(x,y,a);
}

char juego::menu_p(void)
{
    srand(time(NULL));
    boton M[5];
    boton N[12];
    char puntos[3];

    imprime_imagen(menu[0],0,0,800,600);reproducir(audio[12],1);
    imprime_imagen(avatar[pez],610,50,755,195);imprime_imagen(menu[7],602,205,760,260);
    itoa(t,puntos,10);outtextxy(615,217,puntos);

    M[0].posicion(50,480,209,543);
    M[1].posicion(219,480,378,543);
    M[2].posicion(388,480,608,543);
    M[3].posicion(618,480,767,543);
    while(true)
    {
        M[0].estado(botones_M[0],botones_M[1]);
        M[1].estado(botones_M[2],botones_M[3]);
        M[2].estado(botones_M[4],botones_M[5]);
        M[3].estado(botones_M[6],botones_M[7]);

        if(M[0].prueba())
            {
            reproducir(audio[6],2);
            reproducir(audio[3],1);
            imprime_imagen(menu[1],0,0,800,600);
            N[0].posicion(150,200,322,372);
            N[1].posicion(392,200,679,346);
            N[10].posicion(357,500,412,555);
                while (true)
                {
                N[0].estado(botones_J[4],botones_J[5]);
                N[1].estado(botones_J[6],botones_J[7]);
                N[10].estado(botones_M[14],botones_M[15]);
                if(N[0].prueba())
                    {
                    reproducir(audio[1],2); reproducir(audio[2],1);
                    imprime_imagen(avatar[8],0,0,800,600);
                    while(true)
                    {
                    N[6].posicion(600,493,720,565);
                    N[10].posicion(60,510,115,565);
                    N[6].estado(botones_M[10],botones_M[11]);
                    N[10].estado(botones_M[14],botones_M[15]);
                    if(N[6].prueba())
                        {
                        reproducir(audio[1],2);reproducir(audio[2],1);
                        imprime_imagen(juego_m[0],0,0,800,600);
                        generar_frac();comparar_fracc();nivel();while(nivel()!=27);
                        delete []numerador;
                        delete []numerador2;
                        delete []denom;
                        delete []denom2;
                        delete []mayor;
                        delete []mayor2;
                        delete []com;
                        guardar_puntaje();break;
                        }
                    if(N[10].prueba()){reproducir(audio[6],2);break;}
                        } break;
                    }
                if(N[1].prueba())
                    {
                    reproducir(audio[1],2);reproducir(audio[15],1);
                    imprime_imagen(juego_m[15],0,0,800,600);
                    while(true)
                        {
                    N[8].posicion(600,493,720,565);
                    N[9].posicion(60,510,115,565);
                    N[8].estado(botones_M[10],botones_M[11]);
                    N[9].estado(botones_M[14],botones_M[15]);
                    if(N[8].prueba())
                        {
                        reproducir(audio[1],2);reproducir(audio[15],1);
                        imprime_imagen(juego_m[10],0,0,800,600);
                        num=new char [30];
                        num2=new char [30];
                        generar_frac();operaciones_fracc();nivel2();while(nivel2()!=27);
                        delete []numerador;
                        delete []numerador2;
                        delete []denom;
                        delete []denom2;
                        delete []mayor;
                        delete []mayor2;
                        delete []com; delete []num; delete []num2;
                        guardar_puntaje();break;
                        }
                     if(N[9].prueba()){reproducir(audio[6],2);break;}
                        } break;
                    }
                    if(N[10].prueba()){reproducir(audio[6],2);break;}
                } break;
            }

        if(M[1].prueba())
            {
              int op=2;
              reproducir(audio[6],2);reproducir(audio[4],1);
              imprime_imagen(menu[op],0,0,800,600);
              N[2].posicion(600,450,785,510);
              N[7].posicion(600,520,785,580);
              N[3].posicion(730,10,785,65);
              while(true)
              {
                if(N[2].prueba()){op++; if(op>4){op=2;} imprime_imagen(menu[op],0,0,800,600);}
                if(N[7].prueba()){op--; if(op<2){op=2;} imprime_imagen(menu[op],0,0,800,600);}
                if(N[3].prueba()){reproducir(audio[6],2);break;}

                N[2].estado(botones_M[8],botones_M[9]);
                N[7].estado(botones_M[12],botones_M[13]);
                N[3].estado(botones_M[14],botones_M[15]);
              } break;
            }

        if(M[2].prueba())
            {
              reproducir(audio[6],2);reproducir(audio[5],1);
              imprime_imagen(menu[5],0,0,800,600);
              N[5].posicion(100,480,259,543);
              while(true)
              {
                    N[5].estado(botones_M[6],botones_M[7]);
                    if(N[5].prueba()){reproducir(audio[6],2);break;}
              } break;
            }

        if(M[3].prueba())
            {reproducir(audio[6],2);reproducir(audio[14],1);imprime_imagen(menu[6],0,0,800,600);return(0);}
    }
}

char juego::nivel(void)
    {
        int s;
        boton J[3];
        J[0].posicion(185,500,245,560);
        J[1].posicion(545,500,605,560);
        reproducir(audio[2],1);

        imprime_imagen(numeros_j[puntaje],180,25,210,55);
        imprime_imagen(numeros_j2[vida],660,45,690,75);
        imprime_imagen(numeros_j[r],135,155,165,185);
        imprime_imagen(corazon[vida-1],720,30,780,90);
        //Imprimir fracciones
        imprime_imagen(juego_m[numerador[n]],175,270,255,350);
        imprime_imagen(juego_m[numerador2[n]],535,270,615,350);
        if(n<5)//Nivel 1
        {
        imprime_imagen(juego_m[denom[n]],175,380,255,460);
        imprime_imagen(juego_m[denom[n]],535,380,615,460);
        }      //Nivel 2
        else{imprime_imagen(juego_m[denom[n]],175,380,255,460);
        imprime_imagen(juego_m[denom2[n]],535,380,615,460);}
        //Seleccionar fraccion N1 y N2
        while(true)
        {
        J[0].estado(botones_J[0],botones_J[1]);
        J[1].estado(botones_J[2],botones_J[3]);
        if(J[0].prueba())
            {
            if(n<5){if(numerador[n]==numerador2[n]){puntaje++; s=7; if(puntaje%3==0){vida++; s=8;}break;}}

            if(numerador[n]==mayor[n]||mayor[n]==com[n]){puntaje++; s=7; if(puntaje%3==0){vida++; s=8;}break;}
            else{puntaje--; if(puntaje<0){puntaje=0;} vida--; s=9; break;}
            }
            if(J[1].prueba())
            {
            if(n<5){if(numerador[n]==numerador2[n]){puntaje++; s=7; if(puntaje%3==0){vida++; s=8;}break;}}

            if(numerador2[n]==mayor[n]||mayor2[n]==com[n]){puntaje++; s=7; if(puntaje%3==0){vida++; s=8;}break;}
            else{puntaje--; if(puntaje<0){puntaje=0;} vida--; s=9; break;}
            }
        }
        reproducir(audio[s],2);
        n++;r++;
        //Fin de juego por numero de vidas
        if (vida==0)
        {reproducir(audio[10],2); total=puntaje; puntaje=0; vida=3;
        num_j++;return(27);}
        //Fin de juego por numero de rondas
        if (n==10)
        {reproducir(audio[13],2); total=puntaje; puntaje=0; vida=3;
         num_j++;return(27);}
    }
char juego::nivel2(void)
{
    int s, m1, m2;
    reproducir(audio[15],1);
    imprime_imagen(numeros_j[puntaje],180,25,210,55);
    imprime_imagen(numeros_j2[vida],610,65,640,95);
    imprime_imagen(numeros_j[r],40,140,70,170);
    imprime_imagen(corazon[vida-1],720,30,780,90);

    if (r<5){imprime_imagen(juego_m[13],230,240,305,315);}
    else {imprime_imagen(juego_m[14],230,240,305,315);}
    imprime_imagen(juego_m[numerador[n]],110,190,190,270);
    imprime_imagen(juego_m[numerador2[n]],345,190,425,270);
    imprime_imagen(juego_m[denom[n]],110,290,190,370);
    imprime_imagen(juego_m[denom2[n]],345,290,425,370);

    outtextxy(610,200,"      ");
    outtextxy(610,330,"      ");
    imprime_imagen(juego_m[11],260,480,510,530);
    m1=captura_f(590,490,3,num);
    imprime_f(610,200,num,m1);
    imprime_imagen(juego_m[12],260,480,510,530);
    m2=captura_f(590,490,3,num2);
    imprime_f(610,330,num2,m2);

    if(m1==mayor[n]&&m2==mayor2[n]){puntaje++; s=7; if(puntaje%3==0){vida++; s=8;}}
    else{puntaje--; if(puntaje<0){puntaje=0;} vida--; s=9;}

    reproducir(audio[s],2);
    n++;r++;
    //Fin de juego por numero de vidas
    if (vida==0)
        {reproducir(audio[10],2); total=puntaje; puntaje=0; vida=3;
         num_j++;return(27);}
    //Fin de juego por numero de rondas
    if (n==10)
        {reproducir(audio[13],2); total=puntaje; puntaje=0; vida=3;
        num_j++;return(27);}
}

void juego::iniciar(void)
    {
        elegir_perfil();
        ver_perfil();
        while(menu_p()!=0);
    }
void usuario::elegir_avatar(void)
    {
        boton T[2];
        T[0].posicion(200,400,340,446);
        T[1].posicion(450,400,590,446);
        reproducir(audio[0],1);
        imprime_imagen(avatar[7],0,0,800,600);
        while(true)
        {
        T[0].estado(botones_A[2],botones_A[3]);
        T[1].estado(botones_A[4],botones_A[5]);
        if(T[0].prueba()){genero='M';reproducir(audio[1],2);break;}
        if(T[1].prueba()){genero='F';reproducir(audio[1],2);break;}
        }
    }
void usuario::elegir_alias(void)
    {
        boton A[7];
        reproducir(audio[0],1);
        imprime_imagen(avatar[0],0,0,800,600);

        if (genero=='M')
        {
        imprime_imagen(avatar[1],115,200,265,350);
        imprime_imagen(avatar[2],335,200,485,350);
        imprime_imagen(avatar[3],555,200,705,350);

        A[0].posicion(100,350,277,397);
        A[1].posicion(320,350,497,397);
        A[2].posicion(540,350,717,397);

        while(true)
        {
        A[0].estado(botones_A[6],botones_A[7]);
        A[1].estado(botones_A[8],botones_A[9]);
        A[2].estado(botones_A[10],botones_A[11]);
        if(A[0].prueba()){alias=2;imagen=avatar[1];pez=1;break;}
        if(A[1].prueba()){alias=3;imagen=avatar[2];pez=2;break;}
        if(A[2].prueba()){alias=4;imagen=avatar[3];pez=3;break;}
        }
        }

        else
        {
        imprime_imagen(avatar[4],115,200,265,350);
        imprime_imagen(avatar[5],335,200,485,350);
        imprime_imagen(avatar[6],555,200,705,350);

        A[3].posicion(100,350,277,397);
        A[4].posicion(320,350,497,397);
        A[5].posicion(540,350,717,397);

        while(true)
        {
        A[3].estado(botones_A[12],botones_A[13]);
        A[4].estado(botones_A[14],botones_A[15]);
        A[5].estado(botones_A[16],botones_A[17]);
        if(A[3].prueba()){alias=5;imagen=avatar[4];pez=4;break;}
        if(A[4].prueba()){alias=6;imagen=avatar[5];pez=5;break;}
        if(A[5].prueba()){alias=7;imagen=avatar[6];pez=6;break;}
        }
        }
       reproducir(audio[1],2);
    }
void usuario::elegir_perfil(void)
    {
        boton I[1];
        I[0].posicion(100,440,322,495);
        imprime_imagen(avatar2[8],0,0,800,600);
        reproducir(audio[12],1);
        while(true)
        {
        I[0].estado(botones_A[0],botones_A[1]);
        if(I[0].prueba()){reproducir(audio[1],2);break;}
        }
        elegir_avatar();
        elegir_alias();
    }
void usuario::ver_perfil(void)
    {
        boton V[1];
        V[0].posicion(285,500,507,555);
        reproducir(audio[0],1);
        switch(genero)
        {
            case 'F':imprime_imagen(avatar2[1],0,0,800,600); break;
            case 'M':imprime_imagen(avatar2[0],0,0,800,600); break;
        }
        imprime_imagen(imagen,280,165,520,405);
        imprime_imagen(avatar2[alias],285,120,515,170);
        while(true)
        {
        V[0].estado(botones_A[0],botones_A[1]);
        if(V[0].prueba()){reproducir(audio[1],2);break;}
        }
    }
void usuario::reproducir(char *audio,int c)
    {
        switch(c)
        {
            case 1:PlaySound(audio, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); break;
            case 2:PlaySound(audio, NULL, SND_FILENAME | SND_LOOP | SND_SYNC);  break;
        }
    }
void usuario::imprime_imagen(char *im, int xi, int yi, int xf, int yf)
    {
        readimagefile(im,xi,yi,xf,yf);
    }
