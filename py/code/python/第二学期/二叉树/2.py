# 先序创建（递归）二叉树，再先序、中序、后续遍历（递归）
# A
# B
# #
# D
# F
# #
# #
# G
# #
# #
# C
# #
# #
class BinaryTreeNode:
    def __init__(self):
        self.data = "#"
        self.lchild = None
        self.rchild = None


class BinaryTree:
    def __init__(self):
        self.t = BinaryTreeNode()

    # 先序创建二叉树
    def CreateBinaryTree(self):
        element = input()
        if element == "#":
            return None
        self.t = BinaryTreeNode()
        self.t.data = element
        self.t.lchild = self.CreateBinaryTree()
        self.t.rchild = self.CreateBinaryTree()
        return self.t

    # 先序遍历二叉树
    def PreOrder(self, root):
        if root is not None:
            self.VisitNode(root)
        self.PreOrder(root.lchild)
        self.PreOrder(root.rchild)

    # 中序遍历二叉树
    def InOrder(self, root):
        if root is not None:
            self.InOrder(root.lchild)
        self.VisitNode(root)
        self.InOrder(root.rchild)

    # 后续遍历二叉树
    def PostOrder(self, root):
        if root is not None:
            self.PostOrder(root.lchild)
        self.PostOrder(root.rchild)
        self.VisitNode(root)

    # 访问二叉树某一个结点
    def VisitNode(self, node):
        if node.data is not "#":
            print(node.data, end=" ")


if __name__ == "__main__":
    T = BinaryTree()
    root = T.CreateBinaryTree()
    print("先序遍历结果：", end="")
    T.PreOrder(root)
    print("中序遍历结果：", end="")
    T.InOrder(root)
    print("后序遍历结果：", end="")
    T.PostOrder(root)
