#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

#include "_CSVWriter.h"
 
/*
 * This Function accepts a range and appends all the elements in the range
 * to the last row, seperated by delimeter (Default is comma)
 */
template<typename T>
void CSVWriter::addDatainRow(T first, T last)
{
	//linesCount = 0;
	std::fstream file;
	// Open the file in truncate mode if first line else in Append Mode
	file.open(fileName, std::ios::out | (linesCount ? std::ios::app : std::ios::trunc));
 
	// Iterate over the range and add each lement to file seperated by delimeter.
	for (; first != last; )
	{
		file << *first;
		if (++first != last)
			file << delimeter;
	}
	file << "\n";
	linesCount++;
 
	// Close the file
	file.close();
}
template void CSVWriter::addDatainRow(std::vector<std::string>::iterator, std::vector<std::string>::iterator);
template void CSVWriter::addDatainRow(std::deque<std::string>::iterator, std::deque<std::string>::iterator);
template void CSVWriter::addDatainRow(std::list<std::string>::iterator, std::list<std::string>::iterator);

template <typename T>
T CSVWriter::minimum (T a, T b)
{
	return a<b ? a : b;
}
template int CSVWriter::minimum(int,int);