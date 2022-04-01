#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

enum ConsoleColors
{
   BlackFore   = 0,
   MaroonFore  = FOREGROUND_RED,
   GreenFore   = FOREGROUND_GREEN,
   NavyFore    = FOREGROUND_BLUE,
   TealFore    = FOREGROUND_GREEN | FOREGROUND_BLUE,
   OliveFore   = FOREGROUND_RED | FOREGROUND_GREEN,
   PurpleFore  = FOREGROUND_RED | FOREGROUND_BLUE,
   GrayFore    = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
   SilverFore  = FOREGROUND_INTENSITY,
   RedFore     = FOREGROUND_INTENSITY | FOREGROUND_RED,
   LimeFore    = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
   BlueFore    = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
   AquaFore    = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
   YellowFore  = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
   FuchsiaFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
   WhiteFore   = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

   BlackBack   = 0,
   MaroonBack  = BACKGROUND_RED,
   GreenBack   = BACKGROUND_GREEN,
   NavyBack    = BACKGROUND_BLUE,
   TealBack    = BACKGROUND_GREEN | BACKGROUND_BLUE,
   OliveBack   = BACKGROUND_RED | BACKGROUND_GREEN,
   PurpleBack  = BACKGROUND_RED | BACKGROUND_BLUE,
   GrayBack    = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
   SilverBack  = BACKGROUND_INTENSITY,
   RedBack     = BACKGROUND_INTENSITY | BACKGROUND_RED,
   LimeBack    = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
   BlueBack    = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
   AquaBack    = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
   YellowBack  = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
   FuchsiaBack = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
   WhiteBack   = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
};

//jogo da velha
char p1[10];
char p2[10];
int pontox = 0;
int pontoy = 0;
int vez = 0;

//pedra papel tesoura
int placarpptp = 0;
int placarpptb = 0;

//menu
char charmenu = 16;
int maxmenu = 6;
int escmenu = 0;

void proximarodada(){
    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("Deseja ir para a proxima rodada? [");
    SetConsoleTextAttribute(cmd, LimeFore);
    printf(" y ");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("/");
    SetConsoleTextAttribute(cmd, RedFore);
    printf(" n ");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("/");
    SetConsoleTextAttribute(cmd, YellowFore);
    printf(" menu ");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("]\n\n");
}
void jogarnovamente(){
    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("Deseja jogar novamente? [");
    SetConsoleTextAttribute(cmd, LimeFore);
    printf(" y ");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("/");
    SetConsoleTextAttribute(cmd, RedFore);
    printf(" n ");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("/");
    SetConsoleTextAttribute(cmd, YellowFore);
    printf(" menu ");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("]\n\n");
}

void telacustom(char frase[20], char cor[10]){

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(cmd, cor);

    int ec = 201;
    int m = 205;
    int m1 = 196;
    int m2 = 223;
    int m3 = 219;
    int ed = 187;
    int ml = 186;
    int eec = 200;
    int eed = 188;
    int b = 0;

    printf("\n");

    printf("\t%c", ec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }

    printf("%c \n", ed);

    b = 0;

    printf("\t%c    %s     %c\n", ml, frase, ml);
    printf("\t%c", eec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }
    printf("%c \n", eed);

    printf("\n");

    SetConsoleTextAttribute(cmd, WhiteFore);
}

void telaperdeu(){

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(cmd, RedFore);
    int ec = 201;
    int m = 205;
    int m1 = 196;
    int m2 = 223;
    int m3 = 219;
    int ed = 187;
    int ml = 186;
    int eec = 200;
    int eed = 188;
    int b = 0;

    printf("\n");

    printf("\t%c", ec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }

    printf("%c \n", ed);

    b = 0;

    printf("\t%c       VOCE PERDEU      %c \n", ml, ml);
    printf("\t%c", eec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }
    printf("%c \n", eed);

    printf("\n");
    placarpptb++;

    SetConsoleTextAttribute(cmd, WhiteFore);

}
void telaganhou(){

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(cmd, LimeFore);

    int ec = 201;
    int m = 205;
    int m1 = 196;
    int m2 = 223;
    int m3 = 219;
    int ed = 187;
    int ml = 186;
    int eec = 200;
    int eed = 188;
    int b = 0;

    printf("\n");

    printf("\t%c", ec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }

    printf("%c \n", ed);

    b = 0;

    printf("\t%c       VOCE GANHOU      %c \n", ml, ml);
    printf("\t%c", eec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }
    printf("%c \n", eed);

    printf("\n");
    placarpptp++;

    SetConsoleTextAttribute(cmd, WhiteFore);
}
void telaempatou(){

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(cmd, YellowFore);

    int ec = 201;
    int m = 205;
    int m1 = 196;
    int m2 = 223;
    int m3 = 219;
    int ed = 187;
    int ml = 186;
    int eec = 200;
    int eed = 188;
    int b = 0;

    printf("\n");

    printf("\t%c", ec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }

    printf("%c \n", ed);

    b = 0;

    printf("\t%c    VOCES EMPATARAM     %c \n", ml, ml);
    printf("\t%c", eec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }
    printf("%c \n", eed);

    printf("\n");

    SetConsoleTextAttribute(cmd, WhiteFore);

}
void placarppt(){

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("Placar atual: \n\n");

    SetConsoleTextAttribute(cmd, LimeFore);

    printf("Pontos do Jogador: %d\n", placarpptp);

    SetConsoleTextAttribute(cmd, RedFore);

    printf("Pontos do Bot: %d\n", placarpptb);

    SetConsoleTextAttribute(cmd, WhiteFore);
}

