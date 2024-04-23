#include <iostream>
#include <string>
using namespace std;
class Store
{
    int Store_ID;
    string Store_Name;
    //list of products.
public:
    Store()
    {
        Store_ID = 0;
        Store_Name = "nothing";
    }
    Store(int ID , string Name)
    {
        this->Store_ID = ID;
        this->Store_Name = Name;
    }
    void set_Store_ID(int ID)
    {
        this->Store_ID = ID;
    }
    void set_Store_Name(string Name)
    {
        this->Store_Name = Name;
    }
};
class Admin
{
    string Admin_UserName;
    string Admin_Password;
};
