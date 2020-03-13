#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std; //Note: This is a bad idea in header files!

void die(string s = "") {
	if (s == "") 
		cout << "BAD INPUT!" << endl;
	else
		cout << s << endl;
	exit(1);
}

class LL { //A single node in a linked list
	int cost = 0; //There is a class invariant stating cost can never be negative. Enforce this rule below.
	string province;
	LL *prev;
	LL *next;
	public:
	//This is a default constructor, 1 parameter constructor, 2 param, 3 param, and 4 param in one!
	LL(int new_cost = 0, string s = "", LL *new_prev = nullptr, LL *new_next = nullptr) {
		if (new_cost <=0) cost =0;
		else cost = new_cost;
		if (s != "") province = s;
		prev = new_prev;
		next = new_next;
	}
	int get_cost() {
		if (cost <=0) cost =0;
		return cost;
	}
	void set_cost(int new_cost) {
		cost = new_cost;
	}
	string get_province() {
		return province;
	}
	void set_province(string s) { 
		province = s;
	}
	LL *get_next() { 
		return next;
	}
	void set_next(LL *new_next) { 
		next = new_next;
	}
	LL *get_prev() { 
		return prev;
	}
	void set_prev(LL *new_prev) { 
		prev = new_prev;
	}
};

//DON'T MODIFY THIS FUNCTION. IT WILL TEST YOUR LL CLASS TO MAKE SURE IT'S COOLIO
void LL_test() {
	LL a;
	if (a.get_cost() || a.get_province() != "" || a.get_next() || a.get_prev()) die("Your default constructor or your get functions don't work. Please fix.");
	LL b(42,"Constantinople");
	if (b.get_cost() != 42 || b.get_province() != "Constantinople" || b.get_next() || b.get_prev()) die("Your one parameter constructor sucks. Please fix it pronto.");
	LL *c = new LL(-10,"Istanbul");
	if (c->get_cost() != 0) die("You allowed a negative cost to be set in a constructor. Your code should set a negative cost to 0.");
	if (c->get_province() != "Istanbul") die("The province name was set to Istanbul, but get_province did not return it.");
	LL *d = new LL(20,"Prague",c);
	if (d->get_cost() != 20 || d->get_province() != "Prague" || d->get_prev() != c) die("Your three parameter constructor doesn't work.");
	LL *e = new LL(30,"Ulm",c,d); //BTW, don't make linked lists like this
	if (e->get_cost() != 30 || e->get_province() != "Ulm" || e->get_prev() != c || e->get_next() != d) die("Your four parameter constructor doesn't work.");
	delete (c); //Every new must be paired with one delete
	delete (d);
	delete (e);
}

class List {
	LL *head = nullptr;
	LL *tail = nullptr;
	int size = 0;
	public:
	List() {} //Set above
	~List() { //This should free all memory allocated in this list
		//YOU: one delete for every new
		delete head;
	}
	
	int get_size() { 
		return size;
	} 
	//No set_size function needed. Why? Because it will only be set through insert/delete
	//No get/set methods for head and tail. Why? Because main doesn't need to know anything about them. Main will just call insert and delete

	string print_list() {
		LL *temp = head;
		ostringstream ss; //This lets us write to a string like we do to cout
		if (!temp) {
			ss << "Empty List\n";
			return ss.str(); //Converts the stringstream to a string so we can return it
		}
		while (temp) {
			ss << "Province: " << left << setw(12) << temp->get_province() << " Cost: " << temp->get_cost() << endl;
			temp = temp->get_next();
		}
		return ss.str();
	}

