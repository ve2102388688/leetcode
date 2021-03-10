#ifndef MYCOMMON_H_
#define MYCOMMON_H_
#include <iostream>
#include <vector>
#include <queue>
#include <stack>


/******************************* Definition for a ListNode *****************************/ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/** \brief      creatList  创建链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 * 
 *  \param[in] s 输入数组
 *  \return      返回链表
 */
ListNode* creatList(std::vector<int>& s){
    ListNode *dummy = new ListNode(0);           /**<要保证正序，需要一个head来记住，创建完成后直接返回head->next*/
    ListNode *p = dummy;

    /**<正序创建链表 */
    for (int i = 0; i < s.size(); ++i){
        ListNode *t = new ListNode(s[i]);
        p->next = t;
        p = t;
    }
    p->next = nullptr;

    ListNode* ans = dummy->next;                /**<注意delete和返回的顺序，因此有一个临时变量 */
    delete dummy;
    return ans;
}

/** \brief      printList  输出链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 * 
 *  \param[in] head 输入数组
 *  \return         void
 */
void printList(ListNode* head){
    for (ListNode* p = head; p != nullptr; p = p->next) 
        std::cout << p->val << " -> ";
}

/** \brief      freeList  释放链表内存
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-13
 *  \remark     使用递归
 * 
 *  \param[in] head 输入链表
 *  \return         void
 */
void freeList(ListNode* head){
    if(head == NULL)
        return;
    freeList(head->next);
    delete head->next;
}






/******************************* Definition for a TreeNode *****************************/ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(TreeNode *rhs) : val(rhs->val), left(rhs->left), right(rhs->right) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/** \brief      creatList  数组建树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 * 
 *  \param[in] s 输入数组
 *  \return      返回树的根节点
 */
TreeNode* creatTree(std::vector<int> nums, int i){
    if(i >= nums.size() || nums[i] == -1)               /**<出现无效下标 或者值为1均返回nullptr */
        return nullptr;

    TreeNode *root = new TreeNode(nums[i]);             /**<创建根节点 */
    root->left = creatTree(nums, 2*i+1);                /**<创建左子树 */
    root->right = creatTree(nums, 2*i+2);               /**<创建右子树 */

    return root;
}

/** \brief      freeTree  释放内存
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     Valgrind已经通过测试，没有内存泄漏 
 *  \remark     valgrind --tool=memcheck --leak-check=full ./_1
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         void
 */
void freeTree(TreeNode* root) {
    if(root == nullptr)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

/** \brief      printTree  层序打印二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         void
 */
void printTree(TreeNode* root) {
    if(root == nullptr)
        return;

    std::queue<TreeNode*> Q;
    Q.push(root);

    while (!Q.empty()) {
        TreeNode *node = Q.front(); Q.pop();
        std::cout << node->val << " ";
        if (node->left) Q.push(node->left);
        if(node->right)  Q.push(node->right);
    }
}

/** \brief      traverseIn 先序非递归遍历
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return       	void
 */
void traverseIn(TreeNode* root) {
    if(root == nullptr)
        return ;
    
    std::stack<TreeNode*> sta;
    TreeNode *p = root;
    while (!sta.empty() || p) {			    /**<什么时候栈空了但是p不空？根节点遍历完成即将遍历根的右子树 */
        while(p) {               		    /**<一直向左走到底，先压入根结点再向左走 */
		    std::cout << p->val << " ";  /**<do something */
            sta.push(p);
            p = p->left;
        }

        p = sta.top(); sta.pop();		/**<弹出的是根结点 */
        p = p->right; 					/**<处理右子树 */

    }
}

/** \brief      traversePre 中序非递归遍历
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return       	void
 */
void traversePre(TreeNode* root) {
    if(root == nullptr)
        return ;
    
    std::stack<TreeNode*> sta;
    TreeNode *p = root;
    while (!sta.empty() || p) {			/**<什么时候栈空了但是p不空？根节点遍历完成即将遍历根的右子树 */
        while(p) {               		/**<一直向左走到底，先压入根结点再向左走 */
            sta.push(p);
            p = p->left;
        }

        p = sta.top(); sta.pop();		/**<弹出的是根结点 */
		std::cout << p->val << " ";     /**<do something */
        p = p->right; 					/**<处理右子树 */
    }
}







/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/



// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


#endif