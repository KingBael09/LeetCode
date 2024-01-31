use std::cmp::Ordering;

pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
    points.sort_by_key(|x| x[1]);

    let (count, _) = points
        .iter()
        .skip(1)
        .fold((1, points[0][1]), |(count, curr), x| {
            match curr.cmp(&x[0]) {
                Ordering::Less => (count + 1, x[1]),
                _ => (count, curr.min(x[1])),
            }
        });

    count
}

fn main() {}
