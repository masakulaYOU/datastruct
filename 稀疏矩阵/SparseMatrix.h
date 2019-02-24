#include <iostream>
#include <cstdlib>
#include "Trituple.h"

// ������
template <class T>
class SparseMatrix;

// template friend operator����
template <class T>
std::ostream& operator << (std::ostream& os, SparseMatrix<T>& M);

template <class T>
std::istream& operator >> (std::istream& in, SparseMatrix<T>& M);

//template <class T>
//SparseMatrix<T>& operator = (SparseMatrix<T>& M);
// ϡ�����������
template <class T>
class SparseMatrix
{
    friend std::ostream& operator << <> (std::ostream& os, SparseMatrix& M);
    friend std::istream& operator >> <> (std::istream& in, SparseMatrix& M);
private:
    int Rows, Cols, Terms;
    Trituple<T>* smArray;
    int maxTerms;
public:
    SparseMatrix(int maxSz = defaultSize);
    SparseMatrix(SparseMatrix<T>& x);
    ~SparseMatrix() { delete[] smArray; }
    SparseMatrix<T>& operator = (SparseMatrix& M);
    // ����ת��
    SparseMatrix<T> transpose();
    // �������
    SparseMatrix<T> add(SparseMatrix<T>& b);
    // �������
    SparseMatrix<T> multiply(SparseMatrix<T>& b);
};


template <class T>
SparseMatrix<T>::SparseMatrix(int maxSz): maxTerms(maxSz)
{
    if (maxSz < 1) { std::cerr << "�����ʼ��ʧ��" << std::endl; exit(1);}
    smArray = new Trituple<T>[maxSz];
    if (smArray == NULL) { std::cerr << "�洢�������" << std::endl; exit(1); }

    Rows = Cols = Terms = 0;
}


template <class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T>& x)
{
    Rows = x.Rows; Cols = x.Cols; Terms = x.Terms;
    maxTerms = x.maxTerms;
    smArray = new Trituple<T>[maxTerms];
    if (smArray == NULL) { std::cerr << "�洢�������" << std::endl; exit(1); }
    for(int i = 0; i < maxTerms; i++)
    {
        smArray[i] = x.smArray[i];
    }
}

template <class T>
std::ostream& operator << (std::ostream& os, SparseMatrix<T>& M)
{
    os << "rows = " << M.Rows << std::endl;
    os << "cols = " << M.Cols << std::endl;
    os << "Nonzero terms = " << M.Terms << std::endl;

    for(int i = 0; i < M.Terms; i++)
    {
        os << "M[" << M.smArray[i].row << "][" << M.smArray[i].col << "]="
            << M.smArray[i].value << std::endl;
    }

    return os;
}

template <class T>
std::istream& operator >> (std::istream& in, SparseMatrix<T>& M)
{
    std::cout << "Enter numbers of rows, columns, and terms" << std::endl;
    in >> M.Rows >> M.Cols >> M.Terms;
    if (M.Terms > M.maxTerms)
    {
        std::cerr << "Number of terms overflow!" << std::endl;
        exit(1);
    }

    for(int i = 0; i < M.Terms; i++)
    {
        std::cout << "Enter row, column, and value of term: " << i + 1 << std::endl;
        in >> M.smArray[i].row >> M.smArray[i].col >> M.smArray[i].value;
    }
    return in;
}

/*
// �����ת��(����ת��)
// ???
template <class T>
SparseMatrix<T> SparseMatrix<T>::transpos()
{
    int* rowSize = new int[Cols];   // �������飬ͳ�Ƹ��з���Ԫ�صĸ���
    int* rowStart = new int[Cols];  // �������飬Ԥ��ת�ú���д��λ��
    SparseMatrix<T> b(maxTerms);    // ���ת�ý��
    b.Rows = Cols; b.Cols = Rows; b.Terms = Terms;

    if (Terms > 0)
    {
        int i, j;
        for(i = 0; i < Cols; i++) rowSize[i] = 0;
        for(i = 0; i < Terms; i++) rowSize[smArray[i].col]++;   // ����Ԫ��������ͳ�Ƹ���
        rowStart[0] = 0;
        for(i = 1; i < Cols; i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        for(i = 0; i < Terms; i++)  //��a��b����
        {
            j = rowStart[smArray[i].col];   // ��i������Ԫ����b��Ӧ�ŵ�λ��
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;

            rowStart[smArray[i].col]++;
        }
    }
    delete[] rowSize;
    delete[] rowStart;
    return b;
}

*/

