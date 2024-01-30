fn dfs(grid: &mut Vec<Vec<char>>, i: usize, j: usize) {
    let (rows, cols) = (grid.len(), grid.first().unwrap().len());

    grid[i][j] = '0';

    for (i, j) in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)] {
        if i < rows && j < cols && grid[i][j] == '1' {
            dfs(grid, i, j);
        }
    }
}

pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
    let (rows, cols) = (grid.len(), grid.first().unwrap().len());

    let mut count = 0;

    for i in 0..rows {
        for j in 0..cols {
            if grid[i][j] == '1' {
                count += 1;
                dfs(&mut grid, i, j);
            }
        }
    }

    count
}

fn main() {}
