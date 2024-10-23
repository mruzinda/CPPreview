#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

//typedef std::vector<std::pair<std::string, int>> pairlist_t;
//typedef std::string text_t;
using text_t = std::string;

namespace first{
    int x = 1;
}

namespace second{
    int x = 2;
}

int main(){
    std::cout << "I like Burgers!" << '\n';
    std::cout << "They're really good!" << '\n';

    int x; // declaration
    x = 5; // assignment
    int y = 6;
    int sum = x + y;

    std::cout << first::x << '\n';

    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << sum << '\n';

    int age = 21;
    int year = 2023;
    int days = 7;

    //double (number including decimal)
    double price = 10.09;
    double gpa = 2.5;
    double temperature = 25.1;

    std::cout << "price = " << price << '\n';

    // single character
    char grade = 'A';
    char initial = 'C';

    std::cout << "grade = " << grade << '\n';

    // boolean (true or false)
    bool student = false;
    bool power = true;
    bool forSale = true;

    std::cout << "student = " << student << '\n';

    // string (objecys that represents a sequence of text)
    //std::string name = "Bro";
    text_t name = "Bro";

    std::cout << "Hello " << name << '\n';

    const double PI = 3.14159;
    double radius = 10;
    double circumference = 2*PI*radius;

    std::cout << circumference << " cm" << '\n';

    int correct = 8;
    int questions = 10;
    double score = correct/(double)questions * 100;

    std::cout << score << "%" << '\n';

    std::string name1;

    //std::cout << "What's your name?" << '\n';
    //std::cin >> name1;

    //std::cout << "Hello " << name1 << '\n';

    int age1;
    std::cout<< "What's your age? " << '\n';
    std::cin >> age1;

    std::cout << "What's your full name?" << '\n';
    std::getline(std::cin >> std::ws,name1);

    std::cout << "Hello " << name1 << '\n';

    std::cout<< "You are " << age1 << " years old!" << '\n';

    std::string cars[] = {"Corvette", "afsgff", "drgdfh"};

    std::cout << "Car: " << cars[0] << '\n';
    std::cout << "Size of Cars: " << sizeof(cars)<< '\n';

    std::string name2 = "Mark R";
    std::cout << "Size of name2: " << sizeof(name2)<< '\n';


    return 0;
}