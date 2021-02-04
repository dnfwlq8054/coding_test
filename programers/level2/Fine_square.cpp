using namespace std;

long long gcd(int a, int b){
    return a == 0 ? b : gcd(b % a, a);
}

long long solution(int w,int h) {

    return (long)w * (long)h - w - h + gcd(w , h);
}