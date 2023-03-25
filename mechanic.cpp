#include <stdio.h>
#include "mechanic.h"

using namespace std;

mechanic::mechanic() 
{
    counter=0;
}

void mechanic::set_counter(int count)
 {
    counter=count;
 }

int mechanic::get_counter()
{
    return counter;
}

void mechanic::set_book( Appointment val, int index)
{
        book[index]=val;
}

void mechanic::get_book(int index , int &hour , int &min)
{
    hour=book[index].hours;
    min=book[index].mins;
    
}

bool mechanic::IsAvailable(Appointment time)
{
    for(int n=0 ; n<counter ; n++)
    {
        if(book[n].hours==time.hours && book[n].mins==time.mins )
        {
            return false;
        }
    }
    
    return true;
}
