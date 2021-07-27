import _ from 'underscore'
// splat 接受一个函数作为参数，返回一个函数，该函数的作用是用前面的参数函数执行现有的参数。
export const splat = fun => args => fun(...args)

const fail = msg => _.identity(msg)
const isIndexed = data => _.isArray(data) || _.isString(data)

export const nth = (a, index) => {
	if (!_.isNumber(index)) return fail('Expected a number as the index!')
	if (!isIndexed(a)) return fail('Not support on non-indexed type!')
	if (index < 0 || index > a.length - 1) return fail('Index value out of bounds!')
	return a[index]
}

export const second = array => nth(array, 1)

export const existy = x => x != null
// note: truthy(0) === true
export const truthy = x => x !== false && existy(x)

export const lessOrEqual = (x, y) => x <= y
export const comparator = pred => {
	return (x, y) => {
		if (truthy(pred(x, y))) return -1
		else if (truthy(pred(y, x))) return 1
		else return 0
	}
}

export const allOf = (...args) => _.reduceRight(args, (truth, f) => truth && f(), true)
export const anyOf = (...args) => _.reduceRight(args, (truth, f) => truth || f(), false)

export const compliment = pred => (...args) => !pred(...args)

export const plucker = field => obj => obj && obj[field]

export const finder = (valueFn, bestFn, collection) => {
	return _.reduce(collection, (best, current) => {
		const bestValue = valueFn(best)
		const currentValue = valueFn(current)
		return (bestValue === bestFn(bestValue, currentValue)) ? best : current
	})
}

export const iterateUntil = (fn, check, init) => {
	const ret = []
	let result = fn(init)
	while (check(result)) {
		ret.push(result)
		result = fn(result)
	}
	return ret
}

export const always = value => () => value

// 当条件为true时，返回第二个参数调用的结果，当条件为false时，返回undefined
export const doWhen = (cond, fn) => cond ? fn() : undefined

export const invoker = (name, method) => (target, ...args) => {
	const targetMethod = target[name]
	return doWhen(existy(targetMethod) && targetMethod === method, () => targetMethod.apply(target, args))
}

export const uniqueString = len => Math.random().toString(36).substr(2, len)

export const uniqueId = (init => {
	let start = init
	return prefix => [prefix, start++].join('')
})(0)

export const nullf = (fn, ...args) =>
	(...innerArgs) =>
	fn(...(_.map(innerArgs, (e, i) => existy(e) ? e : args[i])))

export const checker = (...validators) => obj => _.reduce(validators, (err, check) => {
	return check(obj) ? err : _.chain(err).push(check.message).value()
}, [])

export const validator = (msg, fn) => {
	const f = (...args) => fn(...args)
	f.message = msg
	return f
}

// export const dispatch = (...funs) => arg => {
// 	const len = funs.length
// 	let i, result
// 	for (i = 0; i < len; i++) {
// 		result = funs[i](arg)
// 		if (existy(result)) return result
// 	}
// 	return result
// }
// 用下面递归的方法，消除for循环的使用。函数式编程尽量使用递归来替代迭代
// dispatch函数甚至可以dispatch一个dispatch返回的函数
// dispatch 还可以实现重载先前的函数
export const dispatch = (first, ...rest) => target => {
	return first ? first(target) || dispatch(...rest)(target) : undefined
}

export const curry = func => arg => func(arg)
export const curry2 = func => secondArg => firstArg => func(firstArg, secondArg)
export const curry3 = func => thirdArg => secondArg => firstArg => func(firstArg, secondArg, thirdArg)

export const partial1 = (func, arg1) => (...args) => func(arg1, ...args)
export const partial2 = (func, arg1, arg2) => (...args) => func(arg1, arg2, ...args)
export const partial = (func, ...preArgs) => (...lastArgs) => func(...preArgs, ...lastArgs)

export const condition1 = (...validators) => (fun, arg) => {
	const errors = validators.map(isValid => isValid(arg) ? [] : [isValid.message])
	const msgArray = Array.prototype.concat.apply([], errors)
	if (!_.isEmpty(msgArray)) {
		return msgArray.join(', ')
	}
	return fun(arg)
}

export const cat = (first, ...rest) => first === undefined ? [] : first.concat(cat(...rest))

export const isEven = num => num % 2 === 0

export const repeatedly = (times, fun) => _.map(_.range(times), fun)

export const deepFreeze = obj => {
	if (!Object.isFrozen(obj)) Object.freeze(obj)
	for (let key in obj) {
		if (!obj.hasOwnProperty(key) || !_.isObject(obj[key])) continue
		deepFreeze(obj[key])
	}
}










