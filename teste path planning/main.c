#include <stdio.h>
#include <stdlib.h>


void preencheMatriz(int matriz[][100])
{
    int i, j;
    for(i=0; i<50; i++)
    {
        for(j=0; j<100; j++)
        {
            matriz[i][j]=0;
        }
    }
}

void inserirObstaculos(int matriz[][100])
{
    int i, j;
    char comando;
    do
    {
        printf("Deseja adicionar um obstaculo?(s/n)\n");
        fflush(stdin);
        scanf("%c", &comando);
        while(comando=='s')
        {
            printf("Qual eh a posicao do obstaculo em x e y?");
            fflush(stdin);
            scanf("%d %d", &j, &i);
            if(i>=50 || j>=100 || i<0 || j<0)
            {
                printf("Coordenada invalida, tente novamente\n");
            }
            else
            {
                matriz[i][j]=1;
                comando='o';
            }


        }
    }while(comando!='n');
}

int checaPonto(int matriz[][100], int x, int y)
{
    if (matriz[y][x]==0)
        return 0;
    else
        return 1;
}
void escolheAlvo(int posicao[][2], int matriz[][100])
{
    int i=0;
    do
    {
        printf("Para onde o jogador deve ir?(em x e y)\n");
        fflush(stdin);
        scanf("%d %d", &posicao[1][0], &posicao[1][1]); //armazena na segunda linha da matriz posicao a posicao final do jogador
        i=checaPonto(matriz, posicao[1][0], posicao[1][1]);
        if(i!=0)
            printf("Posicao invalida, tente novamente\n");
    }while(i!=0);

}

void pontoInicial(int posicao[][2], int matriz[][100])
{
    int i=0;
    do
    {
        printf("Onde o jogador esta no campo?(em x e y)\n");
        fflush(stdin);
        scanf("%d %d", &posicao[0][0], &posicao[0][1]); //armazena na primeira linha da matriz posicao a posicao inicial do jogador
        i=checaPonto(matriz, posicao[0][0], posicao[0][1]);
        if(i!=0)
            printf("Posicao invalida, tente novamente\n");
    }while(i!=0);
}

void distanciaEntrePontos(int posicao[][2])
{
    posicao[2][0]=posicao[1][0]-posicao[0][0];
    posicao[2][1]=posicao[1][1]-posicao[0][1];
}

int checaPosicao(int matriz[][100], int x, int y) //matriz do campo e posicao em x e y do caminho a ser percorrido
{
    int conferidor;

    if(matriz[y][x]==0)
    {
        conferidor=0;
        matriz[y][x]=8;
    }

    else
    {
        conferidor=1;
    }
    return conferidor;

}

int caminho(int posicao[][2], int matriz[][100])
{
    int x, y, dx, dy, conferidor;
    x=posicao[0][0];
    y=posicao[0][1];
    dx=posicao[2][0];
    dy=posicao[2][1];



    if(dx>0)
    {
        if(dy>0)
        {
            x++;
            y++;
            conferidor=checaPosicao(matriz, x, y);
            if(conferidor!=0)
            {
                y--;
                conferidor=checaPosicao(matriz, x, y);
                if(conferidor!=0)
                {
                    x--;
                    y++;
                    conferidor=checaPosicao(matriz, x, y);
                    if(conferidor!=0)
                    {
                        return 0;
                    }

                }
            }
        }
        else if(dy<0)
        {
            x++;
            y--;
            conferidor=checaPosicao(matriz, x, y);
            if(conferidor!=0)
            {
                y++;
                conferidor=checaPosicao(matriz, x, y);
                if(conferidor!=0)
                {
                    x--;
                    y--;
                    conferidor=checaPosicao(matriz, x, y);
                    if(conferidor!=0)
                    {
                        return 0;
                    }

                }
            }
        }
        else
        {
            x++;
            conferidor=checaPosicao(matriz, x, y);
            if(conferidor!=0)
            {
                y++;
                conferidor=checaPosicao(matriz, x, y);
                if(conferidor!=0)
                {
                    y=y-2;
                    conferidor=checaPosicao(matriz, x, y);
                    if(conferidor!=0)
                    {
                        return 0;
                    }

                }
            }
        }
    }
    else if(dx<0)
    {
            if(dy>0)
            {
                x--;
                y++;
                conferidor=checaPosicao(matriz, x, y);
                if(conferidor!=0)
                {
                    y--;
                    conferidor=checaPosicao(matriz, x, y);
                    if(conferidor!=0)
                    {
                        x++;
                        y++;
                        conferidor=checaPosicao(matriz, x, y);
                        if(conferidor!=0)
                        {
                            return 0;
                        }

                    }
                }
            }
            else if(dy<0)
            {
                x--;
                y--;
                conferidor=checaPosicao(matriz, x, y);
                if(conferidor!=0)
                {
                    y++;
                    conferidor=checaPosicao(matriz, x, y);
                    if(conferidor!=0)
                    {
                        x++;
                        y--;
                        conferidor=checaPosicao(matriz, x, y);
                        if(conferidor!=0)
                        {
                            return 0;
                        }

                    }
                }
            }
            else
            {
                x--;
                conferidor=checaPosicao(matriz, x, y);
                if(conferidor!=0)
                {
                    y++;
                    conferidor=checaPosicao(matriz, x, y);
                    if(conferidor!=0)
                    {
                        y=y-2;
                        conferidor=checaPosicao(matriz, x, y);
                        if(conferidor!=0)
                        {
                            return 0;
                        }

                    }
                }
            }
    }
    else if(dx==0)
    {
        if(dy>0)
        {
            y++;
            conferidor=checaPosicao(matriz, x, y);
            if(conferidor!=0)
            {
                x++;
                conferidor=checaPosicao(matriz, x, y);
                if(conferidor!=0)
                {
                    x=x-2;
                    conferidor=checaPosicao(matriz, x, y);
                    if(conferidor!=0)
                    {
                        return 0;
                    }
                }

            }
        }
        else if(dy<0)
        {
            y--;
            conferidor=checaPosicao(matriz, x, y);
            if(conferidor!=0)
            {
                x++;
                conferidor=checaPosicao(matriz, x, y);
                if(conferidor!=0)
                {
                    x=x-2;
                    conferidor=checaPosicao(matriz, x, y);
                    if(conferidor!=0)
                    {
                        return 0;
                    }
                }

            }
        }
        else
        {
            return 8;
        }
    }
    posicao[0][0]=x;
    posicao[0][1]=y;
    printf("%d %d\n", x, y);
    return 1;


}



int main()
{
   int campo[50][100], posicao[3][2];
   int i;
   preencheMatriz(campo);
   inserirObstaculos(campo);
   pontoInicial(posicao, campo);
   escolheAlvo(posicao,campo);

   do{
    distanciaEntrePontos(posicao);
    i=caminho(posicao, campo);
   }while(i!=0);
    return 0;
}
