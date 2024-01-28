use std::{cmp, collections::HashMap};

pub fn longest_palindrome(s: String) -> i32 {
    let mut map = HashMap::new();

    s.chars().for_each(|x| *map.entry(x).or_insert(0) += 1);

    let mut odd = 0;

    let mut count = 0;

    map.into_iter().for_each(|(_, freq)| {
        if freq % 2 == 0 {
            count += freq;
        } else {
            odd = cmp::max(odd, freq);

            count += freq - 1;
        }
    });

    // count + odd
    if odd == 0 {
        count
    } else {
        count + 1
    }
}

fn main() {}
