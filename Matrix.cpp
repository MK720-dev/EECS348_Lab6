#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void readMatrixFromFile(const string& filename, vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int& n){
    ifstream file(filename);
    string line;
    int line_count = 0;

    if (file.is_open()){
       
        while(getline(file,line)){

            stringstream ss(line);
            int value;
            vector<int> row;

            if (line_count == 0){
                ss >> value;
                n = value;
                //matrix1.resize(n, vector<int>(n));
                //matrix2.resize(n, vector<int>(n));
            }
            else {
                
                while(ss >> value){
                    row.push_back(value);
                }
                if (line_count >= 1 && line_count <= n){
                    
                    matrix1.push_back(row);
                
                }
                else if (line_count > n && line_count <= (2*n)){
                    matrix2.push_back(row);
                }

            }
            line_count++;
        }
        file.close();
    }
    else{
        cerr << "Unable to open file: " << filename << endl;
    }

}

vector<vector<int>> addMatrices(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int& n){
    vector<vector<int>> result;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for (int j = 0; j < n; j++){
            row.push_back(matrix1[i][j] + matrix2[i][j]);
        }
        result.push_back(row);
    }
    return result;
}

vector<vector<int>> substractMatrices(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int& n){
    vector<vector<int>> result;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for (int j = 0; j < n; j++){
            row.push_back(matrix1[i][j] - matrix2[i][j]);
        }
        result.push_back(row);
    }
    return result;
}

vector<vector<int>> multiplyMatrices(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int& n){
    vector<vector<int>> result;
    
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < n; j++){
            int temp = 0;
            for (int k = 0; k < n; k++){
                temp = temp + matrix1[i][k]*matrix2[k][j];
            }
            row.push_back(temp);
        } 
        result.push_back(row);
    }  
    return result;
}

void printMatrix(vector<vector<int>> matrix){
     for (const auto& row : matrix){
        for (int value: row){
            cout << value << " ";
        }
        cout << endl;
    } 
}

void updateValue(vector<vector<int>>& matrix,int i,int j, int value){
    if (i > 0 && i < matrix.size() && j > 0 and j < matrix[0].size()){
        matrix[i][j] = value;
    }
    else{
        cout << "Index out of range" << endl;
    }
    
}

void getMax(vector<vector<int>> matrix, int n){
    int max = matrix[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }
    cout << "Max elemnet in matrix 1 is: " << max << endl;
}

void transposeMatrix(vector<vector<int>>& matrix, int n){
    for(int i = 0; i < n; i++){ 
        for (int j = i+1; j < n; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main(){
    string filename = "SampleInputFile.txt";
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    int n;

    readMatrixFromFile(filename, matrix1, matrix2, n);

    cout << "Matrix 1 read from file:" << endl;
    printMatrix(matrix1);
    
    cout << "Matrix 2 read from file:" << endl;
    printMatrix(matrix2);

    cout << "Adding Matrix 1 and 2:" << endl;
    vector<vector<int>> addition_result = addMatrices(matrix1, matrix2, n);
    printMatrix(addition_result);

    cout << "Mutliplying Matrix 1 and 2:" << endl;
    vector<vector<int>> multiplication_result = multiplyMatrices(matrix1, matrix2, n);
    printMatrix(multiplication_result);

    cout << "Subtracting Matrix 2 from 1:" << endl;
    vector<vector<int>> substraction_result = substractMatrices(matrix1, matrix2, n);
    printMatrix(substraction_result);

    cout << "Changing value of matrix 1 at index (2,2) to 8" << endl;
    updateValue(matrix1, 1, 1, 8);
    printMatrix(matrix1);

    getMax(matrix1, n);

    transposeMatrix(matrix1, n);
    cout << "Matrix 1 transposed: " << endl;
    printMatrix(matrix1);

}