#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int choice, player;

int CheckForWin();
void DisplayBoard();
void MarkBoard(char mark);

int main()
{
    int gameStatus;
    char mark;
    player = 1;
    do
    {
        DisplayBoard();
        //change turns
        player = (player % 2) ? 1 : 2;

        //get input
        printf("Player %d, enter a number(if you enter a LETTER it will bug): ", player);
        scanf("%d", &choice);


        mark = (player == 1) ? 'X' : 'O';
        MarkBoard(mark);

        gameStatus = CheckForWin();
        player++;
    }while(gameStatus == -1);
    if(gameStatus == 1)
        printf("===>\aPlayer %d wins!!", --player);
    else
        printf("===>\aGame draw!!");
    return 0;
}
/**********************************
Function return game status
1 if game is over with results
-1 if game is in progress
0 if game is over and no result
**********************************/
int CheckForWin(){
    int returnValue = 0;
    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;
    else if(square[4] == square[5] && square[5] == square[6])
        returnValue = 1;
    else if(square[7] == square[8] && square[8] == square[9])
        returnValue = 1;
    else if(square[1] == square[4] && square[4] == square[7])
        returnValue = 1;
    else if(square[2] == square[5] && square[5] == square[8])
        returnValue = 1;
    else if(square[3] == square[6] && square[6] == square[9])
        returnValue = 1;
    else if(square[1] == square[5] && square[5] == square[9])
        returnValue = 1;
    else if(square[3] == square[5] && square[5] == square[7])
        returnValue = 1;
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5'
             && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
                returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}


void DisplayBoard(){
    system("cls");

    printf("\n\tTic Tac Toe\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    //Line 1
    printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n", square[1], square[2], square[3]);
    //Line 2
    printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n", square[4], square[5], square[6]);
    //Line 3
    printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n", square[7], square[8], square[9]);
}

/*******************************
Set the board with the correct character
x or o in the correct spot in the grid
*********************************/

void MarkBoard(char mark){
    if(choice == 1 && square[1] == '1')
        square[1] = mark;
    else if(choice == 2 && square[2] == '2')
        square[2] = mark;
    else if(choice == 3 && square[3] == '3')
        square[3] = mark;
    else if(choice == 4 && square[4] == '4')
        square[4] = mark;
    else if(choice == 5 && square[5] == '5')
        square[5] = mark;
    else if(choice == 6 && square[6] == '6')
        square[6] = mark;
    else if(choice == 7 && square[7] == '7')
        square[7] = mark;
    else if(choice == 8 && square[8] == '8')
        square[8] = mark;
    else if(choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("Invalid move");
        player--;
        getch();
    }
}
