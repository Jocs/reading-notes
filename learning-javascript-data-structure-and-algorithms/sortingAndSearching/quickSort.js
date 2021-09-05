import swap from './swap.js'
import createRandomArray from "./randomIntArray.js"

const partition = (array, left, right) => {
  const middle = Math.floor((right + left) / 2)
  let i = left
  let j = right
  const middleValue = array[middle]
  while (i <= j) {
    while (array[i] < middleValue)
      i++
    while (array[j] > middleValue)
      j--

    if (i <= j) {
      swap(array, i, j)
      i++
      j--
    }
  }

  return i
}

const quick = (array, left, right) => {
  const index = partition(array, left, right)
  if (left < index - 1) {
    quick(array, left, index - 1)
  }
  if (index < right) { // 为什么不是 index + 1
    quick(array, index, right)
  }
}

const quickSort = (array) => {
  quick(array, 0, array.length - 1)
  return array
}

export default quickSort
