// 生成 doc
const fs = require('fs')
const DOC_DIR = 'docs'

const promisefy = fn => (...args) => {
  return new Promise((resolve, reject) => {
    fn(...args, (err, data) => {
      if (err) reject(err)
      else resolve(data)
    })
  })
}

const rm = path => {
  if (fs.existsSync(path)) {
    const files = fs.readdirSync(path)
    files.forEach(f => {
      const curPath = `${path}/${f}`
      if (fs.statSync(curPath).isDirectory()) {
        rm(curPath)
      } else {
        fs.unlinkSync(curPath)
      }
    })
    fs.rmdirSync(path)
  }
}
// 删除 doc 目录
rm(`./${DOC_DIR}`)

async function getFileName(path) {
  await promisefy(fs.mkdir)(DOC_DIR)
  let dirs = await promisefy(fs.readdir)(path)
  // 过滤包含文档的文件夹
  dirs = dirs.filter(f => /^cp/.test(f))

  const fileCol = await Promise.all(dirs.map(d => {
    return promisefy(fs.readdir)(`${path}/${d}`)
      .then(files => files.filter(f => /\.py$/.test(f)).map(f => (`${path}/${d}/${f}`)))
  }))
  return fileCol.reduce((acc, arr) => {
    return [...acc, ...arr]
  }, [])
}

async function getCacheSource(files) {
  const sources = await Promise.all(files.map(p => {
    return promisefy(fs.readFile)(p, 'utf-8')
      .then(s => ({source: s, pathname: `${__dirname}/${DOC_DIR}/${p.match(/\/([^\/]+)\./)[1]}.md`}))
  }))
  return sources.map(s => {
    let cacheLine = []
    let cacheCode = []
    
    s.source
      .split('\n')
      .filter(l => !/(coding\:utf8|\!\/usr\/bin\/env)/.test(l))
      .filter(l => !!l)
      .forEach((l, i, lines) => {
        if (/^#/.test(l)) {
          if (cacheCode.length) {
            cacheCode.push('```')
            cacheLine = [...cacheLine, ...cacheCode]
            cacheCode.length = 0
          }
          cacheLine.push(l.slice(2))
        } else if (!lines[i - 1] || /^#/.test(lines[i - 1])) {
          cacheCode.push('```python')
          cacheCode.push(l)
        } else if (!lines[i + 1] || /^#/.test(lines[i + 1])) {
          if (cacheCode.length > 0) {
            cacheCode.push(l)
            cacheCode.push('```')
          }
          cacheLine = [...cacheLine, ...cacheCode]
          cacheCode.length = 0
        } else {
          cacheCode.push(l)
        }
      })
    return {
      source: cacheLine.join('\n'),
      pathname: s.pathname
    }
  })
}

function writeDocs(sources) {
  return Promise.all(sources.map(s => {
    promisefy(fs.writeFile)(s.pathname, s.source, 'utf-8')
  }))
}

async function generateDoc() {
  const files = await getFileName(__dirname)
  const sources = await getCacheSource(files)
  await writeDocs(sources)
  return 'finished'
}

generateDoc()
.then(console.log.bind(console))



