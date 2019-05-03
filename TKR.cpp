// Dedicated to Ryan Nair.

#include <iostream>
#include <string>
using namespace std;

int hMenu()
{
	system("cls");
	// TODO

	return 0;
}

int main()
{
	string input;
	string command;
	char yn = 'Y';
	int worked;

	while (yn == 'Y' || yn == 'y')
	{
		system("cls");
		cout << "Welcome to TaskKillerRecoded!\n";
		cout << "(C) Twizzlestorm LLC / Ethan Custer [2019]\n\n";
		cout << "Please enter a task to kill (ex. chrome.exe), or type \"help\" for help: ";
		cin >> input;

		if (input == "help")
			hMenu();

		command = "taskkill /f /im " + input;

		worked = system(command.c_str());
		
		if (worked == 0)
		cout << "The programs specified have been killed successfully.";
		else
		cout << "There was an error while killing the program - check spelling and try again.";

		cout << "\nWould you like to run the program again? (Y/N): ";
		cin >> yn;

	}
	return 0;

}
