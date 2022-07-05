#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

struct user {
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct user user,usr;
	char filename[50],phone[50],password[50],phone2[50];
	int loan_amount,interest_rate,number_of_year,total_amount,monthly_amount;
	FILE *fp,*fptr;
	int opt,choice;
	int amount;
	char cont = 'y';
	cout<<("\nWhat do you want to do?");
	cout<<("\n\n1.Register your account");
	cout<<("\n2.Login to your account");
	cout<<("\n\nPlease enter your choice:\t");
	cin>>("%d",opt);
	if(opt == 1){
		cout<<("\nEnter your phone number:\t");
		cin>>("%s",user.ac);
		cout<<("Enter your Name:\t");
		cin>>("%s",user.phone);
		cout<<("Enter your new password:\t");
		cin>>("%s",user.password);
		user.balance=1500;
		
		fp=fopen(strcat(filename,".txt"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			cout<<("Succesfully registered");
			cout<<"\nYou Have Got a Voucher Of Rs.1500";
		}
	}
	else if(opt == 2){
		cout<<("\nEnter your Name.:\t");
		cin>>("%s",phone);
		cout<<("Password:\t");
		cin>>("%s",password);
		fp=fopen(strcat(filename,".txt"),"r");
		if(fp == NULL) cout<<("Account number not registered");
		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
				cout<<"\nWelcome "<<user.phone;
				cout<<("\nPress 1 for balance inquiry");
				cout<<("\nPress 2 for adding fund");
				cout<<("\nPress 3 for cash withdraw");
				cout<<("\nPress 4 for loan ");
				cout<<("\nPress 5 for changing password\n\n");
				cin>>("%d",choice);
				switch(choice){
					case 1:
						cout<<"Your current balance is : "<<user.balance;
						break;

					case 2:
						cout<<"Enter your amount to be deposited : "<<endl;
						cin>>("%d",amount);
						user.balance += amount;
						fp=fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0); 
						cout<<"\nYou have depostied Rs."<<amount;
						fclose(fp);
						break;

					case 3:
						cout<<"Enter the amount : "<<endl;
						cin>>("%d",amount);
						if(amount % 500 != 0) 
						cout<<("\nSorry amount should be multiple of 500");
						else if(amount>user.balance) 
						cout<<("\nSorry insufficeint balance");
						else {
							user.balance -= amount;
						fp=fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) 
						cout<<"\nYou have withdrawn Rs."<<amount;
						fclose(fp);
						}
						break;
					
					case 4:
						cout<<"Enter the Loan Amount : ";
						cin>>loan_amount;
						cout<<endl;
						
						cout<<"Enter the Interest Rate : ";
						cin>>interest_rate;
						cout<<endl;
						
						cout<<"Enter the Number Of years : ";
						cin>>number_of_year;
						cout<<endl;
						
						total_amount = (number_of_year*loan_amount) + (number_of_year*interest_rate);
						monthly_amount = total_amount/(number_of_year*12);
						
						cout<<"Total amount to be paid : "<<total_amount<<endl;
						cout<<"Total interest : "<<total_amount-loan_amount<<endl;
						cout<<"Monthly Amount to be paid : "<<monthly_amount<<endl;
						
						break;
						
						
					case 5:
						cout<<"Enter the Old Password : "<<endl;
						cin>>("%s",password);
						if(!strcmp(password,user.password)){
							cout<<"\n\nPlease enter your new password:\t";
							cin>>("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.phone);
							fp=fopen(strcat(filename,".txt"),"w");
							fwrite(&user,sizeof(struct user),1,fp);
							fclose(fp);	
							cout<<("\nPassword succesfullly changed");
						}else cout<<("\nSorry your password is wrong");
					
					default:
					break;
				}
				cout<<("\n\nDo you want to continue?[y/n]:\t");
				cin>>("%s",&cont);
				}
			}
			else {
				cout<<("Invalid password");
			}	
		}
		cout<<("\n\n***Khatam Tata BY BY***\n\n");
	}
	
	return 0;
}
