//
// Created by Donato Wolfisberg on 18.12.2017.
//

#include "dept.h"

Dept *addDept(string reason, double amount, Person *person) {
	auto *dept = new Dept();
	dept->reason = reason;
	dept->amount = amount;
	return addNode(dept, person->deptList)->value;
}

double getSumOfDept(Person *person) {
	double sum = 0;
	NodeWrapper<Dept>* deptWrapper = nullptr;
	while (getNextNode(&deptWrapper, person->deptList)) {
		sum += deptWrapper->value->amount;
	}
	return sum;
}
