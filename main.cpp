#include<iostream>
#include "itemsclass.h"
#include "fruitsclass.h"
#include "vegetablesclass.h"
#include "nodeclass.h"
#include "linkedlistclass.h"
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int id = 1001;
int main()
{
    linked_list store;
    FILE* fruit = fopen("fruits.txt","r");
    char t[20] = {'\0'};
    int x,y,p,c,u;
    float w;
    if(fruit!=NULL)
    {
        while(!feof(fruit))
        {
            fscanf(fruit," %s %d %d %f %d %d %d ",t,&x,&y,&w,&p,&c,&u);
            items* i;
            i = new fruits(x,y,t,w,c,p,u);
            store.add_item(i);
        }
    }
    else
    {
        cout << "Fruit file not opened" << endl;
    }
    fclose(fruit);


    FILE* vegetable = fopen("vegetables.txt","r");
    char t1[20] = {'\0'};
    int x1,y1,p1,v1,c1,a1;
    if(vegetable!=NULL)
    {
        while(!feof(vegetable))
        {
            fscanf(vegetable," %s %d %d %d %d %d %d ",t1,&x1,&y1,&p1,&v1,&c1,&a1);
            items* i;
            i = new vegetables(x1,y1,t1,c1,p1,v1,a1);
            store.add_item(i);
        }
    }
    else
    {
        cout << "Vegetable file not opened" << endl;
    }
    fclose(vegetable);

    
    int n=1;
   
    while(n)
   {  cout << "\t\t\t\tGROCERY STORE SYSTEM" << endl;
    cout << "ENTER 0 FOR EXIT." << endl;
    cout << "ENTER 1 FOR THE STORE DETAILS." << endl;
    cout << "ENTER 2 TO ADD THE ITEM IN THE STORE."<< endl;
    cout << "ENTER 3 TO KNOW THE AMOUNT OF A FRUIT OR VEGETABLE IN THE STORE."<< endl;
    cout << "ENTER 4 TO KNOW THE MAX AMOUNT FOR GIVEN CALORIES"<< endl;
    cout << "ENTER 5 TO BUY SOMETHING"<< endl;
    cout << "ENTER 6 TO CHECK THE ITEMS IN PARTICULAR AREA"<< endl;
      cin >> n;
    switch(n)
    {   
        case 1: {store.store_details();
                break;}
        case 2: {
                cout << "\t\t\t\t\t\tSTORE DETAILS BEFORE ADDITION:" << endl;
                store.store_details();
                store.add_item_dynam();
                cout << "\n\n\n\n\n\n";
                cout << "\t\t\t\t\t\tSTORE DETAILS AFTER ADDITION:" << endl;
                store.store_details();
                break;}
        case 3: {string t1,t2;
                cout << "fruit/vegetable:";
                cin >> t1;
                cout << "Which one?:";
                cin >> t2;
                if(t1=="fruit")
                    cout << store.count_item(t1,t2) << " units are available.";
                if(t1=="vegetable")
                    cout << store.count_item(t1,t2) << " kg is available.";
                break;}
        case 4: {store.calories();
                break;}
        case 5: {store.sell();
                break;}
        case 6: {int a,b,c,d;
                cout << "Enter the coordinates for rectangular area" << endl;
                cout << "bottom left coordinates & top right coordinates:";
                cin >> a >> b >> c >> d;
                store.area_items(a,b,c,d);
                break;}
       default : break;
    }


  }
    return 0;
}
