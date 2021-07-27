function Graph(v) {
	this.vertices = v
	this.edges = 0
	this.adj = []
	this.marked = []
	this.edgeTo = []
	this.pathTo = pathTo
	this.hasPathTo = hasPathTo
	this.showPath = showPath

	function hasPathTo(v) {
		return this.marked[v]
	}

	function pathTo(source, v) {
		if (!this.hasPathTo(v)) {
			return undefined
		}
		var path = []
		for (var i = v; i != source; i = this.edgeTo[i]) {
			path.push(i)
		}
		path.push(source)
		return path
	}

	function showPath() {
		var str = ''
		while (path.length > 0) {
			if (path.length > 1) {
				str += path.pop() + '-'
			} else {
				str += path.pop()
			}
		}
		console.log(str)
	}

	for (var i = 0; i < this.vertices; i++) {
		this.marked[i] = false
	}
	for (var i = 0; i < this.vertices; i++) {
		this.adj[i] = []
	}
	this.addEdge = addEdge
	this.showGraph = showGraph
	this.dfs = dfs
	this.bfs = bfs

	function addEdge(v, w) {
		this.adj[v].push(w)
		this.adj[w].push(v)
		this.edges++
	}

	function showGraph() {
		var str = ''
		for (var i = 0; i < this.adj.length; i++) {
			str += i + ' -> ' + this.adj[i].join(', ') + '\n'
		}
		console.log(str)
	}

	function dfs(v) {
		if (this.marked[v] === true) return
		this.marked[v] = true
		if (this.adj[v] !== undefined) {
			//console.log('visited: ' + v)
		}
		for (var i = 0; i < this.adj[v].length; i++) {
			var w = this.adj[v][i]
			if (!this.marked[w]) {
				this.dfs(w)
			}
		}
	}

	function bfs(v) {
		var query = []
		this.marked[v] = true
		query.push(v)
		while (query.length) {
			var w = query.shift()
			if (this.adj[w] !== undefined) //console.log('visited: ' + w)
			for (var i = 0; i < this.adj[w].length; i++) {
				var k = this.adj[w][i]
				if (!this.marked[k]){
					this.edgeTo[k] = w
					this.marked[k] = true
					query.push(k)
				}
			}
		}
	}
}

function generateGraph(n) {
	var graph = new Graph(n)
	for (var i = 0; i < n - 1; i++) {
		for (var j = i + 1; j < n; j ++) {
			graph.addEdge(i, j)
		}
	}
	return graph
}

var graph = generateGraph(10000)

graph.showGraph()
var start = +new Date()
graph.dfs(0)
console.log(+new Date() - start)

graph.marked = []
for (var i = 0; i < graph.vertices; i++) {
	graph.marked[i] = false
}
var start2 = +new Date()
graph.bfs(0)
console.log(+new Date() - start2)
// var path = graph.pathTo(0, 4)
// graph.showPath(path)














