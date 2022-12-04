    #include<iostream>
    #include<string>
    #include<math.h>
    #include<conio.h>
    

    using namespace std;

    class bank{
        string name;
        int p,r,t,ci;
        char type;
        int acno;
        string actype;
        int balance;

        public:
            void initialize(string n,int ano,string atype,int bal);
            void deposit(int val);
            void withdrawal(int val);
            void display();
            void compound();
            void checkbk();
    };

    void bank:: initialize(string a,int b,string c,int d){
        name=a;
        acno=b;
        actype=c;
        balance=d;
    }

    void bank::deposit(int val){
        balance+=val;
        cout<<"\nThe new balance is "<<balance<<endl;
    }

    void bank::withdrawal(int val){
        if(val>balance){
            cout<<"\nSorry.. There is no sufficient balance..";
        }
        else{
            balance-=val;
            cout<<"\nThe new balance is "<<balance<<endl;
        }
    }

    void bank:: display(){
        cout<<"\nThe details of the Account is..";
        cout<<"\nName : "<<name<<endl;
        cout<<"\nAccount Number : "<<acno<<endl;
        cout<<"\nAccount Type  C|S: "<<actype<<endl;
        cout<<"\nBalance : "<<balance<<endl;
    }
    void bank :: compound()
		 {
		    system("cls");
		     
		    if(type=='s' || type=='S')
		    {
		     cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t   Enter Principle Amount : ";
			 cin>>p; 
			 cout<<"\n\n\t\t\t\t\t\t\t   Enter the rate of interest : ";
             cin>>r;
             cout<<"\n\n\t\t\t\t\t\t\t   Enter the time : ";
             cin>>t;  
             ci=p*(pow((1+r/100),t));
             cout<<"\n\n\n\t\t\t\t\t\t\t\t\t The Compound Interest is : "<<ci<<endl;
             }
             else
                cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t Compound Interest Not Available in Current Account";
           getch();
		  }  
		  
      void bank::checkbk()
	   {
	     if(type=='c' || type=='C')
	     {
	        system("cls");
	         
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t Check Book Facility Available";
	         getch();
		  }
		  else
		  {
		     system("cls");
		      
		      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t Check Book Facility Not Available";
		    getch();
		  }
		 } 
		 

    int main()
    {
        int i,n;
        int ch,x,y;
        string a,b;
        cout<<"Enter the number of customers..";
        cin>>n;
        bank customer[n];
        cout<<"\nEnter the customer details one by one ";
        for(i=0;i<n;i++){
            cout<<"\nCustomer : "<<i+1<<endl;
            cout<<"\nEnter Name...";
            cin>>a;
            cout<<"\nEnter Account type...";
            cin>>b;
            cout<<"\nYour Account Number is.."<<i+1<<endl;
            customer[i].initialize(a,i+1,b,0);
        }

        cout<<"\nWelcome to Bank Information Center :D ";
        cout<<"\nChoice : \n1) Know your Account Inf. \n2) Deposit an amount. \n3) Withdraw an amount. \n4) Exit :P 5 enquiry for checkbook\n 6: compound\n";
        while(1){
            cout<<"\nEnter your choice..";
            cin>>ch;
            if(ch==1){
                cout<<"\nEnter your Account Number..";
                cin>>x;
                customer[x-1].display();
            }
            else if(ch==2){
                cout<<"\nEnter the Account Number and the Amount to be deposited..";
                cin>>x>>y;
                customer[x-1].deposit(y);
            }
            else if(ch==3){
                cout<<"\nEnter the Account Number and the Amount to be withdrawn..";
                cin>>x>>y;
                customer[x-1].withdrawal(y);
            }
            else if(ch==5)
            {
            	customer[x-1].checkbk();
            	
			}
			else if(ch==6)
			{
				customer[x-1].compound();
			}
            else{
                break;
            }
        }
        return 0;
    }
