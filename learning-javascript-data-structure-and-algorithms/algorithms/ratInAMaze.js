
const isSafe = (maze, x, y) => {
  return x >= 0 && y >= 0 && x < maze.length && y < maze[0].length && maze[x][y] === 1
}

const findPath = (maze, x, y, solutions) => {
  if (x === maze.length - 1 && y === maze[0].length - 1) {
    if (isSafe(maze, x, y)) {
      solutions[x][y] = 1
      return true
    }
    return false
  }
  if (isSafe(maze, x, y)) {
    solutions[x][y] = 1
    if (findPath(maze, x + 1, y, solutions)) {
      return true
    }
    if (findPath(maze, x, y + 1, solutions)) {
      return true
    }
    solutions[x][y] = 0
    return false
  }

  return false
}

const ratInAMaze = (maze) => {
  const solutions = [...new Array(maze.length)].map(_ => [...new Array(maze[0].length)].fill(0))
  if (findPath(maze, 0, 0, solutions)) {
    return solutions
  }
  return 'NO_SOLUTIONS'
}

console.log(ratInAMaze([
  [1, 0, 1, 1, 1],
  [1, 1, 1, 0, 1],
  [0, 0, 0, 0, 1],
  [0, 1, 1, 1, 1]
]))
