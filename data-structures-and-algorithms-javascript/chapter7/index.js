var Dictionary = function() {
	this.dataStore = {}
	this.add = add
	this.sortByKey = sortByKey

	function add(key, value) {
		this.dataStore[key] = this.dataStore[key] ?  this.dataStore[key] + value : this.dataStore[key] = value
	}

	function sortByKey() {
		var keys = Object.keys(this.dataStore)
		var str = ''
		keys.sort()
		for (var i = 0; i < keys.length; i++) {
			str += keys[i] + ": " + this.dataStore[keys[i]] + '\n'
		}
		return str
	}

}

var lib = new Dictionary()
var text = 'hello nice to meet you, my name is ransixi, and very glad to see you ransixi ransixi haha'
var textArray = text.split(/,\s|\s/)
textArray.forEach(function(item, index) {
	lib.add(item, 1)
})
console.log(lib.sortByKey())








