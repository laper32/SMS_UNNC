#pragma once
#ifndef _SMS_PRACTICAL_SESSION_7_H_
#define _SMS_PRACTICAL_SESSION_7_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <string>
#include <fstream>

namespace SMS
{
	namespace q1_helper
	{
		template <typename T>
		int countPerfect(vector<T> &_array)
		{
			int counter = 0;
			for (int i = 0; i < _array.size(); i++)
			{
				if (_array[i] == 100) counter++;
			}

			return counter;
		}
	}

	namespace q3_helper
	{
		template <typename T>
		void winningDigits(vector<T> &_array)
		{
			vector<T> _generator_array;
			int lb = 1, ub = 9, range = ub - lb;
			auto generator = time(nullptr);
			srand((unsigned)generator);
			
			for (int i = 0; i < 5; i++)
			{
				unsigned number = rand() % range + 1;
				_generator_array.push_back(number);
			}

			_array = _generator_array;
		}
	}

	namespace q4_helper
	{
		template <typename T>
		T mode(vector<T>& _array, int vec_size)
		{
			// sort -> start at lowest.pos -> pass -> gonext->similar->return mode.
			sort(_array.begin(), _array.end());
			int index = 0, highest = 0;
			
			for (int i = 0; i < vec_size; i++)
			{
				int count = 1;
				int pos = _array.at(i);
				for (unsigned int j = i + 1; j < (unsigned)vec_size; j++)
				{
					if (_array.at(j) == pos) count++;
				}
				if (count >= index)
				{
					index = count;
					highest = pos;
				}
			}
			
			return highest;
		}
	}

