import swap from './swap.js'
import createRandomArray from './randomIntArray.js'

const selectionSort = (array) => {
  const len = array.length

  for (let i = 0; i < len; i++) {
    let minValue = array[i]
    let minIndex = i
    for (let j = i; j < len; j++) {
      if (array[j] < minValue) {
        minValue = array[j]
        minIndex = j
      }
    }
    if (array[i] !== minValue) {
      swap(array, i, minIndex)
    }
  }

  return array
}