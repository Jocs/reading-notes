angular.module('ngOptions' , [])
.controller('MainController' , function ($scope) {
	$scope.iterms = [
		{name: 'ransixi', job: 'developter' , age: 27},
		{name: 'wujingwen', job: 'analysist' , age: 23},
		{name: 'fumin', job: 'biolojist' , age: 27},
		{name: 'wangwei', job: 'sicentist' , age: 29},
		{name: 'xiaoming', job: 'actor' , age: 37},
		{name: 'huangjiao', job: 'angWay' , age: 24}
	];

	$scope.selected = {name: 'ransixi', job: 'developter' , age: 27}

	var ob1 = {hd: 'dd'};
	var prototypeOfObj1 = Object.getPrototypeOf(ob1);
	prototypeOfObj1.getName = function () {
		return 'ddd';
	};
	// var ob2 = {hd: 'dd'};
	// console.log(angular.equals(ob1, ob2));
	// console.log(ob1 === ob2);
	// console.log(ob1)
	// console.log(ob2)
});

	








