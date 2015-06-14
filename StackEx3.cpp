/*
 * StackEx3.cpp
 *
 *  Created on: 2015年6月15日
 *      Author: yomi
 */
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> stack;
	int data;

	cout<<"Push data as below:"<<endl;
	for(int i = 1 ; i <= 5 ; i++) {
		data = i * 10;
		stack.push(data);
		cout<<"Data = "<<data<<endl;
	}

	cout<<"Pop data as below:"<<endl;
	while(!stack.empty()) {
		data = stack.top();
		cout<<"Data = "<<data<<endl;
		stack.pop();
	}

	return 0;

}



