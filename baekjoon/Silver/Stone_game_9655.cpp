#include <stdio.h>
using namespace std;
 
int n;
 
int main() {
    scanf("%d", &n);
 
    n % 2 == 1 ? puts("SK") : puts("CY");
 
    return 0;
}
