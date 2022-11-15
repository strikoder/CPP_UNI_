// Mohamad Alamin Yassin HKH-01-20 c++ homework exercise 1
#include <iostream>
using namespace std;
class matrix;
class vector
{
    // Private variables
    int dim;
    double *coor;
    static int counterVec;
    // Public variables
public:
    friend vector vector_matrix (vector vecto, matrix matri);
    int num;


    vector()
    {
        dim = 1;
        num = counterVec++;
        coor = new double [dim];
        *coor = 1;
        cout<<"the vector No "<<num<<" was successfully created without any parameters"<<endl;
    }

    vector(int dim_n)
    {
        dim = dim_n;
        num = counterVec++;
        coor = new double [dim];
        for (int i = 0; i<dim; i++)
            coor[i] = 0;
        cout<<"the vector No "<<num<<" was successfully created with 1 parameter"<<endl;
    }
    vector(int dim_n, double * coord)
    {
        dim = dim_n;
        num = counterVec++;
        coor = new double [dim];
        for(int i=0; i<dim; i++)
            coor[i] = coord[i];
        cout<<"the vector No "<<num<<" was successfully created with 2 parameters"<<endl;
    }
    vector (const vector &vecto)
    {
        dim = vecto.dim;
        num = counterVec++;
        coor = new double [dim];
        for (int i=0; i<dim; i++)
            coor[i] = vecto.coor[i];
        cout<<"the vector No "<<num<<" is created as an instance of vector No "<<vecto.num<<endl;
    }
    ~ vector()
    {

        delete [] coor;
        cout<<"the vector No "<<num<<" was successfully deleted"<<endl;
    }

    vector operator + (const vector ma);

    vector operator - (const vector ma);

    vector operator - ();

    vector operator * ( double k);

    void  operator = (const vector vecto);

