#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}
//
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub fn add_two_numbers(
    l1: Option<Box<ListNode>>,
    l2: Option<Box<ListNode>>,
) -> Option<Box<ListNode>> {
    let mut head = Box::new(ListNode::new(0));
    let mut tail = &mut head;

    let (mut l1, mut l2) = (l1.as_ref(), l2.as_ref());

    let mut carry = 0;

    while l1.is_some() || l2.is_some() || carry == 1 {
        let mut sum = 0;

        if let Some(node) = l1 {
            sum += node.val;
            l1 = node.next.as_ref();
        }

        if let Some(node) = l2 {
            sum += node.val;
            l2 = node.next.as_ref();
        }

        sum += carry;

        tail.next = Some(Box::new(ListNode::new(sum % 10)));
        tail = tail.next.as_mut().unwrap();

        carry = sum / 10;
    }

    head.next
}

pub fn add_two_numbers_other(
    l1: Option<Box<ListNode>>,
    l2: Option<Box<ListNode>>,
) -> Option<Box<ListNode>> {
    let mut head = Box::new(ListNode::new(0));
    let mut tail = &mut head;

    let (mut l1, mut l2) = (&l1, &l2);

    let mut carry = 0;

    loop {
        if l1.is_none() && l2.is_none() && carry == 0 {
            break;
        }

        let mut sum = 0;

        if let Some(node) = l1 {
            sum += node.val;
            l1 = &node.next;
        }

        if let Some(node) = l2 {
            sum += node.val;
            l2 = &node.next;
        }

        sum += carry;

        tail.next = Some(Box::new(ListNode::new(sum % 10)));
        tail = tail.next.as_mut().unwrap();

        carry = sum / 10;
    }

    head.next
}

fn main() {}
