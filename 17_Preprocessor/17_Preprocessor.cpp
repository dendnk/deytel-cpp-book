// 17_Preprocessor.cpp - exercises

#include <iostream>

#define YES 1
#define NO  0
//#include "common.h"
//#line 3000

#if defined TRUE
#undef TRUE
#define TRUE 1
#endif

#ifdef TRUE
#undef TRUE
#define TRUE 0
#endif

#if ACTIVE
#define INACTIVE 0
#else
#define INACTIVE 1
#endif

#define IN_CUBE(x) ((x)*(x)*(x))

#define CUBE_VOLUME(a) IN_CUBE(a)

#define PI 3.14159

#define SPHERE_VOLUME(radius) (4/3.)*PI*(IN_CUBE(radius))

#define SUM(x,y) std::cout << "Sum " #x " and " #y " is " << x+y

#define MINIMUM2(a,b) (((a) > (b)) ? (b) : (a))

#define MINIMUM3(a,b,c) MINIMUM2(a,MINIMUM2(b,c))

#define PRINT(a) std::cout << #a << " = " << a << std::endl

#define PRINTARRAY(arr, num)  for (int i = 0; i < num; ++i)  std::cout << "arr[" << i << "] = " << arr[i] << std::endl

#define SUMARRAY(arr, num, sum)  sum = 0; for (int i = 0; i < num; ++i)  { sum += arr[i];}


void fun17_4()
{
    using namespace std;
    cout << "SPHERE VOLUME CALCULATION" << endl;

    for (int radius = 1; radius <= 10; ++radius)
    {
        cout << "Radius : " << radius << " Volume : " << SPHERE_VOLUME(radius) << endl;
    }
}

void fun17_5()
{
    SUM(6, 7);
}

void fun17_6()
{
    using namespace std;

    cout << "17_6 - minimum of 2" << endl;
    cout << "Please input 2 numbers!" << endl;

    int a;
    int b;

    cin >> a >> b;

    cout << MINIMUM2(a, b) << endl;
}

void fun17_7()
{
    using namespace std;

    cout << "17_7 - minimum of 3" << endl;
    cout << "Please input 3 numbers!" << endl;

    int a;
    int b;
    int c;

    cin >> a >> b >> c;

    cout << MINIMUM3(a, b, c) << endl;
}

void fun17_8()
{
    int j = 123;
    float f = 23.45f;
    std::string s = "abc";

    PRINT(j);
    PRINT(f);
    PRINT(s);

    const int length = 3;
    int a[length] = { 11, 22, 33 };

    PRINTARRAY(a, length);

    int sum = 0;
    SUMARRAY(a, length, sum);
    std::cout << "Array sum : " << sum << std::endl;
}

// fun 17_11

inline float GetSphereVolume(float radius)
{
    return (4 / 3.) * PI * (IN_CUBE(radius));
}

inline int GetArraySum(int* array, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += array[i];
    }
    return sum;
}

void fun17_11()
{
    // inline functions

    using namespace std;
    for (int radius = 1; radius <= 10; ++radius)
    {
        cout << "Radius : " << radius << " Volume : " << GetSphereVolume(static_cast<float>(radius)) << endl;
    }

    const int length = 3;
    int a[length] = { 14, 25, 63 };
    std::cout << "Array sum : " << GetArraySum(a, length) << std::endl;
}

int main()
{
    // 17_2
    using namespace std;
    cout << "Hello World!\n";
    cout << "Current line number : " << __LINE__ << endl;
    cout << "Current file name : " << __FILE__ << endl;
    cout << "Current date : " << __DATE__ << endl;
    cout << "Current time : " << __TIME__ << endl;

    cout << "Cube volume : " << CUBE_VOLUME(10) << endl;

    //fun17_4();
    //fun17_5();
    //fun17_6();
    //fun17_7();
    //fun17_8();
    fun17_11();
}
