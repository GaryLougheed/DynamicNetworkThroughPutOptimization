#include "helperFunctions.h"

int strLen(char theString[MAX_CSTRING_SIZE])
{

  // Declare and Initialize Variables
    int totalLength = 0;
    int index = 0;

  // loop
    
   while(theString[index]  != CONST_NULL_CHAR && index < MAX_CSTRING_SIZE )
   {
      index++;
      totalLength++;
    }
    
  return totalLength;
}


void cstringCopy(char src[MAX_CSTRING_SIZE], char dest[MAX_CSTRING_SIZE])
{
  // Declare and Initialize variables

  int src_size = 0;
  src_size  =  strLen(src);
  int dest_size = 0;
  dest_size = strLen(dest);
  int index = 0;

  while(src[index] != CONST_NULL_CHAR)
  {
    dest[index] = src[index];
    index++;
  }
    dest[index] = CONST_NULL_CHAR;

}


bool isEqual(char src[MAX_CSTRING_SIZE], char dest[MAX_CSTRING_SIZE]) 
{

  // Declare and Initialize 
   int src_size = 0;
   int dest_size = 0;
   int index = 0;

   src_size = strLen(src);
   dest_size = strLen(dest);

   if (src_size != dest_size)
     return false;   
   
   while(src[index] == dest[index] && index < src_size)
   {
      index++;
   }    

   if( index == src_size )
   {
     return true; 
   }

  return false;
}

void printPrompt(char print[MAX_CSTRING_SIZE])
{
  
  cout << print << CONST_ENDLINE;

}

void promptForInput(char prompt[MAX_CSTRING_SIZE], char userInput[MAX_CSTRING_SIZE])
{

  cout << prompt << CONST_ENDLINE;  

  cin >> userInput;

}

int countWords(ifstream& fin,char fileName[MAX_CSTRING_SIZE], char fileInput[MAX_CSTRING_SIZE])
{

  // Declare and initialize variables
    int result = 0;
    
  // open file
    fin.open(fileName);
    
  // if the file is good continue, else report false, and return 0 counted end lines.
    if( !fin.good())
    {
      printPrompt("Error!");

    }


  // While the file input steam is good
    while(fin.good())
    {
      fin >> fileInput;
      if(isEqual(fileInput,"\n"));
        result++;
    }
      
  // close file stream
    fin.close();

  return result-1;
}

int countEndLines(ifstream& fin, char fileName[MAX_CSTRING_SIZE], char fileInput[MAX_CSTRING_SIZE])
{
  // Declare and initialize variables
    int result = 0;
    char charReadFromFile = '0'; 
  // open file
    fin.open(fileName);
    
  // if the file is good continue, else report false, and return 0 counted end lines.
    if( !fin.good())
    {
      printPrompt("Error!");

    }


  // While the file input steam is good
    while(fin.good())
    {
        fin.get(charReadFromFile);
        if ( charReadFromFile == '\n')
          result++;
    }
      
  // close file stream
    fin.close();

  return result-1;
}
