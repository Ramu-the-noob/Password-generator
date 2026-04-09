#include <iostream>
#include <random>
#include <string>

std::string Randompassword(int passwordLength, const std::string& charSet);
std::string Randompassword(int passwordLength, const std::string& charSet, int seed);

int main() {

    std::cout << "Enter password length : ";
    int passwordLength = 0;
    std::cin >> passwordLength;

    if (passwordLength <= 0) {
        std::cout << "Password length must be greater than 0!\n";
        return 1;
    }

    std::cout << "Enter the character sets you want to use (LDS) : ";
    std::string charSet;
    std::cin >> charSet;

    if (charSet.empty()) {
        std::cout << "Enter valid character sets!\n";
        return 1;
    }

    std::cin.ignore(256, '\n');

    std::cout << "Enter randomizer seed (press Enter to skip) : ";
    std::string seedInput;

    std::getline(std::cin, seedInput);

    std::string password;


    if (seedInput.empty()) {
        password = Randompassword(passwordLength, charSet);
    }
    else {
        try {
            int seed = std::stoi(seedInput);
            password = Randompassword(passwordLength, charSet, seed);
        } catch (...) {
            std::cout << "Invalid seed format! Skipping seed \n";
            password = Randompassword(passwordLength, charSet);
        }
    }

    std::cout << "Password : " << password << "\n";

    return 0;
}

std::string Randompassword(int passwordLength, const std::string& charSet) {

    std::random_device rd;
    std::mt19937 g(rd());


    std ::string password; // main password string

    std::string basket; //basket of characters

    for (char i : charSet) {
        if (i == 'L' || i == 'l') {
            basket += "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        }
        else if (i == 'D' || i =='d') {
            basket += "1234567890";
        }
        else if (i == 'S' || i == 's') {
            basket += "~`!@#$%^&*()_+=-{}[];:<>,.?/";
        }
    }

    if (basket.empty()) {
        return "Error: put in a proper charset.";
    }

    std::uniform_int_distribution<int> distribution(0, basket.length() - 1);


    for (int i = 0; i < passwordLength; i++) {
        int randomIndex = distribution(g);
        password += basket[randomIndex];
    }
    return password;

}
std::string Randompassword(int passwordLength, const std::string& charSet, int seed) {

    std::mt19937 g(seed);

    std ::string password;

    std::string basket;

    for (char i : charSet) {
        if (i == 'L' || i == 'l') {
            basket += "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        }
        else if (i == 'D' || i == 'd') {
            basket += "1234567890";
        }
        else if (i == 'S' || i == 's') {
            basket += "~`!@#$%^&*()_+=-{}[];:<>,.?/";
        }
    }

    if (basket.empty()) {
        return "Error: put in a proper charset.";
    }

    std::uniform_int_distribution<int> distribution(0, basket.length() - 1);

    for (int i = 0; i < passwordLength; ++i) {
        int randomIndex = distribution(g);
        password += basket[randomIndex];
    }

    return password;
}
