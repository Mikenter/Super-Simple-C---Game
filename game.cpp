#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int random(int, int);
int main()
{
	srand((unsigned)time(0));
	string input; string area = "forest";
	int dlow = 1; int d6 = 6; int d8 = 8; int d12 = 12; int d20 = 20;
	int hp = 15 + random(dlow, d20); int hpmax = hp; int mp = 10 + random(dlow, d20);
		int mpmax = mp; int exp = 0; int gold = 5 + random(dlow, d12);

	begin:
	cout << "You arrive in town\n";
	begin1:
	cout << ">";
	cin >> input;

	if (input == "help"){
		cout << "Commands are:\n";
		cout << "'battle' - start a battle\n";
		cout << "'inn' - takes you to the inn, where you can heal\n";
		cout << "'shop - takes you to the shop\n";
		cout << "'hp', 'mp', 'exp', 'gold', or 'info' - view your current exp, gold, hp, and mp.\n";
		cout << "'quit - quit the game\n\n";
		goto begin;
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
			cout << "No? too bad, come back some other time!";
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
		cout << "\nWelcome to my humble shop, I have a little bit of everything. Have a 'look' around.\n";
		cout << ">";
		cin >> input;
		if (input == "look"){ cout << "There's nothing around, you decide to leave.\n\n"; goto begin;}
		else {cout << "You decline his offer and leave the store.\n\n"; goto begin;}
	}
	else if (input == "hp" || input == "mp" || input == "exp" || input == "gold" || input == "info"){
		cout << "You have " << exp << " exp, " << gold << " gold, " << hp << " hp, " << mp << " mp.\n\n";
		goto begin1;
	}
	else if (input == "quit") return 0;
	else if (input == "battle"){
		cout << endl;
		goto battle;
	}
	else{ cout << "That's not a valid command, type help to see the commands\n\n"; goto begin;}

	battle:
	int mon = random(dlow, d6);
	int enemyattack;
	int enemyhp;
	int goldget;
	if(area == "forest"){
		switch(mon){
		case 1:
		case 2:
			cout << "You encounter a Giant Rat!\n";
			enemyattack = random(dlow, d6);
			enemyhp = 25;
			goldget = random(dlow, d6);
			break;
		case 3:
			cout << "You encounter test 3.\n";
			enemyattack = random(dlow, d6);
			enemyhp = random(15, 25);
			goldget = random(dlow, d6);
			break;
		case 4:
			cout << "You encounter test 4.\n";
			enemyattack = random(dlow, d6);
			enemyhp = 25;
			goldget = random(dlow, d6);
			break;
		case 5:
			cout << "You encounter test 5.\n";
			enemyattack = random(dlow, d6);
			enemyhp = 25;
			goldget = random(dlow, d6);
			break;
		case 6:
			cout << "You encounter test 6.\n";
			enemyattack = random(dlow, d6);
			enemyhp = 25;
			goldget = random(dlow, d6);
			break;
		}
	}

	do {
		int attack= random(dlow, d8);
		int heal = random(dlow, d6);
		int magicmissile = random(dlow, d6) + 2;
		int attackroll = random(dlow, d20);
		int enemyattackroll = random(dlow, d20);

		cout << ">";
		cin >> input;

		if (input == "help"){
			cout << "Commands are:\n";
			cout << "'attack' or 'atk' - attack the enemy.\n";
			cout << "'heal' - heal yourself.\n";
			cout << "'magicmissile' or 'mm' - cast magic missile on the enemy.\n";
			cout << "'hp', 'mp', 'exp', gold, or 'info' - view your current exp, gold, hp, and mp.\n\n";
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
				cout << "You got hit for " << enemyattack << "hp.\n\n";
				hp = hp - enemyattack;
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
				cout << "You got hit for " << enemyattack << "hp.\n\n";
				hp = hp - enemyattack;
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
				cout << "You got hit for " << enemyattack << "hp.\n\n";
				hp = hp - enemyattack;
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
		exp = 0;
	}
	else if(enemyhp <= 0){
		cout << "You have won the battle!" << endl;
		exp = exp + 25;
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
	else goto loop2;
}

int random(int low, int high)
{
	return (rand() % (high - low + 1)) + low;
}
