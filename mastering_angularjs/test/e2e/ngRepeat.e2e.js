// at the top of the test spec:
var fs = require('fs');

// ... other code

// abstract writing screen shot to a file
function writeScreenShot(data, filename) {
    var stream = fs.createWriteStream(filename);

    stream.write(new Buffer(data, 'base64'));
    stream.end();
}

// ...



describe('filter and ngRepeat' , function () {

	it('should location to index', function() {
    browser.get('src/data/ngRepeat.html');
    browser.getLocationAbsUrl().then(function(url) {
        expect(url).toEqual('');
      });
  });

  describe('filter in this little DEMO ', function () {
  	beforeEach(function() {
  		browser.get('src/data/ngRepeat.html');
  	});

  	it('should filter the users list as a user types into the search box', function() {

      var phoneList = element.all(by.repeater('user in filterUsers'));
      var query = element(by.model('filterWord'));

      expect(phoneList.count()).toBe(5);

      query.sendKeys('ransixi');
      expect(phoneList.count()).toBe(2);

      query.clear();
      query.sendKeys('wujingwen');
      expect(phoneList.count()).toBe(1);
    });

    it('should test the click envent to order by name' , function () {
    		
    		var query = element(by.model('filterWord'));
    		query.sendKeys("text was",
                   protractor.Key.BACK_SPACE,protractor.Key.BACK_SPACE,protractor.Key.BACK_SPACE,protractor.Key.BACK_SPACE,
                   "now text is");
    		query.clear();


      console.log(protractor.Key)
    // within a test:
    // browser.takeScreenshot().then(function (png) {
    //   writeScreenShot(png, 'exception.png');
    // });
    	element(by.css('#orderByName')).click();
    	element(by.css('#orderByEmail')).click();
    	expect(element(by.css('#tableBody > tr > td:first-child')).getText()).toMatch(/fumin/);
    });
  });
});









