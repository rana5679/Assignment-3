#ifndef Queue_h
#define Queue_h

#include <iostream>
template <typename  T>


class Queue
{
private:
    int count;
    int top;
    int bottom;
    int Maxsize;
    T* values;
    
public:
    Queue(int size)
    {
        count=0;
        top=0;
        bottom=-1;
        Maxsize=size;
        values= new T[size];
    }
    
    ~Queue()
    {
        delete [] values;
    }
    
    bool isEmpty()
    {
        if(count==0)
        {
            return true;
        }
        
        return false;
            
    }
    
    bool isFull()
    {
        if(count==Maxsize)
        {
            return true;
        }
        
        return false;
    }
    
    void push(T x)
    {
        if(isFull())
        {
            std::cout<<"The queue is full you cant add more";
        }
        else
        {
            bottom=(bottom+1)%Maxsize;
            values[bottom]=x;
            count++;
            
        }
    }
    
    void pop(T &x)
    {
        if(isEmpty())
        {
            std::cout<<"Error there is no element to pop";
        }
        else
        {
            x=values[top];
            top=(top+1) % Maxsize;
            count--;
        }
        
    }
    
    void display_queue()
    {
        std::cout << "top -->";
        for (int i = 0; i < count; i++)
        {
            if (i == 0) std::cout << "\t";
            else        std::cout << "\t\t";
            std::cout << values[(top + i) % Maxsize];
            if (i != count - 1)
                std::cout << std::endl;
            else
                std::cout << "\t<-- bottom" << std::endl;
        }
    }
    
    
};

#endif
