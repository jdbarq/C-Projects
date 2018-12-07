#pragma once
#include <iostream>
#include <string>



namespace Records {

	const int kDefaultStartingSalary = 3000;





	class Employee {

	public:
		Employee() = default;
		Employee(const std::string& firstName,
			const std::string& lastName); //const so the value doesn't change
		void promote(int raiseAmount = 1000); // values change
		void demote(int decrease = 1000); // values change
		void hire(); //change
		void fire(); //change
		void display() const; //outputs employee info 

		//getters and setters
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isHired() const;


	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber = -1;
		int mSalary = kDefaultStartingSalary; 
		bool mHired = false;





	};
}
