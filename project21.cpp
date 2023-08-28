#include <iostream>
#include <string>
#include <map>

class PasswordManager {
private:
    std::map<std::string, std::string> passwords;

public:
    void addPassword(const std::string &account, const std::string &password) {
        passwords[account] = password;
        std::cout << "Password added for account: " << account << std::endl;
    }

    void getPassword(const std::string &account) {
        if (passwords.find(account) != passwords.end()) {
            std::cout << "Password for account " << account << ": " << passwords[account] << std::endl;
        } else {
            std::cout << "No password found for account: " << account << std::endl;
        }
    }
};

int main() {
    PasswordManager manager;
    int choice;

    do {
        std::cout << "\nPassword Manager Menu:" << std::endl;
        std::cout << "1. Add Password" << std::endl;
        std::cout << "2. Get Password" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string account, password;
                std::cout << "Enter account name: ";
                std::cin >> account;
                std::cout << "Enter password: ";
                std::cin >> password;
                manager.addPassword(account, password);
                break;
            }
            case 2: {
                std::string account;
                std::cout << "Enter account name: ";
                std::cin >> account;
                manager.getPassword(account);
                break;
            }
            case 3:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}


