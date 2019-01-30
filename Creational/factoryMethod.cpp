#include <iostream>
using namespace std;

class Product
{
public:
    virtual void doSomething() = 0;
    virtual ~Product() = default;
};

class ConcreteProductA : public  Product
{
public:
    void doSomething() override
    {
        cout << "doSomething A\n";
    }
};

class ConcreteProductB : public  Product
{
public:
    void doSomething() override
    {
        cout << "doSomething B\n";
    }
};

class Factory
{
public:
    virtual Product* setProduct() = 0;
    virtual ~Factory() = default;
};

class ConcreteFactoryA : public Factory
{
public:
    Product* setProduct() override
    {
        return new ConcreteProductA;
    }
};

class ConcreteFactoryB : public Factory
{
public:
    Product* setProduct() override
    {
        return new ConcreteProductB;
    }
};

int main()
{
    ConcreteFactoryA concreteA;
    ConcreteFactoryB concreteB;

    Factory* doSomethingTypes[] = {&concreteA, &concreteB};

    for(auto&& product : doSomethingTypes)
    {
        Product* p = product->setProduct();
        p->doSomething();
        delete p;
    }   
    return 0;
}