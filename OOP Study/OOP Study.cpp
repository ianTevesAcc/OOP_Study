// Test Run
/*
#include <iostream>
#include <string>

int main() {
	//declare str var
	std::string name;
	char fullName[20];

	//ask user their name
	std::cout << "What is your name user? ";
	getline(std::cin, name);
	
	//greet user
	std::cout << "Hello " << name << std::endl;

	return 0;
}
*/

//Introduction to OOP

//CLASSES AND OBJECTS - CONSTRUCTOR
// classes are user defined data type which are different from pre defined data types which are int, char, float, double, string
/*
#include <iostream>
using namespace std;

// Declaring a class called "Employee"
class Employee {
public:
	// Class members (variables)
	string name, company;
	int age;

	// Class member function (method)
	void introduceSelf() {
		// Outputting the values of the class members
		cout << "Name: " << name << endl;
		cout << "Company: " << company << endl;
		cout << "Age: " << age << endl;
	}

	Employee(string name, string company, int age) {
		this->name = name;
		this->company = company;
		this->age = age;
	}
};

int main() {
	// Variable to store the number of employees
	int number;

	// Asking the user to enter the number of employees
	cout << "Enter number of employees: " << endl;
	cin >> number;

	// Dynamically allocating memory for an array of "Employee" objects
	Employee* employees = new Employee[number];

	// Loop to enter the details of each employee
	for (int i = 0; i < number; i++) {
		cout << "Enter name, age, and company for employee " << i + 1 << endl;
		cin >> employees[i].name >> employees[i].age >> employees[i].company;
	}

	// Loop to display the details of each employee
	for (int i = 0; i < number; i++) {
		cout << "Employee " << i + 1 << ": " << endl;
		employees[i].introduceSelf();
	}

	// Deallocating the memory for the array of "Employee" objects
	delete[] employees;

	// Returning 0 to indicate success
	return 0;
}
*/

//ENCAPSULATION
/*
#include <iostream>
using namespace std;

struct EmployeeData {
	string name, company;
	int age;

	~EmployeeData() {};
};

class Employee {
private:
	string name, company;
	int age;

public:
	// class member functions
	void intro() {
		cout << "Name:\t\t" << name << endl;
		cout << "Company:\t" << company << endl;
		cout << "Age:\t\t" << age << endl;
	}

	void setData(string name, string company, int age) {	// setter function
		if (age > 19) {
			this->name = name;
			this->company = company;
			this->age = age;
		}
		else {
			cout << "User must be 18+ to be qualified to be an Employee" <<	endl;
		}
	}

	//getter functions
	string getName() {
		return name;
	}
	string getCompany() {
		return company;
	}
	int getAge() {
		return age;
	}

};

int main() {
	Employee employee1;
	employee1.setData("Ian Teves", "Mash Finance", 20);
	employee1.intro();

	Employee employee2;
	employee2.setData("John", "Doe", 10);
	cout << "Name:\t\t" << employee2.getName() << endl;
	cout << "Company:\t" << employee2.getCompany() << endl;
	cout << "Age:\t\t" << employee2.getAge() << endl;

	return 0;
}
*/

//ABSTRACTION
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractEmployee {
	virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
	string name, company;
	int age;

public:
	Employee(string name, string company, int age) {
		this->name = name;
		this->company = company;
		this->age = age;
	}
	void printEmployeeData() {
		cout << "name:\t\t" << name << endl;
		cout << "company:\t\t" << company << endl;
		cout << "age:\t\t" << age << endl;
	}
	void AskForPromotion() {
		if (age > 19) {
			cout << name << ": promotion accepted" << endl;
		}
		else {
			cout << name << ": promotion denied" << endl;
		}
	}
};

