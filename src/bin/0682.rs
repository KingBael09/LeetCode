pub fn cal_points(operations: Vec<String>) -> i32 {
    let mut res = Vec::new();

    for str in operations.iter() {
        match str.as_str() {
            "C" => res.truncate(res.len() - 1),
            "D" => res.push(res.last().take().unwrap() * 2),
            "+" => res.push(res.iter().rev().take(2).sum()),
            s => res.push(s.parse().unwrap()),
        }
    }

    res.into_iter().sum()
}

fn main() {}
