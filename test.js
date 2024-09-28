const vertexShaderSource = `
    #version 330 core
    layout (location = 0) in vec3 aPos;

    void main() {
        gl_Position = vec4(aPos, 1.0);
    }
`;

const fragmentShaderSource = `
    #version 330 core
    out vec4 FragColor;

    void main() {
        FragColor = vec4(1.0, 0.5, 0.2, 1.0);
    }
`;

const vertices = new Float32Array([
    -0.5, -0.5, 0.0,
    0.5, -0.5, 0.0, 
    0.0, 0.5, 0.0 
]);

const isCreate = glfwInit(); 
if (!isCreate) {
    console.log('init glfw fail'); 
}


glfwWindowHint(); 
let window = glfwCreateWindow(800, 600, 'longdeptrai'); 
if (!window.create) {
    console.log('create window fail'); 
}
glfwMakeContextCurrent(window);

//loop 
if (!glewInit()) {
    console.log('Failed to init glew');
}

const VAO = glGenVertexArrays(1); 
glBindVertexArray(VAO);
console.log(VAO); 
const VBO = glGenBuffers(1); 
console.log(GL_ARRAY_BUFFER); 
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, vertices);
glVertexAttribPointer(0); 
glEnableVertexAttribArray(0); 


const vertexShader = glCreateShader(GL_VERTEX_SHADER); 
glShaderSource(vertexShader, vertexShaderSource); 
glCompileShader(vertexShader);

const fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, fragmentShaderSource);
glCompileShader(fragmentShader);


const shaderProgram = glCreateProgram();
glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);

glLinkProgram(shaderProgram);

glDeleteShader(vertexShader);
glDeleteShader(fragmentShader);

while (!glfwWindowShouldClose(window))
{
    glfwPollEvents();
    glClearColor(0.2, 0.3, 0.3, 1.0);
    glClear(); 
    glUseProgram(shaderProgram);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3); 
    glfwSwapBuffers(window);
}

glDeleteVertexArrays(VAO);
glDeleteBuffers(VBO);
glDeleteProgram(shaderProgram);
glfwDestroyWindow(window);
glfwTerminate();