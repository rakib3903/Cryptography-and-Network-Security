#include<bits/stdc++.h>
using namespace std;

string makeCipher(string s){
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            if(s[i] >= 'a' && s[i <= 'z']){
                s[i] = 'a' + (s[i] - 'a' + 3) % 26; 
            }else if(s[i] >= 'A' && s[i <= 'Z']){
                s[i] = 'A' + (s[i] - 'A' + 3) % 26;
            }else if(isdigit(s[i])){
                s[i] = '0' + (s[i] - '0' + 3) % 10;
            }
        }
    }
    return s;
}

string makePlainText(string s){
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            if(s[i] >= 'a' && s[i <= 'z']){
                s[i] = 'a' + (s[i] - 'a' + 23) % 26; 
            }else if(s[i] >= 'A' && s[i <= 'Z']){
                s[i] = 'A' + (s[i] - 'A' + 23) % 26;
            }else if(isdigit(s[i])){
                s[i] = '0' + (s[i] - '0' + 7) % 10;
            }
        }
    }
    return s;
}
int main(){
    string plainText = "rakib123A";
    string encryptedText = makeCipher(plainText);
    string decryptedText =  makePlainText(encryptedText);
    
    cout<<"Plain text is : "<<plainText<<endl;
    cout<<"Cipher text is : "<<encryptedText<<endl;
    cout<<"Recovered Plain text is : "<<decryptedText<<endl;
    return 0;
}