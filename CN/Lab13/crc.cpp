#include <iostream>
using namespace std;

string xor1(const string &a, const string &b) {
    string result;
    for (size_t i = 1; i < b.length(); ++i)
        result += (a[i] == b[i]) ? '0' : '1';
    return result;
}

string mod2div(const string &dividend, const string &divisor) {
    string tmp = dividend.substr(0, divisor.length());
    size_t pick = divisor.length();

    for (size_t i = pick; i < dividend.length(); ++i) {
        if (tmp[0] == '1')
            tmp = xor1(divisor, tmp) + dividend[i];
        else
            tmp = xor1(string(pick, '0'), tmp) + dividend[i];
    }

    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(string(pick, '0'), tmp);

    return tmp;
}

string encodeData(const string &data, const string &key) {
    string appended_data = data + string(key.size() - 1, '0');
    string remainder = mod2div(appended_data, key);
    cout << "Remainder: " << remainder << "\n";
    string codeword = data + remainder;
    cout << "Encoded Data (Data + Remainder): " << codeword << "\n";
    return codeword;
}

void receiver(const string &codeword, const string &key) {
    string received_codeword;
    cout << "Enter received codeword: ";
    cin >> received_codeword;

    string currxor = mod2div(received_codeword.substr(0, key.size()), key);
    size_t curr = key.size();

    while (curr != received_codeword.size()) {
        if (currxor.size() != key.size())
            currxor.push_back(received_codeword[curr++]);
        else
            currxor = mod2div(currxor, key);
    }

    if (currxor.size() == key.size())
        currxor = mod2div(currxor, key);

    cout << ((currxor.find('1') != string::npos) ? "There is an error in data" : "Correct message received") << endl;
}

int main() {
    string data, key;
    cout << "Enter data: ";
    cin >> data;
    cout << "Enter key: ";
    cin >> key;

    cout << "Sender side..." << endl;
    string codeword = encodeData(data, key);

    // cout << "\nReceiver side..." << endl;
    // receiver(codeword, key);
    cout<<"enter recieved..";
    string recieved;
    cin>>recieved;
    
    string res = mod2div(recieved, key);
    int flag = 1;
    for(auto x : res) {
        if(x=='1') {
            cout<<"error";
            flag = 0;
        }
    }
    if(flag) {
        cout<<"correct";
    }
    

    return 0;
}
