#include "iostream"
#include "iomanip"

#define ENTER_THE_NUMBER_OF_LINES cout << """enter the number of lines: ";  \
cin >> n;                                                                   \
cout << "enter the number of columns: ";                                    \
cin >> m;                                                                   \
do{                                                                         \
if (n < 1 || m < 1) {                                                       \
    cout << "The number of lines and columns must be at least 1" << endl;   \
    cin.clear();                                                            \
    cin.ignore(10000, '\n');                                                \
    continue;                                                               \
}                                                                           \
}while (n < 1 || m < 1);{}
void a(int *b){
    *b = 1;
}

void input_sizes(int *pm, int *pn);

void genmatrix(int n, int m, int **matrix);

void printmatrix(int n, int m, int **matrix);

int printlastpositiveline(int n, int m, int **matrix);

void deleteMatrix(int n, int **matrix);

void initMatrix(int n, int m, int **&matrix);

using namespace std;

int main() {
    char answer;
    do {
        srand(time(nullptr));
        int n, m;
        int **matrix;
        int b = 7;
        a(&b);
        printf("%d", b);
        input_sizes(&m, &n);
        initMatrix(n, m, matrix);
        genmatrix(n, m, matrix);
        printmatrix(n, m, matrix);
        printlastpositiveline(n, m, matrix);
        int lastpositiveline = printlastpositiveline(n, m, matrix);
        if (lastpositiveline == -1) {
            cout << "There are no positive lines" << endl;
        } else {
            cout << "The last positive line is " << lastpositiveline + 1 << endl;
        }
        deleteMatrix(n, matrix);
        cout << "press n to exit or any other key to continue: ";
        cin >> answer;

    } while (answer != 'n');
    return 0;
}

void initMatrix(int n, int m, int **&matrix) {
    matrix = new int *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];
}

void deleteMatrix(int n, int **matrix) {
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void genmatrix(int n, int m, int **matrix) {
    int min = 0, max = 0;
    do {
        cout << "enter the minimum value: ";
        cin >> min;
        cout << "enter the maximum value: ";
        cin >> max;
        if (min > max || !cin) {
            cout << "The maximum value must be greater than the minimum value" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
    } while (min > max || !cin);
    {}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void printmatrix(int n, int m, int **matrix) {
    for (int i = 0; i < n; i++) {
        cout << "Line " << i + 1 << ": ";
        for (int j = 0; j < m; j++) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int printlastpositiveline(int n, int m, int **matrix) {
    int lastpositiveline = -1;
    for (int i = 0; i < n; i++) {
        bool ispositiveline = true;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] <= 0) {
                ispositiveline = false;
                break;
            }
        }
        if (ispositiveline) {
            lastpositiveline = i;
        }
    }
    return lastpositiveline;
}

void input_sizes(int *pm, int *pn) {
    cout << "enter the number of lines: ";
    cin >> *pn;
    cout << "enter the number of columns: ";
    cin >> *pm;
    do {
        if (*pn < 1 || *pm < 1) {
            cout << "The number of lines and columns must be at least 1" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
    } while (*pn < 1 || *pm < 1);
}
