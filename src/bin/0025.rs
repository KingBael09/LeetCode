#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub fn reverse_k_group(mut head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
    let mut current = &head;

    let mut stack = Vec::with_capacity(k as usize);

    let mut vals: Vec<i32> = Vec::new();

    while let Some(ref node) = current {
        // stack.insert(0, node.val);
        stack.push(node.val);

        if stack.len() == k as usize {
            // vals.extend(stack.iter());
            vals.extend(stack.iter().rev());
            stack.clear();
        }

        current = &node.next;
    }

    let mut current = &mut head;

    for val in vals {
        if let Some(ref mut node) = current {
            node.val = val;
            current = &mut node.next;
        }
    }

    head
}

fn main() {}
