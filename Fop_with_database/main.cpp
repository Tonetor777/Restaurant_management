#include <iostream>
#include <mysql.h>
#include <iomanip>
#include <string.h>
#include<fstream>
using namespace std;


fstream OrderTrack,about_us, report;
int  order_no = 0, food_no, drink_no;
double price, daily_income = 0;

struct order_track
{
    int food [10];
    int food_quantity[10];
    int drink[10];
    int drink_quantity[10];
    double total_price;
    int table_no;
} order[200];



int option()
{
    system("cls");
    lable:
    cout << "    ________________________________________________________________________________________________________________________" << endl << endl;
    cout << " SSSSS    AAA   LL      EEEEEEE MM    MM    RRRRRR  EEEEEEE  SSSSS  TTTTTTT   AAA   UU   UU RRRRRR    AAA   NN   NN TTTTTTT " << endl;
    cout << "SS       AAAAA  LL      EE      MMM  MMM    RR   RR EE      SS        TTT    AAAAA  UU   UU RR   RR  AAAAA  NNN  NN   TTT   " << endl;
    cout << " SSSSS  AA   AA LL      EEEEE   MM MM MM    RRRRRR  EEEEE    SSSSS    TTT   AA   AA UU   UU RRRRRR  AA   AA NN N NN   TTT   " << endl;
    cout << "     SS AAAAAAA LL      EE      MM    MM    RR  RR  EE           SS   TTT   AAAAAAA UU   UU RR  RR  AAAAAAA NN  NNN   TTT   " << endl;
    cout << " SSSSS  AA   AA LLLLLLL EEEEEEE MM    MM    RR   RR EEEEEEE  SSSSS    TTT   AA   AA  UUUUU  RR   RR AA   AA NN   NN   TTT   " << endl;
    cout << "    ________________________________________________________________________________________________________________________" << endl << endl;
    int option, password;  // password = 3214
    cout << "WELCOME TO SALEM RESATURANT\n\n";
    cout << "OPTIONS" << endl;
    cout << "1. Customer" << endl;
    cout << "2. Employee" << endl;
    cin >> option;
    if (option == 1) return option;
    else if (option == 2)
    {
        cout << "Enter Password: ";
        cin >> password;
        if (password == 3214) return option;
        else
        {
            system ("cls");
            cout << "Incorrect Password \n";
            goto lable;
        }
    }
    else
    {
        system ("cls");
        cout << "Wrong Input\n";
        goto lable;
    }
}
int employees ()
{
    int option;
lable:
    cout << "OPTIONS" << endl;
    cout << "1. MENU MANAGEMENT"<< endl;
    cout << "2. TABLE MANAGEMENT" << endl;
    cout << "3. EXIT THE PROGRAM" << endl;
    cout << "4. RETURN" << endl;
    cin >> option;
    if (option == 1 || option == 2 || option == 3|| option == 4 )
        return option;

    else
    {
        cout << "Wrong Input\n";
        goto lable;
    }
}
int customer ()
{
    int option;
    system("cls");
    cout << "WELCOME TO SALEM RESATURANT\n\n";
lable:
    cout << "OPTIONS\n";
    cout << "...........\n";
    cout << "1. Order\n";
    cout << "2. About us\n";
    cout << "3. Review\n";
    cout << "4. Exit\n";
    cin >> option;
    if (option == 1) return 1;
    else if (option == 2) return 2;
    else if (option == 3) return 3;
    else if (option == 4) return 4;
    else
    {
        cout << "Wrong Input\n";
        goto lable;
    }
}
void table_reservation (MYSQL *conn)
{
    int choice;
    bool cont = true;
    while(cont)
    {

        cout << "------------------------"<<endl;
        cout << "TABLE RESERVATION\n";
        cout << "------------------------\n"<<endl;
        cout << "OPTIONS\n";
        cout << "1. Display available table\n";
        cout << "2. Reserve a table\n";
        cout << "3. Exit\n";
        cin >> choice;
        MYSQL_RES *res;
        MYSQL_ROW  row;
        mysql_query(conn, "select table_number from table_reservation where availability = 1");
        res = mysql_store_result(conn);
        switch (choice)
        {

        case 1:
            system("cls");
            cout << "Available Tables:\n";
            while((row = mysql_fetch_row(res) ) )
            {
                cout << "TABLE " << row[0] << endl;
            }
            break;
        case 2:
            int table;
            cout << "Which Table Do You Want to Reserve: ";
            cin >> table;
            char query[100];
            while((row = mysql_fetch_row(res) ) )
            {
                if (table == stoi(row[0]) )
                {
                    order[order_no].table_no = table;
                    sprintf(query, "update table_reservation set availability = 0 WHERE table_number = %d", table);

                    if (mysql_query(conn, query))
                    {
                        cerr << "query failed: " << mysql_error(conn) <<endl;
                        break;

                    }
                    else cout << "Table Reserved Sucessfully!"<< endl;
                    system("pause");
                    system ("cls");
                    return;
                }
            }
            system("cls");
            cout << "Unavailable\n";
            break;
        case 3:
            cont = false;
            system("cls");
            break;
        default:
            system("cls");
            cout << "Invalid Input\n";
            break;
        }
    }
}

