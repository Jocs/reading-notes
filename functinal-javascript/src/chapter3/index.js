import _ from 'underscore'

// 词法作用域，其作用域嵌套关系是在函数定义是决定了，而非运行时。
const variable = 'outer'
const staticFn = () => variable

const result = (() => {
	const variable = 'inner'
	return staticFn()
})()

console.log(result)
// 模拟动态作用域
const globals = {}
const makeBindFun = resolver => (key, value) => {
	const stack = globals[key] || []
	globals[key] = resolver(stack, value)
	return globals
}

const stackBinder = makeBindFun((stack, value) => {
	stack.push(value)
	return stack
})

const stackUnBinder = makeBindFun(stack => {
	stack.pop()
	return stack
})

const dynamicLookup = k => {
	const slot = globals[k] || []
	return _.last(slot)
}

stackBinder('a', 1)
stackBinder('b', 200)
stackBinder('b', 300)
console.log(globals)
stackUnBinder('b')
console.log(dynamicLookup('b'))

// FUNCTOR是被捕获的参数
const makeAdder = FUNCTOR => number => number + FUNCTOR
const add10 = makeAdder(10)
console.log(add10(2))

const double = FUN => n => n + FUN(n)
const double2 = double(n => n * 2)
console.log(double2(5))

const plucker = FIELD => obj => obj && obj[FIELD]
const getName = plucker('name')
const me = {
	name: 'ransixi',
	age: 21
}
console.log(getName(me))
