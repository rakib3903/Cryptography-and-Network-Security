#include <bits/stdc++.h>

using namespace std;


int mod_pow(int base, int exp, int mod) {
    long long result = 1;
    long long b = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * b) % mod;
        exp >>= 1;
        b = (b * b) % mod;
    }
    return (int)result;
}


int mod_inverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}

int main() {
    int p = 47, q = 71;
    int n = p * q;               
    int phi = (p - 1) * (q - 1); 
    int e = 79;
    int d = mod_inverse(e, phi);

    if (d == -1) {
        cout << "Modular inverse not found.\n";
        return 1;
    }

    cout << "Public key: (" << e << ", " << n << ")\n";
    cout << "Private key: (" << d << ", " << n << ")\n";

  
    string message;
    cout << "Enter a message: ";
    getline(cin, message);


    vector<int> encrypted;
    for (char ch : message) {
        int ascii = static_cast<unsigned char>(ch);              
        int cipher = mod_pow(ascii, e, n);
        encrypted.push_back(cipher);
    }

  
    cout << "Encrypted: ";
    for (int c : encrypted) {
        cout << c << " ";
    }
    cout << endl;

 
    string decrypted;
    for (int c : encrypted) {
        int num = mod_pow(c, d, n);                   
        decrypted += static_cast<char>(num);        
    }

    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
