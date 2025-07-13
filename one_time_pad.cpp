#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file1("file1.txt");
    string word, s = "ABC";
    getline(file1, word, '\0');
    file1.close();

    string cipher = "";
    for(int i = 0; i < s.size(); i++){
        char encryptedChar = (((s[i] - 'A') + (word[i]  - 'A') + 1) % 26) + 'A';
        cipher += encryptedChar;
    }
    cout<< "Cipher Text is : " << cipher<<endl;
    word.erase(0, s.size());
    ofstream fileOut1("file1.txt");
    fileOut1 << word;
    fileOut1.close();



    ifstream file2("file2.txt");
    getline(file2, word, '\0');
    file2.close();

    string decrypt = "";
    for(int i = 0; i < cipher.size(); i++){
        char decryptedChar = (((cipher[i] - 'A') - (word[i]  - 'A') + 25) % 26) + 'A';
        decrypt += decryptedChar;
    }
    cout<< "Decrypt Text is : " << decrypt<<endl;
    word.erase(0, cipher.size());
    ofstream fileOut2("file2.txt");
    fileOut2 << word;
    fileOut2.close();
    
    return 0;
}