// ����ת��(һ�㷽��)
template <class T>
SparseMatrix<T> SparseMatrix<T>::transpose()
{
    SparseMatrix<T> b(maxTerms);
    b.Rows = Cols;
    b.Cols = Rows;
    b.Terms = Terms;

    if (Terms > 0)
    {
        int k, i, currentB = 0; //���λ��ָ��
        for( k = 0; k < Cols; k++)
        {
            for(i = 0; i < Terms; i++)
            {
                if(smArray[i].col == k)
                {
                    b.smArray[currentB].row = k;
                    b.smArray[currentB].col = smArray[i].row;
                    b.smArray[currentB].value = smArray[i].value;
                    currentB++;
                }
            }
        }
    }
    return b;
}

// ϡ���������
template <class T>
SparseMatrix<T> SparseMatrix<T>::add(SparseMatrix<T>& b)
{
    SparseMatrix<T> result(Rows * Cols);
    if (Rows != b.Rows || Cols != b.Cols)
    {
        std::cout << "Imcompatible matrices" << std::endl;  //�������Ͳ�ƥ��
        return result;
    }

    int i =0, j = 0, index_a, index_b;
    result.Terms = 0;
    while(i < Terms && j <b.Terms)
    {
        index_a = Cols * smArray[i].row + smArray[i].col;
        index_b = Cols * b.smArray[i].row + b.smArray[i].col;

        if (index_a < index_b)  // smArray[i]��b.smArray[i]֮ǰ
        {
            result.smArray[result.Terms] = smArray[i];
            i++;
        }
        else if (index_a > index_b)
        {
            result.smArray[result.Terms] = b.smArray[j];
            j++;
        }
        else
        {
            result.smArray[result.Terms] = smArray[i];
            result.smArray[result.Terms].value = smArray[i].value + b.smArray[i].value;
            i++; j++;
        }
        result.Terms++;
    }
    // ����ʣ��Ԫ��
    for(;i < Terms; i++) result.smArray[result.Terms++] = smArray[i];
    for(;j < b.Terms; j++) result.smArray[result.Terms++] = b.smArray[j];
    return result;
}


// ϡ��������
/*
    C[i][j] = Sigma[k=0->n-1] A[i][k]*B[k][j]

    c_ij = sum_{k=0}^n a_ik * b_kj
*/

template <class T>
SparseMatrix<T> SparseMatrix<T>::multiply(SparseMatrix<T>& b)
{
    SparseMatrix<T> result(Rows, b.Cols);
    if(Cols != b.Rows)
    {
        std::cerr << "Incompatible matrices" << std::endl;
        return result;
    }
    // �ռ䲻��
    if (Terms == maxTerms || b.Terms == maxTerms)
    {
        std::cerr << "One additional space in a or b needed" << std::endl;
        return result;
    }

    int* rowSize = new int[b.Rows];
    int* rowStart = new int[b.Rows + 1];
    T* temp = new T[b.Cols];

    int i, current, lastInResult, rowA, colA, colB;
    for(i = 0; i < b.Rows; i++) rowSize[i] = 0;
    for(i = 0; i < b.Terms; i++) rowStart[b.smArray[i].row]++;

    rowStart[0] = 0;
    for(i = 1; i <= b.Rows; i++) rowStart[i] = rowStart[i - 1] + rowSize[i - 1];

    current = 0;
    lastInResult = -1;

    while(current < Terms)
    {
        rowA = smArray[current].row;
        for(i = 0; i < b.Cols; i++) temp[i] = 0;

        while(current < Terms && smArray[current].row == rowA)
        {
            colA = smArray[current].col;
            for(i = rowStart[colA]; i < rowStart[colA + 1]; i++)
            {
                colB = b.smArray[i].col;
                temp[colB] += smArray[current].value * b.smArray[i].value;
            }
            current++;
        }
        for(i = 0; i < b.Cols; i++)
        {
            if(temp[i] != 0)
            {
                lastInResult++;
                result.smArray[lastInResult].row = rowA;
                result.smArray[lastInResult].col = i;
                result.smArray[lastInResult].value = temp[i];
            }
        }

        result.Rows = Rows;result.Cols = b.Cols;
        result.Terms = lastInResult + 1;
        delete[] rowSize;
        delete[] rowStart;
        delete[] temp;

        return result;
    }
}


// �Ⱥ�����
template <class T>
SparseMatrix<T>& SparseMatrix<T>::operator = (SparseMatrix& M)
{
    SparseMatrix<T> temp;
    temp.Rows = M.Rows; temp.Cols = M.Cols; temp.Terms = M.Terms;
    temp.maxTerms = M.maxTerms;
    temp.smArray = new Trituple<T>[M.maxTerms];
    if(temp.smArray == NULL) { std::cerr << "�洢�������" << std::endl; exit(1); }
    for(int i = 0; i < M.maxTerms; i++)
    {
        temp.smArray[i] = M.smArray[i];
    }
    return temp;
}




