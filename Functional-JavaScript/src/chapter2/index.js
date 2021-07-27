import _ from 'underscore'
import { allOf, anyOf, compliment, truthy } from '../utils'

const lyricSegment = n => {
	return _.chain([])
			.push(n + ' bottles of beer on the wall')
			.push(n + ' bottles of beer')
			.push('Take one down, pass it around')
			.tap(lyrics => n > 1 ? lyrics.push((n - 1) + ' bottles of beer on the wall.')
				: lyrics.push('No more bottles of beer on the wall!'))
			.value()
}

const song = (start, end, lyricGen) => {
	return _.reduce(_.range(start, end, -1), (acc, n) => {
		return acc.concat(lyricGen(n))
	}, [])
}

console.log(song(2, 0, lyricSegment))

const T = () => true
const F = () => false

console.log(allOf(T, T, T))
console.log(anyOf(F, F, T))

// _.reject()函数的使用
console.log(_.reject([1, 2, 3], n => n === 2))
// _.find()函数的使用
console.log(_.find([1, 2, 3], n => n >= 2))

console.log(_.filter(['a', 'b', 2], compliment(_.isNumber)))

// _.sortBy()使用
const people = [{
	name: 'ransixi',
	age: 34
}, {
	name: 'wujingwen',
	age: 21
}]

console.log(_.sortBy(people, p => p.age))

// _.groupBy()的使用
const members = [{
	name: 'ransixi',
	hobby: 'basketball'
}, {
	name: 'wujingwen',
	hobby: 'reading'
}, {
	name: 'xiaoming',
	hobby: 'reading'
}]

console.log(_.groupBy(members, member => member.hobby))
console.log(_.countBy(members, member => member.hobby))

// _.pluck()函数的使用
console.log(_.pluck(members, 'name'))
const member = members[0]
const objMember = _.object(_.map(_.pairs(member), pair => [pair[0].toUpperCase(), pair[1]]))
console.log(objMember)

// _.invert()可以翻转键值
console.log(_.invert(member))

const person = {
	name: 'ransixi',
	token: '123455',
	password: 78905643
}

console.log(_.omit(person, 'token', 'password'))
console.log(_.pick(person, 'token'))

// findWherr() 和 where()的使用
const library = [{
	title: 'CSS',
	isbn: '2344545324',
	ed: 3
}, {
	title: 'CSS',
	isbn: '65467745',
	ed: 5
}, {
	title: 'JavaScript',
	isbn: '65467745',
	ed: 5
}]

console.log(_.findWhere(library, {title: 'CSS'}))
console.log(_.where(library, {title: 'CSS'}))

const project = (table, keys) => _.map(table, obj => _.pick(obj, ...keys))

console.log(project(library, ['title', 'ed']))

const rename = (obj, newNames) => _.reduce(newNames, (o, value, old) => {
	if (_.has(obj, old)) o[value] = obj[old]
	return o
}, _.omit(obj, ...(_.keys(newNames))))
const as = (table, newNames) => _.map(table, obj => rename(obj, newNames))
console.log(rename({name: 'ransixi', age: 34}, {name: 'NAME'}))
console.log(as(library, {ed: 'edtion'}))

// _.without()是shadow copy
const restrict = (table, pred) =>
	_.reduce(table,
			(newTable, obj) => truthy(pred(obj)) ? newTable : _.without(newTable, obj),
			table)

const selectedLibrary = restrict(library, obj => obj.ed >= 5)
console.log(selectedLibrary)
