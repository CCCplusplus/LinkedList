

#include <iostream>
#include "List.hpp"

using namespace std;

//struct Node 
//{
//    int data;
//    Node* next;
//};
//
//void AddNode(Node*& head, int value)
//{
//    Node* newNode = newNode;
//    newNode->data = value;
//    newNode->next = nullptr;
//    if (head == nullptr)
//        head = newNode;
//    else 
//    {
//        Node* current = head;
//        while (current->next != nullptr) 
//        {
//            current = current->next;
//        }
//        current->next = newNode;
//    }
//}
//
//void PrintList(Node* head) 
//{
//    Node* Current = head;
//    while (Current != nullptr)
//    {
//        cout << Current->data << " ";
//        Current = Current->next;
//    }
//}

int main()
{
    /*Node* head = nullptr;
    AddNode(head, 1);
    AddNode(head, 2);
    AddNode(head, 3);
    AddNode(head, 4);
    AddNode(head, 5);
    PrintList(head);*/

    List* pokemons = new List();
    pokemons->AddNodeBack("Charizard");
    pokemons->AddNodeBack("Greninja");
    pokemons->AddNodeBack("Lucario");
    pokemons->AddNodeFront("Rayquaza");
    pokemons->AddNodeBack("Pikachu");
    pokemons->AddNodeAt("Charmander", 2);
    pokemons->AddNodeBack("Mimikyu");
    pokemons->ReverseList_Recursive();
    pokemons->DeleteNodeAt(4);
    pokemons->DeleteLast();
    pokemons->DeleteFirst();

    std::cout << pokemons->GetNodeAT(1)->value << endl;

    pokemons->PrintList();

    List* numbers = new List();
    numbers->AddNodeBack("12");
    numbers->AddNodeBack("24");
    numbers->AddNodeBack("36");
    numbers->AddNodeFront("12");
    numbers->AddNodeFront("24");
    numbers->AddNodeFront("36");
    numbers->AddNodeAt("48", 4);
    numbers->DeleteNodeAt(4);

    numbers->PrintList();
    return 0;
}