
module.exports = (function(){
	//这个练习是利用栈来构建一个函数，该函数能够将中缀表达式转化为后缀表达式，并且对后缀表达式求值。
	var Stack = require('./Stack'),
			DIGIT_REGEXP = /\d+/,
			OPERATOR_REGEXP = /[\*\+\-\/\(\)]{1}/,
			PURE_OPERATOR_REGEXP = /[\+\-\*\/]{1}/;
	// infixToPostfix方法用来把中缀表达式转化为后缀表达式
	function infixToPostfix( expression ){
	//替换掉expression中的所有空白符
	var expList = chop( expression ),
			stack = new Stack(),
			resultString = '';
			

			for(var i = 0, ii = expList.length; i < ii; i ++){
				if(DIGIT_REGEXP.test( expList[i] )){
					resultString = resultString + expList[i] + ' ';
				} else if( OPERATOR_REGEXP.test( expList[i] ) ) {
					if(stack.top == 0) stack.push( expList[i] );
					else {
						//如果是"("就直接push进stack，如果是运算符，需要比较优先级，优先级比栈顶部的高就直接push进栈，
						//如果优先级比栈顶部运算符的优先级低，就把栈顶部的操作符加在resultString的后面，然后在对栈顶部
						//操作符进行比较，直到优先级没有比它低得。如果是")"，就直接把栈顶部的操作符加到resultSring后面
						//再把"("去掉。
						if(expList[i] == '(') stack.push(expList[i]);
						if(expList[i] == ')'){
							resultString = resultString + stack.pop() + ' ';
							if(stack.peek() == '(') stack.pop();
						}
						if(PURE_OPERATOR_REGEXP.test( expList[i] )){
							var preOperator = symbolToPriority( expList[i] );
							var stackTopOperator = symbolToPriority( stack.peek());

							if(preOperator > stackTopOperator || stack.peek() == '(') stack.push( expList[i] );
							else {
								while( stackTopOperator && preOperator <= stackTopOperator ){
									resultString = resultString + stack.pop() + ' ';
									stackTopOperator = symbolToPriority( stack.peek());
								}
								stack.push( expList[i] );
							}	
						}	
					}
				}
			};
			while( stack.peek() ){
				resultString = resultString + stack.pop() + ' ';
			};
			return resultString.trim();
	}
	// calculatePostfix 方法用来对后缀表达式求值
	function calculatePostfix ( postfixExp ) {
		var token = postfixExp.split(/\s+/),
				stack = new Stack();

				for(var i = 0, ii = token.length; i < ii; i ++){
					if(DIGIT_REGEXP.test(token[i])){
						stack.push(token[i]);
					} else if(PURE_OPERATOR_REGEXP.test(token[i])){
						var rightNumber = Number(stack.pop()),
								leftNumber = Number(stack.pop());
								switch(token[i]){
									case '+':stack.push(rightNumber + leftNumber);break;
									case '-':stack.push(leftNumber - rightNumber);break;
									case '*':stack.push(leftNumber * rightNumber);break;
									case '/':stack.push(leftNumber / rightNumber);break;
									default: break;
								}
					}
				}
				if(stack.top == 1) return stack.pop();
	}
	var WHITE_SPACE = /\s+/g;
	var CHOP_REGEXP = /\d+|[\*\+\/\-\(\)]/g;
	function chop(expression){
		return expression.replace(WHITE_SPACE, '')
					 .match(CHOP_REGEXP);
	}
	function symbolToPriority( symbol ){
		if(!PURE_OPERATOR_REGEXP.test(symbol)) return false;
		return symbol == '*' || symbol == '/'? 2 : 1;
	}
	return function(expression){
		var postfixExpression = infixToPostfix(expression);
		return calculatePostfix( postfixExpression );
	}
})();



