use std::{
    cmp::Ordering,
    collections::{HashMap, HashSet},
};

fn distinct(i: usize, j: usize, k: usize) -> bool {
    i != j && i != k && j != k
}

// This has very bad runtime
pub fn three_sum_other(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut map = HashMap::new();

    for (idx, val) in nums.iter().enumerate() {
        map.insert(val, idx);
    }

    let mut set = HashSet::new();

    // for (i_idx, i) in nums.iter().enumerate() {
    //     for (j_idx, j) in nums.iter().enumerate() {
    //         let k = -i - j;
    //         let k_idx = *map.get(&k).unwrap_or(&0);

    //         if map.contains_key(&k) && distinct(i_idx, j_idx, k_idx) {
    //             let mut res = vec![*i, *j, k];
    //             res.sort();
    //             set.insert(res);
    //         }
    //     }
    // }

    let n = nums.len();

    for i_idx in 0..n {
        for j_idx in i_idx + 1..n {
            let (i, j) = (nums.get(i_idx).unwrap(), nums.get(j_idx).unwrap());

            let k = -i - j;

            let k_idx = *map.get(&k).unwrap_or(&0);

            if map.contains_key(&k) && distinct(i_idx, j_idx, k_idx) {
                let mut res = vec![*i, *j, k];
                res.sort();
                set.insert(res);
            }
        }
    }

    set.into_iter().collect()
}
pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
    nums.sort();

    let mut ans = Vec::new();

    for i in 0..nums.len() {
        if i != 0 && nums[i] == nums[i - 1] {
            continue;
        }

        let (mut l, mut r) = (i + 1, nums.len() - 1);

        while l < r {
            let sum = nums[l] + nums[i] + nums[r];

            match sum.cmp(&0) {
                Ordering::Greater => r -= 1,
                Ordering::Less => l += 1,
                Ordering::Equal => {
                    ans.push(vec![nums[l], nums[i], nums[r]]);
                    l += 1;

                    while nums[l] == nums[l - 1] && l < r {
                        l += 1;
                    }
                }
            }
        }
    }

    ans
}

// Still not the fastest
pub fn three_sum_other_other(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
    // nums.sort();
    nums.sort_unstable();
    let n = nums.len();

    let mut answer = HashSet::new();

    for i in 0..n {
        for j in i + 1..n {
            let (i_val, j_val) = (*nums.get(i).unwrap(), *nums.get(j).unwrap());

            let k_val = -i_val - j_val;

            let res = match nums[j + 1..].binary_search(&k_val) {
                Ok(x) => Some(x),
                Err(_) => None,
            };

            if res.is_some() {
                answer.insert(vec![i_val, j_val, k_val]);
            }
        }
    }

    answer.into_iter().collect()
}

fn main() {
    let v = vec![-1, 0, 1, 2, -1, -4];

    println!("{:?}", three_sum(v))
}
