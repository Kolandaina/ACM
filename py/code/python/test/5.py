class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def buildTree(inorder_node, postorder_node):
    if not inorder_node or not postorder_node:
        return None
    root_val = postorder_node[-1]
    root = TreeNode(root_val)
    root_index = inorder_node.index(root_val)
    root.left = buildTree(inorder_node[:root_index], postorder_node[:root_index])
    root.right = buildTree(inorder_node[root_index + 1:], postorder_node[root_index:-1])
    return root


def preorderTraversal(root_node):
    if not root_node:
        return []
    res = [root_node.val]
    res += preorderTraversal(root_node.left)
    res += preorderTraversal(root_node.right)
    return res


inorder = ["D", "B", "E", "F", "A", "G", "H", "C", "K"]
postorder = ["D", "E", "F", "B", "H", "G", "K", "C", "A"]
root = buildTree(inorder, postorder)
preorder = preorderTraversal(root)
print(preorder)
