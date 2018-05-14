class Node(object):
    def __init__(self, name, left=None, right=None):
        self.name = name
        self.left = left
        self.right = right

node_e = Node('e', Node('f'), Node('g'))
node_d = Node('d', node_e, Node('u'))
node_b = Node('b', Node('c'), node_d)
node_j = Node('j', Node('l'), Node('m'))
node_k = Node('k', Node('n'), Node('o'))
node_i = Node('i', node_j, node_k)
node_q = Node('q', Node('r'), Node('s'))
node_p = Node('p', Node('t'), node_q)
node_h = Node('h', node_i, node_p)
root   = Node('a', node_b, node_h)

#def postwalk(node):
#    if node:
#        postwalk(node.left)
#        postwalk(node.right)
#        print(node.name)
#
#postwalk(root)

def print_bf(node):
    if node is None:
        return 0
    lh, rh = print_bf(node.left), print_bf(node.right)
    if node.left or node.right:
        print(node.name, lh-rh)
    return max(lh, rh) + 1

print_bf(root)
