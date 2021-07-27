angular.module('app' , [])
.controller('UsersController' , function($scope, $http ) {
	$scope.queryUsers = function () {
		$http.get('/users')
		.success(function(data) {
			$scope.users = data;
		})
		.error(function() {
			throw new Error('Nothing retrun...');
		});
	};
});