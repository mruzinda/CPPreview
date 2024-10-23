#include <iostream>

// Figher classes

class Fighter{
    public:
        std::string name;
        int age;
        float weight;
        float height;
        float reach;
    
    void warrior(){
        std::cout << "This fighter is a warrior!" << '\n';
    }

    void resilience(){
        std::cout << "This fighter has resilience!" << '\n';
    }

    void athlete(){
        std::cout << "This fighter is an athlete!" << '\n';
    }
};

class MMA : public Fighter{
    public:

    void strike_and_grapple(){
        std::cout << "This fighter can strike and grapple!" << '\n';
    }
};

class Grappler : public Fighter{
    public:

    void grapple(){
        std::cout << "This fighter can only grapple!" << '\n';
    }
};

class Striker : public Fighter{
    public:

    void strike(){
        std::cout << "This fighter can only strike!" << '\n';
    }
};

class Boxer : public Fighter{
    public:

    void box(){
        std::cout << "This fighter can only box!" << '\n';
    }
};

int main(){
    MMA Mighty_mouse;

    Mighty_mouse.name = "Demetrious Johnson";
    Mighty_mouse.age = 35;
    Mighty_mouse.weight = 125;
    Mighty_mouse.height = 5.3;
    Mighty_mouse.reach = 60;

    std::cout << Mighty_mouse.name << " is " << Mighty_mouse.age << " years old." << '\n';
    std::cout << "He weighs " << Mighty_mouse.weight << " pounds." << '\n';
    std::cout << "He is " << Mighty_mouse.height << " feet tall." << '\n';
    std::cout << "He has a " << Mighty_mouse.reach << " inch reach." << '\n';

    Mighty_mouse.resilience();
    Mighty_mouse.strike_and_grapple();

    return 0;
}