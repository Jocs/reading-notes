angular.module('button' , [])
.directive('button' , function () {
	return {
		restrict: 'E',
		compile : function(element, attrs) {
			element.addClass('btn');
			if(attrs.type === 'submit') element.addClass('btn-success');
			if(attrs.size) element.addClass('btn-' + attrs.size);
		}
	}
})