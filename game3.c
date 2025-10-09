#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void tictactoe();
void rockpaperscissors();
void numberguessing();
void showhighscore();
void resetscore();
void addplayer();
FILE *as;
int sccc[3][50][1];
int best_num = 0;
char name1[50][19];

//  score[game ][ id ][ score ]
int score[3][50][1];
int lastid;
int game_id = 1;
int main()
{
   int file_game, file_id, temp_score;
    
    char temp_name[19]; 
    as = fopen("save_score.txt", "r");

    if (as == NULL) {
        perror("Error opening save_score.txt for reading. Starting fresh.");
        game_id = 1; 
    } else {
        int max_id = 0;

    
        while (1)
        {
        
            int read_count = fscanf(as, "%s %d %d %d", temp_name, &file_game, &file_id, &temp_score);

        
            if (read_count != 4)
            {
                break;
            }
            

            
            if ((file_game >= 0 && file_game < 3) ||( file_id >= 1 && file_id < 50))
            {
                
                score[file_game][file_id][0] = temp_score;

                
                strcpy(name1[file_id], temp_name); 

                
                printf("Loaded -> Name: %s, Game: %d, ID: %d, Score: %d \n", name1[file_id], file_game, file_id, temp_score);

                
                
                    max_id = file_id;
                
            }
        }
        fclose(as);
        // Set game_id to the NEXT available ID (1 + highest ID read)
        game_id = max_id + 1; 
    }
    // --- EN0

    
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

        printf("0.Add player \n1. play Rock-paper-Scissors\n2. Play Tic-Tac-Toe\n3. Play Number Guessing\n4. View High Scores\n5. Reset score\n6. Exit");
        printf("\nEnter your choice:");
        int choice;
        scanf("%d", &choice);
        char menu1[1];

        switch (choice)
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
            printf("\n");
            for (int i = 0; i < 50; i++)
            {
                printf("=");
            }
            printf("\n         TIC-TAC-TOE SCORE CARD\n");
            for (int i = 0; i < 50; i++)
            {
                printf("=");
            }
            printf(" \nGame : Tic-Tac-Toe\n");
            printf("       NAME       SCORE\n");
            for (int i = 1; i < game_id; i++)
            {
                printf(" %9s %4d\n", name1[i], score[1][i][0]);
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
        case 6:
            lastid = game_id;
              int game_counter = 0; 
        as = fopen("save_score.txt", "w");
        
        if (as != NULL) {
            
            for (int i = 0; i < 3; i++)
            {
            
                for (int j = 1; j < game_id; j++)
                {
                
                    fprintf(as, " %s %d %d %d\n",name1[j], game_counter, j, score[i][j][0]);
                }
                game_counter++;
            }
            fclose(as);
        }
            return 0;
            break;

        case 5:
            resetscore();
            printf(" \n wnat to go back then prees \"b\"\n");
            scanf("%s", menu1);
            if (menu1[0] == 'b')
                goto w;

            break;

        default:
            break;
        }

        return 0;
    }
    void numberguessing()
    {

        printf("you salect number guessing  game \n");
        for (int i = 0; i < 50; i++)
        {
            printf("=");
        }
        printf("\n               NUMBER GUESSING GAME\n");
        for (int i = 0; i < 50; i++)
        {
            printf("=");
        }
        printf("\n");
        printf("Enter your game id:");
        int id;
        scanf("%d", &id);

        srand(time(0));
        int randomnumber = (rand() % 100) + 1;
        int guess;
        printf(" enter your number: ");
        scanf("%d", &guess);
        int att = 1;
        while (guess != randomnumber)
        {
            if (guess > randomnumber)
            {
                att++;
                printf("enter small number");
                scanf("%d", &guess);
            }
            if (guess < randomnumber)
            {
                att++;
                printf("enter greter number");
                scanf("%d", &guess);
            }
        }
        printf("cong\n");
        score[2][id][0] += 20 - att;
        for (int i = 0; i < 50; i++)
        {
            printf("=");
        }
        printf("\n         NUMBER GUESSING GAME  SCORE CARD\n");
        for (int i = 0; i < 50; i++)
        {
            printf("=");
        }
        printf(" \nGame : Number Guessing \n");
        printf("        NAME         SCORE\n");
        for (int i = 1; i < game_id; i++)
        {
            printf(" %9s %9d\n", name1[i], score[2][i][0]);
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
        printf("\n");
        printf(" enter your game id: ");
        int id;
        scanf("%d", &id);
        printf(" enter your game id2: ");
        int id2;
        scanf("%d", &id2);
        char arr[3][3];
        for (int i = 1; i < 10; i++)
        {
            printf("%d", i);
            if (i % 3 == 0)
                printf("\n");
            else
                printf("|");
        }

        int n = 0, m = 0;

        int p1_i = 0, p2_i = 0;
        int p1[5], p2[4];

        for (int k = 0; k < 9; k++)
        {
            int l = 0;
            if (k % 2 == 0)
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
                        if (p1[p1_i] >= 10)
                        {
                            printf(" invaild input ");
                            goto a;
                        }
                    }
                }
                arr[n][m] = 'X';

                p1_i++;
            }
            if (k % 2 != 0)
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
        printf("draw ");
        score[1][id][0] += 10;
        score[1][id2][0] += 10;
    a:;
    }
    void rockpaperscissors()
    {

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
        printf("\n");
        printf(" enter your id: ");
        int id, id2;
        scanf("%d", &id);
        printf("enter your id2: ");
        scanf("%d", &id2);
    r:
        printf("\nR = rock\nP=paper\nS=scissors\n");
        char n[2];
        char m[2];
        printf(" player 1 enter your choice: ");
        scanf("%s", &n[0]);
        printf(" player 2 enter your choice: ");
        scanf("%s", &m[0]);
        if ((n[0] != 'R' && n[0] != 'P' && n[0] != 'S') && (m[0] != 'R' && m[0] != 'S' && m[0] != 'P'))
        {
            printf("enter vaild input \n");
            goto r;
        }
        if (n[0] == m[0])
        {
            printf("draw");
            score[0][id][0] += 10;
            score[0][id2][0] += 10;
            goto e;
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
    e:
        printf("\n");
        for (int i = 0; i < 50; i++)
        {
            printf("=");
        }
        printf("\n         ROCK-PAPER-SCISSORS SCORE CARD\n");
        for (int i = 0; i < 50; i++)
        {
            printf("=");
        }
        printf(" \nGame :  ROCK-PAPER-SCISSORS\n");
        printf("        NAME         SCORE\n");
        for (int i = 1; i < game_id; i++)
        {
            printf(" %9s %9d \n ", name1[i], score[0][i][0]);
        }
    }
    void showhighscore()
    {

        int id = 0, id1 = 0, id2 = 0;
        int HIGH_SCORE_ROCK = 0;
        for (int i = 0; i < 50; i++)
        {
            if (score[0][i][0] > HIGH_SCORE_ROCK)
            {
                HIGH_SCORE_ROCK = score[0][i][0];
                id = i;
            }
        }
        printf("high score of Rock paper  %d by %s\n", HIGH_SCORE_ROCK, name1[id]);

        int HIGH_SCORE_NUMBER_G = 0;
        for (int j = 0; j < 50; j++)
        {
            if (score[2][j][0] > HIGH_SCORE_NUMBER_G)
            {
                HIGH_SCORE_NUMBER_G = score[2][j][0];
                id1 = j;
            }
        }
        printf("high score of number guess %d by %s\n", HIGH_SCORE_NUMBER_G, name1[id1]);
        int HIGH_SCORE_TIC = 0;
        for (int i = 0; i < 50; i++)
        {
            if (score[1][i][0] > HIGH_SCORE_TIC)
            {
                HIGH_SCORE_TIC = score[1][i][0];
                id2 = i;
            }
        }
        printf(" high score of tic tac toe is %d by %s\n", HIGH_SCORE_TIC, name1[id2]);
    }
    void resetscore()
    {
        for (int o = 0; o < 3; o++)
        {
            for (int l = 0; l < 50; l++)
            {
                
                    score[o][l][0] = 0;
                
            }
        }
        game_id=1;
    }
    void addplayer()
    {
        printf("\nenter player:");
        
        scanf("%s", name1[game_id]);
      
        printf("your game id is %d", game_id);
          game_id++;
    
    }
