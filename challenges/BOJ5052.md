# 문제
전화번호 목록
## 문제 원본
문제의 원본은 [여기서](https://www.acmicpc.net/problem/5052) 확인하세요.

## 분류
* Trie (Prefix Tree) 자료구조

# 풀이

Trie 구조에 번호를 모두 추가 한후, 모든 전화번호를 각각 검색하는 과정에서 Prefix중 isTerm == true인 경우를 찾는다. 이 경우, 일관성이 깨짐

``` c++
#include <iostream>
#include <vector>
#include <string>

#define N_NUMBER 10

using namespace std;


struct TrieNode {
    TrieNode* child[N_NUMBER];
    bool isTerm;
};


TrieNode* newNode() {
    TrieNode* node = new TrieNode;
    node->isTerm = false;
    for (int i = 0; i < N_NUMBER; i++) {
        node->child[i] = NULL;
    }

    return node;
}


int toNum(char c) {
    return c - '0';
}


// Trie에 주어진 words를 추가한다.
void insert(TrieNode* tn, const char* words) {
    if(*words == '\0') {
        tn->isTerm = true;
        return;
    }

    int next = toNum(*words);

    if (tn->child[next] == NULL) {
        tn->child[next] = newNode();
    }

    insert(tn->child[next], words + 1);
}


bool hasPrefixNumber(TrieNode* tn, const char* words) {
    // Prefix인 번호가 없이 문자열 끝까지 도달한 경우 false
    if (*words == '\0') {
        return false;
    }

    // Prefix인 번호가 있는 경우 true
    if (tn->isTerm == true) {
        return true;
    }

    int next = toNum(*words);
    return hasPrefixNumber(tn->child[next], words + 1);
}


void destroyAll(TrieNode* tn) {
    for (int i = 0; i < N_NUMBER; i++) {
        // 자식이 있으면 자식들을 먼저 지우고
        if (tn->child[i] != NULL) {
            destroyAll(tn->child[i]);
        }
    }
    // 자식이 없다면 자신을 메모리 헤제한다.
    delete tn;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int nCase;
    cin >> nCase;


    TrieNode* root;
    for (int i = 0; i < nCase; i++) {
        int nNumbers;
        cin >> nNumbers;

        root = newNode();

        vector<string> phoneNumbers(nNumbers);
        for (int i = 0; i < nNumbers; i++) {
            cin >> phoneNumbers[i];
            insert(root, phoneNumbers[i].c_str());
        }

        bool isOkay = true;
        for (int i = 0; i < nNumbers; i++) {
            if (hasPrefixNumber(root, phoneNumbers[i].c_str())) {
                isOkay = false;
                break;
            }
        }

        if (isOkay) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

        destroyAll(root);
    }

    return 0;
}
```
