#include<bits/stdc++.h>
using namespace std;

string cipherText(string s){
    vector<vector<char>>v;
    int row = 5;
    int col = 9;
    int cnt = 0;
    for(int i = 0; i < row; i++){
        v.push_back({});
        for(int j = 0; j < col; j++){
            v[i].push_back(s[cnt]);
            cnt++;
            if(cnt == s.size()) break;
        }
    }
    string c = "";
    int x = s.size() % col;
    for(int j = 0; j < col; j++){
        if(x > 0){
            for(int i = 0; i < s.size() / col + 1; i++){
                c += v[i][j];
            }
        }else{
            for(int i = 0; i < s.size() / col; i++){
                c += v[i][j];
            }
        }
        x--;
    }

    return c;
}

string decryptedText(string s){
    vector<vector<char>>v;
    int row = 5;
    int col = 9;
    int cnt = 0;
    for(int i = 0; i < row; i++) v.push_back({});
    int x = s.size() % col;
    for(int j = 0; j < col; j++){
        v.push_back({});
        if(x > 0){
            for(int i = 0; i < s.size() / col + 1; i++){
                v[i].push_back(s[cnt]);
                cnt++;
            }
        }else{
            for(int i = 0; i < s.size() / col; i++){
                v[i].push_back(s[cnt]);
                cnt++;
            }
        }
        x--;
    }

    string c = "";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < v[i].size(); j++){
            c += v[i][j];
        }
    }
    return c;
}

int main(){
    string s = "DEPARTMENTOFCOMPUTERSCIENCEANDENGINEERING";
    string c = cipherText(s);
    c = cipherText(c);
    string decrypt = decryptedText(c);
    decrypt = decryptedText(decrypt);
    cout<<"Cipher text is : "<<c<<endl;
    cout<<"Decrypted text is : "<<decrypt<<endl;
    
    return 0;
}
