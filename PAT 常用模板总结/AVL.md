# 平衡二叉树AVL

（1）首先要明确平衡二叉树AVL仍然是一棵二叉查找树BST，只是结构体成员变量需要加上高度（新建结点时初始值为1），因此满足BST的所有定义和性质，如数据域左<根<右，基本操作大致与BST相同，只需注意插入操作

（2）明确结点的高度、平衡因子和左旋、右旋的概念，熟悉AVL插入时的树型、判断条件和调整方法，记住P326的表格

（3）AVL考题十分固定，都是通过建树操作来解决，因此在理解的基础上牢记模板即可，注意实际操作时，大部分代码写一半即可，另一半只是把L和R换一下，写起来还算快，静态实现的模板如下：

//获得高度

int getHeight(int root) {

​    if(root == -1)

​        return 0;

​    else

​        return node[root].height;

}

//获得平衡因子

int getBalanceFactor(int root) {

​    return getHeight(node[root].lchild) - getHeight(node[root].rchild);

}

//更新高度，用于每次insert后

void updateHeight(int root) {

 node[root].height =

max(getHeight(node[root].lchild),getHeight(node[root].rchild)) + 1;

}

**//左旋**

void L(int &root) {

​    int temp = node[root].rchild;

​    node[root].rchild = node[temp].lchild;

​    node[temp].lchild = root;

​    updateHeight(root);

​    updateHeight(temp);

​    root = temp;

}

**//右旋**

void R(int &root) {

​    int temp = node[root].lchild;

​    node[root].lchild = node[temp].rchild;

​    node[temp].rchild = root;

​    updateHeight(root);

​    updateHeight(temp);

​    root = temp;

}

**//插入**

int index = 0;

void insert(int &root, int x) {

​    if(root == -1) {

​        node[index].data = x;

​        node[index].height = 1;

​        node[index].lchild = node[index].rchild = -1;

​        root = index++;

​        return;

​    }

​    if(x < node[root].data) {

​        insert(node[root].lchild, x);

​        updateHeight(root);

​        if(getBalanceFactor(root) == 2) {

​            if(getBalanceFactor(node[root].lchild) == 1) {

​                R(root);

​            } else if(getBalanceFactor(node[root].lchild) == -1) {

​                L(node[root].lchild);

​                R(root);

​            }

​        }

​    } else {

​        insert(node[root].rchild, x);

​        updateHeight(root);

​        if(getBalanceFactor(root) == -2) {

​            if(getBalanceFactor(node[root].rchild) == -1) {

​                L(root);

​            } else if(getBalanceFactor(node[root].rchild) == 1) {

​                R(node[root].rchild);

​                L(root);

​            }

​        }

​    }

}