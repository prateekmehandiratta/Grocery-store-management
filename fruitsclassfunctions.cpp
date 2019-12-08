#include<iostream>
#include "itemsclass.h"
#include "fruitsclass.h"
#include<stdio.h>
#include<stdlib.h>
using namespace std;

fruits::fruits(int x,int y,string t,float w,int c,int p,int u):items(x,y)
{
    type = t;weight_per_unit=w;calories=c;price_per_unit=p;units=u;
}
void fruits::print()
{
    cout << "fruit - " << type << endl;
    cout << "Purchase ID - " << purchase_ID << endl;
    cout << "location - " << location_x << "," << location_y<< endl;
    cout << "Purchase time - " << purchase_time << endl;
    cout << "Weight per unit - " << weight_per_unit << endl;
    cout << "Price per unit - " << price_per_unit << endl;
    cout << "calories - " << calories << endl;
    cout << "Units available - " << units << endl;
    cout << "\n";
}
void fruits::update(int u)
{
    units = units - u;
    if(units<=0)
    {
        units = 0;
    }
}
