#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define linhas 5
#define colunas 5

char campo_aliado[linhas][colunas], campo_inimigo[linhas][colunas], barco[linhas][colunas];
int afundados, perdidos;

int main()
{
    int vencedor, barco_inimigo1x, barco_inimigo1y, barco_inimigo2x, barco_inimigo2y, barco_inimigo3x, barco_inimigo3y, cont, barco_aliado1x, barco_aliado1y, barco_aliado2x, barco_aliado2y, barco_aliado3x, barco_aliado3y;

    vencedor = 0; afundados = 0; perdidos = 0; cont = 0;

    cria_campo();
    cria_campo_maquina();

    char fala1[] = "Capitao: Comandante, encontramos a area com as embarcacoes inimigas!\n";
    char fala2[] = "Capitao: Nao sabemos o local exato mas estao por aqui!\n";
    char fala3[] = "Capitao: Estamos esperando suas ordens de ataque.\n";
    char fala4[] = "Capitao: Antes de entrarmos na luta, vamos posicionar nossas tropas.\n";
    char fala5[] = "Capitao: Certo, vamos a batalha.\n";

    char fala_posiciona[] = "Capitao: Selecione as coordenadas X e Y para posicionarmos nossas embarcacoes\n";
    char fala_posiciona2[] = "Capitao: Lembre-se, nao queremos ser descobertos e por isso estamos com poucos soldados.";

    char fala_barco[] = "Capitao: Ja posicionamos um barco nessa area, por favor, selecione outra: ";
    char fala_matriz[] = "Capitao: Nao podemos posicionar por ai, X e Y precisam ser valores entre 1 e 5: ";

    char fala_descobertos[] = "Capitao: Droga comandante, fomos descobertos! Prepare-se para o ataque inimigo.\n";

    char fala_vitoria1[] = "Capitao: Vencemos! Derrubamos todas as embarcacoes inimigas.\n";
    char fala_vitoria2[] = "Capitao: A missao foi um sucesso!\n";

    char fala_derrota1[] = "Capitao: Comandante, precisamos recuar! Todas as nossas embarcacoes foram derrubadas.\n";
    char fala_derrota2[] = "Capitao: A missao fracassou...\n";

    srand(time(NULL));

    barco_inimigo1x = rand() % (linhas);
    if((barco_inimigo1x < 1) || (barco_inimigo1x > linhas)) {
        do {
            barco_inimigo1x = rand() % (linhas);
        } while((barco_inimigo1x < 1) || (barco_inimigo1x > linhas));
    }

    barco_inimigo1y = rand() % (colunas);
    if((barco_inimigo1y < 1) || (barco_inimigo1y > colunas)) {
        do {
            barco_inimigo1y = rand() % (linhas);
        } while((barco_inimigo1y < 1) || (barco_inimigo1y > colunas));
    }

    barco_inimigo2x = rand() % (linhas);
    if((barco_inimigo2x < 1) || (barco_inimigo2x > linhas)) {
        do {
            barco_inimigo2x = rand() % (linhas);
        } while((barco_inimigo2x < 1) || (barco_inimigo2x > linhas));
    }

    barco_inimigo2y = rand() % (colunas);
    if((barco_inimigo2y < 1) || (barco_inimigo2y > colunas)) {
        do {
            barco_inimigo2y = rand() % (linhas);
        } while((barco_inimigo2y < 1) || (barco_inimigo2y > colunas));
    }

    if((barco_inimigo2x == barco_inimigo1x) && (barco_inimigo2y == barco_inimigo1y)) {
        do {
            barco_inimigo2x = rand() % (linhas);
            if((barco_inimigo2x < 1) || (barco_inimigo2x > linhas)) {
                do {
                    barco_inimigo2x = rand() % (linhas);
                } while((barco_inimigo2x < 1) || (barco_inimigo2x > linhas));
            }

            barco_inimigo2y = rand() % (colunas);
            if((barco_inimigo2y < 1) || (barco_inimigo2y > colunas)) {
                do {
                    barco_inimigo2y = rand() % (linhas);
                } while((barco_inimigo2y < 1) || (barco_inimigo2y > colunas));
            }

        } while((barco_inimigo2x == barco_inimigo1x) && (barco_inimigo2y == barco_inimigo1y));
    }

    barco_inimigo3x = rand() % (linhas);
    if((barco_inimigo3x < 1) || (barco_inimigo3x > linhas)) {
        do {
            barco_inimigo3x = rand() % (linhas);
        } while((barco_inimigo3x < 1) || (barco_inimigo3x > linhas));
    }

    barco_inimigo3y = rand() % (colunas);
    if((barco_inimigo3y < 1) || (barco_inimigo3y > colunas)) {
        do {
            barco_inimigo3y = rand() % (linhas);
        } while((barco_inimigo3y < 1) || (barco_inimigo3y > colunas));
    }

    if(((barco_inimigo3x == barco_inimigo1x) && (barco_inimigo3y == barco_inimigo1y)) || ((barco_inimigo3x == barco_inimigo2x) && (barco_inimigo3y == barco_inimigo2y))) {
        do {
            barco_inimigo3x = rand() % (linhas);
            if((barco_inimigo3x < 1) || (barco_inimigo3x > linhas)) {
                do {
                    barco_inimigo3x = rand() % (linhas);
                } while((barco_inimigo3x < 1) || (barco_inimigo3x > linhas));
            }

            barco_inimigo3y = rand() % (colunas);
            if((barco_inimigo3y < 1) || (barco_inimigo3y > colunas)) {
                do {
                    barco_inimigo3y = rand() % (linhas);
                } while((barco_inimigo3y < 1) || (barco_inimigo3y > colunas));
            }
        } while(((barco_inimigo3x == barco_inimigo1x) && (barco_inimigo3y == barco_inimigo1y)) || ((barco_inimigo3x == barco_inimigo2x) && (barco_inimigo3y == barco_inimigo2y)));
    }

    printf("\n%s", fala1);
    sleep(2);

    printf("%s", fala2);
    sleep(2);

    printf("%s\n", fala3);
    sleep(2);

    system("pause");

    system("cls");

    printf("%s", fala4);
    sleep(2);

    printf("%s", fala_posiciona);
    sleep(2);

    printf("%s\n\n", fala_posiciona2);
    sleep(2);

    system("pause");

    desenha_campo();

    printf("\n\nDigite as coordenadas X e Y pra o barco 1: ");
    scanf("%d%d", &barco_aliado1x, &barco_aliado1y);

    if((barco_aliado1x < 1) || (barco_aliado1x > linhas) || (barco_aliado1y < 1) || (barco_aliado1y > colunas)) {
        do {
            printf("%s", fala_matriz);
            scanf("%d%d", &barco_aliado1x, &barco_aliado1y);
        } while((barco_aliado1x < 1) || (barco_aliado1x > linhas) || (barco_aliado1y < 1) || (barco_aliado1y > colunas));
    }

    printf("\nDigite as coordenadas X e Y pra o barco 2: ");
    scanf("%d%d", &barco_aliado2x, &barco_aliado2y);

    if((barco_aliado2x == barco_aliado1x) && (barco_aliado2y == barco_aliado1y)) {
        do {
            printf("%s", fala_barco);
            scanf("%d%d", &barco_aliado2x, &barco_aliado2y);

            if((barco_aliado2x < 1) || (barco_aliado2x > linhas) || (barco_aliado2y < 1) || (barco_aliado2y > colunas)) {
                do {
                    printf("%s", fala_matriz);
                    scanf("%d%d", &barco_aliado1x, &barco_aliado1y);
                } while((barco_aliado2x < 1) || (barco_aliado2x > linhas) || (barco_aliado2y < 1) || (barco_aliado2y > colunas));
            }
        } while((barco_aliado2x == barco_aliado1x) && (barco_aliado2y == barco_aliado1y));
    }

    if((barco_aliado2x < 1) || (barco_aliado2x > linhas) || (barco_aliado2y < 1) || (barco_aliado2y > colunas)) {
        do {
            printf("%s", fala_matriz);
            scanf("%d%d", &barco_aliado2x, &barco_aliado2y);

            if((barco_aliado2x == barco_aliado1x) && (barco_aliado2y == barco_aliado1y)) {
                do {
                    printf("%s", fala_barco);
                    scanf("%d%d", &barco_aliado1x, &barco_aliado1y);
                } while((barco_aliado2x == barco_aliado1x) && (barco_aliado2y == barco_aliado1y));
            }
        } while((barco_aliado2x < 1) || (barco_aliado2x > linhas) || (barco_aliado2y < 1) || (barco_aliado2y > colunas));
    }

    printf("\nDigite as coordenadas X e Y pra o barco 3: ");
    scanf("%d%d", &barco_aliado3x, &barco_aliado3y);

    if(((barco_aliado3x == barco_aliado1x) && (barco_aliado3y == barco_aliado1y)) || ((barco_aliado3x == barco_aliado2x) && (barco_aliado3y == barco_aliado2y))) {
        do {
            printf("%s", fala_barco);
            scanf("%d%d", &barco_aliado3x, &barco_aliado3y);

            if((barco_aliado3x < 1) || (barco_aliado3x > linhas) || (barco_aliado3y < 1) || (barco_aliado3y > colunas)) {
                do {
                    printf("%s", fala_matriz);
                    scanf("%d%d", &barco_aliado3x, &barco_aliado3y);
                } while((barco_aliado3x < 1) || (barco_aliado3x > linhas) || (barco_aliado3y < 1) || (barco_aliado3y > colunas));
            }
        } while(((barco_aliado3x == barco_aliado1x) && (barco_aliado3y == barco_aliado1y)) || ((barco_aliado3x == barco_aliado2x) && (barco_aliado3y == barco_aliado2y)));
    }

    if((barco_aliado3x < 1) || (barco_aliado3x > linhas) || (barco_aliado3y < 1) || (barco_aliado3y > colunas)) {
        do {
            printf("%s", fala_matriz);
            scanf("%d%d", &barco_aliado3x, &barco_aliado3y);

            if(((barco_aliado3x == barco_aliado1x) && (barco_aliado3y == barco_aliado1y)) || ((barco_aliado3x == barco_aliado2x) && (barco_aliado3y == barco_aliado2y))) {
                do {
                    printf("%s", fala_barco);
                    scanf("%d%d", &barco_aliado1x, &barco_aliado1y);
                } while(((barco_aliado3x == barco_aliado1x) && (barco_aliado3y == barco_aliado1y)) || ((barco_aliado3x == barco_aliado2x) && (barco_aliado3y == barco_aliado2y)));
            }
        } while((barco_aliado3x < 1) || (barco_aliado3x > linhas) || (barco_aliado3y < 1) || (barco_aliado3y > colunas));
    }

    printf("\n%s\n", fala5);

    system("pause");

    system("cls");

    do {
        desenha_campo_maquina();
        jogada(barco_inimigo1x, barco_inimigo1y, barco_inimigo2x, barco_inimigo2y, barco_inimigo3x, barco_inimigo3y);
        desenha_campo_maquina();
        printf("\n");
        system("pause");

        vencedor = verifica(afundados);

        if(vencedor != 0) break;

        if(cont == 0) {system("cls"); printf("%s", fala_descobertos); printf("\n"); cont = 1; system("pause");}

        desenha_campo();
        jogada_maquina(barco_aliado1x, barco_aliado1y, barco_aliado2x, barco_aliado2y, barco_aliado3x, barco_aliado3y);
        desenha_campo();
        printf("\n");
        system("pause");

        vencedor = verifica(perdidos);

        if(vencedor != 0) break;

    }while(vencedor == 0);

    if(vencedor == 1) {
        system("cls");
        printf("%s", fala_vitoria1);
        printf("%s\n", fala_vitoria2);
        system("pause");
    } else {
        system("cls");
        printf("%s", fala_derrota1);
        printf("%s\n", fala_derrota2);
        system("pause");
    }

    return 0;
}

