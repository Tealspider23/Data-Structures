#include <stdio.h>
#include <stdlib.h>

// Calculate depth of a full binary Tree from preorder 

#include <stdio.h>

int findDepth(int preorder[], int n, int index, int level) {
    // Base case: If the index exceeds the number of elements or the value at the index is -1
    if (index >= n || preorder[index] == -1)
        return level;

    // Recursive calls for left and right subtrees
    int leftDepth = findDepth(preorder, n, index + 1, level + 1);
    int rightDepth = findDepth(preorder, n, index + 2, level + 1);

    // Return the maximum depth among the left and right subtrees
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}

int main() {
    int preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    int depth = findDepth(preorder, n, 0, 0);
    printf("Depth of the full binary tree: %d\n", depth);

    return 0;
}
