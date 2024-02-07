pub fn cal_points(operations: Vec<String>) -> i32 {
    operations
        .into_iter()
        .fold(vec![], |mut st, str| {
            match str.as_str() {
                "C" => st.truncate(st.len() - 1),
                "D" => st.push(st.last().take().unwrap() * 2),
                "+" => st.push(st.iter().rev().take(2).sum()),
                s => st.push(s.parse().unwrap()),
            };
            st
        })
        .into_iter()
        .sum()

    // let mut res = Vec::new();

    // operations.into_iter().for_each(|str| match str.as_str() {
    //     "C" => res.truncate(res.len() - 1),
    //     "D" => res.push(res.last().take().unwrap() * 2),
    //     "+" => res.push(res.iter().rev().take(2).sum()),
    //     s => res.push(s.parse().unwrap()),
    // });

    // res.into_iter().sum()
}

fn main() {}
