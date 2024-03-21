use std::rc::Rc;

pub fn main_exec() {
    let name = "Jocs".to_string();

    {
        let name_rc = Rc::new(name);
        println!("name_rc is {:?}, and its RC count is {}", name_rc, Rc::strong_count(&name_rc));

        {
            let name_rc_clone = Rc::clone(&name_rc);
            println!("name_rc_clone is {:?}, and its RC count is {}", name_rc_clone, Rc::strong_count(&name_rc_clone));
            println!("name_rc is {:?}, and its RC count is {}", name_rc, Rc::strong_count(&name_rc));
        }

        println!("name_rc is {:?}, and its RC count is {}", name_rc, Rc::strong_count(&name_rc));
    }
}