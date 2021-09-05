const minCoinChange = (coins, amount) => {
  if (coins.includes(amount)) return 1
  return Math.min(...coins.filter(c => amount > c).map(c => 1 + minCoinChange(coins, amount - c)))
}