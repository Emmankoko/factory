#include <iostream>

enum vehicleType { 
    twoWheeler,
    threeWheeler,
    fourWheeler
};

// abstarct class from which i can print all other vehicle types
//vehicle is our product
class Vehicle
{
public:
    virtual void printVehicleInfo() = 0;
    virtual ~Vehicle() {};
};

class twoWheelerVehicle : public Vehicle
{
    void printVehicleInfo() override
    {
        std::cout << "I am a two wheeler" << std:: endl;
    }
};

class threeWheelerVehicle : public Vehicle
{
    void printVehicleInfo() override
    {
        std::cout << "I am a three wheeler" << std:: endl;
    }
};

class fourWheelerVehicle : public Vehicle
{
    void printVehicleInfo() override
    {
        std::cout<< "I am a four wheeler" << std:: endl;
    }
};

// we are about to create our vehicle product
// and bear in mind, we have to create them in our factory

class vehicleFactory
{
public:
// we create our factory method to return our product .. i.e vehicle product
    Vehicle* createVehicle(vehicleType type)
    {
        if (type == twoWheeler)
        {
            return new twoWheelerVehicle();
        }
        else if (type == threeWheeler)
        {
            return new threeWheelerVehicle();
        }
        else if (type == fourWheeler)
        {
            return new fourWheelerVehicle();
        }
        else
            return nullptr;
    }
};

//the client class
// this class will ask the factory to build the vehicle.
class client
{
    Vehicle* pvehicle;
public:
    client()
    {
        pvehicle = nullptr;
    }
    // client's request to build a vehicle  
    void buildVehicle(vehicleType type)
    {
        vehicleFactory* vf = new vehicleFactory();
        pvehicle = vf->createVehicle(type);
        delete vf;
    }
    ~client()
    {
        if (pvehicle)
        {
            delete pvehicle;
            pvehicle = NULL;
        }
    }
    Vehicle* getVehicle()
    {
        return pvehicle;
    }
};

int main()
{
    client* pclient = new client();
    pclient->buildVehicle(twoWheeler);
    pclient->getVehicle()->printVehicleInfo();
    delete pclient;
}