angular.module('sv' , [])
.directive('uniqueEmail' , function (Users) {
	return {
		restrict : 'AE',
		require : 'ngModel',
		link :  function (scope, element, attrs, ngModelCtrl) {
			var original;

			ngModelCtrl.$formatters.unshift(function(value){
				original = value;
				return value;
			});

			ngModelCtrl.$parsers.push(function(viewValue){
				if(viewValue !== original && viewValue) {
					Users.query({email: viewValue} , function( users ) {
						if(users.length === 0) ngModelCtrl.$setValidity('uniqueEmail', true);
						else ngModelCtrl.$setValidity('uniqueEmail', false);
					});
				}
				return viewValue;
			});
		}
	}
})
.factory('Users' , function(){
	var Users = {};
	Users.query = function(query, callback){
		Users.respondWith = function(emails){
			callback(emails);
			Users.respondWith = undefined;
		}
	};
	return Users;
});





