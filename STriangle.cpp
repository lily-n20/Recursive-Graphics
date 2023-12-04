#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string drawTriangle(int n, bool isSecondPattern = false);

std::string drawTriangle(int n, bool isSecondPattern) {
    // base case
    if (n == 0) {
        return "F ";
    } else {
        std::string A = drawTriangle(n-1, false);
        std::string B = drawTriangle(n-1, true);
        if (isSecondPattern) {
            return B + B;
        } else {
            return A + "+ " + B + "- " + A + "- " + B + "+ " + A;
        }
    }
}

std::string generateLSystem(int n) {
    std::string part = drawTriangle(n, false);
    return part + "+ " + drawTriangle(n, true) + "+ " + drawTriangle(n, true);
}

void save(std::string filename, std::string Lsystem) {
    std::ofstream file;
    file.open(filename);
    file << Lsystem;
    file.close();
}

int main(int argc, char **argv) {
    int n = std::stoi(argv[1]);
    std::string Lsystem = generateLSystem(n);
    save("l-system.txt", Lsystem);
    return 0;
}