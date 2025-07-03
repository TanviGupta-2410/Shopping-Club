#include<iostream>
#include<string>
#include <sstream>
#include <bits/stdc++.h>
#include<windows.h>
#include"queue.h"
#include"animation.h"
#include"stack.h"

using namespace std;

int search(int);
int display();
string check(int);       // for checking quantity

// Node structure for the linked list
struct node {
    int ID;
    string proName;
    double prePrice;
    int quantity;
    struct node* next;
};

struct node* head = NULL;

// Function to add a product at the beginning
void beg() {
    system("cls");
    int id, quant;
    string name;
    double pre;
    struct node* t = new node;
    struct node* p = head;

    cout << "\t\t\tEnter product ID:-";
    cin >> id;
    t->ID = id;
    cout << "\t\t\tEnter product Name:-";
    cin >> name;
    t->proName = name;
    cout << "\t\t\tEnter product price:-";
    cin >> pre;
    t->prePrice = pre;
    cout << "\t\t\tEnter product quantity:-";
    cin >> quant;
    t->quantity = quant;

    if (head == NULL) {
        t->next = head;
        head = t;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
        t->next = NULL;
    }
    system("cls");
    cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}

// Search product by ID
int search(int id) {
    int count = 1;
    struct node* p = head;
    while (p != NULL) {
        if (p->ID == id)
            break;
        else
            count++;
        p = p->next;
    }
    return count;
}

// Hash function
int hashh(int x, int mod) {
    return x % mod;
}

// Delete product by ID
void delPro() {
    system("cls");
    display();
    int id;
    struct node* cur = head;
    struct node* pre = head;
    cout << "\n\nEnter ID to delete that product:\n\n";
    cin >> id;
    if (head == NULL) {
        system("cls");
        cout << "List is empty" << endl;
        return;
    }
    int pos = 0;
    int count = display();
    pos = search(id);
    if (pos <= count) {
        while (cur->ID != id) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        system("cls");
        cout << "\n<<item is deleted>>\n";
    } else {
        cout << "\n<<<Not found>>\n\n";
    }
}

// Modify product details
void modify() {
    int id;
    double pre;
    string pName;
    int nid, nq;
    if (head == NULL) {
        system("cls");
        cout << "List is empty" << endl;
    } else {
        display();
        cout << "\n\nEnter ID to modify product Name and its price:\n";
        cin >> id;
        struct node* cur = head;
        int pos = 0;
        int count = display();
        pos = search(id);
        if (pos <= count) {
            while (cur->ID != id) {
                cur = cur->next;
            }
            cout << "\nOld ID : " << cur->ID << endl;
            cout << "\nOld Name : " << cur->proName << endl;
            cout << "\nOld Price : " << cur->prePrice << endl;
            cout << "\nOld Quantity : " << cur->quantity << endl;

            cout << endl << endl;
            cout << "Enter new ID:";
            cin >> nid;
            cur->ID = nid;
            cout << "Enter new Name:";
            cin >> pName;
            cur->proName = pName;
            cout << "Enter new Price:";
            cin >> pre;
            cur->prePrice = pre;
            cout << "Enter new Quantity:";
            cin >> nq;
            cur->quantity = nq;
        } else {
            cout << id << " is <<<Not found>>\n\n";
        }
    }
}

// Display all products
int display() {
    system("cls");
    int c = 0;
    struct node* p = head;
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    cout << "=================================================================|\n";
    while (p != NULL) {
        cout << p->ID << "\t\t" << p->proName << "\t\t\t" << p->prePrice << "\t\t\t" << check(p->quantity) << "\n";
        p = p->next;
        c++;
    }
    cout << "\nTotal products in our store is : " << c << "\n\n\n";
    return c;
}

// Quantity check
string check(int quant) {
    if (quant <= 0)
        return "out of stock!";
    else
        return to_string(quant);
}

