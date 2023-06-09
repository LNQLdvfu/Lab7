#include <iostream>
#include <cmath>

using namespace std;

float fx(float x) {
    return 2 - x*expf(x);
}
float fxx(float x) {
    return -(expf(x) + x* expf(x));
}
float bisection_method (float a, float b, float tolerance, int n);
float newton_method (float initial, float tolerance, int n);
float secant_method (float p0,float p1, float tolerance, int n);

int main() {
    float a{-1}, b{1};
    int n{};
    cout<<"Input n: ";
    cin >> n;
    float tolerance{};
    cout<<"Input tolerance: ";
    cin>>tolerance;
    if(bisection_method(a,b,tolerance,b) > 0)
        cout<< bisection_method(a,b,tolerance,n)<<endl;
    else cout<<"Method failed after N iterations"<< n<<endl;

    cout<<newton_method(a,tolerance,n)<<endl;
    cout<<secant_method(a,a+0.01,tolerance,n);
}

float bisection_method (float a, float b, float tolerance, int n) {
    int i{1};
    float FA{fx(a)};
    while(i <= n) {
        float p = (a + b) / 2;
        float FP = fx(p);
        if(FP == 0 or (b-a) /2 < tolerance) {
            return p;
            break;
        }
        i++;
        if(FA*FP > 0) {
            a = p ;
            FA = FP;
        } else b = p;
    }
//    return -1;
}

float newton_method (float p0, float tolerance, int n){
    int i =1;
    while(i < n) {
        float p = p0 - fx(p0)/ fxx(p0);
        if(abs(p -p0) < tolerance) {
            return p;
        }
        i++;
        p0 = p;
    }
}

float secant_method (float p0,float p1, float tolerance, int n) {
    int i{2};
    float q0{fx(p0)};
    float q1{fx(p1)};
    while (i <= n) {
        float p = p1 -q1*(p1 -q0) / (q1 -q0);
        if(abs(p - p1) < tolerance) {
            return p;
        }
        i++;
        p0 = p1;
        q0 = q1;
        p1 = p;
        q1 = fx(p);
    }
}

