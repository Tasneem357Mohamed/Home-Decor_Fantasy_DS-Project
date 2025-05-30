#include "Home_Decor.h"
/** Class Product **/
Product::Product()
{
    Product::Product_ID = 0;
    this->Price = 0.0;
    this->Null_check = false;
    this->Points = 0.0;
    this->Product_Name = " ";
}
Product::Product(int id, double price, string productname)
{
    Product::Product_ID = id;
    this->Price = price;
    this->Product_Name = std::move(productname);
}
Product::Product(int id, string productname, double points)
{
    Product::Product_ID = id;
    this->Product_Name = std::move(productname);
    this->Points = points;
}
Product::Product(int id, string productname, string storename, int productcounter, double price)
{
    Product::Product_ID = id;
    this->Null_check = false;
    this->Product_Name = std::move(productname);
    this->Store_Name = std::move(storename);
    this->Product_counter = productcounter;
    this->Price = price;
    this->Points = 0.0;
}
Product::Product(int id, string nameofproduct, string nameofstore, int productcounter, double price, double points)
{
    Product::Product_ID = id;
    this->Product_Name = std::move(nameofproduct);
    this->Store_Name = std::move(nameofstore);
    this->Product_counter = productcounter;
    this->Price = price;
    this->Points = points;
}
bool Product::get_Null_Check() const
{
    return Null_check;
}
void Product::set_Null_Check(bool nuller)
{
    this->Null_check = nuller;
}
void Product::set_Price(double new_price) const
{
    const_cast<double&>(Price) = new_price;
}
double Product::get_Price() const
{
    return Price;
}
void Product::set_Product_Name(string proname)
{
    this->Product_Name = proname;
}
string Product::get_Product_Name() const
{
    return Product_Name;
}
const string& Product::getStoreName() const {
    return Store_Name;
}
double Product::getPoints() const {
    return Points;
}
void Product::setStoreName(const string& storeName) {
    Store_Name = storeName;
}
void Product::setProductCounter(int count) {
    Product_counter = count;
}
void Product::setPoints(double points) {
    Points = points;
}
int Product::getProductCounter() const {
    return Product_counter;
}
bool Product::operator<(const Product& other) const {
    return Product_Name > other.Product_Name;
}
void Product::setProductId(int ID)
{
    this->Product_ID = ID;
}
int Product::getProductId() const
{
    return Product_ID;
}
Product::~Product()
{

}




/** Class Store **/
Store::Store()
{
    priority_queue<pair<double, Product>> default_list;
    Store_Name = " ";
    Null_checker = true;
    Store_Rate = 0;
    Number_Of_Products = 0;
    Products_List = default_list;
}
Store::Store(int id, string Name)
{
    this->Store_ID = id;
    Null_checker = true;
    this->Store_Name = std::move(Name);
    this->Store_Rate = 0;
}
Store::Store(int id, string name, double rate, int numProducts)
{
    this->Store_ID = id;
    Null_checker = true;
    this->Store_Name = name;
    this->Store_Rate = rate;
    this->Number_Of_Products = numProducts;
}
Store::Store(int id, string name, double rate, int numProducts, priority_queue<pair<double, Product>> products)
{
    this->Store_ID = id;
    this->Store_Name = name;
    this->Store_Rate = rate;
    this->Number_Of_Products = numProducts;
    this->Null_checker = true;
    this->Products_List = priority_queue<pair<double, Product>>(std::move(products));
}
void Store::set_Store_ID(int stoid)
{
    this->Store_ID = stoid;
}
int Store::get_Store_ID() const
{
    return Store_ID;
}
bool Store::get_Null_Checker() const
{
    return Null_checker;
}
void Store::set_Null_Checker(bool nullChecker)
{
    this->Null_checker = nullChecker;
}
void Store::set_Store_Rate(double rate)
{
    this->Store_Rate = rate;
}
double Store::get_Store_Rate()const
{
    return Store_Rate;
}
void Store::set_Store_Name(string name)
{
    this->Store_Name = name;
}
string Store::get_Store_Name()const
{
    return Store_Name;
}
void Store::set_Number_Of_Product(int Num_Of_Product)
{
    this->Number_Of_Products = Num_Of_Product;
}
int Store::get_Number_Of_Product() const
{
    return Number_Of_Products;
}
void Store::set_Product_List(priority_queue<pair<double, Product>> prolist)
{
    Products_List = prolist;
}
priority_queue<pair<double, Product>> Store::get_Product_List()const
{
    return Products_List;
}
bool Store::operator<(const Store& other) const
{
    return Store_Name > other.Store_Name;
}
Store::~Store()
{

}




