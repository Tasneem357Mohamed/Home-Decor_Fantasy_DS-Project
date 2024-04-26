#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
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
    double Store_Rate;
    string Store_Name;
public:
    Store();
    Store(string Name);
    void set_Store_ID(int ID);
    int get_Store_ID();
    void set_Store_Rate(double Store_Rate);
    double get_Store_Rate();
    void set_Store_Name(string Name);
    string get_Store_Name();
};
class player {
private:
    int ID = 100;
    int points;
    string User_Name;
    string Password;
    double Budget;
    vector<pair<string, float>>Decoration;
public:
    void setUserName(string username);
    string getUserName();
    void setPass(string password);
    string getPass();
    void set_ID();
    int get_id();
    void setPoints(int point);
    int getPoints();
    void set_budget(double budget);
    double get_budget();
    vector<pair<string, float>>getdecoration();
    player(string username, string password);
    player();
    float SerachProduct(string name);
    ~player();


};
class PlayerManager {
public:
    PlayerManager(int);
    ~PlayerManager();
    map<string, player>players;
    set<int>id;
    void signUpPlayer(string& username, string& password);
    void signInPlayer(string& username, string& password);
    void signOutPlayer();
    void choise();
    void choiseoperation();
    /*float Sellproduct(string s);
    float Buyproduct(string s);
    float Replaceproduct(string s);*/
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
    Store iterate_on_Stores_Data(multimap<double , Store, greater<double>> stores, string store_name);
    void Display_Top_Rated_Products(multimap<double , Store, greater<double>> stores, string store_name);
    void Display_Products(multimap<double , Store, greater<double>> stores, string store_name);
    void Change_Price_Of_Product(multimap<double , Store, greater<double>> stores);
    multimap<double, Product, greater<double>>iterate_on_products_Data(vector<pair<string, float>>Decoration, multimap<double, Product, greater<double>>products);
    vector<pair<float, player>> calculate_points(vector<pair<string, float>>Decoration, multimap<double, Product, greater<double>>products,vector<player>players);
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