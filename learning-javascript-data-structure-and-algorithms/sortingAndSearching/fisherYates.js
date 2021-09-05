import swap from "./swap.js"
import createRandomArray from "./randomIntArray.js"
import quickSort from "./quickSort.js"

const shuffle = array => {
  const len = array.length
  for (let i = len - 1; i > 0; i--) {
    const randomNum = Math.floor(Math.random() * (i + 1))
    swap(array, randomNum, i)
  }
  return array
}

const data = createRandomArray()
const sortedArray = quickSort(data)
// console.log(JSON.stringify(sortedArray))
shuffle(sortedArray)
// console.log(JSON.stringify(sortedArray))