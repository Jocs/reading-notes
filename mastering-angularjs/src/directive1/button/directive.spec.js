describe('button directive' , function () {
	var $compile, $rootScope, $scope;
	beforeEach(module('button'));
	beforeEach(inject(function (_$compile_ , _$rootScope_) {
		$compile = _$compile_;
		$rootScope = _$rootScope_;
		$scope = $rootScope.$new();
	}));

	it('add a "btn" to the element className' , function () {
		var element = $compile("<button>Click Me</button>")($scope);
		expect(element.hasClass('btn')).toBeTruthy();
	});

	it('should add a "btn-success" className to the button element' , function () {
		var element = $compile('<button type="submit">Click Me</button>')($scope);
		expect(element.hasClass('btn-success')).toBe(true);
	});

	it('should add a "btn-large" className to the button element' , function () {
		var element = $compile('<button type="submit" size="large">Click Me</button>')($scope);
		expect(element.hasClass('btn-success')).toBe(true);
	});
});