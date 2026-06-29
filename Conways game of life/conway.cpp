#include <iostream>
#include <vector>

using namespace std;

int rows, cols;
int inrows, incols;

string input ;

//counts the value of the neghbour cells

int countNeighbors(const vector<vector<int>>& grid, int row, int col, int rows, int cols)
{
    int neighbors = 0;

    for(int di = -1; di <= 1; di++)
    {
        for(int dj = -1; dj <= 1; dj++)
        {
            if(di == 0 && dj == 0)
                continue;

            int ni = row + di;
            int nj = col + dj;

            if(ni >= 0 && ni < rows &&
               nj >= 0 && nj < cols)
            {
                neighbors += grid[ni][nj];
            }
        }
    }

    return neighbors;
}


int main(){

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> oldgrid(rows, vector<int>(cols));
    vector<vector<int>> newgrid(rows, vector<int>(cols));      


    // Input

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            oldgrid[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newgrid[i][j] = 0;
        }
    }

    do{
        cout << "Input the location of the starting lives cell." << endl;
        cout << "Input row number:";
        cin >> inrows;
        inrows = inrows-1;
        cout << "Input collum number:";
        cin >> incols;
        incols = incols - 1;
        
        if(inrows < 0 || inrows >= rows || incols < 0 || incols >= cols){
            cout << "Invalid location!\n";
            continue;
        }
    
        oldgrid[inrows][incols] = 1;
        cout << "Do you wanna add another live cell?(Y/N)";
        cin >> input;
    }
    while(input == "Y" || input == "y");

    cout << endl << "Initial state:" << endl;
    cout << "Live cells are represented with 0.";
    cout << endl << "Grid:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << endl;
        for (int j = 0 ; j < cols; j++){
            if(oldgrid[i][j]==1){
                cout << "0"; 
            }
            else{
                cout << "."; 
            }
        }
    }    
    cout << endl;
    system("pause");
    
    //start of the generation cycle

    do{
    
    // Conways game of life rules

    for(int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            
            int neighbors = countNeighbors(oldgrid, i, j, rows, cols);
            
            if(oldgrid[i][j] == 1){
            
                if(neighbors == 2 || neighbors == 3)
                {
                    newgrid[i][j]=1;
                }
                else {
                    newgrid[i][j]=0;
                } 
        
            }
            else if (oldgrid[i][j] == 0)
            {
                if (neighbors == 3)
                {
                    newgrid[i][j] = 1;
                }
                else{
                    newgrid[i][j] = 0;
                }    
            }
                
        }
    }

    // Output

    cout << endl << "Grid:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << endl;
        for (int j = 0 ; j < cols; j++){
            if(newgrid[i][j]==1)
                cout << "0";
            else
                cout << ".";  
        }
    }

    //Next generation

    oldgrid = newgrid;

    cout << endl << "Next generation? (Y/N): ";
    cin >> input;


    }
    while(input == "Y" || input == "y");
return 0;
}