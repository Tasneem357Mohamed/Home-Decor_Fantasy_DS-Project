#include "Home_Decor.h"
int main()
{
    Admin admin;
    admin.Sounds("/Users/admin/Desktop/Home_Decor/Yala Bena.ogg");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    PlayerManager player_manager;
    UserManager user_manager;
    Player player;
    User user;
    pair<double , Product> searched_product;
    pair<double , Store> searched_store;
    string store_name , old_product , product_name , username , password , email , answer;
    int operation ,choo , id;
    admin.read_stores();
    user_manager.user_read();
    player_manager.readFromFile();
    cout << RED << "          ^^ Welcome In Our Home Décor System ^^          " <<RESET<< std::flush  <<'\n';
    do
    {
        while(true)
        {
            cout << "Press :" << '\n';
            cout << "1-To Sign UP." << '\n';
            cout << "2-To Sign IN." << '\n';
            while(true)
            {
                cin >> operation;
                cin.ignore();
                if(operation == 1 ||operation == 2)
                {
                    cout << "Valid Choice ^^" << '\n';
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                    cout << "----------------" << '\n';
                    break;
                }
                else
                {
                    cout << "Invalid Operation/Please,Enter Operation again!!!!";
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                    cout << "---------------------------------------------------"<< '\n';
                }
            }
            while(true)
            {
                cout << "Confirm Your Choice,Please ^^" << '\n';
                getline(cin , answer);
                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                if(answer == "sign up" || answer == "sign in")
                {
                    cout << "Valid Answer ^^" << '\n';
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                    cout << "-----------------------------------------------------" << '\n';
                    break;
                }
                else
                {
                    cout << "Invalid Answer/Please Enter Your Answer again!!!!!";
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                    cout << "-----------------------------------------------------" << '\n';

                }
            }
            if((operation == 1 && answer == "sign up") || (operation == 2 && answer == "sign in"))
            {
                cout << "Operation Confirmation Is Done ^^"<<'\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------------------------------------------" << '\n';
                break;
            }
            else
            {
                cout << "Invalid Matching,Please Choice Operation again!!!" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "--------------------------------------------------" << '\n';
            }
        }
        //choose Sign up
        if(operation == 1 && answer == "sign up")
        {
            cout << "Press :" << '\n';
            cout << "1-If You Are Player." << '\n';
            cout << "2-If You Are User." << '\n';
            int choice;
            while(true)
            {
                cin >> choice;
                cin.ignore();
                if(choice == 1 || choice == 2)
                {
                    cout << "Valid Choice ^^" << '\n';
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                    cout << "----------------" << '\n';
                    break;
                }
                else
                {
                    cout << "Invalid Choice/Please Enter Choice again!!!!!!";
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                    cout << "-----------------------------------------------" << '\n';
                }
            }
            //choose Player
            if(choice == 1)
            {
                int op = 0;
                while(true)
                {
                    cout << "UserName: ";
                    getline(cin , username);
                    cout << "----------" << '\n';
                    while(true)
                    {
                        cout << "Password: ";
                        getline(cin , password);
                        if(admin.Check_Validate_on_Password(password))
                        {
                            cout << "Valid Password ^^" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "------------------" << '\n';
                            break;
                        }
                        else
                        {
                            cout << "Invalid Password!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "Your password must contain:\n"
                                    "\n"
                                    "X At least 8 characters\n"
                                    "\n"
                                    "X At least 3 of the following:\n"
                                    "\n"
                                    "X Lower case letters (a-z)\n"
                                    "\n"
                                    "X Upper case letters (A-Z)\n"
                                    "\n"
                                    "X Numbers (0-9)\n"
                                    "\n"
                                    "X Special characters (ex. !@#$%^&*)"<<'\n';
                            cout <<"----------------------------------------------" << '\n';
                        }
                    }
                    cout << "ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "----------" << '\n';
                    //handel cases
                    int returned = player_manager.signUpPlayer(id , username , password , user_manager.users , player);
                    if(-1 == returned)
                    {
                        cout << "This Username Is Already exist!!! , Please Enter Your Data again" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-----------------------------------------------------" << '\n';
                    }
                    else if(-2 == returned)
                    {
                        cout << "This Password or ID Is Already exist!!! , Please Enter Your Data again" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-----------------------------------------------------" << '\n';
                    }
                    else
                    {
                        break;
                    }
                }
                //after sign up
                do
                {
                    if(op == 0)
                    {
                        cout << "Press :" << '\n';
                        cout << "1-If You Want Sign In" << '\n';
                        cout << "2-If You Want Search About Product\n";
                        cout << "3-If You Want Search About Store\n";
                        cout << "4-If You Want Buy Product\n";
                        cout << "5-If You Want Exit\n";
                        while(true)
                        {
                            cin >> choo;
                            cin.ignore();
                            if(choo == 1 || choo == 2 || choo == 3 || choo == 4 || choo == 5)
                            {
                                cout << "Valid Choice ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Operation!!! / Please,Enter Operation again: ";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                        //sign in after Sign Up
                        if(choo == 1)
                        {
                            int function = 0;
                            while(true)
                            {
                                cout << "Username: ";
                                getline(cin , username);
                                cout << "-----------" << '\n';
                                cout << "Password: ";
                                getline(cin , password);
                                cout << "-----------" << '\n';
                                if(player_manager.signInPlayer(username , password , function , player) == 1)
                                {
                                    cout << "You signed in successfully ^^\n";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "------------------------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Your Username Or Password Incorrect , Please Sign IN Again!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-------------------------------------------------------------" << '\n';
                                }
                            }
                            do
                            {
                                int enter;
                                cout << "Press :" << '\n';
                                cout << "1-If You Want Search About Product\n";
                                cout << "2-If You Want Search About Store\n";
                                cout << "3-If You Want Buy Product\n";
                                cout << "4-If You Want Exit\n";
                                while(true)
                                {
                                    cin >> enter;
                                    cin.ignore();
                                    if(enter == 1 || enter == 2 || enter == 3 || enter == 4)
                                    {
                                        cout << "Valid Choice ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "----------------" << '\n';
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Invalid Operation!!! / Please,Enter Operation again: ";
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "------------------------------------------------------" << '\n';
                                    }
                                }
                                //player search about product.
                                if(enter == 1)
                                {
                                    do
                                    {
                                        while(true)
                                        {
                                            cout << "Enter Name Of Product Do You Want Search about It: ";
                                            getline(cin , product_name);
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            searched_product = admin.iterate_On_System_Products(product_name);
                                            if(searched_product.second.get_Null_Check() == 1)
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Product Not Found!!!" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                                cout << "-----------------------------------------------------" << '\n';
                                            }
                                        }
                                        cout << "Product ID: " << searched_product.second.getProductId() << '\n';
                                        cout << "Product Name: " << searched_product.second.get_Product_Name() << '\n';
                                        cout << "Store Name it belongs to: " << searched_product.second.getStoreName() << '\n';
                                        cout << "Product Points: " << searched_product.first << '\n';
                                        cout << "Product Price: " << searched_product.second.get_Price() << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "====================================================================" << '\n';
                                        cout << "Do You Want Buy This Product?\n";
                                        while(true)
                                        {
                                            cout << "Answer: ";
                                            getline(cin , answer);
                                            cout << "---------" << '\n';
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            if((answer == "yes") || (answer == "no"))
                                            {
                                                cout << "valid Answer ^^" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                                cout << "----------------" << '\n';
                                                break;
                                            }
                                            cout << "Invalid Answer!!!" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                            cout << "------------------" << '\n';
                                        }
                                        if(answer == "yes")
                                        {
                                            player.Buyproduct(product_name , searched_product.second.get_Price());
                                            admin.Change_budget_of_Player(product_name ,2 , player);
                                            admin.change_Product_counter(product_name , "buy");
                                            player_manager.writeToFile();
                                        }
                                        while(true)
                                        {
                                            cout << "Do You Want To Search about Another Product?" << '\n';
                                            cout << "Answer: ";
                                            getline(cin , answer);
                                            cout << "---------" << '\n';
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            if((answer == "yes") || (answer == "no"))
                                            {
                                                cout << "valid Answer ^^" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                                cout << "---------------" << '\n';
                                                break;
                                            }
                                            cout << "Invalid Answer!!!" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                            cout << "------------------" << '\n';
                                        }
                                    }while(answer != "no");
                                    while(true)
                                    {
                                        cout << "Do You Want Do Another Operation?" << '\n';
                                        cout << "Answer: ";
                                        getline(cin , answer);
                                        cout << "---------" << '\n';
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        if((answer == "yes") || (answer == "no"))
                                        {
                                            cout << "valid Answer ^^" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                            cout << "----------------" << '\n';
                                            break;
                                        }
                                        cout << "Invalid Answer!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "------------------" << '\n';
                                    }
                                }
                                //player search about Store.
                                else if(enter == 2)
                                {
                                    cout << "           ^^ These Are Top 5 Stores In System / You Can Choose one ^^"<<'\n';
                                    admin.display_Top_Rated_Stores();
                                    cout << "           ------------------------------------------------------------" << '\n';
                                    cout << "           ^^ These Are All Stores In System / You Can Choose one ^^"<<'\n';
                                    admin.display_Stores();
                                    cout << "===========================================================================" << '\n';
                                    do
                                    {
                                        string store_name;
                                        pair<double , Store> searched_store;
                                        while(true)
                                        {
                                            cout << "Enter Name Of Store Do You Want: ";
                                            getline(cin , store_name);
                                            cout << "----------------------------------" << '\n';
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            searched_store = admin.iterate_on_Stores_Data(store_name);
                                            if(searched_store.second.get_Null_Checker() == 1)
                                            {
                                                cout << "Store Is Found ^^" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                                cout << "------------------" << '\n';
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Store Not Found!!!" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                                cout << "-------------------" << '\n';
                                            }
                                        }
                                        cout << "           ^^ These Are Top 5 Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                                        admin.Display_Top_Rated_Products(store_name);
                                        cout << "           -------------------------------------------------------------------------------" << '\n';
                                        cout << "           ^^ These Are All Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                                        admin.Display_Products(store_name);
                                        cout << "==========================================================================================" << '\n';
                                        cout << "Do You Want Buy Any Product?\n";
                                        while(true)
                                        {
                                            cout << "Answer: ";
                                            getline(cin , answer);
                                            cout << "---------"<< '\n';
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            if((answer == "yes") || (answer == "no"))
                                            {
                                                cout << "valid Answer ^^" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                                cout << "----------------" << '\n';
                                                break;
                                            }
                                            cout << "Invalid Answer!!!" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                            cout << "------------------" << '\n';
                                        }
                                        if(answer == "yes")
                                        {
                                            while(true)
                                            {
                                                cout << "Enter Product Name Do You Want Buy It: ";
                                                getline(cin , product_name);
                                                cout << "----------------------------------------" << '\n';
                                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                                searched_product = admin.iterate_On_System_Products(product_name);
                                                if(searched_product.second.get_Null_Check() == 1)
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    cout << "Product Not Found!!!" << '\n';
                                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                                    cout << "---------------------" << '\n';
                                                }
                                            }
                                            player.Buyproduct(product_name , searched_product.second.get_Price());
                                            admin.Change_budget_of_Player(product_name ,2 , player);
                                            admin.change_Product_counter(product_name , "buy");
//                                    player_manager.writeToFile();
                                        }
                                        while(true)
                                        {
                                            cout << "Do You Want Do Search about another Store?" << '\n';
                                            cout << "Answer: ";
                                            getline(cin , answer);
                                            cout << "---------" << '\n';
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            if((answer == "yes") || (answer == "no"))
                                            {
                                                cout << "valid Answer ^^" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                                cout << "---------------" << '\n';
                                                break;
                                            }
                                            cout << "Invalid Answer!!!" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                            cout << "------------------" << '\n';
                                        }
                                    }while(answer != "no");
                                    while(true)
                                    {
                                        cout << "Do You Want Do Another Operation?" << '\n';
                                        cout << "Answer: ";
                                        getline(cin , answer);
                                        cout << "---------" << '\n';
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        if((answer == "yes") || (answer == "no"))
                                        {
                                            cout << "valid Answer ^^" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                            cout << "----------------" << '\n';
                                            break;
                                        }
                                        cout << "Invalid Answer!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "------------------" << '\n';
                                    }
                                }
                                //Buy Product
                                else if(enter == 3)
                                {
                                    do
                                    {
                                        while(true)
                                        {
                                            cout << "Enter Product Name Do You Want Buy It: ";
                                            getline(cin , product_name);
                                            cout << "----------------------------------------" << '\n';
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            searched_product = admin.iterate_On_System_Products(product_name);
                                            if(searched_product.second.get_Null_Check() == 1)
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Product Not Found!!!" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                                cout << "---------------------" << '\n';
                                            }
                                        }
                                        player.Buyproduct(product_name , searched_product.second.get_Price());
                                        admin.Change_budget_of_Player(product_name ,2 , player);
                                        admin.change_Product_counter(product_name , "buy");
//                                player_manager.writeToFile();
                                        while(true)
                                        {
                                            cout << "Do You Want Buy Another Product?" << '\n';
                                            cout << "Answer: ";
                                            getline(cin , answer);
                                            cout << "---------" << '\n';
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            if((answer == "yes") || (answer == "no"))
                                            {
                                                cout << "valid Answer ^^" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                                cout << "---------------" << '\n';
                                                break;
                                            }
                                            cout << "Invalid Answer!!!" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                            cout << "------------------" << '\n';
                                        }
                                    }while(answer != "no");
                                    while(true)
                                    {
                                        cout << "Do You Want Do Another Operation?" << '\n';
                                        cout << "Answer: ";
                                        getline(cin , answer);
                                        cout << "---------" << '\n';
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        if((answer == "yes") || (answer == "no"))
                                        {
                                            cout << "valid Answer ^^" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                            cout << "---------------" << '\n';
                                            break;
                                        }
                                        cout << "Invalid Answer!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------" << '\n';
                                    }
                                }
                                //exit
                                else
                                {
                                    cout << "Thank You ^^" << '\n';
                                    goto done;
                                }
                            }while(answer != "no");
                            while(true)
                            {
                                cout << "Do You Want Do Another Operation?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                        }
                        //search about Product after Sign Up.
                        else if(choo == 2)
                        {
                            //check for sign IN
                            if(!player_manager.isPlayerSignedIn())
                            {
                                //sign in First then do operation.
                                cout << "Please, Sign In First" << '\n';
                                int function = 0;
                                while(true)
                                {
                                    cout << "Username: ";
                                    getline(cin , username);
                                    cout << "---------------------------" << '\n';
                                    cout << "Password: ";
                                    getline(cin , password);
                                    cout << "---------------------------" << '\n';
                                    if(player_manager.signInPlayer(username , password , function, player) == 1)
                                    {
                                        cout << "You signed in successfully ^^\n";
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Your Username Or Password Incorrect , Please Sign IN Again!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                }
                                do
                                {
                                    while(true)
                                    {
                                        cout << "Enter Name Of Product Do You Want Search about It: ";
                                        getline(cin , product_name);
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        searched_product = admin.iterate_On_System_Products(product_name);
                                        if(searched_product.second.get_Null_Check() == 1)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Product Not Found!!!" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                            cout << "-----------------------------------------------------" << '\n';
                                        }
                                    }
                                    cout << "Product Name: " << searched_product.second.get_Product_Name() << '\n';
                                    cout << "Store Name it belongs to: " << searched_product.second.getStoreName() << '\n';
                                    cout << "Product Points: " << searched_product.first << '\n';
                                    cout << "Product Price: " << searched_product.second.get_Price() << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "===============================================================================" << '\n';
                                    cout << "Do You Want Buy This Product?\n";
                                    while(true)
                                    {
                                        cout << "Answer: ";
                                        getline(cin , answer);
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        if((answer == "yes") || (answer == "no"))
                                        {
                                            cout << "valid Answer ^^" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                            cout << "-----------------------------------------------------" << '\n';
                                            break;
                                        }
                                        cout << "Invalid Answer!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                    if(answer == "yes")
                                    {
                                        player.Buyproduct(product_name , searched_product.second.get_Price());
                                        admin.Change_budget_of_Player(product_name ,2 , player);
                                        admin.change_Product_counter(product_name , "buy");
                                    }
                                    while(true)
                                    {
                                        cout << "Do You Want Do Search about Another Product?" << '\n';
                                        cout << "Answer: ";
                                        getline(cin , answer);
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        if((answer == "yes") || (answer == "no"))
                                        {
                                            cout << "valid Answer ^^" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                            cout << "-----------------------------------------------------" << '\n';
                                            break;
                                        }
                                        cout << "Invalid Answer!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                }while(answer != "no");
                            }
                            while(true)
                            {
                                cout << "Do You Want Do Another Operation?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                        }
                        //search about Store after Sign Up.
                        else if(choo == 3)
                        {
                            //check for sign IN
                            if(!player_manager.isPlayerSignedIn())
                            {
                                //sign in First then do operation.
                                cout << "Please, Sign In First" << '\n';
                                int function = 0;
                                while(true)
                                {
                                    cout << "Username: ";
                                    getline(cin , username);
                                    cout << "---------------------------" << '\n';
                                    cout << "Password: ";
                                    getline(cin , password);
                                    cout << "---------------------------" << '\n';
                                    if(player_manager.signInPlayer(username , password , function , player) == 1)
                                    {
                                        cout << "You signed in successfully ^^\n";
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Your Username Or Password Incorrect , Please Sign IN Again!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                }
                                cout << "           ^^ These Are Top 5 Stores In System / You Can Choose one ^^"<<'\n';
                                admin.display_Top_Rated_Stores();
                                cout << "           ^^ These Are All Stores In System / You Can Choose one ^^"<<'\n';
                                admin.display_Stores();
                                do
                                {
                                    while(true)
                                    {
                                        cout << "Enter Name Of Store Do You Want: ";
                                        getline(cin , store_name);
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        searched_store = admin.iterate_on_Stores_Data(store_name);
                                        if(searched_store.second.get_Null_Checker() == 1)
                                        {
                                            cout << "Store Is Found ^^" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                            cout << "-----------------------------------------------------" << '\n';
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Store Not Found!!!" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                            cout << "-----------------------------------------------------" << '\n';
                                        }
                                    }
                                    cout << "           ^^ These Are Top 5 Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                                    admin.Display_Top_Rated_Products(store_name);
                                    cout << "           ^^ These Are All Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                                    admin.Display_Products(store_name);
                                    cout << "===============================================================================" << '\n';
                                    cout << "Do You Want Buy Any Product?\n";
                                    while(true)
                                    {
                                        cout << "Answer: ";
                                        getline(cin , answer);
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        if((answer == "yes") || (answer == "no"))
                                        {
                                            cout << "valid Answer ^^" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                            cout << "-----------------------------------------------------" << '\n';
                                            break;
                                        }
                                        cout << "Invalid Answer!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                    if(answer == "yes")
                                    {
                                        while(true)
                                        {
                                            cout << "Enter Product Name Do You Want Buy It: ";
                                            getline(cin , product_name);
                                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                            searched_product = admin.iterate_On_System_Products(product_name);
                                            if(searched_product.second.get_Null_Check() == 1)
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Product Not Found!!!" << '\n';
                                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                                cout << "-----------------------------------------------------" << '\n';
                                            }
                                        }
                                        player.Buyproduct(product_name , searched_product.second.get_Price());
                                        admin.Change_budget_of_Player(product_name ,2 , player);
                                        admin.change_Product_counter(product_name , "buy");
//
                                    }
                                    while(true)
                                    {
                                        cout << "Do You Want Do Search about another Store?" << '\n';
                                        cout << "Answer: ";
                                        getline(cin , answer);
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        if((answer == "yes") || (answer == "no"))
                                        {
                                            cout << "valid Answer ^^" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                            cout << "-----------------------------------------------------" << '\n';
                                            break;
                                        }
                                        cout << "Invalid Answer!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                }while(answer != "no");
                            }
                            while(true)
                            {
                                cout << "Do You Want Do Another Operation?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                        }
                        //buy after Sign Up
                        else if(choo == 4)
                        {
                            //sign in First then do operation.
                            cout << "Please, Sign In First" << '\n';
                            int function = 0;
                            while(true)
                            {
                                cout << "Username: ";
                                getline(cin , username);
                                cout << "---------------------------" << '\n';
                                cout << "Password: ";
                                getline(cin , password);
                                cout << "---------------------------" << '\n';
                                if(player_manager.signInPlayer(username , password , function , player) == 1)
                                {
                                    cout << "You signed in successfully ^^\n";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Your Username Or Password Incorrect , Please Sign IN Again!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                            do
                            {
                                while(true)
                                {
                                    cout << "Enter Product Name Do You Want Buy It: ";
                                    getline(cin , product_name);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    searched_product = admin.iterate_On_System_Products(product_name);
                                    if(searched_product.second.get_Null_Check() == 1)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Product Not Found!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                }
                                player.Buyproduct(product_name , searched_product.second.get_Price());
                                admin.Change_budget_of_Player(product_name ,2 , player);
                                admin.change_Product_counter(product_name , "buy");
                                while(true)
                                {
                                    cout << "Do You Want Buy Another Product?" << '\n';
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }while(answer != "no");
                            while(true)
                            {
                                cout << "Do You Want Do Another Operation?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                        }
                        //exit after Sign Up
                        else
                        {
                            //ask for competition.
                            cout << "Do You Want Exit?" << '\n';
                            while(true)
                            {
                                cout << "Do You Want Access The System Again?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                            if(answer == "yes")
                            {
                                if(player.getdecoration().size() >= 5)
                                {
                                    admin.calculate_points(player);
                                    player_manager.signOutPlayer();
                                    goto done;
                                }
                                else
                                {
                                    cout << "Your decoration set must contains at least five products!!!!!!" << '\n';
                                    answer = "yes";
                                    goto competition;
                                }
                            }
                            else
                            {
                                answer = "yes";
                                goto competition;
                            }
                        }
                    }
                    else
                    {
                        cout << "Press :" << '\n';
                        cout << "1-If You Want Search About Product\n";
                        cout << "2-If You Want Search About Store\n";
                        cout << "3-If You Want Buy Product\n";
                        cout << "4-If You Want Exit\n";
                        while(true)
                        {
                            cin >> choo;
                            cin.ignore();
                            if(choo == 1 || choo == 2 || choo == 3 || choo == 4)
                            {
                                cout << "Valid Choice ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Operation!!! / Please,Enter Operation again: ";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                        //search about Product after Sign Up.
                        if(choo == 1)
                        {
                            do
                            {
                                while(true)
                                {
                                    cout << "Enter Name Of Product Do You Want Search about It: ";
                                    getline(cin , product_name);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    searched_product = admin.iterate_On_System_Products(product_name);
                                    if(searched_product.second.get_Null_Check())
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Product Not Found!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                }
                                cout << "Product Name: " << searched_product.second.get_Product_Name() << '\n';
                                cout << "Store Name it belongs to: " << searched_product.second.getStoreName() << '\n';
                                cout << "Product Points: " << searched_product.first << '\n';
                                cout << "Product Price: " << searched_product.second.get_Price() << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "===============================================================================" << '\n';
                                cout << "Do You Want Buy This Product?\n";
                                while(true)
                                {
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                                if(answer == "yes")
                                {
                                    player.Buyproduct(product_name , searched_product.second.get_Price());
                                    admin.Change_budget_of_Player(product_name ,2 , player);
                                    admin.change_Product_counter(product_name , "buy");
                                }
                                while(true)
                                {
                                    cout << "Do You Want Do Search about Another Product?" << '\n';
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }while(answer != "no");
                            while(true)
                            {
                                cout << "Do You Want Do Another Operation?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                        }
                        //search about Store after Sign Up.
                        else if(choo == 2)
                        {
                            cout << "           ^^ These Are Top 5 Stores In System / You Can Choose one ^^"<<'\n';
                            admin.display_Top_Rated_Stores();
                            cout << "           ^^ These Are All Stores In System / You Can Choose one ^^"<<'\n';
                            admin.display_Stores();
                            do
                            {
                                while(true)
                                {
                                    cout << "Enter Name Of Store Do You Want: ";
                                    getline(cin , store_name);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    searched_store = admin.iterate_on_Stores_Data(store_name);
                                    if(searched_store.second.get_Null_Checker() == 1)
                                    {
                                        cout << "Store Is Found ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Store Not Found!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                }
                                cout << "           ^^ These Are Top 5 Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                                admin.Display_Top_Rated_Products(store_name);
                                cout << "           ^^ These Are All Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                                admin.Display_Products(store_name);
                                cout << "===============================================================================" << '\n';
                                cout << "Do You Want Buy Any Product?\n";
                                while(true)
                                {
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                                if(answer == "yes")
                                {
                                    while(true)
                                    {
                                        cout << "Enter Product Name Do You Want Buy It: ";
                                        getline(cin , product_name);
                                        transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                        searched_product = admin.iterate_On_System_Products(product_name);
                                        if(searched_product.second.get_Null_Check() == 1)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Product Not Found!!!" << '\n';
                                            std::this_thread::sleep_for(std::chrono::seconds(0));
                                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                            cout << "-----------------------------------------------------" << '\n';
                                        }
                                    }
                                    player.Buyproduct(product_name , searched_product.second.get_Price());
                                    admin.Change_budget_of_Player(product_name ,2 , player);
                                    admin.change_Product_counter(product_name , "buy");
//                          player_manager.writePlayerToFile(player);
                                }
                                while(true)
                                {
                                    cout << "Do You Want Do Search about another Store?" << '\n';
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }while(answer != "no");
                            while(true)
                            {
                                cout << "Do You Want Do Another Operation?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                        }
                        //buy after Sign Up
                        else if(choo == 3)
                        {
                            do
                            {
                                while(true)
                                {
                                    cout << "Enter Product Name Do You Want Buy It: ";
                                    getline(cin , product_name);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    searched_product = admin.iterate_On_System_Products(product_name);
                                    if(searched_product.second.get_Null_Check() == 1)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Product Not Found!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                    }
                                }
                                player.Buyproduct(product_name , searched_product.second.get_Price());
                                admin.Change_budget_of_Player(product_name ,2 , player);
                                admin.change_Product_counter(product_name , "buy");
                                while(true)
                                {
                                    cout << "Do You Want Buy Another Product?" << '\n';
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------------------------------------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }while(answer != "no");
                            while(true)
                            {
                                cout << "Do You Want Do Another Operation?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                        }
                        //exit after Sign Up
                        else
                        {
                            //ask for competition.
                            cout << "Do You Want Exit?" << '\n';
                            while(true)
                            {
                                cout << "Do You Want Access The System Again?" << '\n';
                                getline(cin , answer);
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if(answer == "yes" || answer == "no")
                                {
                                    cout << "Valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                            if(answer == "yes")
                            {
                                if(player.getdecoration().size() >= 5)
                                {
                                    admin.calculate_points(player);
                                    player_manager.signOutPlayer();
                                    goto done;
                                }
                                else
                                {
                                    cout << "Your decoration set must contains at least five products!!!!!!" << '\n';
                                    answer = "yes";
                                    goto competition;
                                }
                            }
                            else
                            {
                                answer = "yes";
                                goto competition;
                            }
                        }
                    }
                    op++;
                    competition:{};
                }while(answer != "no");
            }
            // user
            else
            {
                int u_id , sign_Up_Returned;
                while(true)
                {
                    cout << "ID: ";
                    cin >> u_id;
                    cin.ignore();
                    cout << "----------" << '\n';
                    cout << "UserName: ";
                    getline(cin , username);
                    cout << "-----------" << '\n';
                    while(true)
                    {
                        cout << "Password: ";

                        getline(cin , password);
                        if(admin.Check_Validate_on_Password(password))
                        {
                            cout << "Valid Password ^^" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "------------------" << '\n';
                            break;
                        }
                        else
                        {
                            cout << "Invalid Password!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "Your password must contain:\n"
                                    "\n"
                                    "X At least 8 characters\n"
                                    "\n"
                                    "X At least 3 of the following:\n"
                                    "\n"
                                    "X Lower case letters (a-z)\n"
                                    "\n"
                                    "X Upper case letters (A-Z)\n"
                                    "\n"
                                    "X Numbers (0-9)\n"
                                    "\n"
                                    "X Special characters (ex. !@#$%^&*)"<<'\n';
                            cout <<"----------------------------------------------" << '\n';
                        }
                    }
                    cout << "----------" << '\n';
                    while(true)
                    {
                        cout << "Email: ";
                        getline(cin , email);
                        if(admin.Check_Validate_On_Email(email))
                        {
                            cout << "Valid Email ^^" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "-----------------------------------------------------" << '\n';
                            break;
                        }
                        else
                        {
                            cout << "Invalid Email!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-----------------------------------------------------" << '\n';
                            cout << "Your Email must Be Like :(example@gmail.com)"<<'\n';
                            cout <<"----------------------------------------------" << '\n';
                        }
                    }
                    cout << "----------" << '\n';
                    sign_Up_Returned = user_manager.signUpUser(u_id ,username , password , email , player_manager.Players);
                    if(-1 == sign_Up_Returned)
                    {
                        cout << "This Username Is Already exist/Please Enter Your Data again!!!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "-----------------------------------------------------------------" << '\n';
                    }
                    else if(-2 == sign_Up_Returned)
                    {
                        cout << "This Password,ID or Email Is Already exist/Please Enter Your Data again!!!!" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "----------------------------------------------------------------------" << '\n';
                    }
                    else if(1 == sign_Up_Returned)
                    {
                        //call function write
                        break;
                    }
                }
                cout << "Press :" << '\n';
                cout << "1-If You Want Sign In" << '\n';
                cout << "2-If You Want Search About Store\n";
                cout << "3-If You Want Exit\n";
                while(true)
                {
                    cin >> choo;
                    cin.ignore();
                    if(choo == 1 || choo == 2 || choo == 3 || choo == 4 || choo == 5)
                    {
                        cout << "Valid Choice ^^" << '\n';
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                        cout << "----------------" << '\n';
                        break;
                    }
                    else
                    {
                        cout << "Invalid Operation!!! / Please,Enter Operation again: ";
                        std::this_thread::sleep_for(std::chrono::seconds(0));
                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                        cout << "------------------------------------------------------" << '\n';
                    }
                }
                if(choo == 1)
                {
                    int function = 0;
                    user_manager.user_read();
                    while(true)
                    {
                        cout << "Username: ";
                        getline(cin , username);
                        cout << "-----------" << '\n';
                        cout << "Password: ";
                        getline(cin , password);
                        cout << "-----------" << '\n';
                        if(user_manager.signInUser(username , password , function) == 1)
                        {
                            cout << "You signed in successfully ^^\n";
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "-----------------------------------------------------" << '\n';
                            break;
                        }
                        else
                        {
                            cout << "Your Username Or Password Incorrect , Please Sign IN Again!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-------------------------------------------------------------" << '\n';
                        }
                    }
                    int enter;
                    cout << "Press :" << '\n';
                    cout << "1-If You Want Search About Store\n";
                    cout << "2-If You Want Exit\n";
                    while(true)
                    {
                        cin >> enter;
                        cin.ignore();
                        if(enter == 1 || enter == 2)
                        {
                            cout << "Valid Choice ^^" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "---------------" << '\n';
                            break;
                        }
                        else
                        {
                            cout << "Invalid Operation/Please,Enter Operation again!!!!!";
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-----------------------------------------------------" << '\n';
                        }
                    }
                    //user search about Store.
                    if(enter == 1)
                    {
                        user.Search_for_Store_When_Sign_Up(admin.get_Stores_List());
                        cout << "Thank You ^^" << '\n';
                        goto done;
                    }
                    else
                    {
                        cout << "Thank You ^^" << '\n';
                        goto done;
                    }
                }
                else if(choo == 2)
                {
                    //check for sign IN
                    if(!user_manager.isUserSignedIn())
                    {
                        //sign in First then do operation.
                        cout << "Please, Sign In First" << '\n';
                        int function = 0;
                        while(true)
                        {
                            cout << "Username: ";
                            getline(cin , username);
                            cout << "-----------" << '\n';
                            cout << "Password: ";
                            getline(cin , password);
                            cout << "-----------" << '\n';
                            if(user_manager.signInUser(username , password , function) == 1)
                            {
                                cout << "You signed in successfully ^^\n";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "--------------------------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Your Username Or Password Incorrect , Please Sign IN Again!!!" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "--------------------------------------------------------------" << '\n';
                            }
                        }
                        user.Search_for_Store_When_Sign_Up(admin.get_Stores_List());
                        cout << "Thank You ^^" << '\n';
                        goto done;
                    }
                }
                else
                {
                    user_manager.signOutUser();
                    goto done;
                }
            }
        }
        //sign in (player / User / Admin)
        else if(operation == 2 && answer == "sign in")
        {
            int function = 0 , check;
            while(true)
            {
                cout << "Username: ";
                getline(cin , username);
                cout << "---------------------------" << '\n';
                cout << "Password: ";
                getline(cin , password);
                cout << "---------------------------" << '\n';
//            player_manager.readfromfile();
//            user_manager.readUsersFromFile("/Users/admin/Desktop/Home_Decor/userdata.txt");
                if(player_manager.signInPlayer(username , password , function , player) == 1 || user_manager.signInUser(username , password , function) == 1 || admin.Sign_In(username , password, function) == 1)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Data!!!" << '\n';
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                    cout << "-----------------------------------------------------" << '\n';
                }
            }
            //check for function
            if(function == 1)
            {
                //player
                cout << "Player signed in successfully ^^\n";
                std::this_thread::sleep_for(std::chrono::seconds(0));
                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "-----------------------------------------------------" << '\n';
                do
                {
                    int enter;
                    cout << "Press :" << '\n';
                    cout << "1-If You Want Search About Product\n";
                    cout << "2-If You Want Search About Store\n";
                    cout << "3-If You Want Buy Product\n";
                    cout << "4-If You Want Sell Product\n";
                    cout << "5-If You Want Replace Product\n";
                    cout << "6-If You Want Edit your information\n";
                    cout << "7-If You Want Exit\n";
                    while(true)
                    {
                        cin >> enter;
                        cin.ignore();
                        if(enter == 1 || enter == 2 || enter == 3 || enter == 4 || enter == 5 || enter == 6)
                        {
                            cout << "Valid Choice ^^" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "------------------" << '\n';
                            break;
                        }
                        else
                        {
                            cout << "Invalid Operation!!! / Please,Enter Operation again: ";
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-----------------------------------------------------" << '\n';
                        }
                    }
                    //player search about product.
                    if(enter == 1)
                    {
                        do
                        {
                            while(true)
                            {
                                cout << "Enter Name Of Product Do You Want Search about It: ";
                                getline(cin , product_name);
                                cout << "-----------------------------------------------------" << '\n';
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                searched_product = admin.iterate_On_System_Products(product_name);
                                if(searched_product.second.get_Null_Check() == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Product Not Found!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                            cout << "Product Name: " << searched_product.second.get_Product_Name() << '\n';
                            cout << "Store Name it belongs to: " << searched_product.second.getStoreName() << '\n';
                            cout << "Product Points: " << searched_product.first << '\n';
                            cout << "Product Price: " << searched_product.second.get_Price() << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "===============================================================================" << '\n';
                            cout << "Press :" << '\n';
                            cout << "1-If You Want Buy This Product\n";
                            cout << "2-If You Want Replace This Product\n";
                            cout << "3-If You Want Exit\n";
                            while(true)
                            {
                                cin >> enter;
                                cin.ignore();
                                if(enter == 1 || enter == 2 || enter == 3)
                                {
                                    cout << "Valid Choice ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Operation!!! / Please,Enter Operation again: ";
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-----------------------------------------------------" << '\n';
                                }
                            }
                            if(enter == 1)
                            {
                                player.Buyproduct(product_name , searched_product.second.get_Price());
                                admin.Change_budget_of_Player(product_name ,2 , player);
                                admin.change_Product_counter(product_name , "buy");
                                while(true)
                                {
                                    cout << "Do You Want Do Search about Another Product?" << '\n';
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    cout << "---------" << '\n';
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "----------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "------------------" << '\n';
                                }
                            }
                            else if(enter == 2)
                            {
                                string old_product = player.Replaceproduct(product_name , searched_product.second.get_Price());
                                admin.Change_budget_of_Player(old_product , 3 , player , searched_product.second.get_Price());
                                admin.change_Product_counter(product_name , "replace" , old_product);
                                while(true)
                                {
                                    cout << "Do You Want Do Search about Another Product?" << '\n';
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    cout << "---------" << '\n';
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "----------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "------------------" << '\n';
                                }
                            }
                            else
                            {
                                goto outing;
                            }
                        }while(answer != "no");
                        outing:{};
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            cout << "Answer: ";
                            getline(cin , answer);
                            cout << "---------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if((answer == "yes") || (answer == "no"))
                            {
                                cout << "valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "---------------" << '\n';
                                break;
                            }
                            cout << "Invalid Answer!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "------------------" << '\n';
                        }
                    }
                    //player search about Store.
                    else if(enter == 2)
                    {
                        do
                        {
                            int press;
                            cout << "Press:\n";
                            cout << "1-If You Know Store Name\n";
                            cout << "2-If You don't Know Store Name\n";
                            do
                            {
                                cin >> press;
                                if(press == 1 || press == 2)
                                {
                                    cout << "valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "-----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-------------------" << '\n';
                                }
                            }while(true);
                            if(press == 2)
                            {
                                cout << "           ^^ These Are Top 5 Stores In System / You Can Choose one ^^"<<'\n';
                                admin.display_Top_Rated_Stores();
                                cout << "           ------------------------------------------------------------" << '\n';
                                cout << "           ^^ These Are All Stores In System / You Can Choose one ^^"<<'\n';
                                admin.display_Stores();
                            }
                            string store_name;
                            pair<double , Store> searched_store;
                            while(true)
                            {
                                cout << "Enter Name Of Store Do You Want: ";
                                getline(cin , store_name);
                                cout << "----------------------------------" << '\n';
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                searched_store = admin.iterate_on_Stores_Data(store_name);
                                if(searched_store.second.get_Null_Checker() == 1)
                                {
                                    cout << "Store Is Found ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "------------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Store Not Found!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-------------------" << '\n';
                                }
                            }
                            cout << "           ^^ These Are Top 5 Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                            admin.Display_Top_Rated_Products(store_name);
                            cout << "            -------------------------------------------------------------------------------" << '\n';
                            cout << "           ^^ These Are All Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                            admin.Display_Products(store_name);
                            cout << "===============================================================================" << '\n';
                            cout << "Press :" << '\n';
                            cout << "1-If You Want Buy Product\n";
                            cout << "2-If You Want Replace Product\n";
                            cout << "3-If You Want Exit\n";
                            do
                            {
                                cin >> press;
                                if(press == 1 || press == 2 || press == 3)
                                {
                                    cout << "valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "------------------" << '\n';
                                }
                            }while(true);
                            if(press == 1)
                            {
                                while(true)
                                {
                                    cout << "Enter Product Name Do You Want Buy It: ";
                                    getline(cin , product_name);
                                    cout << "----------------------------------------" << '\n';
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    searched_product = admin.iterate_On_System_Products(product_name);
                                    if(searched_product.second.get_Null_Check() == 1)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Product Not Found!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "--------------------" << '\n';
                                    }
                                }
                                player.Buyproduct(product_name , searched_product.second.get_Price());
                                admin.Change_budget_of_Player(product_name ,2 , player);
                                admin.change_Product_counter(product_name , "buy");
                                while(true)
                                {
                                    cout << "Do You Want Do Search about another Store?" << '\n';
                                    cout << "Answer: ";
                                    getline(cin , answer);
                                    cout << "----------" << '\n';
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "----------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "------------------" << '\n';
                                }
                            }
                            else if(press == 2)
                            {
                                while(true)
                                {
                                    cout << "Enter Product Name Do You Want Sell It: ";
                                    getline(cin , product_name);
                                    cout << "-----------------------------------------" << '\n';
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    searched_product = admin.iterate_On_System_Products(product_name);
                                    if(searched_product.second.get_Null_Check() == 1)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Product Not Found!!!" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                        cout << "---------------------" << '\n';
                                    }
                                }
                                old_product = player.Replaceproduct(product_name , searched_product.second.get_Price());
                                admin.Change_budget_of_Player(old_product,3 , player , searched_product.second.get_Price());
                                admin.change_Product_counter(product_name , "replace" , old_product);
                                while(true)
                                {
                                    cout << "Do You Want Do Search about another Store?" << '\n';
                                    cout << "Answer: ";
                                    cout << "-------------------------------------------" << '\n';
                                    getline(cin , answer);
                                    transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                    if((answer == "yes") || (answer == "no"))
                                    {
                                        cout << "valid Answer ^^" << '\n';
                                        std::this_thread::sleep_for(std::chrono::seconds(0));
                                        admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                        cout << "-----------------" << '\n';
                                        break;
                                    }
                                    cout << "Invalid Answer!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-------------------" << '\n';
                                }
                            }
                            else
                            {
                                cout << "Thank You ^^" << '\n';
                                goto out;
                            }
                        }while(answer != "no");
                        out:{};
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            cout << "Answer: ";
                            getline(cin , answer);
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if((answer == "yes") || (answer == "no"))
                            {
                                cout << "valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                                break;
                            }
                            cout << "Invalid Answer!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-----------------------------------------------------" << '\n';
                        }
                    }
                    //Buy Product
                    else if(enter == 3)
                    {
                        do
                        {
                            string name , pro_name;
                            cout << "Enter Name Of Store You Want Buy Products from it:" ;
                            while(true)
                            {
                                getline(cin , name);
                                transform(name.begin(), name.end(), name.begin(), [](unsigned char c){ return std::tolower(c); });
                                searched_store = admin.iterate_on_Stores_Data(name);
                                if(!searched_store.second.get_Null_Checker())
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Store Not Found!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "-------------------" << '\n';
                                }
                            }
                            cout << "           ^^ These Are Top 5 Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                            admin.Display_Top_Rated_Products(name);
                            cout << "            -------------------------------------------------------------------------------" << '\n';
                            cout << "           ^^ These Are All Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                            admin.Display_Products(name);
                            cout << "===============================================================================" << '\n';
                            while(true)
                            {
                                cout << "Enter Product Name Do You Want Buy It: ";
                                getline(cin , pro_name);
                                cout << "----------------------------------------" << '\n';
                                transform(pro_name.begin(), pro_name.end(), pro_name.begin(), [](unsigned char c){ return std::tolower(c); });
                                searched_product = admin.iterate_On_System_Products(pro_name);
                                if(searched_product.second.get_Null_Check())
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Product Not Found!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "---------------------" << '\n';
                                }
                            }
                            player.Buyproduct(product_name , searched_product.second.get_Price());
                            admin.Change_budget_of_Player(product_name ,2 , player);
                            admin.change_Product_counter(product_name , "buy");
                            while(true)
                            {
                                cout << "Do You Want Buy Another Product?" << '\n';
                                cout << "Answer: ";
                                getline(cin , answer);
                                cout << "---------" << '\n';
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if((answer == "yes") || (answer == "no"))
                                {
                                    cout << "valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                cout << "Invalid Answer!!!" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "------------------" << '\n';
                            }
                        }while(answer != "no");
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            cout << "Answer: ";
                            getline(cin , answer);
                            cout << "---------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if((answer == "yes") || (answer == "no"))
                            {
                                cout << "valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "-----------------" << '\n';
                                break;
                            }
                            cout << "Invalid Answer!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-----------------" << '\n';
                        }
                    }
                    else if(enter == 4)
                    {
                        do
                        {
                            vector<pair<string, double>> Décoration_set = player.getdecoration();
                            cout << "           ^^ These Are The Products In Your Décoration Set ,Please Choose one To Sell it^^"<<'\n';
                            cout << "Product Name" << "|" <<  "Product Price" << '\n';
                            cout << "---------------------------------------" << '\n';
                            for(auto it : Décoration_set)
                            {
                                cout << it.first << "|" << it.second << '\n';
                            }
                            cout << "===========================================================================================" << '\n';
                            while(true)
                            {
                                cout << "Enter Product Name Do You Want Sell It: ";
                                getline(cin , product_name);
                                cout << "-----------------------------------------" << '\n';
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                searched_product = admin.iterate_On_System_Products(product_name);
                                if(searched_product.second.get_Null_Check() == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Product Not Found!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "---------------------" << '\n';
                                }
                            }
                            player.Sellproduct(product_name);
                            admin.Change_budget_of_Player(product_name ,1 , player);
                            admin.change_Product_counter(product_name , "sell");
                            while(true)
                            {
                                cout << "Do You Want Buy Another Product?" << '\n';
                                cout << "Answer: ";
                                getline(cin , answer);
                                cout << "---------" << '\n';
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if((answer == "yes") || (answer == "no"))
                                {
                                    cout << "valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "----------------" << '\n';
                                    break;
                                }
                                cout << "Invalid Answer!!!" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "------------------" << '\n';
                            }
                        }while(answer != "no");
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            cout << "Answer: ";
                            getline(cin , answer);
                            cout << "--------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if((answer == "yes") || (answer == "no"))
                            {
                                cout << "valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            cout << "Invalid Answer!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-----------------" << '\n';
                        }
                    }
                    else if(enter == 5)
                    {
                        do
                        {
                            cout << "           ^^ These Are Top 5 Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                            admin.Display_Top_Rated_Products(store_name);
                            cout << "           --------------------------------------------------------------------------------" << '\n';
                            cout << "           ^^ These Are All Products In " << store_name << "Store /You Can Choose one ^^"<<'\n';
                            admin.Display_Products(store_name);
                            cout << "===============================================================================" << '\n';
                            while(true)
                            {
                                cout << "Enter Product Name Do You Want Replace another one with it: ";
                                getline(cin , product_name);
                                cout << "--------------------------------------------------------------" << '\n';
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                searched_product = admin.iterate_On_System_Products(product_name);
                                if(searched_product.second.get_Null_Check() == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Product Not Found!!!" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                    cout << "--------------------" << '\n';
                                }
                            }
                            old_product = player.Replaceproduct(product_name , searched_product.second.get_Price());
                            admin.Change_budget_of_Player(old_product ,3 , player , searched_product.second.get_Price());
                            admin.change_Product_counter(product_name , "replace" , old_product);
                            while(true)
                            {
                                cout << "Do You Want Replace Another Product?" << '\n';
                                cout << "Answer: ";
                                getline(cin , answer);
                                cout << "--------" << '\n';
                                transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                                if((answer == "yes") || (answer == "no"))
                                {
                                    cout << "valid Answer ^^" << '\n';
                                    std::this_thread::sleep_for(std::chrono::seconds(0));
                                    admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                    cout << "-----------------" << '\n';
                                    break;
                                }
                                cout << "Invalid Answer!!!" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------" << '\n';
                            }
                        }while(answer != "no");
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            cout << "Answer: ";
                            getline(cin , answer);
                            cout << "--------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if((answer == "yes") || (answer == "no"))
                            {
                                cout << "valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            cout << "Invalid Answer!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "------------------" << '\n';
                        }
                    }
                    else if(enter == 6)
                    {
                        player_manager.Edit_Information_of_player(user_manager.users);
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            cout << "Answer: ";
                            getline(cin , answer);
                            cout << "--------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if((answer == "yes") || (answer == "no"))
                            {
                                cout << "valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "------------------" << '\n';
                                break;
                            }
                            cout << "Invalid Answer!!!" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-------------------" << '\n';
                        }
                    }
                    else
                    {
                        cout << "Do You Want Exit?" << '\n';
                        while(true)
                        {
                            cout << "Do You Want Access The System Again?" << '\n';
                            getline(cin , answer);
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                        if(answer == "yes")
                        {
                            if(player.getdecoration().size() >= 5)
                            {
                                admin.calculate_points(player);
                                player_manager.signOutPlayer();
                                goto done;
                            }
                            else
                            {
                                cout << "You Can't Exit/Your decoration set must contains at least five products!!!!!!" << '\n';
                                answer = "yes";
                                goto end;
                            }
                        }
                        else
                        {
                            answer = "yes";
                            goto end;
                        }
                    }
                    end:{};
                }while(answer != "no");
            }
            else if(function == 2)
            {
                int enter;
                //user
                cout << "User signed in successfully ^^\n";
                std::this_thread::sleep_for(std::chrono::seconds(0));
                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "--------------------------------" << '\n';
                //user search about Store.
                do
                {
                    cout << "Press :" << '\n';
                    cout << "1-If You Want Search About Store\n";
                    cout << "2-If You Want Edit Your information\n";
                    cout << "3-If You Want Exit\n";
                    while(true)
                    {
                        cin >> enter;
                        cin.ignore();
                        if(enter == 1 || enter == 2 || enter == 3)
                        {
                            cout << "Valid Choice ^^" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "----------------" << '\n';
                            break;
                        }
                        else
                        {
                            cout << "Invalid Operation!!! / Please,Enter Operation again: ";
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "-----------------------------------------------------" << '\n';
                        }
                    }
                    if(enter == 1)
                    {
                        user.Search_for_Store(admin.get_Stores_List());
                        while(true)
                        {
                            cout << "Do You Want Do Another operation?" << '\n';
                            getline(cin , answer);
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                    }
                    else if(enter == 2)
                    {
                        user_manager.editUser(player_manager.Players);
                        while(true)
                        {
                            cout << "Do You Want Do Another operation?" << '\n';
                            getline(cin , answer);
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                    }
                    else
                    {
                        cout << "Thank You ^^" << '\n';
                        goto done;
                    }
                }while(answer != "no");
            }
            else
            {
                //Admin
                int press;
                string default_store_name;
                cout << "You signed in successfully ^^\n";
                std::this_thread::sleep_for(std::chrono::seconds(0));
                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "---------------------------------" << '\n';
                do
                {
                    while(true)
                    {
                        cout << "Press :" << '\n';
                        cout << "1-Add New Store." << '\n';
                        cout << "2-Update Information About Store." << '\n';
                        cout << "3-Remove Store." << '\n';
                        cout << "4-Add New Product In certain Store." << '\n';
                        cout << "5-Update Information Any Product." << '\n';
                        cout << "6-Remove Any Product From Any store" << '\n';
                        cout << "7-Sign OUT" << '\n';
                        cin >> press;
                        cin.ignore();
                        if(press == 1 || press == 2 || press == 3 || press == 4 || press == 5 || press == 6 || press == 7)
                        {
                            cout << "Valid Choice ^^" << '\n';
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                            cout << "----------------" << '\n';
                            break;
                        }
                        else
                        {
                            cout << "Invalid Operation!!! / Please,Enter Operation again: ";
                            std::this_thread::sleep_for(std::chrono::seconds(0));
                            admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                            cout << "------------------------------------------------------" << '\n';
                        }
                    }
                    if(press == 1)
                    {
                        admin.Add_Store();
                        admin.write_store();
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            getline(cin , answer);
                            cout << "--------------------------------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                    }
                    else if(press == 2)
                    {
                        admin.update_Store_Information();
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            getline(cin , answer);
                            cout << "--------------------------------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                    }
                    else if(press == 3)
                    {
                        admin.Remove_Store();
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            getline(cin , answer);
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                    }
                    else if(press == 4)
                    {
                        cout <<"Enter The Store Name Would Do You Want Add Product To IT" << '\n';
                        getline(cin , default_store_name);
                        cout << "-------------------------------------------------------" << '\n';
                        pair<double , Store> store = admin.iterate_on_Stores_Data(default_store_name);
                        priority_queue<pair<double , Product>> pro_temp = priority_queue<pair<double , Product>>(store.second.get_Product_List());
                        admin.Add_New_Product(pro_temp , default_store_name);
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            getline(cin , answer);
                            cout << "--------------------------------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                    }
                    else if(press == 5)
                    {
                        cout <<"Enter The Store Name Would Do You Want Update its Product Information" << '\n';
                        getline(cin , default_store_name);
                        cout << "---------------------------------------------------------------------" << '\n';
                        pair<double , Store> store = admin.iterate_on_Stores_Data(default_store_name);
                        priority_queue<pair<double , Product>> pro_temp = priority_queue<pair<double , Product>>(store.second.get_Product_List());
                        admin.Update_Product_Information(pro_temp , default_store_name);
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            getline(cin , answer);
                            cout << "--------------------------------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                    }
                    else if(press == 6)
                    {
                        cout <<"Enter The Store Name Would Do You Want Remove Product From IT" << '\n';
                        getline(cin , default_store_name);
                        cout << "--------------------------------------------------------------" << '\n';
                        pair<double , Store> store = admin.iterate_on_Stores_Data(default_store_name);
                        priority_queue<pair<double , Product>> pro_temp = priority_queue<pair<double , Product>>(store.second.get_Product_List());
                        admin.Remove_Product(pro_temp, default_store_name);
                        while(true)
                        {
                            cout << "Do You Want Do Another Operation?" << '\n';
                            getline(cin , answer);
                            cout << "--------------------------------" << '\n';
                            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
                            if(answer == "yes" || answer == "no")
                            {
                                cout << "Valid Answer ^^" << '\n';
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                                cout << "----------------" << '\n';
                                break;
                            }
                            else
                            {
                                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                                std::this_thread::sleep_for(std::chrono::seconds(0));
                                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                                cout << "-----------------------------------------------------" << '\n';
                            }
                        }
                    }
                    else{
                        admin.Sign_Out();
                        goto done;
                    }
                }while(answer != "no");
            }
        }
        done:{};
        while(true)
        {
            cout << "Do You Want Access The System Again?" << '\n';
            getline(cin , answer);
            transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c){ return std::tolower(c); });
            if(answer == "yes" || answer == "no")
            {
                cout << "Valid Answer ^^" << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(0));
                admin.Sounds("/Users/admin/Desktop/Home_Decor/rigth.ogg");
                cout << "----------------" << '\n';
                break;
            }
            else
            {
                cout << "Invalid Answer/Please,Enter Your Answer again!!!!";
                std::this_thread::sleep_for(std::chrono::seconds(0));
                admin.Sounds("/Users/admin/Desktop/Home_Decor/error.ogg");
                cout << "-----------------------------------------------------" << '\n';
            }
        }
        if(answer == "no")
        {
            admin.write_store();
            user_manager.user_write();
            player_manager.writeToFile();
        }
    }while(answer != "no");
    return 0;
}









