#include "ChessBoardCreator.h"

ChessBoardCreator::ChessBoardCreator()
{
    cout << "Number of rows: ";
    cin >> rows;
    cout << "Number of cols: ";
    cin >> columns;
    cout << "Size of square (mm): ";
    cin >> squareSizeMm;

    squareSizePt = squareSizeMm * mm2pt;
}

void ChessBoardCreator::CreateBoardMm()
{
    string fileName = "chessboard_" + to_string(rows) \
                              + "x" + to_string(columns) + \
                              + "_" + to_string(squareSizeMm) + "mm.ps";

    PSDoc *cb;
    float color;

    PS_boot();
    cb = PS_new();
    PS_open_file(cb, fileName.c_str());

    PS_set_info(cb, "Creator", __FILE__);
    PS_set_info(cb, "Author", "https://github.com/alvcap/chessboard-creator");
    PS_set_info(cb, "Title", "Chessboard");
    PS_begin_page(cb, rowSizeA4, colSizeA4);    //A4

    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<columns; c++)
        {
            // Alternate black and white between squares
            if ((c+r)%2==0)
                color = 0.0;
            else
                color = 1.0;

            PS_setcolor(cb, "fillstroke", "gray", color, 0.0, 0.0, 0.0);
            PS_rect(cb, squareSizePt*r, squareSizePt*c, \
                             squareSizePt, squareSizePt);
            PS_fill(cb);
        }
    }

    PS_end_page(cb);
    PS_close(cb);
    PS_delete(cb);
    PS_shutdown();

    cout << "Generated file: " << fileName << endl;
}

int main()
{
    ChessBoardCreator CB;
    CB.CreateBoardMm();

    return 0;
}
