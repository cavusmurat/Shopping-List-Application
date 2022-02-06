//MURAT ÇAVUÞ
//FINAL PROJECT-> Shopping List Application

#include <iostream>
#include <vector>
using namespace std;

class Products {
public:
    string name = "";
    int amount = 0;
    bool mark = 0;
};

class ShoppingList {
public:
    vector < Products > list;
    string name;
};

vector < ShoppingList > keepList;
string currentListName;
string currentProductName;

int findShoppingList(string listName) {
    int index = -1;
    for (int i = 0; i < keepList.size(); i++) {
        if (keepList[i].name == listName) {
            currentListName = keepList[i].name;
            index = i;
        }
    }
    return index;
}

int findProduct(string listName, string name) {
    int index = findShoppingList(listName);
    for (int i = 0; i < keepList[index].list.size(); i++) {
        if (keepList[index].list[i].name == name) {
            currentProductName = keepList[index].list[i].name;
            index = i;
        }
    }
    return index;
}

void insertList(string listName) {
    ShoppingList list;
    int index = findShoppingList(listName);
    if (index == -1) {
        list.name = listName;
        keepList.push_back(list);
    }
    else if (index != -1)
    {
        cout << "ERROR : A list with this name is already exists , please go to the main menu and try a different list name!";
    }    
}

void deleteList(string listName) {
    int index = findShoppingList(listName);
    keepList.erase(keepList.begin() + index);
}

void insertProduct(string listName, string name, int amount) {
    Products product;
    int listIndex = findShoppingList(listName);
    int productIndex = findProduct(listName, name);
    product.name = name;
    product.amount = amount;
    keepList[listIndex].list.push_back(product);       
}

void markingProduct(string listName, string name) {
    int listIndex = findShoppingList(listName);    
    int productIndex = findProduct(listName, name);
    if (keepList[listIndex].list[productIndex].name == name && keepList[listIndex].list[productIndex].mark == 0) {
        keepList[listIndex].list[productIndex].mark = 1;
    }
    else if (keepList[listIndex].list[productIndex].name == name && keepList[listIndex].list[productIndex].mark == 1) {
        cout << "This product is already marked!";
        }    
}

void unmarkingProduct(string listName, string name) {
    int listIndex = findShoppingList(listName);
    int productIndex = findProduct(listName, name);
    if (keepList[listIndex].list[productIndex].name == name && keepList[listIndex].list[productIndex].mark == 1) {
            keepList[listIndex].list[productIndex].mark = 0;
    }else if(keepList[listIndex].list[productIndex].name == name && keepList[listIndex].list[productIndex].mark == 0){
            cout << "This product is already unmarked!";
    }
}

void displayCertainProduct(string listName, string name) {
    int productIndex = -1;   
    int listIndex = findShoppingList(listName);
    if (keepList[listIndex].list.size()==0) {
        cout << endl;
        cout << "This list is empty , please go to the main menu and insert a product!";
        cout << endl;
    }
    else {
        if (productIndex==-1) {
            cout << endl;
            cout << "There is no product named as '" << name << "' , please try again ! ";
            cout << endl;
        }
        else
        {
            int productIndex = findProduct(listName, name);
            cout << "[  " << endl << " List Name : " << keepList[listIndex].name << endl;
            cout << " name : " << keepList[listIndex].list[productIndex].name << endl;
            cout << " amount : " << keepList[listIndex].list[productIndex].amount << endl;
            cout << " mark : " << (keepList[listIndex].list[productIndex].mark ? "X" : "O") << endl;
            cout << "]";
        } 
            
    }
}

void displayAllLists() {
    cout << "[";
    if (keepList.size() == 0) {
        cout << endl << "There is no list yet , please go to the main menu and insert a list!";
    }
    else {

        for (int i = 0; i < keepList.size(); i++) {
            cout << endl << " List Name : " << keepList[i].name << " [";
            for (int j = 0; j < keepList[i].list.size(); j++) {
                cout << endl << " {";
                cout << endl << " name : " << keepList[i].list[j].name;
                cout << endl << " amount : " << keepList[i].list[j].amount;
                cout << endl << " mark : " << (keepList[i].list[j].mark ? "X" : "O");
                cout << endl << " }";
            }
            cout << "]";
        }
    }
    cout << endl;
    cout << "]";
}

