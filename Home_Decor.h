#pragma once
#include <iostream>
#include <thread>
#include <optional>
#include <chrono>
#include <cmath>
#include <sstream>
#include <fstream>
#include <utility>
#include <regex>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
#include <SFML/Audio.hpp>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
using namespace std;
class Product
{
private:
    int Product_ID;
    bool Null_check;
    string Product_Name;
    string Store_Name;
    int Product_counter;
    double Points;
    double Price;
public:
    Product();
    Product(int id, double Price, string Product_Name);
    Product(int id, string Product_Name, double Points);
    Product(int id, string Product_Name, string Store_Name, int Product_Counter, double Price);
    Product(int id, string Product_Name, string Store_Name, int Product_Counter, double Price, double Points);
    [[nodiscard]] bool get_Null_Check() const;
    void set_Null_Check(bool Null_check);
    void set_Price(double Price) const;
    [[nodiscard]] double get_Price() const;
    void set_Product_Name(string Product_Name);
    [[nodiscard]] string get_Product_Name() const;
    [[nodiscard]] const string& getStoreName() const;
    [[nodiscard]] double getPoints() const;
    void setStoreName(const string& storeName);
    void setProductCounter(int productCounter);
    void setPoints(double points);
    [[nodiscard]] int getProductCounter() const;
    void setProductId(int Product_ID);
    int getProductId() const;
    bool operator<(const Product& other) const;
    ~Product();
};
class Store
{
private:
    int Store_ID;
    bool Null_checker;
    string Store_Name;
    double Store_Rate;
    int Number_Of_Products;
    // change rate of product.
    priority_queue<pair<double, Product>> Products_List;
public:
    Store();
    Store(int id, string Name);
    Store(int id, string name, double rate, int numProducts);
    Store(int id, string name, double rate, int numProducts, priority_queue<pair<double, Product>> products);
    void set_Store_ID(int ID);
    int get_Store_ID() const;
    bool get_Null_Checker() const;
    void set_Null_Checker(bool nullChecker);
    void set_Store_Rate(double Store_Rate);
    [[nodiscard]] double get_Store_Rate() const;
    void set_Store_Name(string Name);
    [[nodiscard]] string get_Store_Name() const;
    void set_Number_Of_Product(int Num_Of_Product);
    int get_Number_Of_Product() const;
    [[nodiscard]] priority_queue<pair<double, Product>> get_Product_List() const;
    void set_Product_List(priority_queue<pair<double, Product>> prolist);
    bool operator<(const Store& other) const;
    ~Store();
};
class User {
private:
    int id;
    string username;
    string password;
    string email;
    int Number_Of_productRatings{};
    int Number_Of_storeRatings{};
    unordered_map<int, double> productRatings;
    unordered_map<int, double> storeRatings;
public:
    User();
    User(int id, string username, string password, string email);
    User(int id, const string& username, const string& password, const string& email, int numberOfProductRatings, int numberOfStoreRatings, const unordered_map<int, double>& productRatings,
         const unordered_map<int, double>& storeRatings);
    void set_productRatings_list(unordered_map<int, double> pro_list);
    void set_storeRatings_list(unordered_map<int, double> sto_list);
    unordered_map<int, double> get_storeRatings_list();
    unordered_map<int, double> get_productRatings_list();
    void set_Number_Of_productRatings(int Number_Of_productRatings);
    void set_Number_Of_storeRatings(int Number_Of_storeRatings);
    [[nodiscard]] int get_Number_Of_productRatings() const;
    [[nodiscard]] int get_Number_Of_storeRatings() const;
    [[nodiscard]] string getUsername() const;
    void setUsername(string& newUsername);
    [[nodiscard]] string getPassword()const;
    void setPassword(string newPassword);
    [[nodiscard]] string getEmail()const;
    void setEmail(string newEmail);
    void setId(int newId);
    [[nodiscard]] int getId() const;
    [[nodiscard]] unordered_map<int, double> get_storeRatings() const;
    [[nodiscard]] unordered_map<int, double> get_productRatings()const;
    void addProductRating(int productId, double rating);
    double removeProductRating(int productId);
    double updateProductRating(int productId, double newRating);
    //  vector<string>getRatedProducts() const;
    void addStoreRating(int StoreId, double rating);
    double removeStoreRating(int StoreId);
    // new rate from main and return old rate;
    double updateStoreRating(int StoreId, double newRating);
    void Search_for_Store(priority_queue<pair<double, Store>> stores);
    void Search_for_Store_When_Sign_Up(priority_queue<pair<double, Store>> stores);
    ~User();
};
class Player {
private:
    int ID;
    double points;
    string UserName;
    string Password;
    double Budget;
    vector<pair<string, double>> Decoration;
public:
    Player(int id, string username, string password);
    Player();
    void setUserName(string username);
    string getUserName() const;
    void setPass(string password);
    string getPass()const;
    void set_ID(int);
    int get_id() const;
    void setPoints(double point);
    double getPoints() const;
    void set_budget(double budget);
    double get_budget()const;
    vector<pair<string, double>> getdecoration()const;
    void setdecoration(vector<pair<string, double>> list);
    double SerachProduct(string name, int& ind);
    void Sellproduct(string s);
    void Buyproduct(string s, double price);
    string Replaceproduct(string s, double price);
    bool operator<(const Player& other) const;
    ~Player();
};
class PlayerManager {
public:
    unordered_map<string, Player>Players;
    Player currentPlayer;
    PlayerManager();
    int signUpPlayer(int id, string username, string password, unordered_map<string, User> users, Player& player);
    int signInPlayer(string& username, string& password, int& function, Player& player);
    void signOutPlayer();
    bool isPlayerSignedIn()const;
    void Edit_Information_of_player(unordered_map<string, User> userlist);
    void writeToFile();
    void readFromFile();
    ~PlayerManager();
};
class UserManager
{
public:
    string currentUser;
    unordered_map<string, User> users;
    UserManager();
    void user_read();
    void user_write();
    int signUpUser(int id, string username, string password, string email, unordered_map<string, Player> Players);
    int signInUser(string& username, string& password, int& function);
    void signOutUser();
    void editUser(unordered_map<string, Player> playerlist);
    bool isUserSignedIn()const;
    ~UserManager();
};
class Admin {
private:
    string Admin_UserName;
    string Admin_Password;
public:
    priority_queue<pair<double, Store>> stores;
    priority_queue<pair<double, Product>> products;
public:
    Admin();
    string get_Admin_UserName();
    string get_Admin_Password();
    priority_queue<pair<double, Store>> get_Stores_List();
    void setprolist(priority_queue<pair<double, Product>>lists);
    priority_queue<pair<double, Product>> get_Products_List();
    void read_stores();
    void write_store();
    void change_Product_counter(string proname, string operation, string old = " ");
    int Sign_In(const string& username, string password, int& function);
    void Sign_Out();
    void Add_Store();
    void update_Store_Information();
    void Remove_Store();
    vector<string> split(const string& s, char delimiter);
    void Display_Product_Data(string product_name);
    void Add_New_Product(priority_queue<pair<double, Product>>& Product_List, string Store_Name);
    void Update_Product_Information(priority_queue<pair<double, Product>>& Product_List, string store_name);
    void Remove_Product(priority_queue<pair<double, Product>>& Product_List, string store_name);
    void Display_Products(const string& store_name);
    void Display_Top_Rated_Products(const string& store_name);
    void Change_Price_Of_Product(const string& product_name);
    pair<double, Product>
    iterate_On_Store_Products(priority_queue<pair<double, Product>> products, string product_name);
    pair<double, Product> iterate_On_System_Products(const string& product_name);
    pair<double, Store> iterate_on_Stores_Data(const string& store_name);
    priority_queue<pair<double, Product>> iterate_on_products_Data(const vector<pair<string, double>>& Decoration);
    void calculate_points(Player& player);
    void Change_budget_of_Player(string old_product, int operation, Player& P, double new_price = 0);
    double search_for_product(const string& product_name);
    void display_Top_Rated_Stores();
    void display_Stores();
    void display_top(unordered_map<string, Player> playerlist);
    bool Check_Validate_On_Email(const string& email);
    bool Check_Validate_on_Password(const string& password);
    void Calculate_Stores_Points(string store_name, double new_points, int operation, double old_points);
    void Calculate_Product_Points(string product_name, double new_points, int operation, priority_queue<pair<double, Product>> product_list, double old_points);
     int Sounds(string path);
    ~Admin();
};