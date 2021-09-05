// 背包问题
const knapSack = (capacity, weights, values) => {
  const n = weights.length
  const KS = [...new Array(n + 1)].map((_) => [...new Array(capacity + 1)].fill(0))
  for (let i = 0; i < n + 1; i++) {
    for (let w = 0; w < capacity + 1; w++) {
      if (i === 0 || w === 0) {
        KS[i][w] = 0
      } else if (weights[i - 1] > w) {
        KS[i][w] = KS[i - 1][w]
      } else {
        KS[i][w] = Math.max(KS[i - 1][w], values[i - 1] + KS[i - 1][w - weights[i - 1]])
      }
    }
  }

  console.log(JSON.stringify(KS, null, 2))

  return KS[n][capacity]
}

console.log(knapSack(5, [1, 2, 5], [1000, 3000, 10000]))