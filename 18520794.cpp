#include <iostream>
#include <fstream>

using namespace std;

struct board
{
    int height;
    int width;
};

void inputFile(board(&listOfBoard)[100])
{
    ifstream box;
    box.open("box.inp");
    for (int i = 0; i < 6; i++)
    {
        int firstVal;
        int secondVal;
        box >> firstVal;
        box >> secondVal;
        if (firstVal > secondVal)
        {
            listOfBoard[i].width = firstVal;
            listOfBoard[i].height = secondVal;
        }
        else
        {
            listOfBoard[i].width = secondVal;
            listOfBoard[i].height = firstVal;
        }
    }
    box.close();
}

bool inArray(board value, board arr[], int len)
{
    for (int j = 0; j < len; j++)
    {
        if (value.height == arr[j].height && value.width == arr[j].width)
        {
            return true;
        }
    }

    return false;
}

bool checkBoardValidity(board arr[])
{
    bool checker = false;
    board firstBoard = arr[0];
    board secondBoard;
    board otherBoard;
    for (int i = 1; i < 3; i++)
    {
        if (firstBoard.width == arr[i].width)
        {
            secondBoard = arr[i];
        }
        else
        {
            otherBoard = arr[i];
        }
    }

    if (firstBoard.height == otherBoard.width && secondBoard.height == otherBoard.height)
        checker = true;

    if (firstBoard.height == otherBoard.height && secondBoard.height == otherBoard.width)
        checker = true;

    return checker;
}

void solver(board listOfBoard[100])
{
    board newListOfBoard[100];
    int len = 1;
    newListOfBoard[0].height = listOfBoard[0].height;
    newListOfBoard[0].width = listOfBoard[0].width;
    for (int i = 0; i < 6; i++)
    {
        if (!inArray(listOfBoard[i], newListOfBoard, len))
        {
            newListOfBoard[len].height = listOfBoard[i].height;
            newListOfBoard[len].width = listOfBoard[i].width;
            len++;
        }
    }

    if (len > 3)
    {
        cout << "NO";
        exit(0);
    }
    if (checkBoardValidity(newListOfBoard))
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    board listOfBoard[100];
    inputFile(listOfBoard);
    solver(listOfBoard);
    return 1;
}
