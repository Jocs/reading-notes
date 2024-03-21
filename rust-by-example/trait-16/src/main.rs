mod dyn_example;
mod derive_example;
mod operator_overloading;
mod drop_example;
mod iterator_example;
mod impl_trait;
mod supertraits;

fn main() {
    derive_example::main_exec();
    dyn_example::main_exec();
    operator_overloading::main_exec();
    drop_example::main_exec();
    iterator_example::main_exec();
    impl_trait::main_exec();
    supertraits::main_exec();
}
