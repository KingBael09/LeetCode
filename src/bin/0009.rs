pub fn is_palindrome(x: i32) -> bool {
    if x >= 0 {
        let mut y = 0;
        let mut z = x;

        while z != 0 {
            let last = z % 10;
            z /= 10;

            y = y * 10 + last;
        }

        if x == y {
            return true;
        }
    }

    false
}

pub fn is_palindrome_other(x: i32) -> bool {
    // x == x
    //     .to_string()
    //     .chars()
    //     .rev()
    //     .collect::<String>()
    //     .parse()
    //     .unwrap_or(0)

    let y = x.to_string();

    y.chars()
        .zip(y.chars().rev())
        .take_while(|(x, y)| x == y)
        .count()
        == y.len()
}

fn main() {}
