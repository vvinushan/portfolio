/**
@file main.cpp
*/


/*! \mainpage Double Linked List
 *
 * Implementation of a Double Linked List
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  //!< Define to show memory leak report
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "doubleLinkedList.h"

void main() /** Entry point for the application */
{
	// Variables used during the linked list use
	int option;
	bool exit = false;
	string data;

	// Initialises myList from class template
	DoubleLinkedList<string> myList;
	
	// While loop executing code until user exits the program
	while (!exit)
	{
		cout << "Double Linked List data structure" << endl;
		cout << "1. Check if list is empty" << endl;
		cout << "2. Give number of elements in the list" << endl;
		cout << "3. Add element to front of the list" << endl;
		cout << "4. Remove element from front of the list" << endl;
		cout << "5. Add element to back of the list" << endl;
		cout << "6. Remove element from back of the list" << endl;
		cout << "7. Look at the first element of the list" << endl;
		cout << "8. Look at the last element of the list" << endl;
		cout << "9. Look at the current element of the list" << endl;
		cout << "10. Add element before the current element" << endl;
		cout << "11. Add element after the current element" << endl;
		cout << "12. Traverse the list from back to front" << endl;
		cout << "13. Traverse the list from front to back" << endl;
		cout << "14. Sort the list" << endl;
		cout << "15. Exit" << endl;
		cout << "" << endl;
		cout << "Enter an option: ";
		cin >> option;

		// Switch for receiving the input from user about linked list operation
		switch (option) {
			case 1:
				if (myList.empty() == true)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
				break;
			case 2:
				cout << myList.getSize() << endl;
				break;
			case 3:
				cout << "Enter data: ";
				cin >> data;
				myList.addFront(data);
				break;
			case 4:
				myList.removeHead();
				break;
			case 5:
				cout << "Enter data: ";
				cin >> data;
				myList.addBack(data);
				break;
			case 6:
				myList.removeTail();
				break;
			case 7:
				cout << myList.getHead() << endl;
				break;
			case 8:
				cout << myList.getTail() << endl;
				break;
			case 9:
				cout << myList.getCurrent() << endl;
				break;
			case 10:
				cout << "Enter data: ";
				cin >> data;
				myList.addBeforeCurrent(data);
				break;
			case 11:
				cout << "Enter data: ";
				cin >> data;
				myList.addAfterCurrent(data);
				break;
			case 12:
				while (!myList.empty())
					cout << myList.traverseBack() << endl;
				break;
			case 13:
				while (!myList.empty())
					cout << myList.traverseFront() << endl;
				break;
			case 14:
				myList.sort();
				break;
			case 15:
				exit = true;
				break;
		}
	}


	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
