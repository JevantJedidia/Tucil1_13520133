#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <unistd.h>
using namespace std;

void display2DVector(vector<vector<char>> vec){
    for (int i=0;i<vec.size();i++){
        for (int j=0;j<vec[0].size();j++){
            cout << vec[i][j];
            if (j < vec[0].size()-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}

void findSolution (vector<vector<char>> puzzle, int row, int col, int length, int direction){
    vector<vector<char>> solution(puzzle.size(), vector<char>(puzzle[0].size(), '-'));
    switch (direction){
        case 1:
            while (length > 0){
                solution[row][col] = puzzle[row][col];
                row--;
                col--;
                length--;
            }
            break;
        case 2:
            while (length > 0){
                solution[row][col] = puzzle[row][col];
                row--;
                length--;
            }
            break;
        case 3:
            while (length > 0){
                solution[row][col] = puzzle[row][col];
                row--;
                col++;
                length--;
            }
            break;
        case 4:
            while (length > 0){
                solution[row][col] = puzzle[row][col];
                col--;
                length--;
            }
            break;
        case 6:
            while (length > 0){
                solution[row][col] = puzzle[row][col];
                col++;
                length--;
            }
            break;
        case 7:
            while (length > 0){
                solution[row][col] = puzzle[row][col];
                row++;
                col--;
                length--;
            }
            break;
        case 8:
            while (length > 0){
                solution[row][col] = puzzle[row][col];
                row++;
                length--;
            }
            break;
        case 9:
            while (length > 0){
                solution[row][col] = puzzle[row][col];
                row++;
                col++;
                length--;
            }
            break;
    }
    display2DVector(solution);
}

void wordSearch (vector<vector<char>> puzzle, string word, int *ctr) {
    bool found = false;
    int length = word.length(),row,col,len,direction,i,j;

    i = 0;
    while ((i<puzzle.size()) and !found){
        j = 0;
        while ((j<puzzle[0].size()) and !found){
            *ctr += 1;
            if (puzzle[i][j] == word[0]){
                if ((j+1-length >= 0) and (i+1-length >= 0) and !found){
                    found = true;
                    direction = 1;
                    row = i;
                    col = j;
                    for (int len=0; len<length; len++){
                        *ctr += 1;
                        if (puzzle[row][col] != word[len]){
                            found = false;
                            direction = 0;
                            break;
                        }
                        else{
                            row -= 1;
                            col -= 1;
                        }
                    }
                }
                if ((i+1-length >= 0) and !found){
                    found = true;
                    direction = 2;
                    row = i;
                    col = j;
                     for (int len=0; len<length; len++){
                        *ctr += 1;
                        if (puzzle[row][col] != word[len]){
                            found = false;
                            direction = 0;
                            break;
                        }
                        else{
                            row -= 1;
                        }
                    }
                }
                if ((i+1-length >= 0) and (j+length-1 < puzzle[0].size()) and !found){
                    found = true;
                    direction = 3;
                    row = i;
                    col = j;
                     for (int len=0; len<length; len++){
                        *ctr += 1;
                        if (puzzle[row][col] != word[len]){
                            found = false;
                            direction = 0;
                            break;
                        }
                        else{
                            row -= 1;
                            col += 1;
                        }
                    }
                }
                if ((j+1-length >= 0) and !found){
                    found = true;
                    direction = 4;
                    row = i;
                    col = j;
                     for (int len=0; len<length; len++){
                        *ctr += 1;
                        if (puzzle[row][col] != word[len]){
                            found = false;
                            direction = 0;
                            break;
                        }
                        else{
                            col -= 1;
                        }
                    }
                }
                if ((j+length-1 < puzzle[0].size()) and !found){
                    found = true;
                    direction = 6;
                    row = i;
                    col = j;
                     for (int len=0; len<length; len++){
                        *ctr += 1;
                        if (puzzle[row][col] != word[len]){
                            found = false;
                            direction = 0;
                            break;
                        }
                        else{
                            col += 1;
                        }
                    }
                }
                if ((j+1-length >= 0) and (i+length-1 < puzzle.size()) and !found){
                    found = true;
                    direction = 7;
                    row = i;
                    col = j;
                    for (int len=0; len<length; len++){
                        *ctr += 1;
                        if (puzzle[row][col] != word[len]){
                            found = false;
                            direction = 0;
                            break;
                        }
                        else{
                            row += 1;
                            col -= 1;
                        }
                    }
                }
                if ((i+length-1 < puzzle.size()) and !found){
                    found = true;
                    direction = 8;
                    row = i;
                    col = j;
                     for (int len=0; len<length; len++){
                        *ctr += 1;
                        if (puzzle[row][col] != word[len]){
                            found = false;
                            direction = 0;
                            break;
                        }
                        else{
                            row += 1;
                        }
                    }
                }
                if ((i+length-1 < puzzle.size()) and (j+length-1 < puzzle[0].size()) and !found){
                    found = true;
                    direction = 9;
                    row = i;
                    col = j;
                     for (int len=0; len<length; len++){
                        *ctr += 1;
                        if (puzzle[row][col] != word[len]){
                            found = false;
                            direction = 0;
                            break;
                        }
                        else{
                            row += 1;
                            col += 1;
                        }
                    }
                }
            }
            j++;
        }
        i++;
    }
    findSolution(puzzle,i-1,j-1,length,direction);
}

int main() {
    char text;
    int ctr = 0;
    string filename, fileloc, key;
    vector<char> rows;
    vector<vector<char>> puzzle;

    using clock = chrono::system_clock;
    using sec = chrono::duration<double>;

    cout << "Input file name (in .txt): ";
    cin >> filename;
    fileloc = "../test/" + filename;
    ifstream ifile;
    ifile.open(fileloc);
    if (!ifile){
        fileloc = "./test/" + filename;
    }
    
    ifile.close();

    ifstream file(fileloc);
    while (file.get(text)){
        if (text == '\n'){
            if (rows.empty()){
                break;
            }
            puzzle.push_back(rows);
            rows.clear();
        }
        else if (text != ' '){
            rows.push_back(text);
        }
    }

    const auto before = clock::now();

    while(getline(file, key)){
        cout << key << endl;
        wordSearch(puzzle,key,&ctr);
        cout << endl;
    }

    const sec duration = clock::now() - before;
    cout << "Waktu eksekusi program: " << duration.count() << "s" << endl;
    cout << "Jumlah total perbandingan huruf: " << ctr << endl;

    file.close();
}