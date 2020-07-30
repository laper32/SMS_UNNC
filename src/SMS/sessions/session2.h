#pragma once
#ifndef _SMS_PRACTICAL_SESSION_2_H_
#define _SMS_PRACTICAL_SESSION_2_H_

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
	namespace PracticalSession2
	{
		/*
		1. Write a program that computes the total sales tax on a $52 purchase.
		Assume the state sales tax is 4% and the country sales tax is 2%.
		Display the purchase price, state tax, country tax, and total tax amounts on the screen.
		*/
		int q_1()
		{
			int m_iTotalPurchase = 52;
			double m_flSalesTaxRatio = 0.04, m_flCountrySalesTaxRatio = 0.02;

			double m_flSalesTax = m_iTotalPurchase * m_flSalesTaxRatio, m_flCountrySalesTax = m_iTotalPurchase * m_flCountrySalesTaxRatio, m_flTaxTotal = m_flSalesTax + m_flCountrySalesTax;

			cout <<
				"Purchase price: " << m_iTotalPurchase <<
				"\nState tax: " << m_flSalesTax <<
				"\nCountry tax: " << m_flCountrySalesTax <<
				"\nTotal tax: " << m_flTaxTotal <<
				endl;
			return 0;
		}

		/*
		2. Write a program that computes the tax and tip on a restaurant bill for a patron with a $44.50 meal charge.
		The tax should be 6.75 percent of the meal cost. The tip should be 15 percent of the total after adding the tax.
		Display the meal cost, tax amount, tip amount, and total bill on the screen.
		*/
		int q_2()
		{
			double m_flResurantBill = 44.5, m_flTaxCostRatio = 0.0675, m_flBitRatioAfterTax = 0.15;
			double m_flTaxAmount = m_flResurantBill * m_flTaxCostRatio;

			double m_flResurantBillAfterTax = m_flResurantBill * (1.0 + m_flTaxCostRatio), m_flTip = m_flResurantBillAfterTax * m_flBitRatioAfterTax;

			double m_flResult = m_flResurantBillAfterTax + m_flTip;

			cout <<
				"meal cost: " << m_flResurantBill <<
				"\ntax amount: " << m_flTaxAmount <<
				"\ntip: " << m_flTip <<
				"\ntotal bill: " << m_flResult <<
				endl;

			return 0;
		}

		/*
		3. A soft drink company recently surveyed 12,467 of its customers and found that approximately 14% of those surveyed purchase one or
		more energy drinks per week. Of those customers who purchase energy drinks, approximately 64% of them prefer citrus flavored energy drinks.
		Write a program that displays the following:
		a. The approximate number of customers in the survey who purchase one or more energy drinks per week.
		b. The approximate number of customers in the survey who prefer citrus flavored energy drink.
		*/
		int q_3()
		{
			unsigned int m_iCustomersTotal = 12467;
			double m_iPurchaseEnergyDrinkPerWeek = m_iCustomersTotal * 0.14;
			double m_iPurchaseFlavoredDrink = m_iCustomersTotal * 0.14 * 0.64;

			cout << "The approximate number of customers in the survey who purchase one or more energy drinks per week: " << (unsigned int)m_iPurchaseEnergyDrinkPerWeek <<
				"\nThe approximate number of customers in the survey who prefer citrus flavored energy drink: " << (unsigned int)m_iPurchaseFlavoredDrink <<
				endl;
			return 0;
		}

		/*
		4. There are three seating categories at a stadium. For a softball game, Class A seats cost $15, Class B seats cost $12, and Class C seats cost $9.
		Write a program that asks how many tickets for each class of seats were sold, then displays the amount of income generated from ticket sales.
		*/
		int q_4()
		{
			int m_iClassACost = 15, m_iClassBCost = 12, m_iClassCCost = 9;
			int m_iTicketForA, m_iTicketForB, m_iTicketForC;

			cout << "The ticket amount for A, B, and C (seperate by [SPACE])" << endl;
			std::cin >> m_iTicketForA >> m_iTicketForB >> m_iTicketForC;

			int m_iClassACostTotal = m_iClassACost * m_iTicketForA,
				m_iClassBCostTotal = m_iClassBCost * m_iTicketForB,
				m_iClassCCostTotal = m_iClassCCost * m_iTicketForC,
				m_iTotalIncome = m_iClassACostTotal + m_iClassBCostTotal + m_iClassCCostTotal;

			cout << "A: " << m_iClassACostTotal <<
				"\nB: " << m_iClassBCostTotal <<
				"\nC: " << m_iClassCCostTotal <<
				"\nTotal: " << m_iTotalIncome <<
				endl;
			return 0;
		}

		/*
		5. Write a program to find a baseball player¡¯s batting hit rate.
		The program should ask the user to enter the number of times the player was at bat and the number of hits he got.
		It should then display his batting rate to 4 decimal places.
		*/
		int q_5()
		{
			double m_iPlayerThrowed, m_iPlayerHitted;
			cout << "enter the number of times the player was at bat and the number of hits he got: ";
			cin >> m_iPlayerThrowed >> m_iPlayerHitted;
			double m_flHitRate = m_iPlayerHitted / m_iPlayerThrowed;
			printf("batting rate: %.4f", m_flHitRate);

			//TOFIX: WHY DECIMAL PLACES IS 6?
			//cout << "batting rate: " << m_flHitRate << endl;
			return 0;
		}

		/*
		6. Write a program that calculates the average monthly rainfall for three months. The program should calculate the average test score and display it.
		The number displayed should be formatted in fixed-point notation, with two decimal point of precision.
			> The average monthly rainfall for June, July, and August was 6.51 inches.
		*/
		int q_6()
		{
			double m_flRainedInchesInJune, m_flRainedInchesInJuly, m_flRainedInchesInAugust;

			cout << "Input the data of monthly rainfall inches: " << endl;

			cin >> m_flRainedInchesInJune >> m_flRainedInchesInJuly >> m_flRainedInchesInAugust;

			double m_flInchesAvg = (m_flRainedInchesInJune + m_flRainedInchesInJuly + m_flRainedInchesInAugust) / 3;

			printf("The average monthly rainfall for Jun., Jul., Aug. was %.2f inches", m_flInchesAvg);

			//cout << "The average monthly rainfall for June, July, and August was " << m_flInchesAvg << " inches." << endl;

			return 0;
		}

		/*
		7. Write a program that will convert U.S. dollar amounts to Japanese yen and to euros, storing the conversion factors in the constant variables
		YEN_PER_DOLLAR and EUROS_PER_DOLLAR. Use the following exchange rate:
			1 dollar = 78.18 Yen
			1 dollar = 0.8235 Euros
		*/
		int q_7()
		{
			constexpr auto YEN_PER_DOLLAR = 78.18, EUROS_PER_DOLLAR = 0.8235;

			double m_flUSD, m_flJPY, m_flEUR;
			cout << "Input USD: " << endl;
			cin >> m_flUSD;

			m_flJPY = YEN_PER_DOLLAR * m_flUSD;
			m_flEUR = EUROS_PER_DOLLAR * m_flUSD;

			cout << "USD: " << m_flUSD <<
				"\nJPY: " << m_flJPY <<
				"\nEUR: " << m_flEUR <<
				endl;

			/*printf("Input USD: ");
			scanf_s("%lf", &m_flUSD);

			m_flJPY = YEN_PER_DOLLAR * m_flUSD;
			m_flEUR = EUROS_PER_DOLLAR * m_flUSD;
			printf("USD : %.2f \
			\nYen: %.2f \
			\nEur: %.2f", m_flUSD, m_flJPY, m_flEUR);*/

			return 0;
		}

		/*
		8. Assuming there are no deposits other than the original investment, the balance in a saving accounts after one year may be calculated as

			> Amount = Principal * (1 + Rate / T)^T

		Principal is the balance in the account, Rate is the annual interest rate, and T is the number of times of the interest of compounded during a year
		(e.g., T is 4 if the interest is compounded quarterly).
		Write a program that asks for the principal, the interest rate, and the number of times the interest is compounded.
		It should display a report similar to the following:

		Interest Rate:                      4.25%
		Times Compounded:                      12
		Principal:                      $ 1000.00
		Interest:                       $   43.33
		Final Balance:                  $ 1043.33
		*/
		int q_8()
		{
			int T;
			double m_flPrincipal, m_flRate, m_flAmount, m_flInterest;

			cout << "Input the principal, rate, and the number of times of the interest of compounded during a year" << endl;
			cin >> m_flPrincipal >> m_flRate >> T;


			m_flAmount = m_flPrincipal * pow((1 + m_flRate / T), T);

			m_flInterest = m_flAmount - m_flPrincipal;

			double m_flRateDisplay = m_flRate * 100;

			cout <<
				"Interest rate: " << m_flRateDisplay << "%" <<
				"\nTimes Compunded: " << T <<
				"\nPrincipal: " << m_flPrincipal <<
				"\nInterest: " << m_flInterest <<
				"\nFinal Balance: " << m_flAmount <<
				endl;

			return 0;
		}

		/*
		9. Write the formula below into the code.
		a. d = sqrt( (x2-x1)^2 + (y2-y1)^2 )
		b. d = sin(x+0.5z)+cos(y*y)-tan(pow(z,5)/x)
		c. d = {-b+-sqrt(b^2-4ac)}/2a
		d. d = -z+6x( ( (12y/z) - x^5 ) /2z )
		*/
		int q_9()
		{
			double m_flDistance;
			// case a: d = sqrt( (x2-x1)^2 + (y2-y1)^2 )
			/*double x2, x1, y2, y1;

			cout << "input: x2, x1, y2, y1" << endl;
			cin >> x2 >> x1 >> y2 >> y1;
			m_flDistance = sqrtf( pow( (x2-x1), 2 ) + pow( (y2-y1) , 2 ) );
			cout << "distance: " << m_flDistance << endl;*/

			// case b: d = sin(x+0.5z)+cos(y*y)-tan(pow(z,5)/x)
			/*double x, y, z;
			cout << "input: x, y, z" << endl;
			cin >> x >> y >> z;
			m_flDistance = sin(x+0.5*z) + cos(y*y)-tan(pow(z,5)/x);
			cout << "distance: " << m_flDistance << endl;*/

			// case c: d = {-b+-sqrt(b^2-4ac)}/2a
			/*double a, b, c, d1, d2;
			cout << "input: a, b, c" << endl;
			cin >> a >> b >> c;
			d1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
			d2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
			cout << "distance: " << d1 << " " << d2 << endl;*/

			// case d: d = -z+6x( ( (12y/z) - x^5 ) /2z )
			double x, y, z;
			cout << "input: x, y, z" << endl;
			cin >> x >> y >> z;
			m_flDistance = -z + 6 * x * (((12 * y / z) - pow(x, 5)) / 2 * z);
			cout << "distance: " << m_flDistance << endl;

			return 0;
		}

		/*
		10. Write a program that asks the user for an angle, entered in radians. The program should then display the sine, cosine, and tangent of the angle.
		The output should be displayed in fixed-point notation, rounded to four decimal places of precision.
		*/
		int q_10()
		{
			double m_flRadian;
			cout << "input the rad: " << endl;
			cin >> m_flRadian;

			double pi = 3.1415926;
			double output_sine = sin(m_flRadian * 180.f / pi), output_cosine = cos(m_flRadian * 180.f / pi), output_tan = tan(m_flRadian * 180.f / pi);

			cout << "sin: " << output_sine <<
				"\ncos: " << output_cosine <<
				"\ntan: " << output_tan <<
				endl;

			return 0;
		}

		/*
		11. Joe¡¯s Pizza Palace needs a program to calculate the number of slices a pizza of any size can be divided into.
		The program should perform the following steps:
		a) Ask the user for the diameter of the pizza in inches.
		b) Calculate the number of slices that may be taken from a pizza of that size if each slice has an area of 14.125 square inches.
		c) Display a message telling the number of slices.
		The number of square inches in the total pizza can be calculated with this formula:
			> Area = pi*r^2
		Where variable r is the radius of the pizza and ¦Ð is the Greek letter PI. In your program make PI a named constant with the value 3.14.
		Display the number of slices as a whole number (i.e., with no decimals).

		Expansion: Let assume each person is expected to eat an average of 4 slices.
		The program should ask the user for the number of people who will be at the party and for the diameter of the pizzas to be ordered.
		It should then calculate and display the number of pizzas to purchase.
		Because it is impossible to buy a part of a pizza, the number of required pizzas should be display as a whole number.
		*/
		int q_11()
		{
			constexpr auto pi = 3.1415926;
			double m_flInchesRequired, m_flArea;
			cout << "Input the inches what you want: " << endl;
			cin >> m_flInchesRequired;
			m_flArea = pi * pow(m_flInchesRequired, 2);
			double m_flSpiltTotal = m_flArea / 14.125f;
			cout << "slices: " << (int)m_flSpiltTotal << endl;
			return 0;
		}
	}
}

#endif // !_SMS_PRACTICAL_SESSION_2_H_
