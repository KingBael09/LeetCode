use std::collections::HashMap;

pub fn can_construct(ransom_note: String, magazine: String) -> bool {
    if magazine.len() < ransom_note.len() {
        return false;
    }

    let mut map = HashMap::new();

    for c in magazine.chars() {
        *map.entry(c).or_insert(0) += 1;
    }

    for c in ransom_note.chars() {
        let count = map.entry(c).or_insert(0);
        *count -= 1;

        if *count < 0 {
            return false;
        }
    }

    true
}
fn main() {}