/** Class Player **/
Player::Player(int idofplayer, string nameofplayer, string passwordofplayer) {
    ID = idofplayer;
    UserName = std::move(nameofplayer);
    Password = std::move(passwordofplayer);
    points = 0;
    Budget = 80000;
}
Player::Player() {
}
void Player::setUserName(string usernameofplayer) {
    UserName = std::move(usernameofplayer);
}
string Player::getUserName() const
{
    return UserName;
}
void  Player::setPass(std::string password) {
    Password = std::move(password);
}
string Player::getPass() const
{
    return Password;
}
void Player::set_ID(int id_ofplayer) {
    this->ID = id_ofplayer;
}
int Player::get_id() const
{
    return ID;
}
void Player::set_budget(double budget_ofplayer)
{
    Budget = budget_ofplayer;
}
double Player::get_budget() const
{
    return Budget;
}
void Player::setPoints(double point) {
    points = point;
}
double Player::getPoints() const
{
    return points;
}
void Player::setdecoration(vector<pair<string, double>> x) {
    Decoration = x;
}
vector<pair<string, double>> Player::getdecoration() const
{
    return Decoration;
}
double Player::SerachProduct(string name, int& ind) {
    vector<pair<string, double>> list = getdecoration();
    for (int i = 0; i < list.size(); i++) {
        if (list[i].first == name)
        {
            ind = i;
            return list[i].second;
        }
    }
    return  -1;
}
void Player::Sellproduct(string s)
{
    Admin admin;
    int ind = -1;
    float price = SerachProduct(s, ind);
    if (ind == -1)
    {
        cout << "invalid product\n";
        std::this_thread::sleep_for(std::chrono::seconds(0));
        //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
        cout << "-----------------" << '\n';
    }
    else {
        Decoration.erase(Decoration.begin() + ind);
    }
    cout << "Now Your Décoration Set Contains :" << '\n';
    cout << "Product Name" << " | " << "Product Price" << '\n';
    cout << "----------------------------------------" << '\n';
    for (auto it : Decoration) {
        cout << it.first << " | " << it.second << "\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(0));
    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
}
void Player::Buyproduct(string s, double price)
{
    Admin admin;
    Decoration.push_back(make_pair(s, price));
    cout << "Now Your Décoration Set Contains :" << '\n';
    cout << "Product Name" << " | " << "Product Price" << '\n';
    cout << "----------------------------------------" << '\n';
    for (auto it : Decoration) {
        cout << it.first << " | " << it.second << "\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(0));
    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
}
//take new name of product and its price.
string Player::Replaceproduct(string s, double price)
{
    Admin admin;
    cout << "Product Name" << " | " << "Product Price" << '\n';
    cout << "----------------------------------------" << '\n';
    for (auto it : Decoration)
    {
        cout << it.first << " | " << it.second << "\n";
    }
    cout << "Enter Name of old product\n";
    string old_product;
    getline(cin, old_product);
    int replace_index;
    //no need for price >> price is changeable.
    float old_price = SerachProduct(old_product, replace_index);
    Decoration.erase(Decoration.begin() + replace_index);
    Decoration.push_back(make_pair(s, price));
    cout << "Now Your Décoration Set Contains :" << '\n';
    cout << "Product Name" << " | " << "Product Price" << '\n';
    cout << "----------------------------------------" << '\n';
    for (auto it : Decoration) {
        cout << it.first << " | " << it.second << "\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(0));
    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
    return old_product;
}
bool Player::operator<(const Player& other) const {
    return UserName > other.getUserName();
}
Player::~Player()
{

}


/** Class Player Manager**/
PlayerManager::PlayerManager() {
    //    Player newPlayer("toka", "12345");
    //    vector<pair<string, float>> d;
    //    d.push_back(make_pair("bed", 300));
    //    d.push_back(make_pair("chair", 500));
    //    newPlayer.setdecoration(d);
    //    Players.insert(make_pair(newPlayer.getUserName(), newPlayer));
}
int PlayerManager::signUpPlayer(int id, string username, string password, unordered_map<string, User> users, Player& player)
{
    Admin admin;
    cout << username << "\n";
    // Check if username already exists
    if (Players.find(username) != Players.end()) {
        cout << username<<"sa" << "\n";
        //if username is exist.
        return -1;
    }
    auto it = Players.begin();
    bool f = 0, u = 0;
    while (it != Players.end())
    {
        if (it->second.getPass() == password)
        {
            f = 1;
            break;
        }
        else
        {
            if (it->second.get_id() == id)
            {
                f = 1;
                break;
            }
        }
        it++;
    }
    for (auto ir : users)
    {
        if (ir.second.getPassword() == password)
        {
            u = 1;
            break;
        }
    }
    if (f || u || password == "Aaaaa$009") {
        //if password is exist in Players , Users or Admin.
        //if id is exist in Players.
        return -2;
    }
    Player newPlayer(id, username, password);
    // Add the new user to the map
    Players.insert({ username, newPlayer });
    cout << "Player signed up successfully!\n";
    std::this_thread::sleep_for(std::chrono::seconds(0));
    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
    cout << "-------------------------------" << '\n';
    player = newPlayer;
    return 1;
}
int PlayerManager::signInPlayer(string& username, string& password, int& function, Player& player) {
    auto it = Players.find(username);
    if (it != Players.end())
    {
        if (it->second.getPass() == password)
        {
            currentPlayer = it->second;
            player = currentPlayer;
            function = 1;
            return 1;
        }
        return -2;
    }
    return -1;
}
bool PlayerManager::isPlayerSignedIn() const
{
    return !currentPlayer.getUserName().empty();
}
void PlayerManager::Edit_Information_of_player(unordered_map<string, User> userlist)
{
    Admin admin;
    string ans;
    int choice;
    do
    {
        auto it = Players.find(currentPlayer.getUserName());
        while (true)
        {
            cout << "Choose what you want to update:\n";
            cout << "1-Change Username\n";
            cout << "2-Change Password\n";
            cin >> choice;
            cin.ignore();
            if (choice == 1 || choice == 2)
            {
                cout << "Valid Choice ^^" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------------------------------------------" << '\n';
                break;
            }
            else
            {
                cout << "Invalid Choice!!! / Please,Enter Choice again: ";
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "-----------------------------------------------------" << '\n';
            }
        }
        unordered_map<string, Player>::iterator itt = Players.find(currentPlayer.getUserName());
        Player& player = itt->second;
        switch (choice)
        {
            case 1:
            {
                string newUsername;
                cout << "Enter new username: ";
                getline(cin, newUsername);
                while (Players.find(newUsername) != Players.end()) //check username is exist / or not
                {

                    cout << "This username is already exist!!!" << '\n';
                    cout << "Enter new username: ";
                    getline(cin, newUsername);
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                    cout << "-----------------------------------------------------" << '\n';
                }
                unordered_map<string, Player>::iterator it2;
                it2 = Players.find(currentPlayer.getUserName());
                int id = it2->second.get_id();
                Player newPlayer(id, newUsername, it2->second.getPass());
                newPlayer.set_ID(it2->second.get_id());
                // Add the Player with her/his new data to the map
                Players.insert({ newUsername, newPlayer });
                Players.erase(it2);
                currentPlayer.setUserName(newUsername);
                cout << "Username updated successfully!\n";
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------------------------------------------" << '\n';
                break;
            }
            case 2:
            {
                auto it = Players.begin();
                bool f = 0;
                string newPassword;
                while (true)
                {
                    cout << "Enter new password: ";
                    getline(cin, newPassword);
                    while (it != Players.end())
                    {
                        if (it->second.getPass() == newPassword)
                        {
                            f = 1;
                            break;
                        }
                        it++;
                    }
                    for (auto irr : userlist)
                    {
                        if (irr.second.getPassword() == newPassword)
                        {
                            f = 1;
                            break;
                        }
                    }
                    if (f == 1 || newPassword == "Aaaaa$009")
                    {
                        cout << "This password already exist!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-----------------------------------------------------" << '\n';
                        f = 0;
                    }
                    else
                    {
                        cout << "Valid Password ^^" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                        cout << "------------------" << '\n';
                        break;
                    }
                }
                itt->second.setPass(newPassword);
                cout << "Your Password is updated successfully ^^" << '\n';
                break;
            }
        }
        while (true)
        {
            cout << "Enter yes(if you want change another data) / no(if not)" << '\n';
            getline(cin, ans);
            transform(ans.begin(), ans.end(), ans.begin(), [](unsigned char c) { return std::tolower(c); });
            if ((ans == "yes") || (ans == "no"))
            {
                break;
            }
            cout << "Invalid Answer!!!" << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(0));
            //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
            cout << "------------------" << '\n';
        }
    } while (ans != "no");
}
void PlayerManager::signOutPlayer()
{
    Admin admin;
    //currentUser = "";
    cout << "Player signed out successfully!\n";
    std::this_thread::sleep_for(std::chrono::seconds(0));
    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
    cout << "------------------------------" << '\n';
}
void PlayerManager::readFromFile()
{
    //cout << "file1";
    fstream in("/Users/admin/Desktop/Home_Decor/Player.txt", ios::in);
    if (!in) {
        cout << "file dont found";
        return;
    }

    for (int i = 0; !in.eof(); i++) {

        //cout << "file2";
        string type, name, pass;
        int id, point;
        double budget;
        int s;

        in >> type >> name >> pass >> id >> budget >> point >> s;
        if (type == "user")
            break;
        vector<pair<string, double>>d;
        for (int i = 0; i < s; i++) {
            string product;
            float price;
            in >> product >> price;
            d.push_back(make_pair(product, price));
        }
        Player p(id, name, pass);
        p.setPoints(point);

        p.set_budget(budget);
        p.setdecoration(d);
        Players.insert(make_pair(name, p));
        //cout << "fileend";
    }
    // cout << Players["AhmedHossam"].getPass();
    in.close();

}
void PlayerManager::writeToFile()
{
    fstream out("/Users/admin/Desktop/Home_Decor/Player.txt", ios::out);
    if (!out) {
        cout << "file dont found";
        return;
    }
    for (auto it : Players) {
        out << "player" << " " << it.second.getUserName() << " " << it.second.getPass() << " "
            << it.second.get_id() << " " << it.second.get_budget() << " "
            << it.second.getPoints() << " ";
        vector<pair<string, double>> d = it.second.getdecoration();
        out << d.size() << " ";
        for (int i = 0; i < d.size(); i++) {
            out << d[i].first << " " << d[i].second << " ";
        }
        cout << it.second.getUserName() << d.size() << "\n";
        out << "\n";
    }
    out.close();

}
PlayerManager::~PlayerManager()
{

}






/** Class Admin **/
Admin::Admin()
{
    Admin_UserName = "Engy Abdullah";
    Admin_Password = "Aaaaa$009";
}
string Admin::get_Admin_UserName()
{
    return Admin_UserName;
}
string Admin::get_Admin_Password()
{
    return Admin_Password;
}
priority_queue<pair<double, Store>> Admin::get_Stores_List()
{
    return stores;
}
priority_queue<pair<double, Product>> Admin::get_Products_List()
{
    return products;
}
bool Admin::Check_Validate_On_Email(const std::string& email)
{
    //email format should be >> (Username@gmail.com).
    regex emailRegex("\\b[A-Za-z0-9._%+-]+(\\s[A-Za-z0-9._%+-]+)*@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");
    return regex_match(email, emailRegex);
}
bool Admin::Check_Validate_on_Password(const std::string& password)
{
    //Password Should Has At least one uppercase letter / At least one lowercase letter / At least one digit [0 , 9] / At least one special character from the provided set/ Minimum length of 8 characters.
    regex passwordRegex("^(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*[!@#$%^&*()_+\\-={}\\[\\]|;:'\",<.>/?]).{8,}$");
    return regex_match(password, passwordRegex);
}
pair<double, Store> Admin::iterate_on_Stores_Data(const string& store_name)
{
    priority_queue<pair<double, Store>> temp;
    pair<double, Store> store;
    while (!stores.empty())
    {
        if (stores.top().second.get_Store_Name() == store_name)
        {
            store.first = stores.top().first;
            store.second = stores.top().second;
            store.second.set_Null_Checker(false);
        }
        temp.push(stores.top());
        stores.pop();
    }
    stores = priority_queue<pair<double, Store>>(temp);
    return store;
}
pair<double, Product> Admin::iterate_On_Store_Products(priority_queue<pair<double, Product>> products_set, std::string proname)
{
    priority_queue<pair<double, Product>> temp;
    pair<double, Product> product;
    while (!products_set.empty())
    {
        if (products_set.top().second.get_Product_Name() == proname)
        {
            product.first = products_set.top().first;
            product.second = products_set.top().second;
        }
        temp.push(products_set.top());
        products_set.pop();
    }
    products_set = priority_queue<pair<double, Product>>(temp);
    return product;
}
pair<double, Product> Admin::iterate_On_System_Products(const string& product_name)
{
    priority_queue<pair<double, Product>> temp;
    pair<double, Product> product;
    while (!products.empty())
    {
        if (products.top().second.get_Product_Name() == product_name)
        {
            product.first = products.top().first;
            product.second = products.top().second;
            product.second.set_Null_Check(1);
        }
        temp.push(products.top());
        products.pop();
    }
    products = priority_queue<pair<double, Product>>(temp);
    return product;
}
void Admin::Add_Store()
{
    bool f = 0;
    string storename;
    int Number_Of_Product, counter, count, storeid;
    priority_queue<pair<double, Product>> product_list;
    priority_queue<pair<double, Store>> sto_temp;
    while (true)
    {
        cout << "Enter The Store ID: ";
        cin >> storeid;
        cin.ignore();
        while (!stores.empty())
        {
            if (stores.top().second.get_Store_ID() == storeid)
            {
                f = 1;
            }
            sto_temp.push(stores.top());
            stores.pop();
        }
        stores = priority_queue<pair<double, Store>>(sto_temp);
        if (f == 1)
        {
            cout << "This ID Is Already Exist!!!!!" << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(0));
            // Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
            cout << "-------------------------------" << '\n';
            f = 0;
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::seconds(0));
            // Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
            break;
        }
    }
    cout << "Enter The Name Of Store: ";
    getline(cin, storename);
    transform(storename.begin(), storename.end(), storename.begin(), [](unsigned char c) { return std::tolower(c); });
    cout << "Enter The Number Of Products: ";
    cin >> Number_Of_Product;
    cin.ignore();
    counter = Number_Of_Product;
    count = 1;
    if (Number_Of_Product != 0)
    {
        cout << "Enter The Product List :" << '\n';
    }
    while (counter--)
    {
        if (count == 1)
        {
            cout << "Enter The Product List" << '\n';
        }
        cout << count << "-";
        Add_New_Product(product_list, storename);
        count++;
    }
    Store newstore(storeid, storename, 0, Number_Of_Product, product_list);
    stores.push(make_pair(0, newstore));
}
void Admin::Add_New_Product(priority_queue<pair<double, Product>>& Product_List, string storename)
{
    string productname;
    int procounter, proid;
    double pri;
    bool f = 0;
    //if Add With Store.
    priority_queue<pair<double, Product>> pro_list;
    while (true)
    {
        cout << "Enter The Product ID: ";
        cin >> proid;
        cin.ignore();
        while (!products.empty())
        {
            if (products.top().second.getProductId() == proid)
            {
                f = 1;
            }
            pro_list.push(products.top());
            products.pop();
        }
        products = priority_queue<pair<double, Product>>(pro_list);
        if (f == 1)
        {
            cout << "This ID Is Already Exist!!!!!" << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(0));
            //  Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
            cout << "-------------------------------" << '\n';
            f = 0;
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::seconds(0));
            //   Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
            break;
        }
    }
    cout << "Enter Product Name : ";
    getline(cin, productname);
    transform(productname.begin(), productname.end(), productname.begin(), [](unsigned char c) { return std::tolower(c); });
    cout << '\n';
    cout << "Enter Product Counter : ";
    cin >> procounter;
    cin.ignore();
    cout << '\n';
    cout << "Enter Product Price : ";
    cin >> pri;
    cin.ignore();
    cout << '\n';
    Product newproduct(proid, productname, storename, procounter, pri, 0.0);
    pair<double, Store> sto_temp = iterate_on_Stores_Data(storename);
    int stocount = sto_temp.second.get_Number_Of_Product();
    stocount++;
    sto_temp.second.set_Number_Of_Product(stocount);
    //pushing in list product for store
    Product_List.push(make_pair(0.0, newproduct));
    //pushing in list of all products in system.
    products.push(make_pair(0.0, newproduct));
}
void Admin::Update_Product_Information(priority_queue<pair<double, Product>>& Product_List, string store_name)
{
    priority_queue<pair<double, Product>> pro_alter;
    string answer, product_name;;
    cout << "Product ID" << "|" << "Product Name" << "|" << "Store Name it belongs to" << "|" << "Product Points" << "|" << "Product Price" << '\n';
    cout << "------------------------------------------------------------------------------------------------------" << '\n';
    while (!Product_List.empty())
    {
        cout << Product_List.top().second.getProductId() << "|" << Product_List.top().second.get_Product_Name() << "|" << Product_List.top().second.getStoreName() << "|" << Product_List.top().first << "|" << Product_List.top().second.get_Price() << '\n';
        pro_alter.push(Product_List.top());
    }
    Product_List = priority_queue<pair<double, Product>>(pro_alter);
    cout << "Enter Product Name Which You Want to Update its Information" << '\n';
    getline(cin, product_name);
    pair<double, Product> pro = iterate_On_Store_Products(Product_List, product_name);
    do
    {
        int ans;
        do
        {
            cout << "Choose what you want to update:\n";
            cout << "1- Change Product_Counter\n";
            cout << "2- Change Product_Price\n";
            cin >> ans;
            if (ans == 1 || ans == 2)
            {
                break;
            }
            else
            {
                cout << "Invalid Answer!!!" << '\n';
            }
        } while (true);
        cin.ignore();
        if (ans == 1)
        {
            int new_counter;
            cout << "Enter New counter of product : ";
            cin >> new_counter;
            cin.ignore();
            Product newproduct(pro.second.getProductId(), pro.second.get_Product_Name(), pro.second.getStoreName(), new_counter, pro.second.get_Price(), pro.second.getPoints());
            Product_List.push(make_pair(pro.first, newproduct));
            products.push(make_pair(pro.second.getPoints(), newproduct));
            priority_queue<pair<double, Product>> alter;
            while (!Product_List.empty())
            {
                if (Product_List.top().second.get_Product_Name() != pro.second.get_Product_Name())
                {
                    alter.push(Product_List.top());
                    Product_List.pop();
                }
            }
            Product_List = priority_queue<pair<double, Product>>(alter);
            while (!products.empty())
            {
                if (products.top().second.get_Product_Name() != pro.second.get_Product_Name())
                {
                    alter.push(products.top());
                    products.pop();
                }
            }
            products = priority_queue<pair<double, Product>>(alter);
        }
        else
        {
            Change_Price_Of_Product(product_name);
        }
        while (true)
        {
            cout << "Enter yes(if you want change another data) / no(if not)" << '\n';
            getline(cin, answer);
            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c) { return std::tolower(c); });
            if ((answer == "yes") || (answer == "no"))
            {
                break;
            }
            cout << "Invalid Answer!!!" << '\n';
        }
    } while (answer != "no");
}
void Admin::Remove_Product(priority_queue<pair<double, Product>>& Product_List, string store_name)
{
    priority_queue<pair<double, Product>> pro_alter;
    string answer, product_name;;
    cout << "Product ID" << "|" << "Product Name" << "|" << "Store Name it belongs to" << "|" << "Product Points" << "|" << "Product Price" << '\n';
    cout << "------------------------------------------------------------------------------------------------------" << '\n';
    while (!Product_List.empty())
    {
        cout << Product_List.top().second.getProductId() << "|" << Product_List.top().second.get_Product_Name() << "|" << Product_List.top().second.getStoreName() << "|" << Product_List.top().first << "|" << Product_List.top().second.get_Price() << '\n';
        pro_alter.push(Product_List.top());
    }
    Product_List = priority_queue<pair<double, Product>>(pro_alter);
    cout << "Enter Product Name Which You Want to Remove it " << '\n';
    getline(cin, product_name);
    transform(product_name.begin(), product_name.end(), product_name.begin(), [](unsigned char c) { return std::tolower(c); });
    pair<double, Product> pro = iterate_On_Store_Products(Product_List, product_name);
    while (!Product_List.empty())
    {
        if (Product_List.top().second.get_Product_Name() != pro.second.get_Product_Name())
        {
            pro_alter.push(Product_List.top());
            Product_List.pop();
        }
    }
    Product_List = priority_queue<pair<double, Product>>(pro_alter);
    while (!products.empty())
    {
        if (products.top().second.get_Product_Name() != pro.second.get_Product_Name())
        {
            pro_alter.push(products.top());
            products.pop();
        }
    }
    pair<double, Store> sto_temp = iterate_on_Stores_Data(store_name);
    int stocount = sto_temp.second.get_Number_Of_Product();
    stocount--;
    sto_temp.second.set_Number_Of_Product(stocount);
    products = priority_queue<pair<double, Product>>(pro_alter);
}
void Admin::update_Store_Information()
{
    string answer;
    do
    {
        priority_queue<pair<double, Store>> temp;
        int count = 1;
        cout << "Choose Which Store You Want To Update Its Information : " << '\n';
        while (!stores.empty())
        {
            cout << "Store Number : " << count << "-" << stores.top().second.get_Store_Name();
            temp.push(stores.top());
            stores.pop();
            count++;
        }
        getline(cin, answer);
        pair<double, Store> store = iterate_on_Stores_Data(answer);
        do
        {
            int ans;
            do
            {
                cout << "Choose what you want to update:\n";
                cout << "1- Change Store_Name \n";
                cout << "2- Change Number_Of_Product\n";
                cout << "3- Change Product_List\n";
                cin >> ans;
                cin.ignore();
                if (ans == 1 || ans == 2 || ans == 3)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Answer!!!" << '\n';
                }
            } while (true);
            int new_Num_Product, press, newnum;
            if (ans == 1)
            {
                string new_name;
                cout << "Enter New Name : ";
                getline(cin, new_name);
                transform(new_name.begin(), new_name.end(), new_name.begin(), [](unsigned char c) { return std::tolower(c); });
                Store newstore(store.second.get_Store_ID(), new_name, store.second.get_Store_Rate(), store.second.get_Number_Of_Product(), store.second.get_Product_List());
                stores.push(make_pair(store.first, newstore));
                priority_queue<pair<double, Store>> alter;
                while (!stores.empty())
                {
                    if (stores.top().second.get_Store_Name() != store.second.get_Store_Name())
                    {
                        alter.push(stores.top());
                        stores.pop();
                    }
                }
                stores = priority_queue<pair<double, Store>>(alter);
            }
            else if (ans == 2)
            {
                cout << "Press :" << '\n';
                cout << "1-Add New Product." << '\n';
                cout << "2-Remove Product." << '\n';
                while (true)
                {
                    cin >> press;
                    if (press == 1 || press == 2)
                    {
                        cout << "Valid Choice ^^" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        // Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                        cout << "-----------------------------------------------------" << '\n';
                        break;
                    }
                    else
                    {
                        cout << "Invalid Choice!!! / Please,Enter Operation again: ";
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        // Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-----------------------------------------------------" << '\n';
                    }
                }
                if (press == 1)
                {
                    cout << "Enter Number Of Products You Will Add them: ";
                    cin >> new_Num_Product;
                    press = new_Num_Product;
                    cin.ignore();
                    while (press--)
                    {
                        priority_queue<pair<double, Product>> pro_temp = priority_queue<pair<double, Product>>(store.second.get_Product_List());
                        Add_New_Product(pro_temp, store.second.get_Store_Name());
                    }
                    newnum = store.second.get_Number_Of_Product();
                    newnum += new_Num_Product;
                    int stocount = store.second.get_Number_Of_Product();
                    stocount++;
                    store.second.set_Number_Of_Product(stocount);
                }
                else
                {
                    cout << "Enter Number Of Products You Will Remove them: ";
                    cin >> new_Num_Product;
                    press = new_Num_Product;
                    cin.ignore();
                    while (press--)
                    {
                        priority_queue<pair<double, Product>> pro_temp = priority_queue<pair<double, Product>>(store.second.get_Product_List());
                        Remove_Product(pro_temp, store.second.get_Store_Name());
                    }
                    newnum = store.second.get_Number_Of_Product();
                    newnum -= new_Num_Product;
                    int stocount = store.second.get_Number_Of_Product();
                    stocount--;
                    store.second.set_Number_Of_Product(stocount);
                }
                Store newstore(store.second.get_Store_ID(), store.second.get_Store_Name(), store.second.get_Store_Rate(), newnum, store.second.get_Product_List());
                stores.push(make_pair(store.first, newstore));
                priority_queue<pair<double, Store>> alter;
                while (!stores.empty())
                {
                    if (stores.top().second.get_Store_Name() != store.second.get_Store_Name())
                    {
                        alter.push(stores.top());
                        stores.pop();
                    }
                }
                stores = priority_queue<pair<double, Store>>(alter);
            }
            else
            {
                int choice;
                do
                {
                    cout << "Choose what you want to update:\n";
                    cout << "1- Add New Product \n";
                    cout << "2- Update Information of Product\n";
                    cout << "3- Remove Product\n";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 1 || choice == 2 || choice == 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Answer!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        //  Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-----------------" << '\n';
                    }
                } while (true);
                if (choice == 1)
                {
                    cout << "Enter Number Of Products You Will Add them: ";
                    cin >> new_Num_Product;
                    press = new_Num_Product;
                    cin.ignore();
                    while (press--)
                    {
                        priority_queue<pair<double, Product>> pro_temp = priority_queue<pair<double, Product>>(store.second.get_Product_List());
                        Add_New_Product(pro_temp, store.second.get_Store_Name());
                    }
                    newnum = store.second.get_Number_Of_Product();
                    newnum += new_Num_Product;
                    Store newstore(store.second.get_Store_ID(), store.second.get_Store_Name(), store.second.get_Store_Rate(), newnum, store.second.get_Product_List());
                    stores.push(make_pair(store.first, newstore));
                }
                else if (choice == 2)
                {
                    cout << "Enter Number Of Products You Will Update them: ";
                    cin >> new_Num_Product;
                    press = new_Num_Product;
                    cin.ignore();
                    while (press--)
                    {
                        priority_queue<pair<double, Product>> pro_temp = priority_queue<pair<double, Product>>(store.second.get_Product_List());
                        Add_New_Product(pro_temp, store.second.get_Store_Name());
                    }
                    Store newstore(store.second.get_Store_ID(), store.second.get_Store_Name(), store.second.get_Store_Rate(), store.second.get_Number_Of_Product(), store.second.get_Product_List());
                    stores.push(make_pair(store.first, newstore));
                }
                else
                {
                    cout << "Enter Number Of Products You Will Remove them: ";
                    cin >> new_Num_Product;
                    press = new_Num_Product;
                    cin.ignore();
                    while (press--)
                    {
                        priority_queue<pair<double, Product>> pro_temp = priority_queue<pair<double, Product>>(store.second.get_Product_List());
                        Remove_Product(pro_temp, store.second.get_Store_Name());
                    }
                    newnum = store.second.get_Number_Of_Product();
                    newnum -= new_Num_Product;
                    Store newstore(store.second.get_Store_ID(), store.second.get_Store_Name(), store.second.get_Store_Rate(), newnum, store.second.get_Product_List());
                    stores.push(make_pair(store.first, newstore));
                }
                priority_queue<pair<double, Store>> alter;
                while (!stores.empty())
                {
                    if (stores.top().second.get_Store_Name() != store.second.get_Store_Name())
                    {
                        alter.push(stores.top());
                        stores.pop();
                    }
                }
                stores = priority_queue<pair<double, Store>>(alter);
            }
            while (true)
            {
                cout << "Enter yes(if you want change another data) / no(if not)" << '\n';
                getline(cin, answer);
                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c) { return std::tolower(c); });
                if ((answer == "yes") || (answer == "no"))
                {
                    break;
                }
                cout << "Invalid Answer!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "------------------" << '\n';
            }
        } while (answer != "no");
        while (true)
        {
            cout << "Enter yes(if you want change Information of another Store) / no(if not)" << '\n';
            getline(cin, answer);
            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c) { return std::tolower(c); });
            if ((answer == "yes") || (answer == "no"))
            {
                break;
            }
            cout << "Invalid Answer!!!" << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(0));
            //Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
            cout << "-------------------" << '\n';
        }
    } while (answer != "no");
}
void Admin::Remove_Store()
{
    priority_queue<pair<double, Store>> store_alter;
    pair<double, Store> sto;
    string answer;
    do
    {
        cout << "Enter Store Name Which You Want to Remove it " << '\n';
        int count = 1;
        while (!stores.empty())
        {
            cout << "Product Number : " << count << "-" << stores.top().second.get_Store_Name() << '\n';
            store_alter.push(stores.top());
            stores.pop();
            count++;
        }
        string product_name;
        getline(cin, product_name);
        transform(product_name.begin(), product_name.end(), product_name.begin(), [](unsigned char c) { return std::tolower(c); });
        stores = priority_queue<pair<double, Store>>(store_alter);
        pair<double, Store> store = iterate_on_Stores_Data(product_name);
        sto = store;
        if (store.second.get_Store_Rate() < 1.5)
        {
            break;
        }
        else
        {
            cout << "Sorry You Can't Remove This Store , Choose Another One" << '\n';
            continue;
        }
    } while (true);
    while (!stores.empty())
    {
        if (stores.top().second.get_Store_Name() != sto.second.get_Store_Name())
        {
            store_alter.push(stores.top());
            stores.pop();
        }
    }
    stores = priority_queue<pair<double, Store>>(store_alter);
}
int Admin::Sign_In(const std::string& username, std::string password, int& function)
{
    if (username == Admin_UserName)
    {
        if (password == Admin_Password)
        {
            function = 3;
            return 1;
        }
        else
        {
            //password wrong.
            cout << "Your Username Or Password Incorrect!!!" << '\n';
            return -1;
        }
    }
    else
    {
        //username wrong.
        return -2;
    }
}
void Admin::Sign_Out()
{
    cout << "Thank You ^^" << '\n';
    return;
}
// should user make search function return string(Store_Name).
void Admin::Display_Top_Rated_Products(const string& store_name)
{
    int count = 1;
    priority_queue<pair<double, Product>> pro_alter;
    while (!products.empty())
    {
        if (products.top().second.getStoreName() == store_name)
        {
            if (count > 5)
            {
                break;
            }
            else
            {
                cout << "Product Number: " << products.top().second.getProductId() << '\n';
                cout << "Name Of Product : " << products.top().second.get_Product_Name() << '\n';
                cout << "Price Of Product : " << products.top().second.get_Price() << '\n';
                cout << "Points Of Product : " << products.top().first << '\n';
            }
            count++;
        }
        pro_alter.push(products.top());
        products.pop();
    }
    // Recreate the 'products' priority queue using elements from 'pro_alter'
    products = priority_queue<pair<double, Product>>(pro_alter);
}
// should user make search function return string(Store_Name).
void Admin::Display_Products(const string& store_name)
{
    int count = 1;
    priority_queue<pair<double, Product>> pro_alter;
    while (!products.empty())
    {
        if (count >= 1 && count <= 5)
        {
            goto prolist;
        }
        else
        {
            if (products.top().second.getStoreName() == store_name)
            {
                cout << "Product Number: " << products.top().second.getProductId() << '\n';
                cout << "Name Of Product : " << products.top().second.get_Product_Name() << '\n';
                cout << "Price Of Product : " << products.top().second.get_Price() << '\n';
                cout << "Points Of Product : " << products.top().first << '\n';
            }
        }
        prolist: {};
        count++;
        pro_alter.push(products.top());
        products.pop();
    }
    products = priority_queue<pair<double, Product>>(pro_alter);
}
// should discuss.
void Admin::Change_Price_Of_Product(const string& product_name)
{
    priority_queue<pair<double, Product>> pro_alter;
    while (!products.empty())
    {
        if (products.top().second.get_Product_Name() == product_name)
        {
            //discount 35%
            if (products.top().first >= 0 && products.top().first < 1.5)
            {
                double price = products.top().second.get_Price();
                price -= (price * (35 / 100.00));
                products.top().second.set_Price(price);
            }
                //discount 15%
            else if (products.top().first >= 1.5 && products.top().first < 2.5)
            {
                double price = products.top().second.get_Price();
                price -= (price * (15 / 100.00));
                products.top().second.set_Price(price);
            }
                //increase price 15%
            else if (products.top().first > 2.5 && products.top().first < 3.5)
            {
                double price = products.top().second.get_Price();
                price += (price * (15 / 100.00));
                products.top().second.set_Price(price);
            }
                //increase price 35%
            else if (products.top().first >= 3.5 && products.top().first < 5)
            {
                double price = products.top().second.get_Price();
                price += (price * (35 / 100.00));
                products.top().second.set_Price(price);
            }
        }
        pro_alter.push(products.top());
        products.pop();
    }
    products = priority_queue<pair<double, Product>>(pro_alter);
}
//here should reach to product_list from stores.
priority_queue<pair<double, Product>> Admin::iterate_on_products_Data(const vector<pair<string, double>>& Decoration)
{
    priority_queue<pair<double, Product>> objects;
    priority_queue<pair<double, Product>> pro_alter;
    for (auto it : Decoration) {
        while (!products.empty())
        {
            if (it.first == products.top().second.get_Product_Name())
            {
                objects.push(products.top());
                break;
            }
        }
    }
    return objects;
}
void Admin::calculate_points(Player& player)
{
    double sum = 0;
    priority_queue<pair<double, Product>> result = iterate_on_products_Data(player.getdecoration());
    priority_queue<pair<double, Product>> alter_result;
    while (!result.empty())
    {
        sum += result.top().first;
        alter_result.push(result.top());
        result.pop();
    }
    while (!alter_result.empty())
    {
        result.push(alter_result.top());
        alter_result.pop();
    }
    player.setPoints(sum);
}
double Admin::search_for_product(const string& product_name)
{
    double price;
    priority_queue<pair<double, Product>> alter;
    while (!products.empty())
    {
        if (products.top().second.get_Product_Name() == product_name)
        {
            price = products.top().second.get_Price();
        }
        alter.push(products.top());
        products.pop();
    }
    while (!alter.empty())
    {
        products.push(alter.top());
        alter.pop();
    }
    return price;
}
vector<string> Admin::split(const std::string& s, char delimiter)
{
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
void Admin:: setprolist(priority_queue<pair<double, Product>>lists) {
    products = lists;
}
void Admin::read_stores()
{
    fstream in("/Users/admin/Desktop/Home_Decor/Store.txt", ios::in);
    if (!in) {
        cout << "file does Not found";
        return;
    }
    //cout << "file\n";
    string stoname;
    double stoid, point;
    int s;
    while(in >> stoid >> stoname >> point >> s)
    {
        // cout << id << name << point << s<<"\n";
        if (stoname == "break")
            break;
        priority_queue<pair<double, Product>> list,temp;
        int j = 0;
        //cout << s << "uppp\n";
        while (j < s) {
            string productname, stoname;
            double proprice, propoints;
            int num , proid;
            in >> proid >> productname >> stoname >> proprice >> propoints >> num;
            Product pro(proid, productname, stoname, num, proprice, propoints);
            list.push(make_pair(propoints, pro));
            //cout << Product_List.size() << "up" << endl;
            products.push(make_pair(propoints, pro));
            j++;
        }
        Store sto(stoid , stoname , point , s , list);
        stores.push(make_pair(point, sto));
    }
    in.close();
}
void Admin::write_store()
{
    ofstream storefile, productfile;
    storefile.open("store.txt");
    productfile.open("products.txt", ios::app); // Open in append mode
    if (!storefile.is_open() || !productfile.is_open()) {
        cerr << "Error: Unable to open files" << endl;
        return;
    }
    priority_queue<pair<double, Store>> sto_temp;
    // Writing new store data to the store file
    while (!stores.empty()) {
        Store currentStore = stores.top().second;
        storefile << currentStore.get_Store_ID() << ',' << currentStore.get_Store_Name() << ','
                  << currentStore.get_Store_Rate() << ',' << currentStore.get_Number_Of_Product() << endl;
        // Writing new product data to the product file
        productfile.seekp(0, ios::end); // Set output position indicator to end of file
        productfile << currentStore.get_Store_Name() << "[";
        priority_queue<pair<double, Product>> pro_alter = currentStore.get_Product_List();
        while (!pro_alter.empty())
        {
            Product currentProduct = pro_alter.top().second;
            productfile << currentProduct.getProductId() << "," << currentProduct.get_Product_Name() << ","
                        << currentProduct.getStoreName() << "," << currentProduct.getProductCounter() << ","
                        << currentProduct.getPoints() << "," << currentProduct.get_Price();
            pro_alter.pop();
            if (!pro_alter.empty()) {
                productfile << "[";
            }
        }
        productfile << endl;
        stores.pop();
    }
    storefile.close();
    productfile.close();
}
//old_product >> sell / buy / replace.
//new_product >> replace only.
void Admin::Change_budget_of_Player(string old_product, int operation, Player& P, double new_price)
{
    double price;
    Store S;
    if (operation == 1)
    {
        //price of product change by referance
        //sell.
        price = search_for_product(old_product);
        P.set_budget(P.get_budget() + price);
    }
    else if (operation == 2)
    {
        //buy.
        price = search_for_product(old_product);
        P.set_budget(P.get_budget() - price);
    }
    else
    {
        //old price.
        price = search_for_product(old_product);
        if (price == new_price)
        {
            P.set_budget(P.get_budget() + 0);
        }
        else if (price > new_price)
        {
            double diff = price - new_price;
            P.set_budget(P.get_budget() + diff);
        }
        else
        {
            double diff = new_price - price;
            P.set_budget(P.get_budget() - diff);
        }
    }

}
void Admin::display_Top_Rated_Stores()
{
    priority_queue<pair<double, Store>> alter;
    int count = 1;
    while (!stores.empty())
    {
        if (count > 5)
        {
            break;
        }
        cout << "Store Number: " << stores.top().second.get_Store_ID() << '\n';
        cout << "Name Of Store : " << stores.top().second.get_Store_Name() << '\n';
        cout << "Store ID : " << stores.top().second.get_Store_ID() << '\n';
        cout << "Points Of Product : " << stores.top().first << '\n';
        count++;
        alter.push(stores.top());
        stores.pop();
    }
    // Recreate the 'stores' priority queue using elements from 'alter'
    stores = priority_queue<pair<double, Store>>(alter);
}
void Admin::display_Stores()
{
    priority_queue<pair<double, Store>> alter;
    int count = 1;
    while (!stores.empty())
    {
        if (count >= 1 && count <= 5)
        {
            goto jump;
        }
        else
        {
            cout << "Store Number: " << count << '\n';
            cout << "Name Of Store : " << stores.top().second.get_Store_Name() << '\n';
            cout << "Store ID : " << stores.top().second.get_Store_ID() << '\n';
            cout << "Points Of Product : " << stores.top().first << '\n';
        }
        jump: {};
        count++;
        alter.push(stores.top());
        stores.pop();
    }
    while (!alter.empty())
    {
        stores.push(alter.top());
        alter.pop();
    }
}
void Admin::display_top(unordered_map<string, Player> playerlist)
{
    multimap<double, Player, greater<double>> player_alter;
    multimap<double, Player, greater<double>> ::iterator itr = player_alter.begin();
    for (auto it : playerlist)
    {
        player_alter.insert(make_pair(it.second.getPoints(), it.second));
    }
    int max = -1;
    string name;
    unordered_map<string , Player> l = playerlist;
    for(auto ig : player_alter )
    {
        if(ig.second.getPoints() > max)
        {
            max = ig.second.getPoints();
            name = ig.second.getUserName();
            vector<pair<string , double>> l = ig.second.getdecoration();
        }
    }
    cout << "The Winner Player" << '\n';
    cout << "Winner Name: " << name << endl;
    std::this_thread::sleep_for(std::chrono::seconds(0));
     Sounds("/Users/admin/Desktop/Home_Decor/win.ogg");
    cout << "Winner Decoration set: " << '\n';
    cout << "------------------------" << '\n';
    for (auto ir : l)
    {
        cout << "Product Name: " << ir.first << '\n';
    }
    cout << "congratulation ^^";
}
void Admin::Calculate_Stores_Points(string store_name, double new_points, int operation, double old_points = 0)
{
    double rate = 0.00;
    pair<double, Store> store = iterate_on_Stores_Data(store_name);
    if (operation == 1)
    {
        if (store.second.get_Store_Rate() < 5)
        {
            rate = store.second.get_Store_Rate() + new_points;
            if (rate > 5)
            {
                rate = fmod(rate, 5);
            }
        }
    }
    else if (operation == 2)
    {
        if (new_points > old_points)
        {
            rate = store.second.get_Store_Rate() + (new_points - old_points);
            if (rate > 5)
            {
                rate = fmod(rate, 5);
            }
        }
        else if (old_points > new_points)
        {
            rate = store.second.get_Store_Rate() - (old_points - new_points);
            if (rate > 5)
            {
                rate = fmod(rate, 5);
            }
        }
        else
        {
            rate = store.second.get_Store_Rate() + (0);
        }
    }
    else
    {
        rate = store.second.get_Store_Rate() - new_points;
    }
    Store newstore(store.second.get_Store_ID(), store.second.get_Store_Name(), rate, store.second.get_Number_Of_Product(), store.second.get_Product_List());
    stores.push(make_pair(store.first, newstore));
    priority_queue<pair<double, Store>> alter;
    while (!stores.empty())
    {
        if (stores.top().second.get_Store_Name() != store.second.get_Store_Name())
        {
            alter.push(stores.top());
            stores.pop();
        }
    }
    stores = priority_queue<pair<double, Store>>(alter);
}
void Admin::Calculate_Product_Points(string product_name, double new_points, int operation, priority_queue<pair<double, Product>> product_list, double old_points = 0)
{
    double rate = 0.00;
    pair<double, Product> product = iterate_On_Store_Products(product_list, product_name);
    if (operation == 1)
    {
        if (product.second.getPoints() < 5)
        {
            rate = product.second.getPoints() + new_points;
            if (rate > 5)
            {
                rate = fmod(rate, 5);
            }
        }
    }
    else if (operation == 2)
    {
        if (new_points > old_points)
        {
            rate = product.second.getPoints() + (new_points - old_points);
            if (rate > 5)
            {
                rate = fmod(rate, 5);
            }
        }
        else if (old_points > new_points)
        {
            rate = product.second.getPoints() - (old_points - new_points);
            if (rate > 5)
            {
                rate = fmod(rate, 5);
            }
        }
        else
        {
            rate = product.second.getPoints() + (0);
        }
    }
    else
    {
        rate = product.second.getPoints() - new_points;
    }
    Product newproduct(product.second.getProductId(), product.second.get_Product_Name(), product.second.getStoreName(), product.second.getProductCounter(), product.second.get_Price(), rate);
    products.push(make_pair(product.first, newproduct));
    priority_queue<pair<double, Product>> alter;
    while (!products.empty())
    {
        if (products.top().second.get_Product_Name() != product.second.get_Product_Name())
        {
            alter.push(products.top());
            stores.pop();
        }
    }
    products = priority_queue<pair<double, Product>>(alter);
}
void Admin::change_Product_counter(string proname, string operation, string old)
{
    int count;
    pair<double, Product> pro = iterate_On_System_Products(proname);
    if (operation == "buy")
    {
        count = pro.second.getProductCounter();
        count--;
        pro.second.setProductCounter(count);
    }
    else if (operation == "replace")
    {
        pair<double, Product> oldpro = iterate_On_System_Products(old);
        count = pro.second.getProductCounter();
        count--;
        pro.second.setProductCounter(count);
        int count2 = oldpro.second.getProductCounter();
        count++;
        oldpro.second.setProductCounter(count);
    }
    else
    {
        count = pro.second.getProductCounter();
        count++;
        pro.second.setProductCounter(count);
    }
}
int Admin::Sounds(string path)
{
    sf::Music music;
    if (!music.openFromFile(path)) {
        return -1; // Error loading the file
    }
    // Play the music
    music.play();
    // Keep the program running while the music is playing
    while (music.getStatus() == sf::SoundSource::Playing) {
    }
    return 1;
}
Admin::~Admin()
{

}


/** Class User **/
User::User()
{
    this->username = " ";
}
User::User(int userid, string name, string password, string email)
{
    this->id = userid;
    this->username = name;
    this->password = password;
    this->email = email;
    this->Number_Of_storeRatings = 0;
    this->Number_Of_productRatings = 0;
}
User::User(int id, const string& username, const string& password, const string& email, int numberOfProductRatings, int numberOfStoreRatings, const unordered_map<int, double>& productRatings, const unordered_map<int, double>& storeRatings)
{
    this->id = id;
    this->username = username;
    this->password = password;
    this->email = email;
    this->Number_Of_productRatings = numberOfProductRatings;
    this->Number_Of_storeRatings = numberOfStoreRatings;
    this->productRatings = unordered_map<int, double>(productRatings);
    this->storeRatings = unordered_map<int, double>(storeRatings);
}
void User::setUsername(string& newUsername)
{
    username = newUsername;
}
string User::getUsername() const
{
    return username;
}
void User::set_productRatings_list(unordered_map<int, double> pro_list)
{
    productRatings = pro_list;
}
void User::set_storeRatings_list(unordered_map<int, double> sto_list)
{
    storeRatings = sto_list;
}
unordered_map<int, double> User::get_productRatings_list()
{
    return productRatings;
}
unordered_map<int, double> User::get_storeRatings_list()
{
    return storeRatings;
}
void User::set_Number_Of_productRatings(int number)
{
    this->Number_Of_productRatings = number;
}
void User::set_Number_Of_storeRatings(int num)
{
    this->Number_Of_storeRatings = num;
}
int User::get_Number_Of_productRatings() const
{
    return Number_Of_productRatings;
}
int User::get_Number_Of_storeRatings() const
{
    return Number_Of_storeRatings;
}
void User::setPassword(string newPassword)
{
    password = newPassword;
}
string User::getPassword() const
{
    return password;
}
void User::setEmail(string newEmail)
{
    email = newEmail;
}
string User::getEmail() const
{
    return email;
}
int User::getId() const
{
    return id;
}
void User::setId(int newId) {
    id = newId;
}
unordered_map<int, double> User::get_storeRatings() const
{
    return storeRatings;
}
unordered_map<int, double> User::get_productRatings() const
{
    return productRatings;
}
// main take rate;
// calc points for products.
void User::addProductRating(const int productId, double rating) {
    productRatings[productId] = rating;
}
double User::removeProductRating(const int productId) {
    double rate = productRatings[productId];
    productRatings.erase(productId);
    return rate;
}
// new rate from main and return old rate;
double User::updateProductRating(const int productId, double newRating)
{
    double old_rate = productRatings[productId];
    productRatings[productId] = newRating;
    return old_rate;
}
void User::addStoreRating(const int StoreId, double rating) {
    storeRatings[StoreId] = rating;
}
double User::removeStoreRating(const int StoreId)
{
    double rate = storeRatings[StoreId];
    storeRatings.erase(StoreId);
    return rate;
}
// new rate from main and return old rate;
double User::updateStoreRating(const int StoreId, double newRating)
{
    double old_rate = storeRatings[StoreId];
    storeRatings[StoreId] = newRating;
    return old_rate;
}
void User::Search_for_Store(priority_queue<pair<double, Store>> stores)
{
    priority_queue<pair<double, Store>> alter_store;
    int ID_of_product, press;
    string ans;
    int answer;
    string store_name, product_name;
    double new_rate, rate;
    Admin admin;
    int count = 1;
    do
    {
        cout << "Press:\n";
        cout << "1-If You Know Store Name\n";
        cout << "2-If You don't Know Store Name\n";
        do
        {
            cin >> answer;
            if (answer == 1 || answer == 2)
            {
                cout << "valid Answer ^^" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //  admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "----------------" << '\n';
                break;
            }
            else
            {
                cout << "Invalid Answer!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "------------------" << '\n';
            }
        } while (true);
        if (answer == 2)
        {
            while (!stores.empty())
            {
                cout << "Store Number: " << stores.top().second.get_Store_ID() << "_" << stores.top().second.get_Store_Name() << '\n';
                alter_store.push(stores.top());
                stores.pop();
                count++;
            }
            while (!alter_store.empty())
            {
                stores.push(alter_store.top());
                alter_store.pop();
            }
        }
        cout << "Enter the name of Store you want :" << '\n';
        getline(cin, store_name);
        transform(store_name.begin(), store_name.end(), store_name.begin(), [](unsigned char c) { return std::tolower(c); });
        cout << "-----------------------------------" << '\n';
        while (!stores.empty())
        {
            int ID;
            if (stores.top().second.get_Store_Name() == store_name)
            {
                ID = stores.top().second.get_Store_ID();
                do
                {
                    cout << "Choose what you want to do:\n";
                    cout << "1- Rate Store\n";
                    cout << "2- Rate Its Product\n";
                    cin >> answer;
                    if (answer == 1 || answer == 2)
                    {
                        cout << "Valid Answer ^^" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                        cout << "------------------" << '\n';
                        break;
                    }
                    else
                    {
                        cout << "Invalid Answer!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "------------------" << '\n';

                    }
                } while (true);
                if (answer == 1)
                {
                    //rate Store
                    if (stores.top().second.get_Store_Rate() == 5)
                    {
                        cout << "Sorry You Can't Rate this Store!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "----------------------------------" << '\n';
                        goto done;
                    }
                    int choose;
                    do
                    {
                        cout << "Choose what you want to do In Its Rate:\n";
                        cout << "1- Add Rate to Store\n";
                        cout << "2- Update Rate to Store\n";
                        cout << "3- Remove Rate to Store\n";
                        cin >> choose;
                        if (choose == 1 || choose == 2 || choose == 3)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid Answer!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-----------------" << '\n';
                        }
                    } while (true);
                    int rate;
                    if (choose == 1)
                    {
                        while (true)
                        {
                            cout << "Enter Rate For Store : ";
                            cin >> rate;
                            if (rate >= 0 && rate <= 5)
                            {
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Rate!!!" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "----------------" << '\n';
                            }
                        }
                        addStoreRating(ID, rate);
                        admin.Calculate_Stores_Points(store_name, rate, 1);
                        //write function.
                    }
                    else if (choose == 2)
                    {
                        while (true)
                        {
                            cout << "Enter New Rate For Store : ";
                            cin >> rate;
                            if (rate >= 0 && rate <= 5)
                            {
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Rate!!!" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "---------------" << '\n';
                            }
                        }
                        double points = updateStoreRating(ID, rate);
                        admin.Calculate_Stores_Points(store_name, rate, 2, points);
                    }
                    else
                    {
                        double points = removeStoreRating(ID);
                        admin.Calculate_Stores_Points(store_name, points, 3);
                    }
                }
                else
                {
                    do
                    {
                        cout << "The Product List Of " << store_name << " Store: " << '\n';
                        cout << "Product Number" << " | " << "Product Name" << '\n';
                        cout << "-----------------------------------------" << '\n';
                        while (!stores.top().second.get_Product_List().empty())
                        {

                            cout << stores.top().second.get_Product_List().top().second.getProductId() << " | " << stores.top().second.get_Product_List().top().second.get_Product_Name() << '\n';
                            alter_store.push(stores.top());
                            stores.pop();
                            count++;
                        }
                        stores = priority_queue<pair<double, Store>>(alter_store); //instead of while loop
                        cout << " Enter the name of product you want to Update rating for it  :" << '\n';
                        getline(cin, product_name);
                        cout << "--------------------------------------------------------------" << '\n';
                        while (!stores.top().second.get_Product_List().empty())
                        {
                            if (stores.top().second.get_Product_List().top().second.get_Product_Name() == product_name)
                            {
                                ID_of_product = stores.top().second.get_Product_List().top().second.getProductId();
                                break;
                            }
                            else
                            {
                                alter_store.push(stores.top());
                                stores.pop();
                            }
                        }
                        //return id of product
                        do
                        {
                            cout << "Press :" << '\n';
                            cout << "1- Update Rate To Product :\n";
                            cout << "2- Add Rate To Product:\n";
                            cout << "3- Remove Rate To Product :\n";
                            cin >> press;
                            if (press == 1 || press == 2 || press == 3)
                            {
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer!!!" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "------------------" << '\n';
                            }
                        } while (true);
                        if (press == 1)
                        {
                            while (true)
                            {
                                cout << "Enter New Rate For Product : ";
                                cin >> new_rate;
                                if (rate >= 0 && rate <= 5)
                                {
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Rate!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "----------------" << '\n';
                                }
                            }
                            pair<double, Store> stor = admin.iterate_on_Stores_Data(store_name);
                            double points = updateProductRating(ID_of_product, new_rate);
                            admin.Calculate_Product_Points(product_name, rate, 1, stor.second.get_Product_List(), points);
                            admin.Change_Price_Of_Product(product_name);
                        }
                        else if (press == 2)
                        {
                            while (true)
                            {
                                cout << "Enter Rate For Product : ";
                                cin >> rate;
                                if (rate >= 0 && rate <= 5)
                                {
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Rate!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "----------------" << '\n';
                                }
                            }
                            pair<double, Store> stor = admin.iterate_on_Stores_Data(store_name);
                            addProductRating(ID_of_product, rate);
                            admin.Calculate_Product_Points(product_name, rate, 2, stor.second.get_Product_List());
                            admin.Change_Price_Of_Product(product_name);
                        }
                        else
                        {
                            double points = removeProductRating(ID_of_product);
                            pair<double, Store> stor = admin.iterate_on_Stores_Data(store_name);
                            admin.Calculate_Product_Points(product_name, points, 3, stor.second.get_Product_List());
                            admin.Change_Price_Of_Product(product_name);
                        }
                        while (true)
                        {
                            cout << " choose ((YES)) if you want to rate another product & ((NO)) if not : " << '\n';
                            cout << "YES\n" << "NO\n";
                            getline(cin, ans);
                            if (ans == "YES" || ans == "NO")
                            {
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer !!!" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "--------------------" << '\n';
                            }
                        }
                    } while (ans == "YES");
                }
            }
            else
            {
                alter_store.push(stores.top());
                stores.pop();
            }
        }
        done: {};
        stores = priority_queue<pair<double, Store>>(alter_store);
        while (true)
        {
            cout << " choose ((YES)) if you want to Choose another Store & ((NO)) if not : " << '\n';
            cout << "YES\n" << "NO\n";
            getline(cin, ans);
            if (ans == "YES" || ans == "NO")
            {
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                break;
            }
            else
            {
                cout << "Invalid Answer!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << " Please !! Enter correct answer :\n";
            }
        }
    } while (ans == "YES");
}
void User::Search_for_Store_When_Sign_Up(priority_queue<pair<double, Store>> stores)
{
    priority_queue<pair<double, Store>> alter_store;
    pair<double, Store> searched_store;
    int ID_of_product, press;
    string ans;
    string store_name, product_name;
    int choose;
    double new_rate, rate;
    Admin admin;
    int count = 1;
    int ID;
    int answer;
    do
    {
        cout << "Press:\n";
        cout << "1-If You Know Store Name\n";
        cout << "2-If You don't Know Store Name\n";
        do
        {
            cin >> answer;
            if (answer == 1 || answer == 2)
            {
                cout << "valid Answer ^^" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------" << '\n';
                break;
            }
            else
            {
                cout << "Invalid Answer!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "------------------" << '\n';
            }
        } while (true);
        if (answer == 2)
        {
            cout << "Store Number" << " | " << "Store Name" << '\n';
            cout << "--------------------------------------" << '\n';
            while (!stores.empty())
            {
                cout << stores.top().second.get_Store_ID() << " | " << stores.top().second.get_Store_Name() << '\n';
                alter_store.push(stores.top());
                stores.pop();
                count++;
            }
            while (!alter_store.empty())
            {
                stores.push(alter_store.top());
                alter_store.pop();
            }
        }
        while (true)
        {
            cout << "Enter Name Of Store Do You Want: ";
            getline(cin, store_name);
            transform(ans.begin(), ans.end(), ans.begin(), [](unsigned char c) { return std::tolower(c); });
            searched_store = admin.iterate_on_Stores_Data(store_name);
            if (searched_store.second.get_Null_Checker() == 1)
            {
                cout << "Store Is Found ^^" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "------------------" << '\n';
                break;
            }
            else
            {
                cout << "Store Not Found!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "-------------------" << '\n';
            }
        }
        ID = stores.top().second.get_Store_ID();
        do
        {
            cout << "Choose what you want to do:\n";
            cout << "1- Rate Store\n";
            cout << "2- Rate Product\n";
            cout << "3- Exit\n";
            cin >> answer;
            if (answer == 1 || answer == 2 || answer == 3)
            {
                cout << "valid Answer ^^" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------" << '\n';
                break;
            }
            else
            {
                cout << "Invalid Answer!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "-------------------" << '\n';
            }
        } while (true);
        if (answer == 1)
        {
            if (stores.top().second.get_Store_Rate() == 5)
            {
                cout << "Sorry You Can't Rate this Store!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "-----------------------------------" << '\n';
                goto enter;
            }
            while (true)
            {
                cout << "Enter Rate For Store : ";
                cin >> rate;
                if (rate >= 0 && rate <= 5)
                {
                    cout << "valid Rate!!!" << '\n';
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                    cout << "-------------" << '\n';
                    break;
                }
                else
                {
                    cout << "Invalid Rate!!!" << '\n';
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                    cout << "----------------" << '\n';
                }
            }
            addStoreRating(ID, rate);
            admin.Calculate_Stores_Points(store_name, rate, 1);
        }
        else if (answer == 2)
        {
            do
            {
                cout << "Press:\n";
                cout << "1-If You Know Store Name\n";
                cout << "2-If You don't Know Store Name\n";
                do
                {
                    cin >> answer;
                    if (answer == 1 || answer == 2)
                    {
                        cout << "valid Answer ^^" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        //  admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                        cout << "----------------" << '\n';
                        break;
                    }
                    else
                    {
                        cout << "Invalid Answer!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-----------------" << '\n';
                    }
                } while (true);
                if (answer == 2)
                {
                    cout << "The Product List Of " << store_name << " Store: " << '\n';
                    cout << "Product Number" << " | " << "Prodcut Name" << '\n';
                    cout << "-----------------------------------------" << '\n';
                    while (!stores.top().second.get_Product_List().empty())
                    {
                        cout << stores.top().second.get_Product_List().top().second.getProductId() << " | " << stores.top().second.get_Product_List().top().second.get_Product_Name() << '\n';
                        alter_store.push(stores.top());
                        stores.pop();
                        count++;
                    }
                    stores = priority_queue<pair<double, Store>>(alter_store); //instead of while loop
                }
                cout << " Enter the name of product you want to Update rating for it  :" << '\n';
                getline(cin, product_name);
                transform(product_name.begin(), product_name.end(), product_name.begin(), [](unsigned char c) { return std::tolower(c); });
                while (!stores.top().second.get_Product_List().empty())
                {
                    if (stores.top().second.get_Product_List().top().second.get_Product_Name() == product_name)
                    {
                        ID_of_product = stores.top().second.get_Product_List().top().second.getProductId();
                        break;
                    }
                    else
                    {
                        alter_store.push(stores.top());
                        stores.pop();
                    }
                }
                //return id of product
                cout << "Do You Want Add Any Rate For This Product?\n";
                while (true)
                {
                    cout << "Answer: ";
                    getline(cin, ans);
                    transform(ans.begin(), ans.end(), ans.begin(), [](unsigned char c) { return std::tolower(c); });
                    if ((ans == "yes") || (ans == "no"))
                    {
                        cout << "valid Answer ^^" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                        cout << "-----------------" << '\n';
                        break;
                    }
                    cout << "Invalid Answer!!!" << '\n';
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                    cout << "-----------------" << '\n';
                }
                if (ans == "yes")
                {
                    while (true)
                    {
                        cout << "Enter Rate For Product : ";
                        cin >> rate;
                        if (rate >= 0 && rate <= 5)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid Rate!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "---------------" << '\n';
                        }
                    }
                    pair<double, Store> stor = admin.iterate_on_Stores_Data(store_name);
                    addProductRating(ID_of_product, rate);
                    admin.Calculate_Product_Points(product_name, rate, 2, stor.second.get_Product_List());
                    admin.Change_Price_Of_Product(product_name);
                }
                while (true)
                {
                    cout << " choose ((YES)) if you want to rate another product & ((NO)) if not : " << '\n';
                    cout << "YES\n" << "NO\n";
                    getline(cin, ans);
                    if (ans == "YES" || ans == "NO")
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Answer !!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-------------------" << '\n';
                    }
                }
            } while (ans == "YES");
        }
        else
        {
            cout << "Thank You ^^" << '\n';
        }
        stores = priority_queue<pair<double, Store>>(alter_store);
        enter: {};
        while (true)
        {
            cout << " choose ((YES)) if you want to Choose another Store & ((NO)) if not : " << '\n';
            cout << "YES\n" << "NO\n";
            getline(cin, ans);
            if (ans == "YES" || ans == "NO")
            {
                cout << "valid Answer ^^" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------" << '\n';
                break;
            }
            else
            {
                cout << "Invalid Answer!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "------------------" << '\n';
            }
        }
    } while (ans == "YES");
}
User::~User()
{

}


