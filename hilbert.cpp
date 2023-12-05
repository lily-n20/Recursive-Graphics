#include <iostream>
#include <fstream>

// Function to determine the output string based on the direction and degree (whether its positive or negative)
std::string getOutput(char dir, int degree){

    //if turning right and the degree is positive then it is an actual right turn
    if(dir == 'R' && degree > 0){
        return "+ ";
    }

    //if turning right and the degree is negative then it is a left turn
    else if(dir == 'R' && degree < 0){
        return "- ";
    }

    //if turning left and the degree is positive then it is a left turn
    else if(dir == 'L' && degree > 0){
        return "- ";
    }

    //if turning left and the degree is negative then it is a right turn
    else if(dir == 'L' && degree < 0){
        return "+ ";
    }
    return "";
}

// Recursive function to generate Hilbert curve instructions
void hilbert(int level, double angle, std::ofstream &outFile){

    //initializes variables needed for getOuput function
    char dir;
    int degree;
    std::string outPut;

    //base case -> if level = 0 function is done
    if(level == 0){
        return ;
    }

    // Move right and turn by the specified angle
    dir = 'R';
    degree = angle;
    outPut= getOutput(dir, degree);
    outFile << outPut;

    // Recursively generate the Hilbert curve for the next level with opposite angle
    hilbert(level-1,-1 * angle, outFile);

    // Move forward
    outFile << "F ";

    // Move left and turn by the specified angle
    dir = 'L';
    degree = angle;
    outPut= getOutput(dir, degree);
    outFile << outPut;

    // Recursively generate the Hilbert curve for the next level with the same angle
    hilbert(level - 1, angle, outFile);

    // Move forward
    outFile << "F ";

    // Recursively generate the Hilbert curve for the next level with the same angle
    hilbert(level-1, angle, outFile);

    // Move left and turn by the specified angle
    dir = 'L';
    degree = angle;
    outPut= getOutput(dir, degree);
    outFile << outPut;

    // Move forward
    outFile << "F ";

    // Recursively generate the Hilbert curve for the next level with opposite angle
    hilbert(level-1, -1 * angle, outFile);

    // Move right and turn by the specified angle
    dir = 'R';
    degree = angle;
    outPut= getOutput(dir, degree);
    outFile << outPut;

}

int main(int argc, char* argv[]){

    // Get the level from command line arguments
    int level = std::stoi(argv[1]);

    //exception handling
    if(level < 1){
        level = 1;
    }

    // Specify the output file name
    std::string fileName = "l-system.txt";

    // Open the output file
    std::ofstream out_file(fileName);

    // Generate the Hilbert curve and write instructions to the output file
    hilbert(level, 90, out_file);

    // Close the output file
    out_file.close();

}
