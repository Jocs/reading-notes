describe('pagination directive' , function() {
	var $scope, element, lis;
	beforeEach(module('pageApp'));
	beforeEach(inject(function($compile, $rootScope) {
		$scope = $rootScope.$new();
		$scope.numPages = 8;
		$scope.currentPage = 4;
		element = 
		$compile('<pagination num-pages = "numPages" current-page="currentPage"></pagination>')($scope);
		// why?
		$scope.$digest();
		lis = function(){return element.find('li')};
	}));

	it('should has the number eq to pagenum' , function() {
		for(var i =0; i < $scope.numPages; i ++) {
			//trim()方法用来清除字符串两端的空白符，''+ (i + 1),用来把数字转化为字符串
			expect(lis().eq( i + 1 ).text().trim()).toEqual('' + (i + 1));
		}
	});

	it('the current page should has a "active" className' , function () {
		var currentItem = lis().eq($scope.currentPage);
		expect(currentItem.hasClass('active')).toBeTruthy();
	});

	it('if the current current page equal total page numbers, the "NEXT" should be disabled' , function () {
		$scope.currentPage = 8;
		$scope.$digest();
		var next = lis().eq($scope.numPages + 1 );
		expect(next.hasClass('disabled')).toBeTruthy();
	});

	it('should change current page , when a page is clicked' , function(){
		var page2 = lis().eq( 2 ).find('a');
		//引用jQuery才能够出发click事件//单元测试需要引入click事件吗？？？
		page2.click();
		$scope.$digest();
		expect($scope.currentPage).toEqual(2);
	});

	it('if the current page is the last, "NEXT" button will be unuseful' , function () {
		$scope.currentPage = 8;
		var next = lis().eq(-1).find('a').eq(0);
		next.click();
		$scope.$digest();
		expect($scope.currentPage).toBe(8);
	});

	it('change the nums of pages , the items length shold be change' , function () {
		$scope.numPages = 12;
		$scope.$digest();
		expect(lis().length).toBe(14);
		expect(lis().eq(-1).text().trim()).toBe('Next');
		expect(lis().eq(0).text().trim()).toBe('Previous');
	});
})









