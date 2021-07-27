module.exports = function(){

	this.listSize = 0;
	this.pos = 0;
	this.dataStore = [];
	this.clear = clear;
	this.find = find;
	this.toString = toString;
	this.insert = insert;
	this.append = append;
	this.remove = remove;
	this.front = front;
	this.end = end;
	this.previous = previous;
	this.next = next;
	this.hasPrevious = hasPrevious;
	this.hasNext = hasNext;
	this.length = length;
	this.currPos = currPos;
	this.moveTo = moveTo;
	this.getElement = getElement;
	this.contains = contains;

	//helper function
	function clear () {
		delete this.dataStore;
		this.dataStore = [];
		this.listSize = this.pos = 0;
	}
	function find ( element ) {
		for(var i = 0, ii = this.dataStore.length; i < ii; i ++){
			if(this.dataStore[i] === element) return i;
		}
		return -1;
	}
	function toString() {
		return this.dataStore;
	}
	/**
	 * element and after are both elements.
	 * @param  {[all]} element [the element to be insert] !after is not index;
	 * @param  {[sll]} after   [this element which thi inserted element will be after it]
	 * @return {[boolean]}         [if the insert operation success return true else return false]
	 */
	function insert (element, after) {
		var insertIndex = this.dataStore.indexOf(after);
		if(insertIndex > -1){
			this.dataStore.splice(insertIndex + 1, 0, element);
			this.listSize ++;
			return true;
		} else return false;
	}
	/**
	 * this function is used to add a element to the last of list
	 * @return {[any]} [the element to be added]
	 */
	function append ( element ) {
		this.dataStore[this.listSize ++ ] = element;
	}
	/**
	 * this method is used to remove one element of dataList 
	 * @param  {[any]} element [the element to be added]
	 * @return {[boolean]} [if operation success return true else return the error message]
	 */
	function remove (element) {
		var removeIndex = this.find(element);
		if(removeIndex > -1){
			this.dataStore.splice(removeIndex, 1);
			this.listSize --;
			return true;
		} else {
			return false;
		}
	}
	/**
	 * this method is used to move the current position to the front of listStroe;
	 * @return {[type]} [description]
	 */
	function front () {
		this.pos = 0;
	}
	/**
	 * this mothod is used to move the position to the end of the listStore
	 * @return {[type]} [description]
	 */
	function end () {
		this.pos = this.listSize - 1;
	}
	function previous() {
		if(this.hasPrevious()) return this.dataStore[ -- this.pos ];
		else return false;
	}
	function hasPrevious () {
		return this.pos > 0;
	}
	function next () {
		if(this.hasNext()) return this.dataStore[ ++ this.pos ];
		else return false;
	}
	function hasNext() {
		return this.pos < this.listSize - 1;
	}
	function length() {
		return this.listSize;
	}
	function moveTo (position) {
		this.pos = position;
	}
	function currPos () {
		return this.pos;
	}
	function getElement () {
		return this.dataStore[this.pos];
	}
	/**
	 * this mothod is use to justify wherther one element is in dataStore
	 * @param  {[any]} element [description]
	 * @return {[boolean]}  if contains return true else return false;
	 */
	function contains (element) {
		return ~this.dataStore.find(element);
	}

};










