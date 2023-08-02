#include<iostream>
using namespace std;

struct customer{
	string name;
	int phone;
	string email;
	char ans;
}c1;

struct choice{
	int p,n,s,q;
}ch;

void customer(){
	cout<<"please enter your name: ";
	cin>>c1.name;
	cout<<"please enter your phone: ";
	cin>>c1.phone;
	cout<<"please enter your email: ";
	cin>>c1.email;
 cout<<endl;
}
void firstchoice(){
 	cout<<"\nHello "<<c1.name<<endl;
	cout<<"What would you like to order? "<<endl;
	cout<<"\nFast Food Menu"<<endl;
	cout<<" [choice 1] Drinks \n [choice 2] Sandwich \n [choice 3] Pasta \n [choice 4] Rice \n [choice 5] Potatoes \n [choice 6] Soya "<<endl;
	cin>>ch.p;	
}
void secondchoice(){
	switch(ch.p){
		case 1: cout<<"\nplease enter which drink to have: "<<endl;
		        cout<<" 1) Coca P40 \n 2) Fanta P40 \n 3) Predator P50\n 4) Mango Juice \n 5) Milk P40 \n 6) yoghurt P60"<<endl;
		        cin>>ch.n; break;
		case 2: cout<<"\nplease enter which sandwich to have: "<<endl;
		        cout<<"1) Normal P45 \n 2) Special P60"<<endl;
		        cin>>ch.n; break;
	    case 3: cout<<"\nplease enter which Pasta to have: "<<endl;
	            cout<<"1) Vegetable Pasta P40 \n 2) Soya Pasta P50 "<<endl;
	            cin>>ch.n; break;
	    case 4: cout<<"\nplease enter which rice to have: "<<endl;
	            cout<<"1) Vegetable Rice P35 \n 2) Soya Rice P45 "<<endl;
	            cin>>ch.n; break;
	    case 5: cout<<"\nplease enter which Potatoes to have: "<<endl;
		        cout<<"1) Normal P30 \n 2) Special P55"<<endl;
		        cin>>ch.n; 
} if(ch.p<=0||ch.p>=7){
  cout<<"Wrong input! Enter again.";
  firstchoice();}
}
void sizechoice(){
	if(ch.n==4){
		cout<<" Choose size: 1)Small juice P20 \n 2) Large juice P30"<<endl;
		cin>>ch.s;
	} cout<<"Please enter quantity: ";
	  cin>>ch.q;
}

int main(){
 	customer();
start:{	firstchoice();
	secondchoice();
	sizechoice();
	cout<<"\nWould you like to order again? y/n: ";
	cin>>c1.ans;
	if(c1.ans=='y'||c1.ans=='Y')
	goto start;
 
 else cout<<"\nThank You For Ordering From Salem Restaurant!!!"<<endl;
}	
}