int main() {
	vector<Employee> employeeList;

	NUM_VALID:
	cout << "Enter how much employees youd like to input: ";
	int n; cin >> n;
	while (n < 1 || n > 11) {
		cerr << "ERROR: Invalid input. Enter a number between 1 and 10: ";
		goto NUM_VALID;
	}
	
	string employeeData[3];
	for (int i = 0; i < n; i++) {
		cout << "EMPLOYEE " << i + 1 << endl;
		cout << "Name: ";
		cin >> employeeData[0];
		cout << "Company: ";
		cin >> employeeData[1];
		cout << "Age: ";
		cin >> employeeData[2];
		employeeList.push_back(Employee(employeeData[0], employeeData[1], stoi(employeeData[2])));
	}

	//different ways to output data in vector
	for (auto employee : employeeList) { // easiest way
		employee.printEmployeeData();
		employee.AskForPromotion();
	}
	//for (auto it = employeeList.begin(); it != employeeList.end(); it++) {
	//	it->printEmployeeData();
	//}
	//for (int i = 0; i < employeeList.size(); i++) {
	//	employeeList[i].printEmployeeData();
	//}


	return 0;
}
*/

#include <iostream>
#include <vector>

using namespace std;

// Base class
class Shape {
public:
	virtual void draw() {
		cout << "Drawing a shape." << endl;
	}
};

// Derived class
class Circle : public Shape {
public:
	void draw() {
		cout << "Drawing a circle." << endl;
	}
};

// Derived class
class Square : public Shape {
public:
	void draw() {
		cout << "Drawing a square." << endl;
	}
};

int main() {
	vector<Shape*> shapes;  // Vector of pointers to Shape objects
	shapes.push_back(new Circle());
	shapes.push_back(new Square());
	shapes.push_back(new Circle());

	// Iterating through the vector and calling draw()
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->draw();
	}

	return 0;
}

//POLYMORPHISM
/*
#include <iostream>
#include <vector>

namespace stdFunctions {
	using std::cout;
	using std::vector;
	using std::endl;
}

// Base class
using namespace stdFunctions;

class Shape {
public:
	virtual void draw() {
		cout << "Drawing a shape." << endl;
	}
};

// Derived class
class Circle : public Shape {
public:
	void draw() {
		cout << "Drawing a circle." << endl;
	}
};

// Derived class
class Square : public Shape {
public:
	void draw() {
		cout << "Drawing a square." << endl;
	}
};

int main() {
	vector<Shape*> shapes;  // Vector of pointers to Shape objects
	shapes.push_back(new Circle());
	shapes.push_back(new Square());
	shapes.push_back(new Circle());

	// Iterating through the vector and calling draw()
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->draw();
	}

	return 0;
}
*/

