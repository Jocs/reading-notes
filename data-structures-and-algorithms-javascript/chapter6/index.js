var Node = function(element) {
	this.element = element
	this.next = null
}

var LinkedLint = function() {
	this.length = 0
	this.currentNode = null
	this.next = null
	this.find = find
	this.findPrevious = findPrevious
	this.remove = remove
	this.insert = insert
	this.advance = advance
	this.back = back
	this.show = show

	function find(item) {
		if (this.length === 0) return
		var node = this.currentNode
		var count = this.length
		while (count--) {
			if (node.element === item) return node
			node = node.next
		}
		return false
	}

	function insert(item, previous) {
		if (this.length === 0) {
			this.currentNode = new Node(item)
			this.currentNode.next = this.currentNode
		} else {
			var previousNode = this.find(previous)
			var node = new Node(item)

			node.next = previousNode.next
			previousNode.next = node
		}
		this.length++

	}

	function findPrevious(item) {
		if (this.length === 0) return false
		var node = this.currentNode
		var count = this.length
		while (count--) {
			if (node.next.element === item) return node
			node = node.next
		}
		return false
	}

	function remove(item) {
		var previousNode = this.findPrevious(item)
		var currentNode = this.find(item)
		if (this.currentNode === currentNode) this.currentNode = previousNode
		previousNode.next = currentNode.next
		currentNode.next = null
		this.length--
		return currentNode
	}

	function advance(n) {
		while(n--) {
			this.currentNode = this.currentNode.next
		}
	}
	function back(n) {
		while(n--) {
			this.currentNode = this.findPrevious(this.currentNode.element)
		}
	}
	function show() {
		return this.currentNode.element
	}
}

function killToM(n, m) {
	var linkedArray = new LinkedLint()
	linkedArray.insert(1)
	var i = 0;
	while(i < n - 1) {
		linkedArray.insert(i + 2, i + 1)
		i ++
	}
	while(linkedArray.length >= 3) {
		linkedArray.advance(m)
		var node = linkedArray.remove(linkedArray.currentNode.element)
		console.log(node)
	}
}
killToM(40, 3)








