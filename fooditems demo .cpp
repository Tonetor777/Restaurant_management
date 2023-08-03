#include <iostream>
#include <string.h>
using namespace std;

struct food {
    string fname;
    int fprice;

}f[5];

struct drink {
    string dname;
    int dprice;
}d[7];

void food_menu () {
    f[0].fname= "Sandwich";
    f[1].fname= "Pasta with tomato sauce";
    f[2].fname= "pasta with vegetables";
    f[3].fname= "Rice";
    f[4].fname= "Rice with Vegetables";
    f[0].fprice= 30;
    f[1].fprice= 40;
    f[2].fprice= 40;
    f[3].fprice= 45;
    f[4].fprice= 45;
}

void drink_menu () {
    d[0].dname= "Coke";
    d[1].dname= "Fanta";
    d[2].dname= "Sprite";
    d[3].dname= "Predator";
    d[4].dname= "Juice";
    d[5].dname= "Milk";
    d[6].dname= "Yoghurt";
    d[0].dprice= 40;
    d[1].dprice= 40;
    d[2].dprice= 40;
    d[3].dprice= 45;
    d[4].dprice= 35;
    d{5}.dprice= 30;
    d[6].dprice= 25;
}


int main () {

    int choice1, choice2;

    cout<< "Welcome distinguished customer. what food item would you like?"<< endl;
    food_menu();
    drink_menu();
        for(int i=0; i<5; i++) {
            cout<<"  "<<i+1<<". " f[i].fname<<"   "<< f[i].fprice<< endl;
            cout<<"  "<<i+1<<". " d[i].dname<<"   "<< d[i].dprice<< endl;
        }
    cin>> choice;

    return 0;
}
