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
