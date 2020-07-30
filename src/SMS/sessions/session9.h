#pragma once
#ifndef _SMS_PRACTICAL_SESSION_9_H_
#define _SMS_PRACTICAL_SESSION_9_H_

#include <fstream>

namespace SMS
{
	namespace q2_helper
	{
		bool ValidateMonthParam(int& _month)
		{
			if (_month >= 1 && _month <= 12) return true;
			return false;
		}

		bool ValidateDateParam(int& _day, int& _month, int& _year)
		{
			if (_month == 2)
			{
				if ((_year % 400 == 0) || (_year % 4 == 0 && _year % 100 != 0))
				{
					if (_day == 29) return true;
					else return false;
				}
				else if (_day == 28) return true;
				else return false;
			}
			else
			{
				if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
				{
					if (_day == 31) return true;
					else return false;
				}
				else if (_day == 30) return true;
				else return false;
			}
		}
	}

	// 1
	class Car
	{
	public:
		Car(int _year)
		{
			this->year	= _year;
			this->speed = 0;
		}

		string getName() const { return this->make; }

		int getYear() const { return this->year; }

		int getSpeed() const { return this->speed; }
		void setSpeed(int _speed) { this->speed = _speed; }

		void accelerate() { this->speed += 5; }

		void brake() { this->speed -= 5; }

	private:
		int year;
		string make;
		int speed;
	};

	// 2
	class Date 
	{
	private:
		int day;
		int month;
		int year;
	public:
		Date(int _day = 1, int _month = 1, int _year = 2001)
		{
			this->day	= _day;
			this->month = _month;
			this->year	= _year;
		}

		void MonthConverter(int& _month, string& _month_str)
		{
			if (_month == 1)	_month_str		= "January";
			if (_month == 2)	_month_str		= "Febuary";
			if (_month == 3)	_month_str		= "March";
			if (_month == 4)	_month_str		= "April";
			if (_month == 5)	_month_str		= "May";
			if (_month == 6)	_month_str		= "June";
			if (_month == 7)	_month_str		= "July";
			if (_month == 8)	_month_str		= "August";
			if (_month == 9)	_month_str		= "September";
			if (_month == 10)	_month_str		= "October";
			if (_month == 11)	_month_str		= "November";
			if (_month == 12)	_month_str		= "December";
		}

		void PrintFormatMonthFirstWithOnlyDigit(int& _day, int& _month, int& _year)
		{
			cout << _month << "/" << _day << "/" << _year << endl;
		}

		void PrintDateFormatMonthFirstWithAlphabetic(int& _day, string& _month_str, int& _year)
		{
			cout << _month_str << " " << _day << ", " << _year;
		}

		void PrintDateFormatMonthSecondWithAlphabetic(int& _day, string& _month_str, int& _year)
		{
			cout << _day << " " << _month_str << " " << _year;
		}
	};

