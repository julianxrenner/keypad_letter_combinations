/*
Name: Julian Renner
Date: Feb 7, 2023
Decription: write a program called assignment4.cpp which prompts the user to enter a 7 digit number, then prints out all of the possible letter combinations out based on the telephone keypad
*/
#include <iomanip>	//allows the program to use formatting options like setw
#include <iostream>	//allows the program to use input and output
#include <fstream>//allows the progrom to use files
#include <cmath>    //allows use of math operations
using namespace std;	//allows the program to use cout and cin

const int ROWSIZE = 10; //creates a constant int variable called ROWSIZE that creates 10 rows in the 2d array
const int COLSIZE = 5;  //creates a constant int variable called COLSIZE that creates 5 rows in the 2d array
const int NUMSIZE = 8;  //creates a constant int variable called NUMSIZE that stores 8 digits

void combine(char* input, char letters[ROWSIZE][COLSIZE], char* build, int index, ofstream& out)    //starts the combine function using the variables entered in main
{
    if (index == 7) //if the index is equal to 7
    {
        build[7] = '\0';    //sets teh 8th element of the array equal to the null byte
        out << build << endl;   //adds the build to the output file then creates a new line
    }

    else    //runs if the index is between 0 and 6
    {
        int indexNum = (int)input[index] - (int)'0';    //creates an int variable named indexNum
        int j = 0;  //creates an int variable named j and sets it equal to 0
        while (letters[indexNum][j] != '\0')    //while the letters element in its array is not equal to '0'
        {
            build[index] = letters[indexNum][j];    //sets the element of the build equal to the letter in the 2d array
            combine(input, letters, build, index + 1, out); //recalls the combine function
            j++;    //increments j
        }
    }
}

int main()  //starts the code
{
    char array[NUMSIZE];    // 2-d array of letters: 9 x 5
    char letters[ROWSIZE][COLSIZE] = { { '0', '\0', '\0', '\0', '\0' }, // row index 0
                                       { '1', '\0', '\0', '\0', '\0' },// row index 1
                                       { 'A', 'B', 'C', '\0', '\0' }, // row index 2
                                       { 'D', 'E', 'F', '\0', '\0' }, // row index 3
                                       { 'G', 'H', 'I', '\0', '\0' }, // row index 4
                                       { 'J', 'K', 'L', '\0', '\0' }, // row index 5
                                       { 'M', 'N', 'O', '\0', '\0' }, // row index 6
                                       { 'P', 'Q', 'R', 'S', '\0' }, // row index 7
                                       { 'T', 'U', 'V', '\0', '\0' }, // row index 8
                                       { 'W', 'X', 'Y', 'Z', '\0' } }; // row index 9
    char buildArr[ROWSIZE]; // output array; must be null-terminated!

    cout << "Enter a 7 Digit Number" << endl;
    cin >> array;  // user input – do not go beyond 7 chars and a NULL byte at the end!

    ofstream out;   //creates a file output called inp
    out.open("output.txt"); //opens the newly created output.txt file

    combine(array, letters, buildArr, 0, out);  //calls the combine function

    out.close();    //closes the output file

    cout << "The output is located in the file named output.txt" << endl;   //prints the name of the output file to remind the user

    return 0;   //ends the code
}