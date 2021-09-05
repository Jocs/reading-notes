import createRandomArray from "./randomIntArray.js"

const createBuckets = (array, bucketSize) => {
  let minValue = Infinity
  let maxValue = -Infinity
  for (const num of array) {
    if (num < minValue) {
      minValue = num
    }
    if (num > maxValue) {
      maxValue = num
    }
  }

  const bucketsCount = Math.floor((maxValue - minValue) / bucketSize) + 1
  const buckets = [...new Array(bucketsCount)].map(_ => [])
  for (const num of array) {
    const index = Math.floor((num - minValue) / bucketSize)
    buckets[index].push(num)
  }

  return buckets
}

const sortBuckets = async (buckets) => {
  const promises = []

  for (const bucket of buckets) {
    const wk = new Worker('./bucketSortWorker.js')
    promises.push(new Promise((resolve, reject) => {
      wk.addEventListener('message', function (event) {
        if (event.data.aTopic) {
          resolve(Array.from(new Int32Array(event.data.aBuf)))
        }
        resolve(event.data)
      })
    }))
    const bucketArray = new Int32Array(bucket)

    wk.postMessage({
      aTopic: 'do_sendWorkerArrBuff',
      aBuf: bucketArray.buffer
    }, [
      bucketArray.buffer
    ])
  }

  const res = await Promise.all(promises)

  return res.flatMap(items => items)
}

const bucketSort = async (array, bucketSize = 5) => {
  if (array.length < 2) {
    return array
  }

  const buckets = createBuckets(array, bucketSize)

  return await sortBuckets(buckets)
}

const data = createRandomArray(10000)
console.log('start bucketSort')
const start = +new Date()
bucketSort(data, 40)
  .then(res => {
    console.log(+ new Date() - start)
    console.log('done')
  })