void textocustom(char texto[50], char cor[10]){

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(cmd, cor);
    printf("%s", texto);
    SetConsoleTextAttribute(cmd, WhiteFore);

}

void numerocustom(int numero[10], char cor[10]){

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(cmd, cor);
    printf("%d", numero);
    SetConsoleTextAttribute(cmd, WhiteFore);

}


void continuarblackjack(){
    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("[ ");
    SetConsoleTextAttribute(cmd, LimeFore);
    printf("pedir");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf(" / ");
    SetConsoleTextAttribute(cmd, YellowFore);
    printf("parar");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf(" / ");
    SetConsoleTextAttribute(cmd, RedFore);
    printf("desistir");
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf(" ]\n");
}

void cmenu(){

    system("color f");
    system("cls");

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("\n\n");

    if(escmenu == 0)
    {
        printf("\t ");
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("%c  ", charmenu);
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("JOGO DO NUMERO\n");
        printf("\t     JOGO DA MEMORIA\n");
        printf("\t     JOGO DA VELHA\n");
        printf("\t     PEDRA PAPEL TESOURA\n");
        printf("\t     BLACKJACK\n");
        printf("\t     CREDITOS\n");
        printf("\t     SAIR\n");
    }
    else if(escmenu == 1)
    {
        printf("\t     JOGO DO NUMERO\n");
        printf("\t ");
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("%c  ", charmenu);
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("JOGO DA MEMORIA\n");
        printf("\t     JOGO DA VELHA\n");
        printf("\t     PEDRA PAPEL TESOURA\n");
        printf("\t     BLACKJACK\n");
        printf("\t     CREDITOS\n");
        printf("\t     SAIR\n");
    }
    else if(escmenu == 2)
    {
        printf("\t     JOGO DO NUMERO\n");
        printf("\t     JOGO DA MEMORIA\n");
        printf("\t ");
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("%c  ", charmenu);
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("JOGO DA VELHA\n");
        printf("\t     PEDRA PAPEL TESOURA\n");
        printf("\t     BLACKJACK\n");
        printf("\t     CREDITOS\n");
        printf("\t     SAIR\n");
    }
    else if(escmenu == 3)
    {
        printf("\t     JOGO DO NUMERO\n");
        printf("\t     JOGO DA MEMORIA\n");
        printf("\t     JOGO DA VELHA\n");
        printf("\t ");
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("%c  ", charmenu);
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("PEDRA PAPEL TESOURA\n");
        printf("\t     BLACKJACK\n");
        printf("\t     CREDITOS\n");
        printf("\t     SAIR\n");
    }
    else if(escmenu == 4)
    {
        printf("\t     JOGO DO NUMERO\n");
        printf("\t     JOGO DA MEMORIA\n");
        printf("\t     JOGO DA VELHA\n");
        printf("\t     PEDRA PAPEL TESOURA\n");
        printf("\t ");
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("%c  ", charmenu);
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("BLACKJACK\n");
        printf("\t     CREDITOS\n");
        printf("\t     SAIR\n");
    }
    else if(escmenu == 5)
    {
        printf("\t     JOGO DO NUMERO\n");
        printf("\t     JOGO DA MEMORIA\n");
        printf("\t     JOGO DA VELHA\n");
        printf("\t     PEDRA PAPEL TESOURA\n");
        printf("\t     BLACKJACK\n");
        printf("\t ");
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("%c ", charmenu);
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("CREDITOS\n");
        printf("\t     SAIR\n");
    }
    else if(escmenu == 6)
    {
        printf("\t     JOGO DO NUMERO\n");
        printf("\t     JOGO DA MEMORIA\n");
        printf("\t     JOGO DA VELHA\n");
        printf("\t     PEDRA PAPEL TESOURA\n");
        printf("\t     BLACKJACK\n");
        printf("\t     CREDITOS\n");
        printf("\t ");
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("%c ", charmenu);
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf("SAIR\n");
    }
}

