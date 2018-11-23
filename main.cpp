#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "Functions.h"
#include "Shape.h"
#include "Point.h"
#include "Triangle.h"
#include <iomanip>

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Wrong amount of arguments"; //fail-checking
        return 0;
    }

    double x = 0;
    double y = 0;
    double sum = 0;
    int count = 0;
    std::string stringOfNumbers;
    std::ifstream f(argv[1]);
    if (!f.is_open())
    {
        std::cout << "File failed to open!" << std::endl; //fail-checking
        exit(EXIT_FAILURE);
    }
    while (f >> stringOfNumbers)
    {
        if (countOfChar(stringOfNumbers, '.') > 1 || //Check if string doesn't contain more than 1 dot.
            countOfChar(stringOfNumbers, '-') > 1 || //Check if string doesn't contain more than one subtraction
            countOfChar(stringOfNumbers, '+') > 1 || //Checks if string doesn't contain more than one addition
            !hasValidChars(stringOfNumbers))         //Checks that the strings only contains numbers
        {
            std::cout << "File is corrupt" << std::endl;
            return EXIT_FAILURE;
        }
        count++;
    }
    if (count % 2 != 0)
    {
        std::cout << "File is missing a coordinate" << std::endl;
        return (EXIT_FAILURE);
    }
    Point *arrayOfCoords;
    arrayOfCoords = new Point[count]; //Allocate a dynamic memory array
    f.clear();
    f.seekg(0); //Rewind the file

    int j = 0;
    while (f >> x >> y)
    {
        sum += x+y;
        Point p(x, y);
        arrayOfCoords[j] = p;          // Insert integers into array
        j++;
    }
    f.close(); //Close file

    Triangle myTriangle(arrayOfCoords[0], arrayOfCoords[1], arrayOfCoords[2]);
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    std::cout << "Area is " << myTriangle.getArea() << std::endl;

    Triangle myCircus(arrayOfCoords[0], arrayOfCoords[1], arrayOfCoords[2]);
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    std::cout << "Circumference is " << myCircus.getCircumreference() << std::endl;

    Triangle myCenter(arrayOfCoords[0], arrayOfCoords[1], arrayOfCoords[2]);
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    std::cout << "Centerposition is (" << myCenter.position().getX() << ", " << myCenter.position().getY() << ")" << std::endl;

    /*for (int k = 0; k < count; k++) //Loop and prints the numbers that are above average
        if (arrayOfNumbers[k] > (sum / count))
            std::cout << arrayOfNumbers[k] << " ";*/
    

    delete[] arrayOfCoords; //Delete buffer to prevent memory leakage
    return 0;
}
