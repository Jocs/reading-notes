angular.module('accrodion' , [])
.controller('MainController' , function($scope){
	$scope.users = [
		{name: 'ransixi', message : 'He is a good boy!'},
		{name: 'wujingwen' , message : 'hello nice girl'},
		{name: 'fumin' , message : 'Loreal China Life Scientist'}
	];
})
.directive('accordion' , function(){

	return {
		restrict : 'E',
		controller : function(){
			this.groups = [];

			this.addGroup = function( group ){
				this.groups.push(group);
			};
			this.removeGroup = function (group) {
				var index = this.groups.indexOf(group);
				if(index != -1) this.groups.splice(index, 1);
			};

			this.closeOthers = function(group){
				angular.forEach(this.groups, function(g) {
					g.isOpened = false;
				});
			}
		}
	}
})
.directive('accordionGroup' , function() {
	return {

		restrict : 'E',
		replace : true,
		require : '^accordion',
		scope : {
			heading: '=heading'
		},
		templateUrl: 'tpl.html',
		transclude : true,
		link : function (scope, element ,attrs, ctrl) {
			scope.isOpened = false;
			ctrl.addGroup(scope);
			scope.open = function(){
				if(scope.isOpened == true) {
					ctrl.closeOthers(scope);
				} else {
					ctrl.closeOthers(scope);
					scope.isOpened = true;
				}
			};
		}
	}
});















