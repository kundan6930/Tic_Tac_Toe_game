#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const char player11 = 'X', player22 = 'O';

void playboard(int arr[][3])
{
    printf("\n\n");
    printf("\t\t   %c  |   %c  |   %c  \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("\t\t-----------------------\n");
    printf("\t\t   %c  |   %c  |   %c  \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("\t\t-----------------------\n");
    printf("\t\t   %c  |   %c  |   %c  \n", arr[2][0], arr[2][1], arr[2][2]);
    printf("\n\n");
    return;
}
void gamesrule()
{
    printf("\n\n");
    printf("\t\t*********** TIC-TAC-TOE GAME ***************\n\n");
    printf("Choose the cell number from 1 to 9 as shown below and Play the game\n\n");
    printf("\t\t   1  |   2  |   3  \n");
    printf("\t\t-----------------------\n");
    printf("\t\t   4  |   5  |   6  \n");
    printf("\t\t-----------------------\n");
    printf("\t\t   7  |   8  |   9  \n");
    printf("\n\n");
    return;
}
void eplayer1(int arr[][3], int turn)
{
    int a, row, column,count=0;

    int work1(int arr[][3])
    {
        for (int i = 0; i < 3; i++)
        {
            if (((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) && arr[i][0] != ' ') || ((arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) && arr[0][i] != ' '))
            {
                return 1;
            }
            }
            return 0;
        
    }
    int work2(int arr[][3])
    {

        if (((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) && arr[0][0] != ' ') || ((arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) && arr[0][2] != ' '))
        {
            return 1;
        }

        return 0;
    }

    int gameover(int arr[][3])
    {
        if (work1(arr) == 1 || work2(arr) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    while (gameover(arr) != 1 && count != 9)
    {int arr1[9],flag=0;
        if (turn == 1)
        { printf("Now it's turn for player %d\n",turn);
            scanf("%d", &a);
        arr1[count]=a;
            for(int i=0;i<count;i++)
            {
               if(arr1[i]==a)
               {
                   printf("This box is already filled choose empty box\n\nAgain");
                   flag=1;
                   break;
               }
            }
            if(flag==1)
            {continue; }
            row = (a-1) / 3;
            column = (a-1) % 3;
            arr[row][column] = player11;
            count++;
            printf("Player %d puts %c at box No %d\n",turn,player11,a);
            playboard(arr);
            turn = 2;
            
        }
        else if (turn == 2)
        { printf("Now it's turn for player %d\n",turn);
            scanf("%d", &a); arr1[count]=a;
            for(int i=0;i<count;i++)
            {
               if(arr1[i]==a)
               {
                   printf("This box is already filled choose empty box\n\nAgain ");
                   flag=1;
                   break;
               }
            }if(flag==1)
            {continue; }          

            row = (a-1) / 3;
            column = (a-1) % 3;
            arr[row][column] = player22;
            count++;
            printf("Player %d puts %c at box No %d\n",turn,player22,a);
            playboard(arr);
            turn = 1;
            
        }
    }

    if (gameover(arr) == 0 && count == 9)
    {
        printf("Match draw\n");
    }
    else
    {
        if (turn == 1)
        {
            printf("\t\t**************  player 2 is a winner  *******************\n\n");
        }
        else
        {
            printf("\t\t**************  player 1 is a winner  *******************\n\n");
        }
    }
    return;
}
int main()
{int count = 0, turn;
    gamesrule();
    srand(time(NULL));
    int num = (rand() % 10)+0 ;
    int c,d;
    printf("Enter a number between 0 to 9 by player 1 for tossing\n");
    scanf("%d", &c);
    if (c == num)
    {
        turn = 1;
        printf("Player 1 wins the toss\n");
    }
    else
    {
        turn = 2;
        printf("Player 2 wins the toss\n");
    }
    printf("intially all boxes are empty\n");
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = ' ';
        }
    }
    playboard(arr);
    printf("\t\t******** Let's start the game ***********\n\n");
    printf("\tplayer 1 is represented by ' X ' and player 2 is represented by ' O '\n\n");
    eplayer1(arr, turn);
    printf("Do u want to play again then \nEnter 1 for Yes and 2 for No\n");
    scanf("%d",&d);
    if(d==1)
    {
        main();
    }
    printf("\n\n\t\t************* THANK U ************\n\n");

    return 0;
}