    float scalar (vector vecto)
    {

        float answer = 0;
        for  (int i = 0; i<dim; i++)
            answer += (coor[i]*vecto.coor[i]);
        return answer;
    }
    void print()
    {
        for (int i=0; i<dim; i++)
            cout<<coor[i]<<" ";
        cout<<endl;
    }

};
vector vector :: operator + (const vector ma)
{
    vector answer = ma;
    for (int i=0; i<dim; i++)
        answer.coor[i] = coor[i] + ma.coor[i];
    return answer;
}
vector vector :: operator - (const vector ma)
{
    vector answer = ma;
    for (int i=0; i<dim; i++)
        answer.coor[i] = coor[i] - ma.coor[i];
    return answer;
}
vector vector :: operator * ( double k)
{
    vector answer(dim);
    for (int i=0; i<dim; i++)
        answer.coor[i] = coor[i]*k;
    return answer;
}
vector vector :: operator - ()
{
    vector answer (dim);
    for  (int i = 0; i<dim; i++)
        answer.coor[i] += coor[i]*(-1);
    return answer;
}
void vector :: operator = (const vector vecto)
{
    for (int i=0; i<dim; i++)
        coor[i] = vecto.coor[i];
    return;
}
class matrix
{
    int dim_x;
    int dim_y;
    double *coor;
    static int counterMat;
public:
    friend vector vector_matrix (vector vecto, matrix matri);
    int num;
    matrix()
    {
        dim_x = 1;
        dim_y = 1;
        num = counterMat++;
        coor = new double [1];
        *coor = 1;
        cout<<"the matrix No "<<num<<" was successfully created without any parameters"<<endl;
    }
    matrix (int dim_x_n, int dim_y_n)
    {
        dim_x = dim_x_n;
        dim_y = dim_y_n;
        num = counterMat++;
        coor = new double [dim_x*dim_y];
        for (int i = 0; i < (dim_x*dim_y); i++)
            coor[i] = 0;
        cout<<"the matrix No "<<num<<" was successfully created with 2 parameters "<<endl;
    }
    matrix(int dim_n_x, int dim_n_y, double * coord)
    {
        dim_x = dim_n_x;
        dim_y = dim_n_y;
        num = counterMat++;
        coor = new double [dim_x*dim_y];
        for(int i=0; i<(dim_x*dim_y); i++)
            coor[i] = coord[i];
        cout<<"the matrix No "<<num<<" was successfully created with 3 parameters"<<endl;
    }
    matrix (const matrix &matri)
    {
        dim_x = matri.dim_x;
        dim_y = matri.dim_y;
        num = counterMat++;
        coor = new double [dim_x*dim_y];
        for (int i = 0; i < (dim_x*dim_y); i++)
            coor[i] = matri.coor[i];
        cout<<"the matrix No "<<num<<" is created as an instance of matrix No "<<matri.num<<endl;
    }
    ~ matrix()
    {
        delete [] coor;
        cout<<"the matrix No "<<num<<" was successfully deleted"<<endl;
    }
    matrix operator + (const matrix ma);
    matrix operator - (const matrix ma);
    matrix operator - ();
    matrix operator * ( double k);
    matrix operator * (const matrix matri);
    void operator = (const matrix matri);
    void print()
    {
        for (int i = 0; i < dim_y; i++)
        {
            for  (int j = 0; j<dim_x; j++)
                cout<<coor[i*dim_x + j]<<" ";
            cout<<endl;
        }
    }
};
matrix matrix :: operator + (const matrix ma)
{
    matrix answer = ma;
    for (int i=0; i<(dim_x*dim_y); i++)
        answer.coor[i] = coor[i] + ma.coor[i];
    return answer;
}
matrix matrix :: operator - (const matrix ma)
{
    matrix answer = ma;
    for (int i=0; i<(dim_x*dim_y); i++)
        answer.coor[i] = coor[i] - ma.coor[i];
    return answer;
}
matrix  matrix :: operator - ()
{
    matrix answer (dim_x, dim_y);
    for  (int i = 0; i<(dim_x*dim_y); i++)
        answer.coor[i] += coor[i]*(-1);
    return answer;
}
matrix matrix :: operator * ( double k)
{
    matrix answer (dim_x, dim_y);
    for (int i=0; i<(dim_x*dim_y); i++)
        answer.coor[i] = coor[i]*k;
    return answer;
}
matrix matrix :: operator * (const matrix matri)
{
    matrix answer (matri.dim_x, dim_y);
    for (int i = 0; i<dim_y; i++)
    {
        for (int j = 0; j<matri.dim_x; j++)
        {
            for (int k = 0; k<matri.dim_y; k++)
            {
                answer.coor[i*matri.dim_x+j] += coor[i*dim_x + k] * matri.coor[k*matri.dim_x + j];
            }
        }
    }
    return answer;
}
void matrix :: operator = (const matrix matri)
{
    for (int i=0; i<(dim_x*dim_y); i++)
        coor[i] = matri.coor[i];
    return;
}
vector vector_matrix (vector vecto, matrix matri)
{
    vector answer = vecto;
    for (int i = 0; i< matri.dim_y; i++)
    {
        for (int j = 0; j<matri.dim_x; j++)
            answer.coor[i] +=matri.coor[i*matri.dim_x+j]*vecto.coor[j];
    }
    return answer;
}

int vector::counterVec =0;
int matrix::counterMat=0;

int main ()
{
    double * test1 = new double[3] {44.4, 55.5, 66.6};
    double * test2 = new double[3] {11.1, 22.2, 33.3};
    vector vector1 (3, test1);
    vector vector2 (3,  test2);
    delete [] test1;
    delete [] test2;
    (vector1-vector2).print();
    (vector2+vector1).print();
    (-vector2).print();
    double rez = vector2.scalar(vector1);
    cout<<rez<<endl;
    (vector1*2.0).print();

    std::cout<<std::endl<<std::endl<<std::endl<<std::endl;

    double * temp3 = new double[4] {11.1, 22.1, 33.1, 44.1};
    double * temp4 = new double[4] {5.1, 6.1, 7.1, 8.1};
    matrix matrix1 (2, 2, temp3);
    matrix matrix2 (2, 2, temp4);
    delete [] temp3;
    delete [] temp4;
    (-matrix1).print();
    (matrix1*matrix2).print();
    (matrix1*2.0).print();
    (matrix2+matrix1).print();

    return 0;
}
