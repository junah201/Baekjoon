#include <bits/stdc++.h>
using namespace std;

int N;
struct Node
{
    int left;
    int right;
} tree[30];

void preorder(int idx)
{
    printf("%c", idx + 'A');
    if (tree[idx].left)
        preorder(tree[idx].left);
    if (tree[idx].right)
        preorder(tree[idx].right);
}

void inorder(int idx)
{
    if (tree[idx].left)
        inorder(tree[idx].left);
    printf("%c", idx + 'A');
    if (tree[idx].right)
        inorder(tree[idx].right);
}

void postorder(int idx)
{
    if (tree[idx].left)
        postorder(tree[idx].left);
    if (tree[idx].right)
        postorder(tree[idx].right);
    printf("%c", idx + 'A');
}

int main()
{
    scanf("%d", &N);
    for (char i = 0, a, b, c; i < N; i++)
    {
        scanf(" %c %c %c", &a, &b, &c);
        if (b == '.')
            tree[a - 'A'].left = 0;
        else
            tree[a - 'A'].left = b - 'A';
        if (c == '.')
            tree[a - 'A'].right = 0;
        else
            tree[a - 'A'].right = c - 'A';
    }
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    return 0;
}