void main(){
    SetConsoleTitle("Menu");

    cmenu();

    menucomeco: ;

    int i;
    int tecla;

    tecla = getch();

    if(tecla == 0 || tecla == 224)
    {
        tecla = getch();
    }

    system("cls");

    if(tecla == 80)
    {
        if(escmenu >= maxmenu)
        {
            system("cls");
            escmenu = 0;
            cmenu();

            goto menucomeco;
        }

        system("cls");
        escmenu++;
        cmenu();

        goto menucomeco;
        system("cls");
    }
    else if(tecla == 72)
    {
        if(escmenu <= 0)
        {
            system("cls");
            escmenu = maxmenu;
            cmenu();

            goto menucomeco;
        }
        system("cls");
        escmenu -= 1;
        cmenu();

        goto menucomeco;
        system("cls");
    }
    else if(tecla == 13)
    {
        if(escmenu == 0)
        {
            jogo_numero();
        }
        else if(escmenu == 1)
        {
            jogo_memoria();
        }
        else if(escmenu == 2)
        {
            jogo_velha();
        }
        else if(escmenu == 3)
        {
            pedrapapeltesoura();
        }
        else if(escmenu == 4)
        {
            blackjack();
        }
        else if(escmenu == 5)
        {
            creditos();
        }
        else if(escmenu == 6)
        {
            exit(0);
        }
    }
}