/** Class User Manager **/
UserManager::UserManager()
{
    currentUser = " ";
}
int UserManager::signUpUser(int id, string username, string password, string email, unordered_map<string, Player> Players)
{
    Admin admin;
    // Check if username already exists
    if (users.find(username) != users.end())
    {
        //if username is exist.
        return -1;
    }
    unordered_map<string, User>::iterator it = users.begin();
    bool f = 0, p = 0;
    while (it != users.end()) {
        if (it->second.getPassword() == password) {
            f = 1;
            break;
        }
        else
        {
            if (it->second.getId() == id)
            {
                f = 1;
                break;
            }
            else if (it->second.getEmail() == email)
            {
                f = 1;
                break;
            }
        }
        it++;
    }
    for (auto ir : Players)
    {
        if (ir.second.getPass() == password)
        {
            p = 1;
            break;
        }
    }
    if (f || p || password == "Aaaaa$009")
    {
        //if password is found in Players or users.
        //if id is found in users
        //if email is found in users
        return -2;
    }
    User newUser(id, username, password, email);
    // Add the new user to the map
    users.insert({ username , newUser });
    cout << "Player signed up successfully!\n";
    std::this_thread::sleep_for(std::chrono::seconds(0));
    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
    cout << "------------------------------" << '\n';
    //all data is correct.
    return 1;
}
int UserManager::signInUser(string& username, string& password, int& function)
{
    auto it = users.find(username);
    if (it != users.end()) {
        if (it->second.getPassword() == password) {
            currentUser = it->second.getUsername();
            cout << "User signed in successfully!\n";
            //signed in successfully-
            function = 2;
            return 1;
        }
        //password wrong.
        return -2;
    }
    //username wrong or does not exist.
    return -1;
}
void UserManager::signOutUser()
{
    Admin admin;
    cout << "User signed out successfully!\n";
    std::this_thread::sleep_for(std::chrono::seconds(0));
    // admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
}
void UserManager::editUser(unordered_map<string, Player> playerlist)
{
    Admin admin;
    string ans;
    int choice;
    do
    {
        auto it = users.find(currentUser);
        while (true)
        {
            cout << "Choose what you want to update:\n";
            cout << "1-Change Username\n";
            cout << "2-Change Password\n";
            cout << "3-Change Email\n";
            cin >> choice;
            cin.ignore();
            if (choice == 1 || choice == 2 || choice == 3)
            {
                cout << "Valid Choice ^^" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------------------------------------------" << '\n';
                break;
            }
            else
            {
                cout << "Invalid Choice!!! / Please,Enter Choice again: ";
                std::this_thread::sleep_for(std::chrono::seconds(0));
                // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "-----------------------------------------------------" << '\n';
            }
        }
        unordered_map<string, User>::iterator itt = users.find(currentUser);
        User& user = itt->second;
        switch (choice)
        {
            case 1:
            {
                string newUsername;
                cout << "Enter new username: ";
                getline(cin, newUsername);
                while (users.find(newUsername) != users.end()) //check username is exist / or not
                {

                    cout << "This username is already exist!!!" << '\n';
                    cout << "Enter new username: ";
                    getline(cin, newUsername);
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                    cout << "-----------------------------------------------------" << '\n';
                }
                unordered_map<string, User>::iterator it2;
                it2 = users.find(currentUser);
                int id = it2->second.getId();
                User newUser(id, newUsername, it2->second.getPassword(), it2->second.getEmail());
                newUser.setId(it2->second.getId());
                // Add the Player with her/his new data to the map
                users.insert({ newUsername, newUser });
                users.erase(it2);
                currentUser = newUsername;
                cout << "Username updated successfully!\n";
                std::this_thread::sleep_for(std::chrono::seconds(0));
                //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------------------------------------------" << '\n';
                break;
            }
            case 2:
            {
                auto it = users.begin();
                bool f = 0;
                string newPassword;
                while (true)
                {
                    cout << "Enter new password: ";
                    getline(cin, newPassword);
                    while (it != users.end())
                    {
                        if (it->second.getPassword() == newPassword)
                        {
                            f = 1;
                            break;
                        }
                        it++;
                    }
                    for (auto irr : playerlist)
                    {
                        if (irr.second.getPass() == newPassword)
                        {
                            f = 1;
                            break;
                        }
                    }
                    if (f == 1 || newPassword == "Aaaaa$009")
                    {
                        cout << "This password already exist!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        // admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-----------------------------------------------------" << '\n';
                        f = 0;
                    }
                    else
                    {
                        cout << "Valid Password ^^" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                        cout << "-------------------" << '\n';
                        break;
                    }
                }
                itt->second.setPassword(newPassword);
                break;
            }
            case 3:
            {
                auto it = users.begin();
                bool f = 0;
                string newemail;
                while (true)
                {
                    cout << "Enter new Email: ";
                    getline(cin, newemail);
                    while (it != users.end())
                    {
                        if (it->second.getPassword() == newemail)
                        {
                            f = 1;
                            break;
                        }
                        it++;
                    }
                    if (f == 1)
                    {
                        cout << "This email already exist!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "------------------------------" << '\n';
                    }
                    else
                    {
                        cout << "Valid email ^^" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        //admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                        cout << "-----------------" << '\n';
                        break;
                    }
                }
                itt->second.setPassword(newemail);
                break;
            }
        }
        while (true)
        {
            cout << "Enter yes(if you want change another data) / no(if not)" << '\n';
            getline(cin, ans);
            transform(ans.begin(), ans.end(), ans.begin(), [](unsigned char c) { return std::tolower(c); });
            if ((ans == "yes") || (ans == "no"))
            {
                break;
            }
            cout << "Invalid Answer!!!" << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(0));
            //admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
            cout << "------------------" << '\n';
        }
    } while (ans != "no");
}
bool UserManager::isUserSignedIn() const
{
    return !currentUser.empty();
}
void UserManager::user_read()
{
    //cout << "file1";
    fstream in("/Users/admin/Desktop/Home_Decor/Player.txt", ios::in);
    if (!in) {
        cout << "file dont found";
        return;
    }
    string type, name, pass,email;
    int id;
    int numpro,numstor;
    while(in >> type)
    {
//        cout << "file2";
        if (type == "UsER")
            break;
        if (type == "player")
            continue;
        else if (type == "user")
        {
            in >> name >> pass >> email >> id >> numpro >> numstor;
            unordered_map<int, double> productRating;
            unordered_map<int, double> storeRating;
            //cout << name << pass << email << id << numpro << numstor;
            int coun = 0;
            while (coun < numpro) {
                int  x;
                double y;
                in >> x >> y;

                productRating.insert(make_pair(x, y));
                coun++;
            }
            coun = 0;

            while (coun < numstor) {

                int a;
                double b;
                in >> a >> b;

                storeRating.insert(make_pair(a, b));
                coun++;
            }
            for (auto it : productRating) {
                cout << it.first << " " << it.second << "\n";
            }
            for (auto it : storeRating) {
                cout << it.first << " " << it.second << "\n";
            }
            User user(id, name, pass, email, numpro, numstor, productRating, storeRating);

            users.insert(make_pair(name, user));

        }
        else
            continue;
    }


    in.close();

}
void UserManager::user_write()
{
    fstream out("/Users/admin/Desktop/Home_Decor/Player.txt", ios::app);
    if (!out) {
        cout << "file dont found";
        return;
    }
    for (auto it : users) {
        out << "user" << " " << it.second.getUsername() << " " << it.second.getPassword() << " "
            << it.second.getEmail() << " " << it.second.getId() << " "
            << it.second.get_Number_Of_productRatings() << " "<<it.second.get_Number_Of_storeRatings()<<" ";
        unordered_map<int, double> productlis = it.second.get_productRatings_list();
        out << productlis.size() << " ";
        for (auto it : productlis) {
            out << it.first << " " << it.second << " ";
        }
        unordered_map<int, double> storlis = it.second.get_storeRatings_list();
        out << storlis.size() << " ";
        for (auto it : storlis) {
            out << it.first << " " << it.second << " ";
        }
        out << "\n";
    }
    out.close();

}
UserManager::~UserManager()
{

}