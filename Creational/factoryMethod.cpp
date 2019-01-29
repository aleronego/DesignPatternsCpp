#include <iostream>
using namespace std;

class Transport
{
public:
    virtual void delivery() = 0;
    virtual ~Transport() = default;
};

class Truck : public  Transport
{
public:
    void delivery() override
    {
        cout << "Delivery by road\n";
    }
};

class Ship : public  Transport
{
public:
    void delivery() override
    {
        cout << "Delivery by sea\n";
    }
};

class Factory
{
public:
    virtual Transport* setTransport() = 0;
    virtual ~Factory() = default;
};

class RoadFactory : public Factory
{
public:
    Transport* setTransport() override
    {
        return new Truck;
    }
};

class SeaFactory : public Factory
{
public:
    Transport* setTransport() override
    {
        return new Ship;
    }
};

int main()
{
    RoadFactory road;
    SeaFactory sea;

    Factory* deliveryTypes[] = {&road, &sea};

    for(auto&& transport : deliveryTypes)
    {
        Transport* t = transport->setTransport();
        t->delivery();
        delete t;
    }   
    return 0;
}