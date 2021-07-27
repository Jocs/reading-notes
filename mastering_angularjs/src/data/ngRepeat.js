angular.module('app2' , ['ngAnimate', 'app2.directive'])
.controller('MainController' , function ( $scope, $filter ) {
	$scope.filterWord = '';
	$scope.sortField = 'name';
	$scope.reverse = false;

	$scope.users = [
		{name: 'ransixi' , email: 'luoran1988@126.com' , desc: 'A man on the wheel'},
		{name: 'luoran1988' , email: 'RANSIXI@126.com' , desc: 'A dreaming boy'},	
		{name: 'wujingwen' , email: 'wujingwen@126.com' , desc: 'A loreal boy'},	
		{name: 'fumin' , email: 'fumin@126.com' , desc: 'A shuyun boy'},	
		{name: 'wangwei' , email: 'wangwei@126.com' , desc: 'A xujiahui boy'}
	];

	var sortByKeyword = $filter('filter')($scope.users, $scope.filterWord);
	$scope.filterUsers = $filter('orderBy')(sortByKeyword, $scope.sortField, $scope.reverse);
	//用来监控filterWord的变化，及时unpdate filterUsers
	$scope.$watchGroup(['filterWord', 'sortField', 'reverse'], function( newValue ) {
		var sortByKeyword = $filter('filter')($scope.users, $scope.filterWord);
		$scope.filterUsers = $filter('orderBy')(sortByKeyword, $scope.sortField, $scope.reverse);
	});

	$scope.$watch('filterWord' , function(newValue) {
		// 和服务器发送请求
	});

	$scope.sort = function( sortField ) {
		if($scope.sortField === sortField) {
			$scope.reverse = !$scope.reverse;
		} else {
			$scope.sortField = sortField;
			$scope.reverse = false;
		}
	};

	$scope.isSortUp = function( sortField ) {
		return $scope.sortField === sortField && !$scope.reverse;
	};

	$scope.isSortDown = function( sortField ) {
		return $scope.sortField === sortField && $scope.reverse;
	};

})
.controller('UserController' , function ( $scope ) {

	$scope.toggleSelected = function (  ) {
		$scope.isSelected = !$scope.isSelected;
	};

	

});