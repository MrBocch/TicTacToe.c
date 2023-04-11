#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//stop letting overriding over character
//board wasn't so ugly
//checking who won is so ugly hardcoded. What else?
//player VS A.I

enum gameState {playing, over};

void printBoard(int array[][3]){
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {

            if(array[i][j] == 1){
                printf("X ");
            }else if(array[i][j] == 2){
                printf("T ");
            }else{
                printf("0 ");
            }
        }
    printf("\n");
    }
}

void tutorial(){
    for(int i=1; i<=9; i++) {
        printf("#%d ", i);
        if(i%3 == 0 && i != 0) puts("");
    }
    puts("");
}

int checkWin(int array[][3]){
    //left to right player 2
    if(
        array[0][0] == 1 && array[0][1] == 1 && array[0][2] == 1
    ){
        puts("player 2 wins");
        return 1;
    }else if(
        array[1][0] == 1 && array[1][1] == 1 && array[1][2] == 1
    ){
        puts("player 2 wins");
        return 1;
    }else if(
        array[2][0] == 1 && array[2][1] == 1 && array[2][2] == 1
    ){
        puts("player 2 wins");
        return 1;
    }
    //up down
    else if(
        array[0][0] == 1 && array[1][0] == 1 && array[2][0] == 1
    ){
        puts("player 2 wins");
        return 1;
    }else if(
        array[0][1] == 1 && array[1][1] == 1 && array[2][1] == 1
    ){
        puts("player 2 wins");
        return 1;
    }else if(
        array[0][2] == 1 && array[1][2] == 1 && array[2][2] == 1
    ){
        puts("player 2 wins");
        return 1;
    }
    //diagnal
    else if(
        array[0][0] == 1 && array[1][1] == 1 && array[2][2] == 1
    ){
        puts("player 2 wins");
        return 1;
    }else if(
        array[2][0] == 1 && array[1][1] == 1 && array[0][2] == 1
    ){
        puts("player 2 wins");
        return 1;
    }else{};

    //player 1
    if(
        array[0][0] == 2 && array[0][1] == 2 && array[0][2] == 2
    ){
        puts("player 1 wins");
        return 1;
    }else if(
        array[1][0] == 2 && array[1][1] == 2 && array[1][2] == 2
    ){
        puts("player 1 wins");
        return 1;
    }else if(
        array[2][0] == 2 && array[2][1] == 2 && array[2][2] == 2
    ){
        puts("player 1 wins");
        return 1;
    }
    //up down
    else if(
        array[0][0] == 2 && array[1][0] == 2 && array[2][0] == 2
    ){
        puts("player 1 wins");
        return 1;
    }else if(
        array[0][1] == 2 && array[1][1] == 2 && array[2][1] == 2
    ){
        puts("player 1 wins");
        return 1;
    }else if(
        array[0][2] == 2 && array[1][2] == 2 && array[2][2] == 2
    ){
        puts("player 1 wins");
        return 1;
    }
    //diagnal
    else if(
        array[0][0] == 2 && array[1][1] == 2 && array[2][2] == 2
    ){
        puts("player 1 wins");
        return 1;
    }else if(
        array[2][0] == 2 && array[1][1] == 2 && array[0][2] == 2
    ){
        puts("player 1 wins");
        return 1;
    }

    return 0;
}

int main() {
    srand(time(0));
  
    int board[3][3] = {0};
    enum gameState state;
    state = playing;
  
 
    puts("Hi welcome to my tiktaktoe program"); 
    puts("Decide where you want to place with this grid");
    tutorial();
    
    int turns = 1;
    int pointer;

    while(state == playing){
        
        puts("where?");
        scanf("%d", &pointer);
        puts("---------");
        
        if(turns%2 == 0){
        switch(pointer){
            case 1:{
                board[0][0] = 1;
                break;
            }
            case 2:{
                board[0][1] = 1;
                break;
            }
            case 3:{
                board[0][2] = 1;
                break;
            }
            case 4:{
                board[1][0] = 1;
                break;
            }
            case 5:{
                board[1][1] = 1;
                break;
            }
            case 6:{
                board[1][2] = 1;
                break;
            }
            case 7:{
                board[2][0] = 1;
                break;
            }
            case 8:{
                board[2][1] = 1;
                break;
            }
            case 9:{
                board[2][2] = 1;
                break;
            }

        }
        }else{
        switch(pointer){
            case 1:{
                board[0][0] = 2;
                break;
            }
            case 2:{
                board[0][1] = 2;
                break;
            }
            case 3:{
                board[0][2] = 2;
                break;
            }
            case 4:{
                board[1][0] = 2;
                break;
            }
            case 5:{
                board[1][1] = 2;
                break;
            }
            case 6:{
                board[1][2] = 2;
                break;
            }
            case 7:{
                board[2][0] = 2;
                break;
            }
            case 8:{
                board[2][1] = 2;
                break;
            }
            case 9:{
                board[2][2] = 2;
                break;
            }
            default:
                puts("you lose turn hehe xD");
                break;
        }
        }
        
        
        turns +=1;
        printf("\x1b[2J"); //this clears the screen
        printBoard(board);
        if(checkWin(board)) state = over;
    }
  
}
