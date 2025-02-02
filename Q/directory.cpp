// #include <bits/stdc++.h>
// using namespace std;

// class trieNode {
// public:
//     char data;
//     trieNode* children[26];
//     int childCount;
//     bool isTerminal;

//     trieNode(char d) {
//         data = d;
//         for (int i = 0; i < 26; i++) {
//             children[i] = NULL;
//         }
//         childCount=0;
//         isTerminal = false;
//     }
// };

// class trie {
// public:
//     trieNode* root;

//     trie() {
//         root = new trieNode('\0');
//     }  

//     void insertUtil(trieNode* root, string word) {
//         // base case
//         if (word.length() == 0) {
//             root->isTerminal = true;
//             return;
//         }

//         // assumption: the word will be in caps
//         int index = word[0] - 'a';
//         trieNode* child;

//         // present
//         if (root->children[index] != NULL) {
//             child = root->children[index];
//         } else {
//             // absent
//             child = new trieNode(word[0]);
//             root->childCount++;
//             root->children[index] = child;
//         }

//         // recursion
//         insertUtil(child, word.substr(1));
//     }

//     void insertWord(string word) {
//         insertUtil(root, word);
//     }

//     bool searchUtil(trieNode* root, string word) {
//         // base case
//         if (word.length() == 0) {
//             return root->isTerminal;
//         }

//         int index = word[0] - 'a';
//         trieNode* child;

//         // present
//         if (root->children[index] != NULL) {
//             child = root->children[index];
//         } else {
//             // absent
//             return false;
//         }

//         // recursion
//         return searchUtil(child, word.substr(1));
//     }

//     bool searchWord(string word) {
//         return searchUtil(root, word);
//     }
// };

// void printSuggestions(trieNode* curr, vector<string> &temp, string prefix){
//     if(curr->isTerminal){
//         temp.push_back(prefix);
//         //return;
//     }

//     for(char ch = 'a'; ch<='z';ch++){
//         trieNode* nxt = curr->children[ch-'a'];

//         if(nxt!=NULL){
//             prefix.push_back(ch);
//             printSuggestions(nxt,temp,prefix);
//             prefix.pop_back();
//         }
//     }
// }

// vector<vector<string>> getSuggestions(string str){
//     trieNode* prev = root;
//     vector<vector<string>> output;
//     string prefix = "";

//     for(int i=0;i<str.length();i++){
//         char lastChar = str[i];

//         prefix.push_back(lastChar);

//         //check for last char
//         trieNode* curr = prev->children[lastChar-'a'];

//         //not found then break
//         if(curr==NULL){
//             break;
//         }
//         //found
//         vector<string> temp;
//         printSuggestions(curr,temp,prefix);

//         output.push_back(temp);
//         temp.clear();
//         prev = curr;
//     }
//     return output;
// }

// vector<vector<string>> phoneDir(vector<string>&contactList, string &queryStr){
//     //creation of trie
//     trie* t = new trie();

//     //insert all contacts into the trie
//     for(int i=0;i<contactList.size();i++){
//         string str = contactList[i];
//         t->insertWord(str);
//     }
//     //return ans
//     return getSuggestions(queryStr);
// }

// int main() {
//     vector<string> contactList = {
//         "code",
//         "coding",
//         "coder",
//         "coley"
//     };

//     string s = "coding";

//     cout<<phoneDir(contactList,s)<<endl;
//     return 0;
// }


/* in above we are getting error in getSuggestions as it needed to work with root but as it was out of class trie it can't accessible to it therefore we written it in the class itself in the below code*/


#include <bits/stdc++.h>
using namespace std;

class trieNode {
public:
    char data;
    trieNode* children[26];
    int childCount;
    bool isTerminal;

    trieNode(char d) {
        data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class trie {
public:
    trieNode* root;

    trie() {
        root = new trieNode('\0');
    }  

    void insertUtil(trieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        trieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new trieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(trieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        trieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    void printSuggestions(trieNode* curr, vector<string> &temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            trieNode* nxt = curr->children[ch - 'a'];

            if (nxt != NULL) {
                prefix.push_back(ch);
                printSuggestions(nxt, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        trieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastChar = str[i];
            prefix.push_back(lastChar);
            trieNode* curr = prev->children[lastChar - 'a'];

            if (curr == NULL) {
                break;
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDir(vector<string>& contactList, string &queryStr) {
    trie t;

    for (const string& str : contactList) {
        t.insertWord(str);
    }

    return t.getSuggestions(queryStr);
}

int main() {
    vector<string> contactList = {
        "code",
        "coding",
        "coder",
        "coley"
    };

    string s = "coding";

    vector<vector<string>> result = phoneDir(contactList, s);
    for (const auto& suggestions : result) {
        for (const string& suggestion : suggestions) {
            cout << suggestion << " ";
        }
        cout << endl;
    }
    return 0;
}

