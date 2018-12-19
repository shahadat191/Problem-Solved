#include<bits/stdc++.h>
using namespace std;
#define int long long
#define input freopen("input.txt", "rt", stdin)
#define output freopen("output.txt", "wt", stdout)
double const pi = 3.14159265358979323846;
int const N = 55;
int const MOD = 100000007;


int32_t main(){
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--){
        caseno++;
        double r1, r2, h,p;
        scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);

        double x = (h*r2)/(r1-r2);

        double r3 = (r2*(p+x))/x;

        double full = (1/3.00) * pi * r3 * r3 * (x+p);
        double baki = (1/3.00) * pi * r2 * r2 * x;

        printf("Case %d: %.10f\n", caseno, full - baki);
    }

}
