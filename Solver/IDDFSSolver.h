//
// Created by Utkarsh Singh on 4/19/24.
//
#include "bits/stdc++.h"
#include "../CubeModel/RubiksCube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_IDDFS_SOLVER_H
#define RUBIKS_CUBE_IDDFS_SOLVER_H

template<typename T,typename H>
class IDDFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    int max_search_depth;

public:

    T rubiksCube;

    IDDFSSolver(T _rubiksCube,int _max_search_depth=8)
    {
        rubiksCube=_rubiksCube;
        max_search_depth=_max_search_depth;
    }
    vector<RubiksCube::MOVE> solve()
    {
        for(int i=1;i<=max_search_depth;i++)
        {
            DFSSolver<T,H> dfsSolver(rubiksCube,i);
            moves=dfsSolver.solve();
            if(dfsSolver.rubiksCube.isSolved())
            {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif