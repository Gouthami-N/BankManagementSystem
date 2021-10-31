#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

class Bank{

	private: 

	    int total;

	    struct person{

	    	string name;
            string typeofAcc;
	    	int AccNo;
            double balance;

		}person[100];

	public:

		Bank(){

			total=0;

		}

		void choice();//member function to enter the choice

		void perData();//member function to create new account

		void show();//member function to view customer list

		void update();//member function to update the data

		void search();//to check the details of existing account

		void transactions();//to make transactions and check balance

		void del();//to delete data

};

int main(){

	Bank b;//creating object for class Bank

	b.choice();

	return 0;

}

void Bank::choice(){

	char ch;

	while(1){

	cout<<"\n\nPRESS..!!"<<endl;

	cout<<"1. Create new account"<<endl;

	cout<<"2. View customers list"<<endl;

	cout<<"3. Update information of existing account"<<endl;

	cout<<"4. Check the details of an existing account"<<endl;

	cout<<"5. For transactions"<<endl;

	cout<<"6. Remove existing account"<<endl;

	cout<<"7. Exit"<<endl;

	cin>>ch;

    /* conditional statement to perofrm operations on the user requirement*/

	switch(ch){

		case '1':

			Bank::perData();

			break;

		case '2':

			if(total==0){

				cout<<"No data is entered"<<endl;

			}else{

			Bank::show();

		   }

			break;

		case '3':

			if(total==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::update();

			break;

		case '4':

			if(total==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::search();

			break;

		case '5':

			if(total==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::transactions();

			break;

		case '6':

			if(total==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::del();

			break;

		case '7':

			exit(0);

			break;

		default:

			cout<<"Invalid input"<<endl;

			break;

	}

    }

}

void Bank::perData(){

	cout<<"Enter data of person "<<total+1<<endl;

	cout<<"Enter name: ";

	cin>>person[total].name;
    cout<<"Account no: ";

	cin>>person[total].AccNo;


	cout<<"type of the account: ";

	cin>>person[total].typeofAcc;

	cout<<"Total Cash: ";

	cin>>person[total].balance;

	total++;

}

/*function to show name and account number of all the customers*/
void Bank::show(){

	for(int i=0;i<total;i++){

		cout<<"Data of person "<<i+1<<endl;

		cout<<"Name: "<<person[i].name<<endl;

		cout<<"Account Number: "<<person[i].AccNo<<endl;

	}

}

void Bank::update(){

	int AccNoc;
    cout<<"Enter account number of customer those data you want to update"<<endl;

	cin>>AccNoc;

	for(int i=0;i<total;i++){

		if(AccNoc==person[i].AccNo){

		cout<<"Previous data"<<endl;

		cout<<"Data of person "<<i+1<<endl;

		cout<<"Name: "<<person[i].name<<endl;

		cout<<"Account number: "<<person[i].AccNo<<endl;

		cout<<"type of account: "<<person[i].typeofAcc<<endl;

		cout<<"Cash: "<<person[i].balance<<endl;

		cout<<"\nEnter new data"<<endl;

		cout<<"Enter name: ";

	    cin>>person[i].name;

        cout<<"type of account:";

	    cin>>person[i].typeofAcc;

	    cout<<"Total Cash: ";

	    cin>>person[i].balance;

	break;

		}


		cout<<"No such record found"<<endl;


	}

}

void Bank::search(){
int AccNoc;
cout<<"Enter Account number of customer those data you want to search"<<endl;

cin>>AccNoc;

for(int i=0;i<total;i++){

	if(AccNoc==person[i].AccNo){

		cout<<"Name: "<<person[i].name<<endl;

		cout<<"Account number: "<<person[i].AccNo<<endl;

		cout<<"type of account: "<<person[i].typeofAcc<<endl;

		cout<<"Cash: "<<person[i].balance<<endl;


		break;

	}

	else{

		cout<<"No such record found"<<endl;

	}

}

}

void Bank::transactions(){

	int cash;

	char ch;
    int AccNoc;

	cout<<"Enter AccNo of customer those data you want to transaction"<<endl;

     cin>>AccNoc;

     for(int i=0;i<total;i++){

     	if(AccNoc==person[i].AccNo){

     		cout<<"Name: "<<person[i].name<<endl;

     	     cout<<"Account number: "<<person[i].AccNo<<endl;

		     cout<<"type of account: "<<person[i].typeofAcc<<endl;

		     cout<<"\nExisting Cash "<<person[i].balance<<endl;

		     cout<<"Press 1 to deposit"<<endl;

		     cout<<"Press 2 to withdraw"<<endl;

		     cin>>ch;

		     switch(ch){

		     	case '1':

		     		cout<<"How much cash you want to deposit??"<<endl;

		     		cin>>cash;

		     		person[i].balance+=cash;

		     		cout<<"Your new cash is "<<person[i].balance<<endl;

		     		break;

		     	case '2':

		     		back:

		     		cout<<"How much cash you want to withdraw??"<<endl;

		     		cin>>cash;

		     		if(cash>person[i].balance){

		     			cout<<"Your existing cash is just "<<person[i].balance<<endl;


		     			goto back;

					 }

					 person[i].balance-=cash;

					 cout<<"Your new cash is "<<person[i].balance<<endl;

					 break;

				default:

					cout<<"Invalid input"<<endl;

					break;

			 }

			 break;

		 }

		 else{

		 	cout<<"No such record found"<<endl;

		 }

	 }

}

void Bank::del(){

	char ch;
    int AccNoc;

	cout<<"Press 1 to remove specific record"<<endl;

	cout<<"Press 2 to remove full record"<<endl;

	cin>>ch;

	switch(ch){

		case '1':

	cout<<"Enter account number of customer those data you want to remove"<<endl;

     cin>>AccNoc;

     for(int i=0;i<total;i++){

     	if(AccNoc==person[i].AccNo){

     		for(int j=i;j<total;j++){

     		person[j].name=person[j+1].name;

     		person[j].AccNo=person[j+1].AccNo;

     		person[j].typeofAcc=person[j+1].typeofAcc;

     		person[j].balance=person[j+1].balance;

     		total--;

     		cout<<"Your required data is deleted"<<endl;

     		break;

			 }

		 }

		 else{

		cout<<"No such record found"<<endl;

		 }

	 }

	 break;

	 case '2':

	 	total=0;

	 	cout<<"All record is deleted"<<endl;

	 	break;

	default:

		cout<<"Invalid Input"<<endl;

		break;

	}

}

