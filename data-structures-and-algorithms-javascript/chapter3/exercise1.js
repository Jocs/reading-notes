(function(){
	var Stack = require('./Stack');
	/**
	 * 该函数用来判断表达式的小括号是否匹配，如果匹配返回TRUE，不匹配返回错误的错误位置和符号
	 */
	function findTheErrorPos( expression ){
		var expArr = expression.split('');
		var stack = new Stack();
		var REGEXP = /[\(\)]{1}/;
		for(var i = 0, ii = expArr.length; i < ii; i ++){
			if(REGEXP.test(expArr[i])) {
				if(expArr[i] == '(') stack.push({index: i,symbol: expArr[i]});
				else if(expArr[i] == ')') {
					if(stack.peek().symbol == '(') stack.pop();
					else return {index: i , symbol : expArr[i]};
				}
			}
		}
		if(stack.top == 0) return true;
		else return stack.dataStore;
	}

	console.log( findTheErrorPos('1 + 3 * 4 + 3)'));
})();