describe('validateEqual directive' , function () {
	var $scope, modelValue, modelCtrl1 , modelCtrl2;
	beforeEach(module('validation'));
	beforeEach(inject(function($rootScope, $compile){
		$scope = $rootScope.$new();
		$compile("<form name='testForm'>\
					<input name='password1' ng-model='model.password1'>\
					<input name='password2' ng-model='model.password2' validate-equal='model.password1'>\
			</form>")($scope);
		modelValue = $scope.model = {};
		modelCtrl1 = $scope.testForm.password1;
		modelCtrl2 = $scope.testForm.password2;
	}));

	it('model value change' , function(){
		modelValue.password1 = 'ransixi';
		$scope.$digest();
		expect(modelCtrl1.$viewValue).toBe('ransixi');
		expect(modelCtrl1.$modelValue).toBe('ransixi');
		expect(modelCtrl2.$valid).toBeFalsy();
		expect(modelCtrl2.$viewValue).toBe(undefined);
		modelValue.password2 = 'ransixi';
		$scope.$digest();
		expect(modelCtrl2.$valid).toBeTruthy();
		modelValue.password1 = 'different';
		$scope.$digest();
		expect(modelCtrl2.$valid).toBeFalsy();
	});

	it('should be valid' , function() {

	});
});