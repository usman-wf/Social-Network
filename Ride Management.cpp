#include<iostream>
using namespace std;

class Name
{
private:
	char* fName;
	char* lName;
public:
	Name(char* fN, char* lN);
	//add following functions //Getter, Setters
	//Destructor, Default Constructor, Copy Constructor,
	friend ostream& operator<<(ostream& out, const Name& n)
	{
		out << n.fName << " " << n.lName << endl;
		return out;
	}

};

class Date
{
	int day;
	int month;
	int year;
	//add constructurs getter setters and stream output function, which output date in 
	//given format day / Mon / Year
};

class mTime
{
	int hour;
	int min;
	int sec;
	//add constructurs getter setters and stream output function, which output time in 
	//given format Hr : Min: Sec
};

class Service
{
	char* source;
	char* destination;
	float distance; //in km
	Date bookingDate;
	mTime bookingTime;
	bool status; // false for pending, true if complete
	float fuelrate;
	int cId; // Customer Id who booked the ride
	int dId; // Driver Id
	int vId; // vehicle Id
	//you can add more members here if required
	//add member functions
};

class Ride : public Service 
{
	int noofPassengers; // false for pending, true if complete
	char* rideType; // intercity, intracity
	float DriverRanking; // 0 to 5 scale (worst to best)
	float VehicleRanking; // 0 to 5 scale (worst to best)
	//you can add more members here if required
	//add member functions
};

class Delivery : public Service
{
	float goodsWeight; // Weight of goods in Kg
	char* goodsType; //type of goods food, furniture, petroleum, chemicals, etc.
	//you can add more members here if required
	//add member functions
};

class Person
{
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	//add following functions in this class //Getter, Setters
	//Destructor, Default and Parametrized Constructor, Copy Constructor, Output 
	//operator (print information of person)
};

class Customer : public Person {
private:
	int cId;
	// Unique and assigned first time when customer makes first service request
	Service** bookingHistory;
	//Maintain and Update history of customer for each service (ride or goods 
	//transportation order) by adding address of service in dynamic array.
	//you can add more members here if required
public:
	//add following functions in this class //Getter, Setters
	//Destructor, Default and Parametrized Constructor, Copy Constructor, Output 
	//operator (print complete information of customer including history if any)
};

class Driver : public Person
{
private:
	int dId;
	char** LicencesList;
	int noofLicences;
	float overallRanking;
	float salary;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if canceled
	Service** serviceHistory;
	//Add services address in the array for tracking complete information of service.
public:
	//add following functions in this class
	//Getter, Setters
	//Destructor, Default and Parameterized Constructor, Copy Constructor, Output 
	//operator (prints complete information of Driver)
};

class Feature
{
	int fId;
	char* description;
	float cost;
	//you can add more members here if required
	//add member functions
};

class Vehicle 
{
	int vId;
	int registrationNo;
	float avgMileage;
	char* LicenceType; // License required for driving the vehicle
	bool status; // false for free, true if booked in a service already
	char* fueltype;
	float overallRanking;
	Date manufacturingDate;
	Feature* list;
	Service** serviceHistory;
	//Add services address in the array for tracking complete information of service.
	//you can add more members here if required
	//add member functions
};
//add Complete Hierarchy of vehicles based on their types and functions
void main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int i = 0; i < 5; i++)
			{

			}
		}
	}
}