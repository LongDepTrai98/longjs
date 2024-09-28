#include <iostream>
#include <fs/fs.hpp>
#include <engine/app.hpp>
using namespace longjs; 
int main()
{
	app main_app; 
	std::string path = "test.js"; 
	if (!main_app.initialize())
	{
		std::cout << "Can't init platform\n"; 
		return -1; 
	}
	if (!main_app.initializeIsolate())
	{
		std::cout << "Can't init isolate\n"; 
		return -1; 
	}
	main_app.initializeApp(path, 
		js_type::MODULE); 
	main_app.shutdown(); 
	return 0; 
}
//#include <gl/glew.h>
//#include <gl/wglew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
// Vertex Shader source code
//const char* vertexShaderSource = R"(
//    #version 330 core
//    layout (location = 0) in vec3 aPos;
//
//    void main() {
//        gl_Position = vec4(aPos, 1.0);
//    }
//)";
//
// Fragment Shader source code
//const char* fragmentShaderSource = R"(
//    #version 330 core
//    out vec4 FragColor;
//
//    void main() {
//        FragColor = vec4(1.0, 0.5, 0.2, 1.0); // Màu cam
//    }
//)";
//
//int main() {
//     Khởi tạo GLFW
//    if (!glfwInit()) {
//        std::cerr << "Failed to initialize GLFW" << std::endl;
//        return -1;
//    }
//
//     Thiết lập phiên bản OpenGL, ở đây là 3.3
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//     Tạo cửa sổ GLFW
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Basic Triangle with GLEW", nullptr, nullptr);
//    if (!window) {
//        std::cerr << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//     Khởi tạo GLEW
//    glewExperimental = GL_TRUE; // Đảm bảo GLEW sử dụng các extension hiện đại
//    if (glewInit() != GLEW_OK) {
//        std::cerr << "Failed to initialize GLEW" << std::endl;
//        return -1;
//    }
//
//     Thiết lập viewport
//    glViewport(0, 0, 800, 600);
//
//     Vertex data cho tam giác
//    float vertices[] = {
//        -0.5f, -0.5f, 0.0f,  // Đỉnh dưới trái
//         0.5f, -0.5f, 0.0f,  // Đỉnh dưới phải
//         0.0f,  0.5f, 0.0f   // Đỉnh trên
//    };
//
//     Tạo và bind Vertex Array Object (VAO)
//    unsigned int VAO;
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//
//     Tạo Vertex Buffer Object (VBO)
//    unsigned int VBO;
//    glGenBuffers(1, &VBO);
//
//     Bind VBO và copy dữ liệu vertex vào buffer
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//     Cấu hình các attribute cho vertex (vị trí)
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//     Tạo và biên dịch Vertex Shader
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
//    glCompileShader(vertexShader);
//
//     Kiểm tra lỗi biên dịch Vertex Shader
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success) {
//        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
//        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//     Tạo và biên dịch Fragment Shader
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
//    glCompileShader(fragmentShader);
//
//     Kiểm tra lỗi biên dịch Fragment Shader
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success) {
//        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
//        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//     Liên kết các shader thành một shader program
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//     Kiểm tra lỗi liên kết shader program
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
//        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//
//     Xóa shader sau khi đã liên kết
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//     Vòng lặp chính
//    while (!glfwWindowShouldClose(window)) {
//         Xử lý các sự kiện
//        glfwPollEvents();
//
//         Xóa màn hình và tô màu nền
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//         Sử dụng shader program
//        glUseProgram(shaderProgram);
//
//         Vẽ tam giác
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//         Swap buffers để hiển thị nội dung lên màn hình
//        glfwSwapBuffers(window);
//    }
//
//     Giải phóng tài nguyên
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//
//     Đóng và hủy cửa sổ
//    glfwTerminate();
//    return 0;
//}