import createRandomArray from './randomIntArray.js'

const insertionSort = (array) => {
  const len = array.length
  for (let i = 0; i < len; i++) {
    let idx = i + 1
    while (idx > 0 && array[idx - 1] > array[i + 1]) {
      idx--
    }

    if (idx !== i + 1) {
      const temp = array[i + 1]
      for (let j = i + 1; j > idx; j--) {
        array[j] = array[j - 1]
      }
      array[idx] = temp
    }
  }
  return array
}