	string insert_at_beginning(int cost, string province) {
		string retval = province + " inserted";
		//YOU: Write code to make a new node and insert at the head
		//Make sure size gets updated when you add to the list
		if (head == nullptr){
			LL *node = new LL{cost,province,nullptr, nullptr};
			head = node;
			tail = node;
			size++;
			return retval;
		}
		LL *node = new LL{cost, province, nullptr, head};
		head->set_prev(node);
		head = node;
		size++;
		return retval;
	}
	string insert_at_end(int cost, string province) {
		string retval = province + " inserted";
		//YOU
		size++;
		if (head == nullptr) {
			LL *node = new LL{cost,province, nullptr, nullptr};
			head = tail = node;
			return retval;
		}
		LL *l= new LL{cost,province,tail,nullptr};
		tail->set_next(l);
		tail =l;
		return retval;
	}
	//This function will delete a single node from the LL with a cost <= amount
	//amount_out will hold how much change was left over after the delete was done
	//It will return sentence containing "X deleted\n" (if node X was deleted) or "Nothing deleted"
	string delete_amount(int amount,int &amount_out) {
		string s; //Will be set to the province name deleted
		//YOU: First, handle the list being empty
		if (head == nullptr) return "Nothing deleted";
		//YOU: Second, handle there being one element in the list
		if (size ==1){
			if (head->get_cost() <= amount){
				size--;
				amount_out = amount -head->get_cost();
				s = head->get_province();
				delete head;
				head = tail = nullptr;
				return s + " deleted";
			}
		}
		//YOU: Third, handle deleting from the head or tail 
		for (LL *i = head; i;i = i->get_next()){
			if (i->get_cost() <= amount){ 
				size--;
				amount_out = amount - i->get_cost();
				s = i->get_province();
				if (i == head){
					head = i->get_next();
					head->set_prev(nullptr);
					delete i;
				}
				else if(i==tail){
					tail = i->get_prev();
					tail->set_next(nullptr);
					delete i;
				}
				else {
					i->get_prev()->set_next(i->get_next());
					i->get_next()->set_prev(i->get_prev());
					delete i;
				}
				return s + " deleted";
			}
		}
		return "Nothing deleted";
		//YOU: Handle deleting from the middle of the list

		//Helpful hints - keep track of all of your invariants:
			//1. Size should always be updated when you insert or delete
			//2. All pointers to next and previous from neighbors should be updated if you delete a node in the middle
			//3. If you delete the data at head, head will need to move to head->get_next()
			//4. If you delete from the tail, tail will need to move backwards to tail->get_prev()
			//Don't use pointers to things after you've deleted them
	}
};

