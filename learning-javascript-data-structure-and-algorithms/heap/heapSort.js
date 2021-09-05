import heapify from './heapify.js'
import swap from '../sortingAndSearching/swap.js'
import createRandomArray from '../sortingAndSearching/randomIntArray.js'

const makeMaxHeap = array => {
  const len = array.length
  for (let i = Math.floor(len / 2); i >= 0; i--) {
    heapify(array, i, len, (a, b) => a < b)
  }
  return array
}

const heapSort = array => {
  let heapSize = array.length
  makeMaxHeap(array)

  while (--heapSize > 0) {
    swap(array, 0, heapSize)
    heapify(array, 0, heapSize, (a, b) => a < b)
  }

  return array
}

const data = createRandomArray()
console.log(heapSort(data))
