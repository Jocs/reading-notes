var List = require('./List');
var Custom = require('./Custom');
var io = require('./input_output');
var readline = require('readline');

var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

var customList = new List();
var filmList = new List();

var questionPromise = new Promise(function(resolve, reject){
	rl.question("What's your name and film?", function(answer) {
	  // TODO: Log the answer in a database
	  var info = {};
	  var arr = answer.split(',');
	  info.name = arr[0].trim();
	  info.film = arr[1].trim();
	  resolve(info);
	  rl.close();
	});
})
.then(function(data){
	var custom = new Custom(data.name, data.film);
	customList.append(custom);
})
.then(function(){
	return io.getFilmsList('./chapter2/files.txt');
})
.then(function(data){
	for(var i = 0; i < data.length; i ++){
		filmList.append(data[i]);
	}
}, function(err){
	console.log(err);
})
.then(function(){
filmList.remove(customList.getElement().film);

})
.then(function(){
	io.writeResult('./chapter2/files.txt', './chapter2/customList.txt', filmList, customList);
});








