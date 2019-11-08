#include <stdio.h>
#include <stdlib.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

sf::RenderWindow window(sf::VideoMode(100, 50), "My window");


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

int inserirObstaculos(int matriz[][100], int obstaculos[][2])
{
    int i, j, k=0;
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
                obstaculos[k][0]=j;
                obstaculos[k][1]=i;
                comando='o';
                k++;
            }


        }
    }while(comando!='n');
    return k;
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

int caminho(int posicao[][2], int matriz[][100], int k)
{
    int x, y, dx, dy, conferidor;
    x=posicao[0][0];
    y=posicao[0][1];
    dx=posicao[2][0];
    dy=posicao[2][1];
    posicao[k][0]=x;
    posicao[k][1]=y;




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
    
    sf::Event event;
    sf::RectangleShape retangulo(sf::Vector2f(100,50));
    sf::RectangleShape limite(sf::Vector2f(100,50));
    sf::CircleShape jogador(0.5);
    

    
    limite.setPosition(0,0);

    limite.setOutlineThickness(2);

    limite.setOutlineColor(sf::Color(255,255,255));
    limite.setFillColor(sf::Color(0,125,0));
    jogador.setFillColor(sf::Color(255, 255, 0));
    
    int campo[50][100], posicao[150][2], obstaculos[100][2];
    int i, j, k=0, l=3;

    preencheMatriz(campo);
    k=inserirObstaculos(campo, obstaculos);
    pontoInicial(posicao, campo);
    escolheAlvo(posicao,campo);
    do{
        distanciaEntrePontos(posicao);
        i=caminho(posicao, campo, l);
        l++;
        }while(i!=8);

    while(window.isOpen() && k!=0){
        window.clear(sf::Color(255,255,255));
        window.draw(limite);
        for(j=0 ;j<k; j++)
        {
            jogador.setPosition(obstaculos[j][0], obstaculos[j][1]);
            window.draw(jogador);
        }
        for(j=3; j<l-1; j++)
        {
            sf::Vertex caminho[]={
             sf::Vertex(sf::Vector2f(posicao[j][0], posicao[j][1])), sf::Vertex(sf::Vector2f(posicao[j+1][0],posicao[j+1][1]))
            };
          window.draw(caminho, 3, sf::Lines);
        }
        
        
		
		window.display();

        


        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }
    }
  
    return 0;
}
