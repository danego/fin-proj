
#ifndef ITERATOR_H
#define ITERATOR_H

//#include "List.h"
//#include <string>
//class List;

class List;

class Iterator
{
public:
    Iterator();
    string get() const;
    void next();                    //overload with ++
    void previous();                //overload with --
    bool equals (Iterator b)const;  //this is where you'd overload = probably
private:
    Node* current;
    List* container;        //mainly for accesiblity from main? Or why does class NOde not need reference class List??
    friend class List;
};
Iterator::Iterator()
{
    current = NULL;
    container = NULL;
}
void Iterator::next()
{
    assert (current != NULL);    //will do nothing if cond is true
    current = current->next;
}
void Iterator::previous()
{
    //assert(current->previous != NULL);           NO - use first instead
    //assert(current != container->first);
    //if (current == NULL)                           //ie at end
        //current = container->last;                  // resolve this for header files 
    current = current->previous;
}
string Iterator::get() const
{
    assert(current != NULL);
    return current->data;
}
bool Iterator:: equals(Iterator B)const  //what does this even do? Its in iterator class so not accessbile by main ...
{
    return current == B.current;
}
#endif /* Header_h */
