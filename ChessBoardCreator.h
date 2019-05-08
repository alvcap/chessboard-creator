#ifndef CHESSBOARDCREATOR_H
#define CHESSBOARDCREATOR_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <libps/pslib.h>

using namespace std;

class ChessBoardCreator
{
    private:
        static const float mm2pt;
        static const float rowSizeA4;
        static const float colSizeA4;

        int rows;
        int columns;
        float squareSizeMm;
        float squareSizePt;
        float margin;

    public:
        ChessBoardCreator();
        string CreateFileName();
        void SetMargin(float marginValue);
        void CreateBoardMm();
};

#endif