void tableManagement (MYSQL *conn)
{
    int option;
    option:
    cout << "OPTION\n";
    cout << "1. Display Unvailable Tabels\n";
    cout << "2. Unreserve table\n";
    cout << "3. Exit\n";
    cin >> option;
    MYSQL_RES *res;
    MYSQL_ROW  row;
    mysql_query(conn, "select table_number from table_reservation where availability = 0");
    res = mysql_store_result(conn);
    switch (option)
    {
    case 1:
        system ("cls");
        cout << "Unavailable Tables:\n";
        while((row = mysql_fetch_row(res) ) )
        {
            cout << "TABLE " << row[0] << endl;
        }
        break;

    case 2:
        int table;
        cout << "Which Table Do You Want to Delete/Unreserve: ";
        cin >> table;
        char query[100];
        while((row = mysql_fetch_row(res) ) )
        {
            if (table == stoi(row[0]) )
            {
                sprintf(query, "update table_reservation set availability = 1 WHERE table_number = %d", table);

                if (mysql_query(conn, query))
                {
                    cerr << "query failed: " << mysql_error(conn) <<endl;
                    break;

                }
                else cout << "Table is Freed"<< endl;
                system("pause");
                system ("cls");

            }
        }
        cout << "Already Free\n";
        break;
        case 3: return;
        break;


    }
      goto option;

}



void Menu (MYSQL *conn)
{
    MYSQL_RES *foodmenu, *drinkmenu;

    MYSQL_ROW row;
    cout<< endl;
    cout << setw(25)<< "-------------------" << endl;
    cout << setw(25)<< "    +-+-+-+-+      " << endl;
    cout << setw(25)<< "    |M|e|n|u|      " << endl;
    cout << setw(25)<< "    +-+-+-+-+      " << endl;
    cout << setw(25)<< "-------------------" << endl << endl;
    cout << "........................\n";
    cout << "FOODS\n";
    cout << "........................\n\n";
    mysql_query(conn, "SELECT * FROM Menu where type = 'food' and availability = 1");
    foodmenu = mysql_store_result(conn);
    int i = 1;
    cout << " "<< left << setw(9)<< "NUMBER" << setw(28) << "Meal" << setw(10) << "Price" << setw(10) << "Food_ID" << endl << endl;
    while ((row = mysql_fetch_row(foodmenu)))
    {
        cout << " "<< left << setw(9) << i << setw(28) << row[1] <<  setw(10) << row[3] <<  setw(10) << row [0] << endl;
        i++;
    }
    cout << endl;

    cout << "........................\n";
    cout << "DRINKS\n";
    cout << "........................\n\n";
    mysql_query(conn, "SELECT * FROM Menu where type = 'drink' and availability  = 1");
    drinkmenu = mysql_store_result(conn);
    cout << " "<< left << setw(9) << "NUMBER" <<  setw(28) << "Meal" << setw(10) << "Price" << setw(10)<<"Drink_ID" << endl<< endl;
    while ((row = mysql_fetch_row(drinkmenu)))
    {
        cout << " "<< left << setw(9) << i << setw(28) << row[1] <<  setw(10) << row[3] << setw(10) << row[0] <<endl;
        i++;
    }
    cout << endl << endl;
}


