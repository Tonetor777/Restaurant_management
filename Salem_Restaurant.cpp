#include <iostream>
#include <iomanip>
#include <string.h>
#include<fstream>
using namespace std; 
int tables[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
fstream table , OrderTrack , review , about_us , report;
int number_of_foods = 9 , number_of_drinks = 7 , order_no = 0 , food_no , drink_no , count_rate = 0; 
double price , daily_income = 0 , sum_rate = 0;
string line;
struct foods{
    string name; 
    float price;
}food_item[15];

struct drinks{
    string name;
    float price; 
}drink_item[10];

struct order_track{
    int food [10]; 
    int food_quantity[10]; 
    int drink[10]; 
    int drink_quantity[10]; 
    double total_price;
    int table_no;
}order[200];

int option(){
system("cls"); 
lable:
cout << "    ________________________________________________________________________________________________________________________" << endl << endl; 
cout << " SSSSS    AAA   LL      EEEEEEE MM    MM    RRRRRR  EEEEEEE  SSSSS  TTTTTTT   AAA   UU   UU RRRRRR    AAA   NN   NN TTTTTTT " << endl; 
cout << "SS       AAAAA  LL      EE      MMM  MMM    RR   RR EE      SS        TTT    AAAAA  UU   UU RR   RR  AAAAA  NNN  NN   TTT   " << endl; 
cout << " SSSSS  AA   AA LL      EEEEE   MM MM MM    RRRRRR  EEEEE    SSSSS    TTT   AA   AA UU   UU RRRRRR  AA   AA NN N NN   TTT   " << endl; 
cout << "     SS AAAAAAA LL      EE      MM    MM    RR  RR  EE           SS   TTT   AAAAAAA UU   UU RR  RR  AAAAAAA NN  NNN   TTT   " << endl; 
cout << " SSSSS  AA   AA LLLLLLL EEEEEEE MM    MM    RR   RR EEEEEEE  SSSSS    TTT   AA   AA  UUUUU  RR   RR AA   AA NN   NN   TTT   " << endl; 
cout << "    ________________________________________________________________________________________________________________________" << endl << endl; 
int option , password; // password = 3214
cout << "WELCOME TO SALEM RESATURANT\n\n";
cout << "OPTIONS" << endl; 
cout << "1. Customer" << endl;
cout << "2. Employee" << endl; 
cin >> option; 
if (option == 1) return option; 
else if (option == 2) {
  cout << "Enter Password: "; 
  cin >> password;
       if (password == 3214) return option; 
       else {
        system ("cls");
        cout << "Incorrect Password \n"; 
        goto lable; 
       }
}
else {
  system ("cls");
  cout << "Wrong Input\n"; 
  goto lable; 
}
}
int employees () {
int option;
lable:
cout << "OPTIONS" << endl; 
cout << "1. MENU MANAGEMENT"<< endl; 
cout << "2. TABLE MANAGEMENT" << endl; 
cout << "3. EXIT" << endl; 
cin >> option; 
  if (option == 1 || option == 2) return option; 
  else if (option == 3) {}
  else {
    cout << "Wrong Input\n"; 
    goto lable; 
  }
}
int customer () {
   int option; 
   system("cls");
   cout << "WELCOME TO SALEM RESATURANT\n\n";
   lable:
   cout << "OPTIONS\n";
   cout << "...........\n";  
   cout << "1. Order\n"; 
   cout << "2. About us\n"; 
   cout << "3. Review\n"; 
   cin >> option; 
   if (option == 1) return 1; 
   else if (option == 2) {}
   else if (option == 3) {}
   else {
    cout << "Wrong Input\n"; 
    goto lable; 
   }
}

void append(int tablenum){    
    table.open("TableFile.txt", ios::app);
    if(table.is_open()){
        table<<"Table "<<tablenum<<" Reserved"<<endl;
        cout<<"Table "<<tablenum<<" is Reserved!"<<endl;
    }
    table.close();
}

void available(int arr[10]){
    string line;
    for(int i=0; i<10; i++){
        int arrnum = tables[i]; 
        string catnum = to_string(arrnum);
        table.open("TableFile.txt", ios::in);
        string check = "Table "+catnum+" Reserved";
        if(table.is_open()){
            while(getline(table, line)){
               if(line == check){
                  arr[arrnum-1] = 0;
                }
            }
         } 
        table.close();
    }
}

void display(int arr[10]){
   cout<<"Tables list\n";
   cout<<"~~~~~~~~~~~~~\n";
   table.close();

    for(int i =0; i<10;i++){
        if(arr[i] != 0){
        cout<<"Table "<<i+1<<endl;
        }
    } 
}
void delete_table() {
  int tablenum;
  cout << "Enter table number: "; 
  cin >> tablenum;
   if(tables[tablenum-1] != 0){
                cout<<"This table is not occupied please choose another table"<<endl;
               
            }
            else{
                string update[10];
                for (int i = 0; i < 10; i++) {
                     update[i] = "";
                }
                tables[tablenum-1] = tablenum;
                cout<<"Table "<<tablenum<<" is now free"<<endl;
                
                table.open("TableFile.txt", ios::in);
                string check = "Table "+to_string(tablenum)+" Reserved";
                if(table.is_open()){
                    int i= 0;
                    while(getline(table, line)){
                        if(line != check){
                            update[i] = line;
                            i++;
                            }}
                    table.close();        
                }
                
                table.open("TableFile.txt", ios::out);
                    if(table.is_open()){
                       for(int i =0 ; i< 10 ; i++){
                            if (update[i] != "") {
                                table << update[i] << endl;
                            }
                        }
                    }
                    else{
                        cout<<"ERROR occured!";
                        
                    }
                table.close();    
            } 
}
void table_reserve () {
int choice;
int tablenum;
bool reserve = true;
while(reserve){
    cout << "---------------------\n"; 
    cout << "TABLE RESERVATION" << endl; 
    cout << "---------------------"; 
    cout<<"\n OPTIONS \n1. Reserve a table\n2. Display available tables\n3. Exit \n";
    cin>>choice;
    
    switch(choice){
        case 1: 
            cout<<"Enter table number: ";
            cin>>tablenum;
            available(tables);
            if(tables[tablenum-1]== 0){
                cout<<"This table is UNAVAILABLE please choose another table"<<endl;
                break;
            }
            cout << "Enter '1' to Edit your reservation or any other number to confirm your reservation.\n"; 
            cin >> choice; 
            if (choice == 1) {
                 system("cls"); 
               }
            else { 
                system("cls"); 
                append(tablenum);
                order[order_no].table_no = tablenum;  
                tables[tablenum-1] = 0;
                cout << "Table Reservation Confirmed" << endl; 
             }
            break;
        case 2:
           system("cls");
           available(tables);
           display(tables);
           break;
        case 3:
            reserve = false;
            break;
        default:
                cout<<"INVALID INPUT!";
    }
}
}
void normal_food_menu() {
  string food[9] = {"Dench", "Dench Special", "Enkulal Sandwich", "Enkulal Sandwich Special", "Pasta", "Pasta be Soya", "Ruz", "Ruz be Soya", "Soya"};
  int price[9] = {30, 55, 45, 60, 40, 50, 35, 45, 35};
  for(int i =0; i<9 ;i++){
    food_item[i].name = food[i];
    food_item[i].price = price[i];
  }
}
void normal_drinks() {
  string drink[7] = {"Coca", "Fanta", "Sprite", "Predator", "Juice", "Milk", "Yoghurt"};
  int price[7] = {40, 40, 40, 50, 30, 45, 50};
  for(int i = 0; i < 7; i++){
    drink_item[i].name = drink[i];
    drink_item[i].price = price[i];
  }
}
void menu () {
  system("cls");
  cout << endl << endl; 
  cout << setw(25)<< "-------------------" << endl;
  cout << setw(25)<< "    +-+-+-+-+      " << endl;
  cout << setw(25)<< "    |M|e|n|u|      " << endl;
  cout << setw(25)<< "    +-+-+-+-+      " << endl;
  cout << setw(25)<< "-------------------" << endl << endl;
  cout << "................................" << endl;
  cout << "Foods" << endl; 
  cout << "................................" << endl;
  cout << " "<< left << setw(30) << "TYPE" << setw(5) << "PRICE"<< endl;
  for (int i = 0; i < number_of_foods; i++ ) {
    cout << setw(2) << i + 1 << ":" << setw(30) <<food_item[i].name << setw(5) <<food_item[i].price << endl;
  }
  cout << "................................" << endl;
  cout << "Drinks" << endl; 
  cout << "................................" << endl;
   for (int i = 0; i < number_of_drinks; i++ ) {
    cout << i + 1 << ":" << setw(30) <<drink_item[i].name << setw(5) <<drink_item[i].price << endl;
  }
  cout << "................................" << endl;
}
void order_display () {
        price = 0;  
        cout <<"ORDER:" << endl; 
          if (food_no > 0) {
                 cout << " "<< left << setw(20) << "FOOD" << setw(10) << "QUANTITY" << setw(5)<< "PRICE"<< endl;
          for (int i = 0 ;i < food_no ; i++) {
                cout << setw(2) << i + 1 << ":" << setw(20) << food_item[order[order_no].food[i] - 1].name<< setw(10) << order[order_no].food_quantity[i] << setw(5)<<food_item[order[order_no].food[i] - 1].price * order[order_no].food_quantity[i] << endl; 
                price += food_item[order[order_no].food[i] - 1].price * order[order_no].food_quantity[i];
          } 
          }
          if (drink_no > 0) {
         cout << " "<< left << setw(20) << "DRINK" << setw(10) << "QUANTITY" << setw(5)<< "PRICE"<< endl;
           for (int i = 0 ;i < drink_no ; i++) {
                cout << setw(2) << i + 1 << ":" << setw(20) << drink_item[order[order_no].drink[i] - 1].name<< setw(10) << order[order_no].drink_quantity[i] << setw(5)<<drink_item[order[order_no].drink[i] - 1].price * order[order_no].drink_quantity[i]<< endl;
                price += drink_item[order[order_no].drink[i] - 1].price * order[order_no].drink_quantity[i];
           }
          }
     }
void order_placement(){
     int  drink = 1, food = 1, option;
     drink_no = 0 ; food_no = 0;
              cout << "................................" << endl;
              cout << "ORDER PLACEMENT" << endl; 
              cout << "................................" << endl;
              lable:
              cout << "OPTION"<< endl; 
              cout << "1. FOOD" << endl; 
              cout << "2. DRINK" << endl; 
              cout << "3. DONE\n";
              cin >> option; 
              if (option == 1) {
            while (food == 1){
              cout << "Enter the Food you want to place (Enter the number): "; 
              cin >> order[order_no].food[food_no]; 
              cout << "Enter the Quantity: "; 
              cin >>  order[order_no].food_quantity[food_no]; 
              cout << "Do you want to add another food? \n 0. NO \n 1. YES \n"; 
              cin >> food; 
              food_no += 1; 
               }
               goto lable; 
          }
               else if (option == 2) {
            while(drink == 1){
              cout << "Enter the Drink you want to place (Enter the number): "; 
              cin >> order[order_no].drink[drink_no]; 
              cout << "Enter the Quantity: "; 
              cin >>  order[order_no].drink_quantity[drink_no];
              cout << "Do you want to add another drink? \n 0. NO \n 1. YES \n";
              cin >> drink; 
              drink_no += 1; 
            } 
            goto lable;
         }
              else if (option == 3) {
            system("cls");
          }
              else {
                cout << "Wrong Input"<< endl; 
                goto lable;
              }
            order_display();
}

void manage_order () {
    int option; 
      while (option != 5) {
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
      if (option == 1) {
        system ("cls"); 
        menu(); 
        cout << "Choose the Food you want to add: "<< endl;
        cin >> order[order_no].food[food_no];
        cout << "Enter the Quantity: ";
        cin >>  order[order_no].food_quantity[food_no];
        food_no += 1;
      }

      else if (option == 2) {
        int index; 
        system ("cls");
        order_display(); 
        cout << "Choose the Food you want to Remove: "<< endl;
        cin >> index; 
         for (int i = index-1; i < food_no; i++){
                order[order_no].food[i] = order[order_no].food[i + 1];
                order[order_no].food_quantity[i] = order[order_no].food_quantity[i + 1];
            } 
        food_no -= 1; 
      }
        
      else if (option == 3) {
        system ("cls");
        menu(); 
        cout << "Choose the Drink you want to add: "<< endl;
        cin >> order[order_no].drink[drink_no];
        cout << "Enter the Quantity: ";
        cin >>  order[order_no].drink_quantity[drink_no];
        drink_no += 1;
      }

      else if (option == 4) {
        int index; 
        system ("cls");
        order_display(); 
        cout << "Choose the Drink you want to Remove: "<< endl;
        cin >> index; 
         for (int i = index-1; i < drink_no; i++){
                order[order_no].drink[i] = order[order_no].drink[i + 1];
                order[order_no].drink_quantity[i] = order[order_no].drink_quantity[i + 1];
            } 
          drink_no -= 1; 
      }
      else cout << "Wrong input! Please choose from the options.\n"; 
      
   }
    system ("cls");
    order_display();
}
    
void manage_item () {
      int option; 
      while (option != 5){
      cout << "Current Food and Drinks Available"; 
      menu();
      cout << "    OPTIONS  " << endl; 
      cout << "1. Add a food " << endl;
      cout << "2. Remove a food " << endl;
      cout << "3. Add a drink " << endl;
      cout << "4. Remove a drink" << endl; 
      cout << "5. Exit" << endl; 
      cin >> option; 
      if (option == 1) {
            cout << "Enter Food Name: " << endl; 
            cin.ignore(); 
            getline(cin, food_item[number_of_foods].name); 
            cout << "Enter the Price: "<< endl; 
            cin >> food_item[number_of_foods].price; 
            number_of_foods += 1 ;  
          }
      else if(option == 2) {
            int index; 
            cout << "Enter the Food number you want to remove: "<< endl; 
            cin >> index; 
            for (int i = index-1; i < number_of_foods; i++){
                 food_item[i].name = food_item[i+1].name;
                 food_item[i].price = food_item[i+1].price;
                 number_of_foods -= 1; 
            } 
      }
      else if (option == 3) {
            cout << "Enter Drink Name: " << endl; 
            cin.ignore(); 
            getline(cin, drink_item[number_of_drinks].name); 
            cout << "Enter the Price: "<< endl; 
            cin >> drink_item[number_of_drinks].price; 
            number_of_drinks += 1 ; 
      }
      else if (option == 4) {
            int index; 
            cout << "Enter the Drink number you want to remove: "<< endl; 
            cin >> index; 
            for (int i = index-1; i < number_of_drinks; i++){
                 drink_item[i].name = drink_item[i+1].name;
                 drink_item[i].price = drink_item[i+1].price;
                 number_of_drinks -= 1; 
            } 
      } 
      else if (option == 5) {
        return; 
      }
   }
}
void cash(char){
		cout<<"You can go and pay to the cashier"<<endl;
	}
void credit_card(int){
	string name,pin;
	int cvv,Expt;
	double c_No;
  label:
	cout<<"Please enter your card number"<<endl;
	cin>>c_No;
	cout<<"Please enter the card Expiration  year"<<endl;
	cin>>Expt;
	if(Expt<2023){
		  cout<<"sorry your card  expired"<<endl;
		  cout<<"use another card, please"<<endl;
		  goto label;
	}
	else{
	    cout<<"Please enter cvv the three digit number"<<endl;
	    cin>>cvv;
	    cout<<"Enter the name on the card"<<endl;
	    cin>>name;
	    cout<<"Please enter any key to confirm "<<endl;
	    cin>>pin;
	    cout<<"your payment is completed"<<endl;
	}
}
void mobile_banking(char){
	int choice1;
	string done;
	cout<<"In which mobile banking you want to pay?"<<endl;
	cout<<"1. CBE\n";
    cout<<"2. Dashen\n";
    cout<<"3. Awash\n";
    cout<<"Enter your choice: ";
    cin>>choice1;
      if(choice1==1){
		       cout<<"The account no is 10003456789"<<endl;
	}
	    else if(choice1==2){
		       cout<<"The account no is 76542896540"<<endl;
   }
		  else if(choice1==3){
		       cout<<"The account number is 4092345766"<<endl;
	}
	    else{
		       cout<<"wrong choice\n";
	}
	  cout<<"when you complete your payment please enter any key"<<endl;
	  cin>>done;
		cout<<"your payment is completed"<<endl;
	}

void payment_calculation ( double price){
		char Y; double tax,discount,Ttotal = 0;
		int choice;
        cout<<"Are you student?y/n"<<endl;
        cin>>Y;
		//To calculate the 15% tax of the total
        tax=0.15*price;
        cout<<"Tax="<<tax<<endl;
        Ttotal=price+tax;
	if(Y=='y'||Y=='Y'){
	    discount=Ttotal*0.05;
	    cout<<"Discount "<<discount<<endl;
	    Ttotal=Ttotal-discount;
	    cout<<"Total amount is "<<Ttotal<<endl;
      order[order_no].total_price = Ttotal;
      daily_income += Ttotal;  
	}
	else{
		  cout<<"No discount"<<endl;
		  cout<<"The total amount is: "<<Ttotal<<endl;
      order[order_no].total_price = Ttotal;
      daily_income += Ttotal;
	}
	      cout<<"How would you like to pay?"<<endl;
	      cout<<"1. cash\n";
        cout<<"2. credit_card\n";
        cout<<"3. mobile_banking\n";
        cout<<"Enter your choice: ";
        cin>>choice;
	if(choice==1){
		      cash(2);
	}
	else if(choice==2){
		      credit_card(2);
	}
	else if(choice==3){
		      mobile_banking(3);
	}
	else
	        cout<<"wrong choice"<<endl;
	}

double AverageRate(){
	      return sum_rate / count_rate; 
}

void rating(){
	double rate , option;
	string comment;
	label:
  cout << "OPTION" << endl; 
  cout << "1. Rate" << endl; 
  cout << "2. Comment" << endl; 
  cout << "3. Read previous comments"<< endl; 
  cout << "4. Exit\n";
  cin >> option;
if (option == 1){
  cout << "Current average rate: "<< AverageRate() << endl; 
	cout<< "Rate the restaurant ordering system from 1-5 please: ";
	cin>>rate;
	 if(rate < 1 || rate > 5){
	 	cout<<"wrong rate, please rate again!"<<endl;
	 	goto label;
	 }
   sum_rate += rate; 
	 count_rate += 1; 
   goto label; 
}
else if (option == 2) {
	 cout<<"Enter your comment\n ";
   cin.ignore();
	 getline(cin, comment); 
    review.open("comments.txt", ios::app);
    if(review.is_open()) {
      review << "--------------------------------" << endl; 
      review << __DATE__ <<" : "<< __TIME__ << endl << endl;
      review << comment << endl; 
      review << "--------------------------------" << endl; 
    }
    review.close(); 
    goto label; 
	 }
else if (option == 3) {
     system("cls");
     review.open("comments.txt", ios::in);
     if (review.good() && review.peek() != ifstream:: traits_type::eof()){
     cout << review.rdbuf(); 
     cout << "Enter any number when you are done\n"; 
     cin >> option; 
     }
     else cout << "No Comments Yet!"<< endl; 
     goto label; 
}
else if (option == 4){
  return; 
}
else {
  cout << "Wrong Input\n";
  goto label;
}
}
void Record() {
    OrderTrack.open("Order_Record.txt", ios::app);
    if(OrderTrack.is_open()){
     OrderTrack << "ORDER NUMBER: "<< order_no << endl; 
     OrderTrack <<"ORDER:" << endl; 
        OrderTrack << " "<< left << setw(20) << "FOOD" << setw(10) << "QUANTITY" << setw(5)<< "PRICE"<< endl;
          for (int i = 0 ;i < food_no ; i++) {
                OrderTrack << setw(2) << i + 1 << ":" << setw(20) << food_item[order[order_no].food[i] - 1].name<< setw(10) << order[order_no].food_quantity[i] << setw(5)<<food_item[order[order_no].food[i] - 1].price * order[order_no].food_quantity[i] << endl;  
          } 
         OrderTrack << " "<< left << setw(20) << "DRINK" << setw(10) << "QUANTITY" << setw(5)<< "PRICE"<< endl;
           for (int i = 0 ;i < drink_no ; i++) {
                OrderTrack << setw(2) << i + 1 << ":" << setw(20) << drink_item[order[order_no].drink[i] - 1].name<< setw(10) << order[order_no].drink_quantity[i] << setw(5)<<drink_item[order[order_no].drink[i] - 1].price * order[order_no].drink_quantity[i]<< endl;
           }        
     OrderTrack << "ON TABLE NUMBER: " << order[order_no].table_no << endl; 
     OrderTrack << "TOTAL PAYMENT: "<< order[order_no].total_price << endl; 
     OrderTrack << "_______________________________________________"<< endl; 
    }
    OrderTrack.close(); 
}

void daily_report() {
  system ("cls");
  int hold;
  report.open("Daily_Report.txt", ios::app);
  if (report.is_open()) {
    report << "REPORT FOR: "<< __DATE__ << endl << endl; 
    report << "TOTAL NUMBER OF ORDERS: "<< order_no << endl; 
    report << "TOTAL INCOME: "<< daily_income << endl; 
    report << "DAILY AVERAGE RATING: "<< AverageRate() <<endl; 
  }
  report.close();
  report.open("Daily_Report.txt", ios::in);
  cout << report.rdbuf();
  cin>>hold;
  report.close();
}

int main () {
  normal_drinks(); 
  normal_food_menu(); 
  int choice , customer_choice, employee_choice; 
  OrderTrack.open("Order_Record.txt", ios::app);
  if(OrderTrack.is_open()) {
    OrderTrack << "-----------------------------" << endl;
    OrderTrack << "ORDER RECORD FOR "<< __DATE__ << endl; 
    OrderTrack << "-----------------------------" << endl << endl;
  }
  OrderTrack.close();
  lable:
  choice = option(); 
  if(choice == 1) {
    customer_choice = customer();
      if (customer_choice == 1) {
           char done; int order; 
           table_reserve();
           menu(); 
           cout << "Do You want to Order now? \n";
           cout << "1. Yes\n";
           cout << "2. No\n";
           cin >> order;
             if (order == 1) {
                   order_placement(); 
                   manage_order();
                   payment_calculation(price); 
                   Record();
                   cout << "Thank You, Have a nice Meal! (Press any key) \n";
                   order_no += 1; 
                   cin >> done; 
             }
             else if (order == 2){
                   goto lable;
             }
             else {
                   cout << "Wrong Input\n";
                   goto lable;
             }
            
         }      
  else if (customer_choice == 2) {
             system("cls");
             about_us.open("aboutus.txt", ios::in); 
             cout<< about_us.rdbuf(); 
             cin >> choice;
         }
  else if (customer_choice == 3) {
              rating();
         }
  else cout << "Wrong Input!\n";
}
  else if (choice== 2) {
            employee_choice = employees(); 
            if (employee_choice == 1) {
                   manage_item(); 
            }
            else if (employee_choice==2) {
                bool manage = true ;
                int option; 
                while (manage){
                       cout << "OPTION"<< endl; 
                       cout << "1. Display Available Tables\n"; 
                       cout << "2. Delete Reserved Table\n";
                       cout << "3. Exit\ns";
                       cin >> option;
                       if (option == 1) {
                        system("cls");
                        available(tables);
                        display(tables);
                       }
                       else if (option == 2) {
                        delete_table();
                       }
                       else if (option == 3){
                        manage = false; 
                       }
                       else cout << "Wrong Input!\n";

                }
          
            }
            else if (employee_choice==3) {
                   int exit_password; 
                   cout << "ENTER PASSWORD: ";
                   cin >> exit_password;
                   if (exit_password == 5454) {
                   daily_report();
                   }
                   else cout << "Wrong Password\n";
            }
            else cout << "Wrong Input!";
  }
  goto lable;

    return 0;
}