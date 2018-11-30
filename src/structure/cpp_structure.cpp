
#include <iostream>      //cin, cout
#include <string>			//string class
#include <iomanip>		 //format float number fixed, setw, setprecision, serfill

using namespace std;

const float PI = 3.14;
const int WEEK_DAYS_COUNT = 7;
const string WEEK[WEEK_DAYS_COUNT] = {
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};
const int YEAR_MONTHS_COUNT = 12;
const string YEAR[YEAR_MONTHS_COUNT] = {
	"January", "February", "March",
	"April", "May", "June",
	"July", "August", "September",
	"October", "November", "December"
};
int n_variable = 12; //global n
int main_cpp(int argc, char const *argv[])
{

	system("@cls || clear");

	//--------------------------- Data Type---------------------------------//
	int n_variable = 3;  //local n
	cout<<"global n is: "<<::n_variable<<"\n";  //global n_variable
	cout<<"local n is: "<<n_variable<<endl; //local n_variable
	//-----------------------------------------------------------------------//


	//--------------------------- Data Type---------------------------------//
	char c1;
	char16_t c2;
	char32_t c3;
	wchar_t c4;

	short i1 = -12;  //signed short int
	int i2 = 14;	//signed int
	long i3 = 34567;     //signed long int
	long long i4 = 8887;   //signed long long int

	unsigned short b1; //unsigned short int
	unsigned b2; //unsigned int
	unsigned long b3; //unsigned long int
	unsigned long long b4; //unsigned long long int

	float f;
	double d;
	long double ld;

	bool B;
	decltype(nullptr) np;

	int foo = 100;
	//auto bar = foo;  //warning???
	decltype(foo) sds = 210;

	cout<<"size of char is: "<<sizeof(char)<<endl;
	cout<<"size of short is: "<<sizeof(short)<<endl;
	cout<<"size of int is: "<<sizeof(int)<<endl;
	cout<<"size of long is: "<<sizeof(long)<<endl;
	cout<<"size of long long is: "<<sizeof(long long)<<endl;
	cout<<"size of float is: "<<sizeof(float)<<endl;
	cout<<"size of dlouble is: "<<sizeof(double)<<endl;
	cout<<"size of long double is: "<<sizeof(long double)<<endl;

	char cha = 't';
	cout <<int(cha)<<endl;
	//-----------------------------------------------------------------------//

	//-----------------------------  cin, cout ------------------------------//
	double myDouble = 4456754562.0;
	cout<<fixed<<setw(11)<<setprecision(6)<<setfill('0')<<myDouble<<"\n";
	//-----------------------------------------------------------------------//


	//-----------------------------  string ----------------------------------//
	string str;
	str = "this is my string";
	cout<<str.size()<<" "<<str<<endl;
	str.pop_back();
	cout<<str.size()<<" "<<str<<endl;
	str.pop_back();
	cout<<str.size()<<" "<<str<<endl;
	str.clear();

	if(str.empty())
	{
		cout<<"str is empty"<<endl;
	}
	cout<<str.size()<<" "<<str<<endl;

	for (int i = 0; i < WEEK_DAYS_COUNT; ++i)
	{
		cout<<WEEK[i]<<"\n";
	}
	string line(134, '.');
	cout<<line<<endl;

	/* ---The string Class Input Methods
	The string class has two input methods: stream extraction operator (>>) and getline()*/

	//cin
	string strName;
	cin>>strName;   // only get string befor WHITESPACE
	cin.ignore();
	cout<<strName<<"\n";

	//string::getline()
	string strFullName;
	getline(cin, strFullName);
	cout<<strFullName<<endl;
	//-----------------------------------------------------------------------//

	//-------------------------  std::stoi  ----------------------------------//
	std::string strInt("123");
  	int n1 = std::stoi(strInt);
  	int n2 = 123;
  	std::string strInt2 = std::to_string(n2);
  	char ch = 'B';
  	std::string s5 = std::string(1, ch);
  	//-----------------------------------------------------------------------//

	return 0;
}
