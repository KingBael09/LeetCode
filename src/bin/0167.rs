use std::cmp::Ordering;

pub fn two_sum_inbuilt(numbers: Vec<i32>, target: i32) -> Vec<i32> {
    for (idx1, val) in numbers.iter().enumerate() {
        let rem = target - val;

        if let Ok(idx2) = numbers[idx1 + 1..].binary_search(&rem) {
            return vec![idx1 as i32, (idx2 + idx1) as i32];
        }
    }

    panic!("not found")
}

pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
    let (mut left, mut right) = (0, (numbers.len() - 1));

    while left < right {
        let sum = numbers[left] + numbers[right];
        match sum.cmp(&target) {
            Ordering::Less => left += 1,
            Ordering::Greater => right -= 1,
            Ordering::Equal => return vec![(left + 1) as i32, (right + 1) as i32],
        }
    }

    unreachable!()
}

fn main() {}
