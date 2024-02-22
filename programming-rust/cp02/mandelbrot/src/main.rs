use std::str::FromStr;
use num::Complex;
use image::{ColorType, ImageEncoder};
use image::codecs::png::PngEncoder;
use std::fs::File;

fn main() {
    println!("Hello, world!");
    let args: Vec<String> = std::env::args().collect();

    if args.len() != 5 {
        eprintln!("Example: {} mandel.png 1000-750 -1.20,0.35 -1,0.20", args[0]);
        std::process::exit(1);
    }

    let bounds = parse_pair::<usize>(&args[2], '-').unwrap();
    let upper_left = parse_complex(&args[3]).unwrap();
    let lower_right = parse_complex(&args[4]).unwrap();

    let mut pixels = vec![0; bounds.0 * bounds.1];

    let threads = 8;
    let rows_per_band = bounds.1 / threads + 1;

    {
        let bands: Vec<&mut [u8]> = pixels.chunks_mut(rows_per_band * bounds.0).collect();
        crossbeam::scope(|spawner| {
            for (i, band) in bands.into_iter().enumerate() {
                let top = rows_per_band * i;
                let height = band.len() / bounds.0;
                let band_bounds = (bounds.0, height);
                let band_upper_left = pixel_to_point(bounds, (0, top), upper_left, lower_right);
                let band_lower_right = pixel_to_point(bounds, (bounds.0, top + height), upper_left, lower_right);

                spawner.spawn(move |_| {
                    render(band, band_bounds, band_upper_left, band_lower_right);
                });
            }
        }).unwrap();
    }

    // render(&mut pixels, bounds, upper_left, lower_right);
    write_image(&args[1], &pixels, bounds).unwrap();
}

fn escape_time(c: Complex<f64>, limit: usize) -> Option<usize> {
    let mut z = Complex::new(0.0, 0.0);
    for i in 0..limit {
        if z.norm_sqr() > 4.0 {
            return Some(i);
        }
        z = z * z + c;
    }

    None
}

fn parse_pair<T: FromStr>(input: &str, separator: char) -> Option<(T, T)> {
    // 字符串 find 方法，同 JavaScript indexOf 方法
    match input.find(separator) {
        None => None,
        Some(index) => {
            match (T::from_str(&input[..index]), T::from_str(&input[index + 1..])) {
                (Ok(left), Ok(right)) => Some((left, right)),
                _ => None,
            }
        }
    }
}

fn parse_complex(s: &str) -> Option<Complex<f64>> {
    match parse_pair(s, ',') {
        Some((re, im)) => Some(Complex::new(re, im)),
        None => None,
    }
}

fn pixel_to_point(bounds: (usize, usize), pixel: (usize, usize), upper_left: Complex<f64>, lower_right: Complex<f64>) -> Complex<f64> {
    let (width, height) = (lower_right.re - upper_left.re, upper_left.im - lower_right.im);
    let (x, y) = (pixel.0 as f64, pixel.1 as f64);
    let (x, y) = (x / (bounds.0 as f64), y / (bounds.1 as f64));
    let (x, y) = (x * width + upper_left.re, upper_left.im - y * height);
    Complex::new(x, y)
}

fn render(pixels: &mut [u8], bounds: (usize, usize), upper_left: Complex<f64>, lower_right: Complex<f64>) {
    assert!(pixels.len() == bounds.0 * bounds.1);

    for row in 0..bounds.1 {
        for column in 0..bounds.0 {
            let point = pixel_to_point(bounds, (column, row), upper_left, lower_right);

            pixels[row * bounds.0 + column] = match escape_time(point, 255) {
                None => 0,
                Some(time) => 255 - time as u8,
            }
        }
    }
}

fn write_image(filename: &str, pixels: &[u8], bounds: (usize, usize)) -> Result<(), std::io::Error> {
    let output = File::create(filename)?;

    let encoder = PngEncoder::new(output);

    encoder.write_image(&pixels, bounds.0 as u32, bounds.1 as u32, ColorType::L8).unwrap();

    Ok(())
}



#[test]
fn test_parse_pair() {
    assert_eq!(parse_pair::<i32>("", ','), None);
    assert_eq!(parse_pair::<i32>("10,", ','), None);
    assert_eq!(parse_pair::<i32>(",10", ','), None);
    assert_eq!(parse_pair::<i32>("10,20", ','), Some((10, 20)));
    assert_eq!(parse_pair::<i32>("10,20xy", ','), None);
    assert_eq!(parse_pair::<f32>("10.3,", ','), None);
    assert_eq!(parse_pair::<f32>(",10.3", ','), None);
    assert_eq!(parse_pair::<f32>("10.3,20.5", ','), Some((10.3, 20.5)));
}

#[test]
fn test_parse_complex() {
    assert_eq!(parse_complex(""), None);
    assert_eq!(parse_complex("10"), None);
    assert_eq!(parse_complex("10,"), None);
    assert_eq!(parse_complex(",10"), None);
    assert_eq!(parse_complex("10.0,20.0"), Some(Complex::new(10.0, 20.0)));
    assert_eq!(parse_complex("10,20xy"), None);
    assert_eq!(parse_complex("10.3,20.5"), Some(Complex::new(10.3, 20.5)));
}

#[test]
fn test_pixel_to_point() {
    assert_eq!(pixel_to_point((100, 200), (25, 175), Complex { re: -1.0, im: 1.0 }, Complex { re: 1.0, im: -1.0 }), Complex { re: -0.5, im: -0.75 });
}
