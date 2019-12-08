#pragma once
#include<iostream>
#include "itemsclass.h"
using namespace std;

class vegetables:public items
{
private:
    string type;
    int price_per_kg;
    int volume_per_kg;
    int amount_in_kg;
public:
    vegetables(int ,int ,string ,int ,int ,int ,int );
    void print(void);
    void update(int);
    friend class linked_list;
    friend class node;
};

