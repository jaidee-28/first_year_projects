#include <stdio.h>
char cordinate[4][4];

void tick_1_2(char, int *, int *, char);
void tick_3_4(char dir, int *i, int *m, char v);
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

    printf(" enter your first vehicle name a-z: ");
    char v1;
    scanf(" %c", &v1);
    printf("\nenter direction in which you want to travle : ");
    char dir1;
    scanf(" %c", &dir1);
    printf("\nenter your vehicle cordinate :");
    int x1, y1;
    scanf("%d %d", &x1, &y1);

    printf(" enter your first vehicle name a-z: ");
    char v2;
    scanf(" %c", &v2);
    printf("\nenter direction in which you want to travle : ");
    char dir2;
    scanf(" %c", &dir2);
    printf("\nenter your vehicle cordinate :");
    int x2, y2;
    int ticker =0;
    scanf("%d %d", &x2, &y2);
    for (int d = 0; d < 10; d++)
    {
        for (int a = 0; a < 2; a++)
        {  ticker++;
             
            if (dir3 == 's' && x<5&&y<4)
            { printf("Tick - %d\n",ticker);

                tick_1_2(dir3, &x, &y, v);
            }
            if (dir1 == 's' && x1<5&&y1<4)
            { printf("Tick - %d\n",ticker);

                tick_1_2(dir1, &x1, &y1, v1);
            }
            if (dir2 == 's' && x2<5&&y2<4)
            {
             printf("Tick - %d\n",ticker);
                tick_1_2(dir2, &x2, &y2, v2);
            }

            if (dir3 == 'n'&&x>=-1&&y<4)
            {
               printf("Tick - %d\n",ticker);
                tick_1_2(dir3, &x, &y, v);
            }
            if (dir1 == 'n'&&y1<4)
             {printf("Tick - %d\n",ticker);

                tick_1_2(dir1, &x1, &y1, v1);
            }
            if (dir2 == 'n'&&y2<4)
            {
                printf("Tick - %d\n",ticker);
                tick_1_2(dir2, &x2, &y2, v2);
            }
        }
        for (int a = 0; a < 2; a++)
        { ticker++;
            
}
            if (dir3 == 'e'&&y<=4)
             {printf("Tick - %d\n",ticker);
                tick_3_4(dir3, &x, &y, v);
            }
            if (dir1 == 'e' && y1<=4)
             {printf("Tick - %d\n",ticker);
                tick_3_4(dir1, &x1, &y1, v1);
            }
            if (dir2 == 'e'&&y2<=4)
             {
                printf("Tick - %d\n",ticker);

                tick_3_4(dir2, &x2, &y2, v2);
            }

            if (dir3 == 'w'&&y>=-1)
            {
             printf("Tick - %d\n",ticker);
                tick_3_4(dir3, &x, &y, v);
            }
            if (dir1 == 'w'&&y1>=-1)
             {printf("Tick - %d\n",ticker);

                tick_3_4(dir1, &x1, &y1, v1);
            }
            if (dir2 == 'w'&&y2>=-1)
            {printf("Tick - %d\n",ticker);

                tick_3_4(dir2, &x2, &y2, v2);
            }
        }
    
      for (int j = 0; j < 18; j++)
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

            for (int j = 0; j < 18; j++)
            {
                printf("_");
            }
    return 0;
}
void tick_1_2(char dir, int *i, int *m, char v)
{ 
    if (dir == 's')
    {
        
               if(*i==4){ cordinate[*i][*m]='.';}
        if (cordinate[*i][*m] == '.')
        {
            
        
            cordinate[*i - 1][*m] = '.';

            cordinate[*i][*m] = v;

            for (int j = 0; j < 18; j++)
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

            for (int j = 0; j < 18; j++)
            {
                printf("_");
            }
            printf("\n");
           ++*i;
          
        }
        
 
        
    }
    if (dir == 'n')
    {
       
                if(*i==-1){ cordinate[*i][*m]='.';}
        if (cordinate[*i][*m] == '.')
        {
             if (*i != 3)
        {
            cordinate[*i + 1][*m] = '.';
        }
            cordinate[*i][*m] = v;

            for (int j = 0; j < 18; j++)
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
            for (int j = 0; j < 18; j++)
            {
                printf("_");
            }
            printf("\n");
           --*i ;
        }
    
    }
}
void tick_3_4(char dir, int *i, int *m, char v)
{
    if (dir == 'w')
{     
             if(*m==-1)
         {   cordinate[*i][*m+1] = '.';}
        if (cordinate[*i][*m] == '.')
        {
       
        {cordinate[*i][*m+1]='.';}
        if(*m!=-1)
         {   cordinate[*i][*m] = v;}

            for (int j = 0; j < 18; j++)
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

            for (int j = 0; j < 18; j++)
            {
                printf("_");
            }
            printf("\n"); 
            --*m;
        }
    }
    if (dir == 'e')
    {
    
        if (cordinate[*i][*m] == '.')
        {
            if (*m != 0)
            {
                cordinate[*i][*m - 1] = '.';
            }
            if(*m!=4)
            {cordinate[*i][*m] = v;}

            for (int j = 0; j < 18; j++)
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
            for (int j = 0; j < 18; j++)
            {
                printf("_");
            }
            printf("\n");
            ++*m;
        }
    }
}