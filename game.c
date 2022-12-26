#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<time.h>
void game(char player_name[50]);
int digit_count(int k);
int main()
{  system("cls");
    char name[50], ch;
    int i, j, k = 1, x;
    system("COLOR 0C");
    printf("Enter you name \n");
    fgets(name, 50, stdin);
    system("cls");
    printf("                       RULE OF THIS GAME");
    printf("\n1.You can move only one step at a time by arrow key\n");
    printf("  Move Up    : by Up arrow key\n  Move Down  : by Down arrow key\n  Move left  : by Left arrow key\n  Move right : by right arrow key\n");
    printf("2.You can move number at empty position only\n3.For each valid move : your total number of moves will decrease by 1\n");
    printf("4.Winning situation : number in the 4*4 matrix should be in order from 1 to 15\n\n\n                          WINNING SITUATION\n");
    system("COLOR 0A");
    for (i = 1; i <= 6; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            if (i == 5 && j == 8)
            {
                printf("  | ");
                break;
            }
            if (i == 1 || i == 6)
            {
                printf("==");
                continue;
            }

            if (j % 2 != 0 && i >= 2)
                printf("| ");
            else if (i != 0 && i + j != 13)
            {
                x = digit_count(k);
                if (x == 2)
                    printf("%d", k);
                else
                    printf("%d ", k);
                k++;
            }
        }
        printf("\n");
    }
    system("COLOR 0B");
    printf("\n5.You can exit the game anytime by pressing 'E' or 'e'\nSo try to win in minimum no of moves\n\n\n                       HAPPY GAMING,GOOD LUCK\n");
    printf("Press Enter key to start.....\n");
    scanf("%c", &ch);
    system("cls");
    game(name);

    return 0;
}
int digit_count(int k)
{
    int count = 0;
    while (k != 0)
    {
        k = k / 10;
        count++;
    }
    return count;
}

void game(char player_name[50]) // GENERATING RANDOM NUMBERS
{
    int arr[4][4], i, j, flag, temp, k, l;
    int moves = 60;
    for (i = 0; i < 4; i++)
    {
        srand(time(NULL));
        for (j = 0; j < 4; j++)
        {

            if (i == 3 && j == 3)
                break;
            temp = rand() % 15 + 1;
            flag = 0;

            for (k = 0; k < 4; k++)
            {
                for (l = 0; l < 4; l++)
                {
                    if (i == k && j == l)
                        continue;
                    if (temp == arr[k][l])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                    break;
            }
            if (flag == 0)
                arr[i][j] = temp;
            else
                j--;
        }
    }
    printf("\n");
    arr[3][3] = ' ';
    player_name[strlen(player_name) - 1] = '\0';

    printf("Hello %s                      Moves Remaining : %d", player_name, moves);
    printf("\n\n========================\n"); // DISPLAYING THE  UNORDERED NUMBERS
    for (i = 0; i < 4; i++)
    {

        for (j = 0; j < 4; j++)
        {

            if (digit_count(arr[i][j]) == 2)
            {
                if (i == 3 && j == 3)
                {
                    printf("|  %c |", arr[3][3]);
                    break;
                }
                printf("| %d |", arr[i][j]);
            }
            else
            {
                printf("|  %d |", arr[i][j]);
            }
        }
        printf("\n");
    }
    printf("========================");
    // START SHIFTING
    char ch;
    void swap(int i, int j, int k, int l, int moves_remain)
    {
        system("cls");
        int temp;
        temp = arr[i][j];
        arr[i][j] = arr[k][l];
        arr[k][l] = temp;
        printf("\n                         Moves Remaining : %d", moves_remain);
        printf("\n\n========================\n");
        for (i = 0; i < 4; i++) // AFTER EVERY MOVE CHECK DISPLAY THE NEW MATRIX
        {
            for (j = 0; j < 4; j++)
            {
                if (arr[i][j] == 32)
                    printf("|  %c |", arr[i][j]);
                else
                {
                    if (digit_count(arr[i][j]) == 2)
                        printf("| %d |", arr[i][j]);
                    else
                        printf("|  %d |", arr[i][j]);
                }
            }
            printf("\n");
        }
        printf("========================");
    }

    printf("\nPress appropriate arrow key to shift number\n");

    i = 3;
    j = 3; // BECAUSE MATXIX IS 4*4 ,HENCE MAX VALUE OF INDEX IS 4-1=3
    for (k = 0; k < moves;)
    {
        ch = getch(); // GETCH HELPS TO READ ARROW KEY
        if (ch == 'E' || ch == 'e')
        {
            printf("\n\n              GAME OVER!");
            break;
        }
        if (ch == 72 && i != 3) // IF UP ARROW KEY IS PRESSED
        {
            swap(i, j, i + 1, j, moves - k - 1);
            i++;
            k++;
        }
        if (ch == 75 && j != 3) // IF LEFT ARROW KEY IS PRESSED
        {
            swap(i, j + 1, i, j, moves - k - 1);
            j++;
            k++;
        }
        if (ch == 77 && j != 0) // IF RIGHT ARROW KEY IS PRESSED
        {
            swap(i, j - 1, i, j, moves - k - 1);
            j--;
            k++;
        }
        if (ch == 80 && i != 0) // IF DOWN ARROW KEY IS PRESSED
        {
            swap(i, j, i - 1, j, moves - k - 1);
            i--;
            k++;
        }
    }
    k = 1;
    for (i = 0; i < 4; i++) // AFTER MOVES ARE OVER ,CHECKING THAT MATRIX MATCHES THE CORRECT REQUIRES MATRIX OR OR
    {
        for (j = 0; j < 4; j++, k++)
        {
            if (arr[i][j] != k)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
        printf("\n\n\nYou Lose !\n\n");
    else
        printf("\n\n\nYou Win!\n\n");
}
