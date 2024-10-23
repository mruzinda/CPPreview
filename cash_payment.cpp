#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

class Bank_Account
{
private:
    float balance = 10;

public:
    // Constructor
    // Bank_Accounts(float value) : balance(value){}

    void get_balance()
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Your Balance is $" << this->balance << std::endl;
    }

    void deposit(float deposit_amount)
    {
        this->balance += deposit_amount;
        get_balance();
    }

    void withdraw(float withdrawal_amount)
    {
        this->balance -= withdrawal_amount;
        get_balance();
    }
};

std::string product_choices(std::unordered_map<std::string, float> &products)
{
    std::string product_choice;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "************* HOME PAGE *************" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    std::cout << "These are the current products and prices at the company:" << std::endl;
    for (const auto &pair : products)
    {
        std::cout << pair.first << " - $" << std::fixed << std::setprecision(2) << static_cast<float>(pair.second) << std::endl;
    }
    std::cout << "" << std::endl;
    std::cout << "Select a product:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, product_choice);

    return product_choice;
}

int main()
{
    std::cout << "Welcome to Ruzindana Enterprises!" << std::endl;

    std::string choice;
    std::cout << "Enter <C> to continue and products for sale or <Q> to Quit and press <Enter>:" << std::endl;
    std::cin >> choice;

    // Wait until user chooses to continue or quit
    while (choice != "C")
    {
        if (choice == "Q")
        {
            std::cout << "Come back again!" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "This option does not exist. Type <C> to continue or <Q> to quit." << std::endl;
            std::cin >> choice;
        }
    }

    std::unordered_map<std::string, float> products;
    products["Arc Reactor"] = 1000000000.0;
    products["Vibranium Shield"] = 5000000.0;
    products["Cybernetic Arm"] = 3000000.0;

    std::unordered_map<std::string, float> checkout;

    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> customerData;
    std::unordered_map<std::string, int> customerBalance;
    customerData["John Doe"]["Bank Account"] = "123456789";
    customerData["John Doe"]["Expiration Date"] = "12/25";
    customerData["John Doe"]["CVV"] = "123";
    customerData["John Doe"]["Zip Code"] = "90210";
    customerBalance["John Doe"] = 5000000.0;

    /*
        Bank_Account person1;

        person1.get_balance();
        person1.deposit(100);
        person1.withdraw(50);
    */

    enum
    {
        PRODUCT_SELECTION,
        CHECKOUT,
        PAYMENT
    };

    int currentState = PRODUCT_SELECTION;
    std::string product_choice;
    char continue_process;
    std::string full_name;
    std::string bank_account_info;
    bool bank_account_info_complete = false;
    float balance = 0;

    while (true)
    {
        switch (currentState)
        {
        case PRODUCT_SELECTION:
            product_choice = product_choices(products);

            std::cout << product_choice << "end" << std::endl;

            // Payment options
            if (products.count(product_choice))
            {
                checkout[product_choice] = products[product_choice];
                std::cout << product_choice << " for $" << std::fixed << std::setprecision(2) << static_cast<float>(products[product_choice]) << " has been placed in checkout!" << std::endl;
                std::cout << "Would you like to continue shopping?" << std::endl;
                std::cout << "Enter <P> to go back to product selection or <C> if you would like to go to checkout:" << std::endl;
                std::cin >> continue_process;

                while (continue_process != 'P' && continue_process != 'C')
                {
                    std::cout << "Invalid option. Enter <Y> or <N>:" << std::endl;
                    std::cin >> continue_process;
                }

                if (continue_process == 'P')
                {
                    currentState = PRODUCT_SELECTION;
                    std::cout << "Going back to product selection!" << std::endl;
                }
                else if (continue_process == 'C')
                {
                    currentState = CHECKOUT;
                    std::cout << "Going to checkout!" << std::endl;
                }
            }
            else
            {
                std::cout << "The choice that you made does not exist in the database!" << std::endl;
            }

            break;

        case CHECKOUT:
            if (checkout.empty())
            {
                std::cout << "There is nothing in your checkout." << std::endl;
            }
            else
            {
                std::cout << "These are the current products and prices in the checkout:" << std::endl;
                for (const auto &pair : checkout)
                {
                    std::cout << pair.first << " - $" << static_cast<float>(pair.second) << std::endl;
                }
            }

            std::cout << "Would you like to go back to the product selection <P> or quit <Q> or payment <$>:" << std::endl;
            std::cin >> continue_process;

            while (continue_process != 'P' && continue_process != 'Q' && continue_process != '$')
            {
                std::cout << "Invalid option. Enter <P> or <$> or <Q>:!" << std::endl;
                std::cin >> continue_process;
            }

            if (continue_process == 'P')
            {
                currentState = PRODUCT_SELECTION;
                std::cout << "Going back to product selection!" << std::endl;
            }
            else if (continue_process == '$')
            {
                currentState = PAYMENT;
                std::cout << "Going to Payments!" << std::endl;
            }
            else if (continue_process == 'Q')
            {
                std::cout << "Come back again soon!" << std::endl;
                return 0;
            }

            break;

        case PAYMENT:
            std::cout << "Products in checkout:" << std::endl;
            // Get total amount
            float total_amount;
            for (const auto &pair : checkout)
            {
                std::cout << pair.first << " - $" << std::fixed << std::setprecision(2) << static_cast<float>(pair.second) << std::endl;
                total_amount += pair.second;
            }

            // Display all products in checkout again and display total
            std::cout << "Total Amount: $" << std::fixed << std::setprecision(2) << total_amount << std::endl;

            // Ask whether the amount looks correct.
            std::cout << "Does this amount look correct? Yes <Y> or No <N>" << std::endl;
            std::cin >> continue_process;

            while (continue_process != 'Y' && continue_process != 'N')
            {
                std::cout << "Invalid option. Enter <Y> or <N>:" << std::endl;
                std::cin >> continue_process;
            }

            // If it is correct, request for:
            // First and Last Name
            // Bank Account Number
            // Expiration Date
            // CVV
            // If not, there was a problem, erase checkout, and start over.
            if (continue_process == 'Y')
            {
                while (bank_account_info_complete == false)
                {
                    std::cout << "Enter Bank Account Info." << std::endl;
                    std::cout << "Customer Name:" << std::endl;
                    std::cin.ignore(); // Clear the buffer after cin and before getline()
                    std::getline(std::cin, full_name);
                    if (customerData.count(full_name) > 0)
                    {
                        std::cout << full_name << " exists in the database" << std::endl;
                        std::cout << "Enter Bank Account Number:" << std::endl;
                        std::getline(std::cin,bank_account_info);
                        std::cout << "Bank Account = " << bank_account_info << std::endl;
                        if (customerData[full_name]["Bank Account"] == bank_account_info)
                        {
                            std::cout << "Correct Bank Account Number." << std::endl;
                        }
                        else
                        {
                            std::cout << "Incorrect Bank Account Number." << std::endl;
                            continue;
                        }
                        std::cout << "Enter Expiration Date:" << std::endl;
                        std::getline(std::cin,bank_account_info);
                        std::cout << "Expiration Date = " << bank_account_info << std::endl;
                        if (customerData[full_name]["Expiration Date"] == bank_account_info)
                        {
                            std::cout << "Correct Expiration Date." << std::endl;
                        }
                        else
                        {
                            std::cout << "Incorrect Expiration Date." << std::endl;
                            continue;
                        }
                        std::cout << "Enter CVV (3 digits on card):" << std::endl;
                        std::getline(std::cin,bank_account_info);
                        std::cout << "CVV = " << bank_account_info << std::endl;
                        if (customerData[full_name]["CVV"] == bank_account_info)
                        {
                            std::cout << "Correct CVV." << std::endl;
                        }
                        else
                        {
                            std::cout << "Incorrect CVV." << std::endl;
                            continue;
                        }
                        std::cout << "Enter Zip Code:" << std::endl;
                        std::getline(std::cin,bank_account_info);
                        std::cout << "Zip Code = " << bank_account_info << std::endl;
                        if (customerData[full_name]["Zip Code"] == bank_account_info)
                        {
                            std::cout << "Correct Zip Code." << std::endl;
                            bank_account_info_complete = true;
                        }
                        else
                        {
                            std::cout << "Incorrect Zip Code." << std::endl;
                            continue;
                        }
                    }
                    else
                    {
                        std::cout << full_name << " does not exist in the database." << std::endl;
                    }
                }
            }
            else if (continue_process == 'N')
            {
                std::cout << "There was a problem in the process. Apologies, you will have to start over :(" << std::endl;
                checkout.clear();
                currentState = PRODUCT_SELECTION;
            }

            // If Bank account exists, ask customer to enter <C> to continue with payment or <Q> to quit
            if(bank_account_info_complete == true){
                balance = customerBalance[full_name] - total_amount;
                if(balance < 0)
                {
                    std::cout << "As a courtesy to you," << full_name << ", our customer, you should know that you have insufficient funds. Would you like to continue?" << std::endl;
                }
                std::cout << "Enter <C> to continue with payment or <Q> to quit:" << std::endl;
                std::cin >> continue_process;
                std::cout << "continue_process = " << continue_process << std::endl;

                while (continue_process != 'C' && continue_process != 'Q')
                {
                    std::cout << "Invalid option. Enter <Y> or <N>:" << std::endl;
                    std::cin >> continue_process;
                }
                
                if(continue_process == 'C')
                {
                    std::cout << "Payment Complete!" << std::endl;
                    std::cout << "Thanks for your order!" << std::endl;
                    checkout.clear();
                    currentState = PRODUCT_SELECTION;
                }
                else if(continue_process == 'Q')
                {
                    std::cout << "Come back again!" << std::endl;
                    checkout.clear();
                    return 0;
                }
            }

            // After payment is made, display message, clear checkout and ask to continue shopping <C> or quit <Q>

            break;
        }
    }

    return 0;
}
