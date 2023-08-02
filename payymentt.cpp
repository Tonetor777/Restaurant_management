#include <iostream>
using namespace std;
void cash(char){
		cout<<"you can pay to the cashier"<<endl;
	}
void credit_card(int){
	string name;
	int pin,cvv,Expt;
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
	cout<<"Please enter any number to confirm "<<endl;
	cin>>pin;
	cout<<"your payment is completed"<<endl;
	}
}
void mobile_banking(char){
	int choice1;
	string done;
	cout<<"In which mobile banking you want to pay?"<<endl;
	cout<<"[Choice 1] CBE\n";
    cout<<"[Choice 2] Dashen\n";
    cout<<"[Choice 3] Awash\n";
    cout<<"Enter your choice\n";
    cin>>choice1;
     if(choice1==1){
		 cout<<"The account no is 10003456789"<<endl;
	}
	 else if(choice1==2){
		cout<<"The account no is 76542890"<<endl;
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
int main(){
string Y,y,n;
double total,tax,discount,Ttotal,Tdiscount;
int choice;
cout<<"Are you student?y/n"<<endl;
cin>>Y;
cout<<"Enter the total amount"<<endl;
cin>>total;
//To calculate the 15% tax of the total
tax=0.15*total;
cout<<"Tax="<<tax<<endl;
Ttotal=total+tax;
//calculate 5% discount if the customer is student
if(Y=="y"||Y=="Y"){
	discount=Ttotal*0.05;
	cout<<"Discount "<<discount<<endl;
	Tdiscount=Ttotal-discount;
	cout<<"Total amount is "<<Tdiscount<<endl;
	}
	else{
		cout<<"No discount"<<endl;
		cout<<"The total amount is "<<Ttotal<<endl;
	}
	cout<<"How would you like to pay?"<<endl;
	cout<<"[Choice 1] cash\n";
    cout<<"[Choice 2] credit_card\n";
    cout<<"[Choice 3] mobile_banking\n";
    cout<<"Enter your choice\n";
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
