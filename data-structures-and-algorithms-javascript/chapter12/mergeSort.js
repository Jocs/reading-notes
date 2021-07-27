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

var arr = new Array(10)

for (var i = 0; i < arr.length; i++) {
	arr[i] = Math.floor(Math.random() * 111)
}

console.log(mergeSort(arr))