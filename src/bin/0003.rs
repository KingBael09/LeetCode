use std::{cmp::max, collections::HashMap};

pub fn length_of_longest_substring(s: String) -> i32 {
    let mut start = 0;

    let mut max_size = 0;

    let mut map = HashMap::new();

    for (idx, ch) in s.char_indices() {
        if map.contains_key(&ch) {
            let last_idx = map.get(&ch).unwrap();
            start = max(start, last_idx + 1)
        }

        map.insert(ch, idx);

        max_size = max(max_size, idx - start + 1);
    }

    max_size as i32
}

pub fn length_of_longest_substring_other(s: String) -> i32 {
    let mut last = 0;
    let mut max_size = 0;

    let mut map = HashMap::new();

    for (idx, ch) in s.char_indices() {
        last = max(last, *map.get(&ch).unwrap_or(&0));
        map.insert(ch, idx + 1);
        max_size = max(max_size, idx + 1 - last);
    }

    max_size as i32
}

fn main() {
    let input = String::from("dvdf");

    let result = length_of_longest_substring(input);

    println!("{result}")
}
