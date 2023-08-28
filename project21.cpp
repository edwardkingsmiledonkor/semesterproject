#include <iostream>
#include <string>
#include <map>

class PasswordManager {
private:
    std::map<std::string, std::string> passwords;
    const std::string encryptionKey = "mysecretkey"; // Replace with a strong key

    // Encrypt data using a simple XOR operation
    std::string encrypt(const std::string& data) {
        std::string encrypted = data;
        for (size_t i = 0; i < encrypted.length(); ++i) {
            encrypted[i] ^= encryptionKey[i % encryptionKey.length()];
        }
        return encrypted;
    }

    // Decrypt data using the same XOR operation
    std::string decrypt(const std::string& encrypted) {
        return encrypt(encrypted); // XOR encryption is symmetric
    }

public:
    void addPassword(const std::string& account, const std::string& password) {
        passwords[account] = encrypt(password);
        std::cout << "Password added for account: " << account << std::endl;
    }

    void getPassword(const std::string& account) {
        if (passwords.find(account) != passwords.end()) {
            std::string decrypted = decrypt(passwords[account]);
            std::cout << "Password for account " << account << ": " << decrypted << std::endl;
        } else {
            std::cout << "No password found for account: " << account << std::endl;
        }
    }

    void displayAllPasswords() {
        std::cout << "Stored passwords:" << std::endl;
        for (const auto& entry : passwords) {
            std::string decrypted = decrypt(entry.second);
            std::cout << "Account: " << entry.first << ", Password: " << decrypted << std::endl;
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
        std::cout << "3. Display All Passwords" << std::endl;
        std::cout << "4. Exit" << std::endl;
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
                manager.displayAllPasswords();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);
    
    return 0;
}


