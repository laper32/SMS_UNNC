#pragma once
#ifndef _SMS_PRACTICAL_SESSION_3_H_
#define _SMS_PRACTICAL_SESSION_3_H_

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
	namespace PracticalSession3
	{
		/*
		1. The following code segments are syntactically correct, but each contains an error; find and correct the
		errors.

			a.
				int hours = 12;
				if(hours > 40); // please, DO NOT WRITE SEMICOLON ON STATEMENTS...
				printf("%d hours qualifies for over-time.\n", hours);

			b.
				double interestRate = .05;
				if(interestRate = .07) // it should be ==, not =...
					printf("This account is earning the maximum rate.\n");

			c.
				double interestRate = .05;
				if(interestRate > .07) // when the syntax more than 1 line, using {}; and, where is the balance assignment?
					printf("This account earns a $10 bonus.\n");
					balance += 10.0;

		*/
		int q_1()
		{
			cout << "a. \
				\nDO NOT WRITE SEMICOLON ON IF/ELSEIF/... STATEMENTS" << endl;

			cout << "b. \
				\nit should be ==, not =..." << endl;

			cout << "c.  \
				\n1. when the syntax more than 1 line, using {} \
				\n2. where is the balance assignment?" << endl;
			return 0;
		}

		/*
		2. Create a sample program to input two arguments, variables A and B, output A if A is greater than B, or
		output B is B is greater than A.
		*/
		template <typename T>
		int q_2()
		{
			T a, b;
			cout << "Input a and b for compare: " << endl;
			cin >> a >> b;
			return (a > b) ? a : b;
		}

		/*
		3. Write a C program that gets an input mark from the user and then displays the grade of the mark, based on
		the following table. The mark should be entered in one decimal place.
				Mark			|		  Grade
		---------------------------------------------------
			 75 - 100						A
			 60 - 74.9						B
			 50 - 59.9						C
			  0 - 49.9						F
		*/
		int q_3()
		{
			double m_flMark;
			cout << "input the mark:" << endl; cin >> m_flMark;
			if (m_flMark >= 75.f && m_flMark <= 100.f) cout << 'A' << endl;
			if (m_flMark >= 60.f && m_flMark <= 74.9f) cout << 'B' << endl;
			if (m_flMark >= 50.f && m_flMark <= 59.9f) cout << 'C' << endl;
			if (m_flMark >= 0.f && m_flMark <= 49.9f) cout << 'F' << endl;

			return 0;
		}

		/*
		4. The area of a rectangle is the rectangle¡¯s length times its width. Write a program that asks for the length
		and width of two rectangles. The program should then tell the user which rectangle has the greater area, or
		if the areas are the same.
		*/
		int q_4()
		{
			double length_a, width_a, area_a, length_b, width_b, area_b;

			cout << "input a regtangle's length and width: " << endl;
			cin >> length_a >> width_a;
			cout << "input another regtangle's length and width: " << endl;
			cin >> length_b >> width_b;

			area_a = length_a * width_a; area_b = length_b * width_b;

			if (area_a > area_b) cout << "a > b" << endl;
			else if (area_a < area_b) cout << "a < b" << endl;
			else cout << "has same area" << endl;

			return 0;
		}

		/*
		5. An online book club awards points to its customers based on the number of books purchased each month.
		Points are awarded as follow:
					Books Purchased			|			Points Earned
		-------------------------------------------------------------------------------
						0									0
						1									5
						2									15
						3									30
					4 or more								60
			Write a program that asks the user to enter the number of books purchased this month and then displays
		the number of points awarded
		*/
		int q_5()
		{
			unsigned int m_iBought = 0, m_iPoint = 0;
			cout << "Input the book what have bought" << endl;
			cin >> m_iBought;
			if (m_iBought == 0) m_iPoint = 0;
			else if (m_iBought == 1) m_iPoint = 5;
			else if (m_iBought == 2) m_iPoint = 15;
			else if (m_iBought == 3) m_iPoint = 30;
			else if (m_iBought >= 4) m_iPoint = 60;
			else cout << "Exception occured::m_iBought < 0" << endl;

			cout << "Points: " << m_iPoint << endl;
			return 0;
		}

		/*
		6. Write a program that can be used as math tutor for a young student. The program should display two
		random numbers between 10 and 50 that are to be added: 10 + 24 = ?
			A congratulation message is printed if the answer is correct; else the correct answer should be printed to
		the screen.
		*/
		template <typename T>
		int q_6()
		{
			int lb = 10, ub = 50;
			int range = ub - lb;
			unsigned generator = time(nullptr);
			srand(generator);
			int a, b;
			a = rand() % range + lb;
			b = rand() % range + lb;
			T result;
			cout << a << " + " << b << " = " << endl;
			cin >> result;
			if (result == a + b) cout << "congratulations, the answer is correct" << endl;
			else cout << "incorrect answer" << endl;
			return 0;
		}

		/*
		7. A software company sells a package that retails for $99. Quantity discounts are given according to the
		following table
						Quality					|				  Discount
		-----------------------------------------------------------------------------------
						10 - 19										20%
						20 - 49										30%
						50 - 99										40%
					  100 or more									50%
		Write a program that asks for the number of units purchased and computes the total cost of the purchase

		Input validation: Decide how the program should handle an input of less than 0. std::except
		*/
		int q_7()
		{
			int m_iQuality; double m_flDiscountRate = 0.0;
			cout << "input the quality: " << endl;
			cin >> m_iQuality;

			if (m_iQuality < 0)
			{
				cout << "Exception occurs: Quality input less than 0." << endl;
				return -1;
			}
			else
			{
				if (m_iQuality >= 10 && m_iQuality <= 19)
					m_flDiscountRate = 0.2;
				if (m_iQuality >= 20 && m_iQuality <= 49)
					m_flDiscountRate = 0.3;
				if (m_iQuality >= 50 && m_iQuality <= 99)
					m_flDiscountRate = 0.4;
				if (m_iQuality >= 100)
					m_flDiscountRate = 0.5;

				cout << "Discount rate: " << m_flDiscountRate << endl;
				return 0;
			}
		}

		/*
		8. Write a program that asks the user to enter a number within the range of 1 through 10. Use a switch
		statement to display the Roman numeral version of that number. Decide how the program should handle
		an input that is less than 1 or greater than 10.

		Input validation: Decide how the program should handle an input that is less than 1 or greater than 10.
		*/
		int q_8()
		{
			int input;
			cout << "input a number: " << endl;
			cin >> input;

			if (input < 0 || input > 10)
			{
				cout << "input value oob range: [1, 10]" << endl;
				return -1;
			}
			switch (input)
			{
			case 1: { cout << "I" << endl; break; }
			case 2: { cout << "II" << endl; break; }
			case 3: { cout << "III" << endl; break; }
			case 4: { cout << "IV" << endl; break; }
			case 5: { cout << "V" << endl; break; }
			case 6: { cout << "VI" << endl; break; }
			case 7: { cout << "VI" << endl; break; }
			case 8: { cout << "VII" << endl; break; }
			case 9: { cout << "IX" << endl; break; }
			case 10: { cout << "X" << endl; break; }
			}
			return 0;
		}

		/*
		9. Write a program that displays the following menu:
			> Geometry Calculator
			> 1. Calculate the Area of a Circle
			> 2. Calculate the Area of a Rectangle
			> 3. Calculate the Area of a Triangle
			> 4. Quit

			> Enter your choice (1-4):

			If enter 1: the program should ask for the radius of the circle and display its area. If enter 2: the program
		should ask for the length and width of the rectangle, and then display the rectangle¡¯s area. If enter 3: the
		program should ask for the length of the triangle¡¯s base and its height, and then display its area.
		If enter 4: the program should end.

			Input validation: Decide how the program should handle an illegal input for the menu choice or a
		negative value of any of the other inputs
		*/
		int q_9()
		{
			cout <<
				"Geometry Calculator \
				\n1. Calculate the Area of a Circle \
				\n2. Calculate the Area of a Rectangle \
				\n3. Calculate the Area of a Triangle \
				\n4. Quit \
				\nEnter your choice (1-4):"
				<< endl;

			int m_iOption = 0;
			cin >> m_iOption;

			if (m_iOption < 1 || m_iOption > 4)
			{
				cout << "Nope" << endl;
				return -1;
			}

			switch (m_iOption)
			{
				// 1. Calculate the Area of a Circle
			case 1:
			{
				constexpr auto pi = 3.1415926;
				double radius;
				cout << "input radius" << endl;
				cin >> radius;

				if (radius <= 0.0)
				{
					cout << "Radius must > 0" << endl;
					return -1;
				}

				double area = pi * pow(radius, 2);

				cout << "Area of circle: " << area << endl;
				return 0;
			}
			// 2. Calculate the Area of a Rectangle
			case 2:
			{
				double length, width;

				cout << "input the length and width" << endl;
				cin >> length >> width;
				if (length <= 0.0)
				{
					cout << "Length must > 0" << endl;
					return -1;
				}

				if (width <= 0.0)
				{
					cout << "Width must > 0" << endl;
					return -1;
				}

				double area = length * width;

				cout << "the area of the regtangle is: " << area << endl;

				return 0;
			}
			// 3. Calculate the Area of a Triangle
			case 3:
			{
				double base, height;
				cout << "Input the base and the height" << endl;
				cin >> base >> height;

				if (base <= 0.0)
				{
					cout << "Base must > 0" << endl;
					return -1;
				}

				if (height <= 0.0)
				{
					cout << "Height must > 0" << endl;
					return -1;
				}

				double area = base * height / 2.f;

				cout << "the area of the triangle is: " << area << endl;
				return 0;
			}
			// 4. Quit
			case 4:
			{
				cout << "You now have quitted the calculator" << endl;
				return 0;
			}
			}

			return 0;
		}

		/*
		10. Write a program that calculates and displays a person¡¯s body mass index (BMI). The BMI is often used to
		determine whether a person with a sedentary lifestyle is overweight or underweight for his or her height.
		A person¡¯s BMI is calculated with the following formula:

			> BMI = weight ¡Á 703 / height^2

		where weight is measured in pounds and height is measured in inches. The program should display a
		message indicating whether the person has optimal weight, is underweight, or overweight. A sedentary
		person¡¯s weight is optimal if his or her BMI is between 18.5 and 25. If the BMI is less than 18.5, the
		person is underweight. If the BMI value is greater than 25, the person is overweight.
		*/
		int q_10()
		{
			double bmi, weight, height;

			cout << "input weight(pound)" << endl;
			cin >> weight;
			if (weight <= 0.0)
			{
				cout << "weight must > 0" << endl;
				return -1;
			}

			cout << "input height(inches)" << endl;
			cin >> height;
			if (height <= 0.0)
			{
				cout << "height must > 0" << endl;
				return -1;
			}

			bmi = weight * 703 / pow(height, 2);

			if (bmi >= 18.5 && bmi <= 25)
			{
				cout << "OPTIMAL" << endl;
				return 0;
			}
			else if (bmi < 18.5)
			{
				cout << "UNDERWEIGHT" << endl;
				return 0;
			}
			else if (bmi > 25)
			{
				cout << "OVERWEIGHT" << endl;
				return 0;
			}

			return 0;
		}

		/*
		11. Write a program to get a number, then determine whether the number is prime number or not.
		*/
		int q_11()
		{
			int num; bool isprime = true;
			cout << "input a number: " << endl;
			cin >> num;

			if (num <= 0)
			{
				cout << "must > 0" << endl;
				return -1;
			}

			for (int i = 2; i <= num / 2; i++)
			{
				if (num % i == 0)
				{
					isprime = false;
					break;
				}
			}

			if (isprime) cout << "yes it is" << endl;
			else cout << "nope" << endl;

			return 0;
		}
	}
}

#endif // !_SMS_PRACTICAL_SESSION_3_H_