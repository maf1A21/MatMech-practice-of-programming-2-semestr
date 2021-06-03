#include <iostream>
#include<vector>
using namespace std;

template<typename T>
class Matrix
{
private:
    T** M;
    unsigned rows;
    unsigned cols;
public:
    Matrix();
    ~Matrix();
    Matrix(unsigned _n, unsigned _m);
    Matrix(const Matrix  &_M);
    T& operator()(unsigned row, unsigned col);
    T operator()(unsigned row, unsigned col ) const ;
    Matrix<T> &operator=(const Matrix<T> &_M);
    Matrix<T> operator+(const Matrix<T> &_M);
    Matrix<T> operator-(const Matrix<T> &_M);
    Matrix<T> operator*(const Matrix<T> &_M);
    Matrix<T> operator*(const double d);
    int get_rows() const;
    int get_cols() const;
    Matrix<T> transpose();
};

template<typename T>
T& Matrix<T>::operator()(unsigned i, unsigned j)
{
    return M[i][j];
}
template<typename T>
T Matrix<T>::operator()(unsigned i, unsigned j) const
{
    return M[i][j];
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const double d)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            M[i][j] *= d;
        }
    }
    return *this;
}
template<typename T>
Matrix<T>::Matrix()
{
    rows = cols  = 0;
    M = nullptr;
}

template<typename T>
Matrix<T>::Matrix(unsigned _m, unsigned _n)
{
    rows = _m;
    cols = _n;

    M = (T**) new T*[rows];

    for(int i = 0; i < rows; i++)
    {
        M[i] = (T*)new T[cols];
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            M[i][j] = 0;
        }
    }
}
template<typename T>
Matrix<T>::Matrix(const Matrix<T> &_M)
{
    rows = _M.rows;
    cols = _M.cols;

    M = (T**) new T*[rows];

    for(int i = 0; i < rows; ++i)
    {
        M[i] = (T*) new T[cols];
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            M[i][j] = _M(i, j);
        }
    }
}



template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &_M)
{
    if(cols > 0)
    {
        for(int i = 0; i < rows; ++i)
        {
            delete[] M[i];
        }
    }
    if(rows > 0)
    {
        delete[] M;
    }

    rows = _M.rows;
    cols = _M.cols;
    M = (T**) new T*[rows];
    for(int i = 0; i < rows; ++i)
    {
        M[i] = (T*) new T[cols];
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            M[i][j] = _M(i,j);
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> N(cols, rows);
    for(int i = 0; i < cols; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
          N.M[i][j] = M[j][i];
        }
    }
    return N;
}

template<typename T>
Matrix<T>::~Matrix()
{
    if(cols > 0)
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] M[i];
        }
    }
    if(rows > 0)
    {
        delete[] M;
    }
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &_M)
{
    try
    {
        if( (rows !=_M.rows) || (cols != _M.cols))
        {
            throw "Can't do this operation";
        }
        else
        {
            Matrix<T> S(rows,cols);
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols;j++)
                {
                    S.M[i][j] = M[i][j] + _M(i,j);
                }
            }
            return S;
        }

    }
    catch(const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
        return Matrix<int>(0,0);
    }

}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &_M)
{
    try
    {
        if( (rows !=_M.rows) || (cols != _M.cols))
        {
            throw "Can't do this operation";
        }
        else
        {
            Matrix<T> S(rows,cols);
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols;j++)
                {
                    S.M[i][j] = M[i][j] - _M(i,j); // _M.M[i][j]
                }
            }
            return S;
        }

    }
    catch(const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
        return Matrix<int>(0,0);
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &_M)
{
    try
    {
        if(cols != _M.rows)
        {
            throw "Can't do this operation.";
        }

        Matrix<T> P(rows, _M.cols);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < _M.cols ; j++)
            {
                for(int k = 0; k < cols; k++)
                {
                    P.M[i][j] += M[i][k] * _M.M[k][j];
                }
            }
        }
        return P;
    }
    catch(const char* exception)
    {
        std::cerr << "Error: " << exception << "\n";
        return Matrix<int>(0,0);
    }

}

