#pragma once
#ifndef _SMS_PRACTICAL_SESSION_8_H_
#define _SMS_PRACTICAL_SESSION_8_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

namespace SMS
{
	namespace q1_helper
	{
		template <typename T>
		void rand_array(vector<T>& _array, int size)
		{
			vector<T> _generator_array;
			int lb = 1, ub = 100, range = ub - lb;
			auto generator = time(nullptr);
			srand((unsigned)generator);

			for (int i = 0; i < size; i++)
			{
				unsigned number = rand() % range + 1;
				_generator_array.push_back(number);
			}

			_array = _generator_array;
		}

		// https://www.cnblogs.com/jasenkin/p/median_calculator.html
		template <typename T>
		double median(vector<T>& _array)
		{
			sort(_array.begin(), _array.end());
			if (_array.empty()) return (double)NAN;
			size_t _endIndex = _array.size() / 2;

			for (unsigned int i = 0; i < _endIndex; i++)
			{
				for (unsigned int j = 0; j < _endIndex - 1 - i; j++)
				{
					if (_array[static_cast<unsigned __int8>(j) + 1] < _array[j])
					{
						T _temp = _array[static_cast<unsigned __int8>(j) + 1];
						_array[static_cast<unsigned __int8>(j) + 1] = _array[j];
						_array[j] = _temp;
					}
				}
			}

			double _result = 0;

			if (_array.size() % 2 != 0) _result = _array[_endIndex];
			else {
				double _temp = 0;
				_temp = (_array[_endIndex - 1] + _array[_endIndex]) / 2;
				//_temp = static_cast<unsigned __int8>((_array[_endIndex - 1] + _array[_endIndex])) / 2;
				_result = double(_temp);
			}

			return _result;
		}
	}

	namespace q2_helper
	{
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

