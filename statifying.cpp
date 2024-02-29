#include<iostream>

class avengers
{
private:
    static int health;
    std::string specialPower;
public:
    std::string name;
    avengers(std::string nam,std::string sp,int h = 100){
        name = nam;
        specialPower = sp;
        health += h;
    }

    void display(){
        std::cout << "Name: " << name << std::endl;
        std::cout << "Special Power: " << specialPower << std::endl;
        std::cout << "Health: " << health << std::endl;
    }

    static void attack(){
        std::cout << health<<"Attack" << std::endl;
    }

    void defend(){
        std::cout << "Defend" << std::endl;
    }

    void heal(){
        health += 10;
    }
};

int avengers::health = 0;

int main()
{
    avengers ironMan("IronMan","Suit",100);
    avengers thor("Thor","Hammer",500);
    avengers hulk("Hulk","Rage",1000);
    avengers captainAmerica("Captain America","Shield",150);

    ironMan.display();

    return 0;
}