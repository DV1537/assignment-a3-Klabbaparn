#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include "Functions.h"
#include "Shape.h"
#include "Point.h" //Vital class. Almost everything runs through this
#include "Triangle.h"
#include <iomanip>
#include "Line.h"
#include "OnePoint.h" //This is the shape-point
#include "Polygon.h"

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Wrong amount of arguments"; //fail-checking
        return 0;
    }

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
            return (EXIT_FAILURE);
        }
        count++;
    }
    if (count % 2 != 0)
    {
        std::cout << "File is missing a coordinate" << std::endl;
        return (EXIT_FAILURE);
    }
    f.clear();
    f.seekg(0); //Rewind the file
    count = count / 2;
    Point *arrayOfCoords = new Point[count];
    double x = 0;
    double y = 0;
    int firstShapeCount = 0;
    int secondShapeCount = 0;
    bool firstShapeFilled = false;
    std::string line;
    while (std::getline(f, line))
    {
        std::istringstream iss(line);
        if (!firstShapeFilled)
        {
            while (iss >> x >> y)
            {
                Point p(x, y);
                arrayOfCoords[firstShapeCount++] = p;
                firstShapeFilled = true;
            }
        }
        else
        {
            secondShapeCount = firstShapeCount;
            while (iss >> x >> y)
            {
                Point p(x, y);
                arrayOfCoords[secondShapeCount++] = p;
            }
        }
    }
    f.close(); //Close file
    secondShapeCount = secondShapeCount-firstShapeCount;
    Point *shapeOne = new Point[firstShapeCount];
    Point *shapeTwo = new Point[secondShapeCount];
    for (int h = 0; h < firstShapeCount; h++)
        shapeOne[h] = arrayOfCoords[h];
    int my = firstShapeCount;
    for (int w = 0; w < secondShapeCount; w++)
        shapeTwo[w] = arrayOfCoords[my++];

        Polygon firstShape(shapeOne, firstShapeCount);
        Polygon secondShape(shapeTwo, secondShapeCount);
        Polygon thirdShape;

        thirdShape = firstShape+secondShape;
        std::cout << std::setprecision(4) << thirdShape.getArea() << std::endl;

        delete[] arrayOfCoords;
        delete[] shapeOne;
        delete[] shapeTwo;
        arrayOfCoords = nullptr;
        shapeOne = nullptr;
        shapeTwo = nullptr;
    return 0;
}