#include <iostream>
#include <fstream>

std::string getOutput(char dir, int degree){
    if(dir == 'R' && degree > 0){
        return "+";
    }
    else if(dir == 'R' && degree < 0){
        return "-";
    }
    else if(dir == 'L' && degree > 0){
        return "-";
    }
    else if(dir == 'L' && degree < 0){
        return "+";
    }
}

void hilbert(int level, double angle, std::ofstream &outFile){

    char dir;
    int degree;
    std::string outPut;

    if(level == 0){
        return ;
    }

    dir = 'R';
    degree = angle;
    outPut= getOutput(dir, degree);
    outFile << outPut;
    //outFile << "R " << angle << std::endl;


    hilbert(level-1,-1 * angle, outFile);

    outFile << "F";

    dir = 'L';
    degree = angle;
    outPut= getOutput(dir, degree);
    outFile << outPut;
    //outFile << "L " << angle << std::endl;

    hilbert(level - 1, angle, outFile);

    outFile << "F";
    hilbert(level-1, angle, outFile);

    dir = 'L';
    degree = angle;
    outPut= getOutput(dir, degree);
    outFile << outPut;
    //outFile << "L " << angle << std::endl;

    outFile << "F";
    hilbert(level-1, -1 * angle, outFile);

    dir = 'R';
    degree = angle;
    outPut= getOutput(dir, degree);
    outFile << outPut;

}



int main(int argc, char* argv[]){


    //int angle = std::stoi(argv[2]);
    std::string fileName = argv[1];
    int level = std::stoi(argv[2]);
    std::ofstream out_file(fileName);

    out_file<< "test" << std::endl;

    hilbert(level, 90, out_file);


}
