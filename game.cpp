#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int random(int, int);
int main()
{
	srand((unsigned)time(0));
	string input; string area = "forest";
	int hp = 15 + random(1, 20); int hpmax = hp; int mp = 10 + random(1, 20);
		int mpmax = mp; int exp = 0; int gold = 5 + random(1, 12);

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
	int enemyattack;
	int enemyspell;
	int enemyhp;
	int goldget;
	int expget;
	if(area == "forest"){
		switch(random (1, 6)){
		case 1:
		case 2:
			cout << "You encounter a Giant Rat!\n";
			enemyspell = random(5, 10);
			enemyattack = random(1, 6);
			enemyhp = 25;
			goldget = random(1, 6);
			expget = 10;
			break;
		case 3:
			cout << "Elfling\n";
			enemyspell = random(5, 10);
			enemyattack = random(2, 5);
			enemyhp = random(15, 25);
			goldget = random(0, 5);
			expget = 10;
			break;
		case 4:
			cout << "You encounter test 4.\n";
			enemyspell = random(5, 10);
			enemyattack = random(1, 6);
			enemyhp = 25;
			goldget = random(1, 6);
			expget = 10;
			break;
		case 5:
			cout << "You encounter test 5.\n";
			enemyspell = random(5, 10);
			enemyattack = random(1, 6);
			enemyhp = 25;
			goldget = random(1, 6);
			expget = 10;
			break;
		case 6:
			cout << "You encounter test 6.\n";
			enemyspell = random(5, 10);
			enemyattack = random(1, 6);
			enemyhp = 25;
			goldget = random(1, 6);
			expget = 10;
			break;
		}
	}

	do {
		int attack= random(1, 8);
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
					cout << "You were attacked for " << enemyattack << "hp.\n\n";
					hp = hp - enemyattack;
				}
				else {
					cout << "you were shot for " << enemyspell << "hp.\n\n";
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
					cout << "You were attacked for " << enemyattack << "hp.\n\n";
					hp = hp - enemyattack;
				}
				else {
					cout << "you were shot for " << enemyspell << "hp.\n\n";
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
					cout << "You were attacked for " << enemyattack << "hp.\n\n";
					hp = hp - enemyattack;
				}
				else {
					cout << "you were shot for " << enemyspell << "hp.\n\n";
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
	else{cout << "That's not an input silly!\n\n"; goto loop2;}
}

int random(int low, int high)
{
	return (rand() % (high - low + 1)) + low;
}
