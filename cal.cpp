#include<iostream>
using namespace std;
class number
{
    public:
        float x, y;
        string op;
        void input()
        {
        	cout << "Enter the operation you want to perform (add, sub, multi, div): ";
            cin >> op;
            cout << "Enter the first number: ";
            cin >> x;
            cout << "Enter the second number: ";
            cin >> y;
            
        }
        void displayResult()
        {
            if (op == "add")
            {
                cout << "Addition: " << x + y << endl;
            }
            else if (op == "sub")
            {
                cout << "Subtraction: " << x - y << endl;
            }
            else if (op == "multi")
            {
                cout << "Multiplication: " << x * y << endl;
            }
            else if (op == "div")
            {
                if (y != 0)
                {
                    cout << "Division: " << x / y << endl;
                }
                else
                {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
            }
            else
            {
                cout << "Invalid operation. Please enter add, sub, multi, or div." << endl;
            }
        }
};
int main()
{
    number a;
    a.input();
    a.displayResult();
    return 0;
}
