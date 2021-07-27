import _ from 'underscore'
import { splat, nth, second, comparator, lessOrEqual } from '../utils'
import fs from 'fs'

const addArrayElements = splat((x, y) => x + y)
console.log('3 add 4 is ' + addArrayElements([3, 4]))

const joinElements = splat(array => array.join(' '))
console.log(`$ and * joined is ${joinElements(['$', '*'])}`)

console.log(nth('hello', 2))
console.log(nth('hello', 'd'))
console.log(nth({}, 1))
console.log(nth([1, 2, 3], 6))
console.log(second([1, 2, 3]))

const compareArray = [-2, 1, 3, 2, 4, 5]
console.log(compareArray.sort(comparator(_.isEqual)))
compareArray.sort(comparator(lessOrEqual))
console.log(compareArray)

const lameCSV = strs => {
	return strs.split('\n').reduce((table, str) => {
		table.push(str.split(',').map(word => word.trim()))
		return table
	}, [])
}

const listPromise = new Promise((resolve, reject) => {
	fs.readFile(__dirname + '/list.csv', 'utf8', (err, data) => {
		if (err) reject(err)
		resolve(lameCSV(data))
	})
})


const selectNames = table => _.rest(_.map(table, _.first))
const selectAges = table => _.rest(_.map(table, second))
const selectHairColor = table => _.rest(_.map(table, function(row) {
	return nth(row, 2)
}))
const mergeResults = _.zip

listPromise.then(data => {
	console.log(selectNames(data))
	console.log(selectAges(data))
	console.log(selectHairColor(data))
	console.log(mergeResults(selectNames(data), selectAges(data)))
})
