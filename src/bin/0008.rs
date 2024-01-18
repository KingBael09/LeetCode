pub fn my_atoi_other(s: String) -> i32 {
    let mut read = s
        .trim()
        .chars()
        .take_while(|&x| x == '+' || x == '-' || x.is_ascii_digit())
        .peekable();

    let mut sign = 1;
    if let Some(&c) = read.peek().filter(|&&x| x == '-' || x == '+') {
        read.next();

        if c == '-' {
            sign = -1;
        }
    }

    read.take_while(|ch| ch.is_ascii_digit())
        .map(|ch| ch.to_digit(10).unwrap() as i32 * sign)
        .reduce(|total, digit| total.saturating_mul(10).saturating_add(digit))
        .unwrap_or(0)
}

use std::num::IntErrorKind;

pub fn my_atoi(s: String) -> i32 {
    let mut result = String::new();
    let mut start = false;

    for ch in s.trim().chars() {
        match ch {
            '+' | '-' if !start => result.push(ch),
            _ => {
                if !ch.is_numeric() {
                    break;
                } else {
                    result.push(ch);
                    start = true;
                }
            }
        }
    }

    match result.parse::<i32>() {
        Ok(res) => res,
        Err(msg) => match msg.kind() {
            IntErrorKind::NegOverflow => i32::MIN,
            IntErrorKind::PosOverflow => i32::MAX,
            _ => 0,
        },
    }
}

pub fn my_atoi_smaller(s: String) -> i32 {
    let s = s.trim();

    let (s, sign) = match s.strip_prefix('-') {
        Some(s) => (s, -1),
        None => (s.strip_prefix('+').unwrap_or(s), 1),
    };

    s.chars()
        .take_while(|x| x.is_ascii_digit())
        .map(|x| x.to_digit(10).unwrap() as i32 * sign)
        .reduce(|acc, curr| acc.saturating_mul(10).saturating_add(curr))
        .unwrap_or(0)
}
fn main() {}
