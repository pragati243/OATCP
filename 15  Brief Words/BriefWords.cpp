/*
Problem Name: Brief Words
Author: Vineet Motwani
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define vll vector<int>

// Comment the following function if all short forms for a word are not required to be generated.
vector<string> generateShortForms(const string& word) {
    
    unordered_set<string> shortForms;
    
    int n = word.length();
    for (int i = 0; i < n; ++i) {
        string sub = "";
        sub += word[i];
        shortForms.insert(sub);
        for (int j = i+1; j<n; ++j) {
            sub += word[j];
            shortForms.insert(sub);
            for (int k = j+1; k<n; ++k) {
                sub+=word[k];
                shortForms.insert(sub);
                for (int l = k+1; l<n; ++l) {
                    sub += word[l];
                    shortForms.insert(sub);
                    sub.pop_back();
                }
                sub.pop_back();
            }
            sub.pop_back();
        }
    }
    
    vector<string> result(shortForms.begin(), shortForms.end());
    return result;
}

unordered_map<string, string> generateCodewords(const vector<string>& words) {
    
    unordered_map<string, string> codewordMap;
    unordered_map<string, bool> usedCodewords;

    for (const auto& word : words) {
        bool found = false;
        for (size_t i = 1; i <= 4 && !found; ++i) {
            for (size_t j = 0; j < word.length() && !found; ++j) {
                for (size_t k = j; k < word.length() && !found; ++k) {
                    string codeword = word.substr(j, i);
                    if (usedCodewords.find(codeword) == usedCodewords.end()) {
                        codewordMap[word] = codeword;
                        usedCodewords[codeword] = true;
                        found = true;
                    }
                }
            }
        }
    }
    return codewordMap;
}

signed main() {
    int n;
    cin>>n;
    vector<string> dictionary;
    map<string, vector<string>> allShortForms;
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        dictionary.push_back(s);
        allShortForms[s] = generateShortForms(s);
    }

    auto codewords = generateCodewords(dictionary);

    for (const auto& entry : codewords) {
        cout << "Word: " << entry.first << ", Mapped Word: " << entry.second << endl;
    }
    cout<<endl<<endl;

    for(auto& it : allShortForms) {
        cout<<"Short forms for "<<it.first<<" are : ";
        sort(it.second.begin(), it.second.end());
        for(auto& s : it.second) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}
