const isCreate = glfwInit(); 
if (!isCreate) {
    console.log('init glfw fail'); 
}


glfwWindowHint(); 
let window = glfwCreateWindow(800, 600, 'GLFW Window'); 
if (!window.create) {
    console.log('create window fail'); 
}
glfwMakeContextCurrent(window);

//loop 
while (!glfwWindowShouldClose(window))
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}


glfwDestroyWindow(window);
glfwTerminate();
console.log("t"); 
console.log(JSON.stringify(window)); 