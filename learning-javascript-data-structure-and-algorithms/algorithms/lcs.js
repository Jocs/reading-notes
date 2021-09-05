// 最长公共子序列
const lcs = (wordA, wordB) => {
  const lenA = wordA.length
  const lenB = wordB.length
  const matrix = [...new Array(lenA + 1)].map(_ => [...new Array(lenB + 1)].fill(0))

  for (let i = 1; i <= lenA; i++) {
    for (let j = 1; j <= lenB; j++) {
      if (wordA[i - 1] === wordB[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1] + 1
      } else {
        matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1])
      }
    }
  }

  return matrix[lenA][lenB]
}