void cria_campo() {
    int x, y;

    for(x = 1; x < linhas+1; x++) {
        for(y = 1; y < colunas+1; y++) {
            campo_aliado[x][y] = '#';
        }
    }
}

void cria_campo_maquina() {
    int x, y;

    for(x = 1; x < linhas+1; x++) {
        for(y = 1; y < colunas+1; y++) {
            campo_inimigo[x][y] = '#';
        }
    }
}

void desenha_campo() {
    int x, y;

    system("cls");
    printf("Campo aliado: \n\n");

    printf("  ");

    for(y = 1; y < colunas+1; y++) {
        printf("%d ", y);
    }

    printf("\n");
    for(x = 1; x < linhas+1; x++) {
        printf("%d ", x);

		/* Exibição das coordenadas das embarcações */
//        for(y = 1; y < colunas+1; y++) {
//            printf("%c ", campo_aliado[x][y]);
//        }
        /* Fim da Exibição das coordenadas das embarcações */
        printf("\n");
    }
}

void desenha_campo_maquina() {
    int x, y;

    system("cls");

    printf("Campo inimigo: \n\n");

    printf("  ");

    for(y = 1; y < colunas+1; y++) {
        printf("%d ", y);
    }

    printf("\n");

    for(x = 1; x < linhas+1; x++) {
        printf("%d ", x);

        for(y = 1; y < colunas+1; y++) {
            printf("%c ", campo_inimigo[x][y]);
        }
        printf("\n");
    }
}

