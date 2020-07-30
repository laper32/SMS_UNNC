#pragma once
#ifndef _SMS_PRACTICAL_SESSION_5_H_
#define _SMS_PRACTICAL_SESSION_5_H_

#include <stdio.h> 
#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

namespace SMS
{
	// 1
	inline double calcRetil(double _wholesale_cost, double markup_percentage)
	{
		double retail_price = 0;
		retail_price = _wholesale_cost * (1.f + (markup_percentage / 100));

		return retail_price;
	}

	// 2
	inline double Celsius(double f)
	{
		//f = 5 / 9 (f – 32);
		return ( 5 *( f - 32 ) ) / 9;
	}

	// 3
	// @param _mass			Mass of object, masured in kilogram.
	// @param _vel			Velocity of object, masured in m/s
	inline double kineticEnergy(double _mass, double _vel)
	{
		// (mv^2)/2
		return (0.5 * _mass * pow(_vel, 2));
	}

	// 4
	inline bool isPrime(int val)
	{
		// how to get whether is prime.
		// eg: if a num is 18.
		// divide by 2 is 9, then for loop to test whether its mod is 0
		// if is 0, absolute is not prime; if not 0, OK, it's prime.
		bool isprime = true;

		for (int i = 2; i <= val / 2; i++)
		{
			if (val % i == 0)
			{
				isprime = false;
				break;
			}
		}
		return isprime;
	}

	// 5
	// @param _time			falling time, measured in second.
	inline double fallingDistance(double _time)
	{
		double g = 9.8; // gravity acceleration
		return 0.5 * g * pow(_time, 2);
	}

	// 6
	void pendingStatusOrder(int &_spools_ordered, int &_spools_in_stock, int &_special_handling_charges)
	{
		cout << "current ordered spools: " << _spools_ordered << endl;
		cout << "current spools in stock: " << _spools_in_stock << endl;
		cout << "Any special shipping and handling charges (above the regular $10 rate): " << _special_handling_charges << endl;
	}
	// 6
	void dispathPending(int &_spools_ordered, int &_spools_in_stock, int &_special_handling_charges)
	{
		int backorder_count = _spools_in_stock - _spools_ordered;

		cout << "ordered spools ready to ship from current stock: " << _spools_in_stock << endl;

		if (abs(backorder_count) > 0)
			cout << "there are " << abs(backorder_count) << " in backorder" << endl;
		
		int successful_ordered;

		if (abs(backorder_count) <= 0) successful_ordered = _spools_ordered;
		else successful_ordered = _spools_ordered - abs(backorder_count);

		int _spool_price = 100;
		int _spool_total_price = _spool_price * successful_ordered;
		cout << "total selling price: " << _spool_total_price << endl;

		int _handling_price = _special_handling_charges * successful_ordered;
		cout << "total charges for spools ready to ship: " << _handling_price << endl;

		cout << "total price ready for shipping: " << _handling_price + _spool_total_price << endl;
	}

	// 7
	void getScore(double& score, vector<double>& score_array)
	{
		cout << "input the score: " << endl;
		while (true)
		{
			cin >> score;
			if (score < 0 || score > 100) {
				cout << "value " << score << " must in the range of [0, 100]" << endl;
				continue;
			}
			else score_array.push_back(score);

			if (cin.get() == EOF || score_array.size() == 5) break;
		}
	}
	// 7
	void findLowest(vector<double>& score_array)
	{
		double _min = *min_element(score_array.begin(), score_array.end());
		cout << "the lowest score is: " << _min << endl;
	}
	// 7
	void calcAverage(vector<double>& score_array)
	{
		double sum = 0;
		for (unsigned int i = 0; i < score_array.size(); i++)
		{
			sum += score_array[i];
		}
		cout << "sum is: " << sum << endl;
		cout << "avg: " << sum / score_array.size() << endl;

		findLowest(score_array);
	}

