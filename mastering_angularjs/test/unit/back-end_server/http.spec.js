describe('http basic use test' , function() {
	var $scope, $rootScope, $httpBackend,controller;

	beforeEach(module('app'));
	beforeEach(inject(function(_$rootScope_ , _$httpBackend_, _$controller_) {
		$rootScope = _$rootScope_;
		$httpBackend = _$httpBackend_;
		$controller = _$controller_;

		$scope = $rootScope.$new();
		controller = $controller('UsersController' , {
			$scope : $scope
		});
	}));

	it('shoud return some right message' , function () {
		$httpBackend.whenGET('/users').respond([{name: 'ransixi'}, {name: 'wujingwen'}]);

		$scope.queryUsers();

		$httpBackend.flush();
		expect($scope.users.length).toEqual(2);
	});

	afterEach(function() {
		$httpBackend.verifyNoOutstandingExpectation();
		$httpBackend.verifyNoOutstandingRequest();
	});
});