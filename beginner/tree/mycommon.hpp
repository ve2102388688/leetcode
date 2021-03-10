#ifndef MYCOMMON_H_
#define MYCOMMON_H_
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/** \brief      creatList  数组建树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 * 
 *  \param[in] s 输入数组
 *  \param[in] i 必须为0
 *  \return      返回树的根节点
 */
TreeNode* creatTree(std::vector<int> nums, int i){
    if(i >= nums.size() || nums[i] == -1)               /**<出现无效下标 或者值为1均返回null */
        return NULL;

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
    if(root == NULL)
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

#endif