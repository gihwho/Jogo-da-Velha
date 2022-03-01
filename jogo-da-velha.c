//PUC-SP 2021
//projeto feito em aula
#include <stdio.h>

void zeraMatriz ();
void mostraMatriz ();
void JogaVoce ();
char verificaFim ();
void jogaComputI ();

char Matriz[3][3];    //variavel GLOBAL

int main ()
{
    char ok;
    int vez = 0;    //1 = voce, 2 = computador
    printf ("JOGO DA VELHA Voce X Computador\n");

    ok = ' ';
    while (vez != 1 && vez != 2)
    {
        printf ("Joga primeiro: 1 = voce, 2 = computador: ");
        scanf ("%d", &vez);
    }
    zeraMatriz ();

    do
    {
        if (vez == 1)
        {
            JogaVoce();
            ok = verificaFim();
            if (ok != ' ')
                break;    //existe vencedor ou empatou
            vez = 2;
        }
        if (vez == 2)
        {
            jogaComputI();
            ok = verificaFim();
            if (ok != ' ')
                break;    //existe vencedor
            vez = 1;
        }
        mostraMatriz();

    } while (ok == ' ');

    //resultado
    printf ("\n===========\n");
    mostraMatriz();
    if (ok == 'X')
        printf ("PARABENS, Voce ganhou\n");
    else if (ok == '0')
        printf ("Sinto muito, o computador ganhou...\n");
    else
        printf ("EMPATE\n");
    printf ("===========\n\n");
}

void zeraMatriz()    //função sem argumento porque Matriz é VARIAVEL GLOBAL
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            Matriz[i][j] = ' ';
}

void mostraMatriz()
{
    int t;
    for (t = 0; t < 3; t++)
    {
        printf (" %c | %c | %c ", Matriz[t][0], Matriz[t][1], Matriz[t][2]);
        if (t != 2)
            printf ("\n---|---|---\n");
    }
    printf ("\n");
}

void JogaVoce()
{
    int x, y;
    printf ("Digite as coordenadas (separadas por espaco): ");
    scanf ("%d %d", &x, &y);
    x--;
    y--;
    if (Matriz[x][y] != ' ')
    {
        printf ("Posicao invalida, digite novamente\n");
        JogaVoce();
    }
    else
        Matriz[x][y] = 'X';
}

