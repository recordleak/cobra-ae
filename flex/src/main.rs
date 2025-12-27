use std::ffi::{c_float, c_void};
use std::ptr::null_mut;
use libc::free;

#[repr(C)]


pub struct SIGNAL_ {
    pub ptr: *mut c_float,
    pub signal_size: usize,
    pub flag: bool
}

#[link(name = "cobra_ae", kind = "static")]
unsafe extern "C" {
    fn build_blank_wave_(signal: *mut SIGNAL_, sample_rate: c_float, t: c_float);
}

#[warn(unused_assignments)]
fn main() {
    unsafe {
        let mut signal = SIGNAL_ {
            ptr: null_mut(),
            signal_size: 0,
            flag: false
        };

        build_blank_wave_(&mut signal as *mut SIGNAL_, 44110.0, 2.0);

        if !signal.ptr.is_null() && signal.signal_size > 0 {
            unsafe {
                let first_var: c_float = *signal.ptr;
                println!("{}", first_var);
                println!("{}", signal.signal_size);
            }
        }

        if signal.ptr != null_mut() {
            free(signal.ptr as *mut c_void);
            signal.ptr = null_mut();
        }
    }
}

// Right now ima just testing how FFI in Rust works...