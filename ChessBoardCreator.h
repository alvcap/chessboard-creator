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
        const float mm2pt = 2.8345;
        const int rowSizeA4 = 596;
        const int colSizeA4 = 842;

        int rows;
        int columns;
        float squareSizeMm;
        float squareSizePt;
        float margin = 0;

    public:
        ChessBoardCreator();
        string CreateFileName();
        void SetMargin(float marginValue);
        void CreateBoardMm();
};

#endif
