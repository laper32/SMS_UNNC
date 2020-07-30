#pragma once
#ifndef _SMS_PRACTICAL_SESSION_6_H_
#define _SMS_PRACTICAL_SESSION_6_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

namespace SMS
{
	bool IsAllDigit(string& str)
	{
		for (auto temp : str)
		{
			if (!isdigit(temp))
				return false;
		}
		return true;
	}

	bool IsAllAlphabetic(string& str)
	{
		for (auto temp : str)
		{
			if (!isalpha(temp)) return false;
		}
		return true;
	}

	bool IsAllUpper(string& str)
	{
		for (auto temp : str)
		{
			if (!isupper(temp)) return false;
		}
		return true;
	}

	bool IsAllLower(string& str)
	{
		for (auto temp : str)
		{
			if (!islower(temp)) return false;
		}
		return true;
	}

	void RemoveAllDigits(string& str)
	{
		if (str.size() == 0) return;

		int beforepos = 0, afterpos = 0;
		while (str[beforepos])
		{
			if (!(str[beforepos] >= '0' && str[afterpos] <= '9'))
			{
				str[afterpos++] = str[beforepos];
			}
			beforepos++;
		}
		str = str.substr(0, afterpos);
	}

	bool validate_pw(string& _password)
	{
		if (_password.empty())
		{
			cout << "cannot be empty" << endl;
			return false;
		}

		if (_password.length() < 6)
		{
			cout << "at least 6 characters." << endl;
			return false;
		}

		if (IsAllDigit(_password))
		{
			cout << "must have a character" << endl;
			return false;
		}

		if (IsAllAlphabetic(_password))
		{
			cout << "must have a digit" << endl;
			return false;
		}

		string _template = _password;
		RemoveAllDigits(_template);

		if (IsAllUpper(_template))
		{
			cout << "at least one lower" << endl;
			return false;
		}

		if (IsAllLower(_template))
		{
			cout << "at least one upper" << endl;
			return false;
		}

		return true;
	}

	int encrypt(int src, int key)
	{
		//xor
		return src ^ key;
	}

	int decrypt(int enc, int key)
	{
		//xor
		return enc ^ key;
	}

	namespace PracticalSession6
	{
		/* 
		1. Write a program that asks the user for the name of a text file. The program should display the first 10 lines
		of the file on the screen. If the file has fewer than 10 lines, the entire file should be displayed along with a
		message indicating the entire file has been displayed.
		 */
		int q_1()
		{
			string _filename;
			while (true)
			{
				cout << "input the filename: ";
				getline(cin, _filename);
				if (_filename.empty()) break;

				ifstream file;
				file.open(_filename);
				if (file.fail())
				{
					cout << "unable to open the file. file not found" + _filename;
					continue;
				}
				else
				{
					char _c;
					int linectr = 0;
					while (file.get(_c))
					{
						if (_c == '\n') linectr += 1;

						std::cout << _c;
						if (linectr >= 10) break;
					}

					if (linectr < 10) cout << "\nit has " << linectr << " lines.";
					break;
				} file.close();
			}
			return 0;
		}

		/* 
		2. Write a program that asks the user for the name of a file and a string to search for. The program will
		search the file for all occurrences of the specified string and display all lines that contain the string. After
		all occurrences have been located, the program should report the number of times the string appeared in
		the file
		 */
		int q_2()
		{
			string _filename, _text;
			while (true)
			{
				cout << "input the file name: "; getline(cin, _filename);
				//if (cin.get() == EOF || cin.get() == '\n') break;

				/*if (_filename.empty() )
				{
					cout << "the file name is empty.\n";
					continue;
				}*/

				cout << "input what text need to search: "; getline(cin, _text);
				//if (cin.get() == EOF || cin.get() == '\n') break;

				/*if (_text.empty() )
				{
					cout << "no text has input.";
					continue;
				}*/

				ifstream file;
				file.open(_filename);
				if (file.fail())
				{
					cout << "unable to open the file, file not found: " + _filename;
					continue;
				}
				else 
				{
					int counter = 0;
					while (!file.eof())
					{
						string line; // the line of the text
						getline(file, line);
						if (line.find(_text, 0) != string::npos)
						{
							counter++;
						}
					}

					cout << "the string: " << _text << " has occured: " << counter << " times." << endl;
				}

				break;
			}

			return 0;
		}

		/* 
		3. Imagine you are developing a software package that requires users to enter their own passwords. Your
		software requires that user’s passwords meet the following criteria:
			> The password should be at least 6 characters long.
			> The password should contain at least one uppercase and at least one lowercase letter.
			> The password should have at least one digit.
		Write a program that asks for a password and then verifies that it meets the stated criteria. If it doesn’t, the
		program should display a message telling the user why
		 */
		int q_3()
		{
			string _password;
			while (true)
			{
				cout << "input password: "; getline(cin, _password);

				//if (cin.get() == EOF) break;

				if (!validate_pw(_password)) continue;
				else cout << "the password has set: " + _password;

				break;
			}

			return 0;
		}

		/* 
		4. The letter e is the most frequently used letter in English prose, and the letter z is the least frequently used.
		A friend of yours doing a sociology experiment believes that this may not necessarily be true of the
		writings of first-year college students. To test his theory, he asks you to write a program that will take a
		text file and print, for each letter of the English alphabet, the number of times the letter appears in the file.
		 */
		int q_4()
		{
			string _filename;
			while (true) 
			{
				cout << "input the filename: ";
				getline(cin, _filename);

				if (_filename.empty()) 
				{
					cout << "empty filename here?\n" << endl; 
					continue;
				}

				ifstream file;
				file.open(_filename);
				if (file.fail())
				{
					cout << "unable to open the file, file not found: " + _filename;
					continue;
				}
				else
				{
					char _c;
					int counter[128] = { 0 };
					while (file.get(_c))
					{
						for (int i = 0; i < 128; i++)
						{
							if (isprint((char)i))
								if (_c == (char)i && !isblank((char)i)) counter[i]++;
						}
					}

					for (int i = 0; i < 128; i++)
					{
						if (counter[i] != 0)
						{
							cout << (char)i << " has occured " << counter[i] << " times." << endl;
						}
					}

				}file.close();
				
				break;
			}
			return 0;
		}

		/* 
		5. File encryption is the science of writing the contents of a file in a secret code. Your encryption program
		should work like a filter, reading the contents of one file, modifying the information into a code, and then
		writing the coded contents out to a second file. The second file will be a version of the first file but written
		in a secret code.
		Although there are complex encryption techniques, you should come up with a simple one of your own.
		For example, you could read the first file one character at a time and add 10 to the ASCII code of each
		character before it is written to the second file.
		In addition, write a program that decrypts the file produced. The decryption program should read the
		contents of the coded file, restore the information to its original state, and write it to another file.
		 */
		int q_5()
		{
			constexpr auto KEY = 1010110;
			int src = 2000;
			cout << src << endl;
			int encode = encrypt(src, KEY);
			cout << encode << endl;
			int decode = decrypt(encode, KEY);
			cout << decode << endl;
			return 0;
		}
	}
}

#endif // !_SMS_PRACTICAL_SESSION_6_H_