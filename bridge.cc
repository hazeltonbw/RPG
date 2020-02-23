#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Bridges.h"
#include "CircDLelement.h"
#include "heroes.h"
#include "monsters.h"

using namespace bridges;
using namespace std;

CircDLelement<Heroe> *insertFront(CircDLelement<Heroe> *tailElement, CircDLelement<Heroe> *newElement);

int main(int argc, char **argv) {
	Bridges *bridges =  new Bridges(999, "oanhtran_08", "778148310812");

	bridges->setTitle("Circular Linked List");
	Heroe Tomas(100, 40, 60, 10, 75);
	Heroe Brianna(100, 10, 20, 80, 20);
	Heroe Mario(100, 85, 60, 50, 40);
	//monsters
	Monster Cersei(110, 40, 60, 10, 75);
	Monster Jamie(90, 40, 60, 10, 75);
	Monster Joffrey(80, 40, 60, 10, 75);

	CircDLelement<Heroe> *heroes[] = {new CircDLelement<Heroe>(Tomas, ""), new CircDLelement<Heroe>(Brianna, ""), new CircDLelement<Heroe>(Mario, "")};

	CircDLelement<Heroe> *head = nullptr;
	int num = 3;
	for (int i = 0; i < num; i++) {
		if (i) head = insertFront(head, heroes[i]);
		else
			head = heroes[i];
	}

	CircDLelement<Heroe> * current = head;
	Heroe h;
	do {
		h = current->getValue();
		current = current->getNext();
	} while (current != head);
	bridges->setDataStructure(head);
	bridges->visualize();

	return 0;

}

CircDLelement<Heroe> *insertFront(
    CircDLelement<Heroe> *tailElement,
    CircDLelement<Heroe> *newElement) {

	CircDLelement<Heroe> *tailNextElement = tailElement->getNext();

	newElement->setNext(tailNextElement);
	newElement->setPrev(tailElement);

	tailNextElement->setPrev(newElement);
	tailElement->setNext(newElement);

	return tailElement;
}

