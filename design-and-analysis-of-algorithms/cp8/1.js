  /**
   * 币值最大化问题：给定一排 n 个硬币，其面值均为正整数c1,c2...cn,这些硬币并不一定
   * 两两相同。请问如何选择硬币，是的其原始位置互不相邻的条件下，所选的硬币总金额最大。
   */

  const getMaxSum = coins => {
    const len = coins.length
    if (len === 0) return 0
    if (len === 1) return coins[0]

    let pre1 = 0
    let pre2 = coins[0]
    let i
    for (i = 1; i < len; i++) {
      const num = coins[i]
      const temp = pre2
      pre2 = Math.max(num + pre1, temp)
      pre1 = temp
    }

    return pre2
  }

  console.log(getMaxSum([1, 2, 4, 5, 6, 3]))