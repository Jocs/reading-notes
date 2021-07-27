import _ from 'underscore'
import { finder,
	plucker,
	iterateUntil,
	always,
	invoker,
	uniqueString,
	uniqueId,
	nullf,
	checker,
	validator } from '../utils'

console.log(finder(_.identity, Math.max, [1, 4, 6, 4, 9]))

const people = [{
	name: 'ransixi',
	age: 34
}, {
	name: 'wujingwen',
	age: 21
}]

console.log(finder(plucker('age'), Math.min, people))

const repeat = times => value => _.map(_.range(times), () => value)

console.log(repeat(10)('yaHa'))

const repeatedly = times => fn => _.map(_.range(times), fn)
const repeat10 = repeatedly(10)
console.log(repeat10(i => Math.floor(Math.random() * 10) + i))

const ret = iterateUntil(n => n * 2, num => num < 1024, 2)
console.log(ret)

const f = always(() => 'HELLO WORLD')
console.log(f() === f())
console.log(f()())

const rev = invoker('reverse', Array.prototype.reverse)
console.log(_.map([[1, 2, 3]], rev))
console.log(uniqueString(8))
console.log(_.map(_.range(10), () => uniqueId('id-')))

const safeMult = nullf((total, n) => total * n, 1, 1, 1, 1)

console.log(_.reduce([1, 2, null, 6], safeMult))

const alwaysPass = checker(always(true), always(true))
console.log(alwaysPass({}))

const fail = always(false)
fail.message = 'a failure in life'
const alwaysFail = checker(fail)
console.log(alwaysFail({}))

const aMap = obj => _.isObject(obj)

const commondCheckMap = checker(validator('must be a map', aMap))
console.log(commondCheckMap(123))

const hasKeys = (...args) => {
	const fun = obj => args.every(key => _.has(obj, key))
	fun.message = ['Must has these keys: ', ...args].join(' ')
	return fun
}

const commondCheckHasKeys = checker(validator('must be a map', aMap), hasKeys('name', 'age'))
console.log(commondCheckHasKeys([{
	name: 'ransixi',
	age: 23
}]))
