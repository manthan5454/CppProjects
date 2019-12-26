#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

namespace admin1234
{
class getDateTime
{
public:
    void getDateandTime()   ///Date and time
    {
        time_t now = time(0);
        char *dt=ctime(&now);
        cout<<dt;
    }
};

class mainWindow
{
public:
    int getMainWindow()
    {
        system("cls");
        int i=0;
        getDateTime dt;
        dt.getDateandTime();
        cout<<"\n\nWelcome To Fresh Veggie Store "<<endl;
        cout<<"\n\n 1. Create Bill"<<endl;
        cout<<"\n 2. Add/Edit Item"<<endl;
        cout<<"\n 3. Item Detail"<<endl;
        cout<<"\n 4. Exit"<<endl;
        cin>>i;
        return i;
    }
};

class itemInfo
{
public:
    int i,j,k,l,m,n;
    int itemPrice[1000],itemQty[1000];
    string itemName[1000],h[1000];

    int itemWindow()
    {
        int i;
        cout<<"1. Add Item Detail"<<endl;
        cout<<"2. Modify Item"<<endl;
        cin>>i;
        return i;
    }

    void setItem()
    {
        string name;
        int qty,price;
        ofstream setItemList;
        cin.get();
        setItemList.open("ItemList.txt",ios::app);
        cout<<"Enter the Name Of Item - ";
        getline(cin,name);
        setItemList<<name<<endl;
        cout<<"Enter The Quantity Of Item - ";
        cin>>qty;
        setItemList<<qty<<endl;
        cout<<"Enter The Price/Qty Of Item - ";
        cin>>price;
        setItemList<<price<<endl;
        setItemList.close();
    }

    void getItem()
    {
        i=0,j=0,k=0,l=0,m=0,n=0;
        ifstream getItemList("ItemList.txt");
        while (getline (getItemList,h[i]))
        {
            i++;
        }
        getItemList.close();
        while(m<i)
        {
            itemName[j]=h[m];
            j++,m++;
            std::istringstream temp1 (h[m]);
            temp1>>itemQty[l];
            l++,m++;
            std::istringstream temp2 (h[m]);
            temp2>>itemPrice[k];
            k++,m++;
        }
    }

    void dispItemlist()
    {

        while(n<i/3)
        {
            cout<<n+1<<" Item Name  :- "<<itemName[n]<<endl;
            cout<<"         Qty   :- "<<itemQty[n]<<endl;
            cout<<"         Price :- "<<itemPrice[n]<<endl;
            n++;
        }
    }

    int a,b;
    int getNumb()
    {
        int p;
        cout<<"Select the number of Product :- ";
        cin>>p;
        return p;
    }
    int getQty()
    {
        int p;
        cout<<"Select the Quantity of Product :- ";
        cin>>p;
        return p;
    }

    void cartValue()
    {
        int total;
        a=getNumb();
        b=getQty();
        total=b*itemPrice[a-1];
        cout<<"\nYour Order Detail is \n"<<endl;
        cout<<itemName[a-1]<<"\t"<<b<<"Qty\t"<<itemPrice[a-1]<<"@ rs./piece"<<endl;
        cout<<"\nTotal Amount :- "<<total<<"\n"<<endl;

        int setRQty,setsoldNumb,p=0;
        ofstream setSoldItemList;
        cin.get();
        setSoldItemList.open("SoldItemList.txt",ios::app);
        ///Set number in sold list
        setsoldNumb=a;
        setSoldItemList<<setsoldNumb<<endl;
        ///set Quantity Of sold Item
        setRQty=itemQty[a-1]-b;
        setSoldItemList<<setRQty<<endl;
        setSoldItemList.close();
    }
    void updateItemList()
    {
        int r=0,s=0,t,u;
        string p[1000];
        ifstream updateSoldItemList("SoldItemList.txt");
        while (getline (updateSoldItemList,p[r]))               ///Read Line From  Sold List
        {
            r++;
        }
        updateSoldItemList.close();
        while(s<r)                                             ///Update Detail in total list
        {
            std::istringstream tempo1 (p[s]);
            tempo1>>t;
            s++;
            std::istringstream tempo2 (p[s]);
            tempo2>>itemQty[t-1];
            s++;
        }
    }
};

class process
{
public:
    void task()
    {
        string x;
        mainWindow mw;
        itemInfo itm;
start:
        switch (mw.getMainWindow())
        {
        case 1:
            system("cls");
            itm.getItem();
            itm.updateItemList();
            itm.dispItemlist();
            itm.cartValue();
            break;
        case 2:
            system("cls");
            if(itm.itemWindow()==1)
            {
                system("cls");
                itm.setItem();
            }
            else
            {
                system("cls");
                itm.getItem();
            }
            break;
        case 3:
        {
            system("cls");
            cout<<"\n\nList Of Below You Have Remaining Stock In Your Inventory\n\n"<<endl;
            itm.getItem();
            itm.updateItemList();
            itm.dispItemlist();
            break;
        }
        case 4:
        {
            goto endding;
            break;
        }

        }
        cout<<"Do You Want To Go To Main Menu (y/n)"<<endl;
        cin>>x;
        if(x=="y"||x=="Y")
        {
            goto start;
        }
        else
        {
endding:
            cout<<"\n\nThanks You (^.^) \n\n";
        }
    }
};
}
