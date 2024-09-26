// myPromiseFunction.js
function myAsyncFunction() {
    return new Promise((resolve) => {
        setTimeout(() => {
            let obj = new Object(); 
            obj['dragon'] = 'dragon'; 
        // Simulate some asynchronous task
            const success = true;  // Change this to `false` to simulate a failure
            resolve(obj);
      },100); // Simulate a 2-second delay
    });
  }
  
  // Export the function
export {myAsyncFunction }