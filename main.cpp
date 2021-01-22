#include "TodoList.h"

int main(int argc, char *argv[]) {
  TodoList myList;

	//Checks to make sure a command was provided
	if (argc == 1) {
			cout << "Please specify a command" << endl;
			exit(EXIT_FAILURE);
	}
	else {
  	string command = argv[1];

		//Adds day and task if correct number of arguments
		if (command.compare("add") == 0){
			if (argc < 4) {
				cout << "Please give a day and a task" << endl;
				exit(EXIT_FAILURE);
			}
			else {
				string day = argv[2];
				string task = argv[3];
				myList.add(day, task);
			}
		}
		//Removes task if correct number of arguments
		else if (command.compare("remove") == 0){
			if (argc < 3) {
				cout << "Please specify a task" << endl;
				exit(EXIT_FAILURE);
			}
			else {
				string task = argv[2];
				myList.remove(task);
			}
		}
		//Prints list of all tasks and days
		else if (command.compare("printList") == 0){
			myList.printTodoList();
		}
		//Prints list of all tasks on a day if correct number of arguments
		else if (command.compare("printDay") == 0){
			if (argc <= 2) {
				cout << "Please specify which day's task to list" << endl;
				exit(EXIT_FAILURE);
			}
			string date = argv[2];
			myList.printDaysTasks(date);
		}

		else {
			cout << "Invalid command. Please try again." << endl;
		}
	}
}