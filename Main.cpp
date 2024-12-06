#include<iostream> //output library: a file of prewritten code
#include<string> //allows the use of getline and compare
#include<Windows.h> // allows pause, sound, and text color change
using namespace std; //cheat code that makes io stream easier to use

int Player_Health = 100;
int Player_Mental_Health = 25;
int Player_Stamana = 50;
int Player_Resets = 0;
int Player_Mana = 50;
bool Has_Visited_Room[100];
string pocket_invintory[4];
string backpack_invintory[10];

void Help();


int main() {//starting point of your program!
	srand(time(NULL));
	bool has_backpack = false;
	//for random spawn locations use bools as the conditional
	for (int i = 0; i <= 99; i++) {
		Has_Visited_Room[i] = false;
	}
	cout << "Welcome to the dream..." << endl << "We hope you have a good time..." << endl << endl;
	//cout << "You go to the window and find you are on the third floor of an apartment" << endl; //if window
	//cout << "It is dark but you can tell that you are no longer in the city" << endl; // time sleep continuation of if window
	string input;
	int room = 1;
	while (Player_Resets <= 5) {

		if (Player_Mana < 50) {
			Player_Mana++;
		}
		if (Player_Health <= 0) {
			Player_Resets++;
		}

		switch (room) {
		
		case 1://****************************************************************************
			//cout << "You are in a bedroom" << endl;
			if (!Has_Visited_Room[room - 1] && Player_Resets == 0) {
				do {
					cout << "You wake up in a bed, it is very dark" << endl;
					getline(cin, input);
					if (input == "light" || input.compare("make light") == 0) {
						cout << "You form a small ball of light in your hand." << endl << "With the light you can see an old desk next to the bed, a window that is covered by blinds to the west, a doorway to the east, and an attached wardorbe to the south";
						Player_Mana -= 2;

					}
					else {
						cout << "You try to move around, but it is too dark to see anything and you hit a wall hurting yourself" << endl;
						Player_Health--;
					}
				} while (!Has_Visited_Room[room - 1]);// first runthough of first room
			}
			getline(cin, input);
			if (input == "east" || input.compare("go east") == 0) {
				if (pocket_invintory[0] == "small key") {
					cout << "You go to the door and find it is locked, but the key you found in the desk fits perfectly and the door creaks open." << endl;
					room = 3;//go to hallway
				}
				else {
					cout << "You walk to the door and find it is locked" << endl;
				}
			}
			else if (input == "south" || input.compare("go south") == 0) {
				room = 2;//go to wardrobe
			}
			break;
		case 2://****************************************************************************
			//cout << "You are in the wardrobe" << endl;
			getline(cin, input);
			if (input == "north" || input.compare("go north") == 0)
				room = 1;//bedroom
			break;
		case 3://****************************************************************************
			//cout << "You are in the hallway" << endl;
			getline(cin, input);
			if (input == "northeast")
				room = 4;
			else if (input == "southeast")
				room = 5;
			else if (input == "west")
				room = 1;
			else if (input == "south")
				room = 6;
			break;
		case 4://****************************************************************************
			//cout << "You are in the bedroom" << endl;
			getline(cin, input);
			if (input == "west")
				room = 3;
			break;
		case 5://****************************************************************************
			//cout << "You are in the bathroom" << endl;
			getline(cin, input);
			if (input == "west")
				room = 3;
			break;
		case 6://****************************************************************************
			//cout << "You are in the living room" << endl;
			getline(cin, input);
			if (input == "north")
				room = 3;
			else if (input == "east")
				room = 9;
			else if (input == "west")
				room = 7;
			break;
		case 7://****************************************************************************
			//cout << "You are in the kitction" << endl;
			getline(cin, input);
			if (input == "north")
				room = 8;
			else if (input == "east")
				room = 6;
			break;
		case 8://****************************************************************************
			//cout << "You are in a hidden room" << endl;
			getline(cin, input);
			if (input == "south")
				room = 7;
			break;
		case 9://****************************************************************************
			//cout << "You are in the foyer" << endl;
			getline(cin, input);
			if (input == "west")
				room = 6;
			break;
		default:
			cout << "I don't know where this is" << endl;
			break;
		}//end of switch
	}//end of while loop
}//end of main


