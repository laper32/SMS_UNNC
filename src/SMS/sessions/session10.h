#pragma once
#ifndef _SMS_PRACTICAL_SESSION_10_H_
#define _SMS_PRACTICAL_SESSION_10_H_

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

namespace SMS
{
	class SortManager
	{
	protected:
		int _arr[10], x, y;
	private:
	public:
		SortManager(int _array[10] = { 0 }) { }

		virtual bool compare(int x, int y) = 0;

		void display(int _array[], int _size = 10)
		{
			for (int i = 0; i < _size; i++)
			{
				cout << _array[i] << " ";
			}
		}

		void sort(int _array[], int _size = 10)
		{
			for (int i = 0; i < _size; i++)
			{
				for (int j = i+1; j < _size; j++)
				{
					if (compare(_array[i], _array[j]))
					{
						int _temp = _array[i];
						_array[i] = _array[j];
						_array[j] = _temp;
					}
				}
			}
		}
	};

	class SortManagerAsc : public SortManager
	{
	public:
		bool compare(int x, int y)
		{
			return x > y;
		}
	};

	class SortManagerDsc : public SortManager
	{
	public:
		bool compare(int x, int y)
		{
			return x < y;
		}

		
	};

	class AbstractSort
	{
	protected:
		int counter;
	private:
		int _array[5];
	public:
		bool compare(int x, int y)
		{
			return x > y;
		}
		virtual void sort(int _array[], int _size) = 0;
	};
	
	class BubbleSort :public AbstractSort
	{
	public:
		BubbleSort()
		{
			this->counter = 0;
		}
		void sort(int _array[], int _size)
		{
			int i, j;
			for (i = 0; i < _size - 1; i++)
			{
				for (j = 0; j < _size - 1 - i; j++)
				{
					if (compare(_array[j], _array[j + 1]))
					{
						counter += 1;
						swap(_array[j], _array[j + 1]);
					}
				}
			}
		}

		int getCounter() const { return this->counter; }
	};

	class Encryption
	{
	private:
		int key;
	public:
		Encryption() { this->key = 0; }
		
		int getKey() const { return this->key; }
		void setKey(int _key) { this->key = _key; }

		string encrypt(string _encryptStr)
		{
			for (int i = 0; i < _encryptStr.length(); i++) {
				_encryptStr[i] = transform(_encryptStr[i], encryptMode);
			}
			return _encryptStr;
		}

		string decrypt(string _decryStr)
		{
			for (int i = 0; i < _decryStr.length(); i++) {
				_decryStr[i] = transform(_decryStr[i], decryptMode);
			}
			return _decryStr;
		}

		virtual char transform(char ch, int mode) = 0;

		static const int encryptMode = 0, decryptMode = 1;

		void compareStr(string _strA, string _strB)
		{
			if (_strA == _strB) 
			{
				cout << "Both strings are the same." << endl;
			}
			else 
			{
				cout << "Both strings are not the same." << endl;
			}
		}
	};

	class SimpleEncryption : public Encryption
	{
	public:
		char transform(char ch, int mode) {
			switch (mode) {
			case encryptMode:
				return (ch + getKey());
				break;
			case decryptMode:
				return (ch - getKey());
				break;
			}
			return -1;
		}
	};

	class AbstractSeq
	{
	protected:
		int k, m, sum;
	public:
		AbstractSeq() { this->k = this->m = this->sum = 0; }
		virtual ~AbstractSeq() {}
		void printSeq(int k, int m)
		{
			while (k <= m)
			{
				cout << fun(k) << " ";
				k++;
			}
		}
		int sumSeq(int k, int m)
		{
			int sum = 0;
			while (k <= m)
			{
				sum += fun(k);
				k++;
			}
			return sum;
		}
		virtual int fun(int k) = 0;
	};

	class OddSeq :public AbstractSeq
	{
	public:
		int odd(int k) { return 2 * k + 1; }
		int fun(int k)
		{
			return odd(k);
		}
	};

	class EvenSeq :public AbstractSeq
	{
		int even(int k) { return 2 * k; }
		int fun(int k) { return even(k); }
	};

	namespace PracticalSession10
	{
		/* 
		1. Suppose that the classes Dog and Cat derive from Animal, which in turn derives from Creature.
		Suppose further that pDog, pCat, pAnimal, and pCreature are pointers to the respective classes.
		Suppose that Animal and Creature are both abstract classes.
			a. Will the statement Animal a; compile?
			b. Will the statement pAnimal = new Cat; compile?
			c. Will the statement pCreature = new Dog; compile?
			d. Will the statement pCat = new Animal; compile?
		 */
		int q_1()
		{
			cout << "a. OK" << endl;
			cout << "b. OK" << endl;
			cout << "c. OK" << endl;
			cout << "d. NO" << endl;
			return 0;
		}

		/* 
		2. Write a C++ class called SortManager that has an array of 10 integers as a member variable, a pure
		virtual member function
			bool compare(int x, int y) = 0;
		that compares its two parameters and returns a boolean value, and a member function
			void sort()
		that uses the comparison defined by the compare virtual function to sort the array. The sort function will
		swap a pair of array elements a[k] and a[j] if
			compare(a[k], a[j])
		returns true. Think how you can use this class to produce classes that sort arrays in ascending order and
		descending order.
		 */
		int q_2()
		{
			int _arr_to_do[10] = { 1, 16, 3, 50, 7, 33, 12, 5, 18, 10 };
			
			SortManagerAsc _asc;
			cout << "pre: ";
			_asc.display(_arr_to_do);
			cout << endl;
			_asc.sort(_arr_to_do);
			cout << "post(asc): ";
			_asc.display(_arr_to_do);

			SortManagerDsc _dsc;
			cout << endl;
			_dsc.sort(_arr_to_do);
			cout << "post(dsc): ";
			_dsc.display(_arr_to_do);

			return 0;
		}

