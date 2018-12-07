#include "Database.h"
#include <iostream>
#include <stdexcept>
using namespace std; 
using namespace Records; 

int displayMenu(); 
void doHire(Database &db); 
void doFire(Database &db);
void doPromote(Database &db);
void doDemote(Database &db); 
int main()
{
	Database empDb; 
	bool isDone = false; 

	while (!isDone) {

		int selection = displayMenu(); 
		switch (selection)
		{
		case 0: 
			isDone = true; 
			break; 
		case 1: 
			doHire(empDb);
			break; 
		case 2:
			doFire(empDb);
			break; 
		case 3: 
			doPromote(empDb);
			break; 
		case 4: 
			empDb.displayAll(); 
			break; 
		case 5: 
			empDb.displayCurrent(); 
			break; 
		case 6: 
			empDb.displayFormer(); 
			break; 
		case 7: 
			doDemote(empDb); 
			break; 
		default: 
			cerr << "UNKNOWN COMMAND" << endl; 
			break; 





		}



	}


	return 0; 



}

int displayMenu() {

	int selection;

	cout << endl; 
	cout << "Employee Database" << endl; 
	cout << "-----------------" << endl; 
	cout << "1) Hire an employee: " << endl;
	cout << "2) Fire an employee: " << endl;
	cout << "3) Promote an employee: " << endl;
	cout << "4) List all employees: " << endl;
	cout << "5) List all current employees: " << endl;
	cout << "6) List all former employees: " << endl;
	cout << "7) Demote an employee: " << endl; 
	cout << "0) Quit" << endl;
	cout << endl; 
	cout << "---> ";
	cin >> selection;
	return selection; 








}


void doHire(Database &db) {

	string firstName; 
	string lastName; 

	cout << "First name: ";
	cin >> firstName; 
	cout << "Last name: ";
	cin >> lastName; 

	db.addEmployee(firstName, lastName); 

}

void doFire(Database &db)
{
	int employeeNumber; 

	cout << "Employee Number: "; 
	cin >> employeeNumber; 

	try {

		Employee &emp = db.getEmployee(employeeNumber); 
		emp.fire(); 
		cout << "Employee " << employeeNumber << " terminated." << endl; 

	}
	catch (const std::logic_error& exception)
	{
		cout << "Unable to terminate employee: " << exception.what() << endl; 
	}
}

void doPromote(Database &db)
{
	int employeeNumber; 
	int raiseAmount; 

	cout << "Employee Number: ";
	cin >> employeeNumber;
	cout << endl; 
	cout << "Raise Amount: "; 
	cin >> raiseAmount; 

	try {
		Employee &emp = db.getEmployee(employeeNumber); 
		emp.promote(raiseAmount);

	}
	catch (const std::logic_error& exception)
	{
		cout << "Unable to promote employee.." << exception.what() << endl; 
	}

}

void doDemote(Database &db) {

	int employeeNumber; 
	int demerit; 

	cout << "Enter employee number: ";
	cin >> employeeNumber; 
	cout << endl; 
	cout << "Enter amount to demerit: "; 
	cin >> demerit; 
	cout << endl; 

	try {
		Employee &emp = db.getEmployee(employeeNumber); 
		emp.demote(demerit); 

	}
	catch (const std::logic_error exception) {
		cout << "Could not demote employee.." << exception.what() << endl;
	}


}
