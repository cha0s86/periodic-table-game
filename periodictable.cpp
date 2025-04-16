#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <string>
using namespace std;

int main() {

    std::fstream periodictable;
    periodictable.open("periodictable.csv");

    std::vector<std::vector<std::string>> data;

    std::string line;
    while (std::getline(periodictable, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    periodictable.close();

    bool running = true;

    int score = 0;

    bool again;

    while (running) {

        again = false;

        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

        srand(gen());
        int randomelement = rand() % 117;

        std::string element = data[randomelement][0];

        // Variable for input
        std::string write;
        std::string userinput;

        std::cout << "Atomic number for " << data[randomelement][1] << " (" << data[randomelement][2] << "): ";

        std::cin >> write;
        if (write == data[randomelement][0]) {
            std::cout << "Correct! You scored a point!" << std::endl;
            score++;
        }
        else {
            std::cout << "Incorrect! Your score was: " << score << "!" << std::endl;
            while (again == false) {
                std::cout << "Do you want to play again? (yes/no): ";
                std::cin >> userinput;
                if (userinput == "yes") {
                    again = true;
                }
                else if (userinput == "no") {
                    again = false;
                    return 0;
                }
                else {
                    std::cout << "I didn't understand that..." << std::endl;
                }
            }
        }
    }

    return 0;
}