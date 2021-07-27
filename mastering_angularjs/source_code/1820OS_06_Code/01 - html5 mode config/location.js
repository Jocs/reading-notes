angular.module('location', [], function ($locationProvider) {
  $locationProvider.html5Mode(true);
})

  .controller('MainCtrl', function ($scope, $location) {
    $scope.location = $location;
  });

//THINGS TO EXPLORE => the goal is to prepare examples for the chapter
//- will IE9 / other manage to switch back and forth between modes?
//- what is the hash prefix anyway?