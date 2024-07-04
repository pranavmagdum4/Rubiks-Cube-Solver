//
// Created by Utkarsh Singh on 4/20/24.
//

#ifndef RUBIKSCUBESOLVER_PATTERNDATABASES_H
#define RUBIKSCUBESOLVER_PATTERNDATABASES_H

#include "../CubeModel/RubiksCube.h"
#include "NibbleArray.h"
#include "bits/stdc++.h"

class PatternDatabases{
    NibbleArray database;
    size_t size;
    size_t numItems;

    PatternDatabases();

public:
    PatternDatabases(const size_t size);
    PatternDatabases(const size_t size, uint8_t init_value );

    virtual uint32_t getDatabaseIndex(const RubiksCube &cube) const = 0;
    virtual bool setNumMoves(const uint32_t idx,const uint8_t numMoves);
    virtual bool setNumMoves(const RubiksCube &cube,const uint8_t numMoves);
    virtual uint8_t getNumMoves(const RubiksCube &cube) const;
    virtual uint8_t getNumMoves(const uint32_t idx) const;
    virtual size_t getSize() const;
    virtual size_t getNumItems() const;
    virtual bool isFull() const;
    virtual void toFile(const string &fileName) const;
    virtual bool fromFile(const string &fileName);
    virtual void inflate(vector<uint8_t> &des) const;
    virtual vector<uint8_t> inflate() const;
    virtual void reset();
};

#endif //RUBIKSCUBESOLVER_PATTERNDATABASES_H
