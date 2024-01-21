use std::collections::HashSet;

// Not the best solution out there
pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    nums.sort();
    let n = nums.len();

    let mut set = HashSet::new();

    for i in 0..n {
        for j in i + 1..n {
            for k in j + 1..n {
                let sum = 0_i32
                    .saturating_add(nums[i])
                    .saturating_add(nums[j])
                    .saturating_add(nums[k]);

                let l_val = target - sum;

                let res = match nums[k + 1..].binary_search(&l_val) {
                    Ok(x) => Some(x),
                    Err(_) => None,
                };

                if res.is_some() {
                    set.insert(vec![nums[i], nums[j], nums[k], l_val]);
                }
            }
        }
    }

    set.into_iter().collect()
}

fn main() {
    let t = -294967296;
    let v = vec![1000000000, 1000000000, 1000000000, 1000000000];

    println!("{:?}", four_sum(v, t))
}
