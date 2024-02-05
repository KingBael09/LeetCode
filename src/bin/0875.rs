use std::cmp::{self, Ordering};

pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
    let mut left = 1;
    let mut right = *piles.iter().reduce(|f, c| f.max(c)).unwrap();

    let mut ans = right;

    while left <= right {
        let mid = left + (right - left) / 2;

        let mut hr: i64 = 0;

        for bananas in piles.iter() {
            hr += ((bananas + mid - 1) / mid) as i64;
        }

        if hr <= h as i64 {
            ans = cmp::min(ans, mid);

            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    ans
}

pub fn min_eating_speed_smaller(piles: Vec<i32>, h: i32) -> i32 {
    let (mut left, mut right) = (1, *piles.iter().max().unwrap());

    let mut ans = right;

    while left <= right {
        let mid = left + (right - left) / 2;

        let hr = piles.iter().fold(0_i32, |total, bananas| {
            total.saturating_add((bananas + mid - 1) / mid)
        });

        match hr.cmp(&h) {
            Ordering::Greater => left = mid + 1,
            _ => {
                ans = cmp::min(ans, mid);
                right = mid - 1
            }
        }
    }

    ans
}

fn main() {
    let v = [805306368, 805306368, 805306368];
    let h = 1000000000;

    println!("{}", min_eating_speed(v.to_vec(), h))
}
