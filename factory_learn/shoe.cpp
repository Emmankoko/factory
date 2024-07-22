#include <string>
#include <iostream>
/**
 * this is a code written by me to test my knowledge of factory design pattern
 * this code creates shoes from a client and not from shoe itself
 * the shoe, the shoe manfuacturer, and the requester
*/


/**
 * A shoe as our product has the folowing
 * show year of manufactur
 * color
 * size
*/

enum shoeType
{
    church,
    school,
    party
};


class Shoe
{
public:
    size_t size;
    std::string color;
    int year;
    void setinfo(shoeType type)
    {
        if (type == church)
        {
            size = 34;
            year = 1934;
            color =  "brown";
        }
        else if (type == school)
        {
            size = 37;
            year = 1937;
            color = "white";
        }
        else
        {
            size = 40;
            year = 1940;
            color = "brown";
        }
    }
    virtual void printinfo() = 0;
    ~Shoe() {}
};

// two shoes
class shoeChurch : public Shoe
{
    void printinfo() override
    {
        //setinfo(type);
        std::cout << "shoe size is " << size << std::endl
                  << "shoe color is " << color << std::endl
                  << "shoe year is " << year;
    }
};

class shoeParty : public Shoe
{
    void printinfo() override
    {
        //setinfo(type);
        std::cout << "shoe size is " << size << std::endl
                  << "shoe color is " << color << std::endl
                  << "shoe year is " << year;
    }
};

class shoeSchool : public Shoe
{
    void printinfo() override
    {
        //setinfo(type);
        std::cout << "shoe size is " << size << std::endl
                  << "shoe color is " << color << std::endl
                  << "shoe year is " << year;
    }
};

/**
 * we are now about to set our factory
 * which here, it is our show maker
*/

class shoeMaker
{
public:
    Shoe* makeShoeType(shoeType shoe)
    {
        if (shoe == church)
        {
            return new shoeChurch();
        }
        else if (shoe == school)
        {
            return new shoeSchool();
        }
        else
        {
            return new shoeParty();
        }
    }
};

/**
 * logically, a customer has no shoe
 * after he requests before he can get
*/
class customer
{
public:
    // the customer instructs the manufacturer to work
    customer(shoeType type)
    {
        shoeMaker* shoetype = new shoeMaker();
        shoe = shoetype->makeShoeType(type);
        shoe->setinfo(type);
        delete shoetype;
    }
    // request for shoe.. if he has not yet, he gets null
    Shoe* getshoe()
    {
        return shoe;
    }
private:
    // the customer's shoe.. either null or a shoe
    Shoe* shoe = nullptr;
};

int main()
{
    customer* shoe =  new customer(church);
    shoe->getshoe()->printinfo();
}
