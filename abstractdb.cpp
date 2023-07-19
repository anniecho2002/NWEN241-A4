/**
 * abstractdb.cpp
 * C++ source file that should contain implementation for member functions
 * - loadCSV()
 * - saveCSV()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Tasks 4 and 5)
 */ 


#include <iostream>
#include <fstream>
#include <sstream> // std::stringstream
#include <cstring>
#include "abstractdb.hpp"
#include "vectordb.hpp"

using namespace std;
namespace nwen{
	
	/**
	 * Implementation for the saveCSV function in AbstractDbTable
	 * */
	bool AbstractDbTable::saveCSV(string filename){
		
		ofstream output; // creates a filestream object for output
		output.open(filename, ios::out); // trunc will empty the file
	
		if(!output.is_open() || output.bad()){
			cerr<<"Failed to open file/errors encountered" << endl;
			return false; // if the file is not open, return false	
		}
		
		unsigned int rowNum = rows();
		for(int i = 0; i < rowNum; i++){
			const movie* m = get(i);
			output << m->id << "," << m->title << "," << m->year << "," << m->director << endl;
			// iterate through all the movies and put it into output file
		}
		output.close();
		return true;
	}
	
	
	/**
	 * Implementation for the loadCSV function in AbstractDbTable
	 * */
	bool AbstractDbTable::loadCSV(string filename) {
		
		ifstream input; // opens a filestream object for reading
		input.open(filename, ios::in);
		
		if(!input.is_open() || input.bad()){
			cerr<<"Failed to open file." << endl;
			return false; // if the file is not open, return false	
		}
		
		string line;
		while(getline(input, line)){
			string tokens[4]; // tokens[0] = id, [1] = title, [2] = year, [3] = director
			int count = 0;
			
			string token; 
			istringstream linestream(line);
			while(getline(linestream, token , ',')){
				// comma delimiter for parsing
				if(count > 3){
					cerr << "Error: Line has too many tokens." << endl;
					input.close();
					return false;
				}
				tokens[count++] = token;
			}
			
			
			
			bool error = false;
			// checking for potential errors (too few tokens, too many characters in tokens)
			if(count < 4){
				cerr << "Error: Line has too few tokens." << endl; 
				error = true;
			}
			if(tokens[1].size() >= 50 || tokens[3].size() >= 50){
				cerr << "Error: String is too long." << endl;
				error = true;
			}
			if(error == true){
				input.close();
				return false;
			}
			
			
			try{
				// construct the movie object, add to database
				movie mov;
				mov.id = stoul(tokens[0], nullptr, 10); // stoul function converts to an int
				mov.year = (unsigned short) stoul(tokens[2], nullptr, 10);
				strcpy(mov.title, tokens[1].c_str());
				strcpy(mov.director, tokens[3].c_str());
				add(mov);
			}
			catch(exception &e){
				cerr << "Error : The token couldn't be parsed." << endl;
				input.close();
				return false;
			}
		}
		input.close();
        return true; // successfully loadedthe csv
    }
	
}
	