void order_display(MYSQL *conn)
{
    int menuid;
    price = 0;
    MYSQL_RES *res;
    MYSQL_ROW row;
    cout << "ORDER:" << endl;

    if (food_no > 0)
    {
        cout << " " << left << setw(20) << "FOOD" << setw(10) << "QUANTITY" << setw(5) << "PRICE" << endl;
        for (int i = 0; i < food_no; i++)
        {
            menuid = order[order_no].food[i];

            string query = "SELECT name, price FROM menu WHERE menu_id = " + to_string(menuid);
            if (mysql_query(conn, query.c_str()))
            {
                cerr << "Error executing query: " << mysql_error(conn) << endl;
                continue;
            }
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                cout << setw(2) << i + 1 << ":" << setw(20) << row[0] << setw(10) << order[order_no].food_quantity[i] << setw(5) << stoi(row[1]) * order[order_no].food_quantity[i] << endl;
                price += stoi(row[1]) * order[order_no].food_quantity[i];
            }
        }
    }

    if (drink_no > 0)
    {
        cout << " " << left << setw(20) << "DRINK" << setw(10) << "QUANTITY" << setw(5) << "PRICE" << endl;
        for (int i = 0; i < drink_no; i++)
        {
            menuid = order[order_no].drink[i];


            string query = "SELECT name, price FROM menu WHERE menu_id = " + to_string(menuid);
            if (mysql_query(conn, query.c_str()))
            {
                cerr << "Error executing query: " << mysql_error(conn) << endl;

                continue;
            }

            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                cout << setw(2) << i + 1 << ":" << setw(20) << row[0] << setw(10) << order[order_no].drink_quantity[i] << setw(5) << stoi(row[1]) * order[order_no].drink_quantity[i] << endl;
                price += stoi(row[1]) * order[order_no].drink_quantity[i];
            }
        }
    }
}

void order_placement(MYSQL *conn)
{

    int  drink, food, option;
    drink_no = 0 ;
    food_no = 0;
    MYSQL_RES *res, *avidrink;
    MYSQL_ROW  row;
    lable:
    system ("cls");
    Menu(conn);
    cout << endl << endl;
    cout << "................................" << endl;
    cout << "ORDER PLACEMENT" << endl;
    cout << "................................" << endl;
    cout << "OPTION"<< endl;
    cout << "1. FOOD" << endl;
    cout << "2. DRINK" << endl;
    cout << "3. DONE\n";
    cin >> option;
    if (option == 1)
    {
        add_food:
        mysql_query(conn, "select menu_id from menu where type = 'food' and availability = 1");
        res = mysql_store_result(conn);
        cout << "Enter the Food you want to place (Enter the food_id): ";
        cin >> order[order_no].food[food_no];
        while ((row = mysql_fetch_row(res)))
        {

            if ( stoi(row[0]) == order[order_no].food[food_no])
            {
                cout << "Enter the Quantity: ";
                cin >>  order[order_no].food_quantity[food_no];
                cout << "Do you want to add another food? \n 0. NO \n 1. YES \n";
                cin >> food;
                food_no += 1;
                if (food == 1)
                    goto add_food;
                else goto lable;


            }
        }
        cout << "Invalid Input\n";
        system("pause");
        goto lable;
    }
    else if (option == 2)
    {

        addrink:
        mysql_query(conn, "select menu_id from menu where type = 'drink' and availability = 1");
        avidrink = mysql_store_result(conn);
        cout << "Enter the Drink you want to place (Enter the Drink_id): ";
        cin >> order[order_no].drink[drink_no];

        while ((row = mysql_fetch_row(avidrink)))
        {

            if (stoi(row[0]) == order[order_no].drink[drink_no])
            {

                cout << "Enter the Quantity: ";
                cin >>  order[order_no].drink_quantity[drink_no];
                cout << "Do you want to add another drink? \n 0. NO \n 1. YES \n";
                cin >> drink;
                drink_no += 1;
                if (drink == 1)
                    goto addrink;
                else goto lable;

            }

        }
        cout << "Invalid Input\n";
        system("pause");
        goto lable;
    }
    else if (option == 3)
    {
        system("cls");
    }
    else
    {
        cout << "Wrong Input"<< endl;
        goto lable;
    }
    order_display(conn);
}

