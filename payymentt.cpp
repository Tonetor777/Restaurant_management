#include <iostream>
using namespace std;
void cash(char){
		cout<<"your payment is completed"<<endl;
	}
void credit_card(int){
	int pin;
	cout<<"please insert your card to the post machine"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"Enter your pin code"<<endl;
	cin>>pin;
	cout<<"your payment is on transaction"<<endl;
	cout<<"your payment is completed"<<endl;
}
void mobile_banking(char){
	int choicr1;
	cout<<"In which mobile banking you want to pay?"<<endl;
	cout<<"[Choice 1] CBE\n";
    cout<<"[Choice 2] Dashen\n";
    cout<<"[Choice 3] Awash\n";
    cout<<"Enter your choice\n";
    cin>>choicr1;
     if(choicr1==1){
		 cout<<"The account no is 10003456789"<<endl;
	}
	 else if(choicr1==2){
		cout<<"The account no is 76542890"<<endl;
   }
		else{
		cout<<"The account number is 4092766"<<endl;
	}
	    cout<<"your payment is on transaction"<<endl;
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
	switch(choice){
		case1:cash;
		break;
		case2:credit_card;
		break;
		case3:mobile_banking;
		break;
	}
	if(choice==1){
		cash(2);
	}
	else if(choice==2){
		credit_card(2);
	}
	else{
		mobile_banking(3);
	}
}
