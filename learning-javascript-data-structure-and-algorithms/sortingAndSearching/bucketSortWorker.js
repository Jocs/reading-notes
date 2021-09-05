const swap = (array, i, j) => {
  const temp = array[i]
  array[i] = array[j]
  array[j] = temp
}

const bubbleSort = (array) => {
  const len = array.length
  for (let i = 0; i < len - 1; i++) {
    for (let j = 1; j < len - i; j++) {
      if (array[j - 1] > array[j]) {
        swap(array, j - 1, j)
      }
    }
  }
  return array
}

onmessage = function (event) {
  if (event.data.aTopic) {
    const view = new Int32Array(event.data.aBuf)
    bubbleSort(view)
    postMessage({
      aTopic: 'do_sendWorkerArrBuff',
      aBuf: view.buffer
    }, [
      view.buffer
    ])
  }
}