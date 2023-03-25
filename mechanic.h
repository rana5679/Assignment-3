#ifndef mechanic_h
#define mechanic_h

#include "Person.h"
#include "Appointment.h"

using namespace std;

class mechanic : public Person
{
private:
    int counter;
    Appointment book[];
    
public:
    mechanic();
    void set_counter(int count);
    int get_counter();
    void set_book( Appointment val , int index);
    void get_book(int index , int &hour , int &min);
    bool IsAvailable(Appointment time);
};

#endif


