/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:28:35 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/30 18:20:26 by jvaquer          ###   ########.fr       */
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

// set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------
void	Scop::setVertexData(std::vector<Vec3> obj_vertices)
{
	float vertices[] = {
		-0.5f,	-0.5f * float(sqrt(3)) / 3,		0.0f, 0.8f, 0.3f, 0.02f,	// lower left  
		 0.5f,	-0.5f * float(sqrt(3)) / 3,		0.0f, 0.8f, 0.3f, 0.02f,	// lower right 
		 0.0f,	 0.5f * float(sqrt(3)) * 2 / 3,	0.0f, 1.0f, 0.6f, 0.32f,	// upper
		-0.25f,	 0.5f * float(sqrt(3)) / 6,		0.0f, 0.9f, 0.45f, 0.17f,	// inner left
		 0.25f,	 0.5f * float(sqrt(3)) / 6,		0.0f, 0.9f, 0.45f, 0.17f,	// inner right
		 0.0f,	-0.5f * float(sqrt(3)) / 3,		0.0f, 0.8f, 0.3f, 0.02f		// inner down
	};

	unsigned int indices[] = {
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	// for (int i = 0; i < sizeof(vertices) / sizeof(float); i++)
	// {
	// 	std::cout << vertices[i] << " ";
	// 	if ((i + 1) % 3 == 0 && i != 0)
	// 		std::cout << std::endl;
	// }

	// glGenVertexArrays(1, &VAO);
	this->VAO.construct();
	// glGenBuffers(1, &VBO);
	// glGenBuffers(1, &EBO);
	
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	// glBindVertexArray(VAO);
	this->VAO.bind();
	
	// glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// this->VBO.construct(&obj_vertices, sizeof(obj_vertices));
	this->VBO.construct(vertices, sizeof(vertices));

	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	this->EBO.construct(indices, sizeof(indices));

	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// glEnableVertexAttribArray(0);
	this->VAO.linkAttrib(this->VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	this->VAO.linkAttrib(this->VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	// glBindBuffer(GL_ARRAY_BUFFER, 0);
	this->VBO.unbind();

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	// glBindVertexArray(0);
	this->VAO.unbind();

	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	this->EBO.unbind();

	// uncomment this call to draw in wireframe polygons.
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
}

Scop::Scop(/* args */)
{
	//settings

	this->initGlfw();
	this->createWindow();
	this->loadGlad();
	this->shaderProgram.construct("../dependencies/shaders/default.vert", "../dependencies/shaders/default.frag");
}

// render loop
// -----------
void	Scop::render(std::vector<Vec3> obj_vertices)
{
	this->setVertexData(obj_vertices);
	GLuint uniID = glGetUniformLocation(shaderProgram.id, "scale");
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
		// glUseProgram(this->shaderProgram);
		this->shaderProgram.activate_shader();
		
		glUniform1f(uniID, 0.5f);
		
		glBindVertexArray(this->VAO.id); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		
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
	// glDeleteVertexArrays(1, &this->VAO);
	this->VAO.delete_();
	
	// glDeleteBuffers(1, &this->VBO);
	this->VBO.delete_();
	
	// glDeleteBuffers(1, &this->EBO);
	this->EBO.delete_();
	
	// glDeleteProgram(this->shaderProgram);
	this->shaderProgram.delete_shader();

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
}