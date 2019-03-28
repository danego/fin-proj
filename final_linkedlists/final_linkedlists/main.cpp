//
//  Final Review - Linked Lists

#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <cassert>
#include <cmath>
#include "Node.h"
#include "List.h"
#include "Iterator.h"
//#include "List.h"

using namespace std;

 class List;          //is this all you need to state it before?
 class Iterator;
//class Node;


 void random_lister (List & lst, List & new_list, int random)  //do random number generator for 0 -> end of vector
{
    srand((unsigned)time(NULL));
    int number;
    Iterator it;
    Iterator new_it;
    new_it = new_list.begin();
    do
    {
        if (random > 1)
        {
            number = (rand() % (random-1) + 0);
            it = lst.begin();
            for (int i = 0; i < number; i ++)
                it.next();
            //cout<<number<<" ,name: "<<(it.get())<<endl;
            new_list.push_back(it.get());
            lst.erase(it);
            random --;
        }
        else
        {
            number = 0;
            it = lst.begin();
            //cout<<number<<" ,name: "<<(it.get())<<endl;
            new_list.push_back(it.get());
            lst.erase(it);
            random = 0;
           
        }
            
    } while (random > 0);
    
}

void name_check (string name, Iterator & iter, int name_count)
{
    string recurs_cont;
    string check;
    int new_count = 0;
    do
    {
        check = iter.get();
        if (check == name){
            iter.next();
            cout<<"\nYou have "<<(iter.get())<<" as your secret valentine!"<<endl;
            return;
        }
        else
        {
            iter.next();
            new_count ++;
        }
    } while (new_count <= name_count);
    
    cout<<"Your name did not match our records, try again? (y/n)"<<endl;
    cin>>recurs_cont;
    cin.ignore();
    if (recurs_cont == "y"){
        cout<<"Enter your name again, extra carefully love: ";
        getline(cin,recurs_cont);
        name_check(recurs_cont, iter, name_count);
    }
    else
        return;
}

//heart output optional

int main ()
{
    List mylist;
    int name_count = 0;
    string name;
    ifstream myfile;
    myfile.open("names.txt");
    while (!myfile.eof())
    {
        getline(myfile, name);
        mylist.push_back(name);
        name_count ++;
        //names.push_back(name);
    }
    List new_list;      //randomized contents of old list
    random_lister(mylist, new_list, name_count);
    new_list.print();
    
    //+++++++++++++++++++++++++
    
    Iterator iter;
    iter = new_list.begin();
    string new_name;
    bool loop;
    do
    {
        cout<<"Enter your name to find out your secret valentine: ";
        getline (cin,new_name);
        name_check(new_name, iter, name_count);
        cout<<"\n\nAnother name? (y/n)"<<endl;
        getline (cin, new_name);
        if (new_name == "y")
            loop = true;
        else if (new_name == "n")
            loop = false;
        else
            loop = true;
        //heart();
    } while (loop);
    
    
    //cout<<(iter.current->next->data);  //how to create a printer for one node? - ie print dane's valentine, getline etc
    //or just have people line up in order from text file???
    //cout<<new_list<<endl;
    //cout<<mylist<<endl;
    
    return 0;
}








