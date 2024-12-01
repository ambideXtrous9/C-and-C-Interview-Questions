#include<stdio.h>

/*

What is a Callback Function?
A callback function is a function that is passed as an argument to another function and is invoked after the completion of a specific task or event. It allows deferred execution of the function, enabling flexible and reusable code.

In simple terms:

One function (caller) calls back another function (callback) at the appropriate time.
Key Features:
Decoupling: The caller function doesn't need to know the details of the callback function.
Flexibility: Different behaviors can be achieved by passing different callback functions.
Asynchronous Execution: Frequently used in event-driven programming or when tasks run in parallel.

 */
int Callbck(int a,int b)
{
    int z = a*b;
    printf("Callback Multiplication result = %d\n",z);
    return z;
}


void Operation(int a, int (*fnc_ptr)(int,int))
{
    int res = a + fnc_ptr(a,2*a);
    printf("Result from CallBck to Operation = %d\n",res);
}

// Define functions for arithmetic operations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return b != 0 ? a / b : 0;  // Avoid division by zero
}

int main()
{

    Operation(5,Callbck);

    int (*operations[4])(int, int) = {add, subtract, multiply, divide};

    // Test the functions
    int x = 10, y = 5;
    printf("Add: %d\n", operations[0](x, y));       // Calls add(10, 5)
    printf("Subtract: %d\n", operations[1](x, y));  // Calls subtract(10, 5)
    printf("Multiply: %d\n", operations[2](x, y));  // Calls multiply(10, 5)
    printf("Divide: %d\n", operations[3](x, y));    // Calls divide(10, 5)

    return 0;
}