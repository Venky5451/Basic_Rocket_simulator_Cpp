//Shre ganeshay namah//
#include <graphics.h> //For graphics simulation header file 
#include<sstream>     //Stringstream class is used for insertion and extraction of data to/from the string objects
#include<string.h>    //used for string handling or manipulation but also used for various memory handling operations.
#include<iostream>    //input output operations 
#include <fstream>   //data type represents the file stream generally
#include <cmath>     //matheamtical operations 

using namespace std;   //standard inclusion of all files using namespace 

int fndisplay(int fuel);  //function prototype for fuel display

class Rocket {           //class for storing information of rocket as mass
	public:
    string rocketName;    
    double payloadMass;
    double secondStageFuelMass;  
    double firstStageFuelMass;
    double legsMass;
    double engineMass;
    double fairingsMass;
    double gridFinsMass;
};

// Function to create a new rocket project and save the information to a file
void createRocketProject() {
    Rocket rocket;   // object created for class rocket 

    cout << "Enter rocket name: ";
    cin >> rocket.rocketName;          // name of rocket

    cout << "Enter payload mass (in kg): ";
    cin >> rocket.payloadMass;        // payload mass

    cout << "Enter second stage fuel mass (including propellant) (in kg): ";
    cin >> rocket.secondStageFuelMass; //second stage fuel

    cout << "Enter first stage fuel mass (in kg): ";
    cin >> rocket.firstStageFuelMass;  // first stage mass

    cout << "Enter legs mass (in kg): ";
    cin >> rocket.legsMass;  //legs

    cout << "Enter engine mass (in kg): ";
    cin >> rocket.engineMass; //engine mass

    cout << "Enter fairings mass (in kg): ";
    cin >> rocket.fairingsMass; //fairings

    cout << "Enter grid fins mass (in kg): ";
    cin >> rocket.gridFinsMass; //fins

    // Save the rocket information to a file
    ofstream file("rocket_data.txt", ios::app);   //ios::app is opening of file in append mode //oftream create files in current working directory 
                                                 // file object is created
    if (file.is_open()) {    // checks if file is open then 
        file << rocket.rocketName << " "   //writes data in file 
            << rocket.payloadMass << " "
            << rocket.secondStageFuelMass << " "
            << rocket.firstStageFuelMass << " "
            << rocket.legsMass << " "
            << rocket.engineMass << " "
            << rocket.fairingsMass << " "
            << rocket.gridFinsMass << endl;

        file.close();   // close file

        cout << "Rocket information saved successfully!" << endl;
    }
    else {                   // exception handling
        cout << "Error opening the file." << endl;  
    }
}

// Function to display information about a specific rocket
void displayRocketInformation(const string& rocketName) {
    ifstream file("rocket_data.txt");   //ifstream to input data from file 
    string name;

    if (file.is_open()) {
        while (file >> name) {  //if the file is open, the code enters a while loop: while (file >> name). This loop continues as long as there is data in the file to read. It reads the contents of the file into the variable name in each iteration.
            if (name == rocketName) {
                double payloadMass, secondStageFuelMass, firstStageFuelMass, legsMass, engineMass, fairingsMass, gridFinsMass;//creating variables to store values

                file >> payloadMass >> secondStageFuelMass >> firstStageFuelMass //read data from file after every space 
                    >> legsMass >> engineMass >> fairingsMass >> gridFinsMass;

                cout << "Rocket Name: " << rocketName << endl;                                                          // display info
                cout << "Payload Mass: " << payloadMass << " kg" << endl;
                cout << "Second Stage Fuel Mass (including propellant): " << secondStageFuelMass << " kg" << endl;
                cout << "First Stage Fuel Mass: " << firstStageFuelMass << " kg" << endl;
                cout << "Legs Mass: " << legsMass << " kg" << endl;
                cout << "Engine Mass: " << engineMass << " kg" << endl;
                cout << "Fairings Mass: " << fairingsMass << " kg" << endl;
                cout << "Grid Fins Mass: " << gridFinsMass << " kg" << endl;

                file.close();
                return;
            }
        }

        cout << "Rocket not found." << endl;     // exception handling
        file.close();
    }
    else {
        cout << "Error opening the file." << endl;
    }
}

