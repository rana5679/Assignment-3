#ifndef Person_h
#define Person_h


#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string Name;
    string id;
    string Age;
    
public:
    Person();
    void set_Name(string &name);
    string get_Name();
    void set_id(string &n_id);
    string get_ID();
    void set_Age(string age);
    string get_age();
    void print_info();
    
};

#endif