	namespace q7_helper
	{
		double getData(ifstream& ifile, double _array[][30], int row)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					ifile >> _array[i][j];
				}
			}

			return 0;
		}

		double totalRainfall(double _array[][30], int row)
		{
			double total_sum = 0;
			for (int i = 0; i < row; i++)
				for (int j = 0; j < 30; j++)
					total_sum += _array[i][j];

			return total_sum;
		}

		double averageRainfall(double _array[][30], int row)
		{
			double total_fall = totalRainfall(_array, row);

			return total_fall / 12;
		}

		void driestMonth(double _array[12][30], double _result[2])
		{
			double count = 0;
			double driest = _array[0][0];
			double driest_result[2];
			for (int i = 0; i < 12; i++) 
			{
				for (int j = 0; j < 30; j++) 
				{
					if (_array[i][j] < driest) 
					{
						count = i;
						driest = _array[i][j];
					}
				}
			}
			driest_result[0] = count;
			driest_result[1] = driest;
			_result[0] = driest_result[0];
			_result[1] = driest_result[1];
		}

		void wettestMonth(double _array[12][30], double _result[2])
		{
			double count = 0;
			double wettest = _array[0][0];
			double wettest_result[2];
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					if (_array[i][j] > wettest)
					{
						count = i;
						wettest = _array[i][j];
					}
				}
			}
			wettest_result[0] = count;
			wettest_result[1] = wettest;
			_result[0] = wettest_result[0];
			_result[1] = wettest_result[1];
		}

		void displayReport(double total_rainfall, double avg_rainfall, double driest[2], double wettest[2])
		{
			cout << "total rainfall: " << total_rainfall << "\n"
				<< "avg rainfall: " << avg_rainfall << "\n"
				<< "driest on: " << driest[0] << ", the value:" << driest[1] 
				<< "wettest on: " << wettest[0] << ", the value: " << wettest[1]
				<< endl;
		}
	}

	namespace PracticalSession7
	{
		/*
		1. Write a modular program that accepts up to 20 integer test scores in the range of 0 to 100 from the user
		and stores them in an array. The main should report how many perfect scores were entered (i.e., scores of
		100), using a value-returning countPerfect function to help i.
		*/
		int q_1()
		{
			vector<double> _score_array; double score;
			while (true)
			{
				cout << "input the score: ";
				cin >> score;
				
				if (score < 0 || score > 100)
				{
					cout << "the range of score: [0, 100]" << endl;
					continue;
				}
				else
				{
					_score_array.push_back(score);
				}

				if (_score_array.size() == 20 || cin.get() == EOF) break;

			}

			int perfect = q1_helper::countPerfect(_score_array);

			cout << "you have " << perfect << " perfect scores." << endl;

			return 0;
		}

		/* 
		2. Write a program that displays the Roman numeral equivalent of any decimal number between 1 and 20
		that the user enters. The roman numerals should be stored in an array of strings and the decimal number
		that the user enters should be used to locate the array element holding the Roman numeral equivalent. The
		program should have a loop that allows the user to continue entering numbers until an end sentinel of 0 is
		entered
		 */
		int q_2()
		{
			vector<string> roman_numerals;

			roman_numerals.push_back("I");
			roman_numerals.push_back("II");
			roman_numerals.push_back("III");
			roman_numerals.push_back("IV");
			roman_numerals.push_back("V");
			roman_numerals.push_back("VI");
			roman_numerals.push_back("VII");
			roman_numerals.push_back("VII");
			roman_numerals.push_back("IX");
			roman_numerals.push_back("X");
			roman_numerals.push_back("XI");
			roman_numerals.push_back("XII");
			roman_numerals.push_back("XIII");
			roman_numerals.push_back("XIV");
			roman_numerals.push_back("XV");
			roman_numerals.push_back("XVI");
			roman_numerals.push_back("XVII");
			roman_numerals.push_back("XVIII");
			roman_numerals.push_back("XIX");
			roman_numerals.push_back("XX");

			auto _number = 0;
			while (cin.get() != EOF || cin.get() != 0)
			{
				cout << "input a decimal number (1-20)";
				cin >> _number;
				if (_number > 0 && _number <= roman_numerals.size()) {
					cout << "you have input: " << _number << ", related roman numerals: " << roman_numerals[static_cast<unsigned __int8>(_number) - 1] << "\n" << endl;
					continue;
				}
				else break;
				
				
				break;
			}

			return 0;
		}

		/* 
		3. Write a program that simulates a lottery. The program should have an array of 5 integers named
		winningDigits, with a randomly generated number in the range of 0 through 9 for each element in the
		array. The player should ask the user to enter 5 digits and should store them in a second integer array
		named player. The program must compare the corresponding elements in the two arrays and count how
		many digits’ match. For example, the following shows the winningDigits array and the player array
		with sample numbers stored in each. There are two matching digits, elements 2 and 4.
				> winningDigits				| 7 | 4 | 9 | 1 | 3 |
				> player					| 4 | 2 | 9 | 7 | 3 |
			Once the user has entered a set of numbers, the program should display the winning digits and the player’s
		digit and tell how many digits matched.

		 */
		int q_3()
		{
			vector<int> result_array;
			q3_helper::winningDigits(result_array);

			for (int i = 0; i < 5; i++)
				cout << result_array[i] << " ";
			cout << endl;

			vector<int> guess_array;
			int number;
			while (guess_array.size() < 5)
			{
				cout << "input a number: ";
				cin >> number;
				
				
				guess_array.push_back(number);
				//TOFIX: why cannot validate input?
				/*if (cin.get() > 9 && cin.get() < 1)
				{
					cout << "range: [1,9]\n" << endl;
					continue;
				}*/
			}

			for (unsigned int i = 0; i < guess_array.size(); i++)
			{
				cout << guess_array[i] << " ";
			}

			int counter = 0;
			for (unsigned int i = 0; i < guess_array.size(); i++)
			{
				if (result_array[i] == guess_array[i])
					counter++;
			}

			cout << "\ntotal: " << counter << " correct" << endl;

			return 0;
		}

		/* 
		4. In statistics the mode of a set of values is the value that occurs most often. Write a program that
		determines how many pieces of pie most people eat in a year. Set up an integer array that can hold
		responses from 15 people. For each person, enter the number of pieces they say they eat in a year. Then
		write a function that finds the mode of these 15 values. This will be the number of pie slices eaten by the
		most people. The function that finds and returns the mode should accept two arguments, an array of
		integers, and a value indicating how many elements are in the array.
		 */
		int q_4()
		{
			vector<int> _array; constexpr auto _array_SIZE = 15;
			auto value = 0;
			while (_array.size() < 15)
			{
				cout << "input the value: ";
				cin >> value;
				_array.push_back(value);
			}
			
			cout << "The highest is: " << q4_helper::mode(_array, _array_SIZE) << endl;

			return 0;
		}

		/* 
		5. A local zoo wants to keep track of how many pounds of food each of its three monkeys eats each day
		during a typical week. Write a program that stores this information in a two-dimensional 3×7 array, where
		each row represents a different monkey and each column represents a different day of the week. The
		program should first have the user input the data for each monkey. Then it should create a report that
		includes the following information:
			> Average amount of food eaten per day by the whole family of monkeys
			> The least amount of food eaten during the week by any one monkey.
			> The greatest amount of food eaten during the week by any one monkey.

		 */
		int q_5()
		{
			constexpr auto monkey_amount = 3, weekdays_count = 7;
			double monkey_info[monkey_amount][weekdays_count];
			for (int monkey = 0; monkey < monkey_amount; monkey++)
			{
				for (int weekday = 0; weekday < weekdays_count; weekday++)
				{
					cout << "the monkey: " << monkey + 1 << endl;
					cout << "I: weekday food: " << weekday + 1<< ": ";
					cin >> monkey_info[monkey][weekday];
				}
				cout << endl;
			}

			double sum_total = 0;
			for (int i = 0; i < monkey_amount; i++)
			{
				for (int j = 0; j < weekdays_count; j++)
				{
					sum_total += monkey_info[i][j];
				}
			}

			cout << "the avg amount of all monkey per day: " << sum_total / weekdays_count << endl;

			double highest = monkey_info[0][0];
			for (int i = 0; i < monkey_amount; i++)
			{
				for (int j = 0; j < weekdays_count; j++)
				{
					if (monkey_info[i][j] > highest)
						highest = monkey_info[i][j];
				}
			}
			cout << "the highest: " << highest << endl;

			double lowest = monkey_info[0][0];

			for (int i = 0; i < monkey_amount; i++)
			{
				for (int j = 0; j < weekdays_count; j++)
				{
					if (monkey_info[i][j] < lowest)
						lowest = monkey_info[i][j];
				}
			}
			cout << "the lowest: " << lowest << endl;

			return 0;
		}

		/* 
		6. An amateur meteorologist wants to keep track of weather conditions during the past year’s three-month
		summer season and has designated each day as either rainy (‘R’), cloudy (‘C”), or sunny (‘S’). Write a
		program that stores this information in a 3 × 30 array of characters, where the row indicates the month (0
		= June, 1 = July, 2 = August) and the column indicates the day of the month. Note that data is not being
		collected for the 31st of any month. The program should begin by reading the weather data in from a file.
		Then it should create a report that displays for each month and for the whole three-month period, how
		many days were rainy, how many were cloudy, and how many were sunny. It should also report which of
		the three months had the largest number of rainy days
		 */
		int q_6()
		{
			constexpr auto month_count = 3, day_count = 30;
			char weather_data[month_count][day_count];

			ifstream ifile;
			ifile.open("weather_debug.txt");
			
			for (int i = 0; i < month_count; i++)
			{
				for (int j = 0; j < day_count; j++)
				{
					ifile >> weather_data[i][j];
				}
			}ifile.close();
			
			int rainy_count = 0, sunny_count = 0, cloudy_count = 0;
			for (int i = 0; i < month_count; i++)
			{
				for (int j = 0; j < day_count; j++)
				{
					if (weather_data[i][j] == 'R') rainy_count++;
					if (weather_data[i][j] == 'S') sunny_count++;
					if (weather_data[i][j] == 'C') cloudy_count++;
				}
			}

			cout << "Totally has: " << rainy_count << " rainy days." << endl;
			cout << "Totally has: " << sunny_count << " sunny days." << endl;
			cout << "Totally has: " << cloudy_count << " cloudy days." << endl;

			int rainy_total_june = 0, rainy_total_july = 0, rainy_total_august = 0;
			for (int i = 0; i < day_count; i++)
			{
				if (weather_data[0][i] == 'R') rainy_total_june++;
				if (weather_data[1][i] == 'R') rainy_total_july++;
				if (weather_data[2][i] == 'R') rainy_total_august++;
			}
			
			int highest_month;
			int arr_highest[3] = { rainy_total_june, rainy_total_july, rainy_total_august };
			highest_month = arr_highest[0];
			for (int i = 0; i < 3; i++)
			{
				if (arr_highest[i] > highest_month)
				{
					highest_month = arr_highest[i];
				}
			}

			string _most_rainy_month; 
			if (highest_month == rainy_total_june) _most_rainy_month = "june";
			else if (highest_month == rainy_total_july) _most_rainy_month = "july";
			else if (highest_month == rainy_total_august) _most_rainy_month = "august";
			cout << "the most rainy month: " << _most_rainy_month << " has: " << highest_month << "days." << endl;

			return 0;
		}

		/* 
		7. Write a modular program that analyzes a year’s worth of rainfall data. In addition to main, the program
		should have a getData function that accepts the total rainfall for each of 12 months from the user and
		stores it in a double array. It should also have four value-returning functions that compute and return to
		main the totalRainfall, averageRainfall, driestMonth, and wettestMonth. These last two
		functions return the number of the month with the lowest and highest rainfall amounts, not the amount of
		rain that fell those months. Notice that this month number can be used to obtain the amount of rain that
		fell those months. This information should be used either by main or by a displayReport function
		called by main to print a summary rainfall report similar to the following:

			> 2020 Rain Report for China

			> Total rainfall: 23.19 inches
			> Average monthly rainfall: 1.93 inches
			> The least rain fell in January with 0.24 inches.
			> The most rain fell in April with 4.29 inches.
		 */
		int q_7()
		{
			string _filename;
			cout << " input the filename: ";
			while (getline(cin, _filename))
			{
				if (_filename.empty())
				{
					cout << "file name is empty.\n" << endl;
					continue;
				}

				ifstream ifile;
				ifile.open(_filename);
				if (ifile.fail())
				{
					cout << "unable to open the file. file not found: " + _filename + "\n";
					continue;
				}
				else {
					constexpr auto month_of_the_year = 12, day_of_the_month = 30;
					double _weather_data[month_of_the_year][day_of_the_month];
					q7_helper::getData(ifile, _weather_data, month_of_the_year);
					
					double total_rainfall = q7_helper::totalRainfall(_weather_data, month_of_the_year);
					double avg_rainfall = q7_helper::averageRainfall(_weather_data, month_of_the_year);
					double driest_data[2], wettest_data[2];
					q7_helper::driestMonth(_weather_data, driest_data);
					q7_helper::wettestMonth(_weather_data, wettest_data);

					//cout << "driest: " << driest_data[0] << " " << driest_data[1];

					q7_helper::displayReport(total_rainfall, avg_rainfall, driest_data, wettest_data);
					
					return 0;
				}

				
			}
			
			

			return 0;
		}
	}
} // namespace SMS


#endif // !_SMS_PRACTICAL_SESSION_7_H_