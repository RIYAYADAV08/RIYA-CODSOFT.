#include <iostream>
using namespace std;
int main()
{
	char op;
	float num1, num2,result;
	cout<<"Enter First Number: ";
	cin >> num1;
	cout<<"Enter Second Number: ";
	cin >> num2;
	cout<<"Enter Operand (+, -, * or /): ";
	cin >> op;
	switch (op) {
	case '+':
		result=num1 + num2;
		break;
	case '-':
		result= num1 - num2;
		break;
	case '*':
		result=num1 * num2;
		break;
	case '/':
	if (num2 != 0){
		result= num1 / num2;
	}
	else{
		cout<<"Error!";
		return 1;
	}
		break;
	default:
		cout << "Error! operator is not correct";
	}
	cout<<"Result: "<<result<<endl;
	return 0;
}
