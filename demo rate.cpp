#include<iostream>
#include<fstream>
#include <string>
using namespace std;
double average;
ofstream outfile1;
void rating(int count){
	int x,ave;
	double sum=0;
    string comment;
	for(int i=0;i<count;i++){
	label:
	cout<< "Rate the restaurant ordering system from 1-5 please: ";
	cin>>x;
	
	 switch(x){
	 	case 1: ave=1;
	 	break;
	 	case 2: ave=2;
	 	break;
	 	case 3: ave=3;
	 	break;
	 	case 4: ave=4;
	 	break;
	 	case 5: ave=5;
	 	break;
	 	default:
	 		cout<<"wrong rate, please rate again!"<<endl;
	 	goto label;
	 }
	 sum+=ave;
	 average= sum/count;
	 cout<<endl;
	 
	outfile1.open("my rate.txt", ios::app);
	
	 char yn;
	 cout<<"would you leave your comment about our food (y/n): ";
	 cin>>yn;
	  cin.ignore();
	 cout<<endl; 
	 if(yn=='y'){
	 cout<<"comment: ";
	 getline(cin, comment);
	  outfile1<<"comment:"<<comment<<endl;
	 }
	 else
	 cout<<"Thank you for choosing us, come again!!!"<<endl;
	 outfile1.close();}
}
void averate(double average,int count){
	cout<<"average daily rating is: "<<average<<" out of "<<count<<" customers"<<endl;
	outfile1.open("my rate.txt", ios::app);
	outfile1<<"average daily rating is: "<<average<<" out of "<<count<<" customers"<<endl;
	outfile1.close();
}
int main(){
	int c=2;
	rating(c);
	averate(average,c);
}
