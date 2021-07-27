const fs = require('fs')
const path = require('path')

const build = function(rootPath, cb) {
	if (!fs.existsSync(rootPath)) return
	fs.readdir(rootPath, (err, dirs) => {
		if (err) return cb(err)
		dirs.forEach(dir => {
			const pathName = path.join(rootPath, dir)
			if (fs.statSync(pathName).isDirectory() && /^chapter[\d]+$/.test(dir)) {
				const writeString = `require('babel-register')\nrequire('../src/${dir}')\n`
				if (!fs.existsSync(`${__dirname}/dist`)) fs.mkdirSync(`${__dirname}/dist`)
				fs.writeFile(`${__dirname}/dist/${dir}.js`, writeString, err => {
					if (err) console.log(err)
				})
			}
		})
	})
}

build(__dirname + '/src', console.log)
