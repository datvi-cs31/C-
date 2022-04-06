// This is password setter....

#include<iostream>
#include<string.h>
using namespace std;
int main() {

	string pass,pass2;
	int digit,caps,smalls,speChars;
	cout << "------------( SET YOUR PASSWORD )----------------\n\n";
	cout << "INSTRUCTIONS : \n\n";
	cout << "\tYour password must contain the following\n";
	cout << "\t1. Atleast one uppercase \n";
	cout << "\t2. Atleast one smallcase \n";
	cout << "\t3. Atleast one special charecter \n";
	cout << "\t4. Atleast one digit\n";
	cout << "\t5. Maximum length of Password is 15\n";
	
	while(1) {
		digit = caps = smalls = speChars = 0;
		cout << "\n--> Enter your password    : ";
		getline(cin,pass);
		if(pass.length()<=15) 
		{
			int i=0,p,count=0;
			while(pass[i]!='\0') 
			{
				p = int(pass[i]);
				
				if(p>=48 && p<=57)		{digit = digit + 1;}
				else if(p>=65 && p<=90)	{caps = caps + 1;}
				else if(p>=97 && p<=122)	{smalls = smalls + 1;}
				else					{speChars = speChars + 1;}
				i++;
			}
			if(digit>0 && caps>0 && smalls>0 && speChars>0) 
			{
				cout << "--> Re-Enter your password : ";
				getline(cin,pass2);
				int i=0,count=0;
				while(pass2[i]!='\0') 
				{
					if(pass[i]==pass2[i])	{count++;}
					if(pass[i]!=pass2[i])	{break;}
					i++;
				}
				if(count==pass.length() && count==pass2.length())	{cout << "\nYour password is set successfully!!! \n";exit(1);}
				else					{cout << "\n2 PASSWORDS DOESN'T MATCH!\n----------------------------------------------------\n";}
			}
			else	{
				cout << "\n\tYour password must contain the following\n";
				cout << "\t1. Atleast one uppercase \n";
				cout << "\t2. Atleast one smallcase \n";
				cout << "\t3. Atleast one special charecter \n";
				cout << "\t4. Atleast one digit\n";
				cout << "\t5. Maximum length of Password should be 15\n";
			cout << "!---------------------------------------------------\n";}
		}
		else {cout << "\nTHE MAX LENGTH OF PASSWORD SHOULD BE 15! \n--------------------------------------------------\n";}
	}	
	return 0;
}
