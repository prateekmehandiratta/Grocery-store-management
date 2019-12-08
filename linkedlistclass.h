#pragma once
#include<iostream>
#include "itemsclass.h"
#include "fruitsclass.h"
#include "vegetablesclass.h"
#include "nodeclass.h"
using namespace std;

class linked_list
{
private:
    node* head;
    node* temp;
    node* curr;
public:
	node* headptr();
	linked_list();
	~linked_list();
	void add_item(items*);
	void remove_item(items*);
	void remove_item(node* );
	void store_details(void);
	int count_item(string,string);
	void area_items(int ,int ,int ,int );
	void calories(void);
	void add_item_dynam(void);
	void sell(void);
};
