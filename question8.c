#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 40
void SWAP(char names[10][MAX_STRING_SIZE], char covid[10], int position) {
    char temp[MAX_STRING_SIZE];
    strcpy(temp, names[position]);
    strcpy(names[position], names[position + 1]);
    strcpy(names[position + 1], temp);

    
    char temp1 = covid[position];
    covid[position] = covid[position + 1];
    covid[position + 1] = temp1;
}
void BUBBLE_SORT(char names[10][MAX_STRING_SIZE], char  covid[10]) {
    void (*swapPtr)(char [10][MAX_STRING_SIZE], char [10], int) = &SWAP; 
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (covid[j] == 'N' && covid[j+1] == 'P')
              (*swapPtr)(names, covid, j); 
        }
    }
}

void DISPLAY(char names[10][MAX_STRING_SIZE], char covid[10]) {
    for(int i = 0; i < 10; i++) {
        printf("Name: %s\tCovid Status: %c\n", names[i], covid[i]);
    }
}



int main() {
    char names[10][MAX_STRING_SIZE] = {
        "Hina", "Sara", "Ali","Zain","Bakhtawar","Hashim","Zeeshan","Jameela","Asfa","Zahid"
    };
    char covid[10] = {
        'P','N','P','P','N','P','N','N','N','N'
    };
    void (*bubbleSortPtr)(char [10][MAX_STRING_SIZE], char [10]) = &BUBBLE_SORT; 
    void (*displayPtr)(char [10][MAX_STRING_SIZE], char [10]) = &DISPLAY;
    printf("Before Sorting\n");
    (*displayPtr)(names, covid);
    (*bubbleSortPtr)(names, covid); 
    printf("After Sorting\n");

    (*displayPtr)(names, covid); 
}

