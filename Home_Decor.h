#include <iostream>
#include <string>
#include <map>
using namespace std;
class Product
{
private:
    string Product_Name;
    double Price;
    double Points;
public:
    Product();
    Product(double Price , string Product_Name);
    void set_Price(double Price);
    double get_Price();
    void set_Product_Name(string Product_Name);
    string get_Product_Name();
    void set_Points(double Points);
    double get_Points()const;
};
class Store
{
public:
    std::multimap<double , Product> Products_List;
private:
    static int Store_ID;
    string Store_Name;
public:
    Store();
    Store(string Name);
    void set_Store_ID(int ID);
    int get_Store_ID();
    void set_Store_Name(string Name);
    string get_Store_Name();
};
class Admin
{
private:
    string Admin_UserName;
    string Admin_Password;
public:
    Admin();
    string get_Admin_UserName();
    string get_Admin_Password();
//    implemented with file
//    void Add_Product();
    Store iterate_on_Stores_Data(vector<Store> stores , string store_name);
    void Display_Top_Rated_Products(vector<Store> stores , string store_name);
    void Change_Price_Of_Product(vector<Store> stores);
};
class User {
private:
    string username;
    string password;
    string email;

public:
    User(string& username,  string& password,  string& email);
    string getUsername();
    void setUsername(string& newUsername);
    string getPassword();
    void setPassword(string& newPassword);
    string getEmail();
    void setEmail( string& newEmail);
};

class UserManager {
private:
    map<string , User> users;
    string currentUser;

public:
    UserManager();
    void signUpUser( string& username,  string& password,  string& email);
    void signInUser( string& username,  string& password);
    void signOutUser();
    void editUser();
    bool isUserSignedIn()const;
    void choice();
};
