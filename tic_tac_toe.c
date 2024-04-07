#include <stdio.h>

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void showBoard();
int checkWin();
void system();

void main()
{
    int player = 1, input;
    showBoard();

    while (1)
    {
        player = (player % 2) ? 1 : 2;
        char mark = (player == 1) ? 'X' : 'O';

    again:
        printf("Enter number for player - %d: ", player);
        scanf("%d", &input);
        if (input < 1 || input > 9)
        {
            printf("\nInvalid Input.\n");
            goto again;
        }
        if (board[input] == 'X' || board[input] == 'O')
        {
            printf("\nPrefilled position selected, please choose some different block.\n");
            goto again;
        }
        board[input] = mark;
        showBoard();
        int result = checkWin();
        if (result == 1)
        {
            printf("Player %d is winner.", player);
            return;
        }
        else if (result == 0)
        {
            printf("Draw.");
            return;
        }
        player++;
    }
}

void showBoard()
{
    printf("\n\n");
    system("cls");

    printf("=====TIC TAC TOE=====\n\n");
    printf("Player -1('X')----Player -2('O')\n\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c  \n", board[1], board[2], board[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c  \n", board[4], board[5], board[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c  \n", board[7], board[8], board[9]);
    printf("   |   |   \n");
}

int checkWin()
{
    if (board[1] == board[2] && board[2] == board[3])
        return 1;

    if (board[1] == board[4] && board[4] == board[7])
        return 1;

    if (board[4] == board[5] && board[5] == board[6])
        return 1;

    if (board[7] == board[8] && board[8] == board[9])
        return 1;

    if (board[2] == board[5] && board[5] == board[8])
        return 1;

    if (board[3] == board[6] && board[6] == board[9])
        return 1;

    if (board[1] == board[5] && board[5] == board[9])
        return 1;

    if (board[3] == board[5] && board[5] == board[7])
        return 1;

    int count = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            count++;
        }
    }
    if (count == 9)
        return 0;
    else
        return -1;
}