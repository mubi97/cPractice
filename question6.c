#include<stdio.h>
#include <stdlib.h>
int Jeet_ki_bazi(int * boxes, int noOfBoxes) {
    int cashPlayer1 = 0, cashPlayer2 = 0;
    for(int i = 0; i < noOfBoxes / 2; i++) {
        int turnP1 = 0, turnP2 = 0;
        while ( turnP1 == 0 || boxes[turnP1] == 0 || turnP1 > noOfBoxes) {
            printf("Player A Please choose a number from 1-%d that is not used till now : ", noOfBoxes);
            scanf("%d", &turnP1);
        }
        printf("%d\n", boxes[turnP1 - 1]);
        cashPlayer1 += boxes[turnP1 - 1];
        boxes[turnP1 - 1] = 0;
         while ( turnP2 == 0 || boxes[turnP2] == 0 || turnP2 > noOfBoxes) {
            printf("Player B Please choose a number from 1-%d that is not used till now : ", noOfBoxes);
            scanf("%d", &turnP2);
        }
        printf("%d\n", boxes[turnP2 - 1]);

        cashPlayer2 += boxes[turnP2 - 1];
        boxes[turnP2 - 1] = 0;
    }
    printf("The total value collected by player A is %d\n", cashPlayer1);
    printf("The total value collected by player B is %d\n", cashPlayer2);
    int winFlag = cashPlayer1 > cashPlayer2 ? 0 : 1;
    if(cashPlayer1 == cashPlayer2) {
        winFlag = 2;
    }
    return winFlag;
}
int main() {
    int noOfBoxes = 6;
    int * boxes;
   
   
    boxes = (int *) malloc(noOfBoxes * sizeof(int));
    for(int i = 0; i < noOfBoxes; i++) {
        boxes[i] = (rand() % 50) + 1;
    }
    int flag = Jeet_ki_bazi(boxes, noOfBoxes);
    if(flag == 0) {
        printf("The first picker, Player A wins. Congratulations on your well-deserved success.\n");
    } else if(flag == 1) {
        printf("The first picker, Player A wins. Congratulations on your well-deserved success.\n");
    } else {
        printf("Game is draw.\n");
    }
    free(boxes);
    return 0;
}