void displayCertainList(string listName) {
    cout << "[  ";    
    int index = findShoppingList(listName);
    if (index==-1) {
        cout << endl;
        cout << "There is no list named as '" << listName << "' , please try again !";
        cout << endl;
    }
    else {
        cout << "[  " << " List Name : " << keepList[index].name;
        for (int j = 0; j < keepList[index].list.size(); j++) {
            cout << endl << " {";
            cout << endl << " name : " << keepList[index].list[j].name;
            cout << endl << " amount : " << keepList[index].list[j].amount;
            cout << endl << " mark : " << (keepList[index].list[j].mark ? "X" : "O");
            cout << endl << " }";
        }
    }
    cout << "]";
}

string selectList() {
    int index;
    cout << "Choose List : " << endl;
    for (int i = 0; i < keepList.size(); i++) {
        cout << "Type '" << i << "' to select " << " - List Name : " << keepList[i].name << endl;
    }
    cin >> index;
    return keepList[index].name;
}

int showMenu() {
    int input;
    cout << endl;
    cout << "------Main Menu------";
    cout << endl;
    cout << "Type '1' to display all lists!" << endl;
    cout << "Type '2' to display a certain list!" << endl;
    cout << "Type '3' to display a certain product!" << endl;
    cout << "Type '4' to insert a list!" << endl;
    cout << "Type '5' to insert a product to a certain list!" << endl;
    cout << "Type '6' to delete a certain list!" << endl;
    cout << "Type '7' to mark a certain product!" << endl;
    cout << "Type '8' to unmark a certain product! " << endl;
    cout << "Type '9' to EXIT!" << endl;
    cout << "Choose : ";
    cin >> input;
    return input;
}

int main() {
    int input = 0;
    string name;
    string listName;
    int amount;    
    do {
        switch (input) {
        case 0:
            input = showMenu();
            break;
        case 1:
            displayAllLists();
            input = showMenu();
            break;
        case 2:
            if (keepList.size() == 0) {
                cout << endl;
                cout << "There is no list yet , please go to the main menu and insert a list!";
                cout << endl;
            }
            else {
                cout << "Please enter the name of list you want to see: ";
                cin >> listName;
                displayCertainList(listName);
            }
            input = showMenu();
            break;
        case 3:
            if (keepList.size() == 0) {
                cout << endl;
                cout << "There is no list yet , please go to the main menu and insert a list!";
                cout << endl;
            }
            else {
                cout << "Enter the name of list: ";
                cin >> listName;
                cout << "Enter the name of product: ";
                cin >> name;
                displayCertainProduct(listName, name);
            }
            input = showMenu();
            break;
        case 4:
            cout << "Please enter the name of the list you want to add: ";
            cin >> listName;
            insertList(listName);
            input = showMenu();
            break;
        case 5:
            cout << "Please enter the name of the product you want to add: ";
            cin >> name;
            cout << "Please enter the amount of this product: ";
            cin >> amount;
            listName = selectList();
            if (amount <= 0) {
                cout << "Invalid input";
            }
            else {
                insertProduct(listName, name, amount);
            }
            input = showMenu();
            break;
        case 6:        
            if (keepList.size() == 0) {
                cout << endl;
                cout << "There is no list yet , please go to the main menu and insert a list!";
                cout << endl;
            }
            else {
            cout << "Please enter the name of list you want to delete: ";
            cin >> listName;
            deleteList(listName);
            }
            input = showMenu();
            break;
        case 7:            
            if (keepList.size() == 0) {
                cout << endl;
                cout << "There is no list yet , please go to the main menu and insert a list!";
                cout << endl;
            }
            else {
                cout << "Please enter the name of list: ";
                cin >> listName;
                int index = findShoppingList(listName);
                if (keepList[index].list.size() == 0) {
                    cout << endl;
                    cout << "There is no product , please insert a product to mark!";
                    cout << endl;
                }else{
                    cout << "Please enter the name of product that you want to mark: ";
                    cin >> name;
                    markingProduct(listName, name);
                }                                
            }                       
            input = showMenu();
            break;
        case 8:            
            if (keepList.size() == 0) {
                cout << endl;
                cout << "There is no list yet , please go to the main menu and insert a list!";
                cout << endl;
            }else{
                cout << "Please enter the name of list: ";
                cin >> listName;
                int index = findShoppingList(listName);
                if (keepList[index].list.size() == 0) {
                    cout << endl;
                    cout << "There is no product , please insert a product to unmark!";
                    cout << endl;
                }else{
                    cout << "Please enter the name of product that you want to unmark: ";
                    cin >> name;
                    unmarkingProduct(listName, name);
                }
                
            }                        
            input = showMenu();
            break;
        case 9:           
            input = 9;
            break;
        default:
            cout << "Invalid input!" << endl;
            input = showMenu();
            break;
        }
    } while (input != 9);
    return 0;
}