void manage_order (MYSQL *conn)
{
    int option = 1;
    while (option != 5)
    {
        cout << "..................." << endl;
        cout << "ORDER MANAGMENT" << endl;
        cout << "..................." << endl;
        cout << "    OPTIONS  " << endl;
        cout << "1. Add a food " << endl;
        cout << "2. Remove a food " << endl;
        cout << "3. Add a drink " << endl;
        cout << "4. Remove a drink" << endl;
        cout << "5. Confirm order" << endl;
        cin >> option;
        if (option == 1)
        {
            system ("cls");
            Menu(conn);
            cout << "Choose the Food you want to add: "<< endl;
            cin >> order[order_no].food[food_no];
            cout << "Enter the Quantity: ";
            cin >>  order[order_no].food_quantity[food_no];
            food_no += 1;
        }

        else if (option == 2)
        {
            int index;
            system ("cls");
            order_display(conn);
            cout << "Choose the Food you want to Remove: "<< endl;
            cin >> index;
            for (int i = index-1; i < food_no; i++)
            {
                order[order_no].food[i] = order[order_no].food[i + 1];
                order[order_no].food_quantity[i] = order[order_no].food_quantity[i + 1];
            }
            food_no -= 1;
        }

        else if (option == 3)
        {
            system ("cls");
            Menu(conn);
            cout << "Choose the Drink you want to add: "<< endl;
            cin >> order[order_no].drink[drink_no];
            cout << "Enter the Quantity: ";
            cin >>  order[order_no].drink_quantity[drink_no];
            drink_no += 1;
        }

        else if (option == 4)
        {
            int index;
            system ("cls");
            order_display(conn);
            cout << "Choose the Drink you want to Remove: "<< endl;
            cin >> index;
            for (int i = index-1; i < drink_no; i++)
            {
                order[order_no].drink[i] = order[order_no].drink[i + 1];
                order[order_no].drink_quantity[i] = order[order_no].drink_quantity[i + 1];
            }
            drink_no -= 1;
        }
        else if(option == 5){
            order_display(conn);
            return;
        }
        else cout << "Wrong input! Please choose from the options.\n";

    }
    system ("cls");
    order_display(conn);
}

