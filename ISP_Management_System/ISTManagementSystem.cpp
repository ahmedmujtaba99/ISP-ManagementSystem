	/*
	Name: DSA PROJECT
	Author: Ahmed Mujtaba and M Yousaf 
	Date: 23/02/22 12:41
	Description: INTERNET SERVICE PROVIDRE MANAGEMENT SYSTEM 	
    */


	#include<iostream>  
	#include<conio.h>  // using getch() function
	#include<windows.h>  //using Sleep() function
	#include<fstream>   //using file handing 
	
	
	//main menu function declaration
	void mainMenu();
	
	using namespace std;
	
	
	

    /*
	class person  which holds common things 
	of employee and customer class (parent class)
	 */
	
	class person{
		
		//access speicifiers
		public:
			
			//data members
			unsigned int id;
			string name;
			string address;
			string contact;
			
			//member function	
			
			// default constructor
		  person()
		  {
		  	id=0;
		  	name="null";
		  	address="null";
		  	contact="null";
		  }
			
				
	};
	
	
	/*
    class of employee haveing some data members
    alos have a default constuctor
	
	
	*/
	
	class employee:public person  //child class of person class
	{ 
	//   access spicifiers
	    public:
	    	
		string post; 
		string salary;
			
	//		default constructor
			employee()  
		{
			post="NULL";
			salary="NULL";
		}
		
	  
	};
	
	/*
	 node class of employee side 
	 have object of employee class
	 also have next pointer
	
	
	*/
	
	
	 class enode
	 {
	// 	access spicifire
	 	public:
	 		employee data;  //object of employee class
	 		enode* next;
	 };
	 
	 
	 /*
	list class of employye side 
	having data member and functions	
	
	*/
	 
	 class elist
	 {
	// 	access spicifirs
	 	private:
	 		
	 	//data member 
	 	enode* head;  //ojects of enode class
	 	enode* tail;
	 	
	 	//memeber function
	 	public:
	 		elist() //default constructor of employee list class
	 		{
	 			head=NULL;
	 			tail=NULL;
			 }
			 
	 	// member functions declaration
	    void employeeMenu();
		void addEmployee();
		void updateEmployee();
		void searchEmployee();
		void deleteEmployee();
		void deleteAllEmployee();
		void sort2();
		void displayAllEmployee();
	 };
	 
	 /*
	In employee menu() function we call all insert(),search()
	 update(),delete(),dispaly() etc functions and make a menu for
	 customer side using if else statement 
	
	
	*/
	 
	void elist::employeeMenu()
	{
		again:
			
		//It clear the  previous console
	 	system("cls"); 
		
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\tPlease, Choose from the following Options:"<<endl<<endl;
		cout<<"\t\t\t _______________________________________________________________"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t1-Add new employee data\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t2-Update employee data\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t3-Search employee data\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;	
		cout<<"\t\t\t|\t4-Delete employee data\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t5-Display employee data\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t6-Go back to main menu\t\t\t\t\t|"<<endl;	
		cout<<"\t\t\t|_______________________________________________________________|"<<endl;
		
		unsigned int ch;  // ch->choice
		cout<<endl<<"Enter your choice (integer )[1/2/3/4/5/6] "<<endl;
//		cin>>ch;
		while( !(cin>>ch))
		{
			cout<<"Choice must be a number[1/2/3]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
		if(ch==1)
		{
			addEmployee();
		}
		else if(ch==2)
		{
			updateEmployee();
		}
		else if(ch==3)
		{
		    searchEmployee();
		}
		else if(ch==4)
		{
			a1:
			int op;
			cout<<" Press 1 to delete one employee "<<endl;
			cout<<" press 2 to delete all employee "<<endl;
			cout<<"Enter your choice "<<endl;  
			cin>>op;
			if(op==1)
			{
				deleteEmployee();	
			}
			else if(op==2)
			{
				deleteAllEmployee();
			}
			else {
				cout<<" invalid input "<<endl;
				goto a1;
			}
		
		}
		else if(ch==5)
		{
			sort2();
			displayAllEmployee();
		}
		else if(ch==6)
		{
		   mainMenu();
		}
		else 
		{
			cout<<"invalid input "<<endl;
			cout<<"Please Enter integer [1/2/3/4/5/6]"<<endl;	
		}
		
		cout<<"press enter to continue <-|"<<endl;
		getch(); //take any charactor
		goto again;
	}
	
	
	/*
     This function  insert the record of every employee
	 in a node 
	 1.if it is first emplyee so it save record in 
	 first node
	 2.if it is not first employee so it save record in
	 last node
	 
	
	*/
	
	
	void elist::addEmployee()
	{
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tADD NEW EMPLOYEE RECORD"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
	    enode* curr=new enode();
	    
	    cout<<"Enter Employee ID(only interger) : "<<endl;
//	    cin>>curr->data.id;
    	while( !(cin>>curr->data.id))
		{
			cout<<"ID must be a number[unique]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
	    cout<<"Enter Employee Full Name : "<<endl;
	    cin.ignore();
	    getline(cin,curr->data.name);
	    cout<<"Enter Employee Contact Number : "<<endl;
	    getline(cin,curr->data.contact);
	    cout<<"Enter Employee Address : "<<endl;
	    getline(cin,curr->data.address);
	    cout<<"Enter Employee designation( job nature ) in Company : "<<endl;
	    getline(cin,curr->data.post);
	    cout<<"Enter Employee salary : "<<endl;
	    getline(cin,curr->data.salary);
	    cout<<"Employee record is saved successfully!!! "<<endl;
	    
	    
	    
	    curr->next=NULL;
	    if(head==NULL) // if no node is present so meke is first
	    {
	    	head=curr;
	    	tail=curr;
		}
		else  //make it last node
		 {
			tail->next=curr;
			tail=curr;
		}
	    
	    
	
	}
	
	/*
     This function update the record fo the employee.
	 take id from user, search from employee id 
	 and then user can modify  employee record
	
	
	*/
	
	//functon to update the employee record
	void elist::updateEmployee()
	{
		start:
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tUPDATE EMPLOYEE RECORD"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    if(head==NULL) // if linked list is emplty 
	    {
	    	cout<<"No Employee rocord is present "<<endl;
		}
		else 
		{
			int eid;
			cout<<"Enter Employee ID(only interger) : "<<endl;
			cin>>eid;
			int find_id=0;
			enode* curr;
			curr=head;
			
		    while(curr != NULL)
		    {
		    	if(eid==curr->data.id)
		    	{
		    		cout<<"\t _______________________________________________"<<endl;
					cout<<"\n\tEmployee ID is : "<<curr->data.id<<endl;
					cout<<"\n\tEmployee name is :"<<curr->data.name<<endl;
					cout<<"\n\tEmployee address is : "<<curr->data.address<<endl;
					cout<<"\n\tEmployee contact number  is : "<<curr->data.contact<<endl;
					cout<<"\n\tEmployee Post is : Rs "<<curr->data.post<<endl;
					cout<<"\n\tEmployee Salary : "<<curr->data.salary<<"/-"<<endl;
					cout<<"\n\t_______________________________________________"<<endl;
					
					cout<<endl<<endl;
					cout<<"You Can not change Employee Id as it is unique "<<endl<<endl;
					
					cout<<"Enter New Name of the Employee : "<<endl;
					cin.ignore();
					getline(cin,curr->data.name);
					
					cout<<"Enter New contact of the Employee : "<<endl;
					getline(cin,curr->data.contact);
					
					cout<<"Enter New Address of the Employee : "<<endl;
					getline(cin,curr->data.address);
					
					cout<<"Enter New designation of the Employee : "<<endl;
					getline(cin,curr->data.post);
					
					cout<<"Enter New Salary of the Employee : "<<endl;
					getline(cin,curr->data.salary);
					
		    		find_id++;
				}
				
				curr=curr->next;
			}
			
			if(find_id==0)
			{
				cout<<"\aSorry!!! Invalid ID "<<endl;
				char again='y';
				cout<<"Do you want to continue press(y/n) "<<endl;
				cin>>again;
				if(again=='y')
				{
					goto start;
				}
				else 
				{
					employeeMenu();
				}
				
			}
			
		}
		
	}
	
	
	/*
    This function update the record fo the employee.
	 take id from user, search from customer id 
	 and dispaly his/her detail
	
	*/
	
	//function to search the employee record 
	void elist::searchEmployee()
	{
		start:
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tSEARCH FROM EMPLOYEE RECORD"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
	    
	     if(head==NULL) // if linked list is emplty 
	    {
	    	cout<<"No Employee rocord is present "<<endl;
		}
		else 
		{
		
			int eid;
			cout<<"Enter Employee ID(only interger) : "<<endl;
//			cin>>eid;
    	while( !(cin>>eid))
		{
			cout<<"ID must be a number[unique]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
		
			int find_id=0;
			enode* curr;
			curr=head;
			
		    while(curr != NULL)
		    {
		    	if(eid==curr->data.id)
		    	{
		    		cout<<"\t _______________________________________________"<<endl;
					cout<<"\n\tEmployee ID is : "<<curr->data.id<<endl;
					cout<<"\n\tEmployee name is :"<<curr->data.name<<endl;
					cout<<"\n\tEmployee address is : "<<curr->data.address<<endl;
					cout<<"\n\tEmployee contact number  is : "<<curr->data.contact<<endl;
					cout<<"\n\tEmployee Post is : "<<curr->data.post<<endl;
					cout<<"\n\tEmployee Salary : "<<curr->data.salary<<"/-"<<endl;
					cout<<"\n\t_______________________________________________"<<endl;
			
		    		find_id++;
				}
				
				curr=curr->next;
			}
		
			
			if(find_id==0)
			{
				cout<<"\aSorry!!! Invalid ID "<<endl;
				char again='y';
				cout<<"Do you want to continue press[y/n] "<<endl;
				cin>>again;
				if(again=='y')
				{
					goto start;
				}
				else 
				{
					employeeMenu();
				}
				
			}
			
		}
		
	}
	
	
	/*
	 This function update the record fo the employee.
	 take id from user, search from customer id 
	 and delete this node
	
	*/
	
	void elist::deleteEmployee()
	{
		
		start:
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tDELETE FROM EMPLOYEE RECORD"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
	    	enode* curr;
		 	curr=head;
		 	
		 	if(head == NULL)
		 	{ 
		 	cout<<"NO Employee is present so please first add employee rercord  "<<endl;
		 	return ;
			}
			else {
				
				unsigned int eid;
				int find_yes=0;
			    cout<<"Enter Employee ID(only interger) : "<<endl;
//				cin>>eid;
				while( !(cin>>eid))
				{
				cout<<"ID must be a number[unique]"<<endl;
				cin.clear();
				cin.ignore(100,'\n');
}
				//if employee is present in first node (best case)
				if(eid == curr->data.id)
				{
					head=head->next;
					delete (curr);
					find_yes=find_yes+1;
				
				}
				//else employee is presen in middle or in last of the list
				else 
				{
				   curr=curr->next;
				   enode* prev=head;
					while(curr != NULL)
					{
						if(eid == curr->data.id)
						{
						prev->next=curr->next;
						delete(curr);
						find_yes=find_yes+1;
						break;
				    	}
				    		prev=curr;
				        	curr=curr->next;
				
					}
					if(find_yes==0)
					{
						cout<<"\aSorry!!! Invalid ID "<<endl;
				char again='y';
				cout<<"Do you want to continue press(y/n) "<<endl;
				cin>>again;
				if(again=='y')
				{
					goto start;
				}
				else 
				{
					employeeMenu();
				}
					
				}
		     	else
			    {
			    cout<<"Record of this Employee is delete Successfully "<<endl;	
				}
					
					
				}
				
			}
		 
		
	}
	
	
	/*
	this funciont delete the all
	detalis of the employees
	
	
	*/
	
	void elist::deleteAllEmployee()
	{
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tDELETE ALL EMPLOYEE RECORD"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
	    if(head == NULL)
		{
			cout<<"No customer is present first add Customer "<<endl;
		}
		else 
		{
			char yes='y';
			cout<<"Are your sure you want to delete All records [y/n]" <<endl;
			cin>>yes;
			if(yes=='y')
			{
			enode* curr;
			curr=head;
			while(curr != NULL)
			{
				curr=curr->next;
				delete(head);
				head=curr;
			}
			cout<<"Records of All Employees is deleted successfully "<<endl;
			
		}
		}
	    
	    
		
	}
	
	
	/*
    function to sort details of the employee
    and then we call simply display function
	
	*/
	
	
	void elist::sort2()
	{
		/*
		once we check this condition in sort fuction 
		so we dsnt need to check it again in display fuction
		*/

		 if(head==NULL) // if linked list is emplty 
	    {
	    	cout<<"No Employee rocord is present "<<endl;
		}
		else 
		{
			int count=0;
			enode* curr=head;
			while(curr != NULL)
			{
				count++;
				curr = curr->next;
			}
			int s_id;
			string s_name;
			string s_address;
			string s_contact;
			string s_post;
			string s_salary;
			
			for(int i=1;i<=count;i++)  //outer loop
			{
				enode* curr=head; 
			    	for(int j=1;j<count;j++) ///inner loop
					{
						if(curr->data.id > curr->next->data.id)
						{
							//swaping code
							
							//store data in sample variable
							s_id=curr->data.id;
							s_name=curr->data.name;
							s_address=curr->data.address;
							s_contact=curr->data.contact;
							s_post=curr->data.post;
							s_salary=curr->data.salary;
							
							//store data in current node
							curr->data.id=curr->next->data.id;
						    curr->data.name=curr->next->data.name;
							curr->data.address=curr->next->data.address;
							curr->data.contact=curr->next->data.contact;
							curr->data.post=curr->next->data.post;
							curr->data.salary=curr->next->data.salary;
							
							//store data in current->next node
							curr->next->data.id=s_id;
						    curr->next->data.name=s_name;
							curr->next->data.address=s_address;
							curr->next->data.contact=s_contact;
							curr->next->data.post=s_post;
							curr->next->data.salary=s_salary;
								
							
						}
						curr = curr->next;
					 } 
				
			}
			
		}
		
	}
	
	
	/*
	this function display the data of all employees
	
	
	*/
	
	
	void elist::displayAllEmployee()
	{
			system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tRECORD OF ALL EMPLOYEES"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
	  
			int total=0;
			enode* curr;
			curr=head;
			
			enode* ptr; //for total number of employees
			ptr=head;
			while(ptr != NULL)
			{
				total++;
				ptr=ptr->next;
			}
			cout<<"\n\tTotal No of Employees are : "<<total<<endl<<endl;
			
		    while(curr != NULL)
		    {
		
		cout<<"\t _______________________________________________"<<endl;
					cout<<"\n\tEmployee ID is : "<<curr->data.id<<endl;
					cout<<"\n\tEmployee name is :"<<curr->data.name<<endl;
					cout<<"\n\tEmployee address is : "<<curr->data.address<<endl;
					cout<<"\n\tEmployee contact number  is : "<<curr->data.contact<<endl;
					cout<<"\n\tEmployee Post is : "<<curr->data.post<<endl;
					cout<<"\n\tEmployee Salary : "<<curr->data.salary<<"/-"<<endl;
					cout<<"\n\t_______________________________________________"<<endl;
			cout<<"\n********************************************************************"<<endl;
				curr=curr->next;
			}
	
	}
	

//==============================================================================================
	
	/*
	customer class 
	have some data members
	extend by person class
	*/
	
 
	class customer:public person
	{ 
	     
			public:
		string date_Of_Join;
		string packg;
		unsigned int payment;
		
			customer()  //default constructor of customer class
		{	
			date_Of_Join="NULL";
			packg="NULL";
			payment=0;
		}
	};
	
	
	/*
	//node class of customer side
	we declear the object of customer class(composition)
    and have a next pointer 
	*/
	
	 
	class node{        
		public:
			customer data;
			node* next;
	};
	
	
	/*
	//list class of customer side
	we declear the object of node class(composition)
    also declear the function of  all features in employee side
	*/
	
	class list{
		private:
		node* head;
		node* tail;
		public:
			list()  //default constructor of list class 
			{
				head=NULL;
				tail=NULL;
			}
			void customerMenu();
			void addCustomer();
			void updateCustomer();
			void searchCustomer();
			void deleteCustomer();
			void deleteAllCustomer();
			void sort();
			void displayAllCustomer();
	        void addMonthyPayment();
	
			
		
	};
	
	/*
	 In customer menu() function we call all insert(),search()
	 update(),delete(),dispaly() etc functions and make a menu for
	 customer side using if else statement 
	*/
	
	void list::customerMenu()
	{
		int ch;
		
		again:
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\tPlease, Choose from the following Options:"<<endl<<endl;
		cout<<"\t\t\t _______________________________________________________________"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t1-Add new customer record\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t2-Update customer record\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t3-Search customer record\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;	
		cout<<"\t\t\t|\t4-Delete Customer record\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t5-Display customers record\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t6-To add Monthly Payment of customers\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t7-Go back to main menu\t\t\t\t\t|"<<endl;	
		cout<<"\t\t\t|_______________________________________________________________|"<<endl;
		
		cout<<endl<<"Enter your choice [1/2/3/4/5/6/7] "<<endl;
	   
//	    cin>>ch;
 	while( !(cin>>ch))
		{
			cout<<"Choice must be a number[1/2/3]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
	   
		if(ch==1)
		{
		addCustomer();
		}
		else if(ch==2)
		{
		updateCustomer();	
		}
		else if(ch==3)
		{
		searchCustomer();	
		}
		else if(ch==4)
		{
	  	  system("cls");
			cout<<endl<<endl;
			cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl;
		    cout<<" "<<endl;
		    cout<<"\t\t\t\t\tCUSTOMER RECORD IS GIVEN BELOW"<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
		int op;
		lable1:
		cout<<"Press 1 to Delete record of any Customer "<<endl;
		cout<<"Press 2 to Delete record of ALL Customer"<<endl<<endl;//it delete all node
		cout<<"Choose From the above Option "<<endl;
		cin>>op;
		if(op==1)
		{
		deleteCustomer();	
		}
		else if(op==2)
		{
		deleteAllCustomer();	
		}
		else {
			cout<<"INVALID INPUT "<<endl;
			goto lable1;
		}
			
		}
		else if(ch==5)
		{
		 sort();
	    displayAllCustomer();
		}
		else if(ch==6)
		{
		addMonthyPayment();
		}
		else if(ch==7)
		{
	      mainMenu();
		}
		else {
			cout<<"Invalid input "<<endl;
		    }
		
		cout<<"press enter to continue <-|"<<endl;
		getch();//it take any char from user
		
		goto again;
		
		
	}
	
	/*
	 This function  insert the record of every cutomer
	 in a node 
	 1.if it is first customer so it save record in 
	 first node
	 2.if it is not first customer so it save record in
	 last node
	*/
	

	void list::addCustomer()
	{
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tADD NEW CUSTOMER RECORD"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
	    node* curr=new node();
	    
	    cout<<"Enter Customer ID(only integer):"<< endl; 
//	    cin>>curr->data.id;
       	while( !(cin>>curr->data.id))
		{
			cout<<"ID must be a number[unique]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
	    
	    cout<<"Enter Customer Name  : "<<endl;
	    cin.ignore();
	    getline(cin,curr->data.name);
	    
	    cout<<"Enter Customer Address : "<<endl;
	    getline(cin,curr->data.address);
	    
	    cout<<"Enter Contact Number :"<<endl;
	    getline(cin,curr->data.contact);
	    
	    cout<<endl;
	    cout<<"\tPACKAGES\tVOLUME\t\t$(PKR)"<<endl<<endl;
		cout<<"\t1 Mbps\t\tUNLIMITED*\t1000"<<endl;
		cout<<"\t2 Mbps\t\tUNLIMITED*\t2000"<<endl;
		cout<<"\t3 Mbps\t\tUNLIMITED*\t3000"<<endl;
		cout<<"\t4 Mbps\t\tUNLIMITED*\t4000"<<endl;
		cout<<"\t5 Mbps\t\tUNLIMITED*\t5000"<<endl;
		cout<<"\t6 Mbps\t\tUNLIMITED*\t6000"<<endl;
		cout<<"\t8 Mbps\t\tUNLIMITED*\t8000"<<endl<<endl;
		
		cout<<"Enter Pakcage details "<<endl;
		getline(cin,curr->data.packg);
		
		cout<<"Enter payment details "<<endl;
	//	getline(cin,curr->data.payment);
//	    cin>>curr->data.payment;
	while( !(cin>>curr->data.payment))
		{
			cout<<"Payment must be in numbers"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
		
		cout<<"Ente Customer Date Of Join [dd/mm/yyyy]"<<endl;
		cin.ignore();
		getline(cin,curr->data.date_Of_Join);
		
		curr->next=NULL;
		if(head==NULL) // if it is first node 
		{
			head=curr;
			tail=curr;
		}
		else  //add in last node
		{
			tail->next=curr;
			tail=curr;
		}
			cout<<"Customer record is saved!! successfully "<<endl	;
	}
	
	
	/*
	 This function update the record fo the customer.
	 take id from user, search from customer id 
	 and then user can modify  customer record
	*/
	 
	 
	void list::updateCustomer()
	{
			
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tModify CUSTOMER RECORD"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
		
		int cid;
	    int find_cid=0;
		if(head==NULL)  //if linked list is empty
		{
			cout<<"There is no customer so please enter cusotmer records"<<endl;
		}
		else
		{
	    start:
	    node* curr;
		curr=head;
	    cout<<"Enter Customer ID(only integer):"<< endl; 
//	    cin>>cid;
	    while( !(cin>>cid))
		{
			cout<<"ID must be a number[unique]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
	    while(curr != NULL)
	    {
	    	if(cid==curr->data.id)
	    	{
	    	system("cls");
			cout<<endl<<endl;
			cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl;
		    cout<<" "<<endl;
		    cout<<"\t\t\t\t\tUPDAE CUSTOMER RECORD"<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
			cout<<"Customer previous record is given below "<<endl<<endl;
			
			cout<<"\t\t_______________________________________________"<<endl;
			cout<<"\t\tCustomer ID is : "<<curr->data.id<<endl;
			cout<<"\t\tCustomer name is :"<<curr->data.name<<endl;
			cout<<"\t\tCustomer address is : "<<curr->data.address<<endl;
			cout<<"\t\tCuctomer contact number is:"<<curr->data.contact<<endl;
			cout<<"\t\tCustomer package is : "<<curr->data.packg<<endl;
			cout<<"\t\tCustomer payment is : Rs "<<curr->data.payment<<"/-"<<endl;
			cout<<"\t\tCustomer date of join is : "<<curr->data.date_Of_Join<<endl;
			cout<<"\t\t_______________________________________________"<<endl;
			
			cout<<"You can't change Customer ID : "<<curr->data.id<<endl;
			
			cout<<"Enter New Name of Customer : "<<endl;
		    cin.ignore();
			getline(cin,curr->data.name);
			
			cout<<"Enter New Address of Customer : "<<endl;
			getline(cin,curr->data.address);
			
			cout<<"Enter New Contact Number :"<<endl;
	        getline(cin,curr->data.contact); 
			
			cout<<endl;
		    cout<<"\tPACKAGES\tVOLUME\t\t$(PKR)"<<endl<<endl;
			cout<<"\t1 Mbps\t\tUNLIMITED*\t1000"<<endl;
			cout<<"\t2 Mbps\t\tUNLIMITED*\t2000"<<endl;
			cout<<"\t3 Mbps\t\tUNLIMITED*\t3000"<<endl;
			cout<<"\t4 Mbps\t\tUNLIMITED*\t4000"<<endl;
			cout<<"\t5 Mbps\t\tUNLIMITED*\t5000"<<endl;
			cout<<"\t6 Mbps\t\tUNLIMITED*\t6000"<<endl;
			cout<<"\t8 Mbps\t\tUNLIMITED*\t8000"<<endl<<endl;
			cout<<"Enter New Package : "<<endl;
			getline(cin,curr->data.packg);
			
			cout<<"Ente New Payment : "<<endl;
	//		getline(cin,curr->data.payment);
//	        cin>>curr->data.payment;
    	while( !(cin>>curr->data.payment))
		{
			cout<<"payment must be in integer"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
			
			cout<<"Enter Customer New Date of Join "<<endl;
			cin.ignore();
			getline(cin,curr->data.date_Of_Join);
		
			find_cid=find_cid+1; //find_cid++;
			}
			curr=curr->next;
		}
			if(find_cid==0)
	    {
	    		cout<<"\aSorry!!! Invalid ID "<<endl;
				char again='y';
				cout<<"Do you want to continue press(y/n) "<<endl;
				cin>>again;
				if(again=='y')
				{
					goto start;
				}
				else 
				{
					customerMenu();
				}
		}
		
		}
	}
	
	/*
	 This function dispaly the record of a customer.
	 take id from user, search from customer id 
	 and then dispaly the customer record
	
	*/
	
	void list::searchCustomer()
	{
		
		start:
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tSearch CUSTOMER RECORD"<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
		
		int cid;
	    int find_cid=0;
		if(head==NULL)  //if linked list is empty
		{
			cout<<"There is no customer so please enter cusotmer records"<<endl;
		}
		else
		{
	   
	    node* curr;
		curr=head;
	    cout<<"Enter Customer ID(only integer):"<< endl; 
//	    cin>>cid;
	    while( !(cin>>cid))
		{
			cout<<"ID must be a number[unique]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
	    while(curr != NULL)
	    {
	    	if(cid==curr->data.id)
	    	{
	    	  system("cls");
			cout<<endl<<endl;
			cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl;
		    cout<<" "<<endl;
		    cout<<"\t\t\t\t\tCUSTOMER RECORD IS GIVEN BELOW"<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
			
			cout<<"\t\t_______________________________________________"<<endl;
			cout<<"\t\tCustomer ID is : "<<curr->data.id<<endl;
			cout<<"\t\tCustomer name is :"<<curr->data.name<<endl;
			cout<<"\t\tCustomer address is : "<<curr->data.address<<endl;
			cout<<"\t\tCuctomer contact number is:"<<curr->data.contact<<endl;
			cout<<"\t\tCustomer package is : "<<curr->data.packg<<endl;
			cout<<"\t\tCustomer payment is : Rs "<<curr->data.payment<<"/-"<<endl;
			cout<<"\t\tCustomer date of join is : "<<curr->data.date_Of_Join<<endl;
			cout<<"\t\t_______________________________________________"<<endl;
			find_cid=find_cid+1; //find_cid++;
			}
			curr=curr->next;
		}
		
		 //if customer id is invalid 
			if(find_cid==0)
	    {
	    		cout<<"\aSorry!!! Invalid ID "<<endl;
				char again='y';
				cout<<"Do you want to continue press(y/n) "<<endl;
				cin>>again;
				if(again=='y')
				{
					goto start;
				}
				else 
				{
					customerMenu();
				}
		}
		
		}
	
	}
	
	
	/*
    first user have to enter customer unique id
    search from customer id , after show the 
    previus record of the customter and then user 
    can add monthly payment of customer 
	add previus paymemt + new payment
	*/
	

	void list::addMonthyPayment()
	{
		start:	
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl;
	    cout<<" "<<endl;
	    cout<<"\t\t\t\t\t\tADD MONTHLY PAYMENT "<<endl;
	    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
	    
		
		int cid;
	    int find_cid=0;
		if(head==NULL)  //if linked list is empty
		{
			cout<<"There is no customer so please enter cusotmer records"<<endl;
		}
		else
		{
	   	int mpayment;
	    node* curr;
		curr=head;
	    cout<<"Enter Customer ID(only integer):"<< endl; 
//	    cin>>cid;
	   while( !(cin>>cid))
		{
			cout<<"ID must be a number[unique]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
	    while(curr != NULL)
	    {
	    	if(cid==curr->data.id)
	    	{
	    	system("cls");
			cout<<endl<<endl;
			cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl;
		    cout<<" "<<endl;
		    cout<<"\t\t\t\t\tAdd Monthly Payment"<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;
		    
			cout<<"\t\t_______________________________________________"<<endl;
			cout<<"\t\tCustomer ID is : "<<curr->data.id<<endl;
			cout<<"\t\tCustomer name is :"<<curr->data.name<<endl;
			cout<<"\t\tCustomer address is : "<<curr->data.address<<endl;
			cout<<"\t\tCustomer package is : "<<curr->data.packg<<endl;
			cout<<"\t\tCustomer payment is : Rs "<<curr->data.payment<<"/-"<<endl;
			cout<<"\t\tCustomer date of join is : "<<curr->data.date_Of_Join<<endl;
			cout<<"\t\t_______________________________________________"<<endl;
			
		    cout<<"Enter payment of this month : "<<endl;
		    cin>>mpayment;
		    curr->data.payment=curr->data.payment + mpayment; //previous payment + new payment
			find_cid=find_cid+1; //find_cid++;
			}
			curr=curr->next;
		}
			if(find_cid==0)
	    {
	    		cout<<"\aSorry!!! Invalid ID "<<endl;
				char again='y';
				cout<<"Do you want to continue press(y/n) "<<endl;
				cin>>again;
				if(again=='y')
				{
					goto start;
				}
				else 
				{
					customerMenu();
				}
		}
		
		}
	}
	
	
	/*
	this function sort the customer record
	we use bubble sorting technique to sort 
	the customer rercord  
	
	*/
	
	
	//fuction to sort all the record of the customer 
	void list::sort()
	{
		/*
		once we check this condition in sort fuction 
		so we dsnt need to check it again in display fuction
		*/
		
	    if (head==NULL)  //if linked list is empty
	    {
		cout<<"There is no customer so please enter cusotmer records"<<endl;	
	    }
	    else
	    {
	    	int count=0;
	    	int s_id;
	    	string s_name;
	    	string s_address;
	    	string s_contact;
	    	string s_package;
	    	int s_payment;
	    	string s_date;
	    	node* curr=head;
	    	while(curr != NULL)
	    	{
	    		count++;
	    		curr=curr->next;
			}
		    for(int i=1; i<=count; i++)//outer loop
		    {
		    		node *curr;
		    		curr=head;
		    	for(int j=1 ;j<count; j++)//inner loop
		    	{
		    	
		    		if(curr->data.id > curr->next->data.id)
		    		{
		    			//swapping code
		    			// Save Data into sample Variables
		    			
		    			s_id=curr->data.id;
		    			s_name=curr->data.name;
		    			s_contact=curr->data.contact;
		    			s_address=curr->data.address;
		    			s_package=curr->data.packg;
		    			s_payment=curr->data.payment;
		    			s_date=curr->data.date_Of_Join;
		    			
		    			// Save Data into Current Node	
		    			
		    			curr->data.id=curr->next->data.id;
		    			curr->data.name=curr->next->data.name;
		    			curr->data.contact=curr->next->data.contact;
		    			curr->data.address=curr->next->data.address;
		    			curr->data.packg=curr->next->data.packg;
		    			curr->data.payment=curr->next->data.payment;
		    			curr->data.date_Of_Join=curr->next->data.date_Of_Join;
		    			
		    			// Save Data into Next Node
		    			
		    		   curr->next->data.id=s_id;	
		    		   curr->next->data.name=s_name;	
		    		   curr->next->data.contact=s_contact;	
		    		   curr->next->data.address=s_address;	
		    		   curr->next->data.packg=s_package;	
		    		   curr->next->data.payment=s_payment;
					   curr->next->data.date_Of_Join=s_date;	
	                
					}
					curr=curr->next;
				}
			}
		}	
	}
	
	
	/*
	This function dispaly the record of all 
	customer in sorted form
	also display the total numbver of customers
	in our program
	
	*/
	 
	void list::displayAllCustomer()
	{
	    	system("cls");
			cout<<endl<<endl;
			cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl;
		    cout<<" "<<endl;
		    cout<<"\t\t\t\t\tRECORD OF ALL CUSTOMER"<<endl;
		    cout<<"\t\t\t_______________________________________________________________"<<endl<<endl;	
		    
		    node* curr=head;
		    int total=0;
		    node *ptr=head;
		  
				//to count total number of customer
			while(ptr != NULL)
			{
				ptr=ptr->next;
				total=total+1;
			}
			
			cout<<"\t\tTotal Number of Customer are : "<<total<<endl<<endl;
			
			while(curr != NULL)	
			{
				
			cout<<"\t\t_______________________________________________"<<endl;
			cout<<"\t\tCustomer ID is : "<<curr->data.id<<endl;
			cout<<"\t\tCustomer name is :"<<curr->data.name<<endl;
			cout<<"\t\tCustomer address is : "<<curr->data.address<<endl;
			cout<<"\t\tCuctomer contact number is:"<<curr->data.contact<<endl;
			cout<<"\t\tCustomer package is : "<<curr->data.packg<<endl;
			cout<<"\t\tCustomer payment is : Rs "<<curr->data.payment<<"/-"<<endl;
			cout<<"\t\tCustomer date of join is : "<<curr->data.date_Of_Join<<endl;
			cout<<"\t\t_______________________________________________"<<endl;
			cout<<endl;
			cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			curr=curr->next;	
	     	}
		
	}
	
	
	/*
	 first user have to enter customer unique id
    search from customer id , after matching the 
	id this method will delete this node 

	*/
	

	void list::deleteCustomer()
	{
		    start:
			node* curr;
		 	curr=head;
		 	
		 	if(head == NULL)
		 	{ 
		 	cout<<"NO Customer is present so please first add customer rercord  "<<endl;
		 	return ;
			}
			else {
				
				int cid;
				int find_yes=0;
				again:
				cout<<"Enter Customer ID(only integer):"<<endl; 
//				cin>>cid;
			    while( !(cin>>cid))
				{
					cout<<"ID must be a number[unique]"<<endl;
					cin.clear();
					cin.ignore(100,'\n');
				}
				//if customer is present in first node (best case)
				if(cid == curr->data.id)
				{
					head=head->next;
					delete (curr);
					find_yes=find_yes+1;
				
				}
				//else customer is presen in middle or in last node
				else 
				{
				   curr=curr->next;
				   node* prev=head;
					while(curr != NULL)
					{
						if(cid == curr->data.id)
						{
						prev->next=curr->next;
						delete(curr);
						find_yes=find_yes+1;
						break;
				    	}
				    		prev=curr;
				        	curr=curr->next;
				
					}
					if(find_yes==0)
					{
							cout<<"\aSorry!!! Invalid ID "<<endl;
							char again='y';
							cout<<"Do you want to continue press(y/n) "<<endl;
							cin>>again;
							if(again=='y')
							{
								goto start;
							}
							else 
							{
								customerMenu();
							}
					}
					else
				    {
				    cout<<"Record of this Customer is delete Successfully "<<endl;	
					}
					
					
				}
				
			}
  
	}
	
	/*
	this method delete All the records of 
	the customer (delete all node) 
	first ask user to comfirm to delete all 
	node then it delete all nods
	
	*/
	
	
	void list::deleteAllCustomer()
	{
		if(head==NULL)
		{
			cout<<"No customer is present first add Customer "<<endl;
		}
		else 
		{
			char yes='y';
			cout<<"Are your sure you want to delete All records [y/n]" <<endl;
			cin>>yes;
			if(yes=='y')
			{
			node* curr;
			curr=head;
			while(curr != NULL)
			{
	//			head=head->next;
	//			delete(curr);
				curr=curr->next;
				delete(head);
				head=curr;
			}
			cout<<"Records of All Customer is deleted successfully "<<endl;
		}
		}
	}
	
	 /*
	after loging the to program user have 3 main option
	1 for emplyeee side
	2 for customer side
	3 for exit
	
	*/
	 
	 void mainMenu()
	 {
	 
	    while(true)
	    {
	    
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\tPlease, Choose from the following Options:"<<endl<<endl;
		cout<<"\t\t\t _______________________________________________________________"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t1-Employee Side\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t2-Customer Side\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|"<<endl;
		cout<<"\t\t\t|\t3-Exit the Program\t\t\t\t\t|"<<endl;	
		cout<<"\t\t\t|_______________________________________________________________|"<<endl;
		
		int option;
		cout<<"Enter you choice[1/2/3] : ";
		while( !(cin>>option))
		{
			cout<<"Choice must be a number[1/2/3]"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}

		
		if(option == 1)
		{
	     elist eobj;
	     eobj.employeeMenu();
		}
		else if(option == 2)
		{
		list obj; //object of list class (customer)
		obj.customerMenu();	
		}
		else if(option == 3)
		{
		exit(0);
		}
		else 
		{
		cout<<"\aInvlaid input "<<endl;
		Sleep(1000);  //it pouse the console for 1sec
		}
	}
	 }
	 
	 
	 
//      console the program
	int main()
	{
		cout<<"\n\n\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl;
		cout<<"\n\t\t\t\tDSA PROJECT"<<endl;
		cout<<"\n\n\t\tDeveloped by 'AHMED MUJTABA' AND 'YOUSUF EJAZ'"<<endl;
		cout<<"\n\n\t\tInstuctor: AHMAD ARSALAN"<<endl;
		Sleep(5000);  //wait for 5 second
		
		system("cls");
		cout<<"\n\n\t\tINTERNET SERVICE PROVIDER MANAGEMENT SYSTEM"<<endl<<endl;
		//we save default user name and password 
		string username="msfiber";
		string password="pak786786";
	
		//login code
		start:
	
		cout<<"\n\n\t\tLogin "<<endl;
		string username1;
		string password1;
		cout<<"\n\tEnter Username : ";
		cin>>username1;
		cout<<"\n\tEnter password : ";
		cin>>password1;
		
		/*
	   	this lines perform the file handing in our login page
	
	   */
	
		ofstream myfile("login.txt");
		myfile<<username1<<endl;
		myfile<<password1<<endl;
		myfile.close();
		
		
		if(username1 == username && password1 == password)
		{
		cout<<"\n  matching user name and password, please wait ";
		for(int i=0;i<2;i++)
		{
			cout<<".";
			Sleep(1000);        //it pause the console for 1 second
		}
		mainMenu(); // calling main Menu fuction
	   }
	   else if(username1 != username)
	   {
	
		cout<<"Your username is incorrect..."<<endl;
		cout<<"please wait...."<<endl;
		Sleep(2000);//wait for 2 seconds 
		goto start;
		}
		else if(password1 != password)
		{
			cout<<"Your password is incorrect..."<<endl;
			cout<<"please wait...."<<endl;
			Sleep(2000);//wait for 2 seconds
		   goto start;//incondition jump statement
		}

	
		
		return 0;
	}
