#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;


// Checks if number is negative
bool is_negative(const int& number)
{
	return number < 0;
}

// Returns number of 1 bits in the binary representation of a decimal number
int count_1_bits(int number)
{
	vector<unsigned int> my_bits;
	int number_of_1_bits = 0;
	while (number != 0)
	{
		unsigned int bit = number % 2;
		number /= 2;
		if (bit == 1)
		{
			++number_of_1_bits;
		}
		my_bits.push_back(bit);
	}
	return number_of_1_bits;
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	int number = 0;
	while (ifs >> number)
	{
		// Ignore negative numbers
		if (is_negative(number))
		{
			continue;
		}

		int number_of_1_bits = count_1_bits(number);

		cout << number_of_1_bits << endl;
	}

	return 0;
}