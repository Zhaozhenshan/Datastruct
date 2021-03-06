#include<iostream>
using namespace std;
//树的双亲表示法
//知识点:树的双亲表示法可以直接访问到结点的双亲，但是要访问孩子需要遍历整个表
//特点: 树的顺序结构下标代表了结点的编号，结点里面的内容表示了结点之间的关系
//     二叉树的顺序结构下标不仅仅代表了结点的编号，也代表了结点之间的逻辑关系，比如说结点和它的孩子有一个2i=孩子的逻辑关系
typedef struct{
    int data;//数据域
    int parent;//双亲的下标  约定根结点的下标为-1
}PTNode;//数组中使用到的结点
typedef struct {
    PTNode nodes[1024];
    int n;//结点数
}PTree;


//孩子兄弟表示法的存储结构
typedef struct CSNode{
    int data;//数据域
    struct CSNode *firstnode,*nextsibling;//指针域，分别代表了第一个孩子和下一个兄弟结点
}CSNode,*CSTree;
//这种方法比较灵活，最大的优点是可以方便的实现树转换为二叉树的操作，比较容易查找孩子结点 缺点是找双亲比较麻烦，如果需要，可以加一个parent指针

//孩子表示法：这种存储结构类似于哈希表中处理冲突时候的那个单链表
//特点是找子女比较直接，但是求双亲结点需要遍历整个表

//树：   先根遍历，后跟遍历
//森林:  先序遍历，中序遍历
//二叉树:先序遍历，中序遍历，他们的关系是等价的
//任何一棵树或者森林对应的二叉树B有以下两个特点：在B中没有左子树的结点全是叶子结点，因为没孩子
//                                        在森林中的每一个非叶子结点在对应的B中比对应一个叶子结点，因为最后一个孩子没有右指针最后加上最后的根
//根据二叉树的层次遍历以及每个结点的度可以构造孩子兄弟链表，只要顺序访问每一个结点就可以了。
//对于求高度来说，和二叉树一样，只需要关注左子树+1 右子树+0 非空为0即可 

