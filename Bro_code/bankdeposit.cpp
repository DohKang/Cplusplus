#include <iostream>
#include <iomanip>

void showBalance(double Balance);
double deposit();
double withdraw(double Balance);

int main()
{
    double balance = 0;
    int choice = 0;
    do
    {
        std::cout << "********************\n";
        std::cout << "  Enter your choice \n";
        std::cout << "********************\n";
        std::cout << "********************\n";
        std::cout << "1. Show Balance \n";
        std::cout << "2. Deposit Money \n";
        std::cout << "3. Withdraw Money \n";
        std::cout << "4. Exit \n";
        std::cin >> choice;

        // remove input buffer
        std::cin.clear();
        fflush(stdin);

        switch (choice)
        {
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += deposit();
            std::cout << "We are processing your deposit....\n";
            std::cout << "balance is $" << std::setprecision(2) << std::fixed << balance << "\n";
            break;
        case 3:
            balance = withdraw(balance);
            break;
        case 4:
            std::cout << "Thanks for visitng";
            break;
        default:
            std::cout << "Invalid choice";
        }
    } while (choice != 4);

    return 0;
}

void showBalance(double Balance)
{
    std::cout << "Your balance is $" << std::setprecision(2) << std::fixed << Balance << "\n";
}

double deposit()
{
    double input;
    std::cout << "How much do you want to deposit today?\n";
    std::cin >> input;
    if (input > 0)
    {
        return input;
    }
    else
    {
        std::cout << "THat's not a valid amount";
        return 0;
    }
}
double withdraw(double Balance)
{
    while (true)
    {
        double input;
        std::cout << "How much do you want to withdraw today?\n";
        std::cin >> input;

        if (input == -1)
        {
            return Balance;
        }
        else if (Balance - input >= 0)
        {
            Balance -= input;
            std::cout << "After your withdaw\n"
                      << "Your remianing balance is $" << std::setprecision(2) << std::fixed << Balance << "\n";
            return Balance;
        }
        else
        {
            std::cout << "Your bank balance is lower than your input, please try again\n";
        }
    }
}