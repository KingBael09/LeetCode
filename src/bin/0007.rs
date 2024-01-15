pub fn reverse(mut x: i32) -> i32 {
    let mut rev = 0;

    while x != 0 {
        if !(i32::MIN / 10..=i32::MAX / 10).contains(&rev) {
            return 0;
        }

        rev = rev * 10 + (x % 10);
        x /= 10;
    }

    rev
}

// Another way

pub fn reverse_oth(mut x: i32) -> i32 {
    let mut rev: i32 = 0;

    while x != 0 {
        match rev.checked_mul(10) {
            None => return 0,
            Some(t) => match t.checked_add(x % 10) {
                None => return 0,
                Some(t) => rev = t,
            },
        }
        x /= 10;
    }

    rev
}

fn main() {}
