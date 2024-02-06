use std::collections::HashMap;

pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let mut set = HashMap::new();

    nums1.into_iter().for_each(|x| {
        set.entry(x).and_modify(|ct| *ct += 1).or_insert(1);
    });

    let mut ans = Vec::new();

    nums2.into_iter().for_each(|x| {
        if let Some(freq) = set.get(&x) {
            if freq > &0 {
                set.entry(x).and_modify(|ct| *ct -= 1).or_insert(-1);
                ans.push(x)
            }
        }
    });

    ans
}

pub fn intersect_smaller(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let mut set = HashMap::new();

    nums1.into_iter().for_each(|x| {
        set.entry(x).and_modify(|ct| *ct += 1).or_insert(1);
    });

    let mut ans = Vec::new();

    nums2.into_iter().for_each(|x| {
        if let Some(freq) = set.get_mut(&x) {
            ans.push(x);
            *freq -= 1;

            if *freq == 0 {
                set.remove(&x);
            }
        }
    });

    ans
}

fn main() {}
