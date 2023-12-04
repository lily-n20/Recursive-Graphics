#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

// F = move forward
// + = turn left 60
// - = turn right 60

//recursive function to draw single koch curve
std::string koch_curve(int level){
    //base level of complexity 
    if(level == 1){
        return "F ";
    }
    //split line into four parts with middle two lines connecting upwards to create a equilateral triangle with no base
    return koch_curve(level - 1) + "+ " + koch_curve(level - 1) + "- - " + koch_curve(level - 1) + "+ " + koch_curve(level - 1);
}


int main(int argc, char* argv[]) {
    //take in level of complexity
    int depth = std::stof(argv[1]);
    //create output file
    std::ofstream L_string("l-system.txt");

    //exception handling
    if(depth < 1){
        depth = 1;
    }

    //call curve three times to create snowflake
    for (int i = 0 ; i < 3 ; i++) {
        L_string << koch_curve(depth);
        L_string << "- - "; //turn right 120 degrees before next line
    }

}