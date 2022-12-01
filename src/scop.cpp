/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:28:35 by jvaquer           #+#    #+#             */
/*   Updated: 2022/12/01 10:45:20 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.hpp"

// glfw: initialize and configure
// ------------------------------
void	Scop::initGlfw()
{
	if (! glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		exit(1);
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // We don't want the old OpenGL

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	#endif
}

// glfw window creation
// --------------------
void	Scop::createWindow()
{
	this->window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Scop", NULL, NULL);
	if (this->window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(window); // Initialize GLEW
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

// glad: load all OpenGL function pointers
// ---------------------------------------
void	Scop::loadGlad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(1);
	}
}

// build and compile our shader program
// ------------------------------------
void	Scop::compileShaders()
{
	// vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

// set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------
void	Scop::setVertexData()
{
	float vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,	// left  
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,		// right 
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,		// top
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
		0.0f, -0.5 * float(sqrt(3)) / 3, 0.0f
	}; 

	unsigned int indices[] = {
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	for (int i = 0; i < sizeof(vertices) / sizeof(float); i++)
	{
		std::cout << vertices[i] << " ";
		if ((i + 1) % 3 == 0 && i != 0)
			std::cout << std::endl;
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// uncomment this call to draw in wireframe polygons.
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

Scop::Scop(/* args */)
{
	//settings
	this->vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";
	
	this->fragmentShaderSource = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 1.0f, 0.2f, 1.0f);\n"
			"}\n\0";

	this->initGlfw();
	this->createWindow();
	this->loadGlad();
	this->compileShaders();
	this->setVertexData();
}

// render loop
// -----------
void	Scop::render()
{
	while (!glfwWindowShouldClose(this->window))
	{
		// input
		// -----
		processInput(this->window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw our first triangle
		glUseProgram(this->shaderProgram);
		glBindVertexArray(this->VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		// glDrawArrays(GL_TRIANGLES, 0, 9);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// glBindVertexArray(0); // no need to unbind it every time 
 
		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

Scop::~Scop()
{
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &this->VAO);
	glDeleteBuffers(1, &this->VBO);
	glDeleteBuffers(1, &this->EBO);
	glDeleteProgram(this->shaderProgram);

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
}