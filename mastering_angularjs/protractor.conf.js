exports.config = {
  allScriptsTimeout: 11000,

  specs: [
    'test/e2e/*.js'
  ],

  capabilities: {
    'browserName': 'chrome'
  },
  chromeDriver: '/usr/local/lib/node_modules/protractor/selenium/chromedriver.exe',

  seleniumServerJar: '/usr/local/lib/node_modules/protractor/selenium/selenium-server-standalone-2.47.1.jar',

  chromeOnly: true,

  baseUrl: 'http://localhost:8080',

  framework: 'jasmine',

  jasmineNodeOpts: {
    defaultTimeoutInterval: 3000000
  }
};