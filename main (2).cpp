#include<iostream>
using namespace std;




struct patient //data type defined for patient
{
	string fname,lname;
	unsigned long long int adhar_no; //12 digit adhar number so (0, +18,446,744,073,709,551,615)
	unsigned long long int mo_no;
	char gender;
	int dob;  // -2147483647 to 2147483647
	int age;
	string bp;
	string address;
	int temperature;
};




struct node     //to create linked list
{
	patient obj;//Obj - in struct node for data field of node in linked List.
	node *next;
}*head,*tail = NULL; // create null linked list it is constructor




class co_vaccine
{
	public:
	int a;
	
	
	
	
	void add_data()  //function to add new entries, delete last entry.
	{
		system("cls");               //clear current screen
		cout << "\t\t\t\t\t\t\t\t\t||*||*||*||*||  PATIENT DATA  ||*||*||*||*||" << endl;
		int m;
		cout << "Press" << endl;
		cout << "1. Add New Patient" << endl << "2. Delete Last Entry" << endl;	
	    cout << "Enter your Choice";
		cin >> m;                                          // created menu to add data
		
		switch(m)
		{
			case 1: 
		    if ( a > 0)    //checks vaccine count 
        		{
		        	createnode();
			        a--;
	        	}
    		else
        		{ 
        			cout << "Vaccines are not Available" << endl;
        			addvaccine();
        		}
			break;
			case 2: 
			if(head == NULL)             //checks condition for emptiness 
     		{
    			cout << "No Data Available!" << endl;
    		}
    		else
    		{
    			deletenode();
    			a++;
    		}
			
			break;
			default: 
			cout << "Error" << endl;
		}
		wait();
	}         
	
	
	
	
	void createnode()  //function to add new entries called under add_data()
    	{
    	system("cls");
    	cout << "\t\t\t\t\t\t\t\t\t|*|*|*|*|  ADD NEW DATA  |*|*|*|*|" << endl;
		patient p;//P- to deal with operation
		node *temp = new node;                             //declared pointer of type node
        cout << "Enter Full Name(Name and Surname) : ";
		cin >> p.fname >> p.lname;
		cout << "Enter Aadhar Number : ";
		cin >> p.adhar_no;
		cout << "Enter Mobile Number : ";
		cin >> p.mo_no;
		cout << "Enter Gender(M/F) : ";
		cin >> p.gender;
		cout << "Enter Date of Birth(DDMMYY) : ";
		cin >> p.dob;
		cout << "Enter Age : ";
		cin >> p.age;
		cout << "Enter Blood Group : ";
		cin >> p.bp;
		cout << "Enter Address(City) : ";
		cin >> p.address;
		cout << "Enter Temperature in F : ";
		cin >> p.temperature;
		
		temp -> obj = p;                                  //added data to obj patient
		temp -> next = NULL;                              //set next null to set temp as last node in list
		
		if(head == NULL)                                  //checks null list and set head and tail as 1st node of list
			{
				head = temp;
				tail = temp;
			}
			else                                  //if not empty, set next field of tail to temp it will pass address of new node to tail node
			{
				tail -> next = temp;
				tail = tail -> next;              //set tail pointer to new node as tail pointer always point to last node 
			}
			cout << "Patient Added Succesfully........" << endl;
    	}
    
    
    
    
	void deletenode()  //function to delete last entry called under add_data()
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\t\t||*||*||*||*||     DELETE DATA     ||*||*||*||*||" << endl;
		node *temp1,*temp2;              //defined to node pointers
		temp1 = head;
		if(temp1 -> next == NULL)         //condition for one node
		{
			head = NULL;
			cout << "Deleted patient is : " << temp1 -> obj.fname << endl;
			delete(temp1);
		}
		else
		{
			while(temp1 -> next != NULL)     //loop to traverse through list till last node arrives
			{
			temp2 = temp1;                 
			temp1 = temp1 -> next;       //moves temp node to next node
		    }
		    temp2 -> next = NULL;        //second last node will point to null
		    cout << "Deleted patient is : " << temp1 -> obj.fname << " " << temp1 -> obj.lname << endl;
		    delete(temp1);
		}
		wait();
	}	
    	
	
	
	
	void view_data()  //function to view stock of vaccines, full patients data.
	{
		int v;
		system("cls");
		cout << "\t\t\t\t\t\t\t\t\t||*||*||*||*||  CURRENT DATA  ||*||*||*||*||" << endl;
		cout << "Press" << endl;
		cout << "1. Add New Vaccines" << endl << "2. View available number of vaccines" << endl << "3. View all Data" << endl;	
	    cout << "Enter your Choice : ";
		cin >> v;
		switch(v)
		{
			case 1: addvaccine();
			break;
			case 2: viewvaccine();
			break;
			case 3: display();
			break;
			default: 
			cout << "Error" << endl;
		}
		wait();	
	}  
	
	
	
	
	void viewvaccine()  //function to view vaccine stock.
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\t\t||*||*||*||*||     VACCINE DATA     ||*||*||*||*||" << endl;
		cout << "Available Number of Vaccines:" << a << endl;

	} 
	
	
	
	
	void addvaccine()  //function to add vaccine stock.
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\t\t||*||*||*||*||     VAACCINE DATA     ||*||*||*||*||" << endl;
		a = 0;
		cout << "Enter Number of Vaccines: ";
		cin >> a;
		cout << "Available Vaccines are " << a << endl;
	}
	
	
	
	
	void wait()  //function for creating "press any key to continue.."
	{
		char x;
		cout << "Press any key to continue :" << endl;
		cin >> x;
		switch(x)
		{
			default:
			system("cls");	
		}
	}
	
	
	
	
	void display()  //function to display full patients data.
    	{
    	system("cls");
    	cout << "\t\t\t\t\t\t\t\t\t||*||*||*||*||     DISPLAY DATA     ||*||*||*||*||" << endl;
		cout <<"SRNO "<<"\t\tName"<<"\t\t\tAdhar"<<"\t\t\tMOB"<<"\t\t\tGENDER"<<"\t\tDOB"<<"\t\tAGE"<<"\t\tBlood Group"<<"\t\tADDRESS"<<"\t\t\tTEMP"<< endl;
		node *temp;
			temp = head;
			if(head == NULL)
			{
				cout << "List is Empty!!!" << endl;
			}
			else
			{
			    int i = 1;
				while(temp != NULL)     //loop to traverse through list till it arrives last node
				{
				    cout << i <<".)"<<" ";
					cout <<"\t" << temp -> obj.fname << " " << temp -> obj.lname;
					cout << "\t\t"<< temp -> obj.adhar_no << "";
					cout << "\t\t"<< temp -> obj.mo_no << "" ;
					cout << "\t\t"<< temp -> obj.gender << "" ;
					cout << "\t\t"<< temp -> obj.dob << "" ;
					cout << "\t"<< temp -> obj.age << "" ;
					cout << "\t\t\t"<< temp -> obj.bp << "" ;
					cout << "\t\t"<< temp -> obj.address << "" ;
					cout << "\t\t"<< temp -> obj.temperature << "" << endl ;
					temp = temp -> next;
					i++;
				}
				cout << endl;
			}
    	}     
	
	
	
	
	void search_data()  //function to search patients data.
	{
	    system("cls");
		int s;
		cout << "\t\t\t\t||*||*||*||*||     SEARCH DATA     ||*||*||*||*||" << endl;
		cout << "Press" << endl;
		cout << "1. Search by Name" << endl << "2. Search by Adhar Number" << endl << "3. Search by Mobile Number" << endl << "4. Search by Gender" <<  endl << "5. Search by Age" << endl << "6. Back" << endl;	
	    cout << "Enter your Choice: ";
		cin >> s;
		
		switch(s)
		{
			case 1: srch_name();
			break;
			case 2: srch_adhar();
			break;
			case 3: srch_mo();
			break;
			case 4: srch_gender();
			break;
			case 5: srch_age();
			break;
			default: 
			cout << "Error" << endl;
		}
		wait();
	}      
	
	
	
	
	void srch_name()  //function to search patients data by name.
	{
		system("cls");
		cout << "\t\t\t\t||*||*||*||*||     SEARCH DATA     ||*||*||*||*||" << endl;
		cout << endl;
		
		string namef;
		cout << "Enter the first name of Patient: " << endl;
		cin >> namef;
		node *temp;
			temp = head;
			if(head == NULL)
			{
				cout << "List is Empty!!!" << endl;
			}
			else
			{
		
			    int i = 1;
				while(temp != NULL)
				{
				
					if(namef == temp -> obj.fname)
					{

					cout << i <<".)"<<"  ";
					cout << temp -> obj.fname << " " << temp -> obj.lname << "  ";
					cout << temp -> obj.adhar_no << "  ";
					cout << temp -> obj.mo_no << "  " ;
					cout << temp -> obj.gender << "  " ;
					cout << temp -> obj.dob << "  " ;
					cout << temp -> obj.age << "  " ;
					cout << temp -> obj.bp << "  " ;
					cout << temp -> obj.address << "  " ;
					cout << temp -> obj.temperature << "  " << endl ;	
					i++;
					}		
					temp = temp -> next;
					
				}

				cout << endl;
			}
	    wait();
	}
	
	
	
	
	void srch_adhar()  //function to search patients data by aadhar.
	{
		system("cls");
		cout << "\t\t\t\t||*||*||*||*||     SEARCH DATA     ||*||*||*||*||" << endl;
		cout << endl;
		unsigned long long int adhar;;
		cout << "Enter the Adhar Number of Patient : ";
		cin >> adhar;
		node *temp;
			temp = head;
			if(head == NULL)
			{
				cout << "List is Empty!!!" << endl;
			}
			else
			{
				while(temp != NULL)
				{
					if(adhar == temp -> obj.adhar_no)
					{
					cout << " Name: " << temp -> obj.fname << " " << temp -> obj.lname << "  " << endl;
					cout << " Adhar Number: " << temp -> obj.adhar_no << "  " << endl;
					cout << " Mobile Number: " << temp -> obj.mo_no << "  " << endl;
					cout << " Gender: " << temp -> obj.gender << "  " << endl ;
					cout << " Date of Birth: " << temp -> obj.dob << "  " << endl;
					cout << " Age: " << temp -> obj.age << "  " << endl ;
					cout << " Blood Group: " << temp -> obj.bp << "  " << endl;
					cout << " Address: " << temp -> obj.address << "  " << endl;
					cout << " Temperature: " << temp -> obj.temperature << "  " << endl ;
					}		
					temp = temp -> next;
				}
				cout << endl;
			}
	    wait();
	}
	
	
	
	
	void srch_mo()  //function to search patients data by mobile no.
	{
		system("cls");
		cout << "\t\t\t\t||*||*||*||*||     SEARCH DATA     ||*||*||*||*||" << endl;
		cout << endl;
		unsigned long long int mo;
		cout << "Enter the Mobile Number of Patient : ";
		cin >> mo;
		node *temp;
			temp = head;
			if(head == NULL)
			{
				cout << "List is Empty!!!" << endl;
			}
			else
			{
				while(temp != NULL)
				{
					if(mo == temp -> obj.mo_no)
					{
					cout << " Name: " << temp -> obj.fname << " " << temp -> obj.lname << "  " << endl;
					cout << " Adhar Number: " << temp -> obj.adhar_no << "  " << endl;
					cout << " Mobile Number: " << temp -> obj.mo_no << "  " << endl;
					cout << " Gender: " << temp -> obj.gender << "  " << endl ;
					cout << " Date of Birth: " << temp -> obj.dob << "  " << endl;
					cout << " Age: " << temp -> obj.age << "  " << endl ;
					cout << " Blood Group: " << temp -> obj.bp << "  " << endl;
					cout << " Address: " << temp -> obj.address << "  " << endl;
					cout << " Temperature: " << temp -> obj.temperature << "  " << endl ;
					}		
					temp = temp -> next;
				}
				cout << endl;
			}
	    wait();
	}
	
	
	
	
	void srch_gender()  //function to search patients data by gender.
	{
		system("cls");
		cout << "\t\t\t\t||*||*||*||*||     SEARCH DATA     ||*||*||*||*||" << endl;
		cout << endl;
		char g;
		cout << "Enter the Gender of Patient : ";
		cin >> g;
		node *temp;
			temp = head;
			if(head == NULL)
			{
				cout << "List is Empty!!!" << endl;
			}
			else
			{
			    int i = 1;
				while(temp != NULL)
				{
				    
					if(g == temp -> obj.gender)
					{
					    cout << i <<".)"<<"  ";
					    cout << temp -> obj.fname << "  " << temp -> obj.lname << "  ";
					    cout << temp -> obj.adhar_no << "  ";
					    cout << temp -> obj.mo_no << "  " ;
					    cout << temp -> obj.gender << "  " ;
					    cout << temp -> obj.dob << "  " ;
					    cout << temp -> obj.age << "  " ;
					    cout << temp -> obj.bp << "  " ;
					    cout << temp -> obj.address << "  " ;
					    cout << temp -> obj.temperature << "  " << endl ;
					    i++;
					}		
					temp = temp -> next;
					
				}
				cout << endl;
			}
	    wait();
	}
	
	
	
	
	void srch_age()  //function to search patients data by age.
	{
		system("cls");
		cout << "\t\t\t\t||*||*||*||*||     SEARCH DATA     ||*||*||*||*||" << endl;
		cout << endl;
		int agee;
		cout << "Enter the Age of Patient : ";
		cin >> agee;
		node *temp;
			temp = head;
			if(head == NULL)
			{
				cout << "List is Empty:" << endl;
			}
			else
			{
			    int i = 1;
				while(temp != NULL)
				{
				    
					if(agee == temp -> obj.age)
					{
					    cout << i <<".)"<<"  ";
                		cout << temp -> obj.fname << "  " << temp -> obj.lname << "  ";
                		cout << temp -> obj.adhar_no << "  ";
                		cout << temp -> obj.mo_no << "  " ;
                		cout << temp -> obj.gender << "  " ;
                		cout << temp -> obj.dob << "  " ;
                		cout << temp -> obj.age << "  " ;
                		cout << temp -> obj.bp << "  " ;
                		cout << temp -> obj.address << "  " ;
                		cout << temp -> obj.temperature << "  " << endl ;
                		i++;
					}		
					temp = temp -> next;
					
				}
				cout << endl;
			}
	    wait();
	}




      
};




int main()
{
	co_vaccine a;                 //object of class
	int choice,i;
	cout << "\t\t\t\t\t\t\t\t\t|*|*|*|*| VACCINE MANAGEMENT SYSTEM |*|*|*|*|" << endl;
	a.addvaccine();            //to add vaccine at start


	while(1)
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\t\t|*|*|*|*| VACCINE MANAGEMENT SYSTEM |*|*|*|*|" << endl;
		cout << endl;
		cout << "1. Add Data" << endl << "2. View Data" << endl << "3. Search" << endl << "4. Exit" << endl;	
	    cout << "Enter your Choice : ";
		cin >> choice;
		
		switch(choice)
		{
			case 1: a.add_data();
			break;
			case 2: a.view_data();
			break;
			case 3: a.search_data();
			break;
			default:
				exit(0);
		}
    }
	return 0;
}