void jogaComputI()
{
    //COMPUTADOR VERIFICA SE PODE GANHAR
    int t;
    for (t = 0; t < 3; t++)   //verifica linhas
    {
        if (Matriz[t][0] == '0' && Matriz[t][1] == '0' && Matriz[t][2] == ' ')
        {
            Matriz[t][2] = '0';
            return;
        }
        if (Matriz[t][0] == '0' && Matriz[t][1] == ' ' && Matriz[t][2] == '0')
        {
            Matriz[t][1] = '0';
            return;
        }
        if (Matriz[t][0] == '0' && Matriz[t][1] == '0' && Matriz[t][2] == ' ')
        {
            Matriz[t][2] = '0';
            return;
        }
    }

    for (t = 0; t < 3; t++)       //verifica colunas
    {
        if (Matriz[0][t] == '0' && Matriz[1][t] == '0' && Matriz[2][t] == ' ')
        {
            Matriz[2][t] = '0';
            return;
        }
        if (Matriz[0][t] == '0' && Matriz[1][t] == ' ' && Matriz[2][t] == '0')
        {
            Matriz[1][t] = '0';
            return;
        }
        if (Matriz[0][t] == ' ' && Matriz[1][t] == '0' && Matriz[2][t] == '0')
        {
            Matriz[0][t] = '0';
            return;
        }

    }

    //verifica uma diagonal
    if (Matriz[0][0] == '0' && Matriz[1][1] == '0' && Matriz[2][2] == ' ')
    {
        Matriz[2][2] = '0';
        return;
    }
    if (Matriz[0][0] == '0' && Matriz[1][1] == ' ' && Matriz[2][2] == '0')
    {
        Matriz[1][1] = '0';
        return;
    }
    if (Matriz[0][0] == ' ' && Matriz[1][1] == '0' && Matriz[2][2] == '0')
    {
        Matriz[0][0] = '0';
        return;
    }

    //verifica outra diagonal
    if (Matriz[0][2] == '0' && Matriz[1][1] == '0' && Matriz[2][1] == ' ')
    {
        Matriz[2][1] = '0';
        return;
    }
    if (Matriz[0][2] == '0' && Matriz[1][1] == ' ' && Matriz[2][1] == '0')
    {
        Matriz[1][1] = '0';
        return;
    }
    if (Matriz[0][2] == ' ' && Matriz[1][1] == '0' && Matriz[2][1] == '0')
    {
        Matriz[0][2] = '0';
        return;
    }

    //COMPUTADOR VERIFICA SE DEVE IMPEDIR GANHO DO OUTRO ADVERSÁRIO

    for (t = 0; t < 3; t++)   //verifica as linhas
    {
        if (Matriz[t][0] == 'X' && Matriz[t][1] == 'X' && Matriz[t][2] == ' ')
        {
            Matriz[t][2] = '0';
            return;
        }
        if (Matriz[t][0] == 'X' && Matriz[t][1] == ' ' && Matriz[t][2] == 'X')
        {
            Matriz[t][1] = '0';
            return;
        }
        if (Matriz[t][0] == 'X' && Matriz[t][1] == 'X' && Matriz[t][2] == ' ')
        {
            Matriz[t][2] = '0';
            return;
        }
    }

    for (t = 0; t < 3; t++)       //verifica colunas
    {
        if (Matriz[0][t] == 'X' && Matriz[1][t] == 'X' && Matriz[2][t] == ' ')
        {
            Matriz[2][t] = '0';
            return;
        }
        if (Matriz[0][t] == 'X' && Matriz[1][t] == ' ' && Matriz[2][t] == 'X')
        {
            Matriz[1][t] = '0';
            return;
        }
        if (Matriz[0][t] == ' ' && Matriz[1][t] == 'X' && Matriz[2][t] == 'X')
        {
            Matriz[0][t] = '0';
            return;
        }
    }

        //verifica uma diagonal
    if (Matriz[0][0] == 'X' && Matriz[1][1] == 'X' && Matriz[2][2] == ' ')
    {
        Matriz[2][2] = '0';
        return;
    }
    if (Matriz[0][0] == 'X' && Matriz[1][1] == ' ' && Matriz[2][2] == 'X')
    {
        Matriz[1][1] = '0';
        return;
    }
    if (Matriz[0][0] == ' ' && Matriz[1][1] == 'X' && Matriz[2][2] == 'X')
    {
        Matriz[0][0] = '0';
        return;
    }

    //verifica outra diagonal
    if (Matriz[0][2] == 'X' && Matriz[1][1] == 'X' && Matriz[2][1] == ' ')
    {
        Matriz[2][1] = '0';
        return;
    }
    if (Matriz[0][2] == 'X' && Matriz[1][1] == ' ' && Matriz[2][1] == 'X')
    {
        Matriz[1][1] = '0';
        return;
    }
    if (Matriz[0][2] == ' ' && Matriz[1][1] == 'X' && Matriz[2][1] == 'X')
    {
        Matriz[0][2] = '0';
        return;
    }

    //COMPUTADOR ESCOLHE A MELHOR JOGADA OU GERA EMPATE
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (Matriz[i][j] == ' ')
                break;
        if (Matriz[i][j] == ' ')
            break;
    }
    if (i = 3 && j == 3)
        return 'e';    //empate
    Matriz[i][j] = '0';
}

char verificaFim()
{
    int t;
    for (t = 0; t < 3; t++)    //verifica as linhas
        if (Matriz[t][0] == Matriz[t][1] &&
            Matriz[t][0] == Matriz[t][2])
            return Matriz[t][0];

    for (t = 0; t < 3; t++)   //verifica as colunas
        if (Matriz[0][t] == Matriz[1][t] &&
            Matriz[0][t] == Matriz[2][t])
            return Matriz[0][t];

    for (t = 0; t < 3; t++)   //verifica uma diagonal
        if (Matriz[0][0] == Matriz[1][1] &&
            Matriz[0][0] == Matriz[2][2])
            return Matriz[0][0];

    for (t = 0; t < 3; t++)   //verifica outra diagonal
        if (Matriz[0][2] == Matriz[1][1] &&
            Matriz[0][2] == Matriz[2][0])
            return Matriz[0][2];

    //Testa empate veirificando se deixou algum espaço em branco
    int i, j;
    t = -1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (Matriz[i][j] == ' ')
            {
                t = 0;
                break;
            }

    if (t == -1)
        return 'e';   //empate

    return ' ';      //nenhum vencedor
}