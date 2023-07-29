#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int tables[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
fstream table;

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

int main(){
string line2;
int choice;
int tablenum;
bool NotFull = true;
while(NotFull){
    cout<<"\nChoose an option: \n1. Reserve a table\n2. Display available tables\n3. Delete reservation\n4. Exit\n";
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
            tables[tablenum-1] = 0;
            break;
        case 2:
           available(tables);
           display(tables);
           break;
      
        case 3:
            
            cout<<"Enter table number: ";
            cin>>tablenum;
            if(tables[tablenum-1] != 0){
                cout<<"This table is not occupied please choose another table"<<endl;
                break;
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
                        break;
                    }
                table.close();    
            }
            break;  
        case 4: 
        
            cout<<"Thank you for visiting us! ";
            NotFull = false;
            break;
        default:
                cout<<"INVALID INPUT!";
    }
}
    return 0;
}