				if (cin.get() == EOF) break;
			}
		}

		void calcAverage(vector<double>& score_array)
		{
			double sum = 0;
			for (unsigned int i = 0; i < score_array.size(); i++)
			{
				sum += score_array[i];
			}
			cout << "sum is: " << sum << endl;
			cout << "avg: " << sum / score_array.size() << endl;

		}
	}

	namespace q3_helper 
	{
		template <typename T>
		double avg(vector<T>& _array)
		{
			double total_sum = 0;
			for (int i = 0; i < _array.size(); i++)
			{
				total_sum += _array[i];
			}

			return total_sum / _array.size();
		}

		template <typename T>
		double median(vector<T>& _array)
		{
			sort(_array.begin(), _array.end());
			if (_array.empty()) return (double)NAN;
			size_t _endIndex = _array.size() / 2;

			for (unsigned int i = 0; i < _endIndex; i++)
			{
				for (unsigned int j = 0; j < _endIndex - 1 - i; j++)
				{
					if (_array[static_cast<unsigned __int8>(j) + 1] < _array[j])
					{
						T _temp = _array[static_cast<unsigned __int8>(j) + 1];
						_array[static_cast<unsigned __int8>(j) + 1] = _array[j];
						_array[j] = _temp;
					}
				}
			}

			double _result = 0;

			if (_array.size() % 2 != 0) _result = _array[_endIndex];
			else _result = static_cast<unsigned __int8>((_array[_endIndex - 1] + _array[_endIndex])) / 2;

			return _result;
		}

		template <typename T>
		T mode(vector<T>& _array)
		{
			// sort -> start at lowest.pos -> pass -> gonext->similar->return mode.
			sort(_array.begin(), _array.end());
			int index = 0, highest = 0;

			for (unsigned int i = 0; i < _array.size(); i++)
			{
				int count = 1;
				int pos = _array.at(i);
				for (unsigned int j = i + 1; j < _array.size(); j++)
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

	namespace q5_helper
	{
		int getNumberOfDays(int month, int year)
		{
			if (month == 2)
			{
				if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) return 29;
				else return 28;
			}
			else
			{
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
				else return 30;
			}
		}
	}

	namespace PracticalSession8
	{
		/*
		1. In statistics the median of a set of values is the value that lies in the middle when the values are arranged
		in sorted order. If the set has an even number of values, then the median is taken to be the average of the
		two middle values. Write a function that determines the median of a sorted array. The function should take
		an array of numbers and an integer indicating the size of the array and return the median of the values in
		the array. You may assume the array is already sorted. Use pointer notation whenever possible.
		*/
		int q_1()
		{
			vector <double> _array; constexpr auto size = 10;
			q1_helper::rand_array(_array, size);

			cout << "the array generated: ";
			for (int i = 0; i < _array.size(); i++)
			{
				cout << _array[i] << " ";
			}cout << endl;

			cout << "the array sorted: ";
			sort(_array.begin(), _array.end());
			for (int i = 0; i < _array.size(); i++)
			{
				cout << _array[i] << " ";
			}cout << endl;

			double median_result = q1_helper::median(_array);
			cout << "median: " << median_result << endl;

			return 0;
		}

		/*
		2. Write a program that dynamically allocates an array large enough to hold a user-defined number of test
		scores. Once all the scores are entered, the array should be passed to a function that sorts them in
		ascending order. Another function should be called that calculates the average score. The program should
		display the sorted list of scores and averages with appropriate headings. Use pointer notation rather than
		array notation whenever possible. (Do not accept negative numbers for test scores.)
		*/
		int q_2()
		{
			// enter->sort(asc)->sorted.list.display->calculate.avg
			vector<double> score_array; double score = 0;

			q2_helper::getScore(score, score_array);

			cout << "the score list: ";
			for (int i = 0; i < score_array.size(); i++)
			{
				cout << score_array[i] << " ";
			}
			sort(score_array.begin(), score_array.end());
			cout << endl;
			cout << "sorted score list: ";
			for (int i = 0; i < score_array.size(); i++)
			{
				cout << score_array[i] << " ";
			}
			cout << endl;

			q2_helper::calcAverage(score_array);
			return 0;
		}

		/*
		3. Write a program that can be used to gather statistical data about the number of movies college students see
		in a month. The program should ask the user how many students were surveyed and dynamically allocate
		an array of that size. The program should then allow the user to enter the number of movies each student
		has seen. The program should then calculate the average, median, and mode of the values entered.
		*/
		int q_3()
		{
			vector<int> _student_movie_data;
			int dim;
			cout << "input how many students: ";
			cin >> dim;

			if (dim <= 0)
			{
				cout << "invalid dim index: " + dim;
			}
			else
			{
				for (int i = 0; i < dim; i++)
				{
					int value;
					cout << "input value: ";
					cin >> value;
					if (value < 0)
					{
						cout << "invalid value: " + value;
						continue;
					}
					_student_movie_data.push_back(value);
				}

				for (int i = 0; i < _student_movie_data.size(); i++)
				{
					cout << _student_movie_data[i] << " ";
				} cout << endl;

				sort(_student_movie_data.begin(), _student_movie_data.end());
				for (int i = 0; i < _student_movie_data.size(); i++)
				{
					cout << _student_movie_data[i] << " ";
				} cout << endl;
				
				double avg_result = q3_helper::avg(_student_movie_data);
				double mode_result = q3_helper::mode(_student_movie_data);
				double median_result = q3_helper::median(_student_movie_data);
				cout << "avg: " << avg_result << endl;
				cout << "mode: " << mode_result << endl;
				cout << "median: " << median_result << endl;
			}

			return 0;
		}

		/*
		4. Write a program that asks for the user's name and year of birth, greets the user by name, and declares the user's age
		in years. Users are assumed to be born between the years 1800 and 2099 and should enter the year of birth in one of
		three formats 18XX, 19XX, or 20XX. A typical output should be "Hello Caroline, you are 23 years old.".
		*/
		int q_4()
		{
			vector<string> _info;
			int year;
			string _name;
			cout << "input year: ";
			cin >> year;
			if (year < 1800 && year < 2099)
				cout << "nope. range in [1800, 2099]\n" << endl;
			else
			{
				int age = 2020 - year;
				string s = to_string(age);
				_info.push_back(s);
			}

			cout << "input name: ";
			cin >> _name;
			_info.push_back(_name);

			cout << "Hello " + _info[1] + ", you are " + _info[0] + " years old." << endl;

			return 0;
		}

		/*
		5. Write a program that can determine the number of days in a month for a specified month and year. The program
		should allow a user to enter two integers representing a month and a year, and it should determine how many days
		are in the specified month. The integer 1 through 12 will be used to identify the months of January through
		December. The user indicates the end of input by entering 0 0 for the month and year. At that point, the program
		terminates. Use the following criteria to identify leap years:
			> A year Y is divisible by 100. Then Y is a leap year if and if only it is divisible by 400. For example, 2000 is a
		leap year but 2100 is not.
			> A year Y is not divisible by 100. Then Y is a leap year and if and if only it is divisible by 4. For example,
		2008 is a leap year but 2009 is not.

		Here is sample run of the program:
			Enter month and year: 2 2008
			29 days
			Enter month and year 0 0
		*/
		int q_5()
		{
			int year = -1, month = -1;
			while (true)
			{
				cout << "input month and year, end with both with 0: ";
				cin >> month >> year;
				if (month == 0 && year == 0) break;
				int day_of_month = q5_helper::getNumberOfDays(month, year);
				cout << day_of_month << " days.\n";
			}
			
			return 0;
		}
	}
}

#endif // !_SMS_PRACTICAL_SESSION_8_H_