//VIRTUAL FUNCTION
/*
#include <iostream>
#include <vector>
using namespace std;

class Instrument { //Abstract class because it contains a pure virtual function
public:
	virtual void makeSound() = 0; // pure virtual function
	//virtual void makeSound() { cout << "Instrument is playing..." << endl; }; // pure virtual function
};

class Accordion : public Instrument {
public:
	void makeSound() {
		cout << "Accordion is playing..." << endl;
	}
};
class Piano : public Instrument {
public:
	void makeSound() {
		cout << "Piano is playing..." << endl;
	}
};

int main() {
	////normal classes allocation
	//Instrument* i1 = new Accordion();
	//i1->makeSound();
	//Instrument* i2 = new Piano();
	//i1->makeSound();
	//i2->makeSound();
	//
	//Instrument* instruments[2] = {i1,i2};
	//for (int i = 0; i < 2; i++) {
	//	instruments[i]->makeSound();
	//}

	//vector classes example
	vector<Instrument*> instrument;
	instrument.push_back(new Accordion());
	instrument.push_back(new Piano());

	for (int i = 0; i < instrument.size(); i++) {
		instrument[i]->makeSound();
	}

	return 0;
}
*/
//Structs
/*
#include <iostream>
using namespace std;

struct Phone {
	string brand;
};

struct Employee{
	string name;
	int age;
	Phone brand;
};

void printEmployee(Employee e) {
	cout << "name:\t" << e.name << endl;
	cout << "age:\t" << e.age << endl;
	cout << "phone:\t" << e.brand.brand << endl;
}

void employeeQuestions(Employee& e) {
	cout << "Enter Name: ";
	cin >> e.name;
	cout << "Enter Age: ";
	cin >> e.age;
	cout << "Enter Phone Brand: ";
	cin >> e.brand.brand;
}

int main() {
	int n = 0;

INVALID:
	cout << "How many entries would you like to create? ";
	cin >> n;

	if (n < 1 || n > 10) {
		cerr << "Error: use input too high or low" << endl;
		goto INVALID;
	}

	Employee* e = new Employee[n];

	for (int i = 0; i < n; i++) {
		employeeQuestions(e[i]);
	}
	for (int i = 0; i < n; i++) {
		printEmployee(e[i]);
	}

	delete[] e;

	return 0;
}
*/
//VECTORS
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> numbers;
	for (int i = 0; i < 10; i++) { // place elements inside vector that changes size
		numbers.push_back(i);
	}

	////insert/erase elements at specific places in vector
	//numbers.insert(numbers.begin() + 5, 88);	// inserts element into vector defined by developer
	//numbers.erase(numbers.begin() + 5);			// clears specific element defined by developer
	//numbers.pop_back();							// clears last element of vector

	//for (int i : numbers) {
	//	cout << i << "\t";
	//}

	////Vector Uses
	//cout << "Size:\t\t\t" << numbers.size() << endl;
	//cout << "Max Size:\t\t" << numbers.max_size() << endl;
	//cout << "Capacity:\t\t" << numbers.capacity() << endl;
	//cout << "Element [2] is:\t\t" << numbers[2] << endl;
	//cout << "Element at [2] is:\t" << numbers.at(2) << endl;
	//cout << "Front:\t\t\t" << numbers.front() << endl;
	//cout << "Back:\t\t\t" << numbers.back() << endl;
	//numbers.resize(1);
	//cout << "Size:\t\t\t" << numbers.size() << endl;
	//if (numbers.empty()) { cout << "Vector is empty" << endl; }
	//else { cout << "Vector is not empty" << endl; }
	//numbers.clear();
	//cout << "Size:\t\t\t" << numbers.size() << endl;
	//if (numbers.empty()) { cout << "Vector is empty" << endl; }
	//else { cout << "Vector is not empty" << endl; }

	////loop examples
	//for (int number : numbers) { //output to console vector elements
	//	cout << number << endl;
	//}
	//for (auto it = numbers.begin(); it != numbers.end(); it++) { //itterators
	//	cout << *it << endl;
	//	cout << &it << endl;
	//	cout << &(*it) << endl;
	//}

	return 0;
}
*/
//MAP
/*
#include <iostream>
#include <map> // ordered map based on ASCII
//#include <unordered <map>
#include <string>
#include <list>

using namespace std;

int main() {
	////DICTIONARY EXAMPLE
	////unordered_map<string, string> dictionary;
	//map<string, string> dictionary;
	//dictionary.insert(pair<string, string>("apple", "mansanas"));
	//dictionary.insert(pair<string, string>("people", "tao"));
	//dictionary.insert(pair<string, string>("bitch", "gago"));
	////access and change value in a map
	//dictionary["apple"] = "pulang masanas";
	//dictionary.erase("bitch");
	//cout << dictionary.size() << endl;
	//for (auto pair : dictionary) {
	//	cout << pair.first << " - " << pair.second << endl;
	//}
	//dictionary.clear();
	
	map<string, list<string>> pokedex;

	list<string> pikachuAttacks{ "thunder shock", "tail whip", "quick tail" };
	list<string> charmanderAttacks{ "flame thrower", "scary face"};
	list<string> chikoritaAttacks{ "razor leaf", "poison powder" };

	pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
	pokedex.insert(pair<string, list<string>>("Charmander", charmanderAttacks));
	pokedex.insert(pair<string, list<string>>("Chikori", chikoritaAttacks));

	for (auto pair : pokedex) {
		cout << pair.first << " - ";
		auto it = pair.second.begin();
		for (; it != pair.second.end(); ++it) {
			if (std::next(it) == pair.second.end()) {
				cout << *it << endl;
				break;
			}
			cout << *it << ", ";
		}
	}


	return 0;
}
*/
//OPERATOR OVERLOADING
/*
#include <iostream>

//NumberCalculator Function
class Calc {
	int num;
public:
	//Constructors
	Calc() {
		num = 0;
	}
	Calc(int num) {
		this->num = num;
	}
	Calc operator +(Calc num){ // operator overload
		Calc temp;
		temp.num = this->num + num.num;
		return temp;
	}

	// member functiosn
	int getNum() {
		return num;
	}
};

int main() {
	Calc c1(2);
	Calc c2(4);
	Calc c3;

	c3 = c1 + c2;
	std::cout << c1.getNum() << " + " << c2.getNum() << " = " << c3.getNum() << std::endl;

	return 0;
}
*/
//POINTERS
//c
/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	int n = 10;
	int* ptr = (int*)malloc(n * sizeof(int));		// allocate memory for 10 integers
													// ptr = (int*)calloc(n, sizeof(int)); can also be used 
													   here to fill the ptr heap block with 0 instead of being empty
	for (int i = 0; i < n; i++) {
		ptr[i] = i;									// initialize values
	}

	int new_n = 20;
	ptr = (int*)realloc(ptr, new_n * sizeof(int));	// resize the memory block to accommodate 20 integers
	for (int i = n; i < new_n; i++) {
		ptr[i] = i;									// initialize new values
	}

	for (int i = 0; i < new_n; i++) {
		cout << ptr[i] << " ";						// print all values
	}
	cout << endl;

	free(ptr);										// deallocate memory
	ptr = NULL;										// set the pointer to NULL to avoid dangling pointer

	return 0;
}
//In this example, malloc is used to allocate memory for an array of 10 integers. The realloc function is then used 
//to resize the memory block to accommodate 20 integers. The newly initialized values are printed to the console. 
//Finally, the free function is called to deallocate the memory and the pointer is set to NULL to avoid a dangling
//pointer.
*/
/*
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	//malloc
	int* p;
	p = (int*)malloc(sizeof(int));
	*p = 10;
	std::cout << *p << std::endl 
					<< std::endl;

	//realloc
	void* temp = realloc(p, 10 * sizeof(int));
	if (temp == NULL) {
		std::cerr << "Error: realloc failed" << std::endl;
		return 1;
	}

	p = (int*)temp;
	for (int i = 0; i < 10; i++) {
		*(p + i) = a[i];
	}
	for (int i = 0; i < 10; i++) {
		std::cout << *(p + i) << std::endl;
	}
	std::cout << std::endl;

	//calloc
	int* zero;
	zero = (int*)calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++){ 
		a[i] = a[i] * 2;
		*(zero + i) = a[i];
	}
	for (int i = 0; i < 10; i++) {
		std::cout << *(zero + i) << std::endl;
	}
	std::cout << std::endl;

	//free
	free(p);
	free(zero);
	return 0;
}
*/
//cpp
/*
#include <iostream>
using namespace std;

int main() {
	int n = 10;
	int* ptr = new int[n];							// allocate memory for 10 integers
	for (int i = 0; i < n; i++) {
		ptr[i] = i; // initialize values
	}

	int new_n = 20;
	int* new_ptr = new int[new_n];					// allocate memory for 20 integers
	for (int i = 0; i < n; i++) {
		new_ptr[i] = ptr[i];						// copy old values
	}
	for (int i = n; i < new_n; i++) {
		new_ptr[i] = i;								// initialize new values
	}
	delete[] ptr;									// deallocate old memory
	ptr = new_ptr;									// set the pointer to the new memory block

	for (int i = 0; i < new_n; i++) {
		cout << ptr[i] << " ";						// print all values
	}
	cout << endl;

	delete[] ptr;									// deallocate memory
	ptr = NULL;										// set the pointer to NULL to avoid dangling pointer

	return 0;
}
//In this example, new is used to allocate memory for an array of 10 integers. A new memory block is then allocated for 
//20 integers using new. The values from the old memory block are copied over to the new memory block, and the new values 
//are initialized. The old memory block is deallocated using delete[] and the pointer is set to the new memory block. 
//Finally, the new memory block is deallocated using delete[] and the pointer is set to NULL to avoid a dangling pointer.
*/
/*
#include <iostream>
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr = new int;
	int* arrPtr = new int[10];

	//normal ptr
	*ptr = 10;
	std::cout << *ptr << std::endl;
	delete ptr;

	//array ptr
	for (int i = 0; i < 10; i++) {
		arrPtr[i] = arr[i];
	}
	for (int i = 0; i < 10; i++) {
		std::cout << arrPtr[i] << std::endl;
	}
	delete[] arrPtr;

	return 0;
}
*/
//VOID POINTER
/*
#include <iostream>
#include <string>

void printNumber(int* numberPtr) {
	std::cout << *numberPtr << std::endl;
}
void printLetter(char* charPtr) {
	std::cout << *charPtr << std::endl;
}
void print(void* ptr, char type) {
	switch (type) {
	case 'i': 
		std::cout << *((int*)ptr) << std::endl;
		break;
	case 'f': 
		std::cout << *((float*)ptr) << std::endl;
		break;
	case 'd':
		std::cout << *((double*)ptr) << std::endl;
		break;
	case 'b': 
		std::cout << *((bool*)ptr) << std::endl;
		break;
	case 'c': 
		std::cout << *((char*)ptr) << std::endl;
		break;
	case 's': 
		std::cout << *((std::string*)ptr) << std::endl;
		break;
	default:
		std::cout << "ERROR ENCOUNTERED" << std::endl;
	}
}

int main() {
	int number = 97;
	float fnumber = 97.0;
	double dnumber = 97.000000000;
	bool bnumber = true;
	char letter = 'a';
	std::string word = "Ninety Seven";

	print(&number, 'i');
	print(&fnumber, 'f');
	print(&dnumber, 'd');
	print(&bnumber, 'b');
	print(&letter , 'c');
	print(&word, 's');

	//printNumber(&number);
	//printLetter(&letter);

	return 0;
}
*/
//RETURN MULTIPLE VALUES FROM FUNCTION USING PTR
/*
#include <iostream>
using namespace std;

//function to return and sort an arr of numbers taken from main
int* numSort(int* arrPtr, int arrSize) {
	// sorting the array using bubble sort algorithm
	for (int i = 0; i < arrSize - 1; i++) {
		for (int j = 0; j < arrSize - i - 1; j++) {
			if (arrPtr[j] > arrPtr[j + 1]) {
				int temp = arrPtr[j];
				arrPtr[j] = arrPtr[j + 1];
				arrPtr[j + 1] = temp;
			}
		}
	}
	// return the sorted array
	return arrPtr;
}


int main() {
	// declaring variable data types
	const int n = 5;
	int* arrPtr = new int[n];
		
	//get input from user
	for (int i = 0; i < n; i++) {
		cout << "Enter Number: ";
		cin >> arrPtr[i];
	}

	// call function to sort code and return sorted arr to arrPtr
	arrPtr = numSort(arrPtr, n);

	// print the sorted function
	for (int i = 0; i < n; i++) {
		cout << arrPtr[i] << endl;
	}

	delete[] arrPtr;

	return 0;
}
*/