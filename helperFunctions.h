
// Header files
#include <iostream>
#include <fstream>
using namespace std;


// GLobal Constants
const char CONST_NULL_CHAR = '\0';
const char CONST_ENDLINE = '\n';
const int MAX_CSTRING_SIZE= 255; 



int strLen(char theString[MAX_CSTRING_SIZE]);
void cstringCopy(char src[MAX_CSTRING_SIZE], char dest[MAX_CSTRING_SIZE]);
bool isEqual(char src[MAX_CSTRING_SIZE], char dest[MAX_CSTRING_SIZE]); 
void printPrompt(char print[MAX_CSTRING_SIZE]);
void promptForInput(char prompt[MAX_CSTRING_SIZE], char userInput[MAX_CSTRING_SIZE]);
int countWords(ifstream& fin,char fileName[MAX_CSTRING_SIZE], char fileInput[MAX_CSTRING_SIZE]);
int countEndLines(ifstream& fin,char fileName[MAX_CSTRING_SIZE], char fileInput[MAX_CSTRING_SIZE]);

// 

//

//







