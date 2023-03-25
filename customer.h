#include "Person.h"
#include "Appointment.h"

using namespace std;

class customer : public Person
{
private:
    string MechanicID;
    Appointment app;
    string mech_name;
    
public:
    customer();
    void set_mechid(string id);
    string get_mechid();
    void set_app(int hour , int min);
    Appointment get_app();
    void set_mechname(string name_mech);
    string get_mechname();
    bool operator==(customer cus2);
    bool operator >(customer cus2);
    bool operator < (customer cus2);
    
};


