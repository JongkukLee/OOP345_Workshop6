// OOP345 Workshop 6: Lambda Expressions
// File Grades.h
// Version 1.0
// Date 2017-07-07
// Author Jongkuk Lee ( jlee465@myseneca.ca, 127730158 )
// Description
//      declaration and implementation of variables and 
//            funtion prototype for Grades Class  
//	    - use a lambda expression to define an operation on a set of data values
//	    - prevent the copying, moving and assigning of an object
//      - throw and report an exception
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <exception>

class Grades
{
  // file name
  char* filename;
  // student information
  std::vector<std::vector<std::string>> studentsV;
public:
  // one parameter constructor
  Grades (const char * f): filename(nullptr)
  {
    if (f)
    {
      filename = new char[strlen(f) + 1];
      strcpy(this->filename, f);
      // memcpy(filename, f, (strlen(f) + 1) * sizeof(char));
    }

    try
    {
      // file open
      std::ifstream fs(this->filename, std::ios::in);

      if (!fs.is_open())
      {
        throw "This file cannot be open.";
      }
      else
      {
        std::string line;
        std::string field = "";
        std::vector<std::string> v;

        while (std::getline(fs, line))
        {
          std::cout << "Line -->" << line << "<--" << std::endl;
		  
          for (int i = 0; i < line.size(); i++)
          {
            field += line[i];
            if (line[i] == ' ' || i == (line.size() - 1) )
            {
				if(field[field.size() -1] == ' ')
					v.push_back(field.erase(field.size() - 1));
				else
					v.push_back(field);
			  std::cout << "Field[" << field << "]";
			  field = "";
            }
          }
		  std::cout << std::endl;
          this->studentsV.push_back(std::move(v));
        }
      }
    }
    catch (std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  // copy constructor
  Grades(const Grades&) = delete;
  // copy assignment constructor
  Grades& operator=(const Grades&) = delete;
  // move constructor
  Grades(const Grades&&) = delete;
  // move assignment constructor
  Grades&& operator=(const Grades&&) = delete;

  // receives a reference to the output stream object and the expression 
  // to be used in determining the letter grade.  Your function displays 
  // the student number, the student grade, and the letter equivalent as 
  // shown below on the right. 
  template<typename Func>
  void displayGrades(std::ostream& os, Func f) const
  {
	  for (auto it : studentsV)
	  {
		  for (auto e : it)
		  {
			  os << e << " ";
			  // display the letter equivalent as grade
			  if (e.find('.') != std::string::npos)
			  {
				  os << f(std::stod(e)) << "\n";
			  }
		  }
	  }
  }
};
