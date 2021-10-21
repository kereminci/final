//kerem inci
//1306190041
//Bilgisayar Muhendisligi 1.Sýnýf


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void showListOperations();
void showMainMenuOperations();
void showOperations();
void showLists();

class Product {
public:
	int amount;
	string title;
	bool isMarked;
	bool isVisible;
	void markDoneUndone();
	Product();
};

Product::Product() {
	amount = -1;
	title = "";
	isMarked = false;
	isVisible = false;
}

void Product::markDoneUndone() {
	isMarked = (isMarked ? false : true);
}


class List {
public:
	string listTitle;
	vector<Product>listItems;
	void addItem();
	void deleteItem();
	void showItems();
	void editItem();
	void markItem();
};

vector<List>lists;

void List::markItem() {
	cin.ignore();
	string title;
	cout << "Enter item title, you want to change mark sign" << endl;
	getline(cin, title);
	for (int i = 0; i < listItems.size(); i++) {
		if (listItems[i].title == title) {
			this->listItems[i].markDoneUndone();
		}
	}
}



void List::editItem() {
	string title;
	int amount;
	cin.ignore();
	cout << "Enter item title ,you want to edit" << endl;
	getline(cin, title);
	cout << "Enter new amount your product" << endl;
	cin >> amount;
	for (int i = 0; i < listItems.size(); i++) {
		if (listItems[i].title == title) {
			this->listItems[i].amount = amount;
		}
	}
}


void List::showItems() {
	cout << "Item check " << "  Item Title  " << "  Item Amount" << endl;
	cout << "-----------" << "  ---------- " << "   ----------    " << endl;
	for (Product item : listItems) {
		cout << (item.isMarked ? "[X]" : "[]") << "            " << item.title << "             " << item.amount << endl;
	}
}


void List::deleteItem() {
	string title;
	cout << "Enter item title you want to delete :" << endl;
	cin >> title;
	for (int i = 0; i < listItems.size(); i++) {
		if (listItems[i].title == title) {
			if (listItems.size() == 1) {
				this->listItems.clear();
			}
			else {
				for (int j = i + 1; j < listItems.size(); j++) {
					this->listItems[j - 1] = this->listItems[j];
				}
			}
			this->listItems.pop_back();
		}
	}
}


void List::addItem() {
	cin.ignore();
	Product item;
	cout << "Enter item title " << endl;
	getline(cin, item.title);
	cout << "Enter item amount " << endl;
	cin >> item.amount;
	item.isVisible = true;
	listItems.push_back(item);
	return;
}


void createList() {
	List newList;
	cout << "Enter list name" << endl;
	getline(cin, newList.listTitle);
	lists.push_back(newList);
}

void showLists() {
	if (lists.size() == 0) cout << "You didint create any list, please create new list" << endl;
	else {
		cout << "  ID  " << "    List Name" << endl;
		cout << "------" << "    ---------" << endl;
		for (int i = 0; i < lists.size(); i++) {
			cout << "  " << i << "       " << lists[i].listTitle << endl;
		}
	}
}



void mainMenu() {
	char c;
	showMainMenuOperations();
	while (cin >> c) {
		cin.ignore();
		switch (c)
		{
		case '1':
			createList();
			cout << "New list created" << endl;
			showMainMenuOperations();
			break;
		case '2':
			showLists();
			showMainMenuOperations();
			break;
		case '3':
			showListOperations();
			break;
		case '4':
			return;
			break;
		}
	}
}

void showOperations() {
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "0. Choose list  you want to make operations ! First make this if you dont program will crash" << endl;
	cout << "1. Add Item" << endl;
	cout << "2. Edit Item" << endl;
	cout << "3. Delete Item" << endl;
	cout << "4. Mark as Dune Undone" << endl;
	cout << "5. Show list items" << endl;
	cout << "6. Back to main menu" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
}

void showMainMenuOperations() {
	cout << "----------------------------------------------------------" << endl;
	cout << "1. Create new list" << endl;
	cout << "2. Show shopping lists" << endl;
	cout << "3. Show list operations and make operations" << endl;
	cout << "4. Exit" << endl;
	cout << "----------------------------------------------------------" << endl;
}

void showListOperations() {
	cout << "Shopping List Menu " << endl << endl;
	char c;
	int id = -1;
	bool chooseList = false;
	showOperations();
	while (cin >> c) {
		//cin.ignore();
		switch (c) {
		case '0':
			showLists();
			cout << "Enter the id of the list which you want to make operations" << endl;
			cin >> id;
			if (id >= 0 && id < lists.size()) {
				cout << "You succesfully selected list, you can make operations now!" << endl;
				showOperations();
				chooseList = true;
			}
			else cout << "Id doesnt exist" << endl;
			break;

		case '1':
			if (chooseList) {
				lists[id].addItem();
				cout << "You succesfully made operation." << endl;
				showOperations();
			}
			else cout << "First choose list " << endl;
			break;

		case '2':
			if (chooseList) {
				lists[id].editItem();
				cout << "You succesfully made operation." << endl;
			}
			else cout << "First choose list " << endl;
			showOperations();
			break;

		case '3':
			if (chooseList) {
				lists[id].deleteItem();
				cout << "You succesfully made operation." << endl;
			}
			else cout << "First choose list " << endl;
			showOperations();
			break;
		case '4':
			if (chooseList) {
				lists[id].markItem();
				cout << "You succesfully made operation." << endl;
			}
			else cout << "First choose list " << endl;
			showOperations();
			break;
		case '5':
			if (chooseList) {
				lists[id].showItems();
				cout << "You succesfully made operation." << endl;
			}
			else cout << "First choose list " << endl;
			showOperations();
			break;

		case '6':
			cout << "You turned main menu" << endl;
			showMainMenuOperations();
			return;
		}
	}

}


int main()
{
	mainMenu();
	return;
}


