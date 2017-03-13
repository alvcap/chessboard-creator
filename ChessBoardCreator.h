#ifndef CHESSBOARDCREATOR_H
#define CHESSBOARDCREATOR_H

#include <iostream>
#include <libps/pslib.h>

using namespace std;

class ChessBoardCreator
{
    public:
        const float mm2pt = 2.8345;

        int rows;
        int columns;
        int size_mm;
        float size_pt;

        ChessBoardCreator();

    void CreateBoardMm();
};

#endif
