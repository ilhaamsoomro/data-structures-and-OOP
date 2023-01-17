#include<iostream>
using namespace std;
class matrix {
    private:
    int row;
    int column;
    int** MATRIX;
    public:
    matrix(){
        int row=1;  //initializing values for row and column as 1 so that a matrix exists
        int column=1;
        MATRIX= new int*[row];  //dynamic memory allocation for rows
    for (int i=0;i<row;i++){
        MATRIX[i]= new int[column]; //dynamic memory allocation for columns
    }
    }
    ~matrix(){} //destructor(needs to be written when you write copy constructor)
    matrix(int row, int column){    //create a matrix
        this->row=row;
        this->column=column;
        MATRIX= new int*[row];
    for (int i=0;i<row;i++){
        MATRIX[i]= new int[column];
    }
    }
    matrix(const matrix &copiedmatrix){ //copy constructor(needs to be written when you write pointers)
        row=copiedmatrix.row;
        column=copiedmatrix.column;
        MATRIX=copiedmatrix.MATRIX;
    }
    void setMatrix(int row, int column){    //setter function to resize matrix and give inputs
        this->row=row;
        this->column=column;
        MATRIX= new int*[row];
        for (int i=0;i<row;i++){
        MATRIX[i]= new int[column];
        }
     cout<<"enter elements row-wise: "<<endl;
     for (int j=0;j<row;j++){
         for(int k=0;k<column;k++){
             cin>>MATRIX[j][k];
         }
     }
    }
    void getMatrix(){   //using getter function to print matrix
     for (int j=0;j<row;j++){
         for(int k=0;k<column;k++){
             cout<<MATRIX[j][k]<<" ";
         }
         cout<<endl;
     }
    }
    friend ostream& operator<<(ostream& COUT, matrix& matrixname){ //overloaded cout operator
        COUT<<"the matrix is "<<endl;
        for (int j=0;j<matrixname.row;j++){
             for(int k=0;k<matrixname.column;k++){
              COUT<<matrixname.MATRIX[j][k]<<" ";
            }
            COUT<<endl;
        }
        return COUT;
    }
    void transpose(){   //transpose of a square matrix
        int** temp;
        temp = new int*[row];
        for (int k=0;k<row;k++){
        temp[k]= new int[column];
        }
        for (int i=0; i<column; i++){
            for (int j=0; j<column; j++){
                temp[j][i]=MATRIX[i][j];
            }
            
        }
        cout<<"the transpose of ";
        for (int i=0; i<row; i++){
            for (int j=0; j<column; j++){
                MATRIX[i][j]=temp[i][j];
            }
            
        }
    }
    //major row operations
    void add(int inrow, int addrow){    //add row to row
        for (int i=0; i<column; i++){
            MATRIX[inrow][i]=MATRIX[inrow][i]+MATRIX[addrow][i];
        }
        cout<<"when row "<<addrow<<"is added to row "<<inrow<<", ";

    }
       void sub(int inrow, int addrow){ //sub row from row
        for (int i=0; i<column; i++){
            MATRIX[inrow][i]=MATRIX[inrow][i]-MATRIX[addrow][i];
        }
        cout<<"when row "<<addrow<<" is subtracted from row "<<inrow<<", ";

    }
       void mul(int inrow, int constant){    //multiply row by constant
        for (int i=0; i<column; i++){
            MATRIX[inrow][i]=MATRIX[inrow][i]*constant;
        }
        cout<<"when row "<<inrow<<" is multiplied by constant "<<constant<<", ";

    }
    void rowswap(int swaprow, int withrow){ //swapping two rows
        int* temp;
        temp = new int[column];
        for (int i=0; i<column; i++){
            temp[i]=MATRIX[withrow-1][i];   //to fix indexing we subtract by 1(we can either do that or give inputs of rows as 0,1,2 rather than 1,2,3..)
            MATRIX[withrow-1][i]=MATRIX[swaprow-1][i];
            MATRIX[swaprow-1][i]=temp[i];
        }
        
        cout<<"when row "<<swaprow<<" is swapped with row "<<withrow<<", ";
    }
};
    int main(){
        matrix M;
        M.setMatrix(3,3);
        cout<<M;
        M.transpose();
        cout<<M;
        M.add(0,1);
        cout<<M;
        M.sub(0,1);
        cout<<M;
        M.mul(0,1);
        cout<<M;
        M.rowswap(1,2);
        cout<<M;
        return 0;
    }
    
