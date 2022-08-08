#include<bits/stdc++.h>
using namespace std;
/*
* Vehicle is a thing used for transporting people or goods, especially on land
* class vehicle includes basic properties present in every vehicle
*/
class Vehicle
{
	public:
		string gear_type; 
		string reg_no;
		int ignition =0, fuel_capacity, seat_capacity, no_of_tyres;
		
		/*
			* steer wheel and acceleration of a vehicle(defferent for different types of vehicles)
			* So they are used as abstract methods to define in it in the derieved class
		*/
		virtual void Steer_type()=0;
		virtual void Acceleration() = 0;
		
		//headlights are a common property in vehicles
		void headlight_mode(int i)
		{
			if(i==0){  cout<<"headlight off";  }
			if(i==1){  cout<<"headlight lower beam";  }
			if(i==2){  cout<<"headlight upper beam";  }
		}
		/*
			* start and stop are the basic properties of a vehicle 
			* these properties are common to all vehicles.
			* hence they are declared in vehicle class itself
		*/
		void start()
		{
			ignition = 1;
		}
		void stop()
		{
			ignition = 0;
		}
};
/*
	* Bike is a type of a vehicle and inherits properties of the same
	* hence Bike is used as a derieved class inheriting from the base class(class Vehicle) 
	* here we are using "Inheritance property"
*/
class Bike: public Vehicle
{
	private:
	int no_of_cylinders;
	string color;
	public:
		int seat_capacity = 2;
		
		// "Consrtructor", to initialize the class Bike
		Bike()
		{
			cout<<"choose capacity between  20-40 litres - "; cin>>fuel_capacity;
			cout<<"seat capacity - "<<seat_capacity<<endl;
			cout<<"no of tyres - "<<no_of_tyres<<endl;
			cout<<"choose gear type A/M - "<<gear_type; cin>>gear_type;
		}
		
		// Acceleration and Steer type defined in the derieved class
		// Here we have used OOPs property of "Abstract method"
		void Acceleration()
		{  }
		void Steer_type()
		{
			cout<<"Handle";
		}
		
		// setting up values of private varieable
		void get_color(){cout<<"bike color - ";cin>>color;
		}
		void get_registration()
		{
		}
		
		
};

/*
	* car is a type of a vehicle and inherits properties of the same
	* here all public members and methods of will be treated as public for derieved class
*/
class Car: public Vehicle
{
	
	private:
		int no_of_cylinders;
		string color;
	public:
		
		int seat_capacity = 4;
		
		//Constructor used
		Car()
		{
			// the members- fuel_capacity,no_of_tyres,gear type are inherited from class vehicle
			cout<<"choose capacity between 45-70 litres- ";cin>>fuel_capacity;
			cout<<"seat capacity - "<<seat_capacity;
			cout<<"no of tyres - "<<"4"<<endl;
			cout<<"choose gear type A/M - ";cin>>gear_type;
		}
		
		// setting up values of private varieable	
		void get_color(){cout<<"Car color - ";cin>>color;
		}
		
		void get_registration()
		{
			cout<<"enter Reg_no - ";cin>>reg_no;
		}
		
		//defined abstract methods
		void Steer_type(){
			cout<<"hydraulic steer";
		};
		void Acceleration(){
	}
};

/*
	* Bus is a type of a vehicle and inherits properties of the same
	* hence Bus is used as a derieved class inheriting from the base class(class Vehicle)
*/
class Bus: public Vehicle
{
	// private members represent data to be hidden from the end user
	private:
		int no_of_cylinders = 8;
		string color;
		
	public:
		
		int seat_capacity = 50;
		
		//Constructor
		Bus()
		{
			// the members- fuel_capacity,no_of_tyres,gear type are inherited from class vehicle
			cout<<"choose capacity between 200-600 litres - ";cin>>fuel_capacity;
			cout<<"seat capacity - "<<seat_capacity;
			cout<<"no of tyres - "<<"6"<<endl;
			cout<<"choose gear type A/M - "<<gear_type;
		}	
		void get_color(){cout<<"Bus color - ";cin>>color;
		}
		void get_registration()
		{
			cout<<"enter Reg_no - ";cin>>reg_no;
		}
		void Steer_type(){
			cout<<"Power steer";
		};
		void Acceleration(){
	}
};

/*
	* Truck is a type of a vehicle and inherits properties of the same
	* hence Truck is used as a derieved class inheriting from the base class(class Vehicle)
*/
class Truck: public Vehicle
{
	
	private:
		int no_of_cylinders;
		string color1,color2;
		string trailer_type;
	public:
		
		int seat_capacity = 2;
		Truck()
		{
			cout<<"choose capacity between 200-1500 litres - ";cin>>fuel_capacity;
			cout<<"seat capacity - "<<seat_capacity;
			cout<<"choose no of tyres - ";cin>>no_of_tyres;
			cout<<"choose gear type A/M - "<<gear_type;
		}	
			// setting up values of private varieable
		void get_color(){cout<<"Truck color - ";cin>>color1;cout<<"trailer color";cin>>color2;
		}
		
		void get_registration()
		{
			cout<<"enter Reg_no - ";cin>>reg_no;
		}
		
		/*
			* Two methods with same name are declared
			* on represents volume of tyre and the other return volume of the trailer
			* however compiler will automatically understand the use of volume method based on input parameters
			* This is a type of "Compile Time Polymorphism" known an "Function overloading" 
		*/
		int Volume(int radius,int width){
			
			//volume of tyres
			return 3.14*radius*radius*width;
		} 
		
		int Volume(int length,int breadth,int height){
			//Volume of trailer
			return length*breadth*height;
		}
		void Steer_type(){
			cout<<"Power steer";
		};
		void Acceleration(){
	}
};

/*
	* Factory is a place of production of different things
	* in our program we are using a Factory class for production of Vehicles
	* this will be the only class to be called in main function
	* it will take care of producing vehicles without the main function accessing the class of the vehicles
*/
class Factory
{
	public:
		// Constructor for factory class
	Factory()
	{
		cout<<"setting up for Production"<<endl;
		for(int i=0;i<INT_MAX/4;i++)
		{
			
		}
	}
	/*
		*this method will be used for creating the vehicle classes
	*/
	void Create(string s)
	{
		if(s=="Bike")
		{
			Bike B;
			B.get_color();
			B.get_registration();
		}
		if(s=="Car")
		{
			Car C;
			C.get_color();
			C.get_registration();
		}
		if(s=="Bus")
		{
			Bus Bu;
			Bu.get_color();
			Bu.get_registration();
		}
		if(s=="Truck")
		{
			Truck T;
			T.get_color();
			T.get_registration();
		}
	}
};

/*
	* accessing class, creating objects, accessing methods and members are all done in main function
	* it is the first function to be accessed while compiling
*/
int main()
{
	//here we only need to create only one class ie Factory
	// it eill taje  are of the rest.
	Factory F ;
	F.Create("Truck"); 
	cout<<endl;
	F.Create("Bike"); 
}

