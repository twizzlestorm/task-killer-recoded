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
	int failed;

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

		failed = system(command.c_str());

		if (failed)		
			cout << "There was an error, it's likely you've typed the program wrong.";
		else		
			cout << "The programs specified have been killed."; 

		cout << "\nWould you like to run the program again? (Y/N): ";
		cin >> yn;

	}
	return 0;			

}