void manage_menu (MYSQL *conn)
{
    int option = 1, meal;
    while (option != 5)
    {
        cout << "Current Food and Drinks Available";
        Menu(conn);
        cout << "    OPTIONS  " << endl;
        cout << "1. Add a food " << endl;
        cout << "2. Remove a food " << endl;
        cout << "3. Add a drink " << endl;
        cout << "4. Remove a drink" << endl;
        cout << "5. Exit" << endl;
        cin >> option;
        char query[100];
        int index;
        if (option == 1)
        {
            system("cls");
            MYSQL_RES *res;
            MYSQL_ROW row;
            mysql_query(conn, "SELECT * FROM Menu where type = 'food' and availability = 0");
            res = mysql_store_result(conn);
            cout << "--------------------------\n";
            cout << "FOODS TO ADD\n";
            cout << " "<< left << setw(28) << "FOOD" <<  setw(10) << "FOOD_ID" << endl ;
            while ((row = mysql_fetch_row(res)))
            {
                cout << " "<< left <<setw(28) << row[1] <<  setw(10) << row [0] << endl;

            }
            cout << "--------------------------\n";
            cout << "\nEnter the Food_id you want to add\n";
            cin >> meal;
            sprintf(query, "update menu set availability = 1 WHERE menu_id = %d", meal);
            if (mysql_query(conn, query))
            {
                cerr << "INSERT query failed: " << mysql_error(conn) << endl;
            }


        }
        else if(option == 2)
        {
            system("cls");
            Menu(conn);
            cout << "Enter the Food_id you want to remove: "<< endl;
            cin >> index;
            sprintf(query, "update menu set availability = 0 WHERE menu_id = %d", index);
            if (mysql_query(conn, query))
            {
                cerr << "INSERT query failed: " << mysql_error(conn) << endl;
            }

        }
        else if (option == 3)
        {
            system("cls");
            MYSQL_RES *res;
            MYSQL_ROW row;
            mysql_query(conn, "SELECT * FROM Menu where type = 'drink' and availability = 0");
            res = mysql_store_result(conn);
            cout << "--------------------------\n";
            cout << "DRINKS TO ADD\n";
            cout << " "<< left << setw(28) << "Drink" <<  setw(10) << "Drink_ID" << endl << endl;
            while ((row = mysql_fetch_row(res)))
            {
                cout << " "<< left <<setw(28) << row[1] <<  setw(10) << row [0] << endl;

            }
            cout << "--------------------------\n";
            cout << "\nEnter Drink_id you want to add\n";
            cin >> meal;
            sprintf(query, "update menu set availability = 1 WHERE menu_id = %d", meal);
            if (mysql_query(conn, query))
            {
                cerr << "INSERT query failed: " << mysql_error(conn) << endl;
            }

        }
        else if (option == 4)
        {
            system("cls");
            Menu(conn);
            cout << "Enter the Drink_id you want to remove: "<< endl;
            cin >> index;
            sprintf(query, "update menu set availability = 0 WHERE menu_id = %d", index);
            if (mysql_query(conn, query))
            {
                cerr << "INSERT query failed: " << mysql_error(conn) << endl;
            }
        }
        else if (option == 5)
        {
            return;
        }
        system("pause");
        system ("cls");
    }
}
void cash()
{
    cout<<"You can go and pay to the cashier"<<endl;
}
void credit_card()
{
    string name,pin;
    int cvv,Expt;
    double c_No;
label:
    cout<<"Please enter your card number"<<endl;
    cin>>c_No;
    cout<<"Please enter the card Expiration  year"<<endl;
    cin>>Expt;
    if(Expt<2023)
    {
        cout<<"sorry your card  expired"<<endl;
        cout<<"use another card, please"<<endl;
        goto label;
    }
    else
    {
        cout<<"Please enter cvv the three digit number"<<endl;
        cin>>cvv;
        cout<<"Enter the name on the card"<<endl;
        cin>>name;
        cout<<"Please enter any key to confirm "<<endl;
        cin>>pin;
        cout<<"your payment is completed"<<endl;
    }
}
void mobile_banking()
{
    int choice1;
    string done;
    cout<<"In which mobile banking you want to pay?"<<endl;
    cout<<"1. CBE\n";
    cout<<"2. Dashen\n";
    cout<<"3. Awash\n";
    cout<<"Enter your choice: ";
    cin>>choice1;
    if(choice1==1)
    {
        cout<<"The account no is 10003456789"<<endl;
    }
    else if(choice1==2)
    {
        cout<<"The account no is 76542896540"<<endl;
    }
    else if(choice1==3)
    {
        cout<<"The account number is 4092345766"<<endl;
    }
    else
    {
        cout<<"wrong choice\n";
    }
    cout<<"when you complete your payment."<<endl;
    system ("pause");
    cout<<"your payment is completed"<<endl;
}

void payment_calculation ( double price)
{
    double tax,Ttotal = 0;
    int choice;
    //To calculate the 15% tax of the total
    tax=0.15*price;
    cout<<"Tax="<<tax<<endl;
    Ttotal=price+tax;
    cout<<"The total amount is: "<<Ttotal<<endl;
    order[order_no].total_price = Ttotal;
    daily_income += Ttotal;

    cout<<"How would you like to pay?"<<endl;
    cout<<"1. cash\n";
    cout<<"2. credit_card\n";
    cout<<"3. mobile_banking\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice==1)
    {
        cash();
    }
    else if(choice==2)
    {
        credit_card();
    }
    else if(choice==3)
    {
        mobile_banking();
    }
    else
        cout<<"wrong choice"<<endl;
}


