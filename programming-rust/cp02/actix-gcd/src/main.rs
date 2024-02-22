use actix_web::{web, App, HttpResponse, HttpServer};
use serde::Deserialize;

#[derive(Deserialize)]
struct GcdParameters {
    m: u64,
    n: u64,
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    let server = HttpServer::new(|| {
        App::new()
            .service(web::resource("/").to(get_index))
            .service(web::resource("/gcd").to(post_gcd))
    });

    println!("Serving on http://localhost:3000");
    server
        .bind("127.0.0.1:3000")?
        .run()
        .await
}

fn gcd(mut m: u64, mut n: u64) -> u64 {
    while m != 0 {
        if m < n {
            let t = n;
            n = m;
            m = t;
        }

        m = m % n;
    }

    n
}

async fn post_gcd(params: web::Form<GcdParameters>) -> HttpResponse {
    if params.m == 0 || params.n == 0 {
        return HttpResponse::BadRequest().content_type("text/html").body("m and n must be non-zero");
    }

    let response = format!("The GCD of {} and {} is {}", params.m, params.n, gcd(params.m, params.n));

    HttpResponse::Ok().content_type("text/html").body(response)
}

async fn get_index() -> HttpResponse {
    HttpResponse::Ok().content_type("text/html").body(
        r#"
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Document</title>
        </head>
        <body>
            <form action="/gcd" method="post">
                <input type="text" name="n">
                <input type="text" name="m">
                <button type="submit">Compute GCD</button>
            </form>
        </body>
        </html>
        "#,
    )
}
