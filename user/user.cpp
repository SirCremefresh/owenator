//
// Created by Donato Wolfisberg on 13.12.2017.
//

#include "user.h"

#include <utility>

List<User>* userList = new List<User>;

List<User> *getUserList() {
	return userList;
}


void setUserList(List<User> *userListNew) {
	if (userList != nullptr) {
		delete userList;
		userList = userListNew;
	}
}

User* addUser(string username, string password) {
	auto* user = new User;
	user->username = std::move(username);
	user->password = std::move(password);
	return addNode(user, userList)->value;
}

User *getUserWith(string username, string password) {
	NodeWrapper<User>* userWrapper = nullptr;
	User *user;
	while (getNextNode(&userWrapper, userList)) {
		user = userWrapper->value;
		if (user->username == username && user->password == password) {
			return user;
		}
	}
	return nullptr;
}

bool doesUsernameExist(string username) {
	NodeWrapper<User>* userWrapper = nullptr;
	User *user;
	while (getNextNode(&userWrapper, userList)) {
		user = userWrapper->value;
		if (user->username == username) {
			return true;
		}
	}
	return false;
}

