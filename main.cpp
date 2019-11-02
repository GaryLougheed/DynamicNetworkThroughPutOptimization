// Program Description
/*
   Computer Networking Project
   10/22/2019

*/

// Header Files
#include <iostream>
#include "simulation.h"
#include "helperFunctions.h"
using namespace std;

// Global Constants



// Function Prototypes

/*
name:
input:
output:
process:
dependancies:
*/


/*
name: displayTitle()
input: none	
output: a cout message displaying the title of the program
process: iostream sending cout message to terminal/screen
dependancies: iostream
*/
void displayTitle();


/*
name: displayMenu()
input: none 
output: a cout mesage displaying the title of the program
process: iostream sending cout message to terminal/screen
dependancies: iostream
*/
void displayMenu();





// Main program
int main()
{

  // Declare and Initialize variables
  int userInput = 0;
  bool runSimulation = true;
  time_t current_time = 0;
  Simulation hi;

  // Networking Simulation

    // Main Loop
    while(runSimulation)
    { 
      // Display TItle
        displayTitle();

      // Display User Menu/Interactions
        displayMenu();



      // TODO: PROMPTFOR INPUT
        cin >> userInput;

      switch( userInput)
      {
        // Upload Network file fstream
        case '1':
               break;

        // Interaction with Network Mesh (add, delete, and change Node Parameters)
        case '2': 
               break;

        // Run Simulation // outputs? parameter duration for simulation.
        case '3':
               current_time = time(NULL);
               cout << current_time << "seconds passed since processID" << '\n';
               break;

          // Determine the overall throughput in the network.
        case '5':
               printPrompt("Ending Simulation");
               runSimulation = false;
               break;
      }
     }
  return 0;
}

// Function Supporting Implementation


void displayTitle()
{
  printPrompt("Networking Simulation");
}

void displayMenu()
{
  printPrompt("");
  printPrompt(" Networking Temporary Menu");
  printPrompt(" Option 1. "); 
}


