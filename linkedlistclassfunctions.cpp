#include<iostream>
#include "itemsclass.h"
#include "fruitsclass.h"
#include "vegetablesclass.h"
#include "nodeclass.h"
#include "linkedlistclass.h"
#include<stdio.h>
#include<stdlib.h>
#include "mainHeader.h"

using namespace std;


linked_list::linked_list()
    {
        head = NULL;
    }

linked_list::~linked_list()
    {
        while(head!=NULL)
        {
            temp = head;
            head = temp->next;
            delete temp;
        }
    }

void linked_list::add_item(items* i)
    {
        node* n = new node;
        n->item = i;
        if(head == NULL)
        {
            head = n;
            n->next = NULL;
            return;
        }
        n->next = head;
        head = n;
    }

void linked_list::remove_item(items *i)
    {
        temp=head;
        if(temp->item == i)
        {
            head = temp->next;
            delete temp;
            return;
        }
        while(!(temp->next->item == i))
        {
            temp = temp->next;
        }
        curr = temp->next ;
        temp->next = curr->next;
        delete curr;
    }

void linked_list::remove_item(node* n)
    {
        temp =head;
        while(temp->next!=n)
        {
            temp = temp->next;
        }
        temp->next = n->next;
        delete n;
    }

void linked_list::store_details()
    {
        cout << "\t\tSTORE DETAILS:\n" << endl;
        temp = head;
        while(temp!=NULL)
        {
            temp->item->print();
            cout << "\n";
            temp = temp->next;
        }
    }

int linked_list::count_item(string t1,string t2)
    {
        if(t1 == "fruit")
        {
            int u = 0;
            temp = head;
            while(temp!=NULL)
            {
                if(((fruits*)temp->item)->type == t2)
                {
                    u += ((fruits*)temp->item)->units;
                }
            temp = temp->next;
            }
        return u;
        }
        else
        {
            int a = 0;
            temp = head;
            while(temp!=NULL)
            {
                if(((vegetables*)temp->item)->type == t2)
                {
                    a += ((vegetables*)temp->item)->amount_in_kg;
                }
                temp = temp->next;
            }
            cout << "Amount of " << t2 << " is " << a << " KG" << endl;
            return a;
        }
    }

void linked_list::area_items(int a,int b,int c,int d)
    {
        int check=0;
        temp = head;
        cout << "ITEMS IN THIS AREA WITH THEIR DETAILS:\n\n\n\n" << endl;
        while(temp!=NULL)
        {
            int x = temp->item->location_x;
            int y = temp->item->location_y;
            if(x>=a && x<=c && y>=b && y<=d)
            {
                check = 1;
                temp->item->print();
            }
            temp=temp->next;
        }
        if(check == 0)
        {
            cout << "NO ITEM IN THAT AREA" << endl;
        }
    }

 void linked_list::calories()
    {
        int cal;
        cout << "Calories - ";
        cin >> cal;
        int minc = cal;
        temp = head;
        while(temp!=NULL)
        {
            if((temp->item->calories) < minc)
            {
                minc = (temp->item->calories);
                curr=temp;
            }
            temp = temp->next;
        }
        int u = cal / minc;
        cout << "Max units you can have is " << u << endl;
    }


 void linked_list::add_item_dynam()
    {
        string i;
        cout << "What do you want to add in the store, fruits or vegetables? : ";
        cin >> i;
        if(i == "fruits")
        {
            string t;
            int x,y,p,c,u;
            float w;
            cout << "Enter the details: type  location_x  location_y  weight_per_unit  price_per_unit  calories  units" << endl;
            cin >> t >> x >> y >> w >> p >> c >> u;
            items* i1;
            i1 = new fruits(x,y,t,w,c,p,u);
            add_item(i1);
        }
        else
        {
            string t;
            int x,y,p,vol,a,c;
            cout << "Enter the details: type  location_x  location_y  price_per_kg  calories volume_per_kg  amount_in_kg" << endl;
            cin >> t >> x >> y >> p >> c >> vol >> a;
            items* i1;
            i1 = new vegetables(x,y,t,c,p,vol,a);
            add_item(i1);
        }
    }

 void linked_list::sell()
    {
        cout << "What do you want to buy,fruits or vegetables?";
        string i;
        cin >> i;
        if(i == "fruits")
        {
            cout << "Which fruit and how much?";
            string t;
            int counti,minc = 50000,dist = 1000000;
            cin >> t >> counti;
            int pay =0;
            temp = head;
            curr = NULL;
            while(temp!=NULL)
            {
                if((((fruits*)(temp->item))->type) == t)
                {
                    int x1 = temp->item->location_x;
                    int y1 = temp->item->location_y;
                    int d = (x1*x1) + (y1*y1);
                    if(d<dist)
                    {
                        dist = d;
                        minc = ((fruits*)(temp->item))->price_per_unit;
                        curr = temp;
                    }
                    if(d == dist)
                    {
                        if((((fruits*)(temp->item))->price_per_unit) < minc )
                        {
                            minc = ((fruits*)(temp->item))->price_per_unit;
                            curr = temp;
                        }
                    }
                }
                temp = temp->next;
            }
            if (curr == NULL)
            {
                cout << "Out of stock";
                return ;
            }
            if( ((fruits*)(curr->item))->units < counti)
            {
                pay = (((fruits*)(curr->item))->units)  * (minc);
                cout << "We have only " << ((fruits*)(curr->item))->units << " units with the minimum rate" << endl;
                cout << "pay" << pay << " for " << ((fruits*)(curr->item))->units  << " units." << endl;
                remove_item(curr->item);
            }
            else
            {
                pay = (counti) *(minc);
                cout << "pay " << pay << endl ;
                ((fruits*)(curr->item))->update(counti);
            }
        }
        else
        {
            cout << "Which vegetable and how much?";
            string t;
            int counti,minc = 50000,dist = 1000000;
            cin >> t >> counti;
            int pay = 0;
            temp = head;
            curr = NULL;
            while(temp!=NULL)
            {
                if((((vegetables*)(temp->item))->type) == t )
                {
                    int x1 = temp->item->location_x;
                    int y1 = temp->item->location_y;
                    int d = (x1*x1) + (y1*y1);
                    if(d<dist)
                    {
                        dist = d;
                        minc = ((vegetables*)(temp->item))->price_per_kg;
                        curr = temp;
                    }
                    if(d == dist)
                    {
                        if((((vegetables*)(temp->item))->price_per_kg) < minc )
                        {
                            minc = ((vegetables*)(temp->item))->price_per_kg;
                            curr = temp;
                        }
                    }
                }
                temp = temp->next;
            }
            if (curr == NULL)
            {
                cout << "Out of stock";
                return ;
            }
            if( ((vegetables*)(curr->item))->amount_in_kg < counti)
            {
                cout << "We have only " << ((vegetables*)(curr->item))->amount_in_kg << "with the minimum rate" << endl;
                pay = (((vegetables*)(curr->item))->amount_in_kg)  * (minc);
                cout << "pay" << pay << " for " << ((vegetables*)(curr->item))->amount_in_kg  << " kg." << endl;
                remove_item(curr->item);
            }
            else
            {
                cout << "pay " << (counti)  * (minc) << endl;
                ((vegetables*)(curr->item))->update(counti);
            }


        }
    }
