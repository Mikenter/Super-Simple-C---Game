#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int random(int, int);
int main() {
	srand((unsigned)time(0));
	string input; string area = "forest"; string weapon = "club"; int weapondmg = random(1, 6);
	int hp = 15 + random(1, 20); int hpmax = hp; int mp = 10 + random(1, 20);int mpmax = mp; int exp = 0; int gold = 5 + random(1, 12);

	begin:
	cout << "You arrive in town\n";
	begin1:
	cout << ">";
	cin >> input;

	if (input == "help") {
		cout << "Commands are:\n";
		cout << "'battle' - start a battle\n";
		cout << "'inn' - takes you to the inn, where you can heal\n";
		cout << "'shop - takes you to the shop\n";
		cout << "'hp', 'mp', 'exp', 'gold', or 'info' - view your current exp, gold, hp, and mp.\n";
		cout << "'quit - quit the game\n\n";
		goto begin1;
	}
	else if (input == "debug"){
		hp = 1000;
		mp = 1000;
		gold = 1000;
		exp = 1000;
		goto begin1;
	}
	else if (input == "inn"){
		cout << "Welcome to the inn lad, would you like to stay a night? Only a mere 5 gold coins.\n";
		inn:
		cout << ">";
		cin >> input;
		if ((input == "yes" && gold >= 5) || (input == "y" && gold >= 5)){
			hp = hpmax; mp = mpmax; gold = gold -5;
			cout << "You slept the night and feel refreshed.\n\n";
			goto begin;
		}
		else if (input == "help"){
			cout << "'yes' or 'y' to sleep at the inn. 'no', 'n', or 'back' to exit the inn.";
			goto inn;
		}
		else if (input == "no" || input == "n" || input == "back"){
			cout << "No? too bad, come back some other time!\n\n";
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
		cout << "\nWelcome to my humble shop, I have a little bit of everything. Have a 'look' around.\n";
		cout << ">";
		cin >> input;
		if (input == "look"){
			cout << "You see:\n";
			cout << "A 'club'\n";
			cout << "A 'longsword'\n\n";
			cout << ">";
			cin >> input;
			if (input == "club"){
				cout << "\nYou fancy buying the club? That'll cost you 7 gold.\n";
				cout << ">";
				cin >> input;
				if ((input == "y" && weapon == "club") || (input == "yes" && weapon == "club")){
					cout << "You already seem to have this weapon friend.\n\n";
					goto shop;
				}
				else if (input == "y"  || input == "yes"){
					if (gold >= 7){
						gold = gold - 7;
						weapon = "club";
						weapondmg = random (1, 6);
						cout << "Thanks for buying that!\n\n";
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
				cout << "\nYou fancy buying the longsword? That'll cost you 15 gold.\n";
				cout << ">";
				cin >> input;
			}
		}
		else {cout << "You decline his offer and leave the store.\n\n"; goto begin;}
	}
	else if (input == "hp" || input == "mp" || input == "exp" || input == "gold" || input == "info"){
		cout << "You have " << exp << " exp, " << gold << " gold, " << hp << " hp, " << mp << " mp.\n\n";
		goto begin1;
	}
	else if (input == "quit"){
		return 0;}
	else if (input == "battle"){
		cout << endl;
		goto battle;
	}
	else{
		cout << "That's not a valid command, type help to see the commands\n\n"; goto begin;}

	battle:
	int enemyattack;
	int enemyspell;
	int enemyhp;
	int goldget;
	int expget;
	string mon;
	string enemyspelltxt;
	string enemyattacktxt;
	if(area == "forest"){
		switch(random (1, 6)){
		case 1:case 2:case 3:case 4:
			cout << "You encounter a Giant Rat!\n";
			enemyhp = 25;
			goldget = random(1, 6);
			expget = 10;
			mon = "rat";
			break;
		case 5:
			cout<< "You encountered a Tree Spider\n";
			enemyhp = 15;
			goldget = random(0, 3);
			expget = 15;
			mon = "treespider";
			break;
		case 6:
			cout << "You encounter an Elfling\n";
			enemyhp = random(15, 25);
			goldget = random(0, 5);
			expget = 10;
			mon = "elfling";
			break;
		}
	}

	do {
	 if(mon == "elfling"){
		enemyspell = random(5, 10);
		enemyspelltxt = "You were shot for ";
		enemyattack = random(1, 6);
		enemyattacktxt = "You were stabbed for ";
	}
	 else if(mon == "rat"){
			enemyspell = random(5, 10);
			enemyspelltxt = "You were bit for ";
			enemyattack = random(1, 6);
			enemyattacktxt = "You were scratched for ";

		}
		else if (mon == "treespider"){
			enemyspell = random(3, 7);
			enemyspelltxt = "Tree Spider spit acid on you damaging you for ";
			enemyattack =  random(3, 8);
			enemyattacktxt = "You were bit for ";
		}

		int attack = random(1, 8);
		int heal = random(1, 6);
		int magicmissile = random(1, 6) + 2;
		int attackroll = random(1, 20);
		int enemyattackroll = random(1, 20);


		cout << ">";
		cin >> input;

		if (input == "help"){
			cout << "Commands are:\n";
			cout << "'attack' or 'atk' - attack the enemy.\n";
			cout << "'heal' - heal yourself.\n";
			cout << "'magicmissile' or 'mm' - cast magic missile on the enemy.\n";
			cout << "'hp', 'mp', 'exp', gold, or 'info' - view your current exp, gold, hp, and mp.\n\n";
		}
		else if (input == "debug"){
			goto loop2;
		}
		else if (input == "attack" || input == "atk") {
			if (attackroll >= 10){
					cout << "You attacked the enemy for " << attack << "hp.\n";
					enemyhp = enemyhp - attack;
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
					cout << "You do not have enough mana for that spell, try a different command.\n\n";
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

		else if (input == "hp" || input == "mp" || input == "exp" || input == "gold" || input == "info")
			cout << "You have " << exp << " exp, " << gold << " gold, " << hp << " hp, " << mp << " mp.\n\n";
		else
			cout << "That's not an input silly." << endl << endl;
	} while (hp > 0 && enemyhp > 0);

	if(hp <= 0 && enemyhp <= 0)
		cout << "You have each fallen at the same time." << endl;
	else if(hp <= 0){
		cout << "You have been defeated!" << endl;
		cout << ">";
		cin >> input;
		return 0;
	}
	else if(enemyhp <= 0){
		cout << "You have won the battle!" << endl;
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
		cout << "Type 'back' to go back to town. Type 'quit' to quit the game.\n";
		goto loop2;
	}
	else if (input == "quit") return 0;
	else{cout << "That's not a valid command. Please type help to see a list of commands.\n\n"; goto loop2;}
}

int random(int low, int high)
{
	return (rand() % (high - low + 1)) + low;
}
