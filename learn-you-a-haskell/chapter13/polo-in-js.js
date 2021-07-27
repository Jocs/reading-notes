function Pole(pole, msgArr) {
	this.pole = pole
	this.state = msgArr
}

Pole.prototype.mBind = function(fn) {
	return fn.call(this, this.pole, this.state)
}

const land = birds => (pole, msgArr) => {
	if (/Peter/.test(msgArr[msgArr.length - 1])) return new Pole([], msgArr)
	const newPole = birds.map((b, i) => b + pole[i])
	const newMsgArr = msgArr.map(item => item)
		  newMsgArr.push(`land left: ${birds[0]} and land right: ${birds[1]}`)
	const errMsgArr = newMsgArr.map(item => item)
		  errMsgArr.push(`left is: ${newPole[0]} and right is: ${newPole[1]} Sorry, Peter fall down!`)
	return Math.abs(newPole[0] - newPole[1]) < 4 ? new Pole(newPole, newMsgArr) : new Pole([], errMsgArr)
}

const start = new Pole([0, 0], ['land left: 0 and land right: 0'])

const result = start.mBind(land([3, 0]))
	.mBind(land([0, 3]))
	.mBind(land([5, 0]))
	.mBind(land([3, 0]))

console.log(result)
