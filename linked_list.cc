#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
struct LL {
    int data;
    LL *next;
    LL(int new_data, LL* new_next) {data = new_data, next=new_next;}
    //~LL() {delete next;}
};

int main() {

    LL *head = nullptr;
    while (1) {
        cout << "Please insert an int (0 to quit):\n";
        int x = 0;
        cin >> x; if (!cin) exit(EXIT_FAILURE);
        if (x == 0) break;
        LL *temp = new LL(x,head);
        head = temp;
    }
    LL *temp = head;
    while (temp) {
        cout << temp-> data << endl;
        temp = temp-> next;
    }
    temp = head;
    while (temp) {
        cout << temp-> data << endl;
        temp = temp-> next;
    }



    // Delete an element from a linked list
    cout << "What element do you want to delete:\n";
    int x = 0; cin >> x; if(!cin) exit(1);
    if (!head) ;// do nothing
    else if (x == head->data) {
        LL *temp = head;
        head = head->next;
        delete temp;
    }
    else {
        LL *prev = head;
        LL *temp = head->next;
        while (temp) {
            if (x == temp->data) {
                prev->next = temp-> next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    temp = head;
    while (temp) {
        cout << temp-> data << endl;
        temp = temp-> next;
    }
    


    // Destroy link list
    temp = head;
    while (temp) {
        LL *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    //delete head;
}