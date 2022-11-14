/*

MATRIX TRANSPOSE

Problem - Given a square matrix A & its number of rows (or columns) N, return the transpose of A. The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

Constraints
1 <= N <= 1000

Sample Input1
A = [
[1,2,3],
[4,5,6],
[7,8,9]
]
N = 3

Sample Output1
A = [
[1,4,7],
[2,5,8],
[3,6,9]
]

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

    for(int i=0;i<3;i++)
    {
        for(int j=i;j<3;j++) // j=i bcz we only want to follow operation in coloured part of our matrix 
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp; 
        }
    }

    for(int r=0;r<3;r++)
    {
        for(int c=0;c<3;c++)
        {
            cout<<a[r][c]<<" ";
        }
        cout<<endl;
    }

    return 0;
}