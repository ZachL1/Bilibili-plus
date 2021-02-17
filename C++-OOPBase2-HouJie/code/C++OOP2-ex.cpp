// author : Hou Jie
// date : 2015/11/27
// compiler : DevC++ 5.11 (MinGW with GNU 4.9.2)
// course : C++OOP2

using namespace std;

//-------------------------------------------------------------
#include <string>
#include <iostream>
#include <memory> //shared_ptr

namespace jj01
{
class Base1 {  };
class Derived1: public Base1 {  };	
class Base2 {  };
class Derived2: public Base2 {  };

	
template <class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  T1 first;
  T2 second;
  pair() : first(T1()), second(T2()) {}
  pair(const T1& a, const T2& b) : first(a), second(b) {}

  template <class U1, class U2>
  pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}
};

void test_member_template()
{
	cout << "test_member_template()" << endl;
    pair<Derived1, Derived2> p; 
    pair<Base1, Base2> p2(pair<Derived1, Derived2>());     
    pair<Base1, Base2> p3(p);   
		//Derived1 will be assigned to Base1; Derived2 will be assigned to Base2.
		//OO allow such assignments since of "is-a" relationship between them.  
		
//!	pair<Derived1, Derived2> p4(p3);
		//error messages as below appear at the ctor statements of pair member template
		// [Error] no matching function for call to 'Derived1::Derived1(const Base1&)'
		// [Error] no matching function for call to 'Derived2::Derived2(const Base2&)'		
		
    Base1* ptr = new Derived1; 	//up-cast 
	shared_ptr<Base1> sptr(new Derived1); 	//simulate up-cast
        //Note: make sure your environment support C++2.0 at first.
}
} //namespace
//-------------------------------------------------------------
#include <string>
#include <iostream>
#include <list>
namespace jj02
{
template<typename T,  
         template <typename T>  
             class Container 
	    > 
class XCls 
{  
private:
  	Container<T> c; 
public:
	XCls() 
	{ 							
        for(long i=0; i< 100; ++i) 		
        	c.insert(c.end(), T());			
	}
};

template<typename T>
using Lst = list<T, allocator<T>>;   //Note: make sure your environment support C++2.0

void test_template_template_parameters_1()
{
	cout << "test_template_template_parameters_1()" << endl;
	
//!	XCls<string, list> mylist;
			//[Error] expected a template of type 'template<class T> class Container', got 'template<class _Tp, class _Alloc> class std::list'
	XCls<string, Lst> mylist;		//Note: make sure your environment support C++2.0
}
} //namespace
//-------------------------------------------------------------
#include <string>
#include <iostream>
#include <memory> //smart pointers
namespace jj03
{
template<typename T,  
         template <typename T>  
             class SmartPtr 
	    > 
class XCls 
{  
private:
  	SmartPtr<T> sp; 
public:
	XCls() : sp(new T)  { }
};

void test_template_template_parameters_2()
{
	cout << "test_template_template_parameters_2()" << endl;
	
	XCls<string, shared_ptr> p1;   	//Note: make sure your environment support C++2.0
	XCls<double, auto_ptr> p4;	
//!	XCls<double, unique_ptr> p2;  	//unique_ptr has two template parameters 
//!	XCls<int, weak_ptr> p3;			//[Error] no matching function for call to 'std::weak_ptr<int>::weak_ptr(int*)'
}
} //namespace
//-------------------------------------------------------------
#include <iostream>
namespace jj04
{	
	
void test_object_model()
{	
	cout << "test_object_model()" << endl;

}
} //namespace 
//-------------------------------------------------------------
#include <iostream>
namespace jj05
{	
class Fraction
{
public:
	explicit Fraction(int num, int den=1) 
	  : m_numerator(num), m_denominator(den)
	{ cout << m_numerator << ' ' << m_denominator << endl; }
	
 	operator double() const { 
      return (double)m_numerator / m_denominator; 
 	}
 	
 	Fraction operator+(const Fraction& f) {  
	   cout << "operator+(): " << f.m_numerator << ' ' << f.m_denominator <<  endl;  
	   //... plus
	   return f; 
	} 
/*	
	Fraction(double d) 
	  : m_numerator(d * 1000), m_denominator(1000) 
	{ cout << m_numerator << ' ' << m_denominator << endl; }
*/

private:   
   int m_numerator;    //
   int m_denominator;  //
};
	
void test_conversion_functions()
{	
	cout << "test_conversion_functions()" << endl;
	
	Fraction f(3,5);
	
	double d = 4 + f;		//4.6
	cout << d << endl;
	
	//! Fraction d2 = f + 4;	 //ambiguous		
}
} //namespace 
//-------------------------------------------------------------
#include <iostream>
namespace jj06
{	
void test_reference()
{	
	cout << "test_reference()" << endl;

    {
	int x=0;
	int* p = &x;
	int& r = x;   	//r is a reference to x. now r==x==0
	int x2=5;
	r = x2;      	//r cannot re-reference to another. now r==x==5
	int& r2 = r; 	//now r2==5 (r2 is a reference to r, i.e. a reference to x)	
	}
	
	
	{
    typedef struct Stag { int a,b,c,d; } S;

	double x=0;
	double* p = &x; 	//p is a pointer to x. p's value is same as x's address.
	double& r = x; 		//r is a reference to x, now r==x==0
	
	cout << sizeof(x) << endl; 	//8
	cout << sizeof(p) << endl; 	//4
	cout << sizeof(r) << endl; 	//8
	cout << p << endl; 			//0065FDFC
	cout << *p << endl; 		//0
	cout << x << endl; 			//0
	cout << r << endl; 			//0
	cout << &x << endl; 		//0065FDFC
	cout << &r << endl; 		//0065FDFC
	
	S s;
	S& rs = s;
	cout << sizeof(s) << endl; 	//16
	cout << sizeof(rs) << endl; //16
	cout << &s << endl; 		//0065FDE8
	cout << &rs << endl; 		//0065FDE8	
 	}
}
} //namespace 
//-------------------------------------------------------------
int main(int argc, char** argv) 
{
	std::cout << __cplusplus << endl;	//199711 or 201103
	
	jj01::test_member_template();	
	jj02::test_template_template_parameters_1();	
	jj03::test_template_template_parameters_2();
	jj04::test_object_model();		
	jj05::test_conversion_functions();
	jj06::test_reference();	
}
