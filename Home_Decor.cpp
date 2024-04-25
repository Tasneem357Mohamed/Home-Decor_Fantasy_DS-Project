#include "Home_Decor.h"

/** Class Product **/
Product::Product()
{
    this->Price = 0;
    this->Points = 0;
    this->Product_Name = " ";
}
Product::Product(double Price, string Product_Name)
{
    this->Price = Price;
    this->Product_Name = Product_Name;
    this->Points = 0;
}
void Product::set_Price(double Price)
{
    this->Price = Price;
}
double Product::get_Price()
{
    return Price;
}
void Product::set_Product_Name(string Product_Name)
{
    this->Product_Name = Product_Name;
}
string Product::get_Product_Name()
{
    return Product_Name;
}
void Product::set_Points(double Points)
{
    this->Points = Points;
}
double Product::get_Points() const
{
    return Points;
}

/** Class Store **/
int Store::Store_ID = 1000;
Store::Store()
{
    Store_Name = " ";
}
Store::Store(string Name)
{
    this->Store_ID++;
    this->Store_Name = Name;
}
void Store::set_Store_ID(int ID)
{
    this->Store_ID = ID;
}
int Store::get_Store_ID()
{
    return Store_ID;
}
void Store::set_Store_Name(string Name)
{
    this->Store_Name = Name;
}
string Store::get_Store_Name()
{
    return Store_Name;
}
/**player,player manger**/
void player::setUserName(string username) {
    User_Name = username;
}
string player::getUserName() {
    return User_Name;

}
void  player::setPass(std::string password) {
    Password = password;
}
string player::getPass() {
    return Password;
}
void player::set_ID() {
    ID++;
}
int player::get_id() {
    return ID;
}
void player::set_budget(double budget) {
    Budget = budget;
}
double player::get_budget() {
    return Budget;
}
player::player(string username, string password) {
    ID++;
    User_Name = username;
    Password = password;
    Budget = 0.00;
}
player::player() {
    Budget = 0.0;
}
void player::setPoints(int point) {
    points = point;
}
int player::getPoints() {
    return points;
}
vector<pair<string, float>> player::getdecoration() {
    return Decoration;
}
float player::SerachProduct(string name) {
    for (int i = 0; i < Decoration.size(); i++) {
        if (Decoration[i].first == name) {
            return Decoration[i].second;
        }
    }
    return  -1;
}
player::~player() {

}
PlayerManager::PlayerManager(int x) {
    player newplayer("toka", "12345");
    players.insert(make_pair(newplayer.getUserName(), newplayer));
    vector<pair<string, float>> d = newplayer.getdecoration();
    d.push_back(make_pair("bed", 300));
    d.push_back(make_pair("chair", 500));
}
void PlayerManager::signUpPlayer(string& username, string& password)
{
    // Check if username already exists
    if (players.find(username) != players.end()) {
        cout << "Username already exists. Please choose a different one.\n";
        return;
    }
    player newPlayer(username, password);

    // Add the new user to the map
    players.insert({ username, newPlayer });

    cout << "Player signed up successfully!\n";
}
void PlayerManager::signInPlayer(string& username, string& password) {
    auto it = players.find(username);
    if (it != players.end()) {
        if (it->second.getPass() == password) {
            //currentUser = username;
            cout << "User signed in successfully!\n";
            return;
        }
    }
    cout << "Invalid username or password . Please try again.\n";
}
void PlayerManager::signOutPlayer()
{
    //currentUser = "";
    cout << "Player signed out successfully!\n";
}
void PlayerManager::choise() {
    while (true) {
        int press;
        cout << "1. Sign Up\n";
        cout << "2. Sign In\n";
        cout << "3. Sign Out\n";
        cout << "4. Exit\n";
        cin >> press;
        cin.ignore();
        if (press == 1) {
            int id;
            string username, password;
            cout << "Enter username: " << '\n';
            getline(cin, username);
            cout << "Enter password: " << '\n';
            getline(cin, password);
            cout << "Enter Id: " << "\n";
            signUpPlayer(username, password);
        }
        else if (press == 2) {
            string username, password;
            cout << "Enter username: " << '\n';
            getline(cin, username);
            cout << "Enter password: " << '\n';
            getline(cin, password);
            signInPlayer(username, password);
        }
        else if (press == 3) {
            signOutPlayer();
        }
        else if (press == 4) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    }
}
void PlayerManager::choiseoperation() {
    while (true) {
        int press;
        cout << "1. Sell product\n";
        cout << "2. Buy product\n";
        cout << "3. Replace product\n";
        cout << "4. Exit\n";
        cin >> press;
        cin.ignore();
        if (press == 1) {
            cout << "Enter Name of Product: \n";
            string product;
            cin >> product;
            //Sellproduct(product);
        }
        else if (press == 2) {
            cout << "Enter Name of Product: \n";
            string product;
            cin >> product;
            // Buyproduct(product);
        }
        else if (press == 3) {
            cout << "Enter Name of Product: \n";
            string product;
            cin >> product;
            // Replaceproduct(product);
        }
        else if (press == 4)
            break;
        else {
            cout << "Invalid choise please try again\n";
        }
    }
}
PlayerManager::~PlayerManager() {
}


