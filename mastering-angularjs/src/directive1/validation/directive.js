angular.module('validation' , [])
.directive('validateEqual' , function() {
	return {
		restrict :'A',
		require : 'ngModel',
		link : function (scope, element, attrs, ngModelCtrl){
			function isValidate( value ) {
				var valid = (value === scope.$eval(attrs.validateEqual));
				console.log(valid)
				ngModelCtrl.$setValidity('equal' , valid);
				return valid ? value : undefined; 
			}

			ngModelCtrl.$parsers.push(isValidate);
			ngModelCtrl.$formatters.push(isValidate);

			scope.$watch(attrs.validateEqual, function( newValue){
				isValidate(ngModelCtrl.$viewValue);
			});
		}
	};
});
