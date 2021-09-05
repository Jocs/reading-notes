import createRandomArray from "./randomIntArray.js"

const merge = (left, right) => {
  const result = []
  while (left.length && right.length) {
    if (left[0] < right[0]) {
      result.push(left.shift())
    } else {
      result.push(right.shift())
    }
  }

  if (left.length) {
    result.push(...left)
  }

  if (right.length) {
    result.push(...right)
  }

  return result
}

const mergeSort = (array) => {
  const len = array.length
  if (len > 1) {
    const middle = ~~(len / 2)
    return merge(
      mergeSort(array.slice(0, middle)),
      mergeSort(array.slice(middle, len))
    )
  }

  return array
}