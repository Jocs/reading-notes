import _ from 'underscore'
import {
	invoker,
	dispatch,
	always,
	curry,
	curry2,
	curry3,
	checker,
	validator,
	partial1,
	partial2,
	partial,
	condition1,
	cat,
	splat
} from '../utils'

const str = dispatch(invoker('toString', Array.prototype.toString), invoker('toString', String.prototype.toString))
console.log(str(_.range(10)))
console.log(str('d'))

const stringReverse = str => {
	if (!_.isString(str)) return undefined
	return str.split('').reverse().join('')
}

const rev = dispatch(invoker('reverse', [].reverse), stringReverse)
console.log(rev('ransixi'))
console.log(rev([1, 2, 3]))

const sillyrev = dispatch(rev, always(45))
console.log(sillyrev(34))
console.log(['11', '11', '11', '11'].map(parseInt))
console.log(['11', '11', '11', '11'].map(curry(parseInt)))
console.log(['11', '11', '11', '11'].map(curry2(parseInt)(2)))

const toHex = n => {
	const hex = n.toString(16)
	return hex.length < 2 ? ['0', hex].join('') : hex
}
const rgbToHexString = (...args) => args.reduce((s, v) => s + toHex(v), '#')

console.log(rgbToHexString(255, 255, 255))
console.log(curry3(rgbToHexString)(100)(125)(157))

const greatThan = curry2((first, second) => first > second)
const lessThan = curry2((first, second) => first < second)

const withinRange = checker(
	validator('Must be great than 10', greatThan(10)),
	validator('Must be less than 20', lessThan(20))
)

console.log(withinRange(15))
console.log(withinRange(25))
console.log(withinRange(5))

const parseIntPartial = partial1(parseInt, '11')
console.log(parseIntPartial(2))

const blueColor = partial2(rgbToHexString, 255, 255)
console.log(blueColor(0))

const redColor = partial(rgbToHexString, 0, 255)
console.log(redColor(255))

const aMap = target => _.isObject(target)
console.log(validator('arg must be  a Map', aMap)(42))

const sqrPre = condition1(
	validator('arg must not be zero', arg => arg !== 0),
	validator('arg must be a number', arg => _.isNumber(arg))
)

console.log(sqrPre(_.identity, 10))
console.log(sqrPre(_.identity, 0))

const uncheckedSqr = n => n * n

const checkedSqr = partial(sqrPre, uncheckedSqr)

console.log(checkedSqr(7))
const sillySquare = partial(condition1(validator('arg must be even', n => n % 2 === 0)), checkedSqr)
console.log(sillySquare(3))
console.log(cat([1, 2], [4, 56]))

const not = n => !n
const isnotString = _.compose(not, _.isString)

console.log(isnotString(4))

const composedMapcat = _.compose(splat(cat), _.map)
console.log(composedMapcat([[1, 2], [3, 4], [5, 6]], _.identity))


