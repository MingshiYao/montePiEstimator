#include <iostream> // Terminal input/output
#include <vector> // General purpose array container
#include <random> // Random number generators
using namespace std;
double montePi(int N) {
    int N_in=0;
    double r;
    double x;
    double y;
    random_device seeder;
    mt19937_64 gen(seeder());
    uniform_real_distribution<double> dist(0.0, 1.0);
    for (int i = 0; i < N; ++i) {
        x=dist(gen);
        y=dist(gen);
        r=sqrt(x*x+y*y);
        if (r<=1.0)
            N_in +=1;
        }
        double Pi = (4.0*N_in)/N;
    return Pi;
}
int main(){
    int N=1000;
    int N_est=1000;
    vector <double> pis(1000);
    double pi_avg=0.0;
    for (int i=0; i<N_est; ++i){
        pis[i]=montePi(N);
        pi_avg += pis[i];
    }
    double x=pi_avg/N_est;
    double d=0.0;
    for (int i = 0; i<N_est; ++i){
        d=(pis[i]-x)*(pis[i]-x);
        d+=d;
    }
    d=sqrt(d/(N_est-1));
    cout<<x<<d;
    return 0;
}