/** Class Admin **/
Admin::Admin()
{
    Admin_UserName = "Amir Eid";
    Admin_Password = "123456";
}
string Admin::get_Admin_UserName()
{
    return Admin_UserName;
}
string Admin::get_Admin_Password()
{
    return Admin_Password;
}
Store Admin::iterate_on_Stores_Data(vector<Store> stores , string store_name)
{
    Store store;
    for(auto it : stores)
    {
        if(it.get_Store_Name() == store_name)
        {
            store = it;
        }
    }
    return store;
}
map<int, int>Admin::calculate_points() {
    map<int,int>mymap;

    return mymap;

}
void Admin::display_top() {
    map<int, int>result = calculate_points();
    map<int, int>::iterator it;
    auto maxIterator = result.begin();
    for (it = next(result.begin()); it != result.end(); it++) {
        if (it->second > maxIterator->second)
            maxIterator=it;
    }
    cout << "The Winner Is Player" << maxIterator->first << endl;
    cout << "congratulation......";

}
//dispaly The top 5 products in each store (the Store which player search on it).
void Admin::Display_Top_Rated_Products(vector<Store> stores , string store_name)
{
    //reach to store as object.
    Store store = iterate_on_Stores_Data(stores , store_name);
    int count = 1;
    for(auto it : store.Products_List)
    {
        if(count > 5)
        {
            break;
        }
        cout << "Product Number: " << count << '\n';
        cout << "Name Of Product : " << it.second.get_Product_Name() << '\n';
        cout << "Price Of Product : " << it.second.get_Price() << '\n';
        cout << "Points Of Product : " << it.first << '\n';
        count++;
    }
}
void Admin::Change_Price_Of_Product(vector<Store> stores)
{
    string ans;
    cout << "Enter The Name Of Store Which You Want Change Product Price:  ";
    getline(cin , ans);
    Store store = iterate_on_Stores_Data(stores , ans);
    for(auto it : store.Products_List)
    {
        if(it.first >= 0 && it.first < 1.5)
        {
            it.second.set_Price(0);
        }
        else if(it.first >= 1.5 && it.first < 2.5)
        {
            double price = it.second.get_Price();
            price -= (price * (50/100.00));
            it.second.set_Price(price);
        }
        else if(it.first == 2.5)
        {
            double price = it.second.get_Price();
            price -= (price * (25/100.00));
            it.second.set_Price(price);
        }
        else if(it.first > 2.5 && it.first < 3.5)
        {
            double price = it.second.get_Price();
            price += (price * (25/100.00));
            it.second.set_Price(price);
        }
        else if(it.first >= 3.5 && it.first < 4.5)
        {
            double price = it.second.get_Price();
            price += (price * (50/100.00));
            it.second.set_Price(price);
        }
        else if(it.first >= 4.5 && it.first <= 5)
        {
            double price = it.second.get_Price();
            it.second.set_Price(price * price);
        }
    }
}


/** Class User **/
User::User(string &username, string &password, string &email)
{
    this->username = username;
    this->password = password;
    this->email = email;
}
void User::setUsername(string &newUsername)
{
    username = newUsername;
}
string User::getUsername()
{
    return username;
}
void User::setPassword(string &newPassword)
{
    password = newPassword;
}
string User::getPassword()
{
    return password;
}
void User::setEmail(string &newEmail)
{
    email = newEmail;
}
string User::getEmail()
{
    return email;
}

/** Class User_Manager **/
UserManager::UserManager()
{
    currentUser = " ";
}
void UserManager::signUpUser(string &username, string &password, string &email)
{
    // Check if username already exists
    if (users.find(username) != users.end()) {
        cout << "Username already exists. Please choose a different one.\n";
        return;
    }
    User newUser(username, password, email);

    // Add the new user to the map
    users.insert({ username, newUser });

    cout << "User signed up successfully!\n";
}
void UserManager::signInUser(string &username, string &password)
{
    auto it = users.find(username);
    if (it != users.end()) {

        if (it->second.getPassword() == password) {
            currentUser = username;
            cout << "User signed in successfully!\n";
            return;
        }
    }
    cout << "Invalid username or password. Please try again.\n";
}
void UserManager::signOutUser()
{
    currentUser = "";
    cout << "User signed out successfully!\n";
}
void UserManager::editUser()
{
    if (currentUser.empty()) {
        cout << "No user is currently signed in. Please sign in first.\n";
        return;
    }

    string newUsername, newPassword, newEmail;
    cout << "Enter new username: ";
    getline(cin , newUsername);
    cout << "Enter new email: ";
    getline(cin , newEmail);
    cout << "Enter new password: ";
    getline(cin , newPassword);
    auto it = users.find(currentUser);
    if (it != users.end()) {
        users.erase(it);
    }
    users.insert({ newUsername, User(newUsername,newPassword, newEmail) });

    // Update currentUser
    currentUser = newUsername;

    cout << "User information updated successfully!\n";
}
bool UserManager::isUserSignedIn() const
{
    return !currentUser.empty();
}
void UserManager::choice() {
    while (true) {
        int press;
        cout << "1. Sign Up\n";
        cout << "2. Sign In\n";
        cout << "3. Sign Out\n";
        cout << "4. Edit User\n";
        cout << "5. Exit\n";
        cin >> press;
        cin.ignore();
        if (press == 1) {
            string username, password, email;
            cout << "Enter username: " << '\n';
            getline(cin , username);
            cout << "Enter email: " << '\n';;
            getline(cin , email);
            cout << "Enter password: " << '\n';;
            getline(cin , password);
            signUpUser(username, password, email);
        }
        else if (press == 2) {
            string username, password;
            cout << "Enter username: " << '\n';
            getline(cin , username);
            cout << "Enter password: " << '\n';
            getline(cin , password);
            signInUser(username, password);
        }
        else if (press == 3) {
            signOutUser();
        }
        else if (press == 4) {
            editUser();
        }
        else if (press == 5) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
