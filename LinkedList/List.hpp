#pragma once
#include "Node.hpp"
#include <iostream>

class List 
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	List();
	~List();
	void AddNodeBack(const std::string& data);
	void AddNodeFront(const std::string& data);
	void AddNodeAt(const std::string& data, const int& at);
	void DeleteNodeAt(const int& at);
	void DeleteLast();
	void DeleteFirst();
	void ReverseList_Iterative();
	void ReverseList_Recursive();
	void RecursiveReverse(Node* currentNode);
	Node* GetNodeAT(const int& at);
	void PrintList();
};

List::List() 
{
}

List::~List()
{
}


void List::PrintList() 
{
	if (head != nullptr) 
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << GetNodeAT(i)->value << std::endl;
		}
	}
}

void List::AddNodeBack(const std::string& data)
{
	Node* temp = new Node(data);
	if (head == nullptr)
	{
		head = tail = temp;
		size = 1;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp; //temp se vielve tail 
		size++;
	}
}


void List::AddNodeFront(const std::string& data)
{
	Node* temp = new Node(data);
	if (head == nullptr)
	{
		head = tail = temp;
		size = 1;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
		size++;
	}
}


inline void List::AddNodeAt(const std::string& data, const int& at)
{
	Node* temp = new Node(data);
	try
	{
		if (at >= 0 && at <= size)
		{
			if (at == 0)
				AddNodeFront(data);
			else if (at == size)
				AddNodeBack(data);
			else
			{
				Node* current = GetNodeAT(at);
				temp->next = current;
				temp->prev = current->prev;
				current->prev->next = temp;
				current->prev = temp;
				size++;
			}
		}
		else
		{
			throw std::out_of_range("ERROR: OUTSIDE OF LIST LIMIT\n");
		}
	}
	catch (std::out_of_range error)
	{
		std::cout << error.what();
	}
}


inline void List::DeleteNodeAt(const int& at)
{
	try
	{
		if (at >= 0 && at < size)
		{
			if (at == 0)
				DeleteFirst();
			else if (at == size - 1)
				DeleteLast();
			else
			{
				Node* toDelete = GetNodeAT(at);
				toDelete->prev->next = toDelete->next;
				toDelete->next->prev = toDelete->prev;
				delete toDelete;
				size--;
			}
		}
		else
		{
			throw std::out_of_range("ERROR: OUTSIDE OF LIST LIMITS\n");
		}
	}
	catch (std::out_of_range error)
	{
		std::cout << error.what();
	}
}


inline void List::DeleteLast()
{
	try
	{
		if (size > 1)
		{
			Node* newTail = tail->prev;
			delete tail;
			tail = newTail;
			tail->next = nullptr;
			size--;
		}
		else if (size == 1)
		{
			delete head;
			head = tail = nullptr;
			size = 0;
		}
		else
		{
			throw std::length_error("ERROR: EMPTY LIST\n");
		}
	}
	catch (std::length_error error)
	{
		std::cout << error.what();
	}
}


inline void List::DeleteFirst()
{
	try
	{
		if (size > 1)
		{
			Node* newHead = head->next;
			delete head;
			head = newHead;
			head->prev = nullptr;
			size--;
		}
		else if (size == 1)
		{
			delete head;
			head = tail = nullptr;
			size = 0;
		}
		else
		{
			throw std::length_error("ERROR: EMPTY LIST\n");
		}
	}
	catch (std::length_error error)
	{
		std::cout << error.what();
	}
}


inline void List::ReverseList_Iterative()
{
	if (head != nullptr)
	{
		Node* currentNode = head;
		Node* previousNode = nullptr;
		Node* nextNode = nullptr;
		while (currentNode != nullptr)
		{
			nextNode = currentNode->next;
			currentNode->next = previousNode;
			currentNode->prev = nextNode;
			previousNode = currentNode;
			currentNode = nextNode;
		}
		tail = head;
		head = previousNode;
	}
}


inline void List::ReverseList_Recursive()
{
	try
	{
		if (head != nullptr) {
			tail = head;
			RecursiveReverse(head);
			tail->next = nullptr; // Aseguramos que el último nodo apunte a nullptr
		}
		else
		{
			throw std::length_error("ERROR: EMPTY LIST\n");
		}
	}
	catch (std::length_error error)
	{
		std::cout << error.what();
	}
}


inline void List::RecursiveReverse(Node* currentNode)
{
	if (currentNode->next == nullptr) {
		head = currentNode;
		return;
	}
	RecursiveReverse(currentNode->next);
	Node* nextNode = currentNode->next;
	nextNode->next = currentNode;
	currentNode->prev = nextNode;
	currentNode->next = nullptr;  // hmm podría sacar esto? estaba antes... pero no se necesita.
}

inline Node* List::GetNodeAT(const int& at) //no necesita cambiar funciona con la doble linked list.
{
	try {
		Node* temp = head;
		int index = 0;
		while (temp != nullptr) 
		{
			if (index == at)
				return temp;
			index++;
			temp = temp->next;
		}
		throw std::out_of_range("ERROR: OUTSIDE OF LIST LIMITS\n");
	}
	catch (std::out_of_range error) 
	{
		std::cout << error.what();
	}
	return nullptr;
}