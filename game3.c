#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void tictactoe();
void rockpaperscissors();
void numberguessing();
void showhighscore();
int game_id = 1, best_num = 0,q;
char name1[50][19];
void addplayer();

int score[3][50][1];

int main()
{
    printf("\nenter player:");

    scanf("%s", name1[game_id]);
    printf("your game id is %d", game_id);
    game_id++;
    printf("\nenter player:");
    scanf("%s", name1[game_id]);

    printf("\nyour game id is %d\n", game_id);
    for (int o = 0; o < 3; o++)
    {
        for (int l = 0; l < 50; l++)
        {
            for (int c = 0; c < 1; c++)
            {
                score[o][l][c] = 0;
            }
        }
    }
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\n            MINI ARCADE SYSTEM (C) \n");

    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\n Welcome player !\n select an option:\n");

w:

    printf("0.Add player \n1. play Rock-paper-Scissors\n2. Play Tic-Tac-Toe\n3. Play Number Guessing\n4. View High Scores\n 5. Exit");
    printf("\nEnter your choice:");
    int cho;
    scanf("%d", &cho);
    char menu1[5];
    switch (cho)
    {
    case 0:
        addplayer();
        printf(" \n wnat to go back then prees \"b\"\n");

        scanf("%s", menu1);
        if (menu1[0] == 'b')
            goto w;
        break;

    case 1:
        rockpaperscissors();
        printf(" \n wnat to go back then prees \"b\"\n");

        scanf("%s", menu1);
        if (menu1[0] == 'b')
            goto w;
        break;
    case 2:
        tictactoe();
          for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\n         TIC-TAC-TOE RANKING\n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf(" \nGame : Tic-Tac-Toe\n");
    for (int i = 1; i <= q; i++)
    {
        printf(" %s     %d\n", name1[i], score[1][i][0]);
    }
        printf(" \n wnat to go back then prees \"b\"\n");

        scanf("%s", menu1);
        if (menu1[0] == 'b')
            goto w;
        break;
    case 3:
        numberguessing();
        printf(" \n wnat to go back then prees \"b\"\n");

        scanf("%s", menu1);
        if (menu1[0] == 'b')
            goto w;
        break;
    case 4:
        showhighscore();
        printf(" \n wnat to go back then prees \"b\"\n");
        scanf("%s", menu1);
        if (menu1[0] == 'b')
            goto w;

        break;
    case 5:
        return 0;
        break;

    default:
        break;
    }

    return 0;
}
void numberguessing()
{
    printf("Enter your game id:");
    int id, x;
    scanf("%d", &id);
    x = id;
    printf("you salect tic tac tor game \n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\n               NUMBER GUESSING GAME\n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }

    srand(time(0));
    int randomnumber = (rand() % 100) + 1;
    int gss;
    printf(" enter your number: ");
    scanf("%d", &gss);
    int att = 1;
    while (gss != randomnumber)
    {
        if (gss > randomnumber)
        {
            att++;
            printf("enter small number");
            scanf("%d", &gss);
        }
        if (gss < randomnumber)
        {
            att++;
            printf("enter greter number");
            scanf("%d", &gss);
        }
    }
    printf("cong\n");
    score[2][id][0] += 20 - att;
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\n         NUMBER GUESSING GAME RANKING\n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf(" \nGame : Tic-Tac-Toe\n");
    for (int i = 1; i <= x; i++)
    {
        printf(" %s     %d\n", name1[i], score[2][i][0]);
    }
}
void tictactoe()
{
    printf("you salect tic tac tor game \n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\n                         TIC- TAC-TOE\n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\nenter your game id ");
    int id;
    scanf("%d", &id);
    printf(" enter your game id2 ");
    int id2;
    scanf("%d", &id2);
    q = id2;
    char arr[3][3];
    for (int i = 1; i < 10; i++)
    {
        printf("%d", i);
        if (i % 3 == 0)
            printf("\n");
        else
            printf("|");
    }
    int l = 1;
    int n = 0, m = 0;

    int p1_i = 0, p2_i = 0;
    int p1[5], p2[4];
    int k = 0;
    for (k; k < 9; k++)
    {
        int l = 0;
        if (k % 2 == 0 && k < 9)
        {
            printf("enter player 1 your cohice:\n");
            scanf("%d", &p1[p1_i]);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    l++;
                    if (p1[p1_i] == l)
                    {
                        n = i;
                        m = j;
                        break;
                    }
                }
            }
            arr[n][m] = 'X';

            p1_i++;
        }
        if (k % 2 != 0 && k < 9)
        {
            printf("enter player 2 your cohice:\n");
            scanf("%d", &p2[p2_i]);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    l++;
                    if (p2[p2_i] == l)
                    {
                        n = i;
                        m = j;
                        break;
                    }
                }
            }
            arr[n][m] = 'O';

            p2_i++;
        }
        for (int c = 0; c < 3; c++)
        {
            if (arr[c][0] == arr[c][1] && arr[c][1] == arr[c][2])
            {
                if (arr[c][0] == 'X')
                {
                    printf("player 1 win1");
                    score[1][id][0] += 20;
                    return;
                }
                else if (arr[c][0] == 'O')
                {
                    printf("player 2 win");
                    score[1][id2][0] += 20;
                    return;
                }
            }
        }
        for (int c = 0; c < 3; c++)
        {
            if (arr[0][c] == arr[1][c] && arr[2][c] == arr[0][c])
            {
                if (arr[0][c] == 'X')
                {
                    printf("player 1 win2");
                    score[1][id][0] += 20;
                    return;
                }
                else if (arr[0][c] == 'O')
                {
                    printf("player 2 win");
                    score[1][id2][0] += 20;
                    return;
                }
            }
        }

        if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        {
            if (arr[0][0] == 'X')
            {
                printf("player 1 win3");
                score[1][id][0] += 20;
                return;
            }
            else if (arr[0][0] = 'O')
            {
                printf("player 2 win");
                score[1][id2][0] += 20;
                return;
            }
        }
        else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        {
            if (arr[2][0] == 'X')
            {
                printf("player 1 win4");
                score[1][id][0] += 20;
                return;
            }
            else if (arr[2][0] == 'O')
            {
                printf("player 2 win\n");
                score[1][id2][0] += 20;
                return;
            }
        }
    }
   printf("draw \n");
}
void rockpaperscissors()
{
    printf(" enter your id :");
    int id, id2;
    scanf("%d", &id);
    printf("enter your id2 :");
    scanf("%d", &id2);
    printf("you salect rock paper scissors game \n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\n                      ROCK-PAPER-SCISSORS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }

    printf("\nR = rock\nP=paper\nS=scissors\n");
    char n[2];
    char m[2];
    printf(" player 1 enter your choice: ");
    scanf("%s", &n[0]);
    printf(" player 2 enter your choice: ");
    scanf("%s", &m[0]);
    if (n[0] == m[0])
    {
        printf("draw \n");
        score[0][id][0] += 10;
        score[0][id2][0] += 10;
        goto q;
    }
    if ((n[0] == 'P' && m[0] == 'R') || (n[0] == 'R' && m[0] == 'S') ||
        (n[0] == 'S' && m[0] == 'P'))
    {
        printf("player 1 win");
        score[0][id][0] += 20;
    }
    else
    {
        printf("player 2 win");
        score[0][id2][0] += 20;
    }
    q:
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf("\n         ROCK-PAPER-SCISSORS RANKING\n");
    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }
    printf(" \nGame : Rock-Paper-scissors\n");
    for (int i = 1; i <= id2; i++)
    {
        printf(" %s     %d\n", name1[i], score[0][i][0]);
    }
}
void showhighscore()
{
    int id = 0, id1 = 0, id2 = 0;
    int highnum = 0;
    for (int i = 0; i < 50; i++)
    {
        if (score[0][i][0] > highnum)
        {
            highnum = score[0][i][0];
            id = i;
        }
    }
    printf("high score of Rock paper  %d by %s\n", highnum, name1[id]);

    int highg = 0;
    for (int j = 0; j < 50; j++)
    {
        if (score[2][j][0] > highg)
        {
            highg = score[2][j][0];
            id1 = j;
        }
    }
    printf("high score of number guess %d by %s\n", highg, name1[id1]);
    int hightic = 0;
    for (int i = 0; i < 50; i++)
    {
        if (score[1][i][0] > hightic)
        {
            hightic = score[1][i][0];
            id2 = i;
        }
    }
    printf(" high score of tic tac toe is %d by %s\n", hightic, name1[id2]);
    printf( "hello");
}
void addplayer()
{
    printf("\nenter player:");
   game_id++;
    scanf("%s", name1[game_id]);
    printf("your game id is %d", game_id);
    game_id++;
    printf("\nenter player:");
    scanf("%s", name1[game_id]);

    printf("\nyour game id is %d", game_id);
}