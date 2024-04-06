#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

class Timer
{
private:
    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration<double, ratio<1> >;

    chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
int main()
{
    ofstream output("time.txt");
    int N = 1000;
    for (int i = N; N <= 20000; N+=1000) {

        int** intMatrix = new int* [N];
        vector<int> intVector(N);  
        float** floatMatrix = new float* [N];
        vector<float> floatVector;
        double** doubleMatrix = new double* [N];
        vector<double> doubleVector;

        for (int i = 0; i < N; i++) {
            intMatrix[i] = new int[N];
            floatMatrix[i] = new float[N];
            doubleMatrix[i] = new double[N];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                intMatrix[i][j] = 2;
                floatMatrix[i][j] = 2.0f;
                doubleMatrix[i][j] = 2.0;
            }
            intVector.push_back(2);
            floatVector.push_back(2.0f);
            doubleVector.push_back(2.0);
        }

        cout << "============================================" << endl;
        cout << "matrix*vector\nN = " << N << endl;
        output << "matrix*vector\nN = " << N << endl;
        int resultInt;
        Timer t;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                resultInt = intMatrix[i][j] * intVector[j];
            }
        }
        double time = t.elapsed();
        cout << "Int: " << time << endl;
        output << time << endl;
        float resultFloat;
        t.reset();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                resultFloat = floatMatrix[i][j] * floatVector[j];
            }
        }
        time = t.elapsed();
        cout << "Float: " << time << endl;
        output << time << endl;
        double resultDouble;
        t.reset();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                resultDouble = doubleMatrix[i][j] * doubleVector[j];
            }
        }
        time = t.elapsed();
        cout << "Double: " << time << endl;
        output << time << endl;
        cout << "============================================" << endl;
        cout << "vector*matrix(slow)\nN = " << N << endl;
        output << "vector*matrix(slow)\nN = " << N << endl;
        t.reset();
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                resultInt = intVector[j] * intMatrix[i][j];
            }
        }
        time = t.elapsed();
        cout << "Int: " << time << endl;
        output << time << endl;

        t.reset();
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                resultFloat = floatVector[j] * floatMatrix[i][j];
            }
        }
        time = t.elapsed();
        cout << "Float: " << time << endl;
        output << time << endl;

        t.reset();
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                resultDouble = doubleVector[j] * doubleMatrix[i][j];
            }
        }
        time = t.elapsed();
        cout << "Double: " << time << endl;
        output << time << endl;
        cout << "============================================" << endl;
        cout << "vector*matrix\nN = " << N << endl;
        output << "vector*matrix\nN = " << N << endl;
        t.reset();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                intVector[j] * intMatrix[i][j];
            }
        }
        time = t.elapsed();
        cout << "Int: " << time << endl;
        output << time << endl;

        t.reset();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                floatVector[j] * floatMatrix[i][j];
            }
        }
        time = t.elapsed();
        cout << "Float: " << time << endl;
        output << time << endl;

        t.reset();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                doubleVector[j] * doubleMatrix[i][j];
            }
        }
        time = t.elapsed();
        cout << "Double: " << time << endl;
        output << time << endl;
        cout << "============================================" << endl;
        for (int i = 0; i < N; i++) {
            delete[] intMatrix[i];
            delete[] floatMatrix[i];
            delete[] doubleMatrix[i];
        }
        delete[] intMatrix;
        delete[] floatMatrix;
        delete[] doubleMatrix;
        intVector.clear();
        floatVector.clear();
        doubleVector.clear();

    }
    
}

