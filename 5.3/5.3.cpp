#include <iostream> 
#include <cmath>    
#include <iomanip>  

using namespace std; 
double z(const double x);

int main() 
{
    double pp, pk; 
    int n;         

    cout << "pp = "; cin >> pp; 
    cout << "pk = "; cin >> pk; 
    cout << "n = "; cin >> n;   

    double dp = (pk - pp) / n; 
    double p = pp;             

    cout << fixed; 
    cout << "---------------------------------" << endl; 
    cout << "|" << setw(10) << "p" << " |"
        << setw(18) << "Result" << " |" << endl; 
    cout << "---------------------------------" << endl;

    while (p <= pk + dp / 2.0) 
    {
        
        double res = z(p * p + 1.0) - z(p * p - 1.0) + 2.0 * z(p);

        cout << "|" << setw(10) << setprecision(2) << p << " |"
            << setw(18) << setprecision(5) << res << " |" << endl;

        p += dp; 
    }
    cout << "---------------------------------" << endl; 

    return 0; 
}

double z(const double x)
{
    if (abs(x) >= 1) 
    {
        return (sin(x) + 1.0) / (pow(cos(x), 2) + exp(x * x));
    }
    else 
    {
        double S = 0;   
        int k = 0;      
        double a = 1.0; 
        S = a;          

        do
        {
            k++;            
            double R = 2.0 * x / k; 
            a *= R;         
            S += a;        
        } while (k < 6);    

        return (1.0 / exp(x * x)) * S; 
    }
}