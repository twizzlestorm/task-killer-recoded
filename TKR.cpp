// Dedicated to Ryan Nair.

#include <iostream>
#include <string>
using namespace std;

int cMenu()
{
	string command;
	string color;
	int failed;

	while (command != "return")
	{
		system("cls");
		cout << "Welcome to the color menu!\n";
		cout << "For information on correct syntax, please visit the TKR wiki here:\n";
		cout << "https://github.com/twizzlestorm/task-killer-recoded/wiki/Color-syntax\n\n";

		cout << "Enter two hex digits, or type \"return\" to return to options: ";
		cin >> color;

		if (color == "return")
			return 0;

		command = "color " + color;

		failed = system(command.c_str());

		if (failed)
			cout << "\nThere was an error; check syntax and try again.";
		else
			cout << "\nColors changed successfully.";
	}

		return 0;

}

int hMenu()
{
	int choice = 0;

	while (choice != 3)
	{

		system("cls");
		cout << "Help options:\n\n";
		cout << "1) Provide a list of tasks to kill\n";
		cout << "2) Change the colors of the screen\n";
		cout << "3) Return to the home screen\n\n";
		cout << "Please enter your choice: ";
		cin >> choice;

		while (choice < 1 || choice > 3)
		{
			cout << "\nYour choice was invalid. Please choose a valid number: ";
			cin >> choice;
		}

		if (choice == 1)
		{
			system("tasklist");
			cout << "Press any key to go back to the options menu.";
			system("pause >nul");
		}

		else if (choice == 2)
			cMenu();
	}

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
		system("title TaskKillerRecoded");
		system("cls");

		cout << "Welcome to TaskKillerRecoded!\n";
		cout << "(C) Twizzlestorm LLC / Ethan Custer [2019]\n\n";
		cout << "Please enter a task to kill (ex. chrome.exe), or type \"help\" for help: ";
		cin >> input;

		if (input == "help")
		{
			hMenu();
			main();
		}

		command = "taskkill /f /im " + input;

		failed = system(command.c_str());

		if (failed)
			cout << "There was an error while killing the task; check your spelling and try again.";
		else
			cout << "The task has been killed successfully.";

		cout << "\nWould you like to kill another task? (Y/N): ";
		cin >> yn;

	}
	return 0;

}
