var fs = require('fs');
module.exports = (function(){
	return {
		getFilmsList : function (path) {
			return new Promise(function(resolve, reject){
					fs.readFile(path, 'utf-8' , function( err, data ){
						if(err) reject(err);
						else resolve(data.split('\n'));
					});
			});
		},
		writeResult: function (filmsListPath, customListPath, filmsList, customList) {
			var promiseCustom = new Promise(function(resolve, reject) {
				fs.writeFile(customListPath, getString(customList), function(err, data){

					if(err) reject(err);
					else resolve(data);
				});
			});
			var promiseFilm = new Promise(function(resolve, reject) {
				fs.writeFile(filmsListPath, filmsList.toString().join('\n'), function(err, data){
					if(err) reject(err);
					else resolve(data);
				});
			});
			return Promise.all([promiseCustom, promiseFilm]);
		}
	}
})();

function getString(customList){
	var str = '';
	customList.front();
	do{
		str += 'name: ' + customList.getElement().name + ' ,' + 'film: ' + customList.getElement().film + '\n';
	} while (customList.next());
	return str;
}