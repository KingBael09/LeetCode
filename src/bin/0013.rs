use std::collections::HashMap;

pub fn roman_to_int(s: String) -> i32 {
    let map = HashMap::from([
        ('M', 1000),
        ('D', 500),
        ('C', 100),
        ('L', 50),
        ('X', 10),
        ('V', 5),
        ('I', 1),
    ]);

    let mut count = 0;

    let mut prev = None;

    for ch in s.chars().rev() {
        if prev.is_none() {
            count += map.get(&ch).unwrap()
        } else if map.get(&prev.unwrap()).unwrap() > map.get(&ch).unwrap() {
            count -= map.get(&ch).unwrap();
        } else {
            count += map.get(&ch).unwrap()
        }
        prev = Some(ch);
    }

    count
}

pub fn roman_to_int_other(s: String) -> i32 {
    let map = HashMap::from([
        ('M', 1000),
        ('D', 500),
        ('C', 100),
        ('L', 50),
        ('X', 10),
        ('V', 5),
        ('I', 1),
    ]);

    let mut count = 0;

    let mut prev = None;

    for ch in s.chars().rev() {
        let current = map.get(&ch).unwrap();

        if let Some(old_ch) = prev {
            if current < map.get(&old_ch).unwrap() {
                count -= current;
                continue;
            }
        }

        count += current;

        prev = Some(ch);
    }

    count
}

pub fn roman_to_int_other_other(s: String) -> i32 {
    let map = HashMap::from([
        ('M', 1000),
        ('D', 500),
        ('C', 100),
        ('L', 50),
        ('X', 10),
        ('V', 5),
        ('I', 1),
    ]);

    let mut prev = None;

    s.chars()
        .rev()
        .map(|ch| {
            let mut current = *map.get(&ch).unwrap();
            if prev.is_some() && map.get(&prev.unwrap()).unwrap() > &current {
                current *= -1;
            }

            prev = Some(ch);

            current
        })
        .sum()
}

fn main() {}
