#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std; 
int number_of_foods = 9 , number_of_drinks = 7 , order_no = 0 , food_no , drink_no; 
double price;

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
              cout << "Do you want to add another food?(Enter '1' for 'Yes' & '0' for 'No'): "; 
              cin >> food; 
              food_no += 1; 
            }
        cout << "Do you want to order a drink?(Enter '1' for 'Yes' & '0' for 'No'): "; 
        cin>> drink; 
            while(drink == 1){
              cout << "Enter the Drink you want to place (Enter the number): "; 
              cin >> order[order_no].drink[drink_no]; 
              cout << "Enter the Quantity: "; 
              cin >>  order[order_no].drink_quantity[drink_no];
              cout << "Do you want to add another drink? (Enter '1' for 'Yes' & '0' for 'No'): ";
              cin >> drink; 
              drink_no += 1; 
            } 
}
void order_display () {
        price = 0; 
        cout << "YOUR CURRENT ORDER:" << endl; 
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


void manage_order () {
    int option; 
      while (option != 5) {
      cout << "ORDER MANAGMENT" << endl; 
      cout << "    OPTIONS  " << endl; 
      cout << "1. Add a food " << endl;
      cout << "2. Remove a food " << endl;
      cout << "3. Add a drink " << endl;
      cout << "4. Remove a drink" << endl; 
      //cout << "5. Exit" << endl; 
      cin >> option; 
      
      if (option == 1) {
        cout << "Choose the Food you want to add: "<< endl;
        cin >> order[order_no].food[food_no];
        cout << "Enter the Quantity: ";
        cin >>  order[order_no].food_quantity[food_no];
        food_no += 1;
      }

      if (option == 2) {
        int index; 
        cout << "Choose the Food you want to Remove: "<< endl;
        cin >> index; 
         for (int i = index-1; i < food_no; i++){
                order[order_no].food[i] = order[order_no].food[i + 1];
                order[order_no].food_quantity[i] = order[order_no].food_quantity[i + 1];
            } 
          food_no -= 1; 
      }
        
      if (option == 3) {
        cout << "Choose the Drink you want to add: "<< endl;
        cin >> order[order_no].drink[drink_no];
        cout << "Enter the Quantity: ";
        cin >>  order[order_no].drink_quantity[drink_no];
        drink_no += 1;
      }

      if (option == 4) {
        int index; 
        cout << "Choose the Drink you want to Remove: "<< endl;
        cin >> index; 
         for (int i = index-1; i < drink_no; i++){
                order[order_no].drink[i] = order[order_no].drink[i + 1];
                order[order_no].drink_quantity[i] = order[order_no].drink_quantity[i + 1];
            } 
          drink_no -= 1; 
      }
      cout << "ENTER '5' FOR CONFORMATION or '0' to continue editing your order: "; 
      cin >> option; 
   }
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

int main () {
normal_drinks(); 
normal_food_menu(); 
menu(); 
order_placement(); 
order_display(); 
manage_order(); 
order_display(); 







    return 0;
}