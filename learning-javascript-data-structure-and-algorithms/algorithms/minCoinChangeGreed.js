const minCoinChange = (coins, amount) => {
  let result = 0
  const sortedCoins = coins.sort()
  const len = coins.length

  while (amount > 0) {
    for (let i = len - 1; i >= 0; i--) {
      if (amount >= sortedCoins[i]) {
        amount = amount - sortedCoins[i]
        result++
        break
      }
    }
  }

  return result
}