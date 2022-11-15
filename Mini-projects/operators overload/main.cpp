// Mohamad Alamin Yassin HKH-01-20 c++ homework exercise 2
#include<bits/stdc++.h>
using namespace std;
class matrix
{
    int dim_x;
    int dim_y;
    float * coor;
public:
    friend matrix line_system (matrix matrix1, matrix vect);
    matrix()
     {
        dim_x = 1;
        dim_y = 1;
        coor = new float [1];
        *coor = 1;
    }
    matrix (int dim_x_n, int dim_y_n)
    {
        dim_x = dim_x_n;
        dim_y = dim_y_n;
        coor = new float [dim_x*dim_y];
        for (int i = 0; i < (dim_x*dim_y); i++)
           coor[i] = 0;
    }
    matrix(int dim_n_x, int dim_n_y, float * coord)
     {
        dim_x = dim_n_x;
        dim_y = dim_n_y;
        coor = new float [dim_x*dim_y];
        for(int i=0; i<(dim_x*dim_y); i++)
            coor[i] = coord[i];
    }
    matrix (const matrix &matr)
    {
        dim_x = matr.dim_x;
        dim_y = matr.dim_y;
        coor = new float [dim_x*dim_y];
        for (int i = 0; i < (dim_x*dim_y); i++)
           coor[i] = matr.coor[i];
    }
    ~ matrix()
    {
        delete [] coor;
    }
    matrix operator + (const matrix mat);
    matrix operator * ( float k);
    matrix operator * (const matrix matr);
    void operator = (const matrix matr);
    bool condition_not (matrix vect, float e)
    {
        for (int i = 0; i<dim_x*dim_y; i++)
        {
            if (abs(coor[i]-vect.coor[i])>e)
                return true;
            return false;
        }
    }
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
matrix matrix :: operator + (const matrix mat)
{
    matrix answer = mat;
    for (int i=0; i<(dim_x*dim_y); i++)
        answer.coor[i] += coor[i];
    return answer;
}
matrix matrix :: operator * ( float k)
{
    matrix answer (dim_x, dim_y);
    for (int i=0; i<(dim_x*dim_y); i++)
        answer.coor[i] = coor[i]*k;
    return answer;
}
void matrix :: operator = (const matrix matr)
{
    for (int i=0; i<(dim_x*dim_y); i++)
        coor[i] = matr.coor[i];
    return;
}
matrix matrix :: operator * (const matrix matr)
{
    matrix answer (matr.dim_x, dim_y);
    for (int i = 0; i<dim_y; i++)
    {
        for (int j = 0; j<matr.dim_x; j++)
        {
            for (int k = 0; k<matr.dim_y; k++)
            {
                answer.coor[i*matr.dim_x+j] += coor[i*dim_x + k] * matr.coor[k*matr.dim_x + j];
            }
        }
    }
    return answer;
}
matrix line_system (matrix matrix1, matrix vect)
{
    matrix ans1(1, matrix1.dim_y);
    matrix ans2(1, vect.dim_y);
    for (int i = 0; i<matrix1.dim_y; i++)
    {
        float k = -1*matrix1.coor[i*matrix1.dim_x + i];
        vect.coor[i] = vect.coor[i]/-k;
        for (int j=0; j<matrix1.dim_x; j++)
        {
            matrix1.coor[i*matrix1.dim_x + j] /= k;
            if (i == j)
                matrix1.coor[i*matrix1.dim_x + j] = 0;
        }
    }
    while ((matrix1*ans1+vect).condition_not(ans1, 0.001))
    {
        ans2 = ((matrix1*ans1)+vect);
        ans1 = ans2;
    }
    return ans1;
}
int main ()
{
    int dim = 4;
    float * temp = new float[dim];
    float * temp1 = new float[dim*dim];
    for (int i = 0; i<dim*dim; i++)
        temp1[i] = rand()%250 + 1;
    for (int i = 0; i<dim; i++)
    {
        temp[i] = rand()%250+ 1;
        temp1[i*dim+i]*=1000;
    }
    matrix matr (dim, dim, temp1);
    matrix ans (1, dim, temp);
    matrix vect = matr*ans;


    ans.print();

    line_system(matr, vect).print();
    return 0;
}
