using namespace std;
#include <iostream>
class SquareArray {
private:
    int** Array;
    int Length;
public:
    SquareArray(int Number) {
        if (Number > 100) Length = 100;
        else Length = Number;
        Array = new int* [Length];
        for (int i = 0; i < Length; i++) {
            Array[i] = new int[Length];
            for (int j = 0; j < Length; j++) {
                Array[i][j] = 0;
            }
        }
    }
    ~SquareArray() {
        for (int i = 0; i < Length; i++) {
            delete[] Array[i];
        }
        delete[] Array;
    }
    int CountPositiveBelowDiagonal() {
        int count = 0;
        for (int i = 1; i < Length; i++) {
            for (int j = 0; j < i; j++) {
                if (Array[i][j] > 0) {
                    count++;
                }
            }
        }
        return count;
    }
    int CountZerosBelowDiagonal() {
        int count = 0;
        for (int i = 1; i < Length; i++) {
            for (int j = 0; j < i; j++) {
                if (Array[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
    friend ostream& operator << (ostream& os, const SquareArray& Number) {
        for (int i = 0; i < Number.Length; i++) {
            for (int j = 0; j < Number.Length; j++) {
                os << Number.Array[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};
int main(){
    setlocale(LC_ALL, "");
    int Length{};
    cout << "Введити длину массива: ";
    cin >> Length; 
    SquareArray NumberOne(Length); 
    cout << "Количество положительных чисел под главной диагональю = " << NumberOne.CountPositiveBelowDiagonal() << endl;
    cout << "Количество нулей под главной диагональю = " << NumberOne.CountZerosBelowDiagonal() << endl;
}
//По факту задание с функцией вывода положительных чисел всегда будет = 0, поскольку в задании надо инициализировать все элементы массива нулями
//Но всё же сделал функцию для нахождению количества нулей CountZerosBelowDiagonal()