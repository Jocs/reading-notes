describe('ngRepeat controller test for use' , function () {
	describe('MainController' , function () {
		var $rootScope, $controller, $scope, controller;

		beforeEach(module('app2'));
		beforeEach(inject(function(_$rootScope_ , _$controller_) {
			$rootScope = _$rootScope_;
			$controller = _$controller_;
			$scope = $rootScope.$new();
			controller = $controller('MainController' , {
				$scope: $scope
			});
		}));
		it('I want the users length tobe 5' , function () {
			expect($scope.users.length).toEqual(5);
		});

		it('test the sort function' , function () {
			$scope.reverse = false;
			$scope.sort('name');
			expect($scope.reverse).toBeTruthy();
		});

		it('test the sort function' , function () {
			expect($scope.filterUsers[0].name).toEqual('fumin');
			$scope.sort('name');
			$scope.$digest();
			expect($scope.filterUsers[0].name).toEqual('wujingwen');
			$scope.sort('email');
			$scope.$digest();
			expect($scope.filterUsers[0].email).toEqual('fumin@126.com');
		});

	});
	
});