	// 8
	void getJudgeData(double& score, vector<double>& judge_array)
	{
		cout << "input the score: " << endl;
		while (true)
		{
			cin >> score;
			if (score < 0 || score > 10) {
				cout << "value " << score << " must in the range of [0, 10]" << endl;
				continue;
			}
			else judge_array.push_back(score);

			if (cin.get() == EOF || judge_array.size() == 5) break;
		}
	}
	// 8
	double findHighest(vector<double>& judge_array)
	{
		return *max_element(judge_array.begin(), judge_array.end());
	}
	// 8
	double findLowest2(vector<double>& judge_array)
	{
		return *min_element(judge_array.begin(), judge_array.end());
	}
	// 8
	void calcScore(vector<double>& judge_array)
	{
		sort(judge_array.begin(), judge_array.end());

		double max_ = findHighest(judge_array);
		double min_ = findLowest2(judge_array);

		constexpr auto _REMOVE_VAL = -1;

		for (unsigned int i = 0; i < judge_array.size(); i++)
		{
			if (judge_array[i] == max_ || judge_array[i] == min_) judge_array[i] = _REMOVE_VAL;
		}

		judge_array.erase(remove(judge_array.begin(), judge_array.end(), _REMOVE_VAL), judge_array.end());

		double sum = 0;

		for (unsigned int i = 0; i < judge_array.size(); i++)
		{
			sum += judge_array[i];
		}

		double avg = sum / judge_array.size();
		cout << "the trimmed avg score is: " << avg << endl;
	}

	namespace PracticalSession5
	{
		/*
		1. Write a program that asks the user to enter an item’s wholesale cost and its markup percentage. It should
		then display the item’s retail price. For example:

			• If an item’s wholesale cost is 5.00 and its markup percentage is 100%, then the item’s retail price is
		10.00.
			• If an item’s wholesale cost is 5.00 and its markup percentage is 50%, then the item’s retail price is 7.50.

			The program should have a function named calcRetail that receives the wholesale cost and the markup
		percentage as arguments and returns the retail price of the item.
		*/
		int q_1()
		{
			double _wholesale_cost, markup_percentage;
			cout << "input wholesale cost: " << endl; cin >> _wholesale_cost;
			cout << "markup percentage: " << endl; cin >> markup_percentage;
			
			double _result = calcRetil(_wholesale_cost, markup_percentage);

			cout << "retail price: " << _result << endl;

			return 0;
		}

		/*
		2. The following for converting a temperature from Fahrenheit to Celsius is
			> C = 5 / 9 (F – 32)

		Where F is the Fahrenheit temperature and C is the Celsius temperature. Write a function named Celsius
		that accepts a Fahrenheit temperature as an argument. The function should return the temperature,
		converted to Celsius. Demonstrate the function by calling it in a loop that displays a table of the
		Fahrenheit temperatures 0 through 20 and their Celsius equivalents.
		*/
		int q_2()
		{
			double fahrenheit;
			cout << "input fahrenheit: " << endl; cin >> fahrenheit;

			cout << "fahrenheit -> celsius: " << Celsius(fahrenheit) << endl;
			return 0;
		}

		/*
		3. In physics, an object that is in motion is said to have kinetic energy. The following formula can be used to
		determine a moving object’s kinetic energy:

				> KE = 0.5 *  mv^2

			KE is the kinetic energy in joules, m is the object’s mass in kilograms, and v is the object’s velocity in
		meters per second.
			Write a function named kineticEnergy that accepts an object’s mass (in kilograms) and velocity (in
		meters per second) as arguments. The function should return the amount of kinetic energy that the object
		has. Demonstrate the function by calling it in a program that asks the user to enter values for mass and
		velocity.
		*/
		int q_3()
		{
			double _mass, velocity;
			cout << "input mass (measured in kilogram): " << endl; cin >> _mass;
			cout << "input velocity (measured in m/s): " << endl; cin >> velocity;

			cout << "kinetic energy: " << kineticEnergy(_mass, velocity) << endl;

			return 0;
		}

		/*
		4. Write a function name isPrime, which takes an integer as an argument and returns 1 if the argument is a
		prime number, and 0 otherwise. Demonstrate the function in a complete program.
		*/
		int q_4()
		{
			int num;

			cout << "input a num: " << endl; cin >> num;

			if (num <= 0)
			{
				cout << "must > 0" << endl;
				return -1;
			}

			cout << "val" << "				" << "Prime status" << endl;
			for (int i = 2; i <= num; i++)
			{
				if (isPrime(i)) cout << i << "					" << "Y" << endl;
				else cout << i << "					" << "N" << endl;
			}

			return 0;
		}

