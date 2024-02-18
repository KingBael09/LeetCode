use std::collections::HashMap;

// damn tle
pub fn check_inclusion_with_tle(s1: String, s2: String) -> bool {
    let mut map = HashMap::new();

    s1.chars().for_each(|c| {
        map.entry(c).and_modify(|ct| *ct += 1).or_insert(1_usize);
    });

    let mut frame = s2.len();

    while frame != 0 {
        for f in s2.as_bytes().windows(frame) {
            let mut small_map = HashMap::new();

            String::from_utf8(f.to_vec())
                .unwrap()
                .chars()
                .for_each(|c| {
                    small_map
                        .entry(c)
                        .and_modify(|ct| *ct += 1)
                        .or_insert(1_usize);
                });

            if small_map.eq(&map) {
                return true;
            }
        }

        frame -= 1;
    }

    false
}

pub fn check_inclusion_slow_but_clean(s1: String, s2: String) -> bool {
    let mut map = HashMap::new();

    s1.chars().for_each(|c| {
        map.entry(c).and_modify(|ct| *ct += 1).or_insert(1_usize);
    });

    let s2: Vec<char> = s2.chars().collect();

    s2.windows(s1.len()).any(|part| {
        let mut clone = map.clone();

        part.iter().for_each(|c| {
            if let Some(f) = clone.get_mut(c) {
                *f -= 1;

                if (*f).eq(&0) {
                    clone.remove(c);
                }
            }
        });

        clone.is_empty()
    })
}

pub fn check_inclusion(s1: String, s2: String) -> bool {
    let (len1, len2) = (s1.len(), s2.len());

    let mut counts = [0; 26];

    let (s1, s2) = (s1.into_bytes(), s2.into_bytes());

    for i in 0..len1 {
        counts[(s2[i] - b'a') as usize] -= 1;
        counts[(s1[i] - b'a') as usize] += 1;
    }

    if counts.iter().all(|ct| 0.eq(ct)) {
        return true;
    }

    for i in len1..len2 {
        counts[(s2[i - len1] - b'a') as usize] += 1;
        counts[(s2[i] - b'a') as usize] -= 1;
        if counts.iter().all(|ct| 0.eq(ct)) {
            return true;
        }
    }

    false
}
fn main() {}
