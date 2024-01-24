use std::cmp::{self, Ordering};

pub fn trap(height: Vec<i32>) -> i32 {
    let mut iter = height.into_iter().enumerate();

    let (mut l_iter, mut r_iter) = (iter.next(), iter.next_back());

    let mut pool_height = 0;

    let mut water = 0;

    while let (Some((l, l_height)), Some((r, r_height))) = (l_iter, r_iter) {
        if l.eq(&r) {
            break;
        }

        let min_height = cmp::min(l_height, r_height);

        pool_height = cmp::max(pool_height, min_height);

        water += 0.max(pool_height - min_height);

        if l_height.cmp(&r_height) == Ordering::Less {
            l_iter = iter.next();
        } else {
            r_iter = iter.next_back()
        }
    }

    water
}

pub fn trap_other(height: Vec<i32>) -> i32 {
    let mut water = 0;

    let (mut left, mut right) = (0, height.len() - 1);

    let mut pool_height = 0;

    while left < right {
        let (l_height, r_height) = (height[left], height[right]);

        let min_height = cmp::min(l_height, r_height);

        pool_height = cmp::max(min_height, pool_height);

        water += 0.max(pool_height - min_height);

        if l_height < r_height {
            left += 1
        } else {
            right += 1
        }
    }

    water
}

pub fn trap_other_other(height: Vec<i32>) -> i32 {
    let (mut left, mut right) = (0, height.len() - 1);

    let mut pool_height = 0;

    let mut water = 0;

    while left < right {
        let l_height = height[left];
        let r_height = height[right];
        let min_height = l_height.min(r_height);

        pool_height = pool_height.max(min_height);

        water += 0.max(pool_height - min_height);

        if l_height < r_height {
            left += 1
        } else {
            right += 1
        }
    }

    water
}

fn main() {}
