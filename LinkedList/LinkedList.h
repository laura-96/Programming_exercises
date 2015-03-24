#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>

template <class TYPE>

struct Node{

	TYPE data;
	Node<TYPE> *prev;
	Node<TYPE> *next;

	inline Node(const TYPE &_data){
		data = _data;
		next = NULL;
		prev = NULL;
	}
};

template <class TYPE>

class LinkedList{

public:

	Node<TYPE>* start;
	Node<TYPE>* end;

private:
	unsigned int size; //It is private because external changes wouldn't be convinient

public:
	//Constructor:
	inline LinkedList(): size(0), start(NULL), end(NULL) {}

	unsigned int Count() const;
	unsigned int Add(const TYPE &item){
		
		Node<TYPE>* item_pointer;
		item_pointer = new Node<TYPE>(item); //It builds the Node from the inline constructor we put in the structure, so now, data = item.

		if (start == NULL){
			start = end = item_pointer;
		}

		else{
			item_pointer->prev = end;
			end->next = item_pointer;
			end = item_pointer;
		}
		return(++size);
	}

	void Delete(Node<TYPE>* item){
		if (item != NULL){
			
			if (item->prev != NULL){
				item->prev->next = item->next;
				
				if (item->next != NULL){
					item->next->prev = item->prev;
				}

				else end = item->prev;
			}

			else{
				
				if (item->next != NULL){
					item->next->prev = NULL;
					start = item->next;
				}
				else{
					start = end = NULL;
				}
			}

			delete item;
			--size;
		}
	}

	//Function to free all memory:
	void Clear(){
		Node<TYPE>* data_pointer;
		Node<TYPE>* next_pointer;

		data_pointer = start;
		while (data_pointer != NULL){

			next_pointer = data_pointer->next;
			delete data_pointer;
			data_pointer = next_pointer;
		}

		start = end = NULL;
		size = 0;
	}

	//Destructor:
	~LinkedList{

		Clear();
	}
};

#endif