// Function to display the total mass of a specific rocket
double getTotalRocketMass(const string& rocketName) {
    ifstream file("rocket_data.txt");
    string name;

    if (file.is_open()) {
        while (file >> name) {
            if (name == rocketName) {
                double payloadMass, secondStageFuelMass, firstStageFuelMass, legsMass, engineMass, fairingsMass, gridFinsMass;

                file >> payloadMass >> secondStageFuelMass >> firstStageFuelMass
                    >> legsMass >> engineMass >> fairingsMass >> gridFinsMass;

                file.close();

                double totalMass = payloadMass + secondStageFuelMass + firstStageFuelMass   // to display total mass
                    + legsMass + engineMass + fairingsMass + gridFinsMass;

                return totalMass;
            }
        }

        cout << "Rocket not found." << endl;
        file.close();
    }
    else {
        cout << "Error opening the file." << endl;
    }

    return 0.0;
}

// Function to launch the rocket and calculate flight parameters

void launchRocket(const string& rocketName) {   
    ifstream file("rocket_data.txt");
    string name;

    if (file.is_open()) {
        while (file >> name) {
            if (name == rocketName) {
                double payloadMass, secondStageFuelMass, firstStageFuelMass, legsMass, engineMass, fairingsMass, gridFinsMass;

                file >> payloadMass >> secondStageFuelMass >> firstStageFuelMass
                    >> legsMass >> engineMass >> fairingsMass >> gridFinsMass;

                file.close();

                // Additional parameters for the rocket launch
                double engineThrust;
                double gravity;
                double atmosphericPressure;

                cout << "Enter engine thrust (in N): ";
                cin >> engineThrust;

                cout << "Enter gravity (in m/s^2): ";
                cin >> gravity;

                cout << "Enter atmospheric pressure (in Pa): ";
                cin >> atmosphericPressure;

                // Calculating flight parameters
                double totalMass = getTotalRocketMass(rocketName);   //fetches total rocket masss from previous function 
                double engineEfficiency = engineThrust / (totalMass * gravity);    
                double flightTime = sqrt(2 * totalMass / (engineThrust * engineEfficiency));
                double altitudeReached = (engineThrust * flightTime * flightTime) / (2 * totalMass);  // formulas 

                // Displaying flight parameters
                cout << "Rocket Name: " << rocketName << endl;
                cout << "Total Mass: " << totalMass << " kg" << endl;
                cout << "Engine Efficiency: " << engineEfficiency << endl;
                cout << "Flight Time: " << flightTime << " s" << endl;
                cout << "Altitude Reached: " << altitudeReached << " m" << endl;
                
                
                

                return ;
            }
        }

        cout << "Rocket not found." << endl;
        file.close();
    }
    else {
        cout << "Error opening the file." << endl;
    }
}



