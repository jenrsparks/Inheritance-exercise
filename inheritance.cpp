#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<iostream.h>
#include<string>

using std::string;

class Object {
public:
	Object() { }
	~Object() { }
	virtual void inputData() = 0;
	virtual void printData() = 0;
}; // Object

class ClassG: public Object {
public:
	ClassG() { }
	~ClassG() { }
	virtual void inputData() { }
	virtual void printData() { }
}; // ClassG

class Class1: public ClassG{
protected:
	char data;
public:
	Class1(){ }
	~Class1(){ }

	void inputData(){
		try{
			cout << "\n\tEnter character >>>  ";
			cin >> data;
		} catch(string e) {
			data = ' ';
		}
	}

	void printData(){
		cout << "\n\tData:\t'"<< data << "'" << endl;
	}
};	// Class1

class Class2: public ClassG{
    protected:
        int data;
    public:
        Class2(){ }
        ~Class2(){ }

	void inputData(){
		try {
			cout << "\n\tEnter integer >>>  ";
			cin >> data;
		} catch(string e) {
			data = 1;
		}
	}

	void printData(){
		cout << "\n\tData:\t " << data << endl;
	}
};	// Class2

class Class3: public ClassG{
protected:
	float data;
public:
	Class3(){ }
	~Class3(){ }

	void inputData(){
		try {
			cout << "\n\tEnter float >>>  ";
			cin >> data;
		} catch(string e) {
			data = 1.0;
		}
	}

	void printData(){
		cout << "\n\tData:\t "<< data << endl;
	}
};	// Class3

class Class4: public ClassG{
protected:
	string data;
public:
	Class4(){ }
	~Class4(){ }

	void inputData(){
		try {
			cout << "\n\n\tEnter string >>>  ";
			cin >> data;
		} catch(string e) {
			data = "";
		}
	}

	void printData(){
		cout << "\n\tData:\t"<< data << endl;
	}
};	// Class4

int main() {
	int choice = 1;
	ClassG *morpher;
	
	while(choice != 5) {
		cout << "\n\tUsing Virtual Classes";
		cout << "\n\n\tWhat type of value would you like to enter?" << endl;
		cout << "\t1. Integer\t2. Float\t3. Character\n\t4. String\t5. Exit";
		cout << "\n\t> ";
		try {
			cin >> choice;
		} catch(string e) {
			cout << "\n\t\tInvalid choice - default choice = 1";
			choice = 1;
		}

		switch(choice) {
			case 2:			// float
				morpher = new Class3;
				break;
			case 3:			// character
				morpher = new Class1;
				break;
			case 4:			// string
				morpher = new Class4;
				break;
			default:		// integer
				morpher = new Class2;
				break;
		} // end switch
		if(choice == 5) break;
		morpher -> inputData();
		morpher -> printData();
		delete morpher;
		cout << "\n\t";
		system("pause");
		system("cls");
	} // end while

	cout << "\n\t";	
	system("pause");
	return 0;
}