//DO NOT MODIFY THIS FUNCTION. IT WILL TEST YOUR LIST CLASS
void List_test() {
	List l,l2;

	//Check for empty list
	string s = l.print_list();
	if (s != "Empty List\n") die("List::print_list() is broken.");

	//Insert first node
	s = l.insert_at_beginning(30,"Moscow");
	if (s != "Moscow inserted") die("List::insert_at_beginning didn't work with an empty list.");
	if (l.get_size() != 1) die("Your size wasn't updated properly in insert_at_beginning.");
	s = l.print_list();
	if (s == "Empty List\n") die("Insert at beginning isn't working with an empty list.");


	//Insert second node
	s = l.insert_at_beginning(40,"Beijing");
	if (s != "Beijing inserted") die("List::insert_at_beginning didn't work with a non-empty list.");
	if (l.get_size() != 2) die("Your size wasn't updated properly in insert_at_beginning.");

	//Insert first node in another list
	s = l2.insert_at_end(60,"Nanjing");
	if (s != "Nanjing inserted") die("List::insert_at_end didn't work with an empty list.");
	if (l2.get_size() != 1) die("Your size wasn't updated properly in insert_at_end.");

	//Insert third node at the end
	s = l.insert_at_end(5,"Ile-de-france");
	if (s != "Ile-de-france inserted") die("List::insert_at_end didn't work with a non-empty list.");
	if (l.get_size() != 3) die("Your size wasn't updated properly in insert_at_end.");

	//Insert fourth node at the end
	s = l.insert_at_end(20,"Roma");
	if (s != "Roma inserted") die("List::insert_at_end didn't work with a non-empty list.");
	if (l.get_size() != 4) die("Your size wasn't updated properly in insert_at_end.");

	//Insert fifth node at the beginning
	s = l.insert_at_beginning(10,"Kiev");
	if (s != "Kiev inserted") die("List::insert_at_beginning didn't work with a non-empty list.");
	if (l.get_size() != 5) die("Your size wasn't updated properly in insert_at_end.");

	//Delete Ile-de-France from the middle (cost 5, with 6 as the amount)
	int change = 0;
	if (l.delete_amount(6,change) != "Ile-de-france deleted") die("Deleting Ile-de-france failed");
	if (change != 1) {
		cout << "Deleting Ile-de-France (Cost 5, Amount 6) should return 1 change but you returned " << change << endl;
		die("");
	}

	//Delete Kiev from front of list (Cost 10, Amount 10)
	s = l.delete_amount(10,change);
	if (s != "Kiev deleted") {
		cout << "You were supposed to return 'Kiev deleted' but you printed '" << s << "'.\n";
		die("Deleting Kiev failed");
	}
	if (change != 0) die("Deleting Kiev returned wrong change (should be 0)");

	//Delete Roma from end of list (Cost 10, Amount 10)
	if (l.delete_amount(23,change) != "Roma deleted") die("Deleting Roma failed");
	if (change != 3) die("Deleting Roma returned wrong change (should be 3)");

	//Testing the list
	s = l.print_list();
	string t = "Province: Beijing      Cost: 40\nProvince: Moscow       Cost: 30\n";

	if (s != t) { 
		cout << "The code is supposed to print:\n" << t;
		cout << "But you printed:\n" << s;
		die("");
	}

	//Add a few more
	l.insert_at_end(50,"Cairo");
	l.insert_at_end(40,"Aleppo");
	l.insert_at_beginning(20,"Ayutthaya");
	l.insert_at_end(30,"Ternate");
	l.insert_at_beginning(30,"Kyoto");
	s = l.print_list();
	t = "Province: Kyoto        Cost: 30\nProvince: Ayutthaya    Cost: 20\nProvince: Beijing      Cost: 40\nProvince: Moscow       Cost: 30\nProvince: Cairo        Cost: 50\nProvince: Aleppo       Cost: 40\nProvince: Ternate      Cost: 30\n";
	if (s != t) {
		cout << "The code is supposed to print:\n" << t;
		cout << "But you printed:\n" << s;
		die("");
	}
	l.delete_amount(20,change); //Ayutthaya
	l.delete_amount(30,change); //Kyoto
	l.delete_amount(30,change); //Moscow
	l.delete_amount(30,change); //Ternate
	s = l.print_list();
	t = "Province: Beijing      Cost: 40\nProvince: Cairo        Cost: 50\nProvince: Aleppo       Cost: 40\n";
	if (s != t) {
		cout << "The code is supposed to print:\n" << t;
		cout << "But you printed:\n" << s;
		die("");
	}
	l.delete_amount(40,change); //Beijing
	s = l.print_list();
	t = "Province: Cairo        Cost: 50\nProvince: Aleppo       Cost: 40\n";
	if (s != t) {
		cout << "The code is supposed to print:\n" << t;
		cout << "But you printed:\n" << s;
		die("");
	}
	l.delete_amount(40,change); //Aleppo
	s = l.print_list();
	t = "Province: Cairo        Cost: 50\n";
	if (s != t) {
		cout << "The code is supposed to print:\n" << t;
		cout << "But you printed:\n" << s;
		die("");
	}
	l.delete_amount(40,change); //Nothing
	l.delete_amount(40,change); //Nothing
	l.delete_amount(50,change); //Cairo
	s = l.print_list();
	t = "Empty List\n";
	if (s != t) {
		cout << "The code is supposed to print:\n" << t;
		cout << "But you printed:\n" << s;
		die("");
	}
	if (l.get_size() != 0) {
		cout << "The list should be empty since I've deleted everything, but you say the size is " << l.get_size() << endl;
		die("Make sure you add to size in your inserts and subtract from it in your deletes");
	}
	s = l.delete_amount(50,change); //Nothing
	if (s != "Nothing deleted") {
		die("The code tried deleting from an empty list but your code did not return 'Nothing deleted'.");
	}
}
