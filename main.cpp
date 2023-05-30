#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main() {
    FILE* res=fopen("text1.txt","r");
    vector < pair <char*,int> > v;
    char* data=new char[30];
    char* ex="search";
    char buf;
    int k=0;
    int ok=0;
    int f=0;
    v.push_back(make_pair(ex,-1));
    while((fscanf(res,"%c",&buf)!=EOF)) {
        if (isalpha(buf)) {
            buf = tolower(buf);
            data[k] = buf;
            k++;
            ok = 1;
        } else {
            if (ok == 1) {
                data[k++]='\0';
                for (int i = 0; i < size(v); i++) {
                    if (strcmp(v[i].first, data) == 0) {
                        //int a = v[i].second + 1;
                        v[i].second++;
                        f=1;
                        break;
                    }
                }
                if(f==0) {
                    v.push_back(make_pair(data, 1));
                }
            }
            k=0;
            f=0;
            ok = 0;
            data = new char[30];
        }
    }
    if(v[size(v)-1].first=data+'\0'){
        v[size(v)-1].second++;
    }
    for(int i=0;i<size(v);i++){
        if(v[i].second>1){
            cout<<v[i].first<<"/";
        }
    }
    fclose(res);
    return 0;
}
