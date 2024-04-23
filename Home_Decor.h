#include <iostream>
#include <string>
#include <map>
using namespace std;
class Store
{
private:
    static int Store_ID;
    string Store_Name;
    //list of products.
public:
    Store();
    Store(int ID , string Name);
    void set_Store_ID(int ID);
    void set_Store_Name(string Name);
};
int Store::Store_ID = 1000;
class Admin
{
    string Admin_UserName;
    string Admin_Password;
};
class User {
private:
    string username;
    string password;
    string email;

public:
    User(string& username,  string& password,  string& email);
    string getUsername();
    void setUsername( string& newUsername);
    string getPassword();
    void setPassword( string& newPassword);
    string getEmail();
    void setEmail( string& newEmail);
};

class UserManager {
private:
    map<string, User> users;
    string currentUser;

public:
    UserManager();
    void signUpUser( string& username,  string& password,  string& email);
    void signInUser( string& username,  string& password);
    void signOutUser();
    void editUser();
    bool isUserSignedIn()const;
    void choise();
};
