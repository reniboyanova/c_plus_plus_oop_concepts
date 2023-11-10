#include <iostream>

class Product {
protected:
    double price;
    int quantity;

public:
    Product() : price(0.0), quantity(0) {}

    virtual ~Product() {
        std::cout << "Product Destructor\n";
        print();
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    virtual void print() {
        std::cout << "Product: Price = " << price << ", Quantity = " << quantity << std::endl;
    }
};

class Order : public Product {
public:
    ~Order() override {
        std::cout << "Order Destructor\n";
        print();
    }

    void print() override {
        std::cout << "Order print:\n";
        Product::print();
    }
};

int main() {
    Product* order = new Order();
    order->setPrice(10.99);
    order->setQuantity(5);
    
    delete order;

    return 0;
}
