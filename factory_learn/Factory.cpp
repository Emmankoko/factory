#include <iostream>
#include <string>
/**
 * this declares the operations all products must implement
 * the main interface
*/

class Product
{
public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};

/**
 * this provides various implementation of the product interface
*/

class ConcreteProduct1 : public Product
{
public:
    std::string Operation() const override
    {
        return " what concreteproduct1 does";
    }
};

class ConcreteProduct2 : public Product
{
public:
    std::string Operation() const override
    {
        return " what ConcreteProduct2 does";
    }
};

/**
 * the creater class declares the factory method to return an object of the product class
*/

class Creator
{
public:
    virtual ~Creator() {}
    virtual Product* Factorymethod() const = 0;

    //call a factor method to create a product object
    std::string SomeOperations() const
    {
        Product* product = this->Factorymethod();

        //now use the product
        std::string result = "the same creator code works with " + product->Operation();
        delete product;
        return result;
    }
};

/**
 * concrete creators use the abstarct factory method to change
 * the resulting product type for each creator
 * since each creator produces different product
*/

class ConcreteCreator1 : public Creator
{
public:
    Product* Factorymethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{
public:
    Product* Factorymethod() const override
    {
        return new ConcreteProduct2();
    }
};

void ClientCode(const Creator& creator)
{
    std::cout << "client: I'm not aware of this concrete class but still works"
              << creator.SomeOperations();
}

int main()
{
    std::cout << "App: Launched with concretecreator1" << std::endl;
    Creator* creator =  new ConcreteCreator1();
    ClientCode(*creator);
}
