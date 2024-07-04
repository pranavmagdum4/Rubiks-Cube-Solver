//
// Created by Utkarsh Singh on 4/21/24.
//

#ifndef RUBIKSCUBESOLVER_CORNERDBMAKER_H
#define RUBIKSCUBESOLVER_CORNERDBMAKER_H

#include "CornerPatternDatabase.h"
#include "../CubeModel/RubiksCubeBitboard.cpp"
#include "../CubeModel/RubiksCube1dArray.cpp"
#include "../CubeModel/RubiksCube3dArray.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};


#endif //RUBIKSCUBESOLVER_CORNERDBMAKER_H
