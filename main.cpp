#include <iostream>
//#include <thread>

#include "gui\gui.h"

#include "debt/debt.h"
#include "person/person.h"
#include "user/user.h"


using namespace std;

void threadfunction() {
	cout << "thrad";
}

void main() {
	//thread t(&threadfunction);
	cout << "Hallo";
	moveCursor(10,10);
	cout << "hoi";

	Button buttons[2];
	Button* btn = new Button;
	btn->text = "Hallo";
	btn->x = 2;
	btn->y = 5;
	buttons[0] = *btn;

	btn = new Button;
	btn->text = "Hoi";
	btn->x = 2;
	btn->y = 8;
	buttons[1] = *btn;

	addButton(buttons);

	getchar();
}

/*
User* uzser = addUser("Gian", "1234");
User* uzsedr = addUser("Donato", "12dd34");

Person* person1 = addPerson(uzser, "da", "fasdf");
Person* person2 = addPerson(uzser, "da2", "fasdf");
Person* person3 = addPerson(uzser, "da3", "fasdf");
Person* person4 = addPerson(uzser, "da4", "Gian");
addDebt(person1, "kdjfkla", 2);
addDebt(person1, "kdjfkla", 3242123);
addDebt(person1, "kdjfkla", 32423123);
addDebt(person1, "kdjfkla", 3212423);

User* user = nullptr;
while (getNextUser(&user)) {
cout << user->id << " " << user->username << " " << user->password << endl;
Person* aaa = nullptr;
while (getNextPerson(user, &aaa)) {
std::cout << "Person: " << aaa->id << " " << aaa->name << endl;
Debt* bbb = nullptr;
while (getNextDebt(aaa, &bbb)) {
cout << bbb->id << " " << bbb->reason << " " << bbb->amount << endl;
}
}
}
*/