int jogada(int barco_inimigo1x, int barco_inimigo1y, int barco_inimigo2x, int barco_inimigo2y, int barco_inimigo3x, int barco_inimigo3y) {
    int atqX, atqY;

    char acerto[] = "Capitao: Isso! Acertamos um!\n";
    char erro[] = "Capitao: Droga! Erramos essa...\n";

    char fala_matriz[] = "Capitao: Nao podemos posicionar por ai, X e Y precisam ser valores entre 1 e 5: ";

    printf("%d %d\n%d %d\n%d %d\n", barco_inimigo1x, barco_inimigo1y, barco_inimigo2x, barco_inimigo2y, barco_inimigo3x, barco_inimigo3y);

    printf("\nEscolha as coordenadas X e Y para lancarmos o ataque: ");
    scanf("%d%d", &atqX, &atqY);

    if((atqX < 1) || (atqX > linhas) || (atqY < 1) || (atqY > colunas)) {
        do {
            printf("%s", fala_matriz);
            scanf("%d%d", &atqX, &atqY);
        } while((atqX < 1) || (atqX > linhas) || (atqY < 1) || (atqY > colunas));
    }

    if(((atqX == barco_inimigo1x) && (atqY == barco_inimigo1y)) || ((atqX == barco_inimigo2x) && (atqY == barco_inimigo2y)) || ((atqX == barco_inimigo3x) && (atqY == barco_inimigo3y))) {
        campo_inimigo[atqX][atqY] = 'X';
        afundados++;
        printf("\n%s\n", acerto);
        system("pause");
        return afundados;
    } else {
        campo_inimigo[atqX][atqY] = '~';
        printf("\n%s\n", erro);
        system("pause");
        return afundados;
    }

    system("cls");
}

