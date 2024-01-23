use std::{cmp::Ordering, collections::HashMap};

// Dumb Method
pub fn find_substring(s: String, mut words: Vec<String>) -> Vec<i32> {
    words.sort();

    let word_len = words.first().unwrap().len();
    let vec_len = words.len();

    let window_size = word_len * vec_len;

    let t = s.as_bytes().windows(window_size).map(|x| {
        // let str = String::from_utf8(x.to_vec()).unwrap_or_default();

        let mut s: Vec<String> = x
            .chunks(word_len)
            .map(|y| String::from_utf8(y.to_vec()).unwrap_or_default())
            .collect();

        s.sort();

        if s == words {
            Some(s)
        } else {
            None
        }
    });

    let mut ans = Vec::new();

    for (i, a) in t.enumerate() {
        // println!("{i}: {:?}\n", a);

        if a.is_some() {
            ans.push(i as i32)
        }
    }

    ans
}

// Shorter but still slow method
pub fn find_substring_other(s: String, mut words: Vec<String>) -> Vec<i32> {
    words.sort();

    let word_len = words.first().unwrap().len();
    let vec_len = words.len();

    let window_size = word_len * vec_len;
    let mut ans = Vec::new();

    for (i, x) in s.as_bytes().windows(window_size).enumerate() {
        let mut s: Vec<String> = x
            .chunks(word_len)
            .map(|y| String::from_utf8(y.to_vec()).unwrap_or_default())
            .collect();

        s.sort();

        if s.cmp(&words) == Ordering::Equal {
            ans.push(i as i32)
        }
    }

    ans
}

pub fn find_substring_other_still_slow(s: String, words: Vec<String>) -> Vec<i32> {
    let word_len = words.first().unwrap().len();
    let vec_len = words.len();

    let window_size = word_len * vec_len;

    let map = words.into_iter().fold(HashMap::new(), |mut mp, s| {
        *mp.entry(s).or_insert(0) += 1;
        mp
    });

    let mut ans = Vec::new();

    for (i, x) in s.as_bytes().windows(window_size).enumerate() {
        if x.chunks(word_len)
            .map(|y| String::from_utf8(y.to_vec()).unwrap_or_default())
            .fold(HashMap::new(), |mut mp, s| {
                *mp.entry(s).or_insert(0) += 1;
                mp
            })
            .eq(&map)
        {
            ans.push(i as i32)
        }
    }

    ans
}

fn main() {
    let s = String::from("barfoofoobarthefoobarman");
    let words = vec!["bar".to_string(), "foo".to_string(), "the".to_string()];

    let res = find_substring(s, words);

    println!("{:?}", res)
}
