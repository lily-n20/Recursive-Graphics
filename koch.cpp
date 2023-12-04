#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

// F = move forward
// + = turn left 60
// - = turn right 60

std::string koch_curve(int level){
    if(level == 1){
        return "F ";
        
    }
    //
    return koch_curve(level - 1) + "+ " + koch_curve(level - 1) + "- - " + koch_curve(level - 1) + "+ " + koch_curve(level - 1);
}


int main(int argc, char* argv[]) {

    //take in evel (level of the drawing) and outfile string name
    int depth = std::stof(argv[1]);
    std::ofstream L_string("l-system.txt");


    for (int i = 0 ; i < 3 ; i++) {
        L_string << koch_curve(depth);
        L_string << "- - ";
    }

}