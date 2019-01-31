/* Реализуйте класс double_vector -  массив вещественных чисел переменного размера.
30 баллов
конструктор без аргументов (создает вектор размера 1, с одним элементом равным нулю): 
double_vector()
конструктор с одним аргументом - длинной массива (создает вектор нужного размера заполненный нулями):
double_vector(unsigned int N)
деструктор: 
~double_vector()
конструктор копий: 
double_vector(const double_vector& A)
оператор присвоения:
const double_vector& operator=(const double_vector& A)
оператор обращения по индексу:
double operator[] (unsigned int n)
добавление в конец: 
void push_back(double x)
извлечение из конца: 
double pop_back()
при извлечении - элемент удаляется из вектора, а значение этого элемента возвращается, как результат работы метода
получение размера вектора:
unsigned int size()
получение вместимости вектора: 
unsigned int capacity()
40 баллов
конструктор создающий вектор по double-массиву и его размеру
изменение вместимости массива (resize)
добавление в начало (push_front)
удаление из начала(pop_front)
добавление на заданную позицию (insert)
удаление из заданной позиции pos: void erase(pos)
удаление интервала по индексам концов отрезка: erase(a,b)
конкатенация(слияние) векторов operator+
линейный поиск по массиву методом find
добавить логическое поле is_sort, быструю сортировку, и бинарный поиск(работающий в случае, если массив отсортирован) */

#include <iostream>
using namespace std;

class double_vector
{
    double* data;
    unsigned int vecSize;
    unsigned int vecCapacity;
public:
    double_vector()
    {
        vecSize = vecCapacity = 1;
        data = new double [1];
        *data = 0;
    };
    double_vector(unsigned int N)
    {
        vecSize = vecCapacity = N;
        data = new double [N];
        for (int i = 0; i < N; i++)
            data[i] = 0;
    };
    double_vector (double* A, unsigned int N)
    {
        vecSize = vecCapacity = N;
        for (int i = 0; i < N; i++)
            data[i] = A[i];
    }
     double_vector (const double_vector& A)
    {
        vecSize = A.vecSize; 
  			data = new double[vecSize]; 
  			for (int i = 0; i < vecSize; i++) 
   		data[i] = A.data[i]; 
    };
    ~double_vector ()
    {
        delete[] data;
    };
    const double_vector& operator=(const double_vector& A)
    {
        vecSize = A.vecSize;
        vecCapacity = A.vecCapacity;
        data = A.data;
        return *this;
    };
    double &operator[] (int i)
    {
        return data[i];
    };
    void push_back (int x)
    {
        if (vecSize >= vecCapacity)
        {
            vecCapacity *= 2;
            double* T = new double[vecCapacity];
            for (int i = 0; i < vecSize; i++)
                T[i] = data [i];
            delete [] data;
            data = T;
        }
        data [vecSize] = x;
        vecSize++;
    };
    double pop_back ()
    {
        double T = data [vecSize - 1];
        delete (data + vecSize - 1);
        vecSize--;
        return T;
    }
    unsigned int Size()
    {
        return vecSize;
    };
    unsigned int Capacity()
    {
        return vecCapacity;
    };
    void resize (unsigned int N)
    {

        vecCapacity += N;
        double* T = new double[vecCapacity];
        for (int i = 0; i < vecSize; i++)
            T[i] = data [i];
        delete [] data;
        data = T;
    }
    void push_front (double x)
    {
        if (vecSize >= vecCapacity)
        {
            vecCapacity *= 2;
            double* T = new double[vecCapacity];
            for (int i = 1; i < vecSize + 1; i++)
                T[i] = data [i];
            delete [] data;
            data = T;
        }
        else
        {
            double* T = new double[vecCapacity];
            for (int i = 1; i < vecSize + 1; i++)
                T[i] = data [i];
            delete [] data;
            data = T;
        };
        vecSize++;
    };
    int pop_front ()
    {
        double T = data [0];
        delete (data + 0);
        vecSize--;
        return T;
    };
    void insert (double x, int k)
    {
        if (vecSize >= vecCapacity)
        {
            vecCapacity *= 2;
            double* T = new double[vecCapacity];
            for (int i = 1; i < k; i++)
                T[i] = data [i];
            for (int i = k+1; i < vecSize; i++)
                T[i] = data [i-1];
            delete [] data;
            data = T;
        }
        data[k] = x;
    };
    void erase (int k)
    {
        delete (data +k);
        vecSize--;
    };
    void erase (int a, int b)
    {
        if (a > b)
        {
            int T = b;
            b = a;
            a = T;
        };
        int length = b - a;
        for (int i = 1; i <= b; i++)
            delete (data+i);
      vecSize -= length;
    };
};

double_vector &operator+ (double_vector& A, double_vector& B)
{
    unsigned int a = A.Size(), b = B.Size();
    double_vector T (a + b);
    for (int i = 0; i < a; i++)
        T[i] = A[i];
    for (int i = a; i < a + b; i++)
        T[i] = B[i - a];
    return T;
}

int main()
{
    double_vector A ();
    cout << A[0] << '\n';
    int v, k, x, a, b;
    cin >> v;
    double_vector B (v);
    for (int i; i < v; i++)
        cout << B[i] << ' ';
    cout << '\n';
    cin >> v;
    double* T = new double(v);
    for (int i; i < v; i++)
        cin >> T[i];
    double_vector C(T, v);
    cin >> x;
    C.push_front(x);
    cout << C.pop_front() << endl;
    cin >> x;
    C.push_back(x);
    cout << C.pop_back() << endl;
    cin >> k >> x;
    C.insert (x, k);
    cin >> a;
    C.erase(a);
    cin >> a >> b;
    C.erase(a, b);
    double_vector D = C + B;
    for (int i = 0; i < D.Size(); i++)
        cout << D[i] << ' ';
    return 0;
}
