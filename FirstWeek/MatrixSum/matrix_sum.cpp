#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
using namespace std;
class Matrix{
public:
    Matrix (){
        numRow=0;
        numCol=0;
    }
    Matrix (int new_numRow, int new_numCol){
        Reset(new_numRow,new_numCol);
    }
    int GetNumRows() const {
        return numRow;
    }
    int GetNumColumns() const {
        return numCol;
    }
    void Reset(int new_numRow,int new_numCol){
        if (new_numRow < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (new_numCol < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        if (new_numRow==0||new_numCol==0){
            new_numCol=new_numRow=0;
        }
        numRow=new_numRow;
        numCol=new_numCol;
        data.assign(new_numRow*new_numCol,0);
    }

    int At(int x, int y) const {
        if(x<0||x>numRow-1){throw out_of_range("invalid Row");}
        if(y<0||y>numCol-1){throw out_of_range("invalid Col");}
        return data[numCol*x+y];
    }
    int& At(int x, int y){
        if(x<0||x>numRow-1){throw out_of_range("invalid Row");}
        if(y<0||y>numCol-1){throw out_of_range("invalid Col");}
        return data[numCol * x + y];
    }
private:
    vector<int>data;
    int numRow;
    int numCol;
};
ostream& operator <<(ostream& stream, Matrix matrix){
    int r=matrix.GetNumRows();
    int c=matrix.GetNumColumns();
    stream<<r<<" "<<c<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (j> 0) {
                stream << " ";
            }
            const int x=matrix.At(i,j);
            stream<<x;
        }
        stream<<endl;
    }
    return stream;
}
istream& operator >>(istream& stream, Matrix& matrix){
    int x,y;
    stream>>x>>y;
    matrix.Reset(x,y);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            stream>>matrix.At(i,j);
        }
    }
    return stream;
}
Matrix operator +(const Matrix& matrix1, const Matrix& matrix2){
    int r1=matrix1.GetNumRows();
    int c1=matrix1.GetNumColumns();
    int r2=matrix2.GetNumRows();
    int c2=matrix2.GetNumColumns();
    if (r1 != r2) {
        throw invalid_argument("Mismatched number of rows");
    }

    if (c1 != c2) {
        throw invalid_argument("Mismatched number of columns");
    }
    Matrix matrix3(r1,c1);
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            matrix3.At(i,j)=matrix1.At(i,j)+matrix2.At(i,j);
        }
    }
    return matrix3;
}

bool operator ==(const Matrix& matrix1,const Matrix& matrix2){
    int r1=matrix1.GetNumRows();
    int c1=matrix1.GetNumColumns();
    int r2=matrix2.GetNumRows();
    int c2=matrix2.GetNumColumns();
    if (r1 != r2) {
        return false;
    }

    if (c1 != c2) {
        return false;
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            if(matrix1.At(i,j)!=matrix2.At(i,j)){
                return false;
            }
        }
    }
    return true;
}
// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {
    stringstream my_ss("3 5\n"
                       "6 4 -1 9 8\n"
                       "12 1 2 9 -5\n"
                       "-4 0 12 8 6\n"
                       "\n"
                       "3 5\n"
                       "5 1 0 -8 23\n"
                       "14 5 -6 6 9\n"
                       "8 0 5 4 1\n");
    //stringstream my_ss("0 0\n"
                       //"\n"
                       //"0 0\n");
    Matrix one;
    Matrix two;
    my_ss >> one >> two;
    cout<<one.At(2,2);

    cout << one + two << endl;
    return 0;
}
