use std::collections::HashMap;

#[derive(PartialEq, Eq, Hash, Debug, Clone, Copy)]
struct Account<'a> {
    username: &'a str,
    password: &'a str,
}

struct AccountInfo<'a> {
    name: &'a str,
    email: &'a str,
}

type Accounts<'a> = HashMap<Account<'a>, AccountInfo<'a>>;

fn login <'a>(accounts: &Accounts<'a>, username: &'a str, password: &'a str) {
    let logon_account = Account { username, password };

    if let Some(account_info) = accounts.get(&logon_account) {
        println!("Welcome, {}, {}!", account_info.name, account_info.email);
    } else {
        println!("Invalid username or password!");
    }
}

pub fn main_exec() {
    let mut accounts: Accounts = HashMap::new();

    accounts.insert(
        Account { username: "jane", password: "1234" },
        AccountInfo { name: "JANE", email: "<EMAIL>" },
    );

    login(&accounts, "jane", "4321");
    login(&accounts, "jane", "1234");
}