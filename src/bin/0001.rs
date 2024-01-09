use std::collections::HashMap;

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut map = HashMap::new();

    for (i, num) in nums.iter().enumerate() {
        let diff = target - num;

        if map.contains_key(&diff) {
            return vec![map[&diff], i as i32];
        }

        map.insert(num, i as i32);
    }

    vec![-1, -1]
}

pub fn two_sum_better(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut map = HashMap::new();

    for (i, v) in nums.iter().enumerate() {
        let counter = target - v;
        if let Some(&idx) = map.get(&counter) {
            return vec![i as i32, idx as i32];
        }
        map.insert(v, i);
    }

    panic!("This wasn't suppose to happen")
}

fn main() {
    let nums = vec![3, 2, 4];

    let target = 6;

    let result = two_sum(nums, target);

    println!("{:#?}", result); // [1, 2])
}
