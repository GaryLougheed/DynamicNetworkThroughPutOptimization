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

void displayNetworkInteraction();
void displaySecretDebug();
void displayStatisticsMenu();

// Main program
int main()
{

  // Declare and Initialize variables
  int userInput = 0;
  bool runSimulation = true;
  time_t current_time = 0;
  Simulation hi;

  int numberOfInitialNodes = 0;
  bool initialCreation = false;

  // Networking Simulation

    // Main Loop
    while(runSimulation)
    { 
      // Display TItle
         printPrompt("Networking Simulation");

      // Display User Menu/Interactions
         printPrompt("");
         printPrompt("Networking Simulation Menu");
         printPrompt("Option 1: Generate initial network"); 
         printPrompt("Option 2: Interact with network");
         printPrompt("Option 3: Run network simulation by packet count");
         printPrompt("Option 4: Run network simulation for a certain amount of time");
         printPrompt("Option 5: View statistics on simulation");
         printPrompt("Option 6: Quit");
      // TODO: PROMPTFOR INPUT
        cin >> userInput;

      switch(userInput)
      {
        // Upload Network
        case 1:
            if(initialCreation == true)
            {
              printPrompt("Initial network generation is allowed only once");
            }
            else
            {
              printPrompt("How many nodes do you want to place into the network");
              cin >> numberOfInitialNodes;
              hi.GenerateInitialNetwork(numberOfInitialNodes);
              initialCreation = true;
            }
            
            break;

        // Interaction with Network Mesh (add, delete, and change Node Parameters)
        case 2:
               displayNetworkInteraction();
               break;

        // Run Simulation // outputs? parameter duration for simulation.
        case 3:
              printPrompt("How many packets would you like to send for the simulation run?");
              int count;
              cin >> count;
              
              hi.RunSimulationByPackets(count);

              cout << count << " ";
              printPrompt("packets have been sent for the simulation run");
              break;
        case 4:
              printPrompt("How many packets would you like to send for the simulation run?");
              int seconds;
              cin >> seconds;

              current_time = time(NULL);
              
              hi.RunSimulationByTime(seconds);

              cout << current_time << " ";
              printPrompt("seconds passed since the simulation was started");
              break;
          // Determine the overall throughput in the network.
        case 5:
               displayStatisticsMenu();
               break;

        //quit the simulation
        case 6:
                printPrompt("Ending Simulation");
               runSimulation = false;
               break;

        //secret debug menu
        case 400:
               printPrompt("You have found the secret debug menu");
        default:
               printPrompt("You have entered an invalid command"); 
      }
     }
  return 0;
}

// Function Supporting Implementation
void displayNetworkInteraction() 
{
   int nodeUserInput = 0;

   printPrompt("");
   printPrompt("Interact with network mesh");
   printPrompt("Option 1: Add Node"); 
   printPrompt("Option 2: Delete Node");
   printPrompt("Option 3: Change a Node");
   printPrompt("Option 4: Link nodes");
   printPrompt("Option 5: Quit");

   cin >> nodeUserInput;
   switch (nodeUserInput)
   {
    case 1:
        if(hi.manipulateNetworkMesh(1,0,0) == true);
        {
          cout << "Node successfully added." << endl;
        }
        else if(hi.manipulateNetworkMesh(1,0,0) == false)
        {
          cout << "Node could not be added. The network is full."
        }
    break;

    case 2:
        int id = 0;
        printPrompt("Enter ID number of node you want to delete");
        cin >> id;

        if(hi.manipulateNetworkMesh(2, id, 0) == true)
        {
            cout << "Node " << id << " has been successfully deleted" << endl;
        }
        else if(hi.manipulateNetworkMesh(2, id, 0) == false)
        {  
            cout << "Node " << id << " has been could not be deleted. Either the node doesn't exist or there are too few in the network." << endl;
        }
     break;

     case 3:
        int id = 0;

        printPrompt("Enter ID number of node you want to adjust");
        cin >> id;

        //retrieve specifications of node and record user requests

     break;

     case 4:
        int id1, id2 = 0;
          printPrompt("Enter ID number of first node you want to link");
          cin >> id1;
          printPrompt("Enter ID number of first node you want to link");
          cin >> id2;

          if(hi.manipulateNetworkMesh(4, id1, id2) == true)
          {
              cout << "Node " << id1 << " and " << id2 <<" has been successfully linked together" << endl;
          }
          else if(hi.manipulateNetworkMesh(4, id1, id2) == false)
          {
              cout << "Node " << id1 << " and " << id2 <<" has been could not be linked together" << endl;
          }
     break;

     case 5:
     /* code */
     break;
   
   default:
        printPrompt("You have entered an invalid command");
     break;
   }
}

void displaySecretDebug()
{
    int debugUserInput = 0;
}

void displayStatisticsMenu()
{
    int userInput;

    printPrompt("");
    printPrompt("You can view network topology and statistics here.");
    printPrompt("Option 1: List all network nodes with basic info");
    printPrompt("Option 2: Get Detailed information on single node");
    printPrompt("Option 3:");
    printPrompt("Option 4:");
    printPrompt("Option 5:");

    cin >> userInput;

    switch(userInput)
    {
        case 1:
            hi.listNetworkNodes();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printPrompt("You have entered an invalid command");
            break;
    }
}