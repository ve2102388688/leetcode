# 二、 N叉树与回溯法

## 1 N叉树介绍
二叉树是最特殊的树，只有左右两个分支，而N叉树每个结点<font color=#ff0000>**最多**</font>N个分支。如图所示，一个三叉树
<div align=center><img src="tree_picture/6.png" /></div>

一种简易的实现，
```C++
struct NTreeNode {
    int val;
    vector<NTreeNode*> children;     /**<多叉树 */
}
```

### 1.1 N叉树的前序遍历 589
N叉树的遍历只有前序、后序、层序，没有中序，因为中序有歧义
```C++
void traverse(NTreeNode *root){
    if(root == nullptr) return ;
    // 先序遍历
    for (const auto &e : root->children)
        traverse(e);
}
```

### 1.2 N叉树的后序遍历 590
```C++
void traverse(NTreeNode *root){
    if(root == nullptr) return ;
    for (const auto &e : root->children)
        traverse(e);
    // 后序遍历
}
```

### 1.3 N叉树的层序遍历 429
下面的代码和二叉树的层序代码完全一致，区别：<font color=#ff0000>**不用单独写左右入队列的两句代码，直接使用一个循环即可**</font>
```C++
void traverseLevel(NTreeNode* root) {
    if(root == nullptr)
        return ;
    
    queue<NTreeNode *> Q;
    Q.push(root);									/**压入根结点 */
    while (!Q.empty()) {
        int size = Q.size();
        while (size > 0) {
            NTreeNode *node = Q.front(); Q.pop();	/**取出根结点 */
			/**<do something */
            for(const auto& e : node->children) {	/**处理结点的所有孩子 */
                Q.push(e);
            }
            --size;
        }
        /**<do something */
    }
}
```
