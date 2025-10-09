#include <stdio.h>
char cordinate[4][4];

void tick_1_2(char, int, int, char);
void tick_3_4(char dir, int i, int m, char v);
void tick_1( char dir,int i, int m, char v)
{
     if (dir == 'n')
    {
        if (cordinate[i][m] == '.')
        {
            cordinate[i][m] = v;
            
        }
        
    
    }
}
int main()
{
    for (int u = 0; u < 4; u++)
    {
        for (int r = 0; r < 4; r++)
        {
            cordinate[u][r] = '.';
        }
    }
    printf(" enter your first vehicle name a-z: ");
    char v;
    scanf(" %c", &v);
    printf("enter direction in which you want to travle : ");
    char dir3;
    scanf("  %c", &dir3);
    printf("enter your vehicle cordinate :");
    int x, y;
    scanf("%d %d", &x, &y);

    printf(" enter your second vehicle name a-z: ");
    char v1;
    scanf(" %c", &v1);
    printf("\nenter direction in which you want to travle : ");
    char dir1;
    scanf("  %c", &dir1);
    printf("\nenter your vehicle cordinate :");
    int x1, y1;
    scanf("%d %d", &x1, &y1);

    printf(" enter your third vehicle name a-z: ");
    char v2;
    scanf(" %c", &v2);
    printf("\nenter direction in which you want to travle : ");
    char dir2;
    scanf("  %c", &dir2);
    printf("\nenter your vehicle cordinate :");
    int x2, y2;
    scanf("%d %d", &x2, &y2);
    for (int d = 0; d < 4;)
    {
        if ((dir3 == 's' && x < 4) || (dir1 == 's' && x1 < 4) || (dir2 == 's' && x2 < 4))
        {
            for (int a = 0; a < 2; a++)
            {

               
                tick_1_2(dir3, x+a+d, y, v);
                
                if (x1+a+d - 1 >= 0)
                    cordinate[x1+a+d - 1][y1] = '.';
                tick_1_2(dir1, x1+a+d, y1, v1);
                
                if (x2+a+d - 1 >= 0)
                    cordinate[x2+a+d - 1][y2] = '.';

                tick_1_2(dir2, x2+a+d, y2, v2);
                

                if (dir2 == 's')
                {
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    for (int j = 0; j < 4; j++)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            printf(" | %c | ", cordinate[j][k]);
                        }
                        printf("\n");
                    }
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    goto t;
                }
                if (dir1 == 's')
                {
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    for (int j = 0; j < 4; j++)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            printf(" | %c | ", cordinate[j][k]);
                        }
                        printf("\n");
                    }
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    goto r;
                }
                if (dir3 == 's')
                {
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    for (int j = 0; j < 4; j++)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            printf(" | %c | ", cordinate[j][k]);
                        }
                        printf("\n");
                    }
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                }
            r:
            t:;
            }
        }

        if ((dir3 == 'n' && x > 0) || (dir1 == 'n' && x1 > 0) || (dir2 == 'n' && x2 > 0))
        {
            for (int a = 0; a < 2; a++)
            {
                if (x -a-d+ 1 < 4)
                    cordinate[x + 1][y] = '.';
                tick_1(dir3, x, y, v);
                
                if (x1 + 1 < 4)
                    cordinate[x1 + 1][y1] = '.';
                tick_1(dir1, x1, y1, v1);
                
                if (x2 -a-d+ 1 < 4)
                    cordinate[x2 -a-d+ 1][y2] = '.';
                tick_1(dir2, x2-a-d, y2, v2);
                
                if (dir2 == 'n')
                {
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    for (int j = 0; j < 4; j++)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            printf(" | %c | ", cordinate[j][k]);
                        }
                        printf("\n");
                    }
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    goto p;
                }
                if (dir1 == 'n')
                {
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    for (int j = 0; j < 4; j++)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            printf(" | %c | ", cordinate[j][k]);
                        }
                        printf("\n");
                    }
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    goto o;
                }
                if (dir3 == 'n')
                {
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                    for (int j = 0; j < 4; j++)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            printf(" | %c | ", cordinate[j][k]);
                        }
                        printf("\n");
                    }
                    for (int j = 0; j < 27; j++)
                    {
                        printf("_");
                    }
                    printf("\n");
                }
            p:
            o:;
            }
        }
        if ((dir3 == 'e' && y < 4) || (dir1 == 'e' && y1 < 4) || (dir2 == 'e' && y2 < 4))
        {
            for (int a = 0; a < 2; a++)
            {
                if (y - 1 >= 0)
                    cordinate[x][y - 1] = '.';
                tick_3_4(dir3, x, y, v);
                y++;
                if (y1 - 1 >= 0)
                    cordinate[x1][y1 - 1] = '.';
                tick_3_4(dir1, x1, y1, v1);
                y1++;
                if (y2 - 1 >= 0)
                    cordinate[x2][y2 - 1] = '.';
                tick_3_4(dir2, x2, y2, v2);
                y2++;
            }
        }

        if ((dir3 == 'w' && y > 0) || (dir1 == 'w' && y1 > 0) || (dir2 == 'w' && y2 > 0))
        {
            for (int a = 0; a < 2; a++)
            {
                if (y + 1 < 4)
                    cordinate[x][y + 1] = '.';
                tick_3_4(dir3, x, y, v);
                y--;
                if (y1 + 1 < 4)
                    cordinate[x1][y1 + 1] = '.';
                tick_3_4(dir1, x1, y1, v1);
                y1--;
                if (y2 + 1 < 4)
                    cordinate[x2][y2 + 1] = '.';
                tick_3_4(dir2, x2, y2, v2);
                y2--;
            }
        }
        int a=0;
         if (x +a+d- 1 >= 0)
   { cordinate[x+a+d - 1][y] = '.'; a++;}
        d += 2;
    }
    return 0;
}
void tick_1_2(char dir, int i, int m, char v)
{
    if (dir == 's')
    {
        if (cordinate[i][m] == '.')
        {
            cordinate[i][m] = v;
            
        }
        
    
    }
   
}
void tick_3_4(char dir, int i, int m, char v)
{
    if (dir == 'w')

    {
        if (cordinate[i][m] == '.')
        {
            cordinate[i][m] = v;

            for (int j = 0; j < 6; j++)
            {
                printf("_");
            }
            printf("\n");
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    printf(" |%c| ", cordinate[j][k]);
                }
                printf("\n");
            }

            for (int j = 0; j < 6; j++)
            {
                printf("_");
            }
            printf("\n");
            m++;
        }
    }
    if (dir == 'e')
    {
        if (cordinate[i][m] == '.')
        {
            cordinate[i][m] = v;

            for (int j = 0; j < 6; j++)
            {
                printf("_");
            }
            printf("\n");
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    printf(" |%c| ", cordinate[j][k]);
                }
                printf("\n");
            }
        }
    }
}