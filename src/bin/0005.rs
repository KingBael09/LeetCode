pub fn longest_palindrome(s: String) -> String {
    let result = String::new();
    let mut window_size = s.len();

    while window_size > 0 {
        let res = s.as_bytes().windows(window_size).find(|slice| {
            let iter = slice.iter();
            let rev_iter = slice.iter().rev();
            iter.eq(rev_iter)
        });

        match res {
            Some(slice) => return String::from_utf8(slice.to_vec()).unwrap_or(result),
            None => window_size -= 1,
        }
    }

    result
}

fn main() {}
