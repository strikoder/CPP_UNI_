#include <iostream>
using namespace std;
class matrix {
	static int coun;
	int dim;
	double* matr;
public:
	int number;
	matrix() {
		dim = 0;
		matr = new double[dim];
		coun++;
		number = coun;
	}
	matrix(int dim) {
		this->dim = dim;
		int matrdim = dim * dim;
		matr = new double[matrdim];
		coun++;
		number = coun;
	}
	matrix(int dim, double* matr) {
		this->dim = dim;
		int matrdim = dim * dim;
		this->matr = new double[matrdim];
		for (int i = 0; i < matrdim; i++) this->matr[i] = matr[i];
		coun++;
		number = coun;
	}
	matrix(matrix& other) {
		this->dim = other.dim;
		int matrdim = dim * dim;
		this->matr = new double[matrdim];
		for (int i = 0; i < matrdim; i++) this->matr[i] = other.matr[i];
		coun++;
		number = coun;

	}
	matrix(const matrix& other) {
		this->number = other.number;
		this->dim = other.dim;
		int matrdim = dim * dim;
		this->matr = new double[matrdim];
		for (int i = 0; i < matrdim; i++) this->matr[i] = other.matr[i];

	}
	matrix operator + (matrix const& other) {
		matrix temp;
		temp.dim = this->dim;
		int matrdim = this->dim * this->dim;
		temp.matr = new double[matrdim];
		for (int i = 0; i < matrdim; i++) temp.matr[i] = this->matr[i] + other.matr[i];

		return temp;
	}

	matrix& operator = (matrix const& other) {
		this->dim = other.dim;
		int matrdim = dim * dim;
		this->matr = new double[matrdim];
		for (int i = 0; i < matrdim; i++) this->matr[i] = other.matr[i];
		return *this;
	}

	matrix operator * (matrix const& other) {
		matrix temp;
		temp.dim = other.dim;
		int matrdim = other.dim * other.dim;
		temp.matr = new double[matrdim];
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				temp.matr[j + dim * i] = 0;
				for (int k = 0; k < dim; k++)
					temp.matr[j + dim * i] += this->matr[k + dim * i] * other.matr[j + dim * k];
			}
		}
		return temp;
	}
	matrix operator * (double x) {
		matrix temp;
		temp.dim = this->dim;
		int matrdim = dim * dim;
		temp.matr = new double[matrdim];
		for (int i = 0; i < matrdim; i++) temp.matr[i] = this->matr[i] * x;
		return temp;
	}
	void print() {
		cout << "Matr:\n";
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				cout << matr[j + dim * i] << " ";
			}
			cout << endl;
		}
	}
	double det(double* matr, int dim) {
		double* temp;
		int matrdim = dim * dim;
		temp = new double[matrdim];
		for (int i = 0; i < matrdim; i++) temp[i] = this->matr[i];
		int tempo;
		double d = 1;

        for (int k = 0; k < dim - 1; k++) {
            for (int i = k + 1; i < dim; i++) {
                tempo = -temp[k + dim * i] / temp[k + dim * k];
                for (int j = 0; j < dim; j++) {
                    temp[j + dim * i] += temp[j + dim * k] * tempo;
                }
            }
        }
        for (int i = 0; i < dim; i++) {
            d *= temp[i + dim * i];
        }

		return d;
	}
	double *cropping(matrix const& other, int x, int y) {
		matrix temp;
		temp.dim = other.dim - 1;
		int matrdim = temp.dim * temp.dim;
		temp.matr = new double[matrdim];
		int position = 0;
		for (int i = 0; i < other.dim; i++) {
			if (i != x) {
				for (int j = 0; j < other.dim; j++) {
					if (j != y) {
						temp.matr[position] = matr[j + other.dim * i];
						position++;
					}
				}

			}
		}
		return temp.matr;
	}

	matrix trans(matrix const& other, double deter) {
		for (int i = 0; i < other.dim; i++) {
			for (int j = i + 1; j < other.dim; j++) {
				double a = other.matr[j + other.dim * i];
				other.matr[j + other.dim * i] = other.matr[i + other.dim * j];
				other.matr[i + other.dim * j] = a;
			}
		}
		for (int i = 0; i < other.dim * other.dim; i++) {
			other.matr[i] /= deter;
		}
		return other;
	}

	matrix rev() {
		matrix temp;
		temp.dim = dim;
		int matrdim = dim * dim;
		temp.matr = new double[matrdim];
		double ma_det = det(matr, dim);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				temp.matr[j + i * dim] = det(cropping(*this, i, j), dim - 1);
			}
		}
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if (i % 2 == 0 && j % 2 != 0 || i % 2 != 0 && j % 2 == 0)
					temp.matr[j + i * dim] *= -1;
			}
		}
		return trans(temp, ma_det);
	}
};


int matrix::coun = 0;

int main() {

	double Aarr[9], Barr[9];
	for (int i = 1; i < 10; i++) {
		Aarr[i - 1] = i;
		Barr[i - 1] = 10 - i;
	}
	Aarr[1] = 8;
	matrix a(3, Aarr);
	matrix b(3, Barr);

	matrix x;
	cout << "Equation of shape X*A = B\n";
	x = b * a.rev();
	cout << "X:\n";
	x.print();
	cout << "A:\n";
	a.print();
	cout << "B:\n";
	b.print();


	return 0;
}

