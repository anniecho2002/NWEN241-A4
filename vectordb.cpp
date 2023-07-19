/**
 * vectordb.cpp
 * C++ source file that should contain implementation for member functions
 * - rows()
 * - get()
 * - add()
 * - update()
 * - remove()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Task 3)
 */ 

#include "vectordb.hpp"
using namespace nwen;

	unsigned int VectorDbTable::rows() const{
		return movies.size(); // returns num of rows
	}

	const movie* VectorDbTable::get(int row) const{
		if(movies.size() == 0) return NULL; // returns null if database is empty
		else if(row < 0 || row > movies.size()) return NULL; // returns null if row is not within boundaries of database
		const movie* p = &(movies.at(row));
		return p;
	}
	

	bool VectorDbTable::add(movie m){
		unsigned long id = m.id;
		for(int i = 0; i < movies.size(); i++){
			if(movies[i].id == id){
				return false; // there already exists a record with the same id
			}
		}
		movies.push_back(m);
		return true;
	}

	// if it doesnt work, try use -> on all the values
	bool VectorDbTable::update(unsigned long id, movie m){
		// searches through all the movie records to find an id match
		for(int i = 0; i < movies.size(); i++){
			if(movies[i].id == id){
				movies[i] = m;
				return true; // returns true if successfully updated
			}
		}
		return false;
	}


	// removes the value
	bool VectorDbTable::remove(unsigned long id){
		for (vector<movie>::iterator it = movies.begin(); it < movies.end(); ++it) {
            if (it->id == id) {
                movies.erase(it);
                return true; // successful removal
            }
        }
        return false;
	}

