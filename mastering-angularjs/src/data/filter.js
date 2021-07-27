angular.module('custormFilter' , [])
.filter('pagination' , function() {
	return function(inputArray, offset, pageSize) {
		var start = offset * pageSize;
		return inputArray.slice(start , start + pageSize);
	};
});