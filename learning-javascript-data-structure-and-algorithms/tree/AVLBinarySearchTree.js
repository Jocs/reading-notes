import BinarySearchTree, { Node } from './binarySearchTree.js'

const BALANCE_FACTOR = {
  HEAVY_LEFT: 'HEAVY_LEFT',
  SLIGHT_HEAVY_LEFT: 'SLIGHT_HEAVY_LEFT',
  HEAVY_RIGHT: 'HEAVY_RIGHT',
  SLIGHT_HEAVY_RIGHT: 'SLIGHT_HEAVY_RIGHT',
  BALANCE: 'BALANCE',
}

const getNodeHeight = (node) => {
  if (!node) return 0

  return 1 + Math.max(getNodeHeight(node.left), getNodeHeight(node.right))
}

const getBalanceFactor = (node) => {
  if (!node) return BALANCE_FACTOR.BALANCE

  const delta = getNodeHeight(node.left) - getNodeHeight(node.right)
  switch (delta) {
    case 2:
      return BALANCE_FACTOR.HEAVY_LEFT
    case 1:
      return BALANCE_FACTOR.SLIGHT_HEAVY_LEFT
    case 0:
      return BALANCE_FACTOR.BALANCE
    case -1:
      return BALANCE_FACTOR.SLIGHT_HEAVY_RIGHT
    case -2:
      return BALANCE_FACTOR.HEAVY_RIGHT
    default:
      console.error('Unhandle balance factor')
      return
  }
}

const rotateLL = (node) => {
  const temp = node.left
  node.left = temp.right
  temp.right = node

  return temp
}

const rotateRR = (node) => {
  const temp = node.right
  node.right = temp.left
  temp.left = node

  return temp
}

const rotateLR = (node) => {
  node.left = rotateRR(node.left)

  return rotateLL(node)
}

const rotateRL = (node) => {
  node.right = rotateLL(node.right)

  return rotateRR(node)
}



class AVLBinarySearchTree extends BinarySearchTree {
  constructor() {
    super()
  }

  insertNode(node, key) {
    if (key < node.key) {
      node.left = node.left ? this.insertNode(node.left, key) : new Node(key)
    } else if (key > node.key) {
      node.right = node.right ? this.insertNode(node.right, key) : new Node(key)
    }

    const balanceFactor = getBalanceFactor(node)

    if (balanceFactor === BALANCE_FACTOR.HEAVY_LEFT) {
      return key < node.key ? rotateLL(node) : rotateLR(node)
    } else if (balanceFactor === BALANCE_FACTOR.HEAVY_RIGHT) {
      return key > node.key ? rotateRR(node) : rotateRL(node)
    }

    return node
  }

  insert(key) {
    if (!this.root) {
      this.root = new Node(key)
    } else {
      console.log('xxx')
      this.root = this.insertNode(this.root, key)
    }
  }

  remove(key) {
    // TODO
  }
}

const tree = new AVLBinarySearchTree()
tree.insert(1)

tree.insert(2)

tree.insert(3)

tree.insert(4)

tree.insert(5)

tree.insert(6)
console.log(tree)