angular.module('mocks' ,[])
.controller('MyController' , function ( $scope , $http ) {
	var authToken;

	$http.get('/auth')
	.success( function ( data, status, headers, config) {

		authToken = headers('A-Token');
		$scope.authToken = headers('A-Token');
		$scope.users = data;

	});

	$scope.saveMessage = function ( msg ) {
		$scope.status = 'saving...';
		$http.post('/add-msg' , msg , {
			headers : {'Authorization' : authToken}
		}).success(function(data, status, headers, config) {
			$scope.status = '';
		}).error(function(data, status, headers, config ) {
			$scope.status = 'failed';
		});
	};
});