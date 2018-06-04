#include "One-armed bandit.h"

int main() {
	system("mode con cols=80 lines=40");
	int Select;

	int Chips = 1000;
	OneArmedBandit GamingMachine;
	do {
		system("cls");
		cout<<"The one-armed bandit" << endl;
		showMenu();
		scanf_s("%d", &Select);
	} while (Select < 0 || Select>1);
	if (Select == 0) {
		exit(0);
	}
	do {
		system("cls");
		cout << "The one-armed bandit" << endl;
		int Rate = 0;
		printf("%d$\n\n", Chips);
		printf("Your rate: ");
		scanf_s("%d", &Rate);
		if (Rate > Chips) {
			continue;
		}
		GamingMachine.Start();
		GamingMachine.ShowRings();
		if (GamingMachine.getScore() == 0) {
			Chips -= Rate;
			cout << "You lose." << endl;
		}
		else {
			int Win = (Rate / 100 * GamingMachine.getScore()) + Rate;
			cout << "You Win." << endl;
			printf("%20d", Win);
			Chips += Win;
		}
		if (Chips <= 0) {
			Select = false;
			cout << "Game Over" << endl;
			system("pause >> void");
		}
		else {
			do {
				printf("\nAgain: 1-yes\t0-No\n");
				scanf_s("%d", &Select);
			} while (Select < 0 || Select>1);
		}
	} while (Select);
	main();
}
void Line(char symbol, int count) {
	for (int i = 0; i < count; i++) {
		printf("%c", symbol);
	}
}
void StringToCenter(char *string, int witdh) {
	int space = (witdh - strlen(string)) / 2;
	Line(char(32), space);
	printf("%s", string);
	Line(char(32), space);
}
void showPanel(char *Title, int Witdh) {
	int left = 0;
	if (Witdh < 80) {
		left = (80 - Witdh) / 2;
	}
	Line(char(32), left);
	printf("%c", char(201));
	Line(char(205), Witdh);
	printf("%c\n", char(187));
	Line(char(32), left);
	printf("%c", char(186));
	StringToCenter(Title, Witdh);
	printf("%c\n", char(186));
	Line(char(32), left);
	printf("%c", char(200));
	Line(char(205), Witdh);
	printf("%c\n\n", char(188));
}


void showMenu() {

	cout << "Menu" << endl;
	
	cout << "1-New Game" << endl;
	
	cout << "0-Exit" << endl;
	
}