int jogada_maquina(int barco_aliado1x, int barco_aliado1y, int barco_aliado2x, int barco_aliado2y, int barco_aliado3x, int barco_aliado3y) {
    int atqX, atqY;

    char acerto[] = "Capitao: Merda! Perdemos um...!\n";
    char erro[] = "Capitao: Eles erraram!\n";

    printf("%d %d\n%d %d\n%d %d\n", barco_aliado1x, barco_aliado1y, barco_aliado2x, barco_aliado2y, barco_aliado3x, barco_aliado3y);

    atqX = rand() % (linhas);
    if(atqX < 1) {
        do {
            atqX = rand() % (linhas);
        } while(atqX < 1);
    }

    atqY = rand() % (colunas);
    if(atqY < 1) {
        do {
            atqY = rand() % colunas;
        } while(atqY < 1);
    }

    if(((atqX == barco_aliado1x) && (atqY == barco_aliado1y)) || ((atqX == barco_aliado2x) && (atqY == barco_aliado2y)) || ((atqX == barco_aliado3x) && (atqY == barco_aliado3y))) {
        campo_aliado[atqX][atqY] = 'X';
        perdidos++;
        printf("\n%s\n", acerto);
        system("pause");
        return perdidos;
    } else {
        campo_aliado[atqX][atqY] = '~';
        printf("\n%s\n", erro);
        system("pause");
        return perdidos;
    }

    system("cls");
}

int verifica(int afundados, int perdidos) {
    if(afundados == 3)
        return 1;
    else if (perdidos == 3)
        return 2;
    else
        return 0;
}
