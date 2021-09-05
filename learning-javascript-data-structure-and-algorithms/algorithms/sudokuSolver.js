const INIT = 0

const usedInRow = (matrix, row, num) => {
  for (let i = 0; i < 9; i++) {
    if (matrix[row][i] === num) {
      return true
    }
  }

  return false
}

const usedInCol = (matrix, col, num) => {
  for (let i = 0; i < 9; i++) {
    if (matrix[i][col] === num) {
      return true
    }
  }

  return false
}

const usedInBox = (matrix, rowStart, colStart, num) => {
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (matrix[i + rowStart][j + colStart] === num) {
        return true
      }
    }
  }

  return false
}

const isSafe = (matrix, row, col, num) => {
  return !usedInRow(matrix, row, num)
    && !usedInCol(matrix, col, num)
    && !usedInBox(matrix, row - row % 3, col - col % 3, num)
}

const solveSudoku = matrix => {
  let row = -1
  let col = -1
  if (matrix.every((r, i) => {
    row = i
    return r.every((c, j) => {
      col = j
      return c !== INIT
    })
  })) {
    return true
  }

  for (let num = 1; num <= 9; num++) {
    if (isSafe(matrix, row, col, num)) {
      matrix[row][col] = num
      if (solveSudoku(matrix)) {
        return true
      }
      matrix[row][col] = INIT
    }
  }

  return false
}

const sudokuSolver = matrix => {
  if (solveSudoku(matrix)) {
    return matrix
  }

  return 'NO_SOLUTIONS'
}

console.log(sudokuSolver([
  [1, 2, 3, 4, 5, 6, 7, 8, 9],
  [0, 0, 0, 0, 0, 0, 0, 5, 0],
  [0, 0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0, 0],
  [4, 0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0, 0],
  [9, 0, 0, 0, 0, 0, 0, 0, 0]
]))