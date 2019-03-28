
#ifndef LIST_H
#define LIST_H

#include "Iterator.h"

class Iterator;

class List
{
public:
    List();
    void push_back(string data);
    void insert(Iterator pos, string data);     //how, from main, is Iterator position known???
    void print() const;
    void print_node(Iterator it) const;
    Iterator erase(Iterator position);
    Iterator begin();                            // how does this work exactly ...
    Iterator end();
    friend ostream & operator << (ostream & os, const List & lst);   // help dummy
    //friend ostream & operator << (ostream &os, const Iterator & it);
    
private:
    Node* first;
    Node* last;
    friend class Iterator;
};
List::List()
{
    first = NULL;
    //last = first;      //only need to adjust first adjustments right??
    last = NULL;
}
Iterator List::erase(Iterator pos)  //will delete node at Iter pos
{
    assert (pos.current != NULL);
    // Do I need remove Node dummy? or just pos.current?
    Node* before_node = pos.current->previous;
    Node*after_node = pos.current->next;
    
    if (pos.current == first)
        first = after_node;
    else
        before_node->next = after_node;
    if (pos.current == last)
        last = before_node;
    else
        after_node->previous = before_node;
    Iterator iter;
    iter.current = after_node;
    iter.container = this;
    return iter;
    
    
}
Iterator List::begin()
{
    Iterator iter;
    iter.current = first;
    iter.container = this;
    return iter;
}
Iterator List::end()
{
    Iterator iter;
    iter.current = NULL;   //why not Last?
    iter.container = this;
    return iter;
}
void List::push_back(string data)
{
    Node* new_node = new Node(data);
    if (last == NULL)                //why not first??
    {
        first = new_node;
        last = new_node;
    }
    else
    {
        new_node->previous = last;
        //new_node->next = NULL;                why wouldnt this work- I guess its extraneous and unnecessary
        last->next = new_node;
        last = new_node;
        last->next = first;
    }
}
void List::insert(Iterator pos, string data)   //will insert new node one before pos.current (ie selected spot)
{
    if (pos.current == NULL)      //if iter pos is at end, call push_back instead
        push_back(data);
    Node* after_node = pos.current;
    Node* before_node = after_node->previous;
    Node*new_node = new Node(data);
    new_node->next = after_node;
    new_node->previous = before_node;
    
    after_node->previous = new_node;
    if(before_node ==NULL)
        first = new_node;
    else
        before_node->next = new_node;
}

void List::print() const
{
    const Iterator it;    //why const
    Node*p = first;
    //p = p->next;
    do
    {
        cout<<p->data;
        cout <<": "<<p->next->data<<endl;
        p = p->next;
    } while (p !=first);
            
    //it = this->begin();                // why create a false node above and not use these lines? only bc const?
   // while(it.current != NULL)
       // cout<<it.current<<endl;
}

void List::print_node(Iterator it) const
{
    cout<<it.current<<endl;
    
}
ostream & operator << (ostream & os, const List & lst)
{
    lst.print();
    return os;
}
/*ostream & operator << (ostream & os, const Iterator & it)
{
    this.print(it);
    return os;
}
*/
#endif /* Header_h */
