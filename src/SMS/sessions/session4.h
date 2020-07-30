#pragma once
#ifndef _SMS_PRACTICAL_SESSION_4_H_
#define _SMS_PRACTICAL_SESSION_4_H_

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
	namespace PracticalSession4
	{
		/*
		1. Write a program that uses a loop to display the characters for each ASCII code 32 through 127. Display 16
		characters on each line with one space between characters.
		*/
		int q_1()
		{
			for (int i = 32; i <= 127; i++)
			{
				cout << (char)i << " ";
				if (i % 16 == 0) cout << "\n";
			}

			return 0;
		}

		/*
		2. Write a program that asks the user for a positive integer value and that uses a loop to validate the input.
		The program should then use a second loop to compute the sum of all the integers from 1 up to the number
		entered. For example, if the user enters 50, the loop will find the sum of 1, 2, 3, 4, … 50
		*/
		int q_2()
		{
			int value, sum = 0;
			cout << "input an positive int" << endl;
			cin >> value;
			if (value <= 0) cout << "must be an positive integer" << endl;
			else
			{
				for (int i = 1; i <= value; i++)
				{
					sum += i;
				}
				cout << "value what have input: " << value << ", the sum: " << sum << endl;
			}
			return 0;
		}

		/*
		3. The distance a vehicle and travels can be calculated as follows:

			> distance = speed * time

			Write a program that asks the user for the speed of vehicle (in miles per hour) and how many hours it has
		traveled. It should then use a loop to display the total distance traveled at the end of each hour of that time
		period.

			> Enter the speed of the vehicle in mph: 40
			> Enter the hours it traveled: 3
					Hour			|			Miles Traveled
			----------------------------------------------------------
					1								40
					2								80
					3								120
		*/
		int q_3()
		{
			double distance, speed; unsigned int hour;
			cout << "input the speed of vehicle: " << endl;
			cin >> speed;
			if (speed < 0.0) {
				cout << "speed must >= 0" << endl;
				return -1;
			}
			cout << "input how many hours it has traveled: " << endl;
			cin >> hour;
			if (hour < 0) {
				cout << "hour must >= 0" << endl;
				return -1;
			}

			cout << "Miles					Traveled" << endl;
			for (unsigned int i = 0; i <= hour; i++)
			{
				distance = i * speed;
				cout << i << "							" << distance << endl;
			}

			return 0;
		}

		/*
		4. Write a program that displays a table of speeds in kilometers per hour with their values converted to miles
		per hour.
			The table should display the speeds from 60 kilometers per hour through 130 kilometers perhour, in increments of 5
		kilometers per hour. (In other words, it should display 60 kph, 65 kph, 70 kph and so forth, up through 130 kph.)

			> MPH = KPH * 0.6214
		*/
		int q_4()
		{
			double mph;

			cout <<
				"Convert: \
				\nMph				Kph"
				<< endl;
			for (unsigned int kph = 60; kph <= 130; kph += 5)
			{
				mph = double(kph) * 0.6214;
				cout << mph << "				" << kph << endl;
			}

			return 0;
		}

		/*
		5. Running on a particular treadmill you burn 3.9 calories per minute. Write a program that uses a loop to
		display the number of calories burned after 10, 15, 20, 25, 30 minutes.
		*/
		int q_5()
		{
			constexpr auto _calories_burned_ = 3.9;

			double calories;

			cout << "Calories burned: \
					\nCalories					Minutes" << endl;
			for (unsigned int minutes = 10; minutes <= 30; minutes += 5)
			{
				calories = (double)minutes * _calories_burned_;
				cout << calories << "						" << minutes << endl;
			}

			return 0;
		}

		/*
		6. Write a program that generates a random number between 1 and 100 and asks the user to guess what the
		number is. If the user’s guess is higher than the random number, the program should display “Too high.
		Try again!”. If the user’s guess is lower than the random number, the program should display “Too low.
		Try again!”. The program should use a loop that repeats until the user correctly guesses the random
		number. Then the program should display “Congratulations. You figured out my number!”.

			Expansion: The program keeps a count of the number of guesses the user makes. When the user correctly
		guesses the random number, the program should display the number of guesses along with the message of
		congratulations.
		*/
		int q_6()
		{
			int lb = 1, ub = 100, range = ub - lb, tried = 0;
			auto generator = time(nullptr);
			srand((unsigned)generator);
			unsigned number = rand() % range + 1;
			cout << number << endl;
			unsigned guess = 0;
			cout << "input a value to guess." << endl;

			while (guess != number)
			{
				cin >> guess;

				if (cin.get() == -1) break;

				if (number > guess)
				{
					cout << "Too low. Try again!" << endl;
					tried++;
				}
				else if (number < guess)
				{
					cout << "Too high. Try again!" << endl;
					tried++;
				}
				else
				{
					cout << "Congratulations. You figured out my number!\n" << endl;
					tried++;
					cout << "and you have tried " << tried << " times" << endl;
				}
			}
			return 0;
		}

		/*
		7. Write a program with a loop that lets the user enter a series of integers, followed by -99 to signal the end
		of series. After all the numbers have been entered, the program should display the largest and smallest
		numbers entered.
		*/
		int q_7()
		{
			vector<int> array;
			int num;
			cout << "input array: " << endl;
			while (true)
			{
				cin >> num;
				array.push_back(num);
				if (cin.get() == '\n' || cin.get() == -99) break;
			}

			for (unsigned int i = 0; i < array.size(); i++)
			{
				cout << array[i];
			}

			int max_ = *max_element(array.begin(), array.end());
			int min_ = *min_element(array.begin(), array.end());

			cout << "max elemnt: " << max_ << "\nmin element: " << min_ << endl;

			return 0;
		}

		/*
		8. Write a program that asks the user to enter today’s sales rounded to the nearest $100 for each of three
		stores. The program should then display a bar graph comparing each store’s sales. Create each bar in the
		graph by displaying a row of asterisks. Each asterisk should represent $100 of sales. Here is an example of
		the program’s output

			> Enter today's sales for store 1: 1000
			> Enter today's sales for store 2: 1200
			> Enter today's sales for store 3: 800

				> DAILY SALES
			  > (each * = $100)
			> store 1: **********
			> store 2: ************
			> store 3: ********
		*/
		int q_8()
		{
			//note: vector is unnecessary...
			int sales_store1, sales_store2, sales_store3;

			cout << "input today's sales for store 1:" << endl;
			cin >> sales_store1;

			cout << "input today's sales for store 2:" << endl;
			cin >> sales_store2;

			cout << "input today's sales for store 3:" << endl;
			cin >> sales_store3;

			cout << "	  DAILY SALES\n";
			cout << "	(each * = $100)\n";
			cout << "store 1: ";
			for (int i = 1; i <= sales_store1 / 100; i++)
			{
				cout << "*";
			} cout << "\n";

			cout << "store 2: ";
			for (int i = 1; i <= sales_store2 / 100; i++)
			{
				cout << "*";
			} cout << "\n";

			cout << "store 3: ";
			for (int i = 1; i <= sales_store3 / 100; i++)
			{
				cout << "*";
			} cout << "\n";

			return 0;
		}

		/*
		9. Write a program that calculates the balance of a savings account at the end of a three-month period. It
		should ask the user for the starting balance and the annual interest rate. A loop should then iterate once for
		every month in the period, performing the following steps:
			a) Ask the user for the total amount deposited into the account during that month and add it to the
		balance. Do not accept negative numbers.
			b) Ask the user for the total amount withdrawn from the account during that month and subtract it from
		the balance. Do not accept negative numbers or numbers greater than the balance after the deposits for
		the month have been added in.
			c) Calculate the interest for that month. The monthly interest rate is the annual interest rate divided by 12.
		Multiply the monthly interest rate by the average of that month’s starting and ending balance to get the
		interest amount for the month. This amount should be added to the balance.

		After the last iteration, the program should display a report that includes the following information:
			• Starting balance at the beginning of the three-month period,
			• Total deposits made during the three months,
			• Total withdraws made during the three months,
			• Total interest posted to the account during the three months,
			• Final balance.
		*/
		int q_9()
		{
			double
				starting_balance,
				annual_interest_rate, monthly_interest_rate,
				deposit_sum = 0, ideposit,
				withdraw_sum = 0, iwithdraw,
				current_balance = 0, interest, interest_sum = 0,
				final_balance = 0;

			cout << "input starting balance" << endl;
			cin >> starting_balance;

			cout << "input annual interest rate" << endl;
			cin >> annual_interest_rate;

			monthly_interest_rate = annual_interest_rate / 12;

			int month = 1;

			while (month <= 3)
			{
				cout << "input deposit" << endl;
				cin >> ideposit;
				if (ideposit < 0.0)
				{
					cout << "only accept >= 0" << endl;
				}
				else {
					deposit_sum += ideposit;

					current_balance = starting_balance + ideposit;
				}

				cout << "input withdraw" << endl;
				cin >> iwithdraw;
				if (iwithdraw < 0.0)
				{
					cout << "only accept >=0" << endl;
				}
				else if (iwithdraw > (starting_balance + deposit_sum))
				{
					cout << "reject when withdraw > starting balance + deposit sum" << endl;
				}
				else
				{
					withdraw_sum += iwithdraw;

					current_balance -= iwithdraw;
				}

				interest = current_balance * monthly_interest_rate;

				interest_sum += interest;

				current_balance += interest;

				month++;
			}

			final_balance = current_balance;

			cout << "starting balance: " << starting_balance << " \n " <<
				"total deposit: " << deposit_sum << " \n " <<
				"total withdraw: " << withdraw_sum << " \n " <<
				"total interest: " << interest_sum << " \n " <<
				"final balance: " << final_balance << " \n " <<
				endl;

			return 0;
		}

		/*
		10. Write a program that uses nested loops to display the diamond pattern shown below.
			+
		   +++
		  +++++
		 +++++++
		  +++++
		   +++
			+
		*/
		// https://www.cnblogs.com/kysnail/archive/2010/08/10/PrintLozenge.html?spm=a2c6h.12873639.0.0.7917801ejwhfz8
		int q_10()
		{
			// solution 3
			int row, col, count = 3;

			for (row = -count; row <= count; row++) 
			{
				for (col = -count; col <= count; col++)
				{
					(abs(row) + abs(col) <= count) ? cout << "+" : cout << " ";
				} 
				cout << "\n";
			}

			return 0;
		}
	}
}

#endif // !_SMS_PRACTICAL_SESSION_4_H_