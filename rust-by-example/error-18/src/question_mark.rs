#[derive(Clone, Copy)]
struct Person {
    job: Option<Job>,
}

#[derive(Clone, Copy)]
struct Job {
    phone_number: Option<PhoneNumber>,
}

#[derive(Clone, Copy)]
struct PhoneNumber {
    area: Option<u8>,
    _number: u8,
}

impl Person {
    fn get_job_phone_number_area(&self) -> Option<u8> {
        self.job?.phone_number?.area
    }
}

pub fn main_exec() {
    let me = Person {
        job: Some(Job {
            phone_number: Some(PhoneNumber {
                area: Some(1),
                _number: 2,
            }),
        }),
    };

    let phone_number_area = me.get_job_phone_number_area();

    assert_eq!(phone_number_area, Some(1));
}