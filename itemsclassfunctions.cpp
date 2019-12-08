#include<iostream>
#include<stdio.h>
#include "itemsclass.h"
#include<time.h>
using namespace std;
extern int id;

items::items(int x,int y)
{
    purchase_ID = id;
    ++id;
    location_x = x;location_y = y;
    time_t my_time = time(NULL);
    purchase_time= ctime(&my_time);

}

bool items::operator == (items & i2)
{
    if(this->purchase_ID == i2.purchase_ID)
        return true;
    return false;
}
void items::print()
{
    cout << "Details:" << endl;
    cout << "Purchase ID - " << purchase_ID << endl;
    cout << "Location - " << location_x << "," << location_y << endl;
    cout << "Purchase time - " << purchase_time << endl;
}
void items::update()
{
    cout << "ENTER THE NEW LOCATION FOR THE ITEM: ";
    int x,y;
    cin >> x >> y;
    location_x = x;
    location_y = y;
}
