/*

* Code to Implement Bank Management System By Using C
            ----(developed both from Employers and Customers point of view)
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct date
{
	int month,date,year;
};
struct bank
{
	char name[50];
	char acc_type[1];
	int balance;
	char aadhar_card[12];
	int acc_no;
	int withdraw;
	char phone[10];
	char gender[1];
	char password[10];
	struct date deposit;
	
	
} add,update,check,transfer;

void employee();
void employee_menu();
void customer();
void fordelay();
void new_acc();
void withdraw();
void deposit();
void balance();
void info();
void apply_cheque();
void apply_debit_Card();
void view();
void edit();
void deleted();

int execution;

void option(void)
{ 
	system("cls");
	execution=1;
	int choice;
	printf("\n\t\t\t BANK MANAGEMENT SYSTEM");
	printf("\n \n \t\t\tINDIAN BANK/ALLAHABAD BANK OF INDIA");
	printf("\n Welcome to your Bank");
	while(execution==1)
	{
		fordelay(10000);
		printf("\n The options are:");
		printf("\n 1.Employer \n 2.Customer \n 3.Exit");
		printf("\n Please enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n The Employee function is selected");
				employee();
				break;
			case 2:
				printf("\n The Customer function is selected");
				customer();
				break;
			case 3 :
				printf("\n Thank You for your visit");
				execution=0;
			default:
				printf("\nInvalid Entry");
				fordelay(10);
		}
	}
	
	
}
int main()
{
	char pwd1[9];
	printf("\nCreated By:-\n\tVidushi Gandhi\n\tCollege Roll_no:20-CSE-058\n\tUniversity Roll_no:20015004058\n\tSemester:3rd\n\tCSE-Student");
	printf("\n\n\nEnter the password to login:");
	scanf("%s",&pwd1);
	if(strcmp(pwd1,"funcoding")==0)
	{
		printf("\n  Correct Password ");
		
		
		printf("\n \n\t\tLoading");
		for(int i=0;i<10;i++)
		{
			fordelay(10000000);
			printf("..");
		}
		system("cls");
		option();
	}
	else
	{
		printf("Login Failed!!!!");
		printf("Please enter correct password");
		fordelay(10000);
	}
	return 0;
}
void fordelay(int j)
{
	for(int i=1;i<j;i++);
	
}
void employee()
{	
	system("cls");
	char emp_id[4];
	char pwd[4];
	printf("\n \t\t \t Employee mode is activated");
	printf("\n For Security reason \n You have to follow certain criteria");
	printf("\n Enter your employee id:");
	scanf("%s",&emp_id);
	printf("Enter your password:");
	scanf("%s",&pwd);

		if(strcmp(pwd,"9876")==0)
		{
			printf("\nCorrect Password");
			printf("\n You are authorised user");
			employee_menu();
			
		}
		else
		{
			printf("Login Failed");
			printf("\n Incorrect Password");
		}

}
void employee_menu()
{
	//employee menu
	int ch;
	printf("\n \t\t \t Employee mode is activated");
	printf("\nThe options are:");
	printf("\n 1.View the account\n 2.Edit the account\n 3.Delete the Account\n 4.Exit");
	printf("\n Please enter your Choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("View mode is Enabled");
			view();	
			break;
		case 2:
			printf("Edit mode is Enabled");
			edit(); 
			break;
		case 3:
			printf("Delete mode is Enabled");
			deleted();
			break;
		default:
			printf("\n Invalid Entry");
	}
}
void customer()
{	
	int choice1;
	system("cls");
	printf("\n You are in customer mode");
	fordelay(100);
	printf("\n The options are:");
	printf("\n 1.New Account \n 2.Withdraw \n 3.Deposit \n 4.Balance \n 5.Information \n 6.Apply for Cheque \n 7.Apply for Debit Card \n 8.Exit ");
	printf("\n Please enter your choice:");
	scanf("%d",&choice1);
	switch(choice1)
	{
		case 1:
			printf("\n New Account function is activated");
			new_acc(
			);
			break;
		case 2:
			printf("\n Withdraw function is activated");
			withdraw();
			break;
		case 3:
			printf("\n Deposit function is activated");
			deposit();
			break;
		case 4:
			printf("\n Balance function is activated");
			balance();
			break;
		case 5:
			printf("\n Information function is activated");
			info();
			break;
		case 6:
			printf("\n Apply For Cheque function is activated");
			apply_cheque();
			break;
		case 7:
			printf("\n Apply For Debit Card function is activated");
			apply_debit_Card();
			break;
		case 8:
			printf("\n Exit function is activated");
			break;
			
		default:
			printf("\n Invalid Option");
			fordelay(10000);
	}
}
void new_acc()
{
	system("cls");
	int choice;
	FILE *ptr;
	ptr=fopen("record2.dat","a+");
	account_no:
		system("cls");
		printf("\t \t \t Add Record");
		printf("\n Enter today's date(mm/dd/yy):");
		scanf("%d/%d/%d",&add.deposit.month,&add.deposit.date,&add.deposit.year);
		printf("\n Enter Account Number:");
		scanf("%d",&add.acc_no);
	
		
		
		printf("\n Enter your Name:");
		scanf("%s",add.name);
		printf("\n Enter your aadharcard No:");
		scanf("%s",add.aadhar_card);
		printf("\n Enter your Account type:");
		scanf("%s",add.acc_type);
		printf("\n Enter your Gender:");
		scanf("%s",add.gender);
		printf("\n Enter your phone number ");
		scanf("%s",add.phone);
		
		printf("\n Enter the amount to be deposit:");
		scanf("%d",&add.balance);
		
		fprintf(ptr,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
		fclose(ptr);
		
		printf("\n Account Created Successfully");
}
void withdraw(void)
{
	int rows=0;
	system("cls");
	printf("\n\t\t\t Withdrawn function is activated");
	FILE *old , *new_rec;
	old=fopen("record2.dat","r");
	new_rec=fopen("temp.dat","w");
	printf("\n Enter your Account_Number:");
	scanf("%d",&update.acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
	{
		if(add.acc_no!=update.acc_no)
	{
		fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
		}
		else 
		{	
			printf("Enter the amount to be withdrawn:");
			scanf("%d",&update.balance);
			int t=add.balance;
			add.balance=0;
			add.balance=t-update.balance;
			fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
			rows++;
			printf("\n Successfully withdrawn");
		}
	}
	if(rows==0)
	{
		printf("\n No Account Match");
	}
	fclose(old);
	fclose(new_rec);
	remove("record2.dat");
	rename("temp.dat","record2.dat");
}
void deposit(void)
{	
	int rows=0;
	system("cls");
	printf("\n\t\t\t Deposit function is activated");
	FILE *old , *new_rec;
	old=fopen("record2.dat","r");
	new_rec=fopen("temp.dat","w");
	printf("\n Enter your Account_Number:");
	scanf("%d",&update.acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
	{
		if(add.acc_no!=update.acc_no)
	{
		fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
		}
		else 
		{	
			printf("Enter the amount to be deposit:");
			scanf("%d",&update.balance);
			int 
			t=add.balance;
			add.balance=0;
			add.balance=t+update.balance;
			fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
			rows++;
			printf("\n Successfully deposit");
		}
	}
	if(rows==0)
	{
		printf("\n No Account Match");
	}
	fclose(old);
	fclose(new_rec);
	remove("record2.dat");
	rename("temp.dat","record2.dat");
}
void balance()
{	int rows=0;
	system("cls");
	printf("\n\t\t\t Balance function is activated");
	FILE *ptr;
	search:
		ptr=fopen("record2.dat","a+");
	printf("\n Enter your Account Number:");
	scanf("%d",&check.acc_no);
		while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
	{
		printf("%d",add.acc_no);
		if(check.acc_no==add.acc_no)
		{ rows=1;
			printf("\n Account match");
			printf("Your Balance is:%d",add.balance);
			
		}
	}
	if(rows==0)
	{
		printf("Invalid Account Number!!!");
		printf("\n Account Not available");
	
	}
	
		fclose(ptr);
}
void info()
{
	int row=0;
	system("cls");
	printf("\n \t\t\t Information function is activated");
	FILE *view;
	view=fopen("record2.dat","r");
	printf("\n Enter your Account Number:");
	scanf("%d",&check.acc_no);
	while(fscanf(view,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
	{
		if(check.acc_no==add.acc_no)
		{
			printf("\n Acc_No. :%d",add.acc_no);
			printf("\n Name:%s",add.name);
			printf("\n Issued at:%d/%d/%d",add.deposit.month,add.deposit.date,add.deposit.year);
			printf("\n Aadhar_Card:%s",add.aadhar_card);
			printf("\n Account Type:%s",add.acc_type);
			printf("\n Gender:%s",add.gender);
		}
		row++;
		
	}
	fclose(view);
	if(row==0)
	{
		printf("\nUnderflow Condition");
		printf("\n No data available");
	}
}
void apply_cheque(void)
{
	int rows=0;
	system("cls");
	printf("\n \t\t\tApply for Cheque function is activated");
	FILE *old , *new_rec;
	old=fopen("record2.dat","r");
	new_rec=fopen("temp.dat","w");
	printf("\n Enter your Account_Number:");
	scanf("%d",&update.acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
	{
		if(add.acc_no!=update.acc_no)
	{
		fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
		}
		else 
		{	
			printf("100 Rupees will be deducted from your account:");
		
			add.balance-=100;
			fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
			rows++;
			printf("\n Successfully deposit");
		}
	}
	if(rows==0)
	{
		printf("\n No Account Match");
	}
	fclose(old);
	fclose(new_rec);
	remove("record2.dat");
	rename("temp.dat","record2.dat");
}

void apply_debit_Card(void)
{
	int rows=0;
	system("cls");
	printf("\n \t\t\tApply for Debit Card function is activated");
	FILE *old , *new_rec;
	old=fopen("record2.dat","r");
	new_rec=fopen("temp.dat","w");
	printf("\n Enter your Account_Number:");
	scanf("%d",&update.acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
	{
		if(add.acc_no!=update.acc_no)
	{
		fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
		}
		else 
		{	
			printf("300 Rupees will be deducted from your account:");
		
			add.balance-=300;
			fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
			rows++;
			printf("\n Successfully deposit");
		}
	}
	if(rows==0)
	{
		printf("\n No Account Match");
	}
	fclose(old);
	fclose(new_rec);
	remove("record2.dat");
	rename("temp.dat","record2.dat");

}
void view()
{	int row=0;
	system("cls");
	FILE *view;
	view=fopen("record2.dat","r");
	  printf("\nACC. NO.\tNAME\t\t\tAADHAR\t\t\tPHONE\n");
	while(fscanf(view,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
	{
		printf("\n%6d\t %10s\t\t\t%10s\t\t%.s",add.acc_no,add.name,add.aadhar_card,add.phone);
		row++;
	}
	fclose(view);
	if(row==0)
	{
		printf("\nUnderflow Condition");
		printf("\n No data available");
	}
	
}
void edit()
{
	int ch1,row=0;
	system("cls");
	printf("\n\t\t\t Editing Function is activated");
	FILE *open,*new_rec;
	open=fopen("record2.dat","r");
	new_rec=fopen("temp.dat","w");
	printf("\n Enter Account Number:");
	scanf("%d",&check.acc_no);
	while(fscanf(open,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
	{
		if(check.acc_no==add.acc_no)
		{
			printf("\n The options are:");
			printf("\n1.Edit Name \n2.Edit Aadhar No.\n3.Edit Acc_Type\n4.Edit Gender");
			printf("\n Enter your choice:");
			scanf("%d",&ch1);
			switch(ch1)
			{
				case 1:
					printf("\n Please enter new name:");
					scanf("%s",&add.name);
					break;
				case 2:
					printf("\n Please enter new aadhar no:");
					scanf("%s",&add.aadhar_card);
					break;
				case 3:
					printf("\n Please enter new Acc_type:");
					scanf("%s",&add.acc_type);
					break;
				case 4:
					printf("\n Please enter new Gender:");
					scanf("%s",&add.gender);
					break;
				default:
					printf("\n Invalid Number!!!");
			}
			printf("Successfully Modified");
		}
		fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);

		row++;
		
	}
		if(row==0)
	{
		printf("\n No Account Match");
	}
	fclose(open);
	fclose(new_rec);
	remove("record2.dat");
	rename("temp.dat","record2.dat");
	
}
void deleted()
{	int rows=0;
	system("cls");
	printf("\n\t\t\t Delete Function is activated");
	FILE *old;
	FILE *new_rec;
	old=fopen("record2.dat","r");
	new_rec=fopen("temp.dat","w");
	printf("\n Enter your Account_Number:");
	scanf("%d",&update.acc_no);
		while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s/n ",&add.acc_no,add.name,&add.deposit.month,&add.deposit.date,&add.deposit.year,&add.balance,add.aadhar_card,add.acc_type,add.gender)!=EOF)
		{
		if(add.acc_no!=update.acc_no)
		{
			fprintf(new_rec,"%d %s %d/%d/%d %d %s %s %s/n ",add.acc_no,add.name,add.deposit.month,add.deposit.date,add.deposit.year,add.balance,add.aadhar_card,add.acc_type,add.gender);
			
		}
		else 
		{rows++;
			printf("\n Record Deleted");
		}
	}
	if(rows==0)
	{
		printf("\n No Account Match");
	}
	fclose(old);
	fclose(new_rec);
	remove("record2.dat");
	rename("temp.dat","record2.dat");
}
