#include <iostream>
#include <iomanip>
#include <string.h>
#include<fstream>
using namespace std; 
int tables[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
fstream table , OrderTrack , review , about_us , report;
int number_of_foods = 9 , number_of_drinks = 7 , order_no = 0 , food_no , drink_no , count_rate = 0; 
double price , daily_income = 0 , sum_rate = 0;

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
void table_reserve () {
int choice;
string line2;
int tablenum;
bool reserve = true;
while(reserve){
    cout << "---------------------\n"; 
    cout << "TABLE RESERVATION" << endl; 
    cout << "---------------------"; 
    cout<<"\n OPTIONS \n1. Reserve a table\n2. Display available tables\n3. Delete reservation\n4. Exit\n";
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
            append(tablenum);
            order[order_no].table_no = tablenum;  
            tables[tablenum-1] = 0;
            cout << "Enter '1' to Edit your reservation or any other number to confirm your reservation.\n"; 
            cin >> choice; 
            if (choice == 1) 
                 system("cls"); 
            else {
                reserve= false; 
                system("cls"); 
                cout << "Table Reservation Confirmed"; 
             }
            break;
        case 2:
           system("cls");
           available(tables);
           display(tables);
           break;
      
        case 3:
            cout<<"Enter table number: ";
            cin>>tablenum;
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
                    while(getline(table, line2)){
                        if(line2 != check){
                            update[i] = line2;
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
            break;  
        case 4: 
        
            cout<<"Thank you for visiting us! ";
            reserve = false;
            break;
        default:
                cout<<"INVALID INPUT!";
    }
}
}


void normal_food_menu() {
    food_item[0].name = "Dench";
    food_item[1].name = "Dench Special";
    food_item[2].name = "Enkulal Sandwich";
    food_item[3].name = "Enkulal Sandwich Special";
    food_item[4].name = "Pasta";
    food_item[5].name = "Pasta be Soya";
    food_item[6].name = "Ruz ";
    food_item[7].name = "Ruz be Soya";
    food_item[8].name = "Soya";
    food_item[0].price = 30;
    food_item[1].price = 55;
    food_item[2].price = 45;
    food_item[3].price = 60;
    food_item[4].price = 40;
    food_item[5].price = 50;
    food_item[6].price = 35;
    food_item[7].price = 45;
    food_item[8].price = 35;
}

void normal_drinks() {
     drink_item[0].name = "Coca";
     drink_item[1].name = "Fanta";
     drink_item[2].name = "Sprite";
     drink_item[3].name = "Pridator";
     drink_item[4].name = "Juice";
     drink_item[5].name = "Milk";
     drink_item[6].name = "Yoghurt";
     drink_item[0].price = 40;
     drink_item[1].price = 40;
     drink_item[2].price = 40;
     drink_item[3].price = 50;
     drink_item[4].price = 30;
     drink_item[5].price = 45;
     drink_item[6].price = 50;
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
        cout << " "<< left << setw(20) << "FOOD" << setw(10) << "QUANTITY" << setw(5)<< "PRICE"<< endl;
          for (int i = 0 ;i < food_no ; i++) {
                cout << setw(2) << i + 1 << ":" << setw(20) << food_item[order[order_no].food[i] - 1].name<< setw(10) << order[order_no].food_quantity[i] << setw(5)<<food_item[order[order_no].food[i] - 1].price * order[order_no].food_quantity[i] << endl; 
                price += food_item[order[order_no].food[i] - 1].price * order[order_no].food_quantity[i];
          } 
         cout << " "<< left << setw(20) << "DRINK" << setw(10) << "QUANTITY" << setw(5)<< "PRICE"<< endl;
           for (int i = 0 ;i < drink_no ; i++) {
                cout << setw(2) << i + 1 << ":" << setw(20) << drink_item[order[order_no].drink[i] - 1].name<< setw(10) << order[order_no].drink_quantity[i] << setw(5)<<drink_item[order[order_no].drink[i] - 1].price * order[order_no].drink_quantity[i]<< endl;
                price += drink_item[order[order_no].drink[i] - 1].price * order[order_no].drink_quantity[i];
           }
     }
void order_placement(){
     int  drink, food = 1;
     drink_no = 0 ; food_no = 0;
              cout << "................................" << endl;
              cout << "ORDER PLACEMENT" << endl; 
              cout << "................................" << endl;
            while (food == 1){
              cout << "Enter the Food you want to place (Enter the number): "; 
              cin >> order[order_no].food[food_no]; 
              cout << "Enter the Quantity: "; 
              cin >>  order[order_no].food_quantity[food_no]; 
              cout << "Do you want to add another food? \n 0. NO \n 1. YES \n"; 
              cin >> food; 
              food_no += 1; 
            }
        cout << "Do you want to order a drink?\n 0. NO \n 1. YES \n"; 
        cin>> drink; 
            while(drink == 1){
              cout << "Enter the Drink you want to place (Enter the number): "; 
              cin >> order[order_no].drink[drink_no]; 
              cout << "Enter the Quantity: "; 
              cin >>  order[order_no].drink_quantity[drink_no];
              cout << "Do you want to add another drink? \n 0. NO \n 1. YES \n";
              cin >> drink; 
              drink_no += 1; 
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
		char Y,y,n; double total,tax,discount,Ttotal = 0;
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

void rating(){
	double rate;
	string comment;
	label:
	cout<< "Rate the restaurant ordering system from 1-5 please: ";
	cin>>rate;
	
	 if(rate < 1 || rate > 5){
	 	cout<<"wrong rate, please rate again!"<<endl;
	 	goto label;
	 }
   sum_rate += rate; 
	 count_rate += 1; 
	 cout<<endl;
	
	 char yn;
	 cout<<"would you leave your comment about our food (y/n): ";
	 cin>>yn;
	 cin.ignore();
	 cout<<endl; 
	 if(yn=='y'){
	 cout<<"comment: ";
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
	 }
	 else
	 cout<<"Thank you for choosing us, come again!!!"<<endl << "Enter any key\n";
   cin>> yn; 
   }

double AverageRate(){
	      return sum_rate / count_rate; 
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
  report.open("Daily_Report.txt", ios::app);
  if (report.is_open()) {
    report << "REPORT FOR: "<< __DATE__ << endl << endl; 
    report << "TOTAL NUMBER OF ORDERS: "<< order_no << endl; 
    report << "TOTAL INCOME: "<< daily_income << endl; 
    report << "DAILY AVERAGE RATING: "<< AverageRate() <<endl; 
    cout << report.rdbuf();  
  }
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
             char done; 
             table_reserve();
             menu(); 
             order_placement(); 
             manage_order();
             payment_calculation(price); 
             Record();
             cout << "Thank You, Have a nice Meal! (Press any key) \n";
             order_no += 1; 
             cin >> done; 
         }      
         else if (customer_choice == 2) {
             system("cls");
             about_us.open("aboutus.txt"); 
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
                   table_reserve();
          
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