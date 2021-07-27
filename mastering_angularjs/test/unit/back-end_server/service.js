describe('$q use' , function() {
	var $q, $rootScope , $log, Person, pawer,Restaurant, peter,pizzaPit, pizzaDelivered;
	Person = function ( name, $log ) {

		this.eat = function ( food ) {
			$log.info( name + ' is eating delicious ' + food);
		};

		this.beHungry = function ( reason ) {
			$log.warn( name + ' is hungry because: ' + reason);
		};
	};
	Restaurant = function ( $q, $rootScope) {
		var currentOrder;

		this.takeOrder = function ( orderedItems ) {
			currentOrder = {
				deferred : $q.defer(),
				items : orderedItems
			};
			return currentOrder.deferred.promise;
		};

		this.deliverOrder = function () {
			currentOrder.deferred.resolve( currentOrder.items );
			$rootScope.$digest();
		};

		this.problemWithOrder = function ( reason ) {
			currentOrder.deferred.reject( reason );
			$rootScope.$digest();
		};
	};
	beforeEach(inject(function(_$q_, _$rootScope_ , _$log_) {
		$q = _$q_;
		$rootScope = _$rootScope_;
		$log = _$log_;
		
		pawer = new Person('pawer', $log);
		peter = new Person('peter', $log);

		pizzaPit = new Restaurant($q, $rootScope);
		pizzaDelivered = pizzaPit.takeOrder('Capricciosa');
	}));
	//$q的基本用法
	describe('the basic use of $q' , function () {
		it('should illustrate basic use of $q' , function () {

			var pizzaOrderFulfillment = $q.defer();
			var pizzaDelivered = pizzaOrderFulfillment.promise;

			pizzaDelivered.then(pawer.eat, pawer.beHungry);
			pizzaOrderFulfillment.resolve('Margherrita');

			$rootScope.$digest();

			expect( $log.info.logs ).toContain(['pawer is eating delicious Margherrita']);
		});
	});
	//reject的使用
	describe('the reject use of $q' , function() {
		
		it('should illustrate promise reject' , function() {

			pizzaDelivered.then(pawer.eat, pawer.beHungry);

			pizzaPit.problemWithOrder('no Capricciosa, only Margherita left');
			expect( $log.warn.logs ).toContain(['pawer is hungry because: no Capricciosa, only Margherita left']);

		});
	});
	//聚合回调
	describe('one promse with more than one callback', function () {
		it('should all callbacks aggregation' , function () {

			pizzaDelivered.then(pawer.eat, pawer.beHungry);
			pizzaDelivered.then(peter.eat, peter.beHungry);

			pizzaPit.deliverOrder();

			expect($log.info.logs).toContain(['pawer is eating delicious Capricciosa']);
			expect($log.info.logs).toContain(['peter is eating delicious Capricciosa']);
		});
	});
	//链式调用
	describe('chain then of $q promise' , function () {
		var slice = function(pizza ) {
			return 'sliced ' + pizza;
		};
		it('should illustrate successful promise chaining', function() {

			pizzaDelivered.then(slice).then(pawer.eat);

			pizzaPit.deliverOrder();

			expect($log.info.logs).toContain(['pawer is eating delicious sliced Capricciosa']);
		});

		it('should behave error promise chaining', function() {
			pizzaDelivered.then(slice).then(pawer.eat, pawer.beHungry);

			pizzaPit.problemWithOrder('no Capricciosa, only Margherita left');
			expect($log.warn.logs).toContain(['pawer is hungry because: no Capricciosa, only Margherita left']);

		});

		it('should behave recovery from promse rejection', function() {
			var retry = function() {
				return pizzaPit.takeOrder('Margherita').then(slice);
			};
			pizzaDelivered
			.then(slice, retry)
			.then(pawer.eat, pawer.beHungry);

			pizzaPit.problemWithOrder('no Capricciosa, only Margherita left');
			pizzaPit.deliverOrder();
			expect($log.info.logs).toContain(['pawer is eating delicious sliced Margherita']);
		});

		it('should illustrate rejection in chain', function() {
			var explain = function() {
				return $q.reject('ordered pizza not available');
			};
			
			pizzaDelivered
			.then(slice, explain)
			.then(pawer.eat, pawer.beHungry);

			pizzaPit.problemWithOrder('no Capricciosa, only Margherita left');
			expect($log.warn.logs).toContain(['pawer is hungry because: ordered pizza not available']);
		});
		describe('promises behavier' , function () {
			var orderDelivered, pizzaPit, saladBar;

			beforeEach(function() {
				pizzaPit = new Restaurant($q, $rootScope);
				saladBar = new Restaurant($q, $rootScope);
				orderDelivered = $q.all([
					pizzaPit.takeOrder('apple'),
					saladBar.takeOrder('orange')
					]);
			});

			it('should illustrate promise aggregation', function() {

				orderDelivered.then(pawer.eat);
				pizzaPit.deliverOrder();
				saladBar.deliverOrder();

				expect($log.info.logs).toContain(['pawer is eating delicious apple,orange']);
			});

			it('should illustrate promise rejection' , function () {
				orderDelivered.then(pawer.eat, pawer.beHungry);
				pizzaPit.deliverOrder();
				saladBar.problemWithOrder('no orange');

				expect($log.warn.logs).toContain(['pawer is hungry because: no orange']);
			});
		});

		describe('the use of when' , function() {
			var orderDelivered, pizzaPit;
			beforeEach(function() {
				pizzaPit = new Restaurant($q, $rootScope);
				orderDelivered = $q.all([
						pizzaPit.takeOrder('apple'),
						$q.when('home made orange')
					])
			});

			it('should illustrate $q use of when' , function () {
				orderDelivered.then(pawer.eat, pawer.beHungry);

				pizzaPit.deliverOrder();

				expect($log.info.logs).toContain(['pawer is eating delicious apple,home made orange']);
			});
		});
		

	});


});









