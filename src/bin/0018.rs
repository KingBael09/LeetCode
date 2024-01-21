use std::collections::HashSet;

// Not the best solution out there
pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    nums.sort();
    let n = nums.len();

    let mut set = HashSet::new();

    for i in 0..n {
        if i != 0 && nums[i] == nums[i - 1] {
            continue;
        }
        for j in i + 1..n {
            for k in j + 1..n {
                let l_val = target
                    .saturating_sub(nums[i])
                    .saturating_sub(nums[j])
                    .saturating_sub(nums[k]);

                if nums[k + 1..].binary_search(&l_val).is_ok() {
                    set.insert(vec![nums[i], nums[j], nums[k], l_val]);
                };
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
