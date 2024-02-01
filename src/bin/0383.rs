use std::collections::HashMap;

pub fn can_construct(ransom_note: String, magazine: String) -> bool {
    let mut map = HashMap::new();

    magazine.chars().for_each(|ch| {
        map.entry(ch).and_modify(|ct| *ct += 1).or_insert(1);
    });

    ransom_note
        .chars()
        .all(|ch| map.entry(ch).and_modify(|ct| *ct -= 1).or_insert(-1) >= &mut 0)
}
fn main() {}
