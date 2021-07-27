var initData = []
function init(n) {
	for (var i = 0; i < n; i++) {
		initData[i] = Math.floor(Math.random() * (n + 1))
	}
}
init(10);

function CArray(arr) {
	this.data = arr.map(function(i){return i})
	this.init = init
	this.swap = swap
	this.gaps = [701, 301, 132, 57, 23, 10, 4, 1]
	this.bubbleSort = bubbleSort
	this.quickSort = quickSort
	this.selectionSort = selectionSort
	this.insertionSort = insertionSort
	this.shellSort = shellSort
	this.mergeSort = mergeSortA

	function quickSort() {
		this.data = sort(this.data)
		function sort(arr) {
			if (arr.length < 2) return arr
			var base = arr[0],
				left = [],
				right = []
			for (var i = 1; i < arr.length; i++) {
				arr[i] > base ? right.push(arr[i]) : left.push(arr[i])
			}
			return sort(left).concat(base, sort(right))
		}
	}

	function mergeSortA() {
		this.data = mergeSort(this.data)
	}

	function merge(arr1, arr2) {
		var res = []
		while(arr1.length > 0 || arr2.length > 0) {
			if (arr1.length > 0 && arr2.length > 0) {
				arr1[0] < arr2[0] ? res.push(arr1.shift()) : res.push(arr2.shift())
			} else {
				arr1[0] !== undefined ? res.push(arr1.shift()) : res.push(arr2.shift())
			}
		}
		return res
	}

	function mergeSort(arr) {
		if (arr.length === 1) return arr
		var mid = Math.floor(arr.length / 2)
		var arr1 = arr.slice(0, mid)
		var arr2 = arr.slice(mid)
		return merge(mergeSort(arr1), mergeSort(arr2))
	}

	function shellSort() {
		var arr = this.data
		for (var g = 0; g < this.gaps.length; g++) {
			for (var i = this.gaps[g]; i < arr.length; i++) {
				var temp = arr[i]
				for (var j = i; j >= this.gaps[g] && arr[j - this.gaps[g]] > temp; j -= this.gaps[g]) {
					arr[j] = arr[j - this.gaps[g]]
				}
				arr[j] = temp
			}
		}
	}

	function insertionSort() {
		var arr = this.data
		var temp, j
		for (var i = 1; i < arr.length; i++) {
			temp = arr[i]
			j = i
			while (j > 0 && arr[j - 1] > temp) {
				arr[j] = arr[j - 1]
				j--
			}
			arr[j] = temp
		}
	}

	function selectionSort() {
		var arr = this.data
		for (var i = 0; i < arr.length - 1; i++) {
			for (var j = i + 1; j < arr.length; j++) {
				if (arr[i] > arr[j]) {
					this.swap(arr, i, j)
				}
			}
		}
	}

	function bubbleSort() {
		var arr = this.data
		for (var i = 0; i < arr.length; i++) {
			for (var j = 0; j < arr.length - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					this.swap(arr, j, j + 1)
				}
			}
		}
	}

	function swap(arr, i, j) {
		var temp = arr[i]
		arr[i] = arr[j]
		arr[j] = temp 
	}

}
// var a = new CArray(initData)
// var start = +new Date()
// a.bubbleSort()
// console.log(`bubble sort take: ${+new Date() - start}s`)

// var a = new CArray(initData)
// var start = +new Date()
// a.selectionSort()
// console.log(`selection sort take: ${+new Date() - start}s`)

// var a = new CArray(initData)
// var start = +new Date()
// a.insertionSort()
// console.log(`insertion sort take: ${+new Date() - start}s`)

// var a = new CArray(initData)
// var start = +new Date()
// a.shellSort()
// console.log(`shell sort take: ${+new Date() - start}s`)

// var a = new CArray(initData)
// var start = +new Date()
// a.mergeSort()
// console.log(`merge sort take: ${+new Date() - start}s`)

var a = new CArray(initData)
var start = +new Date()
a.quickSort()
console.log(`quick sort take: ${+new Date() - start}s`)
console.log(a.data)

var a = new CArray(initData)
var start = +new Date()
a.data.sort()
console.log(`native sort take: ${+new Date() - start}s`)





















