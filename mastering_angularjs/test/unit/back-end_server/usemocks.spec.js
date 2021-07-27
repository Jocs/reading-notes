describe('how to use angular mocks ?' , function () {
	var $httpBackend, $rootScope, $scope, $controller, createController , authRequestHandler;

	beforeEach(module('mocks'));

	beforeEach(inject( function( _$httpBackend_, _$rootScope_ , _$controller_) {
		$httpBackend = _$httpBackend_;
		$rootScope = _$rootScope_;
		$controller = _$controller_;
		$scope = $rootScope.$new();

		authRequestHandler = $httpBackend.whenGET('/auth')
		.respond({userId: 'userX'}, {'A-Token': 'xxx'});
		createController = function () {
			return $controller('MyController' , {
				$scope : $scope
			})
		};
	}));

	afterEach( function() {
		$httpBackend.verifyNoOutstandingExpectation();
		$httpBackend.verifyNoOutstandingRequest();
	});

	it('should get authentication from server after the controller created', function() {
		$httpBackend.expectGET('/auth');
		var controller = createController();
		$httpBackend.flush();
		expect($scope.users.userId).toBe('userX');
		expect($scope.authToken).toBe('xxx');
	});

	it('should fail authentication' , function () {
		authRequestHandler.respond(401, '');
		$httpBackend.expectGET('/auth');
		var controller = createController();
		$httpBackend.flush();
		expect($scope.status).toBeUndefined();
	});

	it('should send message to server' , function () {
		$httpBackend.expectGET('/auth');
		var controller = createController();
		$httpBackend.flush();

		$httpBackend.whenPOST('/add-msg').respond(201, '');
		$scope.saveMessage('some content');
		expect($scope.status).toBe('saving...');
		$httpBackend.flush();
		expect($scope.status).toBe('');

	});

	it('should send a auth headers', function() {
		var controller = createController();
		$httpBackend.flush();

		$httpBackend.expectPOST('/add-msg', undefined, {"Authorization":"xxx","Accept":"application/json, text/plain, */*","Content-Type":"application/json;charset=utf-8"}).respond(201, '');

		$scope.saveMessage('whatever');
		$httpBackend.flush();
	});

});















