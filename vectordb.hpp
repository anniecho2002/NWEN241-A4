/**
 * vectordb.hpp
 * C++ header file that should contain declaration for
 * - VectorDbTable class
 * 
 * You need to modify this file to declare VectorDbTable class 
 * as specified in the hand-out (Task 2)
 */ 
 
#ifndef __VECTOR_DB_HPP__
#define __VECTOR_DB_HPP__
 
 
#include "abstractdb.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
namespace nwen {
	
	class VectorDbTable : public AbstractDbTable {
		public:
			unsigned int rows() const;              
			const movie* get(int) const; 
			bool add(movie);
			bool update(unsigned long, movie);
			bool remove(unsigned long); 
			
		private:
			vector<movie> movies; // vector to store the movies
	};
}

#endif //__VECTOR_DB_HPP__
 




