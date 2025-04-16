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

    while (running) {

        bool again;

        again = false;

        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

        srand(gen());
        int randomelement = rand() % 117;

        std::string element = data[randomelement][0];

        // Variable for input
        std::wstring write;

        std::wcout << "Element " << element << ": ";

        std::wcin >> write;
        if (write == element) {
            std::wcout << "Correct!" << std::endl;
            score++;
            std::wcout << "--------------------------" << std::endl;
        }
    }

    return 0;
}