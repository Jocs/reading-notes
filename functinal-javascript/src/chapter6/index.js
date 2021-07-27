import _ from 'underscore'
import {
	second,
	isEven,
	partial1,
	partial
} from '../utils'

/**
 * [计算数组长度]
 * @param  {[Array]} arr [传入的数组]
 * @return {[Number]}     [数组长度]
 */
const myLength = arr => _.isEmpty(arr) ? 0 : myLength(_.rest(arr)) + 1
console.log(myLength(_.range(9)))

/**
 * [对一个数组进行times次重复，形成一个新的数组]
 * @param  {[Number]} times [重复次数]
 * @param  {[Array]} ary   [被重复的数组]
 * @return {[Array]}       [新生成的数组]
 */
const cycle = (times, ary) => times === 0 ? [] : [...ary, ...cycle(times - 1, ary)]
console.log(_.take(cycle(11, [1, 2, 3]), 11))

const unzip = (first, ...rest) =>
	_.isEmpty(first) ? [[], []] : [
		[_.first(first), ...(_.first(unzip(...rest)))],
		[second(first), ...(second(unzip(...rest)))]
	]
console.log(unzip([1, 'a'], [2, 'b'], [3, 'c']))

// 一张影响Javascript发展的关系图
const influences = [
	['Lisp', 'Smalltalk'],
	['Lisp', 'Scheme'],
	['Smalltalk', 'Self'],
	['Scheme', 'JavaScript'],
	['Scheme', 'Lua'],
	['Self', 'Lua'],
	['Self', 'JavaScript']
]

const nexts = (graph, node) => {
	if (_.isEmpty(graph)) return []
	const pair = _.first(graph)
	const fromNode = _.first(pair)
	const to = second(pair)
	const more = _.rest(graph)
	return _.isEqual(fromNode, node) ? [to, ...(nexts(more, node))] : nexts(more, node)
}
console.log(nexts(influences, 'Lisp'))

const deepSearch = (graph, nodes, seen) => {
	if (_.isEmpty(nodes) && Array.isArray(seen)) return seen
	const node = _.first(nodes)
	const more = _.rest(nodes)
	if (_.contains(seen, node)) {
		return deepSearch(graph, more, seen)
	} else {
		seen.push(node)
		return deepSearch(graph, [...(nexts(graph, node)), ...more], seen)
	}
}
console.log(deepSearch(influences, ['Lisp'], []))

const andify = (...funcs) => (...args) => {
	const everything = (fns, args, truthy) => {
		if (_.isEmpty(fns)) return truthy
		const result = _.every(args, _.first(fns)) && truthy
		return everything(_.rest(fns), args, result)
	}
	return everything(funcs, args, true)
}
console.log(andify(isEven, _.isNumber)(1, 2, 4))

const orify = (...funcs) => (...args) => {
	const something = (fns, args, falsy) => {
		if (_.isEmpty(fns)) return falsy
		const result = _.some(args, _.first(fns)) || falsy
		return something(_.rest(fns), args, result)
	}
	return something(funcs, args, false)
}
console.log(orify(isEven, _.isNumber)(1, 2, 4))

const evenSteven = n => n === 0 ? true : oddJoin(Math.abs(n) - 1)
const oddJoin = n => n === 0 ? false : evenSteven(Math.abs(n) - 1)

console.log(evenSteven(5))

// 简单deepClone 不要用于生产
const deepClone = obj => {
	if (!_.isObject(obj)) return obj
	else if (_.isArray(obj)) {
		const arr = []
		obj.forEach(ele => arr.push(deepClone(ele)))
		return arr
	} else {
		const temp = {}
		for (let key in obj) {
			if (obj.hasOwnProperty(key)) temp[key] = deepClone(obj[key])
		}
		return temp
	}
}
const aobj = {
	name: 'ransixi',
	hobby: ['basketball', 'pinpong'],
	work: {
		destination: 'Shanghai',
		title: 'FE'
	}
}

const copy = deepClone(aobj)
aobj.work.title = 'scientist'
console.log(copy)

const visit = (mapFun, resultFun, array) => {
	return _.isArray(array) ? resultFun(_.map(array, mapFun)) : resultFun(array)
}
console.log(visit(_.identity, _.identity, [1, 2]))
const postDepth = (fun, array) => {
	return visit(partial1(postDepth, fun), fun, array)
}

const postResult = postDepth(node => node === 'Lisp' ? 'LISP' : node, influences)
console.log(postResult)

const evenOLine = n => n === 0 ? true : partial1(oddOLine, Math.abs(n) - 1)
const oddOLine = n => n === 0 ? false : partial1(evenOLine, Math.abs(n) - 1)
const trampoline = (fun, ...args) => {
	let result = fun(...args)
	while (_.isFunction(result)) {
		result = result()
	}
	return result
}
// console.log(evenSteven(20000)) 会栈溢出
console.log(trampoline(evenOLine, 255666))

const isEvenSafe = n => trampoline(evenOLine, n)
const isOddSafe = n => trampoline(oddOLine, n)

console.log(isEvenSafe(2000))
console.log(isOddSafe(2001))

const generator = (seed, current, step) => {
	return {
		head: current(seed),
		tail() {
			console.log('forced')
			return generator(step(seed), current, step)
		}
	}
}

const getHead = gen => gen.head
const getTail = gen => gen.tail()

const init = generator(0, _.identity, n => n + 1)

console.log(getHead(init))
console.log(getTail(init))
console.log(getHead(getTail(init)))

const getTake = (n, gen) => {
	const doTake = (x, g, ret) => {
		return x === 0 ? ret : partial(doTake, x - 1, getTail(g), [...ret, getHead(g)])
	}
	return trampoline(doTake, n, gen, [])
}

console.log(getTake(10, init))



