void rating(MYSQL *conn) {
    int option;
    string comment;
        review:
        system("cls");
        cout << "OPTIONS" << endl;
        cout << "1. Rate" << endl;
        cout << "2. Comment" << endl;
        cout << "3. Read previous comments" << endl;
        cout << "4. Exit" << endl;
        cin >> option;

        if (option == 1) {
            int rate;
            cout << "Rate the restaurant ordering system from 1-5: ";
            cin >> rate;

            if (rate < 1 || rate > 5) {
                cout << "Invalid rating. Please rate again!" << endl;
            } else {
                char query[100];
                sprintf(query, "INSERT INTO feedback (rating, feedback_date) VALUES (%d, CURDATE())", rate);

                if (mysql_query(conn, query)) {
                    cerr << "Query failed: " << mysql_error(conn) << endl;
                    return;
                }
                cout << "Rating submitted successfully!" << endl;
            }
            system("pause");
            goto review;
        } else if (option == 2) {
            cin.ignore();
            cout << "Enter your comment: ";
            getline(cin, comment);

            char query[500];
            sprintf(query, "INSERT INTO feedback (comment, feedback_date) VALUES ('%s', CURDATE())", comment.c_str());

            if (mysql_query(conn, query)) {
                cerr << "Query failed: " << mysql_error(conn) << endl;
                system("pause");
                return;
            }
            cout << "Comment submitted successfully!" << endl;
            system("pause");
            goto review;
        } else if (option == 3) {
            MYSQL_RES *res;
            MYSQL_ROW row;
            mysql_query(conn, "SELECT comment FROM feedback");
            res = mysql_store_result(conn);
            system("cls");
            cout << "---------------------" << endl;
            cout << "COMMENTS" << endl;
            cout << "---------------------" << endl;

            while ((row = mysql_fetch_row(res))) {
                    if (row[0] != NULL) {
                        cout << row[0] << endl;
                    }
            }
            cout << "------------------------" << endl;
            system("pause");
            goto review;
        } else if (option == 4) {
            return;
        } else {
            cout << "Wrong Input" << endl;
            system ("pause");
            goto review;
        }

        system("pause");

}


void Record(MYSQL *conn)
{
    int menuid;
    MYSQL_RES *res;
    MYSQL_ROW row;
    OrderTrack.open("Order_Record.txt", ios::out | ios::app);
    if(OrderTrack.is_open())
    {
        OrderTrack << "ORDER NUMBER: "<< order_no << endl;
        OrderTrack <<"ORDER:" << endl;
        OrderTrack << " "<< left << setw(20) << "FOOD" << setw(10) << "QUANTITY" << setw(5)<< "PRICE"<< endl;
        if (food_no > 0)
        {
            for (int i = 0; i < food_no; i++)
            {
                menuid = order[order_no].food[i];

                string query = "SELECT name, price FROM menu WHERE menu_id = " + to_string(menuid);
                if (mysql_query(conn, query.c_str()))
                {
                    cerr << "Error executing query: " << mysql_error(conn) << endl;
                    continue;
                }

                res = mysql_store_result(conn);
                while ((row = mysql_fetch_row(res)))
                {
                    OrderTrack << setw(2) << i + 1 << ":" << setw(20) << row[0] << setw(10) << order[order_no].food_quantity[i] << setw(5) << stoi(row[1]) * order[order_no].food_quantity[i] << endl;
                }
            }
        }
        if (drink_no > 0)
        {
            OrderTrack << " "<< left << setw(20) << "DRINK" << setw(10) << "QUANTITY" << setw(5)<< "PRICE"<< endl;
            for (int i = 0; i < drink_no; i++)
            {
                menuid = order[order_no].drink[i];

                string query = "SELECT name, price FROM menu WHERE menu_id = " + to_string(menuid);
                if (mysql_query(conn, query.c_str()))
                {
                    cerr << "Error executing query: " << mysql_error(conn) << endl;
                    continue;
                }

                res = mysql_store_result(conn);
                while ((row = mysql_fetch_row(res)))
                {
                    OrderTrack << setw(2) << i + 1 << ":" << setw(20) << row[0] << setw(10) << order[order_no].drink_quantity[i] << setw(5) << stoi(row[1]) * order[order_no].drink_quantity[i] << endl;

                }
            }
        }
        OrderTrack << "ON TABLE NUMBER: " << order[order_no].table_no << endl;
        OrderTrack << "TOTAL PAYMENT: "<< order[order_no].total_price << endl;
        OrderTrack << "_______________________________________________"<< endl;
    }
    OrderTrack.close();
}


