pub fn is_valid(s: String) -> bool {
    let mut st: Vec<char> = Vec::new();

    for ch in s.chars() {
        match ch {
            '{' | '(' | '[' => st.push(ch),
            _ => {
                let last = st.last().unwrap_or(&' ');

                if st.is_empty()
                    || (ch == '}' && last != &'{')
                    || (ch == ']' && last != &'[')
                    || (ch == ')' && last != &'(')
                {
                    return false;
                }

                st.pop();
            }
        }
    }

    st.is_empty()
}

pub fn is_valid_other(s: String) -> bool {
    let mut st = Vec::new();

    let cmp = move |(l, c)| (l, c) == ('(', ')') || (l, c) == ('{', '}') || (l, c) == ('[', ']');

    for c in s.chars() {
        match c {
            '{' | '(' | '[' => st.push(c),
            _ => match st.pop() {
                Some(l) if cmp((l, c)) => continue,
                _ => return false,
            },
        }
    }

    st.is_empty()
}

fn main() {}
