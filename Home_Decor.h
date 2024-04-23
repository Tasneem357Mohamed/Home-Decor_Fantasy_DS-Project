#include <iostream>
#include <string>
using namespace std;
class Store
{
    int Store_ID;
    string Store_Name;
    //list of products.
public:
    Store();
    Store(int ID , string Name);
    void set_Store_ID(int ID);
    void set_Store_Name(string Name);
};
class Admin
{
    string Admin_UserName;
    string Admin_Password;
};
