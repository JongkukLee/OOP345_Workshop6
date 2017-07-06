// OOP345 Workshop 6: Lambda Expressions
// File w6.cpp
// Version 1.0
// Date 2017-07-07
// Author Jongkuk Lee ( jlee465@myseneca.ca, 127730158 )
// Description
//      This file is a test file for Workshop6.
//	    - define the lambda expression for letter
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {

	argc = 2;
	argv[0] = "W6";
	argv[1] = "w6.dat";

  if (argc != 2) {
    std::cerr << argv[0] <<
      ": incorrect number of arguments\n";
    std::cerr << "Usage: " << argv[0] << " file_name\n";
    return 1;
  }


  Grades grades(argv[1]);
  // define the lambda expression for letter
  auto letter = [](double grade) {
    char* let;
    if (90.0 <= grade && grade <= 100.0)     let = "A +";
    else if (80.0 <= grade && grade <= 89.9) let = "A";
    else if (75.0 <= grade && grade <= 79.9) let = "B +";
    else if (70.0 <= grade && grade <= 74.9) let = "B";
    else if (65.0 <= grade && grade <= 69.9) let = "C +";
    else if (60.0 <= grade && grade <= 64.9) let = "C";
    else if (55.0 <= grade && grade <= 59.9) let = "D +";
    else if (50.0 <= grade && grade <= 54.9) let = "D";
    else if (0.0  <= grade && grade <= 49.9) let = "F";

    return let;
  };

  grades.displayGrades(std::cout, letter);

  std::cout << "Press any key to continue ... ";
  std::cin.get();
}
