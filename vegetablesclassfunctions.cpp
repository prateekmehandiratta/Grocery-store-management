#include<iostream>
#include "itemsclass.h"
#include "vegetablesclass.h"
#include<stdio.h>
#include<stdlib.h>

using namespace std;
vegetables::vegetables(int x,int y,string t,int c,int p,int v,int a):items(x,y)
{
    type = t;price_per_kg = p;volume_per_kg=v;amount_in_kg = a;calories = c;
}

void vegetables::print()
{

    cout << "vegetable - " << type << endl;
    cout << "Purchase ID - " << purchase_ID << endl;
    cout << "location - " << location_x << "," << location_y<< endl;
    cout << "Purchase time - " << purchase_time << endl;
    cout << "Price per Kg  - " << price_per_kg << endl;
    cout << "Volume per Kg - " << volume_per_kg << endl;
    cout << "Calories - " << calories << endl;
    cout << "Amount in Kg - " << amount_in_kg  << endl;
    cout << "\n";
}
void vegetables::update(int u)
{
    amount_in_kg -= u;
    if(amount_in_kg<=0)
        amount_in_kg = 0;
}
