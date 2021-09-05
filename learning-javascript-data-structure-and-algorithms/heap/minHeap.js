import swap from '../sortingAndSearching/swap.js'

const leftChildIndex = i => 2 * i + 1
const rightChildIndex = i => 2 * i + 2
const parentIndex = i => i === 0 ? undefined : Math.floor((i - 1) / 2)

class MinHeap {
  constructor() {
    this.heap = []
  }

  siftUp(index) {
    let parent = parentIndex(index)
    while (parent) {
      if (this.heap[parent] > this.heap[index]) {
        swap(this.heap, parent, index)
        index = parent
        parent = parentIndex(index)
      } else {
        break
      }
    }
  }

  siftDown(index) {
    let element = index
    let left = leftChildIndex(index)
    let right = rightChildIndex(index)
    if (this.heap[element] > this.heap[left]) {
      element = left
    }
    if (this.heap[element] > this.heap[right]) {
      element = right
    }
    if (index !== element) {
      swap(this.heap, element, index)
      this.siftDown(element)
    }
  }

  insert(value) {
    this.heap.push(value)
    this.siftUp(this.heap.length - 1)
  }

  findMinValue() {
    return this.heap[0]
  }

  extract() {
    const value = this.heap.shift()
    this.heap.unshift(this.heap.pop())
    this.siftDown(0)

    return value
  }

  size() {
    return this.heap.length
  }

  isEmpty() {
    return this.size() === 0
  }
}

const minHeap = new MinHeap()
minHeap.insert(1)
minHeap.insert(2)
minHeap.insert(5)
minHeap.insert(17)
minHeap.insert(9)
console.log(JSON.stringify(minHeap.heap))
console.log(minHeap.size())
console.log(minHeap.isEmpty())
console.log(minHeap.findMinValue())
console.log(minHeap.extract())
console.log(JSON.stringify(minHeap.heap))
console.log(minHeap.size())