// driver code
int main()
{  int choice;
    string rocketName;

    do {    // initian menu interface
        cout << "Rocket Information and Simulation Software System" << endl;
        cout << "1. Create New Rocket Project" << endl;
        cout << "2. Display Rocket Information" << endl;
        cout << "3.Rocket flight Parameters Calculator" << endl;
        cout << "4. Graphical Simulatation" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {    // switch case to toggle menu
        case 1:
            createRocketProject();
            break;
        case 2:
            cout << "Enter rocket name: ";
            cin >> rocketName;
            displayRocketInformation(rocketName);
            break;
        case 3:
            cout << "Enter rocket name: ";
            cin >> rocketName;
            launchRocket(rocketName);
            break;
        case 4:
            cout << "Entering Simulation in 3.....2......1......Launch" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << endl;
    } while (choice != 4);

    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
    int gd = DETECT, gm;
    
    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    initgraph(&gd, &gm, (char*)"");
    floodfill(90,420,14);


	
	int fuel;
	outtextxy(90,420,"Enter fuel in terminal in liters");
	cin>>fuel;
	if (fuel>=0){
	

    for(int i=1;i<=200;i++)//ground initial 
 {   // line for x1, y1, x2, y2
    line(50, 450, 550, 450);//ground 
     line(50, 10, 550, 10);
    outtextxy(90,420,"Grouynd zero kilo metre");
    line(80,450,80,-10010);//scale
    line(250,400-i,250,250-i);//parallel lines
    line(300,400-i,300,250-i);//parallel loiones
    line(250,250-i,300,250-i);//horizontal
    line(300,250-i,275,200-i);//nose
    line(250,250-i,275,200-i);//nose
    line(250,400-i,300,400-i);
    line(275,400-i,250,450-i);
    line(275,400-i,300,450-i);

    delay(2);
    cleardevice();
    if(i==200){    
	line(50, 450, 550, 450);//ground 
    line(50, 10, 550, 10);
    line(80,450,80,-10010);//scale
    line(250,400-i,250,250-i);//parallel lines
    line(300,400-i,300,250-i);//parallel loiones
    line(250,250-i,300,250-i);//horizontal
    line(300,250-i,275,200-i);//nose
    line(250,250-i,275,200-i);//nose
    line(250,400-i,300,400-i);
    line(275,400-i,250,450-i);
    line(275,400-i,300,450-i);
	}}
int hgt=fuel;

  
  
  	    for(int i=1;i<=1000;i++)//ground second
 {   // line for x1, y1, x2, y2
    line(50, 450, 550, 450);//ground second
     line(50, 10, 550, 10);

  

    line(80,450,80,-10010);//scale
    //Rocket
    line(250,400+450-i,250,250+450-i);//parallel lines
    line(300,400+450-i,300,250+450-i);//parallel loiones
    line(250,250+450-i,300,250+450-i);//horizontal
    line(300,250+450-i,275,200+450-i);//nose
    line(250,250+450-i,275,200+450-i);//nose
    line(250,400+450-i,300,400+450-i);
    line(275,400+450-i,250,450+450-i);
    line(275,400+450-i,300,450+450-i);
    // structure
    delay(2);
    cleardevice();
    if(i==600){       
	 line(50, 450, 550, 450);//ground second
     line(50, 10, 550, 10);
    line(80,450,80,-10010);//scale
    //Rocket
    line(250,400+450-i,250,250+450-i);//parallel lines
    line(300,400+450-i,300,250+450-i);//parallel loiones
    line(250,250+450-i,300,250+450-i);//horizontal
    line(300,250+450-i,275,200+450-i);//nose
    line(250,250+450-i,275,200+450-i);//nose
    line(250,400+450-i,300,400+450-i);
    line(275,400+450-i,250,450+450-i);
    line(275,400+450-i,300,450+450-i);
	}
   

for(hgt=1;hgt<=fuel;hgt++)/* height for */
{   
    for(int i=1;i<=1000;i++)//ground second
 {   // line for x1, y1, x2, y2
    line(50, 450, 550, 450);//ground second
     line(50, 10, 550, 10);
   //height       
  int number=(hgt*10);              // conversion of string to char 
  stringstream strs;
  strs << number;
  string temp_str = strs.str();
  char* char_type = (char*) temp_str.c_str();    // updates heights 
    outtextxy(90,420,char_type);
    //h end 
    line(80,450,80,-10010);//scale
    //Rocket
    line(250,400+450-i,250,250+450-i);//parallel lines
    line(300,400+450-i,300,250+450-i);//parallel loiones
    line(250,250+450-i,300,250+450-i);//horizontal
    line(300,250+450-i,275,200+450-i);//nose
    line(250,250+450-i,275,200+450-i);//nose
    line(250,400+450-i,300,400+450-i);
    line(275,400+450-i,250,450+450-i);
    line(275,400+450-i,300,450+450-i);
    // structure
    delay(2);
    cleardevice();
    if(i==600){       
	 line(50, 450, 550, 450);//ground second
     line(50, 10, 550, 10);
    line(80,450,80,-10010);//scale
    //Rocket
    line(250,400+450-i,250,250+450-i);//parallel lines
    line(300,400+450-i,300,250+450-i);//parallel loiones
    line(250,250+450-i,300,250+450-i);//horizontal
    line(300,250+450-i,275,200+450-i);//nose
    line(250,250+450-i,275,200+450-i);//nose
    line(250,400+450-i,300,400+450-i);
    line(275,400+450-i,250,450+450-i);
    line(275,400+450-i,300,450+450-i);
    
    // to displayu final informationn
    if(hgt==fuel){ closegraph();
    
    // final display 
     fndisplay(fuel);
     getch();    
        }
      }
	}
  }
}

}
    getch();
}
    // function for final display of simulation screen
	int fndisplay(int fuel)
	{
	int gd = DETECT, gm;
    
    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    initgraph(&gd, &gm, (char*)"");
	outtextxy(90,240,"The rocket reached only  ");

	int number=(fuel*10);
    stringstream strs;
    strs << number;
    string temp_str = strs.str();
    char* char_type = (char*) temp_str.c_str();
    outtextxy(90,270,char_type);
    outtextxy(110,270,"kms , came down crashed after then");
	return 0;	
	}