		/* 
		3. Design a class AbstractSort that can be used to analyze the number of comparisons performed by a
		sorting algorithm. The class should have a member function compare that is capable of comparing two
		array elements, and a means of keeping track of the number of comparisons performed. The class should
		be an abstract class with a pure virtual member function
			void sort(int arr[], int size)
		which, when overridden, will sort the array by calling the compare function to determine the relative order
		of pairs of numbers. Create subclass of AbstractSort that uses a simple sorting algorithm to implement
		the sort function. The class should have a member function that can be called after the sorting is done to
		retrieve the number of comparisons performed.
		 */
		int q_3()
		{
			int max = 9, min = 1;
			int length = 5;
			int* listArray = new int[length];

			// random generate a list array
			srand(time(NULL));
			for (int i = 0; i < length; i++) {
				listArray[i] = rand() % (max - min) + min;
			}

			// print unsorted list array
			cout << "Unsorted list array:" << endl;
			for (int i = 0; i < length; i++) {
				cout << listArray[i] << " ";
			}
			cout << endl << endl;
			
			BubbleSort _sort;
			_sort.sort(listArray, length);
			for (int i = 0; i < length; i++) {
				cout << listArray[i] << " ";
			}
			cout << endl << endl;

			cout << "swap times: " << _sort.getCounter() << endl;

			return 0;
		}

		/* 
		4. Create an Encryption class with a pure virtual transform member function that transforms the
		character passed to it by adding the key to it. The encrypt function is called to perform encryption of
		input string. The key should be represented as a member of the Encryption class, and the class should
		have a member function that sets the encryption key. When the program runs, the main function should 
		ask the user for the input string to encrypt, and an encryption key. Add a decrypt function to perform
		decryption on the encrypted string. Make sure that the decrypted text is validated with original text.
		 */
		int q_4()
		{
			string _originalMsg = "Debug Encryption";
			string _encryptMsg, _decryptMsg;

			SimpleEncryption _encryption;
			_encryption.setKey(2);
			_encryptMsg = _encryption.encrypt(_originalMsg);
			_decryptMsg = _encryption.decrypt(_encryptMsg);

			cout << "original msg: " << _originalMsg << endl;
			cout << "encrypt msg: " << _encryptMsg << endl;
			cout << "decrypt msg: " << _decryptMsg << endl;
			_encryption.compareStr(_originalMsg, _decryptMsg);

			cout << "\n===================================\n" << endl;

			_encryption.setKey(3);
			_encryptMsg = _encryption.encrypt(_originalMsg);
			_decryptMsg = _encryption.decrypt(_encryptMsg);

			cout << "original msg: " << _originalMsg << endl;
			cout << "encrypt msg: " << _encryptMsg << endl;
			cout << "decrypt msg: " << _decryptMsg << endl;
			_encryption.compareStr(_originalMsg, _decryptMsg);

			return 0;
		}

		/* 
		5. A sequence of integers such as 1, 3, 5, and 7 … can be represented by a function that takes a nonnegative
		integer as parameter and returns the corresponding term of the sequence. For example, the sequence of
		odd numbers just cited can be represented by the function
			int odd(int k) { return 2 * k + 1; }
		Write an abstract class AbstractSeq that has a pure virtual member function
			virtual int fun(int k) = 0;
		as a stand-in for an actual sequence, and two member functions
			void printSeq(int k, int m);
			int sumSeq(int k, int m);
		that are passed two integer parameters k and m, where k < m. The function printSeq will print all the
		terms fun(k) through fun(m) of the sequence, likewise, the function sumSeq will return the sum of
		those terms. Demonstrate your AbstractSeq class by creating subclasses that you use to sum the terms
		of at least two different sequences. 
		 */
		int q_5()
		{
			OddSeq _odd, _even;
			_odd.printSeq(0, 10);
			cout << "\nsum::odd: " << _odd.sumSeq(0, 10) << endl;

			// print even sequence from 0 to 10
			cout << "// evenSeq.printSeq(0, 10);" << endl;
			_even.printSeq(0, 10);
			cout << "Sum of even sequence from 0 to 10: " << _even.sumSeq(0, 10);
			cout << endl << endl;

			// print odd sequence from 5 to 12
			cout << "// oddSeq.printSeq(5, 12);" << endl;
			_odd.printSeq(5, 12);
			cout << "Sum of odd sequence from 5 to 12: " << _odd.sumSeq(5, 12);
			cout << endl << endl;

			// print even sequence from 5 to 12
			cout << "// evenSeq.printSeq(5, 12);" << endl;
			_even.printSeq(5, 12);
			cout << "Sum of even sequence from 5 to 12: " << _even.sumSeq(5, 12);
			cout << endl << endl;

			// simulate error sequence
			cout << "Simulate error sequence!" << endl;
			cout << "// oddSeq.printSeq(12, 5);" << endl;
			_odd.printSeq(12, 5);

			return 0;
		}
	}
}


#endif // !_SMS_PRACTICAL_SESSION_9_H_

