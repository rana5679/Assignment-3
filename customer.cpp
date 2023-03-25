#include <stdio.h>
#include "customer.h"

using namespace std;

customer::customer()
{
    MechanicID="";
}


void customer::set_mechid(string id)
{
    MechanicID=id;
}

string customer::get_mechid()
{
    return MechanicID;
}

void customer::set_app(int hour , int min)
{
    app.hours=hour;
    app.mins=min;
}

Appointment customer::get_app()
{
    return this->app;
}

void customer::set_mechname(string name_mech)
{
    mech_name=name_mech;
}

string customer::get_mechname()
{
    return mech_name;
}

bool customer::operator==(customer cus2) // checks if two customers have the same time
{
    if(app.hours==cus2.app.hours && app.mins==cus2.app.mins)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool customer::operator >(customer cus2) // checks who customer has an appointment before the other
{
    if(app.hours>cus2.app.hours )
    {
        return true;
    }
    
    return false;
   
}

bool customer::operator < (customer cus2)
{
    if(app.hours<cus2.app.hours )
    {
        return true;
    }
    
    return false;
   
}
