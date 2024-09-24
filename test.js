let delay = 1000; 
let interval = 1000; 
setTimeout(delay, interval, () => {
    print('long dep trai' + new Date().toISOString()); 
    setTimeout(delay, interval, () => {
        print('long dep trai 2' + new Date().toISOString()); 
        setTimeout(delay, interval, () => {
            print('long dep trai 3' + new Date().toISOString());
        }); 
    }); 
}); 