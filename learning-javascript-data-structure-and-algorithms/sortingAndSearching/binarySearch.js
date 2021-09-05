import createRandomArray from "./randomIntArray.js"
import quickSort from "./quickSort.js"
// return index if fount num in array, else return -1.
const binarySearch = (array, num) => {
  let low = 0
  let high = array.length - 1
  while (low <= high) {
    const middle = Math.floor((high + low) / 2)
    const element = array[middle]
    if (num === element) {
      return middle
    } else if (num < element) {
      high = middle - 1
    } else if (num > element) {
      low = middle + 1
    }
  }

  return -1
}



const data = createRandomArray()
const target = data[0]
const sortedArray = quickSort(data)
// console.log(sortedArray, target)
// console.log(binarySearch(sortedArray, target))