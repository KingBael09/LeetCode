fn dfs(board: &mut Vec<Vec<char>>, i: usize, j: usize) {
    let (rows, cols) = (board.len(), board.first().unwrap().len());

    board[i][j] = 'Z';

    for (i, j) in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)] {
        if i < rows && j < cols && board[i][j] == 'O' {
            dfs(board, i, j);
        }
    }
}

// dfs
pub fn solve(board: &mut Vec<Vec<char>>) {
    let (rows, cols) = (board.len(), board.first().unwrap().len());

    // left and right cols
    for i in 0..rows {
        for j in [0, cols - 1] {
            if board[i][j] == 'O' {
                dfs(board, i, j);
            }
        }
    }

    // Top and bottom rows
    for j in 0..cols {
        for i in [0, rows - 1] {
            if board[i][j] == 'O' {
                dfs(board, i, j);
            }
        }
    }

    for v in board.iter_mut() {
        for ch in v.iter_mut() {
            if ch == &'O' {
                *ch = 'X';
            } else if ch == &'Z' {
                *ch = 'O';
            }
        }
    }
}

const MOVES: [i32; 5] = [0, 1, 0, -1, 0];

// bfs
pub fn solve_bfs(board: &mut Vec<Vec<char>>) {
    let mut stack = Vec::new();

    let (rows, cols) = (board.len(), board.first().unwrap().len());

    // first and last rows
    let r = (0..cols).flat_map(|x| [(0, x), (rows - 1, x)]);

    // first and last cols
    let c = (0..rows).flat_map(|x| [(x, 0), (x, cols - 1)]);

    c.chain(r).for_each(|(i, j)| {
        stack.push((i, j));

        while let Some((i, j)) = stack.pop() {
            if i < rows && j < cols && board[i][j] == 'O' {
                board[i][j] = 'Z';

                MOVES
                    .windows(2)
                    .for_each(|w| stack.push((i + w[0] as usize, j + w[1] as usize)))
            }
        }
    });

    board.iter_mut().for_each(|row| {
        row.iter_mut().for_each(|cell| match cell {
            'Z' => *cell = 'O',
            'O' => *cell = 'X',
            _ => (),
        })
    });
}

fn main() {}
