#pragma once
#ifndef _SMS_PRACTICAL_SESSION_1_H_
#define _SMS_PRACTICAL_SESSION_1_H_

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
	namespace PracticalSession1
	{
		/*
		1. Write a program that displays the following pattern on the screen.
			*
		   ***
		  *****
		 *******
		  *****
		   ***
			*
		*/
		int q_1()
		{
			std::cout <<
				"   *\n" <<
				"  *** \n" <<
				" ***** \n" <<
				"******* \n" <<
				" ***** \n" <<
				"  *** \n" <<
				"   * " <<
				std::endl;
			return 0;
		}

		/*
		2. Print a smile face to the screen
		*/
		int q_2()
		{
			std::cout <<
				"  /\\            /\\ \n" <<
				"                     \n" <<
				"          *          \n" <<
				"                     \n" <<
				"    \\         /     \n" <<
				"     ---------       \n" <<
				std::endl;
			return 0;
		}


		/*
		If program is successfully compiled, what is the output? If error occurred, why?
		#include <stdio.h>

		int main()
		{
			int arg1;
			arg1 = -1;
			int x, y, z;
			char myDouble = '5';
			char arg1 = 'A';
			printf("%c\n", arg1);
			return 0;
		}
		*/
		int q_3()
		{
			cout << "No, Must sure that an argument has same type." <<
				"\nie: when has assigned an argument with one specified typename, DO NOT SIGN IT AGAIN WITH TYPES" <<
				endl;
			return 0;
		}

		/*
		4. Below is a sample program. What happen if we declare an identifier in a block, and then declare that same identifier in a
		block nested within that block? Can the program be compiled? What is the output?
		#include <stdio.h>
		int main()
		{
			int arg1;
			arg1 = -1;
			{
				char arg1 = 'A';
				printf("%c\n", arg1);
			} printf("%s\n", arg1);
			return -1;
		}
		*/
		int q_4()
		{
			cout <<
				"Yes, However, when executing, it will throw error:" <<
				"\nerrormessage: ucrtbased.pdb contains the debug information required to find the source for the module ucrtbased.dll" <<
				"\nbtw: In some compiler, this expression (syntax with braces without condition/func/etc) will throw error directly." <<
				endl;
			return 0;
		}

		/*
		5. The East Coast sales division of a company generates 62% of total sales.
		Based on that percentage, write a program that will predict how much the East Coast division will generate if the company
		has $4.6 million in sales this year. Display the result on the screen.
		*/
		int q_5()
		{
			double m_flTotalSales = 0.62;
			double m_flResult = 4.6e6 * m_flTotalSales;
			std::cout << m_flResult << std::endl;
			return 0;
		}

		/*
		6. A car with a 20-gallon gas tank averages 21.5 miles per gallon when driven in town and 26.8 miles per gallon when driven on the highway.
		Write a program that calculates and displays the distance the car can travel on one tank of gas when driven in town and when driven on the highway.
		*/
		int q_6()
		{
			unsigned int m_iGallonTotal = 20;
			double m_flAvgMilesInTown = 21.5, m_flAvgMilesOnHighWay = 26.8;

			double m_flDistanceTotalInTown = m_iGallonTotal * m_flAvgMilesInTown;
			double m_flDistanceTotalOnHighWay = m_iGallonTotal * m_flAvgMilesOnHighWay;

			std::cout << "Total miles in town: " << m_flDistanceTotalInTown << std::endl;
			std::cout << "Total miles on the highway: " << m_flDistanceTotalOnHighWay << std::endl;
			return 0;
		}

		/*
		7. float m_flProfitExpected = 0.4, m_flProducePrice = 12.67, m_flPriceOnSell = m_flProducePrice * (1.f + m_flProfitExpected);
		std::cout << "the selling price of a circuit board: " << m_flPriceOnSell << std::endl;
		return 0;
		*/
		int q_7()
		{
			double m_flProfitExpected = 0.4, m_flProducePrice = 12.67, m_flPriceOnSell = m_flProducePrice * (1.f + m_flProfitExpected);
			std::cout << "the selling price of a circuit board: " << m_flPriceOnSell << std::endl;
			return 0;
		}

		/*
		8. An employee earns $32,500 annually.
		Write a program that determines and displays what the amount of his gross pay will be for
		each pay period if he is paid twice a month (24 pay checks per year) and if he is paid bi-weekly (26 checks per year).
		*/
		int q_8()
		{
			unsigned int m_iEarnAnnual = 32500, m_iTwiceAMonthPeriodTotal = 24, m_iBiWeeklyAMonthPeriodTotal = 26;
			double m_flPayPriceTwiceAMonthPeriod = (double)m_iEarnAnnual / (double)m_iTwiceAMonthPeriodTotal;
			double m_flPayBiWeeklyAMonthPeriodTotal = (double)m_iEarnAnnual / (double)m_iBiWeeklyAMonthPeriodTotal;
			std::cout << " paid twice a month (24 pay checks per year): " << m_flPayPriceTwiceAMonthPeriod << std::endl;
			std::cout << "paid bi-weekly (26 checks per year): " << m_flPayBiWeeklyAMonthPeriodTotal << std::endl;
			return 0;
		}

		/*
		9. Kathryn bought 600 shares of stock at a price of $21.77 per share.  A year later she told them for just $16.44 per share.
		Write a program that calculates and displays the following:
			• The total amount paid for the stock.
			• The total amount received from selling the stock.
			• The total amount of money she lost.
		*/
		int q_9()
		{
			unsigned int m_iStockTotal = 600;
			double m_flStockPriceAtStart = 21.77, m_flStockPrictAtYearLater = 16.44;
			double m_flStockPricePaid = m_flStockPriceAtStart * (double)m_iStockTotal;
			double m_flSoldStockEarned = m_flStockPrictAtYearLater * (double)m_iStockTotal;
			double m_flStockDeductValue = m_flStockPricePaid - m_flSoldStockEarned;
			std::cout << "The total amount paid for the stock: " << m_flStockPricePaid << std::endl;
			std::cout << "The total amount received from selling the stock: " << m_flSoldStockEarned << std::endl;
			std::cout << "The total amount of money she lost:" << fabs(m_flStockDeductValue) << std::endl;
			return 0;
		}

		/*
		10.  The Earth’s ocean levels have risen an average of 1.8 millimeters per year over the past century.
		Write a program that computes and displays the number of centimeters and number of inches the oceans rose during this time.
		One millimeter is equivalent to 0.1 centimeters. One centimeter is equivalent to 0.3937 inches.
		*/
		int q_10()
		{
			double m_flOceanLevelRisenAvgMilliMeters = 1.8;
			double m_flRisenPerYearMilliMeters = 365.f * m_flOceanLevelRisenAvgMilliMeters;

			double m_flRisenPerYearCentiMeters = 0.1 * m_flRisenPerYearMilliMeters;
			double m_flRisenPerYearInches = m_flRisenPerYearMilliMeters * 0.3937;
			std::cout << "Risen per year about inches: " << m_flRisenPerYearInches << std::endl;
			return 0;
		}

		/*
		11. During the past decade ocean levels have been rising faster than in the past, an average of approximately 3.1 millimeters per year.
		Write a program that computes how much ocean levels are expected to rise during the next 20 years if they continue rising at this rate.
		Display the answer in both centimeters and inches.
		*/
		int q_11()
		{
			double m_flRisenUpdatedMilliMeters = 3.1;
			double m_flRisenUpdatedPerYearMilliMeters = 365.f * m_flRisenUpdatedMilliMeters;

			double m_flRisenUpdatedPerYearCentiMeters = 0.1 * m_flRisenUpdatedPerYearMilliMeters;
			double m_flRisenUpdated20YearsCentiMeters = m_flRisenUpdatedPerYearCentiMeters * 20.f;

			double m_flRisenUpdatedPerYearInches = 0.3937 * m_flRisenUpdatedPerYearCentiMeters;
			double m_flRisenUpdated20YearsInches = m_flRisenUpdatedPerYearInches * 20.f;

			std::cout << "20 years with centimeters: " << m_flRisenUpdated20YearsCentiMeters << std::endl;
			std::cout << "20 years with inches: " << m_flRisenUpdated20YearsInches << std::endl;
			return 0;
		}
	}

}

#endif // !_SMS_PRACTICAL_SESSION_1_H_
