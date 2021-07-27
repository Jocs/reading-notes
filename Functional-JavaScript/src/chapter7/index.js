import _ from 'underscore'
import {
	partial1,
	repeatedly,
	deepFreeze
} from '../utils'

const rand = partial1(_.random, 1)
console.log(rand(10))

const randomArray = repeatedly(10, partial1(rand, 10))
console.log(randomArray)
console.log(_.take(randomArray, 5))

const randString = len => {
	const ascii = repeatedly(len, partial1(rand, 26))
	return _.map(ascii, n => n.toString(36)).join('')
}

console.log(randString(8))
const freezeObj = {
	a: 'b',
	c: {
		d: 'e',
		f: 'g'
	}
}

deepFreeze(freezeObj)
// freezeObj.c.d = 'change'
console.log(freezeObj)


