#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Appointment.h"
#include "Person.h"
#include "mechanic.h"
#include "customer.h"
#include "Queue.h"


#ifndef main_cpp
#define main_cpp



using namespace std;

void swap(customer &cus1 , customer &cus2)
{
    customer temp;
    temp=cus1;
    cus1=cus2;
    cus2=temp;
}

void find_mech(string id , int size , mechanic array[] , int &index)
{
    for(int m=0 ; m<size ; m++)
    {
        if(id==array[m].get_ID())
        {
            index=m;
        }
    }

}


int main()
{
    
    
    int size_mech, size_cus;
    string name_mech,name_cus,ID_mech,ID_cus,age_mech,age_cus;
    int hour_cus,min_cus;
    
    cout<<"Enter the number of mechanics available"<<endl; // gets the number of mechanic available
    cin>>size_mech;

    
    mechanic arr_mech[size_mech];
    
    
    for(int i=0 ; i<size_mech ; i++)  // fills the array of mechanics with details about each mechanic
    {
            cout<<"Enter the name of the mechanic"<<endl;
            cin>>name_mech;
            arr_mech[i].set_Name(name_mech);
            
            cout<<"Enter the id of the mechanic"<<endl;
            cin>>ID_mech;
            arr_mech[i].set_id(ID_mech);
         
            cout<<"Enter the age of the mechanic"<<endl;
            cin>>age_mech;
            arr_mech[i].set_Age(age_mech);
        
        
    }
    
    cout<<"Enter the number of customers for today"<<endl; // gets the number of customers avaliable today
    cin>>size_cus;
    
    customer arr_cus[size_cus];
    
    
    for(int i=0 ; i<size_cus ; i++)
    {
            cout<<"Enter the name of the customer"<<endl;
            cin>>name_cus;
            arr_cus[i].set_Name(name_cus);
            
            cout<<"Enter the id of the customer"<<endl;
            cin>>ID_cus;
            arr_cus[i].set_id(ID_cus);
         
            cout<<"Enter the age of the customer"<<endl;
            cin>>age_cus;
            arr_cus[i].set_Age(age_cus);
        
            cout<<"Enter the appointment of the customer"<<endl;
            cin>>hour_cus>>min_cus;
            arr_cus[i].set_app(hour_cus, min_cus);
        
        
    }
    
    int num_cus=0;
    int count=0;
   
    for(int i=0 ; i<size_cus ; i++) // finds a mechanic for each customer
    {
        while(count<size_mech && arr_cus[i].get_mechid()=="")
        {
            if(arr_mech[count].get_counter()==0)
            {
                num_cus++;
                arr_mech[count].set_counter(num_cus);
                arr_mech[count].set_book(arr_cus[i].get_app(), num_cus-1);
                arr_cus[i].set_mechid(arr_mech[count].get_ID());
                arr_cus[i].set_mechname(arr_mech[count].get_Name());
                break;
            }
            else if(arr_mech[count].get_counter()!=0)
            {
                if(arr_mech[count].IsAvailable(arr_cus[i].get_app()))
                {
                    num_cus++;
                    arr_mech[count].set_counter(num_cus);
                    arr_mech[count].set_book(arr_cus[i].get_app(), num_cus-1);
                    arr_cus[i].set_mechid(arr_mech[count].get_ID());
                    arr_cus[i].set_mechname(arr_mech[count].get_Name());
                    break;
                }
            }
                count++;
        }
        
        
    }
    
    
    for(int k=0 ; k<size_cus ; k++) // arranges the appointments of the customers in order
     {
         for(int p=0 ; p<size_cus-1 ; p++)
         {
             if(arr_cus[p]>arr_cus[p+1])
                 swap(arr_cus[p],arr_cus[p+1]);
         }
     }
     
     Queue <customer> customer_line(size_cus); // creates a queue of the customers
     
     for(int k=0 ; k<size_cus ; k++)
     {
         customer_line.push(arr_cus[k]);
     }
    
    customer x;
    int index_mech;
    string id_mech;
    string mechanicName;
    
    for(int i=0 ; i<size_cus ;i++) // prints the deatils of each appointment
    {
        customer_line.pop(x);
        id_mech=x.get_mechid();
        
        if(id_mech=="")
        {
            cout<<"There is no mechanic available at the moment for Mr/Mrs "<<x.get_Name()<<endl;
        }
        else
        {
            find_mech(id_mech, size_mech , arr_mech , index_mech);
            mechanicName=x.get_mechname();
            cout<<"Mr/Mrs "<<x.get_Name()<<" Has an appointment with the mechanic "<<mechanicName<<" at time "<<x.get_app().hours<<":"<<x.get_app().mins<<endl;
        }
    }
    
   
}

#endif