// Buying logic for customers
void buy() {
    system("cls");
    display();
    string products[20];
    int pay = 0, no, c = 0, price, id, i = 1;
    if (head == NULL) {
        cout << "\n<<<<There is no items to buy>>>>\n\n";
        return;
    } else {
        cout << "How many items you wanna to buy!\n";
        cin >> no;
        int count = display();
        while (i <= no) {
            struct node* cur = head;
            int quant, cho;
        a:
            cout << "Enter id of item that you want to buy: ";
            int id, pos = 0;
            cin >> id;
            if (id == -1) {
                system("cls");
                return;
            }
            pos = search(id);
            if (pos <= count) {
                while (cur->ID != id) {
                    cur = cur->next;
                }
                cout << "How many quantities you want:";
                cin >> quant;
                if (cur->quantity < quant) {
                    cout << "\n\n\t\t\t----The Quantity You Entered is not available---" << endl;
                    cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                    goto a;
                }
                products[c] = cur->proName;
                c++;
                pay += (cur->prePrice * quant);
                cur->quantity -= quant;
                i++;
            } else {
                cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
            }
        }
        string customer;
        cout << "\n\t\t Enter Your Name :";
        cin >> customer;
        enqueue(customer);
        system("cls");
        cout << "\n\n\n\n\t\t\tYou have bought : ";
        for (int i = 0; i < no; i++) {
            cout << products[i] << ",";
        }
        price = pay * (0.90);
        cout << "\n\nOriginal price : " << pay;
        cout << "\n with 10% discount: " << price << "\nThank you! for the shopping\n\n";
    }
}

// Administrator Portal
void administator() {
    system("cls");
    int ch;
    do {
        cout << "\t\t============================================" << endl;
        cout << "\t\t|          Administator Portal              |" << endl;
        cout << "\t\t============================================" << endl;
        cout << "\t\t     Enter 1 for ADD a new product    " << endl;
        cout << "\t\t     Enter 2 to display all products   " << endl;
        cout << "\t\t     Enter 3 for MODIFY Existing product" << endl;
        cout << "\t\t     Enter 4 for Delete a particular product item" << endl;
        cout << "\t\t     Enter 5 for Customers List " << endl;
        cout << "\t\t     Enter 6 for Dequeue customer" << endl;
        cout << "\t\t     Enter 7 for Generate hash" << endl;
        cout << "\t\t     Enter 0 for Main Menu" << endl;
        cout << "\nEnter Your choice >>>";
        cin >> ch;
        switch (ch) {
        case 1:
            beg();
            break;
        case 2:
            system("cls");
            display();
            break;
        case 3:
            modify();
            system("cls");
            break;
        case 4:
            delPro();
            cout << "\n-------Product is Deleted-------\n";
            break;
        case 5:
            system("cls");
            cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
            displayQueue();
            break;
        case 6:
            system("cls");
            cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
            dequeue();
            displayQueue();
            break;
        case 7:
            int x, n;
            cout << "Enter element to generate hash = ";
            cin >> x;
            cout << "Of total list number : ";
            cin >> n;
            cout << "Hash of " << x << " is = " << hashh(x, n);
            break;
        default:
            system("cls");
        }
    } while (ch != 0);
}

// Main function
int main() {
    for (int i = 0; i <= 51; i++) {
        push(i);
    }
    system("color 0F"); // Black background, White text
    gotoxy(17, 5);
    cout << "--------------------------------------------------" << endl;
    gotoxy(17, 7);
    cout << "||            Shopping Club System                ||" << endl;
    gotoxy(17, 9);
    cout << "--------------------------------------------------" << endl;
    gotoxy(17, 11);
    cout << "\n" << endl;
    gotoxy(17, 13);
    cout << ">>>----Project Implemented By-----<<<" << endl;
    gotoxy(22, 15);
    cout << "           Tanvi Gupta" << endl;
    system("pause");
    system("cls");

    int ch;
    while (ch != 3) {
        cout << "\n\t\t|--------<Main Menu>-----------|";
        cout << "\n\n";
        cout << "\t\t 1)Administator of Market\n";
        cout << "\t\t 2)Customer               \n";
        cout << "\t\t 3)Exit                    \n";
        cout << "\nEnter Your choice >>>";
        cin >> ch;
        switch (ch) {
        case 1:
            administator();
            break;
        case 2:
            cout << endl << endl;
            bpop();
            system("pause");
            buy();
            break;
        case 3:
            cout << "\n\n\t\t\t\t\tThank You\t\t\t\t";
            break;
        }
    }
    return 0;
}