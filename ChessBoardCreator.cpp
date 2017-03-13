#include "ChessBoardCreator.h"


ChessBoardCreator::ChessBoardCreator()
{
    cout << "Number of rows: ";
    cin >> rows;
    cout << "Number of cols: ";
    cin >> columns;

    while (columns%2 == 0)
    {
        cout << "--" << endl;
        cout << "ERROR: Nr. of columns has to be odd" << endl;
        cout << "  Number of cols: ";
        cin >> columns;
    }

    cout << "Size of square (mm): ";
    cin >> size_mm;

    size_pt = size_mm * mm2pt;

}

void ChessBoardCreator::CreateBoardMm()
{
    string FileName = "chessboard_" + to_string(rows) \
                  + "x" + to_string(columns) + \
                  + "_" + to_string(size_mm) + "mm.ps";

    PSDoc *cb;

    PS_boot();
    cb = PS_new();
    PS_open_file(cb, FileName.c_str());

    PS_set_info(cb, "Creator", __FILE__);
    PS_set_info(cb, "Author", "github.com/alvcap/chessboard-creator");
    PS_set_info(cb, "Title", "Chess Board");
    PS_begin_page(cb, 596, 842);    //A4

    float color = 0.0;
    for (int r=0; r<rows; r++)
    {
        for (int c=0;c<columns; c++)
        {
            PS_setcolor(cb, "fillstroke", "gray", color, 0.0, 0.0, 0.0);
            PS_rect(cb, size_pt*r, size_pt*c, size_pt, size_pt);
            PS_fill(cb);

            if (color == 0.0)
            {
                color = 1.0;
            }else
            {
                color = 0.0;
            }
        }

    }

    PS_end_page(cb);
    PS_close(cb);
    PS_delete(cb);
    PS_shutdown();

    cout << "Generated file: " << FileName << endl;
}

int main()
{
    ChessBoardCreator CB;
    CB.CreateBoardMm();

    return 0;
}
