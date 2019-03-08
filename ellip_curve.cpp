	// Name - Aashay B. Gondalia
	// Register No - 15BCE1284

	#include<iostream>
	#include<math.h>
	#include<cstdlib>
	#include<vector>
	using namespace std;

	int r,s;

	int multiplication(int x1, int y1, int x2, int y2, int a_)
	{
		int lambda=0,x3,y3;
	//	cout<<"x1 = "<<x1<<"y1 = "<<x1<<"1 = "<<x1<<"x1 = "<<x1
		if(x1 == x2)
		{
			lambda = ((3*(x1^2)) + a_)/(2*y1);
		}
		else
		{
			lambda = (y2 - y1)/(x2 - x1);
		}
		cout<<"\nlambda ="<<lambda<<endl;
		x3 = ((lambda)^2) - x1 - x2;
		y3 = lambda*(x1 - x3) - y1;
		r = x3;
		s = y3;
	//	cout<<"x3 = "<<x3<<"\t y3 =  "<<y3 << "r,s = "<<r<<" ,"<<s;	
		return 0;
	}

	class Receiver
	{
		public:
			int alpha_x,alpha_y;
			int beta_x, beta_y;
			int secret,c1_x,c1_y,c2_x,c2_y;
			int ls_x,ls_y;
	
		void secret_s()
		{
			secret = rand()%100 +1;
			cout<<"\nSecret Key is "<<secret<<endl;
		}
	
		void compute_beta()
		{
			beta_x = alpha_x * secret;
			beta_y = alpha_y * secret;	
			cout<<"Beta is ("<<beta_x<<" , "<<beta_y<<" ) "<<endl; 
		}
		
		void Decrypt(int c1_x,int c1_y,int c2_x,int c2_y)
		{
				ls_x = c2_x - (secret)*(c1_x);
				ls_y = c2_y - (secret)*(c2_y);
				cout<<"The message is"<<ls_x<<endl;
		}
	};

	class Sender
	{
		public:
			int k;
			int cipher_one_x,cipher_one_y, cipher_two_x,cipher_two_y;
			int message;
	
		void randomize_k()
		{
			k = rand()%150 + 1;
			cout<<"\nK value = "<<k<<endl;
		}
		void compute_cipher(int a_x,int a_y,int b_x,int b_y)
		{
			cipher_one_x = k*a_x;	
			cipher_one_y = k*a_y;	
			cipher_two_x = message + k*b_x;
			cipher_two_y = message + k*b_y;
			cout<<"Original Message is" <<message<<endl;
			cout<<"\nCipher 1 = ("<<cipher_one_x<<" , "<<cipher_one_y<<" )\n";		
			cout<<"\nCipher 2 = ("<<cipher_two_x<<" , "<<cipher_two_y<<" )\n";
		}
	};


	int main()
	{
		int n,p;
		srand (time(NULL));
		// Here a = 1 and b =1
		cout<<"Elliptic Cryptography by \nName - Aashay B. Gondalia\nRegister Number - 15BCE1284\n\n";
		cout<<"Elliptic Curve General Form \t\t ---> y^2 mod p = (x^3  + A*x + B) mod p \n";
		cout<<"Enter the value of P : \n";
		cin>>p;
		n = p;
		int LHS[2][n],RHS[2][n],a,b,i,j;
	
		cout<<"\nEnter the Value of A : \n";
		cin>>a;
		cout<<"\nEnter the Value of B : \n";
		cin>>b;
		cout<<"\nCurrent Elliptic Curve \t\t ---> y^2 mod "<<p<<" = (x^3  + "<<a<<"*x + "<<b<<") mod p\n\n\n";

		vector <int> arr_x;
		vector <int> arr_y;
	//	vector <int> :: iterator z;

	// Equating LHS and RHS as per arbitrary index to generate range of values.
	
		for(int i = 0; i <	 n; i++)
		{
			LHS[0][i] = i;
			RHS[0][i] = i;
			LHS[1][i] = ((i*i*i) + a*i + b) % p;
			RHS[1][i] = (i*i) % p;	
			cout<<"For  i =  "<< LHS[0][i]<<"\t\tValue of LHS = \t"<<LHS[1][i] <<"\t Value of RHS ="<< RHS[1][i]<<endl ;	
		}
		

	// Generating Elliptic Curve Group	------------------------------------
	int order = 0;
		for(i = 0; i < n; i ++)
		{

			for(j = 0; j < n; j++)
			{
				if(LHS[1][i] == RHS[1][j])
				{
						order++;
						arr_x.push_back(LHS[0][i]);
						arr_y.push_back(RHS[0][j]);		
				}
		//	cout<<"( "<<arr_x[i]<<" , "<<arr_y[i]<<" )"<<endl;
			}
		}
		
		cout<<endl<<"Generated Points are represented as (x,y)"<<endl;

		for(i =0; i < order; i++)
		{
			cout<<i+1<<"\t( "<<arr_x[i]<<" , "<<arr_y[i]<<" )"<<endl;
		}

	// Elliptic Curve Key Generation
		vector <int> base_arr_x;
		vector <int> base_arr_y;
		int u,v;
		int msg;
		/*for(i = 1; i < order; i++)
		{
			j =i+1;
			cout <<j<< "P";	
		}*/
		int Base_pt_x, Base_pt_y;
		Base_pt_x = arr_x[0];
		Base_pt_y = arr_y[0];
	
		Receiver Blake;
		Sender Aashay;		
	
		cout<<"Receiver and Sender Class crearted";
		Blake.alpha_x = Base_pt_x;
		Blake.alpha_y =Base_pt_y;
		cout<<"\nEnter the Message \n\n";
		cin>>msg;
		Blake.secret_s();
		Blake.compute_beta();
		int bt_x,bt_y,c_one_x,c_one_y,c_two_x,c_two_y;
		cout<<"\n\n Randomly generated K value is";
		Aashay.message = msg;
		Aashay.randomize_k();
		cout<<"\nEnter beta_x value:\n";	
		cin>>bt_x;
		cout<<"\nEnter beta_y value:\n";
		cin>>bt_y;
		Aashay.compute_cipher(Base_pt_x,Base_pt_y,bt_x,bt_y);	
		cout<<"Enter Cipher One x and y co-ordinates line by line\n";
		cin>>c_one_x>>c_one_y;
		cout<<"Enter Cipher Two x and Y co- ordinates line by line\n";
		cin>>c_two_x>>c_two_y;
		Blake.Decrypt(c_one_x,c_one_y,c_two_x,c_two_y);
	}
