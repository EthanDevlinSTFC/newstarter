/**
 * Program to count words from a ascii file
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>

struct InvalidArguments : public std::exception {
	const char* what() const throw () {
		return "Invalid number of arguments, WordCounter.exe takes only a ascii text file as argument.";
	}
};

void remove_punctuation_in_string(std::string &data)
{
	// Remove all cases of punctuation in a line
	std::string puntuation{ ".,?!\'\"():;"};
	for (auto x : puntuation) {
		while (data.find(x) != std::string::npos) {
			data.replace(data.find(x), 1, " ");
		}
	}
	while (data.find("--") != std::string::npos) {
		data.replace(data.find("--"), 2, " ");
	}
	// Convert all letters in lower case
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return;
}

void print_map_by_value(std::map<std::string, int> map_to_print)
{
	std::ofstream result_file;
	result_file.open("word_count.txt");
	if (!result_file) {
		try {
			throw "Unable to open results file word_count.txt";
		}
		catch (const char* errtext) {
			std::cout << errtext;
			abort();
		}
	}
	result_file << std::setw(18) << "Word" << std::setw(12) << "Count" << std::endl;
	while (map_to_print.size() > 0) {
		// loop over word map
		std::string max_key;
		int max_val = 0;
		for (const auto& it : map_to_print) {
			if (it.second > max_val) {
				// find largest word count
				max_val = it.second;
				max_key = it.first;
			}
		}
		// save word and count to file
		result_file << std::setw(18) << max_key << std::setw(12) << max_val << std::endl;
		// remove largest count word from map
		map_to_print.erase(max_key);
	}
	result_file.close();
	return;
}

int main(int argc, char* argv[])
{
	std::ifstream ascii_file;
	std::string line;
	std::stringstream str_strm;
	std::string tmp;
	std::vector<std::string> words;
	std::map<std::string, int> word_count_map;
	// Check the number of parameters
	try {
		if (argc != 2) {
			throw InvalidArguments();
		}
	}
	catch(InvalidArguments& e) {
		std::cout << e.what() << std::endl;
		abort();
	}
	ascii_file.open(argv[1]);
	if (!ascii_file) {
		try {
			throw "Unable to open file ";
		}
		catch (const char* errtext) {
			std::cout << errtext << argv[1];
			abort();
		}
	}
	while (std::getline(ascii_file, line)) {
		remove_punctuation_in_string(line);
		str_strm << line << " ";
	}
	ascii_file.close();
	while (str_strm >> tmp) {
		words.push_back(tmp);
	}
	for (const auto& word : words) {
		if (word.size() > 4) {
			word_count_map[word]++;
		}
	}
	print_map_by_value(word_count_map);
	return 0;
}
