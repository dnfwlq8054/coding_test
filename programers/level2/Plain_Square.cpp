using namespace std;

long long gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

long long solution(int w,int h) {

    return (long)w * (long)h - w - h + gcd(w , h);
}