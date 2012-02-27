#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int random(int, int);
int main() {
	srand((unsigned)time(0));
	string input; string weapon;
	int hp = 15 + random(1, 20); int hpmax = hp; int mp = 10 + random(1, 20);int mpmax = mp; int exp = 0; int gold = 5 + random(1, 12);
	switch(random(1, 4)){
		case 1: case 2: weapon = "club"; break;
		case 3: case 4: weapon = "longsword"; break;
	}


	begin:
	cout << "You arrive in town\n\n";
	begin1:
	cout << ">";
	cin >> input;

	if (input == "help") {
		cout << "Commands are:\n";
		cout << "'road' - leave town in search of battles\n";
		cout << "'inn' - takes you to the inn, where you can heal\n";
		cout << "'shop - takes you to the shop\n";
		cout << "'info' - view your currently equiped weapon and current exp, gold, hp, and mp.\n";
		cout << "'quit' - quit the game\n\n";
		goto begin1;
	}
	/*else if (input == "debug"){
		hp = 1000;
		mp = 1000;
		gold = 1000;
		exp = 1000;
		goto begin1;
	}*/
	else if (input == "inn"){
		cout << "Welcome to the inn lad, would you like to stay a night? Only a mere 5 gold coins.\n\n";
		cout << ">";
		cin >> input;
		if ((input == "yes" && gold >= 5) || (input == "y" && gold >= 5)){
			hp = hpmax; mp = mpmax; gold = gold -5;
			cout << "You slept the night and feel refreshed.\n\n";
			goto begin;
		}
		else if (input == "no" || input == "n" || input == "back"){
			cout << "No? Too bad, come back some other time!\n\n";
			goto begin;
		}
		else if( gold < 5){
			cout << "You don't seem to have any gold, go fight some and get a bit, be sure to come back.\n\n";
			goto begin;
		}
		else {
			cout << "What kind of gibberish are you speaking, come back when you have your head on right.\n\n";
			goto begin;}
	}
	else if (input == "shop"){
		shop:
		cout << "Welcome to my humble shop, I have a little bit of everything. Have a 'look' around.\n\n";
		cout << ">";
		cin >> input;
		if (input == "look"){
			cout << "You see:\n";
			cout << "A 'club'\n";
			cout << "A 'longsword'\n\n";
			cout << ">";
			cin >> input;
			if (input == "club"){
				cout << "You fancy buying the club? That'll cost you 7 gold.\n\n";
				cout << ">";
				cin >> input;
				if (input == "y"  || input == "yes"){
					if (weapon == "club"){
						cout << "You already seem to have this weapon friend.\n\n";
						goto shop;
					}
					else if (gold >= 7){
						gold = gold - 7;
						weapon = "club";
						cout << "Thanks for buying that!\n\n";
						goto shop;
					}
					else {
						cout << "You don't seem to have enough money, what a shame.\n\n";
						goto shop;
					}
				}
				else if (input == "n" || input == "no"){
					cout << "No? Too bad, it's a fine weapon.\n\n";
					goto shop;
				}
				else {
					cout << "Come back later when you speak like a normal person.\n\n";
					goto begin;
				}
			}
			else if (input == "longsword"){
				cout << "You fancy buying the longsword? That'll cost you 15 gold.\n";
				cout << ">";
				cin >> input;
				if (input == "y"  || input == "yes"){
					if (weapon == "longsword"){
						cout << "You already seem to have this weapon friend.\n";
						goto shop;
					}
					else if (gold >=15){
						gold = gold - 15;
						weapon = "longsword";
						cout << "Thanks for buying that!\n";
						goto shop;
					}
					else {
						cout << "You don't seem to have enough money, what a shame.\n";
						goto shop;
					}
				}
				else if (input == "n" || input == "no"){
					cout << "No? Too bad, it's a fine weapon.\n";
					goto shop;
				}
				else {
					cout << "Come back later when you speak like a normal person.\n\n";
					goto begin;
				}
			}
			else if (input == "leave" || input == "back"){
				cout << "Come back again sometime!\n\n";
				goto begin;
			}
			else {
				cout << "Come back later when you speak like a normal person.\n\n";
				goto begin;
			}
		}
		else if (input == "leave" || input == "back"){
			cout << "Goodbye. Come again!\n\n";
			goto begin;
		}
		else {
			cout << "Come back later when you speak like a normal person.\n\n";
			goto begin;
		}
	}
	else if (input == "hp" || input == "mp" || input == "exp" || input == "gold" || input == "wep" || input == "weapon" || input == "info"){
		cout << "You have " << exp << " exp, " << gold << " gold, " << hp << " hp, " << mp << " mp.\n";
		cout << "You are currently wielding a " << weapon << ".\n\n";
		goto begin1;
	}
	else if (input == "quit"){
		return 0;
	}
	else if (input == "road"){
		cout << "You have left the village.\n";
		goto road;
	}
	else{
		cout << "That's not a valid command, type help to see the commands\n\n";
		goto begin1;
	}


	road:
	cout << "The road only goes one way, into a 'forest'.\n\n";
	cout << ">";
	cin >> input;
	string area = input;
	//battle integers
	int enemyattack;
	int enemyspell;
	int enemyhp;
	int goldget;
	int expget;
	string mon;
	string enemyspelltxt;
	string enemyattacktxt;
	if(area == "forest"){
		cout << "You have entered the forest and ";
		switch(random (1, 6)){
		case 1:case 2:
			cout << "encountered a Giant Rat!\n";
			enemyhp = random(1, 8) + 8;
			goldget = random(1, 6);
			expget = 10;
			mon = "rat";
			break;
		case 3:
			cout << "encountered a Wild Boar!\n";
			enemyhp = random(1, 8) + 6;
			goldget = random(1, 6) + 1;
			expget = 10;
			mon = "wildboar";
			break;
		case 4:
			cout << "encountered a Snake!\n\n";
			enemyhp = random(1, 6) + 12;
			goldget = random(1, 6) + 2;
			expget = 5;
			mon = "snake";
			break;
		case 5:
			cout<< "encountered a Tree Spider!\n\n";
			enemyhp = 15;
			goldget = random(1, 6) - 2;
			expget = 15;
			mon = "treespider";
			break;
		case 6:
			cout << "encountered an Elfling!\n\n";
			enemyhp = random(1, 8) + 15;
			goldget = random(1, 6) + 3;
			expget = 20;
			mon = "elfling";
			break;
		}
	}
	/*else if (area == "mountains"){

	}
	else if (area == "meadows"){

	}*/
	else {
		cout << "No such area has been discovered, yet!\n\n";
		goto road;
	}

	do {
		//Monster Stats
		if(mon == "elfling"){
			enemyattack = random(1, 8);
			enemyattacktxt = "You were stabbed for ";
			enemyspell = random(1, 8) + 2;
			enemyspelltxt = "You were shot for ";
		}
		else if(mon == "rat"){
			enemyattack = random(1, 6);
			enemyattacktxt = "You were scratched for ";
			enemyspell = random(1, 6) + 1;
			enemyspelltxt = "You were bit for ";
		}
		else if(mon == "snake"){
			 enemyattack = random(1, 6) + 1;
			 enemyattacktxt = "you were bit for ";
			 enemyspell = random(1, 8);
			 enemyspelltxt = "You were poisoned for ";
	 	 }
		else if (mon == "treespider"){
			enemyattack =  random(1, 8) - 1;
			enemyattacktxt = "You were bit for ";
			enemyspell = random(1, 8) + 1;
			enemyspelltxt = "Tree Spider spit acid on you damaging you for ";
		 }
		else if (mon == "wildboar"){
			enemyattack = random(1, 4) + 2;
			enemyattacktxt = "you were gored for ";
			enemyspell = random(1, 6) + 2;
			enemyspelltxt = "The Wild Boar has gone berserk and rammed you for ";
		}

		//Player Stats
		int weapondmg;
		if (weapon == "club") weapondmg = random(1,6);
		else if (weapon == "longsword") weapondmg = random(1,8);
		int heal = random(1, 6);
		int magicmissile = random(1, 6) + 2;

		//d20 Attack rolls
		int attackroll = random(1, 20);
		int enemyattackroll = random(1, 20);

		cout << ">";
		cin >> input;

		if (input == "help"){
			cout << "Commands are:\n";
			cout << "'attack' or 'atk' - attack the enemy.\n";
			cout << "'heal' - heal yourself.\n";
			cout << "'run' - attempt to run from battle.\n";
			cout << "'magicmissile' or 'mm' - cast magic missile on the enemy.\n";
			cout << "'hp', 'mp', or 'info' - view your hp and mp.\n\n";
		}
		/*else if (input == "debug"){
			goto loop2;
		}*/
		else if (input == "run"){
			if (random(1, 20) >= 12){
				cout <<"You ran away.\n\n";
				goto begin;
			}
			else{
				cout <<"You failed to run away.\n";
				if (enemyattackroll >= 10){
					if(random(1, 12) <= 7){
						cout << enemyattacktxt << enemyattack << "hp.\n\n";
						hp = hp - enemyattack;
					}
					else {
						cout << enemyspelltxt << enemyspell << "hp.\n\n";
						hp = hp - enemyspell;
					}
							}
				else {
					cout << "The enemy missed you.\n\n";
				}
			}
		}
		else if (input == "attack" || input == "atk") {
			if (attackroll >= 10){
					cout << "You attacked the enemy for " << weapondmg << "hp.\n";
					enemyhp = enemyhp - weapondmg;
			}
				else {
					cout <<"You missed the enemy!\n";
				}
			if (enemyattackroll >= 10){
				if(random(1, 12) <= 7){
					cout << enemyattacktxt << enemyattack << "hp.\n\n";
					hp = hp - enemyattack;
				}
				else {
					cout << enemyspelltxt << enemyspell << "hp.\n\n";
					hp = hp - enemyspell;
				}
			}
			else {
				cout << "The enemy missed you.\n\n";
			}
		}
		else if (input == "heal"){
			if (mp > 3){
				cout << "You healed yourself for " << heal << " hp.\n";
				hp = hp + heal;
				mp = mp - 4;
			}
				else {
					cout << "You do not have enough mana for that spell, try a different command.\n";
				}
			if (enemyattackroll >= 10){
				if(random(1, 12) <= 7){
					cout << enemyattacktxt << enemyattack << "hp.\n\n";
					hp = hp - enemyattack;
				}
				else {
					cout << enemyspelltxt << enemyspell << "hp.\n\n";
					hp = hp - enemyspell;
				}
			}
			else {
				cout << "The enemy missed you.\n\n";
			}
		}
		else if (input == "magicmissile" || input == "mm"){
			if (mp > 7){
				cout << "You blast the enemy for " << magicmissile << "hp with magic missile!\n";
				enemyhp = enemyhp - magicmissile;
				mp = mp - 8;
			}
			else {
				cout << "You do not have enough mana for that spell, try a different command.\n";
			}
			if (enemyattackroll >= 10){
				if(random(1, 12) <= 7){
					cout << enemyattacktxt << enemyattack << "hp.\n\n";
					hp = hp - enemyattack;
				}
				else {
					cout << enemyspelltxt << enemyspell << "hp.\n\n";
					hp = hp - enemyspell;
				}
			}
			else {
				cout << "The enemy missed you.\n\n";
			}
		}
		else if (input == "hp" || input == "mp" || input == "info")
			cout << "You have " << hp << " hp, and " << mp << " mp.\n\n";
		else cout << "That is not a valid command, type 'help' to see a list of commands.\n\n";
	} while (hp > 0 && enemyhp > 0);

	if(hp <= 0 && enemyhp <= 0)
		cout << "You have each fallen at the same time.\n\n";
	else if(hp <= 0){
		cout << "You have been defeated!\n\n";
		cout << ">";
		cin >> input;
		return 0;
	}
	else if(enemyhp <= 0){
		cout << "You have won the battle!\n\n";
		exp = exp + expget;
		gold = gold + goldget;
	}

	loop2:

	cout << ">";
	cin >> input;

	if (input == "back") {
		cout << endl;
		goto begin;
	}
	else if (input == "help"){
		cout << "Type 'back' to go back to town. Type 'quit' to quit the game.\n\n";
		goto loop2;
	}
	else if (input == "quit") return 0;
	else{cout << "That's not a valid command. Please type help to see a list of commands.\n\n"; goto loop2;}
}

int random(int low, int high)
{
	return (rand() % (high - low + 1)) + low;
}
