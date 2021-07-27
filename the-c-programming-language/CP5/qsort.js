// js version of quick sort.

const swap = (arr, i, j) => {
  const temp = arr[i]
  arr[i] = arr[j]
  arr[j] = temp
}

const qsort = (arr, left, right) => {
  if (left >= right)
    return

  let i
  let last
  swap(arr, left, Math.floor((left + right) / 2))
  last = left
  for (i = left + 1; i <= right; i++) {
    if (arr[i] < arr[left])
      swap(arr, i, ++last)
  }
  swap(arr, left, last)
  qsort(arr, left, last - 1)
  qsort(arr, last + 1, right)
}

const arr = [4, 5, 3, 1, 8, 6, 4, 8, 9, 2, 6]

qsort(arr, 0, arr.length - 1)

console.log(arr)