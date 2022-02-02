#include <iostream>
using namespace std;

class Visitor;


class Element
{
public:
    virtual void Func1() = 0;
    
    virtual void Func2(int data)=0;
    virtual void Func3(int data)=0;
    //...
    
    virtual ~Element(){}
};

class ElementA : public Element
{
public:
    void Func1() override{
        //...
    }
    
    void Func2(int data) override{
        //...
    }
    
};

class ElementB : public Element
{
public:
    void Func1() override{
        //***
    }
    
    void Func2(int data) override {
        //***
    }
    
};






