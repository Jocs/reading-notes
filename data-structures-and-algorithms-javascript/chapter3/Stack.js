module.exports = function(){
	this.dataStore = [];
	this.top = 0;
	this.push = push;
	this.pop = pop;
	this.peek = peek;
	this.clear = clear;
	this.length = length;
/**
 * The push() method adds one or more elements to the end of 
 * an array and returns the new length of the array. the same as Array.prototype.push
 * @param  {[any]} element [the element or elements to be added to the las of array]
 * @return {[Number]}      [return the length(this.top) of the new dataStore]
 */
	function push( element ){
		if(arguments.length === 1){
			this.dataStore[this.top ++] = element; 
			return this.top;
		} else {
			arguments.forEach(function( i ){
				this.dataStore[this.top ++] = i;
			});
			return this.top;
		}
	}
	/**
	 * The pop() method removes the last element from an array and returns that element.
	 * @return {[any]}         [return the poped element]
	 */
	function pop (){
		return this.dataStore[-- this.top];
	}
	function peek() {
		if(this.top > 0){
			return this.dataStore[this.top - 1];
		} else {
			return false;
		}
	}
	function clear() {
		this.top = 0;
	}
	function length(){
		return this.top;
	}
};















