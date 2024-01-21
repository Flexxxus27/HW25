﻿#include <iostream>
#include <string>


bool polindrome(std::string str);

int marks(std::string str);

std::string search(std::string str, char sym);


int main() {
	system("chcp 1251>null");
	int n;

	//Задание 1.
	std::cout << "Задание 1.\n\n";
	std::string str = "Hello world!";
	std::cout << str << '\n';
	std::cout << "Введите символ -> ";
	char sym;
	std::cin >> sym;
	std::string new_str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == sym)
			new_str += sym;
	}
	std::cout << new_str << std::endl;

	//Задане 2.
	std::cin.ignore();
	std::cout << "Задание 2.\n\n";
	std::cout << "Введите слово -> ";
	std::string str1;
	std::getline(std::cin, str1);
	
	if (polindrome(str1))
		std::cout << str1 << " - полиндром!\n\n";
	else
		std::cout << str1 << " - не полиндром!\n\n";
	
	//Задание 3.
	std::cout << "Задание 3.\n\n";
	std::cout << "Введите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	std::cout << "В этой строке " << marks(str2) << " знаков препинания.\n\n";

	//Задание 4.
	std::cout << "Задание 4.\n\n";
	std::cout << "Введите строку -> ";
	std::string str3;
	std::getline(std::cin, str3);
	std::cout << "Введите символ -> ";
	char sym1;
	std::cin >> sym1;
	std::cout << std::endl;
	std::cout << search(str3, sym1) << std::endl;





	return 0;
}

bool polindrome(std::string str) {
	bool pol = true;

	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	for (int i = 0; i < str.length() / 2; i++)
		if (str[i] != str[str.length() - i - 1])
			pol = false;
	return pol;
}

int marks(std::string str) {
	int counter = 0;
	const int size = 5;
	const char sym[size]{
		'!',
		'?',
		'.',
		',',
		' '
	};

	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < size; j++)
			if (str[i] == sym[j])
				counter++;
	}
	return counter;
}


std::string search(std::string str, char sym) {	
	for (int i = 0; i < str.length(); i++) 
		if (str[i] == sym)
			return str.substr(str.rfind(sym));
	str.erase();
	return str;
}