#include <iostream>
using namespace std;

int tabs = 0;
int kol_vo = 0;

struct Branch
{
    int Data;
    Branch* LeftSide;
    Branch* RightSide;
};

void Add(int aData, Branch*& aBranch) 
{
    if (!aBranch) 
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftSide = 0;
        aBranch->RightSide = 0;
        return;
    }
    else 
        if (aBranch->Data < aData)
        {
            Add(aData, aBranch->RightSide);
        }
        else 
        {
            Add(aData, aBranch->LeftSide);
        }
}

void print(Branch* aBranch)
{
    if (!aBranch) return;
    tabs += 5;
    print(aBranch->RightSide);
    for (int i = 0; i < tabs; i++) cout << " ";
    cout << aBranch->Data << endl;
    print(aBranch->LeftSide);
    tabs -= 5;
    return;
}

int main()
{
    Branch* Root = 0;
    int numberOfDigit = 10;
   // cout << "Enter number of digits\n";
   // cin >> numberOfDigit;
    for (int i = 0; i < numberOfDigit; i++)
        Add(rand()%100, Root);
    cout << "Output of tree:\n";
    print(Root);
}