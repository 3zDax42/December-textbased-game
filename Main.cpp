#include<iostream> //output library: a file of prewritten code
using namespace std; //cheat code that makes io stream easier to use

int Player_Health = 100;
int Player_Mental_Health = 25;
int Player_Stamana = 50;
int Player_Resets = 0;
string pocket_invintory[4];
string backpack_invintory[10];


int main() {//starting point of your program!
	
	//for random spawn locations use bools as the conditional
	cout << "Welcome to the dream..." << endl << "We hope you have a good time..." << endl << endl;
	cout << "You turn on the lights and find the room to be unfimiliar." << endl; // if turn on lights
	cout << "There is a door to the east a closet to the south and a window to the west" << endl; // if look
	cout << "You go to the window and find you are on the third floor of an apartment" << endl; //if window
	cout << "It is dark but you can tell that you are no longer in the city" << endl; // time sleep continuation of if window
	cout << "You try to open the door and find it is locked" << endl; //if door
	string input;
	int room = 1;
	while (true) {
		switch (room) {
		case 1:
			cout << "You wake up in a bed, it is very dark" << endl;
			//cout << "You are in a bedroom" << endl;
			cin >> input;
			if (input == "light") {
				cout << "You form a small ball of light in your hand." << endl << "With the ";
			}
			if (input == "east")
				room = 3;
			else if (input == "south")
				room = 2;
			break;
		case 2:
			//cout << "You are in the wardrobe" << endl;
			cin >> input;
			if (input == "north")
				room = 1;
			break;
		case 3:
			//cout << "You are in the hallway" << endl;
			cin >> input;
			if (input == "northeast")
				room = 4;
			else if (input == "southeast")
				room = 5;
			else if (input == "west")
				room = 1;
			else if (input == "south")
				room = 6;
			break;
		case 4:
			//cout << "You are in the bedroom" << endl;
			cin >> input;
			if (input == "west")
				room = 3;
			break;
		case 5:
			//cout << "You are in the bathroom" << endl;
			cin >> input;
			if (input == "west")
				room = 3;
			break;
		case 6:
			//cout << "You are in the living room" << endl;
			cin >> input;
			if (input == "north")
				room = 3;
			else if (input == "east")
				room = 9;
			else if (input == "west")
				room = 7;
			break;
		case 7:
			//cout << "You are in the kitction" << endl;
			cin >> input;
			if (input == "north")
				room = 8;
			else if (input == "east")
				room = 6;
			break;
		case 8:
			//cout << "You are in a hidden room" << endl;
			cin >> input;
			if (input == "south")
				room = 7;
			break;
		case 9:
			//cout << "You are in the foyer" << endl;
			cin >> input;
			if (input == "west")
				room = 6;
			break;
		default:
			cout << "I don't know where this is" << endl;
			break;
		}//end of switch
	}//end of while loop
}//end of main


