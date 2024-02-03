fn update(prev: i32, curr: i32, ans: &mut Vec<String>) {
    ans.push(if prev == curr {
        format!("{prev}")
    } else {
        format!("{prev}->{curr}")
    });
}

pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
    let mut ans = Vec::new();

    if !nums.is_empty() {
        let mut prev = nums[0];
        let mut curr = nums[0];

        for i in nums[1..].iter() {
            if curr + 1 != *i {
                update(prev, curr, &mut ans);
                prev = *i;
            }
            curr = *i
        }
        update(prev, curr, &mut ans);
    }

    ans
}

fn main() {}
