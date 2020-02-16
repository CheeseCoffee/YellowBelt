#include <iostream>
#include <vector>
using namespace std;
class Matrix{
public:
    Matrix (){
    }
    Matrix (int num_rows,int num_cols){
    }
    int GetNumRows(){
        return numRow;
    }
    int GetNumColumns(){
        return numColumn;
    }
    void Reset(int new_numRow,int new_)
    const At()
private:
    vector<int>data;
    int numRow;
    int numColumn;
};
// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
