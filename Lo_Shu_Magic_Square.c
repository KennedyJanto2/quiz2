#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//test if square is a Lo Shu magic square
bool isLoShu(int square[3][3]){
    //keeps track of visited numbers
    int visited[9] = {0,0,0,0,0,0,0,0,0};

    int diagnol1 = 0;
    int diagnol2 = 0;

    //iterate through row
    for(int r = 0; r < 3; r++){
        int rowTotal = 0;
        int colTotal = 0;

        //test if all numbers are valid or not, then add to row total and col total
        //iterate through column
        for(int c = 0; c < 3; c++){
            if(square[r][c] < 1 || square[r][c] > 9){
                return false;
            }
            else if(visited[square[r][c] - 1] == 1){
                return false;
            }
            else{
                visited[square[r][c] - 1] = 1;
            }

            rowTotal += square[r][c];

            colTotal += square[c][r];
        }

        diagnol1 += square[r][r];

        diagnol2 += square[r][2 - r];
        //test if rows and columns adds up to 15 to be Lo Shu Magic Square
        if(rowTotal != 15 || colTotal != 15){
            return false;
        }
        
    }

    //test if diagnols add up to 15 to be Lo Shu Magic Square
    if(diagnol1 != 15 || diagnol2 != 15){
        return false;
    }

    //not a Lo Shu Magic Square
    return true;
}


//print out square in 2d array
void printSquare(int output[3][3]){
    printf("[%i][%i][%i]\n[%i][%i][%i]\n[%i][%i][%i]\n", output[0][0], output[0][1],output[0][2],output[1][0],output[1][1],output[1][2],output[2][0], output[2][1], output[2][2]);
}


int main(){
    int magicSquare[3][3] = {{4, 9, 2},
                             {3, 5, 7},
                             {8, 1, 6}};
    
    int notMagicSquare[3][3] = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
    //magic square example
    printSquare(magicSquare);

    if(isLoShu(magicSquare)){
        printf("This is a Lo Shu Magic Square\n");
    }
    else{
        printf("This is not a Lo Shu Magic Square\n");
    }

    //not magic square example
    printSquare(notMagicSquare);

    if(isLoShu(notMagicSquare)){
        printf("This is a Lo Shu Magic Square\n");
    }
    else{
        printf("This is not a Lo Shu Magic Square\n");
    }

    //random number for square
    printf("\nGenerating random square until Lo Shu Square is created:\n");

    int randomSquare[3][3];

    srand(time(0)); //random number seed

    int random = 0; //random number from 1-9 to fill up array
    int count = 0; //count how many sqauares generated to get Lo Shu Magic Square

    //generete new square until lo shu square is found
    do{ 
        int visited[9] = {0,0,0,0,0,0,0,0,0}; //holds visited numbers
        //iterate through all indexes
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                do{ //generate random number until it is a number not in visited
                    random = rand() % 9 + 1;
                }while(visited[random - 1] == 1);

                randomSquare[r][c] = random; //update array index with number
                visited[random - 1] = 1;    //update visited array
            }
        }
        count++;
    }while(!isLoShu(randomSquare));
        
    printf("The Lo Shu Magic Square is:\n");
    printSquare(randomSquare);
    printf("%i squares were generated to get Lo Shu Magic Square\n", count);

    return 0;
}


