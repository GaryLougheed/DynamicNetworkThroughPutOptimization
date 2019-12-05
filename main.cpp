// Program Description
/*
   Computer Networking Project
   10/22/2019
//TODO: Destruction menu option number 5  

    Throughput: The amount of bits per second sent from source to destination.
                A packet's size will determine when the packet is sent in the simulation.
                For simulation purposes a packet will have size time_t meaning it takes 1.0 second to send a standard packet. This standard packet size will always transmit occur the network at a rate of 1.0 seconds unless the network node and the links provide either increase of decrease the standard transfer rate. If the throughput is 10 then 10 is a number that is derived from many throughput influencing variables, such as node delay, throttle, carrier purchases, security, and reliability.
   A network node may send a standard packet at a newly calculated rate of 15600 bits per second or in the case of the simulation it will take 0.1 seconds to send this packet. 10 times the normalized speed of 1560 bits per second. The simulation takes 1 second to send 1560bits. This means the packet would complete its transmission within 0.1 seconds. This time is maintained by the packet data structure and the simulation handles the simulation time. The network mesh is responsible for updating this the time across all the network nodes.

    Time Sync: The simulation ticks at 0, 0.2, 0.4, 0.6, ...and so forth.
               The simulation ticks at intervals such as 0.2 in order to provide stability across the 
               network. If the time delta or tick is calculated by saying "current time minus pervious
               time" the update would be different across every node if this calculation was provided 
               for each network node. We will use time delta increments of 0.2 to understand what
               occurs at each delta time increment across the entire simulation.
 
                Example: 
 
      If NodeA sends at a rate of 0.1 seconds to NodeB, then this packet will be sent at a rate of 10 times the normal rate or 15600bits per second.
      The packet will then be sent at 0.2 simulation time.
      The packet will maintain the throughput information related to the real time data.
      At the completion of every send function call the packet will be updated to maintain 
      a real time variable called m_timeTraversed this variable maints the integrity of the
      real time throughput being utitlized by the packet across the network.
      
      The transmit method called send(A,B) accumulates 
      the realtime data. This accumulation occurs within the packet structure.

      Example continued: NodeA sends to NodeB at 0.1 seconds. NodaB sends to NodeC at a rate of 2                         times the normalized speed or 0.5 seconds or 3120 bits per second.
                     NodeA sends to NodeB at a rate of 15600 bits per second. This means that
                     NodeB will complete its transmission after 0.5seconds have passed. Therefore
                     NodeA will complete its transmission to NodeC after 0.6 seconds. Or 0.6*1560bits
                     per second = 936bits per second. 

                         Simulation Time:
                
                         At time 0
                           No packet is sent.
 
                         At time 0.2
                           Packet is stored into NodeB inside the NetworkMesh.
                           This packet has a data member that contains the number 0.1(throughput).
                           0.1 is the amount of real time it took to send the packet and 
                           correlates to sending a packet at 10 times the normalized packet
                           send speed. This packet is sent at simulation time 0.2, but the throughput
                           is stored into the packet. The packet maintains the 'actual' throughput
                           as the packet traverses the network in simulated time. The simulation
                           provides a close to accurate send and rcv time for the node traversal
                           otherwise known as the 'hop'.
                           
                         At time 0.4
                           No packet is sent, since NodeB needs 0.1(A send rate to B) +
                                                                  (time for B to send to C).
                           In this case,
                           Node B would only be able to send when the condition 0.1 + 0.5 is true.
                           Since the simulated time is less than the time required to send the packet.
                           The packet will not be sent. 
 
                           At time 0.6
                           The packet can be sent to NodeC since the condition ( A -> B -> C) to
                           traverse is true.
                           Packet is stored into NodeC inside the NetworkMesh. The NetworkMesh
                           has a node registry of all nodes in the mesh.
                           This packet has reached its destination(scanned inside the send method).
                           The packet will report successful send to the simulation.
                          
                           Currently the packet indicates a successful send transmission by
                           reporting to the simulation a boolean value set as true when the
                           packet reached its destination. This reporting by the boolean return
                           allows the simulation to determine the throughput of one transmission.
                           The simulation could then use this information to influence the network
                           mesh as if a master node existed.
 
                           //TODO:The report is a structure with information regarding the nodes
                                  traversed.

           Once the time equals the termination time 0.6. The final storeReport will activate
           but the simulation will end.
 
           After termination the simulation will return the main menu after reporting simulation 
           termination information.
               
     // TODO: All delay is calculated within the initialization of the link establishment through the
              build simulation function.

     // TODO: Header size affecting transmission.

     // TODO: main.cpp line 168 prompt for user input.

     // TODO: main.cpp line 193 Implement Event triggers for network simulation.

     // TODO: simulation.cpp line 228 currently all update line code is in run not update.
 
     // TODO: simulation.cpp line 249 currently using literal 0 instead of iterator for loop.

     // TODO: simulation.cpp line 301 message reporting
  
     // TODO: simulation.cpp line 319 send packets at certain time simulation steps. 
                                           currently only sending at time 0.0 in the simulation.

     // TODO: networkMesh.cpp line 206 delete addNode() overload if necessary
 
     // TODO: netowrkMesh.cpp line 276 pathing availablility (currently in packet traverse header)

     // TODO: networkMesh.cpp line 296 doesNodeExist(const int& nodeId) does not detect deleted nodes.
 
     // TODO: networkMesh.cpp line 318 store reporting data to report structure

     // TODO: NodeAndLink.cpp line 295 error handling at the send receive level
 
     // TODO: NodeAndLink.cpp line 309 Network is built on one packet send for testing. Not multiple
                                                                                                send.

     // TODO: NodeAndLink.cpp line 319 Queueing buffer for multiple packets.

     // TODO: NodeAndLink.cpp line 338 Proper toggling of a network node's link usage.

     // TODO: networkMesh.h line 109 limit changes that can be made to node's parameters. 

     // TODO: NodeAndLink.h line 131 change the throughput to reflect each link established within the node.


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
  char userInput = '0';
  bool runSimulation = true;
  time_t current_time = 0;
  Simulation sim;
  time_t lengthOfSimulation = 0;

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
        /*case '1': 
               break;

        // Interaction with Network Mesh (add, delete, and change Node Parameters)
        case '2': 
               break;
        */
        case '1':
               sim.buildSimulation();
               break; 
        // Run Simulation // outputs? parameter duration for simulation.
         // Ask the user how long the simulation should run for, Remind user to use option 4 before 
           // running simulation.
        case '2':
               cout << '\n' << "How long would you like to run the simulation for? ";
               cin >> lengthOfSimulation; 
               current_time = time(NULL);
               cout<< "Test: "  << current_time << "seconds passed since processID" << '\n';
               sim.run(lengthOfSimulation);
               cout << sim;
               break;

        // Enter Events for the Network.
        case '3':
              // TODO:At time T influence the throughput of the network. 

              break;    

      // Print and Send Simulation data to file.  
        case '4':
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
  printPrompt(" 1. Build simulation. ");
  printPrompt(" 2: Run Simulation, currently testing print function. ");
  printPrompt(" 3. Enter Events for the Simulation. ");
  printPrompt(" 4. End Simulation. Print and Send Simulation data to the file ");
 
}


