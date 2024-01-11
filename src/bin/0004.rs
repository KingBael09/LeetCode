pub fn find_median_sorted_arrays_other(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
    let mut nums1 = nums1.clone();

    nums1.extend(&nums2);

    nums1.sort();

    let len = nums1.len();

    if len % 2 == 0 {
        let ans = nums1.get(len / 2 + 1).unwrap() + nums1.get(len / 2 - 1).unwrap();

        ans as f64 / 2_f64
    } else {
        let ans = *nums1.get(len / 2).unwrap();

        ans as f64
    }
}

// ---

fn median(nums: &Vec<i32>) -> f64 {
    let len = nums.len();

    let idx = len / 2;

    if len % 2 == 1 {
        *nums.get(idx).unwrap() as f64
    } else {
        let ans = nums.get(idx - 1).unwrap() + nums.get(idx).unwrap();
        ans as f64 / 2_f64
    }
}

use std::cmp::Ordering;

// This solution is still O(m+n) not O(log(m+n))
pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
    let len_a = nums1.len();
    let len_b = nums2.len();

    match (len_a, len_b) {
        (0, 0) => return 0.0,
        (_i, 0) => return median(&nums1),
        (0, _i) => return median(&nums2),
        _ => (),
    }

    let mut idx: usize = 0;
    let mut merged = Vec::with_capacity(len_a + len_b);

    let (mut vec_a, mut vec_b) = (nums1.into_iter(), nums2.into_iter());
    let (mut left, mut right) = (vec_a.next(), vec_b.next());

    loop {
        match (left, right) {
            (Some(a), Some(b)) => match a.cmp(&b) {
                Ordering::Equal => {
                    merged.insert(idx, a);
                    idx += 1;
                    merged.insert(idx, b);

                    left = vec_a.next();
                    right = vec_b.next();
                }
                Ordering::Less => {
                    merged.insert(idx, a);
                    left = vec_a.next();
                }
                Ordering::Greater => {
                    merged.insert(idx, b);
                    right = vec_b.next();
                }
            },
            (Some(a), None) => {
                merged.insert(idx, a);
                left = vec_a.next();
            }
            (None, Some(b)) => {
                merged.insert(idx, b);
                right = vec_b.next();
            }
            (None, None) => break,
        }
        idx += 1;
    }

    median(&merged)
}

fn main() {}
