describe('validation2 directive' , function(){
	var Users, $scope, modelValue, modelCtrl;
	beforeEach(module('sv'));
	beforeEach(inject(function(_Users_, $compile, $rootScope){
		Users = _Users_;
		$scope = $rootScope.$new();
		$compile('<form name="testForm">\
				<input type="email" unique-email name="email" ng-model="user.email"/>\
			</from>')($scope);
			modelValue = $scope.user = {};
			modelCtrl = $scope.testForm.email;
			//spyOn什么作用呢？？？
			spyOn(Users , 'query').and.callThrough();
	}));

	it('should call Users query when the view change' , function(){
		modelCtrl.$setViewValue('luoran1988@126.com');
		expect(Users.query).toHaveBeenCalled();
	});
	it('should set invalid ' , function(){
		modelValue.email = 'luoran1988@126';
		modelCtrl.$setViewValue('ransixi@126.com');
		Users.respondWith(['someuser']);
		expect(modelCtrl.$valid).toBeFalsy();
	});

	it('query shold not be called' , function() {
		modelValue.email = 'luoran1988@126';
		$scope.$digest();
		modelCtrl.$setViewValue('luoran1988@126');
		expect(Users.query).not.toHaveBeenCalled();

		modelCtrl.$setViewValue('other@126.com');
		expect(Users.query).toHaveBeenCalled();

		Users.query.calls.reset();
		modelCtrl.$setViewValue('other@126.com');
		expect(Users.query).not.toHaveBeenCalled();
	});

});