pub fn judge_circle(moves: String) -> bool {
    let (mut x, mut y) = (0, 0);

    moves.chars().for_each(|c| match c {
        'U' => x += 1,
        'D' => x -= 1,
        'L' => y -= 1,
        'R' => y += 1,
        _ => panic!(""),
    });

    (x, y) == (0, 0)
}

pub fn judge_circle_other(moves: String) -> bool {
    moves
        .chars()
        .fold((0, 0), |(x, y), ch| match ch {
            'U' => (x + 1, y),
            'D' => (x - 1, y),
            'L' => (x, y - 1),
            'R' => (x, y + 1),
            _ => (x, y),
        })
        .eq(&(0, 0))
}
fn main() {}
