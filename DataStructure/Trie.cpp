#include <iostream>
#include <string>

#define N_ALPHABATS 26

using namespace std;

class TrieNode {
public:
    TrieNode* child[N_ALPHABATS];
    bool isTerm;

    TrieNode() {
        isTerm = false;

        for (int i = 0; i < N_ALPHABATS; i++) {
            child[i] = NULL;
        }
    }

    ~TrieNode() {
        for (int i = 0; i < N_ALPHABATS; i++) {
            if (child[i] != NULL) {
                delete child[i];
            }
        }
    }

    int toNum(char c) {
        return tolower(c) - 'a';
    }

    void insert(const char* words) {
        if (*words == '\0') {
            isTerm = true;
            return;
        }

        int next = toNum(*words);

        if (child[next] == NULL) {
            child[next] = new TrieNode;
        }

        child[next]->insert(words + 1);
    }

    bool find(const char* words) {
        if (*words == '\0') {
            return isTerm;
        }

        int next = toNum(*words);
        if (child[next] == NULL) {
            return false;
        }

        return child[next]->find(words + 1);
    }
};


int main(void) {
    TrieNode root;

    string words[5];

    words[0] = "ABC";
    words[1] = "ABCDE";
    words[2] = "IJK";
    words[3] = "IJKL";
    words[4] = "IJKLM";

    for (int i = 0; i < 5; i++) {
        root.insert(words[i].c_str());
    }


    for (int i = 0; i < 5; i++) {
        if (root.find(words[i].c_str())) {
            cout << words[i] << "가 존재합니다." << endl;
        }
        else {
            cout << words[i] << "가 존재하지 않습니다." << endl;
        }
    }

    string Xwords[5];

    Xwords[0] = "ABSTRACT";
    Xwords[1] = "GOOD";
    Xwords[2] = "NICE";
    Xwords[3] = "YUNBIN";
    Xwords[4] = "NAME";

    for (int i = 0; i < 5; i++) {
        if (root.find(Xwords[i].c_str())) {
            cout << Xwords[i] << "가 존재합니다." << endl;
        }
        else {
            cout << Xwords[i] << "가 존재하지 않습니다." << endl;
        }
    }

    return 0;
}
