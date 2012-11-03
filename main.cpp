#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("./input.txt");
    char ch;
    vector <vector <char> > table;
    int tableSize, maxSize, numLines, numColumns;

    if (!fin.is_open())
    {
        cout << "Unable to open file.";
        return -1;
    }

    table.push_back(vector<char>());
    while (fin.get(ch))
    {
        //new lines trigger creation of new rows in the vector
        if (ch == '\n')
        {
            table.push_back(vector <char>());
        }
        //if a non-newline is found, push it onto the vector, then eat the space following it
        else
        {
            table.back().push_back(ch);
            if (fin.peek() == ' ') fin.ignore(1, ' ');
        }
    }

    fin.close();
    tableSize = table.size();
    numLines = 2*table.size() + 1;
    maxSize = 0;

    //make all vectors the same size, filling in new elements with spaces
    if (tableSize == 1) maxSize = table.at(0).size();
    else
    {
        for (int i = 0; i < tableSize; i++)
        {
            if (table.at(i).size() > maxSize) maxSize = table.at(i).size();
        }

        for (int i = 0; i < tableSize; i++)
        {
            table.at(i).resize(maxSize, ' ');
        }
    }

    numColumns = 2*maxSize + 1;

    //Iterate through each element of the table, determining what to draw (or not draw) as we go
    for (int i = 0; i < numLines; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            int row = i/2, column = j/2;
            if (i % 2 == 0 && j % 2 == 0) //both indices are even, corner ('+')
            {
                bool corner = false;

                //upper left
                if (row - 1 < 0 || column - 1 < 0);
                else corner = (corner || table.at(row - 1).at(column - 1) != ' ');

                //upper right
                if (row - 1 < 0 || column >= maxSize);
                else corner = (corner || table.at(row - 1).at(column) != ' ');

                //lower left
                if (row >= tableSize || column - 1 < 0);
                else corner = (corner || table.at(row).at(column - 1) != ' ');

                //lower right
                if(row >= tableSize || column >= maxSize);
                else corner = (corner || table.at(row).at(column) != ' ');

                if (corner) cout << "+";
                else cout << " ";
            }
            else if (i % 2 == 0 && j % 2 == 1) //horizontal border ('---'); column is guaranteed to be within bounds
            {
                bool border = false;

                //top
                if (row - 1 < 0);
                else border = (border || (table.at(row - 1).at(column) != ' '));

                //bottom
                if(row >= tableSize);
                else border = (border || table.at(row).at(column) != ' ');

                if (border) cout << "---";
                else cout << "   ";
            }
            else if (i % 2 == 1 && j % 2 == 0) //vertical border ('|'); row is guaranteed to be within bounds
            {
                bool border = false;

                //left
                if (column - 1 < 0);
                else border = (border || (table.at(row).at(column - 1) != ' '));

                //right
                if(column >= maxSize);
                else border = (border || table.at(row).at(column) != ' ');

                if (border) cout << "|";
                else cout << "   ";
            }
            else if (i % 2 == 1 && j % 2 == 1) //both indices are odd; there's a character here
            {
                cout << " " <<table.at(row).at(column) << " ";
            }
        }

        if (i != numLines) cout << endl;
    }


    return 0;
}