void jogo_numero(){

    int vitorias_seguidas = 1;

    inicio:

    SetConsoleTitle("Acerte o numero");

    system("color f");

    int ec = 201;
    int m = 205;
    int m1 = 196;
    int m2 = 223;
    int m3 = 219;
    int ed = 187;
    int ml = 186;
    int eec = 200;
    int eed = 188;
    int b = 0;
    char escolha;

    printf("\t%c", ec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }

    printf("%c \n", ed);

    b = 0;

    printf("\t%c        Acerte o        %c \n", ml, ml);
    printf("\t%c         Numero         %c \n", ml, ml);
    printf("\t%c", eec);

   for(b = 0; b <= 23; b++)
   {
       printf("%c", m);
   }

    printf("%c \n", eed);

    int n, e, r;

    e = 3;
    srand(time(NULL));
    r = (rand() % 10) + 1;
    if(r == 0)
    {
        r = ("%d ", rand() % 10);
    }

    printf("\nVoce tem %d chances para acertar numero de 1 a 10 \n\n", e);
    printf("Digite um numero: ");
    digite_numero:
    scanf("%d", &n);

    if(n > 10 || n < 1)
    {
        printf("\n\n");
        for(b = 0; b <= 55; b++)
        {
            printf("%c", m2);
        }
        printf("\n\nNumero invalido.\n\nTente novamente: ");
        goto digite_numero;
    }
    else if(n > r && e > 1)
    {
        e--;
        printf("\n\n");
        for(b = 0; b <= 55; b++)
        {
            printf("%c", m2);
        }
        printf("\n\nSeu numero foi alto, voce ainda tem %d chances.\nTente novamente: ", e);
        goto digite_numero;
    }
    else if(n < r && e > 1)
    {
        e--;
        printf("\n\n");
        for(b = 0; b <= 55; b++)
        {
            printf("%c", m2);
        }
        printf("\n\nSeu numero foi baixo, voce ainda tem %d chances.\nTente novamente:  ", e);
        goto digite_numero;
    }
    else if(n == r && e > 0)
    {

        printf("\n\n");

        telaganhou();

        printf("\nVoce esta com %d vitorias seguidas!\n", vitorias_seguidas);

        proximarodada();
        scanf("%s", &escolha);
        if(escolha == 'y')
        {
            system("cls");
            vitorias_seguidas++;
            goto inicio;
        }
        if(escolha == 'm')
        {
            system("cls");
            main();
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        printf("\n");

        telaperdeu();

        jogarnovamente();
        scanf("%s", &escolha);

        if(escolha == 'y')
        {
            system("cls");
            vitorias_seguidas = 1;
            goto inicio;
        }
        if(escolha == 'm')
        {

            void nocursor();
            main();
        }
        else
        {
            exit(0);
        }
    }
}

//----------------------------------------------------------//

void tabuleiro(char casas2 [9]){
    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    char c = 196;
    char c1 = 197;
    char c3 = 179;
    system("cls");

    if(casas2[6] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[6] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf("\t %c ", casas2[6]);
    SetConsoleTextAttribute(cmd, WhiteFore);

    printf("%c", c3);

    if(casas2[7] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[7] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf(" %c ", casas2[7]);
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("%c", c3);
    if(casas2[8] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[8] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf(" %c", casas2[8]);
    SetConsoleTextAttribute(cmd, WhiteFore);
    puts(" ");
    printf("\t%c%c%c%c%c%c%c%c%c%c%c\n", c, c, c, c1, c, c, c, c1, c, c, c);
    if(casas2[3] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[3] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf("\t %c ", casas2[3]);
    SetConsoleTextAttribute(cmd, WhiteFore);

    printf("%c", c3);

    if(casas2[4] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[4] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf(" %c ", casas2[4]);
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("%c", c3);
    if(casas2[5] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[5] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf(" %c", casas2[5]);
    SetConsoleTextAttribute(cmd, WhiteFore);
    puts(" ");
    printf("\t%c%c%c%c%c%c%c%c%c%c%c\n", c, c, c, c1, c, c, c, c1, c, c, c);
        if(casas2[0] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[0] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf("\t %c ", casas2[0]);
    SetConsoleTextAttribute(cmd, WhiteFore);

    printf("%c", c3);

    if(casas2[1] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[1] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf(" %c ", casas2[1]);
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("%c", c3);
    if(casas2[2] == 'X')
    {
        SetConsoleTextAttribute(cmd, LimeFore);
    }
    else if(casas2[2] == 'O')
    {
        SetConsoleTextAttribute(cmd, RedFore);
    }
    printf(" %c", casas2[2]);
    SetConsoleTextAttribute(cmd, WhiteFore);
    puts(" ");
    SetConsoleTextAttribute(cmd, WhiteFore);
}

void telanova(){
    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("Insira o nome do player 1: ");
    SetConsoleTextAttribute(cmd, LimeFore);
    scanf("%s", &p1);
    SetConsoleTextAttribute(cmd, WhiteFore);
    printf("Insira o nome do player 2: ");
    SetConsoleTextAttribute(cmd, RedFore);
    scanf("%s", &p2);
    SetConsoleTextAttribute(cmd, WhiteFore);
}

void jogo_velha(){
    SetConsoleTitle("Jogo da velha");
    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);
    telanova();

    comeco: ;

    char casas[9] = {'1','2','3','4', '5', '6', '7', '8', '9'};
    tabuleiro(casas);
    char res;
    int cont_jogadas, jogada, i ;

            cont_jogadas = 1;
            for(i = 0; i<=8; i++){
                casas[i] = ' ';
            }
        do{
            tabuleiro(casas);
            printf("digite a casa para marcar [1 - 9]\n");
            if(vez%2==0){
                printf("vez de ");
                SetConsoleTextAttribute(cmd, LimeFore);
                printf("%s", p1);
                SetConsoleTextAttribute(cmd, WhiteFore);
                printf(": ");
            }else{
                printf("vez de ");
                SetConsoleTextAttribute(cmd, RedFore);
                printf("%s", p2);
                SetConsoleTextAttribute(cmd, WhiteFore);
                printf(": ");
            }
            scanf("%i", &jogada);
            if(jogada <1 || jogada > 9){
                jogada = 0;
            }else if(casas[jogada - 1] != ' '){
                jogada = 0;
            }else{
                if(vez%2==0){
                    casas[jogada - 1] = 'X';
                }else{
                    casas[jogada - 1] = 'O';
                }
                cont_jogadas++;
                vez++;
            }
            if(casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O'){cont_jogadas = 12;}
            if(casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X'){cont_jogadas = 11;}
            if(casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O'){cont_jogadas = 12;}
            if(casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X'){cont_jogadas = 11;}
            if(casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}
            if(casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
            if(casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O'){cont_jogadas = 12;}
            if(casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X'){cont_jogadas = 11;}
            if(casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}
            if(casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O'){cont_jogadas = 12;}
            if(casas[2] == 'O' && casas[4] == 'O' && casas[6] == 'O'){cont_jogadas = 12;}
            if(casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}
            if(casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
            if(casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X'){cont_jogadas = 11;}
            if(casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X'){cont_jogadas = 11;}
            if(casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
        }while(cont_jogadas <= 9);
        tabuleiro(casas);

        printf("\n\n");

        if(cont_jogadas==10){
            printf("Voces empataram!\n\n");
            vez = rand()%2;
        }if(cont_jogadas==11){;
            printf("%s ganhou!!!\n\n", p1 );
            pontox = pontox+1;
            vez = 0;
        }if(cont_jogadas==12){
            printf("%s ganhou!!!\n\n", p2);
            pontoy = pontoy+1;
            vez = 1;
        }
        printf ("%s tem %d pontos\n",p1, pontox);
        printf ("%s tem %d pontos\n\n",p2, pontoy);

        jogarnovamente();
        scanf("%s", &res);
        if(res == 'm')
        {
            system("cls");
            pontox = 0;
            pontoy = 0;
            main();
        }
        else if(res == 'y')
        {
            system("cls");
            goto comeco;
        }
        else
        {
            exit(0);
        }
    }

//---------------------------------------------------------//

void jogo_forca(){
    SetConsoleTitle("Jogo da forca");

    printf("EM BREVE!");
    getch();
    system("cls");
    main();

}

//---------------------------------------------------------//

void blackjack(){
    SetConsoleTitle("Blackjack");

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    char escolha[20];
    char resposta;

    int i = 0, j, escolhacartas;
    int cartas[5];
    char c1 = 218;
    char c2 = 196;
    char c3 = 191;
    char c4 = 179;
    char c5 = 192;
    char c6 = 217;
    int rodada = 0;
    char cartaletra;

    char nomep1[25];
    char nomep2[25];

    int somafinalp1 = 0;
    int somafinalp2 = 0;

    int pontop1 = 0;
    int pontop2 = 0;

    srand(time(NULL));

    printf("Digite o nome do jogador um: ");
    scanf("%s", &nomep1);
    system("cls");
    printf("Digite o nome do jogador dois: ");
    scanf("%s", &nomep2);

    system("cls");
    cblackjack: ;

    if(rodada <= 0)
    {
        textocustom(nomep1, LimeFore);
        printf(" escolha o tanto de cartas que voce quer [ 1 - 5 ]: ");
        scanf("%d", &escolhacartas);

        if(escolhacartas < 1 || escolhacartas > 5)
        {
            system("cls");
            goto cblackjack;
        }
    }
    else
    {
        printf("\nPedir quantas cartas [ 1 - 3 ] ? ");
        scanf("%d", &escolhacartas);

        if(escolhacartas > 3)
        {
            escolhacartas = 3;
        }
        else if(escolhacartas < 1)
        {
            escolhacartas = 1;
        }

    }

    printf("\n\n");

    for (i = 0; i < escolhacartas; i++) // gera as cartas
    {
        cartas[i] = (rand() % 11)+1;
        if(cartas[i] > 9)
        {
            somafinalp1 += 10;
        }
        else
        {
            somafinalp1 += cartas[i];
        }
    }

    printf("Suas cartas sao: \n");

    for(i = 0; i < escolhacartas; i++) // printa as cartas que voce recebeu na rodada
    {

        if(cartas[i] == 1 || cartas[i] == 10 || cartas[i] == 11 || cartas[i] == 12)
        {
            if(cartas[i] == 1)
            {
                cartaletra = 'A';
            }
            else if(cartas[i] == 10)
            {
                cartaletra = 'J';
            }
            else if(cartas[i] == 11)
            {
                cartaletra = 'Q';
            }
            else if(cartas[i] == 12)
            {
                cartaletra = 'K';
            }

            printf("\n\t%c%c%c%c%c%c%c\n" , c1, c2, c2, c2, c2, c2, c3);
            printf("\t%c%c    %c\n"      , c4, cartaletra, c4);
            printf("\t%c     %c\n"       , c4, c4);
            printf("\t%c     %c\n"       , c4, c4);
            printf("\t% c    %c%c\n"      , c4, cartaletra, c4);
            printf("\t%c%c%c%c%c%c%c\n"   , c5, c2, c2, c2, c2, c2, c6);
        }
        else
        {
            printf("\n\t%c%c%c%c%c%c%c\n" , c1, c2, c2, c2, c2, c2, c3);
            printf("\t%c%d    %c\n"      , c4, cartas[i], c4);
            printf("\t%c     %c\n"       , c4, c4);
            printf("\t%c     %c\n"       , c4, c4);
            printf("\t%c    %d%c\n"      , c4, cartas[i], c4);
            printf("\t%c%c%c%c%c%c%c\n"   , c5, c2, c2, c2, c2, c2, c6);
        }
    }

    if(somafinalp1 < 21) // se o jogador 1 tiver ao total menos de 21 pontos, mostra opções
    {
        printf("\nVoce esta com %d pontos, o que deseja fazer? ", somafinalp1);

        continuarblackjack();

        printf("\n");

        scanf("%s", &escolha);

        if(escolha[2] == 'd' && somafinalp1 <= 21) // pedir
        {
            rodada++;
            goto cblackjack;
        }
        if(escolha[2] == 'r') // parar
        {
            system("cls");
            rodada = 0;
        }
        if(escolha[2] == 's') // desistir
        {
            printf("tchau");
        }
    }
    else if(somafinalp1 > 21)
    {
        printf("\n\nVoce");
        textocustom(" PERDEU ", AquaFore);
        printf("com %d pontos", somafinalp1);

        Sleep(2500);

        system("cls");
    }
    else if(somafinalp1 == 21)
    {
        textocustom(nomep1, LimeFore);
        printf(" conseguiu o maximo de pontos, a vez vai ser passada...");
        Sleep(2000);
        system("cls");
    }

    // player dois ---------------------------------------------------------------------]

    rodada = 0;

    c2blackjack: ;

    if(rodada <= 0)
    {
        textocustom(nomep2, RedFore);
        printf(" escolha o tanto de cartas que voce quer [ 1 - 5]: ");
        scanf("%d", &escolhacartas);

        if(escolhacartas < 1 || escolhacartas > 5)
        {
            system("cls");
            goto c2blackjack;
        }
    }
    else
    {

        printf("\nPedir quantas cartas [ 1 - 3]? ");
        scanf("%d", &escolhacartas);

        if(escolhacartas > 3)
        {
            escolhacartas = 3;
        }
        else if(escolhacartas < 1)
        {
            escolhacartas = 1;
        }
    }

    printf("\n\n");

    for (i = 0; i < escolhacartas; i++) // gera as cartas
    {
        cartas[i] = (rand() % 11)+1;
        if(cartas[i] > 9)
        {
            somafinalp2 += 10;
        }
        else
        {
            somafinalp2 += cartas[i];
        }
    }

    printf("Suas cartas sao: \n");

    for(i = 0; i < escolhacartas; i++) // printa as cartas que voce recebeu na rodada
    {

        if(cartas[i] == 1 || cartas[i] == 10 || cartas[i] == 11 || cartas[i] == 12)
        {
            if(cartas[i] == 1)
            {
                cartaletra = 'A';
            }
            else if(cartas[i] == 10)
            {
                cartaletra = 'J';
            }
            else if(cartas[i] == 11)
            {
                cartaletra = 'Q';
            }
            else if(cartas[i] == 12)
            {
                cartaletra = 'K';
            }

            printf("\n\t%c%c%c%c%c%c\n" , c1, c2, c2, c2, c2, c3);
            printf("\t%c%c   %c\n"      , c4, cartaletra, c4);
            printf("\t%c    %c\n"       , c4, c4);
            printf("\t%c   %c%c\n"      , c4, cartaletra, c4);
            printf("\t%c%c%c%c%c%c\n"   , c5, c2, c2, c2, c2, c6);
        }
        else
        {
            printf("\n\t%c%c%c%c%c%c\n" , c1, c2, c2, c2, c2, c3);
            printf("\t%c%d   %c\n"      , c4, cartas[i], c4);
            printf("\t%c    %c\n"       , c4, c4);
            printf("\t%c   %d%c\n"      , c4, cartas[i], c4);
            printf("\t%c%c%c%c%c%c\n"   , c5, c2, c2, c2, c2, c6);
        }
    }

    if(somafinalp2 < 21)
    {
        printf("Voce esta com %d pontos, o que deseja fazer? ", somafinalp2);

        continuarblackjack();
        printf("\n");

        scanf("%s", &escolha);

        if(escolha[2] == 'd' && somafinalp2 <= 21) // pedir
        {
            rodada++;
            goto c2blackjack;
        }
        else if(escolha[2] == 'r') // parar
        {
            system("cls");

            if(somafinalp1 > somafinalp2)
            {
                if(somafinalp1 <= 21)
                {
                    system("cls");
                    telacustom("PLAYER 1 GANHOU", LimeFore);
                    pontop1++;
                    Sleep(1000);
                }
                else
                {
                    system("cls");
                    telacustom("PLAYER 2 GANHOU", RedFore);
                    pontop2++;
                    Sleep(1000);
                }
            }
            else if(somafinalp2 > somafinalp1)
            {
                if(somafinalp2 <= 21)
                {
                    system("cls");
                    telacustom("PLAYER 2 GANHOU", RedFore);
                    pontop2++;
                    Sleep(1000);
                }
                else
                {
                    system("cls");
                    {
                        telacustom("PLAYER 1 GANHOU", LimeFore);
                        pontop1++;
                        Sleep(1000);
                    }
                }
            }
            else
            {
                system("cls");
                telacustom("   EMPATARAM   ", YellowFore);
                Sleep(1000);
            }
        }
        else if(escolha[2] == 's') // desistir
        {
            printf("tchau");
        }
    }
    else if(somafinalp2 > 21)
    {
        printf("\n\nVoce");
        textocustom(" PERDEU ", AquaFore);
        printf("com %d pontos", somafinalp2);

        Sleep(2500);

        system("cls");

        if(somafinalp1 <= 21)
        {
            system("cls");
            telacustom("PLAYER 1 GANHOU", LimeFore);
            Sleep(1000);
            pontop1++;
        }
        else
        {
            telacustom("   EMPATARAM   ", YellowFore);
            Sleep(1000);
        }
    }
    else if(somafinalp2 == 21)
    {
        textocustom(nomep2, RedFore);
        printf(" conseguiu o maximo de pontos!!");

        Sleep(2000);

        system("cls");

        if(somafinalp1 == somafinalp2)
        {
            telacustom("   EMPATARAM   ", YellowFore);
            Sleep(1000);
        }
        else if(somafinalp1 < somafinalp2)
        {
            telacustom("PLAYER 2 GANHOU", RedFore);
        }
    }

    printf("\n\n\tPlacar: \n\n");

    printf("\t%s: ", nomep1);
    numerocustom(pontop1, LimeFore);
    printf("\n");
    printf("\t%s: ", nomep2);
    numerocustom(pontop2, RedFore);

    printf("\n\n\n");
    jogarnovamente();
    scanf("%s", &resposta);

    if(resposta == 'y')
    {
        system("cls");
        rodada = 0;
        somafinalp1 = 0;
        somafinalp2 = 0;
        goto cblackjack;
    }
    else if(resposta == 'm')
    {
        pontop1 = 0;
        rodada = 0;
        pontop2 = 0;
        system("cls");
        main();
    }
    else
    {
        exit(0);
    }
}

//---------------------------------------------------------//

void pedrapapeltesoura(){



    SetConsoleTitle("Pedra Papel ou Tesoura");

    int r;
    int esc;

    //PEDRA 1
    //PAPEL 2
    //TESOURA 3

    srand(time(NULL));
    r = ("%d ", rand() % 3)+1;

    printf("1 - Pedra\n2 - Papel\n3 - Tesoura\n");
    printf("Escolha: ");
    scanf("%d", &esc);

    system("cls");

    printf("\nEsperando resposta do computador...");

    Sleep(1050);

    char e = 130;

    printf("\n\nCom base na sua escolha o resultado %c que", e);

    Sleep(850);

    if(esc == 1 && r == 3 || esc == 2 && r == 1 || esc == 3 && r == 2)
    {
        printf("\n\n\n");

        telaganhou();

        printf("\n\n\n");

        placarppt();

        printf("\n");

        char resposta;
        jogarnovamente();
        scanf("%s", &resposta);

        if(resposta == 'y')
        {
            system("cls");
            pedrapapeltesoura();
        }
        else if(resposta == 'm')
        {
            placarpptb = 0;
            placarpptp = 0;
            system("cls");
            main();
        }
        else
        {
            exit(0);
        }
    }
    else if(esc == 1 && r == 2 || esc == 2 && r == 3 || esc == 3 && r == 1)
    {
        printf("\n\n\n");

        telaperdeu();

        printf("\n\n\n");

        placarppt();

        printf("\n");

        char resposta;
        jogarnovamente();
        scanf("%s", &resposta);

        if(resposta == 'y')
        {
            system("cls");
            pedrapapeltesoura();
        }
        else if(resposta == 'm')
        {
            placarpptb = 0;
            placarpptp = 0;
            system("cls");
            main();
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        printf("\n\n\n");

        telaempatou();

        printf("\n\n\n");

        placarppt();

        printf("\n");

        char resposta;
        jogarnovamente();
        scanf("%s", &resposta);

        if(resposta == 'y')
        {
            system("cls");
            pedrapapeltesoura();
        }
        else if(resposta == 'm')
        {
            placarpptb = 0;
            placarpptp = 0;
            system("cls");
            main();
        }
        else
        {
            exit(0);
        }
    }
}

void creditos(){
    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTitle("Creditos");

    SetConsoleTextAttribute(cmd, LimeFore);
    printf("\n\tCREDITOS: \n\n");
    SetConsoleTextAttribute(cmd, WhiteFore);

    printf("\t- Gustavo Walk \n");
    printf("\t- Gabriel Menegasso \n");
    printf("\t- Luis Gustavo\n");
    getch();
    system("cls");
    main();
}

void jogo_memoria(){

    handle_t cmd;
    cmd = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTitle("Jogo da memoria");

    int i = 0, j = 0, acertos = 0;
    char l = 130;
    char c;
    int numeros[5];
    int respostas[5];
    int round = 1;
    int pontos = 0;
    char esc;
    int dif = 0;

    printf ("Neste jogo vai ser gerado 5 numeros aleatorios entre 1 e 15.\n\n");

    printf ("Decore eles e depois de 5 segundos digite na ordem correta.\n\n");

    printf("A cada rodada o numero maximo aumenta de 10 em 10.\n\n");

    printf ("Pressione ");

    SetConsoleTextAttribute(cmd, LimeFore);

    printf("ENTER ");

    SetConsoleTextAttribute(cmd, WhiteFore);

    printf(" para iniciar");

    do{
        c = getch();
    }while (c != 13);

    cmemoria: ;

    srand(time(NULL));

    for (i = 0; i<5; i++)
    {
        numeros[i] = (rand() % 15 + dif)+1;
    }

    if(pontos <= 2)
    {
        j = 10;
    }
    else if(pontos > 2)
    {
        j = 5;
    }
    else if(pontos > 5)
    {
        j = 3;
    }
    else if(pontos >= 8)
    {
        j = 1;
    }

    do{

        system("cls");

        printf("Rodada: %d\n", round);

        printf("\nDecore os numeros abaixo em ");
        SetConsoleTextAttribute(cmd, FuchsiaFore);
        printf("%d", j);
        SetConsoleTextAttribute(cmd, WhiteFore);
        printf(" segundos\n\n\n");
        j--;

        for(i = 0; i < 5; i++)
        {
            printf("%d\t", numeros[i]);
        }
        Sleep(1000);

    }while(j > 0);


    system("cls");
    printf("\nDigite os numeros na ordem que apareceram\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("\t%d numero: ", i + 1);
        scanf("%d", &respostas[i]);

        if(numeros[i] == respostas[i])
        {
            acertos++;
        }
    }

    if(acertos == 5)
    {
        printf("\nParabens, sua memoria %c muito boa!", l);
        printf("\nVeja os numeros exibidos.\n\n");

        acertos = 0;

        for(i = 0; i < 5; i++)
        {
            printf("%d\t", numeros[i]);
        }
        printf("\n\n");

        getch();

        proximarodada();
        scanf("%s", &esc);

        if(esc == 'y')
        {
            system("cls");
            acertos = 0;
            dif = dif + 10;
            pontos = pontos +1;
            round++;
            goto cmemoria;
        }
        else if(esc == 'm')
        {
            main();
        }
        else
        {
            exit(0);
        }

    }
    else
    {
        printf("\nParece que sua memoria nao %c tao boa, continue tentando!", l);
        printf("\nCompare os numeros.\n\n");
        printf("Os seus: ");

        for(i = 0; i < 5; i++)
        {
            printf("\t%d", respostas[i]);
        }

        printf("\n\n");

        printf("Os corretos: ");

        for(i = 0; i < 5; i++)
        {
            printf("\t%d", numeros[i]);
        }
        printf("\n\n");

        getch();

        jogarnovamente();
        scanf("%s", &esc);

        if(esc == 'y')
        {
            system("cls");
            dif = 0;
            acertos = 0;
            pontos = 0;
            round = 1;
            goto cmemoria;
        }
        else if(esc == 'm')
        {
            main();
        }
        else
        {
            exit(0);
        }
    }

}