void daily_report()
{
    system ("cls");
    report.open("Daily_Report.txt", ios::app);
    if (report.is_open())
    {
        report << "****************************************************\n";
        report << "REPORT FOR: "<< __DATE__ << endl << endl;
        report << "TOTAL NUMBER OF ORDERS: "<< order_no << endl;
        report << "TOTAL INCOME: "<< daily_income << endl;
        report << "****************************************************\n";

    }
    report.close();
    cout << "REPORT FOR: "<< __DATE__ << endl << endl;
    cout << "TOTAL NUMBER OF ORDERS: "<< order_no << endl;
    cout << "TOTAL INCOME: "<< daily_income << endl;

}







int main()
{
    int choice, cschoice,employee_choice;
    MYSQL *conn;
    conn = mysql_init(NULL);
    conn = mysql_real_connect(conn, "localhost", "newuser", "newpassword", "restaurant_mgmt", 0, NULL, 0);
    if (!conn)
    {
        cout << "Connection Error\n";
        exit(-1);
    }
    OrderTrack.open("Order_Record.txt", ios::app);
    if(OrderTrack.is_open())
    {
        OrderTrack << "-----------------------------" << endl;
        OrderTrack << "ORDER RECORD FOR "<< __DATE__ << endl;
        OrderTrack << "-----------------------------" << endl << endl;
    }
    OrderTrack.close();
lable:
    choice = option();
    if(choice == 1)
    {
        customer:
        cschoice = customer();
        if (cschoice == 1)
        {
            int order;
            table_reservation(conn);
            Menu(conn);
            cout << "Do You want to Order now? \n";
            cout << "1. Yes\n";
            cout << "2. No\n";
            cin >> order;
            if (order == 1)
            {
                order_placement(conn);
                manage_order(conn);
                payment_calculation(price);
                Record(conn);
                cout << "Thank You, Have a nice Meal! ";
                system("pause");
                order_no += 1;
            }
            else if (order == 2)
            {
                goto lable;
            }
            else
            {
                cout << "Wrong Input\n";
                goto lable;
            }

        }
        else if (cschoice == 2)
        {

            system("cls");
            about_us.open("aboutus.txt", ios::in);
            cout<< about_us.rdbuf();
            system("pause");
            about_us.close();
            goto customer;

        }
        else if (cschoice == 3)
        {
            rating(conn);
            goto customer;
        }
         else if (cschoice == 4)
        {
            goto lable;
        }

        else cout << "Wrong Input!\n";
    }
    else if (choice== 2)
    {
        employee:
        system("cls");
        employee_choice = employees();
        if (employee_choice == 1)
        {
            manage_menu(conn);
        }
        else if (employee_choice==2)
        {
            tableManagement(conn);
        }
        else if (employee_choice==3)
        {
            int exit_password;
            cout << "ENTER PASSWORD: ";
            cin >> exit_password;
            if (exit_password == 5454)
            {
                daily_report();
                system("pause");
                mysql_close(conn);
                exit(0);
            }
            else cout << "Wrong Password\n";

        }
        else if (employee_choice==4) {
            system ("cls");
            goto lable;
        }
        else cout << "Wrong Input!";
    }
    goto lable;






    return 0;
}

