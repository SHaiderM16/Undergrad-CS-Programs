#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Matrix
{
private:
    vector<vector<T>> matrix;
    int rows, columns;

public:
    Matrix(int r, int c) : rows(r), columns(c), matrix(r, vector<T>(c)) {}

    int getRows()
    {
        return rows;
    }
    int getColumns()
    {
        return columns;
    }

    T getValue(int i, int j)
    {
        return matrix[i][j];
    }
    void setValue(int i, int j, T value)
    {
        matrix[i][j] = value;
    }

    virtual void display() = 0;

    virtual ~Matrix() {}
};

class IntMatrix : public Matrix<int>
{
public:
    IntMatrix(int r, int c) : Matrix<int>(r, c) {}

    void display() override
    {
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getColumns(); j++)
            {
                cout << getValue(i, j) << ' ';
            }
            cout << endl;
        }
    }

    IntMatrix *operator+(IntMatrix secondMatrix)
    {
        IntMatrix result(getRows(), getColumns());
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getColumns(); j++)
            {
                result.setValue(i, j, this->getValue(i, j) + secondMatrix.getValue(i, j));
            }
        }
        return &result;
    }

    IntMatrix *operator-(IntMatrix secondMatrix)
    {
        IntMatrix result(getRows(), getColumns());
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getColumns(); j++)
            {
                result.setValue(i, j, this->getValue(i, j) - secondMatrix.getValue(i, j));
            }
        }
        return &result;
    }

    IntMatrix *operator*(IntMatrix secondMatrix)
    {
        if (getColumns() != secondMatrix.getRows())
        {
            cout << "Dimensions not eligible for multiplication" << endl;
        }

        IntMatrix result(getRows(), secondMatrix.getColumns());
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < secondMatrix.getColumns(); j++)
            {
                result.setValue(i, j, 0);
                for (int k = 0; k < getColumns(); k++)
                {
                    result.setValue(i, j, result.getValue(i, j) + this->getValue(i, k) * secondMatrix.getValue(k, j));
                }
            }
        }
        return &result;
    }
};

class DoubleMatrix : public Matrix<double>
{
public:
    DoubleMatrix(int r, int c) : Matrix<double>(r, c) {}

    void display() override
    {
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getColumns(); j++)
            {
                cout << getValue(i, j) << ' ';
            }
            cout << endl;
        }
    }

    DoubleMatrix *operator+(DoubleMatrix secondMatrix)
    {
        DoubleMatrix result(getRows(), getColumns());
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getColumns(); j++)
            {
                result.setValue(i, j, this->getValue(i, j) + secondMatrix.getValue(i, j));
            }
        }
        return &result;
    }

    DoubleMatrix *operator-(DoubleMatrix secondMatrix)
    {
        DoubleMatrix result(getRows(), getColumns());
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getColumns(); j++)
            {
                result.setValue(i, j, this->getValue(i, j) - secondMatrix.getValue(i, j));
            }
        }
        return &result;
    }

    DoubleMatrix *operator*(DoubleMatrix secondMatrix)
    {
        if (getColumns() != secondMatrix.getRows())
        {
            cout << "Dimensions not eligible for multiplication" << endl;
        }

        DoubleMatrix result(getRows(), secondMatrix.getColumns());
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < secondMatrix.getColumns(); j++)
            {
                result.setValue(i, j, 0);
                for (int k = 0; k < getColumns(); k++)
                {
                    result.setValue(i, j, result.getValue(i, j) + this->getValue(i, k) * secondMatrix.getValue(k, j));
                }
            }
        }
        return &result;
    }
};

int main()
{
    IntMatrix intMat1(2, 2);
    IntMatrix intMat2(2, 2);

    IntMatrix *intMatSum = intMat1 + intMat2;

    intMatSum->display();

    delete intMatSum;

    DoubleMatrix doubleMat1(2, 2);
    DoubleMatrix doubleMat2(2, 2);

    DoubleMatrix *doubleMatSum = doubleMat1 + doubleMat2;

    doubleMatSum->display();

    delete doubleMatSum;

    return 0;
}