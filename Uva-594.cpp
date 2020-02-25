#include <iostream>
using namespace std;

int main(){
     int n;
     while(cin >> n){
        int num = n;
        int new_num = 0;
        int i=1;
        while(i<4){
            new_num = new_num | (num&255);
            num = num>>8;
            new_num = new_num<<8;
            i++;
        }

        new_num = new_num | (num&255);
        printf("%d converts to %d\n", n, new_num);
     }

     return 0;

}
