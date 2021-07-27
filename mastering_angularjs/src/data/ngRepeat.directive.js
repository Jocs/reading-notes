angular.module('app2.directive', [])
.directive('screenshots' , function () {
	return {
		restrict : 'A',
		replace : true,
		templateUrl : 'ngRepeat.tpl.html',
		scope: {},
		controller : function ( $document) {
			this.getSshots = function (scope, ele) {
				html2canvas( $document.body , {
					onrendered : function (canvas) {
						scope.canvas = canvas;
						console.log(scope.users)
						angular.element(ele).next().empty().append(canvas);
					}
				});
			};
		}
	};
})
.directive('getScreenshots' , function () {
	return {
		restrict : 'A',
		require : '^?screenshots',
		link : function (scope , ele, attrs, ctrl) {
			angular.element(ele).bind('click' , function () {
				ctrl.getSshots(scope, ele);
			});
		}
	}
});
