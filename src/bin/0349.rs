use std::collections::HashSet;

pub fn intersection(mut nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    nums1.sort();

    let mut ans = HashSet::new();

    nums2.into_iter().for_each(|x| {
        if let Ok(i) = nums1.binary_search(&x) {
            ans.insert(nums1[i]);
        }
    });

    ans.into_iter().collect()
}
pub fn intersection_other(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let set_a: HashSet<i32> = HashSet::from_iter(nums1);
    let set_b: HashSet<i32> = HashSet::from_iter(nums2);

    set_a.intersection(&set_b).copied().collect()
}

fn main() {}
