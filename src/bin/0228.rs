fn update(a: i32, b: i32, v: &mut Vec<String>) {
    v.push(if a == b {
        format!("{a}")
    } else {
        format!("{a}->{b}")
    });
}

pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
    let mut ans = Vec::new();

    if !nums.is_empty() {
        let mut a = nums[0];
        let mut b = nums[0];

        for i in nums[1..].iter() {
            if b + 1 != *i {
                update(a, b, &mut ans);
                a = *i;
            }
            b = *i
        }
        update(a, b, &mut ans);
    }

    ans
}

fn main() {}
