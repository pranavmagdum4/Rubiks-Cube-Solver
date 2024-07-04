//
// Created by Utkarsh Singh on 4/21/24.
//

#ifndef RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H
#define RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H

#include "../CubeModel/RubiksCube.h"
#include "PermutationIndexer.h"
#include "PatternDatabases.h"

class CornerPatternDatabase : public PatternDatabases{

    typedef RubiksCube::FACE F;
    PermutationIndexer<8> permIndexer;
public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_value);
    uint32_t getDatabaseIndex(const RubiksCube &cube) const;
};

#endif //RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H
