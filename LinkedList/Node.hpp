#pragma once
#include "string"

class Node 
{
public:
	std::string value;
	Node* next;
	Node* prev;
	Node(const std::string& value);
};

Node::Node(const std::string& value) 
{
	this->value = value;
	this->next = nullptr; //el valor de ambos se los pongo en la List
	this->prev = nullptr;
}