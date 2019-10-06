#pragma once 
#include <memory> // used for strcmp
#include "GString.h"

// simple linked list based dictionary
template<class T, class U >
class Dictionary {
private:
	// used to pair a key with a value, it contains fields used to implement a simple linked list 
	class Pair {
	public:
		Pair(T k, U v) {
			this->key = k;
			this->value = v;
			prev = nullptr;
			next = nullptr;
		}
		T key;
		U value;
		Pair* prev;
		Pair* next;
	}*root;
public:
	//init dic
	Dictionary() {
		root = nullptr;
	}
	 
	//add an item to the dictionary
	bool set(T k, U v)
	{
		if (root == nullptr) {
			root = new Pair(k, v);
			return true;
		}
		else {
			Pair* tmp = root;
			Pair* last = root;
			while (tmp)
			{
				//is key is string cmp 
				if (comp(k, tmp->key)) return  false;

				last = tmp;
				tmp = tmp->next;
			}
			last->next = new Pair(k, v);
			return true;
		}
	}
	  
	bool comp(GString* f, GString* s) {
		return *f == *s;
	}

	bool comp( GString& f, GString& s) {
		return f == s;
	}

	// used if keys are null terminated strings
	bool comp(const char* f, const char* s) {
		if (strcmp(f, s) == 0) return true;
		return false;
	}

	//used if keys are numbers
	bool comp(int f, int s) {
		if (f == s) return true;
		return false;
	}

	// looks for the given key if found return it
	U get(T k) {
		Pair* tmp = root;
		while (tmp)
		{
			//is key is string cmp 
			if (comp(k, tmp->key)) return tmp->value;

			tmp = tmp->next;
		}

		return 0;
	}

	//check if the following key is the dic
	bool contains(T k) {
		Pair* tmp = root;
		while (tmp)
		{
			//is key is string cmp 
			if (comp(k, tmp->key)) return true;

			tmp = tmp->next;
		}
		return false;
	}
};

