const UNITS: [(&str, i32); 13] = [
    ("M", 1000),
    ("CM", 900),
    ("D", 500),
    ("CD", 400),
    ("C", 100),
    ("XC", 90),
    ("L", 50),
    ("XL", 40),
    ("X", 10),
    ("IX", 9),
    ("V", 5),
    ("IV", 4),
    ("I", 1),
];

pub fn int_to_roman(mut num: i32) -> String {
    UNITS
        .iter()
        .map(|(unit, val)| {
            let qty = num / val;
            num -= qty * val;
            unit.repeat(qty as usize)
        })
        .collect()
}

pub fn int_to_roman_other(mut num: i32) -> String {
    let mut result = String::new();

    for (s, val) in UNITS.iter() {
        while num >= *val {
            num -= val;
            result += s
        }
    }

    result
}

fn main() {}