	// 3
	class PayRoll
	{
	public:
		PayRoll(double profit_array[7][2] = { 0 })
		{
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					this->_profit_array[i][j] = profit_array[i][j];
				}
			}
		}

		void calculateGrossPay(double _array[][2], double _result[7])
		{
			for (int i = 0; i < 7; i++)
			{
				_result[i] = _array[i][0] * _array[i][1];
			}
		}

		void displayResult(double _array[], int _size)
		{
			for (int i = 0; i < _size; i++)
			{
				cout << _array[i] << " ";
			}
		}

	private:
		double _profit_array[7][2];
	};

	// 4
	class Heading
	{
	public:
		Heading(string _comp_name = "ABC Industries", string _report_name = "Report")
		{
			this->comp_name = _comp_name;
			this->report_name = _report_name;
		}

		string getCompName() const { return this->comp_name; }
		void setCompName(string& _str) { this->comp_name = _str; }

		string getReportName() const { return this->report_name; }
		void setReportName(string& _str) { this->report_name = _str; }

		void PrintSingleLine(string& _comp_name, string& _report_name)
		{
			cout << _comp_name << " " << _report_name << endl;
		}

		void PrintMultipleLines(string& _comp_name, string& _report_name)
		{
			cout << "*****************************" << endl;
			cout << setw(20) << _comp_name << endl;
			cout << setw(15) << _report_name << endl;
			cout << "*****************************" << endl;
		}

	private:
		string comp_name;
		string report_name;
	};

	// 5
	class Population
	{
	public:
		Population(double _population = 0, double _annual_number_of_birth = 0, double _annual_number_of_death = 0)
		{
			this->population				= _population;
			this->annual_number_of_birth	= _annual_number_of_birth;
			this->annual_number_of_death	= _annual_number_of_death;
		}

		// Birth Rate = Number of Births / Population 
		double getBirthRate(double _number_of_birth, double _population) { return _number_of_birth / _population; }
		// Death Rate = Number of Deaths / Population 
		double getDeathRate(double _number_of_death, double _population) { return _number_of_death / _population; }

		double	getBirth() const { return this->annual_number_of_birth; }
		void	setBirth(double val) { this->annual_number_of_birth = val; }

		double	getDeath() const { return this->annual_number_of_death; }
		void	setDeath(double val) { this->annual_number_of_death = val; }

		double	getPopulation() const { return this->population; }
		void	setPopulation(double val) { this->population = population; }

	private:
		double population;
		double annual_number_of_birth;
		double annual_number_of_death;
	};

	// 6
	class Inventory
	{
	public:
		Inventory()
		{
			this->itemNumber = 0;
			this->quantity = 0;
			this->cost = 0;
		}
		Inventory(int _itemNum, int _qty, double _cost)
		{
			this->itemNumber	= _itemNum;
			this->quantity		= _qty;
			this->cost			= _cost;
		}

		double getCost() const { return this->cost; }
		void setCost(double _cost) { this->cost = _cost; }

		int getItemNumber() const { return this->itemNumber; }
		void setItemNumber(int _number) { this->itemNumber = _number; }

		int getQuantity() const { return this->quantity; }
		void setQuantity(int _qty) { this->quantity = _qty; }

		double getTotalCost(int _quantity, double _cost)
		{
			double total = 0;
			for (int i = 0; i < _quantity; i++)
			{
				total += _cost;
			}
			return total;
		}

	private:
		int			itemNumber;
		int			quantity;
		double		cost;
	};

	namespace PracticalSession9 
	{
		/* 
		1. Write a class named Car that has the following member variables:
			> year. An int that holds the car’s model year.
			> make. A string object that holds the make of the car.
			> speed. An int that holds the car’s current speed.
		
		In addition, the class should have the following member functions.
			> Constructor. The constructor should accept the car’s year and make as arguments and assign
		these values to the object’s year and make member variables. The constructor should initialize the
		speed member variable to 0.
			> Accessors. Appropriate accessor functions should be created to allow values to be retrieved from
		an object’s year, make, and speed member variables.
			> accelerate. The accelerate function should add 5 to the speed member variable each time it
		is called.
			> brake. The brake function should subtract 5 from the speed member variable each time it is
		called.

		Demonstrate the class in a program that creates a Car object, and then calls the accelerate function
		five times. After each call to the accelerate function, get the current speed of the car, and display it.
		Then call the brake function five times. After each call to the brake function, get the current speed of
		the car and display it. 
		 */
		int q_1()
		{
			Car _car(3);

			int speed = 5;

			_car.setSpeed(speed);

			for (int i = 0; i < 5; i++) _car.accelerate();

			cout << "current speed (accelerate): " << _car.getSpeed() << endl;

			for (int i = 0; i < 5; i++) _car.brake();
				
			cout << "current speed (brake): " << _car.getSpeed() << endl;

			return 0;
		}

		/* 
		2. Design a class called Date that has integer data members to store month, day, and year. The class should
		have a three-parameter default constructor that allows the date to be set at the time a new Date object is
		created. If the user creates a Date object without passing any arguments, or if any of the values passed are
		invalid, the default values of 1, 1, 2001 (i.e., January 1, 2001) should be used. The class should have
		member functions to print the date in the following formats:
			> 3/15/20
			> March 15, 2020
			> 15 March 2020
		Demonstrate the class by writing a program that uses it. Be sure your program only accepts reasonable
		values for month and day. The month should be between 1 and 12. The day should be between 1 and the
		number of days in the selected month.
		 */
		int q_2()
		{
			int day, month, year;
			cout << "input the date (day, month, year):";
			cin >> day >> month >> year;

			if (year < 1) year = 2001;
			if (!q2_helper::ValidateMonthParam(month)) month = 1;
			if (!q2_helper::ValidateDateParam(day, month, year)) day = 1;

			Date _date(day, month, year);
			_date.PrintFormatMonthFirstWithOnlyDigit(day, month, year);

			string _converter;
			_date.MonthConverter(month, _converter);

			_date.PrintDateFormatMonthFirstWithAlphabetic(day, _converter, year);
			_date.PrintDateFormatMonthSecondWithAlphabetic(day, _converter, year);

			return 0;
		}

		/* 
		3. Design a PayRoll class that has data members for an employee’s hourly pay rate and number of hours
		worked. Write a program with an array of seven PayRoll objects. The program should read the hourly
		pay rate and their number of hours each employee worked from a file and call class functions to store this
		information in the appropriate objects. It should then call a class function, once for each object, to return
		the employee’s gross pay, so this information can be displayed.
		 */
		int q_3()
		{
			double _pay[7][2] = {
				{4.5, 6},
				{5.5, 7},
				{6.5, 8},
				{7.5, 9},
				{8.5, 10},
				{9.5, 11},
				{10.5, 12}
			};

			PayRoll _roll(_pay);

			double _result[7];
			_roll.calculateGrossPay(_pay, _result);
			
			_roll.displayResult(_result, 7);

			return 0;
		}

		/* 
		4. Design a class called Heading that has data members to hold the company name and the report name. A
		two-parameter default constructor should allow these to be specified at the time a new Heading object is
		created. If the user creates a Heading object without passing any arguments, “ABC Industries”
		should be used as a default value for the company name and “Report” should be used as a default for the
		report name. The class should have member functions to print a heading in either one-line format, as
		shown here:

								> Pet Pals Payroll Report

		Or in four-line “boxed” format, as shown here:

								> ****************************************
												> Pet Pals
											  > Payroll Report
								> ****************************************
		Try to figure out a way to center the headings on the screen, based on their lengths. Demonstrate the class
		by writing a simple program that uses it.
		 */
		int q_4()
		{
			string comp_name, report_name;
			cout << "input company name, report name: ";
			getline(cin, comp_name); getline(cin, report_name);

			if (comp_name.empty()) comp_name = "ABC Industries";
			if (report_name.empty()) report_name = "Report";

			Heading heading(comp_name, report_name);

			heading.setCompName(comp_name);
			heading.setReportName(report_name);

			heading.PrintSingleLine(comp_name, report_name);
			heading.PrintMultipleLines(comp_name, report_name);
			return 0;
		}

		/* 
		5. In a population, the birth rate and death rate are calculated as follows:
			> Birth Rate = Number of Births / Population
			> Death Rate = Number of Deaths / Population
		Design a Population class that stores a current population, annual number of births, and annual number
		of deaths for some geographic area. The class should allow these three values to be set in either of two
		ways:
			a) By passing arguments to a three-parameter constructor when a new Population object is created or
			b) By calling the setPopulation, setBirths, and setDeaths class member functions.
		In either case, if a population figure less than 2 is passed to the class, use a default value of 2. If a birth or
		death figure less than 0 is passed in, use a default value of 0. The class should also have getBirthRate
		and getDeathRate functions that compute and return the birth and death rates. Write a short program
		that uses the Population class and illustrates its capabilities
		 */
		int q_5()
		{
			double _population, _number_of_births, _number_of_deaths;
			cout << "input population, number of births, and number of deaths: ";
			cin >> _population >> _number_of_births >> _number_of_deaths;
			if (_population <= 2) 
				_population = 2;
			if (_number_of_births < 0) 
				_number_of_births = 0;
			if (_number_of_deaths < 0) 
				_number_of_deaths = 0;

			Population population(_population, _number_of_births, _number_of_deaths);

			population.setPopulation(_population);
			population.setBirth(_number_of_births);
			population.setDeath(_number_of_deaths);

			double _po = population.getPopulation();

			cout << "population: " << _po << endl;
			cout << "birth: " << population.getBirth() << endl;
			cout << "death: " << population.getDeath() << endl;
			cout << "birth rate: " << population.getBirthRate(_number_of_births, _population) << endl;
			cout << "death rate: " << population.getDeathRate(_number_of_deaths, _population) << endl;

			return 0;
		}

		/* 
		6. 
		Design an Inventory class that can hold information for an item in a retail store’s inventory. 
											Variables
		______________________________________________________________________________________________
		itemNumber 									An int that holds the item’s number.
		quantity 									An int that holds the quantity of the item on hand.
		cost 										A double that holds the wholesale per-unit cost of the item.
		______________________________________________________________________________________________
										Member Functions
		______________________________________________________________________________________________	
		default constructor 						Sets all the member variables to 0.
		constructor #2								Accepts an item’s number, quantity, and cost as argument. Calls other class
													functions to copy these values into the appropriate member variables. Then
													calls the setTotalCost function.
		setItemNumber 								Accepts an int argument and copies it into the itemNumber member variable.
		setQuantity 								Accepts an int argument and copies it into the quantity member variable.
		setCost 									Accepts a double argument and copies it into the cost member variable.
		getItemNumber 								Returns the value in itemNumber.
		getQuantity 								Returns the value in quantity.
		getCost 									Returns the value in cost.
		getTotalCost 								Computes and returns the totalCost.
		______________________________________________________________________________________________
		Demonstrate the class by writing a simple program that uses it. The program should validate inputs to
		ensure that negative values are not accepted.
		 */
		int q_6()
		{
			// I think it's easy to know how you can do it with empty overload (with .set classtype).
			// I won't write it here.
			int _item_num, _qty; double _cost;
			cout << "input the items number, qty and cost: ";
			cin >> _item_num >> _qty >> _cost;
			if (_item_num < 0 || _qty < 0 || _cost < 0)
			{
				cout << "\nall params must >= 0." << endl;
				return -1;
			}
			Inventory _inv(_item_num, _qty, _cost);

			int iItemNumGet = _inv.getItemNumber();
			cout << "item number what have get: " << iItemNumGet << endl;

			int iQtyGet = _inv.getQuantity();
			cout << "quantity what have get: " << iQtyGet << endl;

			double dCostGet = _inv.getCost();
			cout << "cost what have get: " << dCostGet << endl;

			double dCostTotal = _inv.getTotalCost(iItemNumGet, dCostGet);
			cout << "total cost: " << dCostTotal << endl;


			double dCostSet = 5; _inv.setCost(dCostSet);

			int iQtySet = 5; _inv.setQuantity(iQtySet);

			cout << "total cost(modified): " << _inv.getTotalCost(_inv.getQuantity(), _inv.getCost()) << endl;

			return 0;
		}
	}
}

#endif // !_SMS_PRACTICAL_S7ESSION_9_H_