use std::cmp::Ordering;

pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
    nums.sort();
    let mut diff: i32 = i32::MAX;

    for (i, c) in nums.iter().enumerate() {
        if i != 0 && nums[i] == nums[i - 1] {
            continue;
        }

        let mut iter = nums[i + 1..].iter();

        let (mut left, mut right) = (iter.next(), iter.next_back());

        while let (Some(l), Some(r)) = (left, right) {
            let sum = l + c + r;

            match sum.cmp(&target) {
                Ordering::Equal => return target,
                Ordering::Greater => right = iter.next_back(),
                Ordering::Less => left = iter.next(),
            }

            if (target - sum).abs() < diff.abs() {
                diff = target - sum;
            }
        }
    }

    target - diff
}

fn main() {
    let v = vec![-1, 2, 1, -4];

    let t = 1;

    println!("{}", three_sum_closest(v, t))
}
