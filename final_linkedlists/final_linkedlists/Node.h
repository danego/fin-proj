//
//  Header.h
//  final_linkedlists
//
#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node
{
public:
    Node(string s);
private:
    string data;
    Node* previous;
    Node* next;
    friend class List;   // means that List and Iterator can access/ alter Node's privates
    friend class Iterator;
};
Node::Node(string s)
{
    data = s;
    previous = NULL;
    next = NULL;
}
#endif /* Header_h */
