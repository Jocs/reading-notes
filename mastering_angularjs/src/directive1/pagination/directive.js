angular.module('pageApp' , [])
.controller('PageController' , function( $scope ) {
	$scope.currentPage = 4;
	$scope.numPages = 8;
	$scope.onSelectPage = function (page) {
		$scope.currentPage = page;
	};
})
.directive('pagination' , function () {
	return {
		restrict : 'E',
		replace : true,
		scope : {
			numPages : '=numPages',
			currentPage : '=currentPage',
			onSelectPage : '&'
		},
		template : '<div class="pagination">\
									<ul class="pagination">\
										<li ng-class="{disabled: noPrivious()}">\
											<a href="" ng-click="selectPrivious()">Previous</a>\
										</li>\
										<li ng-repeat="page in pages" ng-class="{active: isActive(page)}">\
											<a href="" ng-click="selectPage(page)">{{page}}</a>\
										</li>\
										<li ng-class="{disabled: noNext()}">\
											<a href="" ng-click="selectNext()">Next</a>\
										</li>\
									</ul>\
								</div>',

		link : function ( scope ) {

			scope.$watch('numPages' , function( newValue ) {
				scope.pages = [];
				for(var i = 1; i <= newValue; i ++) scope.pages.push(i);
				if( scope.currentPage > newValue) scope.selectPage(newValue);
			});

			scope.selectPage = function(page) {
				if( scope.currentPage !== page ) {
					scope.currentPage = page;
					scope.onSelectPage({page : page});
				}
			};

			scope.isActive = function (page) {
				return scope.currentPage === page;
			};

			scope.noNext = function () {
				return scope.currentPage === scope.numPages;
			};

			scope.selectNext = function() {
				if(!scope.noNext()) {
					scope.selectPage( scope.currentPage + 1 );
				}
			};

			scope.noPrivious = function () {
				return scope.currentPage === 1;
			};

			scope.selectPrivious = function () {
				if(!scope.noPrivious()){
					scope.selectPage( scope.currentPage - 1);
				}
				
			};
		}
	};
})







