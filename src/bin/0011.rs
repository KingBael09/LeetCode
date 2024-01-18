use std::cmp;

pub fn max_area(height: Vec<i32>) -> i32 {
    let (mut start, mut end, mut capacity) = (0, height.len() - 1, i32::MIN);

    while start != end {
        let (left, right) = (height[start], height[end]);

        let vol = cmp::min(left, right) * (end - start) as i32;

        if left < right {
            start += 1;
        } else {
            end -= 1;
        }

        capacity = cmp::max(vol, capacity);
    }

    capacity
}

fn main() {}
