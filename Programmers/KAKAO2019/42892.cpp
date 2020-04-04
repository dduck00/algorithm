#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct tn {
    int index;
    int x;
    int y;
    int left;
    int right;
} node;

vector<pair<pair<int, int>, int>> treeNode;
vector<node> TREE;
int depth;
vector<vector<int>> answer;

void makeTree(int headIndex, int leafIndex) {
    node& head = TREE[headIndex];
    node& leaf = TREE[leafIndex];
    if (head.x > leaf.x) {
        if (head.left == -1) {
            head.left = leaf.index;
            return;
        }
        makeTree(head.left, leafIndex);
    }
    else {
        if (head.right == -1) {
            head.right = leaf.index;
            return;
        }
        makeTree(head.right, leafIndex);
    }
}

void init() {
    int before = -1;
    for (auto node : treeNode) {
        int nowRank = node.first.first;
        if (before != nowRank) {
            before = nowRank;
            depth++;
        }
    }
    TREE = vector<node>(treeNode.size());

    for (auto NODE : treeNode) {
        TREE[NODE.second] = { NODE.second, NODE.first.second, NODE.first.first, -1, -1 };
    }

}

void frontLoop(int index) {
    if (index == -1)
        return;
    answer[0].push_back(index+1);
    frontLoop(TREE[index].left);
    frontLoop(TREE[index].right);
}

void backLoop(int index) {
    if (index == -1)
        return;
    backLoop(TREE[index].left);
    backLoop(TREE[index].right);
    answer[1].push_back(index + 1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int idx = 0;
    for (auto node : nodeinfo)
        treeNode.push_back({ {node[1], node[0]} ,idx++ });

    sort(treeNode.begin(), treeNode.end());

    init();

    for (int i = treeNode.size() - 2 ; i >= 0; i--) {
        makeTree(treeNode[treeNode.size()-1].second, treeNode[i].second);
    }
    answer.push_back(vector<int>());
    frontLoop(treeNode[treeNode.size() - 1].second);
    answer.push_back(vector<int>());
    backLoop(treeNode[treeNode.size() - 1].second);
    return answer;
}
