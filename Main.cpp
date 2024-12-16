#include<iostream> //output library: a file of prewritten code
#include<string> //allows the use of getline and compare
#include<Windows.h> // allows pause, sound, and text color change
using namespace std; //cheat code that makes io stream easier to use

//Globals
int Player_Health = 100;
int Player_Mental_Health = 25;
int Player_Stamana = 50;
int Player_Resets = 0;
int Player_Mana = 50;
int Mana_Stones_Greater = 0;
int Mana_Stones_Lesser = 0;
bool Has_Visited_Room[100];
bool Strong_Poison = false;
bool Weak_Poison = false;
string pocket_invintory[4];
string backpack_invintory[10];
//Functions
void Help();
void Status();
//void Shop();
void Random_item_gen();
void Single_String_Knot_AsciiArt();



int main() {//starting point of your program!
	srand(time(NULL));
	bool Can_See;
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
	while (Player_Resets <= 5) {//****Runs every time

		if (Player_Mana < 50) {
			Player_Mana++;
		}
		if (Player_Health <= 0) {
			Player_Resets++;
		}
		if (Weak_Poison == true) {
			Player_Health--;
		}
		if (Strong_Poison == true) {
			Player_Health -= 3;
		}


		//****Runs every time
		switch (room) {

		case 1://********************************************************************************************************************************************
			//cout << "You are in a bedroom" << endl;
			if (!Has_Visited_Room[room - 1] && Player_Resets == 0) {
				Beep(1600, 300);
				Beep(1600, 200);
				Beep(1600, 300);
				Beep(1600, 200);
				system("pause");
				cout << "You wake up in a bed, it is very dark" << endl;
				Can_See = false;
				do {
					getline(cin, input);
					if (Can_See == false) {
						if ((input == "light" || input.compare("make light") == 0) && Can_See == false) {
							cout << "You form a small ball of light in your hand." << endl << "With the light you can see an old desk next to the bed, a window that is covered by blinds to the west, a doorway to the east with a light swich, and an attached wardorbe to the south" << endl;
							Player_Mana -= 2;
							Can_See = true;
							Has_Visited_Room[room - 1] = true;
						}
						else if (input == "help") {
							Help();
						}
						else if (input == "status") {
							Status();
						}
						else if (input == "look" || input.compare("look around") == 0) {
							if (Can_See == false) { cout << "it is very dark and you can't see" << endl; }
							else { cout << "There is an old desk next to the bed, a window that is covered by blinds to the west, a doorway to the east with a light swich, and an attached wardorbe to the south" << endl; }
						}
						else {
							cout << "You try to move around, but it is too dark to see anything and you hit a wall hurting yourself" << endl;
							Player_Health--;
						}
					}
					else if (input == "help") {
						Help();
					}
					else if (input == "status") {
						Status();
					}

				} while (!Has_Visited_Room[room - 1]);// first runthough of first room
			}
			getline(cin, input);
			if (input == "east" || input.compare("go east") == 0) {
				if (pocket_invintory[0] == "small key" && !Has_Visited_Room[room+1]) {
					cout << "You go to the door and find it is locked, but the key you found in the desk fits perfectly and the door creaks open." << endl;
					room = 3;//go to hallway
					Has_Visited_Room[room - 1] = true;
				}
				else if (pocket_invintory[0] == "small key") {
					cout << "The door creaks as it opens" << endl;
					room = 3;//go to hallway
					Has_Visited_Room[room - 1] = true;
				}
				else {
					cout << "You walk to the door and find it is locked" << endl;
				}
			}
			else if (input == "south" || input.compare("go south") == 0) {
				room = 2;//go to wardrobe
				Has_Visited_Room[room - 1] = true;
			}
			else if (input == "window" || input.compare("look out window") == 0) {
				cout << "Pulling aside the blinds you see nothing out the window. Nothing exept an black abiss that seems to consume everything." << endl;
				cout << "What is this place?" << endl;
				system("pause");
				cout << "How did I get here?" << endl;
				system("pause");
				cout << "Is this a dream?" << endl;
			}
			else if (input == "look" || input.compare("look around") == 0) {
				cout << "There is an old desk next to the bed, a window that is covered by blinds to the west, a doorway to the east with a light swich, and an attached wardorbe to the south" << endl;
			}
			else if (input == "help") {
				Help();
			}
			else if (input == "status") {
				Status();
			}
			else if (input == "desk" || input.compare("look at desk") == 0) {
				if (pocket_invintory[0] == "small key") {
					cout << "You look in the desk" << endl << "There is a bunch of trash in the desk but nothing else of note" << endl;
				}
				else {
					cout << "On the desk there seems to be a small bag" << endl << "Picking it up you see it has a peculiar pattern on it and it gives off a unique mana signature" << endl << "Looking in the desk you see there is a bunch of trash filling it, but a small shiny object cheches you eye" << endl << "You grab the item and find it to be a small key ..... maybe it will be usefull somewhere";
					Single_String_Knot_AsciiArt();
					pocket_invintory[0] = "small key";
					pocket_invintory[1] = "spatial bag";
				}
			}
			else {
				cout << "You should stop hurting your self" << endl;
				Player_Health--;
			}
			
			break;
		case 2://********************************************************************************************************************************************
			if (!Has_Visited_Room[room - 1]) {
				cout << "Walking into the wardrobe you see a few old coats hungs up. They all seem to be infested with mothballs." << endl << "On the ground you see a backpack and mana stones scattered on the ground." << endl;
			}
			else {
				cout << "You walk into the wardrobe" << endl;
			}
			getline(cin, input);
			if (!Has_Visited_Room[room - 1]) {

			}
			else if (input == "north" || input.compare("go north") == 0) {
				room = 1;//bedroom
				Has_Visited_Room[room - 1] = true;
			}
			
			else if (input == "help") {
				Help();
			}
			else if (input == "status") {
				Status();
			}
			break;
		case 3://********************************************************************************************************************************************
			cout << "You are in the hallway" << endl;

			getline(cin, input);
			if (input == "northeast" || input.compare("go northeast") == 0) {
				room = 4;
			}
			else if (input == "southeast" || input.compare("go southeast") == 0) {
				room = 5;
			}
			else if (input == "west" || input.compare("go west") == 0) {
				room = 1;
			}
			else if (input == "south" || input.compare("go south") == 0) {
				room = 6;
			}
			break;
		case 4://********************************************************************************************************************************************
			//cout << "You are in the bedroom" << endl;
			getline(cin, input);
			if (input == "west" || input.compare("go west") == 0)
				room = 3;
			break;
		case 5://********************************************************************************************************************************************
			//cout << "You are in the bathroom" << endl;
			getline(cin, input);
			if (input == "west" || input.compare("go west") == 0)
				room = 3;
			break;
		case 6://********************************************************************************************************************************************
			//cout << "You are in the living room" << endl;
			getline(cin, input);
			if (input == "north" || input.compare("go north") == 0)
				room = 3;
			else if (input == "east" || input.compare("go east") == 0)
				room = 9;
			else if (input == "west" || input.compare("go west") == 0)
				room = 7;
			break;
		case 7://********************************************************************************************************************************************
			//cout << "You are in the kitction" << endl;
			getline(cin, input);
			if (input == "north" || input.compare("go north") == 0)
				room = 8;
			else if (input == "east" || input.compare("go east") == 0)
				room = 6;
			break;
		case 8://********************************************************************************************************************************************
			//cout << "You are in a hidden room" << endl;
			getline(cin, input);
			if (input == "south" || input.compare("go south") == 0)
				room = 7;
			break;
		case 9://********************************************************************************************************************************************
			//cout << "You are in the foyer" << endl;
			getline(cin, input);
			if (input == "west" || input.compare("go west") == 0)
				room = 6;
			else if (input == "east" || input.compare("go east") == 0)
				room = 10;
			break;
		case 10://*******************************************************************************************************************************************
			//cout << "You are in the apartment hallway" << endl;
			getline(cin, input);
			if (input == "west" || input.compare("go west") == 0)
				room = 9;
			break;
		default:
			cout << "I don't know where this is" << endl;
			break;
		}//end of switch
	}//end of while loop
	cout << " ----- End Of Game ----- " << endl;
}//end of main


