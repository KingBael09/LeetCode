use std::cmp::{self, Ordering};

pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
    let mut left = 1;
    let mut right = *piles.iter().reduce(|f, c| f.max(c)).unwrap();

    let mut ans = right;

    while left <= right {
        let mid = left + (right - left) / 2;

        let mut hr = 0;

        for bananas in piles.iter() {
            hr += (bananas + mid - 1) / mid;
        }

        if hr <= h {
            ans = cmp::min(ans, mid);

            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    ans
}

pub fn min_eating_speed_smaller(piles: Vec<i32>, h: i32) -> i32 {
    let mut left = 1;
    let mut right = *piles.iter().reduce(|f, c| f.max(c)).unwrap();

    let mut ans = right;

    while left <= right {
        let mid = left + (right - left) / 2;

        let hr = piles
            .iter()
            .fold(0, |total, bananas| total + ((bananas + mid - 1) / mid));

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

fn main() {}
