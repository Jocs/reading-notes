import swap from '../sortingAndSearching/swap.js'

const leftChildIndex = i => 2 * i + 1
const rightChildIndex = i => 2 * i + 2

const heapify = (array, i, size, compareFn) => {
  if (i >= size) return

  let element = i
  let left = leftChildIndex(i)
  let right = rightChildIndex(i)
  if (compareFn(array[element], array[left]) && left < size) {
    element = left
  }
  if (compareFn(array[element], array[right]) && right < size) {
    element = right
  }
  if (i !== element) {
    swap(array, element, i)
    if (element < size) {
      heapify(array, element, size, compareFn)
    }
  }  
}

export default heapify