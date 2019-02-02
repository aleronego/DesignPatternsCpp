#include <iostream>
using namespace std;


class FarenheitSensor
{
private:
    float t = 37.0;
public:
    //FarenheitSensor(float temp) : t(temp) {};
    //void setTemp(float temp){ t = temp; }
    float getTemp() { return t; }
};

class Sensor
{
public:
    virtual ~Sensor() = default;
    virtual float getTemp() = 0;
    virtual float getFarenheitTemp() = 0;
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
    float getFarenheitTemp() override
    {
        return sensor->getTemp();
    }
};

int main(int argc, char const *argv[])
{
    //FarenheitSensor* far = new FarenheitSensor;
    Sensor* adapt = new Adapter(new FarenheitSensor);
    
    //Sensor* adapt = new Adapter(FarenheitSensor(37));
    cout << "Farenheit: " << adapt->getFarenheitTemp() << endl;
    cout << "Celsius: " << adapt->getTemp() << endl;
    return 0;
}