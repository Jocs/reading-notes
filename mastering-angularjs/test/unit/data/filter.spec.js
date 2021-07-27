describe('test custormFilter' , function () {
	var pagination;
	beforeEach(module('custormFilter'));
	beforeEach(inject(function(_paginationFilter_) {
		pagination = _paginationFilter_;
	}));

	it('shold pass all the test' , function () {
		var inputArray = [1,2,3,4,5,6,7,8,9];
		expect(pagination(inputArray, 0, 3)).toEqual([1,2,3]);
		expect(pagination(inputArray, 3, 3)).toEqual([]);
	});
});