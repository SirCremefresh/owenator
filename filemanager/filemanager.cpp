//
// Created by Donato Wolfisberg on 20.12.2017.
//

#include "filemanager.h"
#include "../list/list.h"
#include "../user/user.h"
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

void loadFromFile() {
	DWORD dwAttr = GetFileAttributes("C:\\ProgramData\\owenatorv2");

	if (dwAttr != 0xffffffff && (dwAttr & FILE_ATTRIBUTE_DIRECTORY)) {
		std::string fileName(R"(C:\ProgramData\owenatorv2\owenator.money)");
		ifstream fin(fileName.c_str());

		if (!fin.fail()) {
			List<User> *userList = new List<User>;
			fin >> userList->length;
			fin >> userList->idCounter;
			for (unsigned long userCounter = 0; userCounter < userList->length; userCounter++) {
				User *user = new User;
				fin >> user->id;
				fin >> user->username;
				fin >> user->password;

				fin >> user->personList->length;
				fin >> user->personList->idCounter;
				for (unsigned long personCounter = 0; personCounter < user->personList->length; personCounter++) {
					Person *person = new Person;
					fin >> person->id;
					fin >> person->forename;
					fin >> person->surname;

					fin >> person->deptList->length;
					fin >> person->deptList->idCounter;
					for (unsigned long deptCounter = 0; deptCounter < person->deptList->length; deptCounter++) {
						Dept *dept = new Dept;
						fin >> dept->id;
						fin >> dept->reason;
						fin >> dept->amount;
						addNodeInternal(dept, person->deptList);
					}
					addNodeInternal(person, user->personList);
				}
				addNodeInternal(user, userList);
			}
			setUserList(userList);
		}
	}
}

void saveToFile() {
	CreateDirectory("C:\\ProgramData\\owenatorv2", NULL);
	ofstream fileHandle;
	fileHandle.open(R"(C:\ProgramData\owenatorv2\owenator.money)", ios::out | ios::trunc);
	if (fileHandle.is_open()) {
		fileHandle << getUserList()->length << endl;
		fileHandle << getUserList()->idCounter << endl;
		NodeWrapper<User> *userWrapper = nullptr;
		while (getNextNode(&userWrapper, getUserList())) {
			fileHandle << userWrapper->value->id << endl;
			fileHandle << userWrapper->value->username << endl;
			fileHandle << userWrapper->value->password << endl;

			fileHandle << userWrapper->value->personList->length << endl;
			fileHandle << userWrapper->value->personList->idCounter << endl;
			NodeWrapper<Person> *personWrapper = nullptr;
			while (getNextNode(&personWrapper, userWrapper->value->personList)) {
				fileHandle << personWrapper->value->id << endl;
				fileHandle << personWrapper->value->forename << endl;
				fileHandle << personWrapper->value->surname << endl;

				fileHandle << personWrapper->value->deptList->length << endl;
				fileHandle << personWrapper->value->deptList->idCounter << endl;
				NodeWrapper<Dept> *deptWrapper = nullptr;
				while (getNextNode(&deptWrapper, personWrapper->value->deptList)) {
					fileHandle << deptWrapper->value->id << endl;
					fileHandle << deptWrapper->value->reason << endl;
					fileHandle << deptWrapper->value->amount << endl;
				}

			}
		}
		fileHandle.close();
	}

}
