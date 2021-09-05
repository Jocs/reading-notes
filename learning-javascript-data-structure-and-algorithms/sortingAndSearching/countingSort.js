import createRandomArray from "./randomIntArray.js"

const countingSort = (array) => {
  if (array.length < 2) {
    return array
  }
  const maxValue = Math.max(...array)
  const len = array.length
  const map = new Map()
  for (let i = 0; i < len; i++) {
    if (map.has(array[i])) {
      map.set(array[i], map.get(array[i]) + 1)
    } else {
      map.set(array[i], 1)
    }
  }
  let k = 0
  for (let j = 0; j <= maxValue; j++) {
    if (map.has(j)) {
      let count = map.get(j)
      while (count) {
        array[k++] = j
        count--
      }
    }
  }

  return array
}