		/*
		5. The following formula can be used to determine the distance an object falls due to gravity in a specific
		time period:
				> d = 0.5 * gt^2
		The variables in the formula are as follows:
			d is distance in meters
			g is 9.8 m/s2
			t is time in seconds that the object has been falling.

			Write a function named fallingDistance that accepts an object’s falling time (in seconds) as an
		argument. The function should return the distance, in meters, that the object has fallen during that time
		interval. Write a program that demonstrates the function by calling it in a loop that passes the values 1
		through 10 as arguments and displays the return value.
		*/
		int q_5()
		{
			double t;
			cout << "input falling time:" << endl; cin >> t;
			cout << "falling distance: " << fallingDistance(t) << endl;
			return 0;
		}

		/*
		6. The Middletown Wholesale Copper Wire Company sells spools of copper wiring for $100 each and ships
		them for $10 apiece. Write a program that displays the status of an order. It should use two functions. The
		first function asks for the following data and stores the input values in reference parameters.
			• The number of spools ordered.
			• The number of spools in stock.
			• Any special shipping and handling charges (above the regular $10 rate).

		The second function receives as arguments any values needed to compute and display the following
		information:
			• The number of ordered spools ready to ship from current stock.
			• The number of ordered spools on backorder (if the number ordered is greater than what is in stock).
			• Total selling price of the portion ready to ship (the number of spools ready to ship times $100).
			• Total shipping and handling charges on the portion ready to ship.
			• Total price of the order ready to ship.
		The shipping and handling parameter in the second function should have the default argument 10.00.
		 */
		int q_6()
		{
			int _spools_ordered, _spools_in_stock, _special_handling_charges = 10;

			cout << "I: spools ordered: " << endl; cin >> _spools_ordered;
			cout << "I: spools in stock" << endl; cin >> _spools_in_stock;
			cout << "I: special handling charges" << endl; cin >> _special_handling_charges;

			pendingStatusOrder(_spools_ordered, _spools_in_stock, _special_handling_charges);

			dispathPending(_spools_ordered, _spools_in_stock, _special_handling_charges);
			return 0;
		}

		/*
		7. Write a program that calculates the average of a group of test scores, where the lowest score in the group
		is dropped. It should use the following functions:
			• void getScore() should ask the user for a test score, store it in a reference parameter variable,
		and validate that it is not lower than 0 or higher than 100. This function should be called by main
		once for each of the five scores to be entered.
			• void calcAverage() should calculate and display the average of the four highest scores. This
		function should be called just once by main and should be passed the five scores.
		int findLowest() should find and return the lowest of the five scores passed to it. It should be called
		by calcAverage, which uses the function to determine which one of the five scores to drop.
		 */
		int q_7()
		{
			vector<double> score_array; double score = 0;

			getScore(score, score_array);

			calcAverage(score_array);

			return 0;
		}

		/*
		8. A particular talent competition has 5 judges, each of whom awards a score between 0 and 10 to each
		performer. Fractional scores, such as 8.3, are allowed. A performer’s final score is determined by
		dropping the highest and lowest score received, then averaging the 3 remaining scores. Write a program
		that uses these rules to calculate and display a contestant’s score. It should include the following
		functions:
			• void getJudgeData() should ask the user for a judge’s score, store it in a reference parameter
		variable, and validate it. This function should be called by main once for each of the 5 judges.
			• double calcScore() should calculate and return the average of the 3 scores that remain after
		dropping the highest and lowest scores the performer received. This function should be called just
		once by main and should be passed the 5 scores.
		Two additional functions, described below, should be called by calcScore, which uses the returned
		information to determine which of the scores to drop.
			• double findLowest() should find and return the lowest of the 5 scores passed to it.
			• double findHighest() should find and return the highest of the 5 scores passed to it.
		 */
		int q_8()
		{
			vector<double> judge_array; double score;
			getJudgeData(score, judge_array);

			calcScore(judge_array);
			return 0;
		}
	}
}

#endif // !_SMS_PRACTICAL_SESSION_5_H_