template<typename T>
int Matrix<T>::get_rows() const
{
    return rows;
}

template<typename T>
int Matrix<T>::get_cols() const
{
    return cols;
}

template<typename T>
class Matrix<std::vector<T>> : public Matrix<T>
{
private:
    T*** M;
    unsigned cols;
    unsigned rows;
    unsigned high;
public:
    Matrix(unsigned m, unsigned n, unsigned k)
    {
        rows = m;
        cols = n;
        high = k;
        M = new T**[rows];

        for(int i = 0; i < rows; ++i)
        {
            M[i] = new T*[cols];
            for(int j = 0; j < cols; ++j)
            {
                M[i][j] =  new T[high];
            }
        }


        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                for(int k = 0; k < high; ++k)
                {
                    M[i][j][k] = 0;
                }
            }
        }
    }
    ~Matrix()
    {
        if(high > 0)
        {
            for(int i = 0; i < rows; ++i)
            {
                for(int j = 0; j < cols; ++j)
                {
                    delete M[i][j];
                }
            }
        }
        if(cols > 0)
        {
            for(int i = 0; i < rows; ++i)
            {
                delete[] M[i];
            }
        }
        if(rows > 0)
        {
            delete[] M;
        }
    }

    T& operator()(unsigned row, unsigned col, unsigned h){
        return M[row][col][h];
    }
    T operator()(unsigned row, unsigned col, unsigned h) const
    {
        return  M[row][col][h];
    }
    Matrix<std::vector<T>> &operator*(const double d)
    {
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                for(int k = 0; k < high; ++k)
                {
                    M[i][j][k] *= d;
                }
            }
        }
        return *this;
    }

    Matrix<vector<T>> &operator=(const Matrix<vector<T>> &_M)
    {
        if(high > 0)
        {
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    delete[] M[i][j];
                }
            }
        }
        if(cols > 0)
        {
            for(int i = 0; i < rows; i++)
            {
                delete[] M[i];
            }
        }
        if(rows > 0)
        {
            delete[] M;
        }

        rows = _M.rows;
        cols = _M.cols;
        high = _M.high;

        M = new T**[rows];

        for(int i = 0; i < rows; i++)
        {
            M[i] = new T*[cols];
            for(int j = 0; j < cols; j++)
            {
                M[i][j] =  new T[high];
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                for(int k = 0; k < high; k++)
                {
                    M[i][j][k] = _M(i,j,k);
                }
            }
        }
        return *this;
    }
    Matrix<vector<T>> operator+(const Matrix<vector<T>> &_M)
    {
        try
        {
            if((rows != _M.get_rows() ) || (cols != _M.get_cols()) || (high != _M.get_high()))
            {
                throw "different sizes";
            }
            Matrix<std::vector<T>> S(rows, cols, high);
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    for(int k = 0; k < high; k++)
                    {
                        S.M[i][j][k] = M[i][j][k] + _M(i,j,k);
                    }
                }
            }
            return S;

        }
        catch(const char* exception)
        {
            std::cerr << "Error: " << exception << '\n';
            return M(0,0,0);
        }

    }
    Matrix<std::vector<T>> operator-(const Matrix<std::vector<T>> &_M)
    {
        try
        {
            if((rows != _M.get_rows() ) || (cols != _M.get_cols()) || (high != _M.get_high()))
            {
                throw "different sizes";
            }
            Matrix<std::vector<T>> S(rows, cols, high);
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    for(int k = 0; k < high; k++)
                    {
                        S.M[i][j][k] = M[i][j][k] - _M(i,j,k);
                    }
                }
            }
            return S;

        }
        catch(const char* exception)
        {
            std::cerr << "Error: " << exception << '\n';
            return M(0,0,0);
        }
    }

    int get_high() const
    {
        return high;
    }
    int get_rows() const
    {
        return rows;
    }
    int get_cols() const
    {
        return cols;
    }

};

int main()
{
  return 0;
}
