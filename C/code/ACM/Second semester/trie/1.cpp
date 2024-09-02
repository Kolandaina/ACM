#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Trie树节点的结构体
struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool is_end;
};

// 插入字符串s到Trie树中
void insert(TrieNode *root, const string &s)
{
    TrieNode *node = root;
    for (char ch : s)
    {
        if (node->children.count(ch) == 0)
        {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->is_end = true;
}

// 在Trie树中查找字符串s的结尾节点
TrieNode *match(TrieNode *root, const string &s)
{
    TrieNode *node = root;
    for (char ch : s)
    {
        if (node->children.count(ch) == 0)
        {
            return nullptr;
        }
        node = node->children[ch];
    }
    return node;
}

// 计算以给定节点为根节点的Trie子树中的字符串数量
int count_patterns(TrieNode *node)
{
    int count = 0;
    if (node->is_end)
    {
        count += 1;
    }
    for (auto &entry : node->children)
    {
        count += count_patterns(entry.second);
    }
    return count;
}

int main()
{
    int n, q;
    cin >> n >> q;

    // 构建Trie树
    TrieNode *root = new TrieNode();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(root, s);
    }

    // 处理每个查询
    for (int i = 0; i < q; i++)
    {
        string t;
        cin >> t;

        // 在Trie树中查找t的结尾节点
        TrieNode *end_node = match(root, t);

        // 计算以end_node为根节点的Trie子树中的字符串数量
        int count = count_patterns(end_node);

        // 输出答案
        cout << count << endl;
    }
    return 0;
}
