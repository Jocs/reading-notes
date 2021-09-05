import swap from './swap.js'
import createRandomArray from "./randomIntArray.js"

const bubbleSort = (array) => {
  const len = array.length
  for (let i = 0; i < len - 1; i++) {
    for (let j = 1; j < len - i; j++) {
      if (array[j - 1] > array[j]) {
        swap(array, j - 1, j)
      }
    }
  }
}

const data = createRandomArray(10000)
console.log('start bubble sort')
const start = +new Date()
bubbleSort(data)
console.log(+ new Date() - start)
console.log('done')
