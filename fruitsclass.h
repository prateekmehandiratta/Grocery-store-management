#pragma once
#include<iostream>
#include "itemsclass.h"
using namespace std;

class fruits:public items
{
private:
    string type;
    float weight_per_unit;
    int price_per_unit;
    int units;
public:
    fruits(int ,int ,string ,float ,int ,int ,int );
    void print(void);
    void update(int);
    friend class linked_list;
    friend class node;
};