void Help() {
	cout << "Type in \"west\", or \"go west\" to move rooms" << endl;
	cout << "Type in \"east\", or \"go east\" to move rooms" << endl;
	cout << "Type in \"north\", or \"go north\" to move rooms" << endl;
	cout << "Type in \"south\", or \"go south\" to move rooms" << endl;
	cout << "Type in \"status\" to veiw your Health, Stamana and Mana" << endl;
	cout << "Type in \"look\", or \"look around\" to hear what the room looked like again" << endl;

}
void Status() {
	cout << "Your health is " << Player_Health << endl << "Your stamana is " << Player_Stamana << endl << "Your mana is " << Player_Mana << endl;
	if (Strong_Poison == true || Weak_Poison == true) {
		cout << "You feel as if breathing is geting harder by the second" << endl;
	}
}
//void Shop() {
//	cout << endl << "-----" << "Welcome to the shop...(use charactors)" << "-----" << endl;
//	char input = 'e';
//	cout << "" << endl << "" << endl;
//	cin >> input;
//	while (input != 'q' || input == 'n') {
//		cout << "We have this ." << endl << "Or would you prefer this ?" << endl;
//		cin >> input;
//		switch (input) {
//		case 'c':
//			if ( >= ) {
//				
//			}
//			else {
//				cout << "Are you tring to cheat me of my stuff? Get out of here." << endl << endl << "...The Shopkeeper kicks you out...";
//				input = 'q';
//			}
//		case 'm':
//			if ( >= ) {
//				
//			}
//			else {
//				cout << "Are you tring to cheat me of my stuff? Get out of here." << endl << endl << "...The Shopkeeper kicks you out...";
//				input = 'q';
//			}
//			break;
//		}//end of switch
//
//	}//end of loop
//}
void Random_item_gen() {
	int num = rand() % 100 + 1;
	if (num > 95) {//5% chance
		cout << "You see an empty vase rolled over on it's side" << endl << "Appon further inpsection you find a spider in the vase" << endl << "Frightend the spider runs out, bites you and runs off";
		if (num > 99) {
			Player_Health -= 2;
			Weak_Poison = true;
			cout << "The bite is exteamly painful and blackens the skin that was biten" << endl;
		}
		else {
			Player_Health -= 2;
			cout << "The bite stings a bit" << endl;
		}
	}
	else if (num > 85) {//10% chance
		Mana_Stones_Greater++;
		cout << "You find a high quality mana stone laying on the ground" << endl;
	}
	else if (num > 70) {//15% chance
		Mana_Stones_Lesser += 20;
		cout << "You find a large pile of low quality mana stones" << endl;
	}
	else if (num > 50) {//20% chance
		Mana_Stones_Lesser += 10;
		cout << "You find a pile of low quality mana stones" << endl;
	}
}
void Single_String_Knot_AsciiArt() {
	cout << endl ;
	cout << "        ___________" << endl;
	cout << "       |           |" << endl;
	cout << "       |    ___    |" << endl;
	cout << "       |   |   |   |" << endl;
	cout << " ______|   |___|___|______" << endl;
	cout << "|      |   |              |" << endl;
	cout << "|   ___|   |_______ ___   |" << endl;
	cout << "|  |   |   |   |   |   |  |" << endl;
	cout << "|  |___|___|___|   |___|  |" << endl;
	cout << "|              |   |      |" << endl;
	cout << "|______________|   |______|" << endl;
	cout << "       |   |   |   |" << endl;
	cout << "       |   |___|   |" << endl;
	cout << "       |           |" << endl;
	cout << "       |___________|" << endl;

}
//void number_puzzle() {
//	int limit = 60;
//	auto start = chrono::steady_clock::now();
//	int num = rand() % 20 + 1;
//	int guess = -1;
//	int timeleft = 60;
//	while (guess != num && timeleft > 0){
//		auto now = chrono::steady_clock::now();
//		timeleft = limit - chrono::duration_cast <chrono::seconds> (now - start).count();
//		cin >> guess;
//		if (guess != num) {
//			cout << "Incorrect" << endl;
//			cout << "time left:" << timeleft << endl;
//		}
//		else {
//			cout << "Correct"
//		}
//	}
//}
