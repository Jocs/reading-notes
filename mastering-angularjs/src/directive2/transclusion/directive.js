angular.module('tran' , [])
.controller('MainController' , function( $scope ){
	$scope.model = {
		show : true,
		count : 0
	}
})
.directive('if' , function(){
	return {
		transclude : 'element',
		priority: 500,
		compile : function(element, attr, transcludeFn){
			return function postLink(scope, element, attr){
				var childElement, childScope;

				scope.$watch(attr.if , function(newValue){
					if(childElement){
						childElement.remove();
						childScope.$destroy();
						childScope = undefined;
						childElement = undefined;
					}
					if(newValue){
						childScope = scope.$new();
						childElement = transcludeFn(childScope, function( clone ) {
							element.after(clone);
						});
					}
				});
			}
		}
	}
})