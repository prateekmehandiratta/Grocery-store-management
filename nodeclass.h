#pragma once
#include<iostream>
#include "itemsclass.h"
#include "fruitsclass.h"
#include "vegetablesclass.h"
#include "mainHeader.h"
using namespace std;

class node
{
private:
    items* item;
    node* next;
public:
	friend class linked_list;
};

