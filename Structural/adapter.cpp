#include <iostream>
using namespace std;

class FarenheitSensor
{
private:
    float t;
public:
    FarenheitSensor(float temp) : t(temp) {};
    float getTemp() { return t; }
};

class Sensor
{
public:
    virtual ~Sensor() = default;
    virtual float getTemp() = 0;
};

class Adapter : public Sensor
{
private:
    FarenheitSensor* sensor;
public:
    Adapter(FarenheitSensor* fs) : sensor(fs){}
    ~Adapter() { delete sensor; }
    float getTemp() override
    {
        return (sensor->getTemp()-32.0)*5.0/9.0;
    }
};

int main(int argc, char const *argv[])
{
    FarenheitSensor* far = new FarenheitSensor(37);
    Sensor* adapt = new Adapter(new FarenheitSensor(37));
    
    cout << "Farenheit: " << far->getTemp() << endl;
    cout << "Celsius: " << adapt->getTemp() << endl;

    delete far; delete adapt;
    return 0;
}