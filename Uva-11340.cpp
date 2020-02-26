#include <iostream>
#include <map>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    while(N--){
        map<char, double> charMap;
        map<char, double>::iterator it;

        int K;
        char c;
        double v;

        double total=0;

        scanf("%d", &K);
        while(K--){
            cin >> c >> v;
            charMap[c] =v;
        }

        int M;
        string line = "";
        scanf("%d", &M);
        cin.ignore();

        while(M--){
            getline(cin, line);
            for(int i=0;i<line.length();i++){
                it = charMap.find(line[i]);
                if(it!=charMap.end()){
                    total += it->second;
                }
            }
        }

        total = total/100;
        printf("%0.2lf$\n", total);

    }

    return 0;
}
