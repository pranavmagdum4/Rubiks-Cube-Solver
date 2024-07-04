//
// Created by Utkarsh Singh on 4/19/24.
//
#include "bits/stdc++.h"
#include "../CubeModel/RubiksCube.h"

#ifndef RUBIKS_CUBE_DFS_SOLVER_H
#define RUBIKS_CUBE_DFS_SOLVER_H

template<typename T,typename H>
class DFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    int max_search_depth;

    bool dfs(int depth)
    {
        if(rubiksCube.isSolved()) return true;
        if(depth>max_search_depth) return false;
        for(int i=0;i<18;i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if(dfs(depth+1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:

    T rubiksCube;

    DFSSolver(T _rubiksCube,int _max_search_depth=8)
    {
        rubiksCube=_rubiksCube;
        max_search_depth=_max_search_depth;
    }
    vector<RubiksCube::MOVE> solve()
    {
        dfs(1);
        return moves;
    }
};

#endif