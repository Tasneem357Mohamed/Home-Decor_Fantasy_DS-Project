#include "Home_Decor.h"
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

void UserManager::choise() {
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
