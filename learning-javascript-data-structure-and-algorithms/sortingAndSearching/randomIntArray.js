const createRandomArray = (n = 10, range = 100) => {
  return [...new Array(n)].map(i => ~~(Math.random() * range))
}

export default createRandomArray