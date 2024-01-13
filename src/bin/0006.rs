pub fn convert(s: String, num_rows: i32) -> String {
    if num_rows < 2 {
        return s;
    }

    let mut floors = vec![String::new(); num_rows as usize];

    let mut current = 0;
    let mut is_edge = true;

    for ch in s.chars() {
        floors[current as usize].push(ch);

        current += if is_edge { 1 } else { -1 };

        is_edge = is_edge == (current > 0 && current < num_rows - 1);

        // if current == 0 || current == num_rows - 1 {
        //     is_edge = !is_edge
        // }
    }

    floors.concat()
}

pub fn convert_other(s: String, num_rows: i32) -> String {
    // consider num_rows = 3
    let mut zigzag: Vec<_> = (0..num_rows) // 0, 1, 2
        .chain((1..num_rows - 1).rev()) // 0, 1, 2, 1
        .cycle() // infinitely goes throuh the pattern
        .zip(s.chars()) // paris the pattern with chars of string
        .collect(); // we key (itr,char)

    /*
        (0, p), (1, a), (2, y), (1, p), (0, a), (1, l), (2, i), (1,s), (0, h), (1, i), (2, r), (1, i), (0, n), (1, g)

        Then sorting them with row number

        (0, p), (0, a), (0, h), (0, n), (1, a), (1, p), (1, l), (1,s),  (1, i), (1, i), (1, g), (2, y), (2, i), (2, r),

        THen only take characters

        pahnaplsiigyir

    */

    zigzag.sort_by_key(|&(row, _)| row);

    zigzag.into_iter().map(|(_, c)| c).collect()
}

fn main() {}
