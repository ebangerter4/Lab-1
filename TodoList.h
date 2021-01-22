#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TodoListInterface.h"

class TodoList : public TodoListInterface {
public:    
  vector <string> taskList;
	TodoList() {
    ifstream inFile;
		inFile.open("TODOList.txt");
		string line;
		if (inFile.is_open()) {
			while (getline(inFile,line)) {
				taskList.push_back(line);
			}
			inFile.close();
    }
  }
		    
  virtual ~TodoList() {
    ofstream outFile;
		outFile.open("TODOList.txt", ofstream::out | ofstream::trunc);
		if (outFile.is_open()){
			for (int i = 0; i < taskList.size(); i++) {
				outFile << taskList.at(i) << endl;
			}
			outFile.close();
		}
  }
  
	/*Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"*/
  virtual void add(string _duedate, string _task) {
		taskList.push_back(_duedate);
		taskList.push_back(_task);
  }
  
	/*Removes an item from the todo list with the specified task name
  Returns 1 if it removes an item, 0 otherwise*/    
  virtual int remove(string _task) {
		for (int i = 0; i < taskList.size(); i++) {
			if (taskList.at(i) != _task) {
				continue;
			}
			else {
				taskList.erase(taskList.begin() + i);
				taskList.erase(taskList.begin() + (i - 1));
				cout << "Task removed" << endl;
				return 1;
			}
		}
		return 0;
	}

	/*Prints out the full todo list to the console*/
  virtual void printTodoList() {
		for(int i =0; i < taskList.size(); i++) {
		cout << taskList.at(i) << endl;
		}
  }
  
	/*Prints out all items of a todo list with a particular due date (specified by _duedate)*/    
  virtual void printDaysTasks(string _duedate) {
		cout << _duedate << endl;
		for(int i = 0; i < taskList.size(); i++) {
			if(taskList.at(i) == _duedate) {
				cout << taskList.at(i + 1) << endl;
			}
		}
  }
};
  
#endif //TODO_LIST_H