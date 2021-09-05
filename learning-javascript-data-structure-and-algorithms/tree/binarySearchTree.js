export class Node {
  constructor(key) {
    this.key = key
    this.left = null
    this.right = null
  }
}

export default class BinarySearchTree {
  constructor() {
    this.root = null
  }

  insertNode(node, key) {
    if (key <= node.key) {
      if (!node.left) {
        node.left = new Node(key)
      } else {
        this.insertNode(node.left, key)
      }
    } else {
      if (!node.right) {
        node.right = new Node(key)
      } else {
        this.insertNode(node.right, key)
      }
    }
  }

  insert(key) {
    if (!this.root) {
      this.root = new Node(key)
    } else {
      return this.insertNode(this.root, key)
    }
  }

  searchNode(node, key) {
    if (node.key === key) {
      return true
    } else if (key < node.key && node.left) {
      return this.searchNode(node.left, key)
    } else if (key > node.key && node.right) {
      return this.searchNode(node.right, key)
    }

    return false
  }

  search(key) {
    if (!this.root) {
      return false
    } else {
      return this.searchNode(this.root, key)
    }
  }

  inOrderTraverse(callback) {
    const travel = (node, cb) => {
      if (node.left) travel(node.left, cb)
      cb(node)
      if (node.right) travel(node.right, cb)
    }
    if (!this.root) {
      return
    } else {
      travel(this.root, callback)
    }
  }

  preOrderTraverse(callback) {
    const travel = (node, cb) => {
      cb(node)
      if (node.left) travel(node.left, cb)
      if (node.right) travel(node.right, cb)
    }
    if (!this.root) {
      return
    } else {
      travel(this.root, callback)
    }
  }

  postOrderTraverse(callback) {
    const travel = (node, cb) => {
      if (node.left) travel(node.left, cb)
      if (node.right) travel(node.right, cb)
      cb(node)
    }
    if (!this.root) {
      return
    } else {
      travel(this.root, callback)
    }
  }

  min() {
    let current = this.root
    while (current && current.left) {
      current = current.left
    }
    return current
  }

  max() {
    let current = this.root
    while (current && current.right) {
      current = current.right
    }
    return current
  }

  removeNode(node, key) {
    if (key < node.ley) {
      if (node.left) {
        node.left = this.removeNode(node.left, key)
      }
    } else if (key > node.key) {
      if (node.right) {
        node.right = this.removeNode(node.right, key)
      }
    } else {
      if (!node.left && !node.right) {
        node = null
      } else if (node.left && node.right) {
        node.key = node.right.key
        node.right = this.removeNode(node.right, node.right.key)
      } else {
        node = node.left || node.right
      }
    }

    return node
  }

  remove(key) {
    if (!this.serach(key)) {
      return false
    } else {
      this.root = this.removeNode(this.root, key)
      return true
    }
  }
}