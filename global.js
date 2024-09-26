//Global function 
const setTimeout = (cb, ms) => lj_timer(ms, 0, cb);
const setInterval = (cb, ms) => lj_timer(0, ms, cb); 
class Console {
    log(...args) {
        print(...args);
    }
}

var console = new Console(); 

