#pragma once
#include<iostream>
using namespace std;

class items
{
protected:
    long purchase_ID ;
    int location_x;
    int location_y;
    string purchase_time;
    int calories;
public:
    friend class linked_list;
    friend class node;
    bool operator == (items & i2);
    items(int ,int );
    virtual void print(void);
    virtual void update(void);
};


