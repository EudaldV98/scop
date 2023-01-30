/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:27:06 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/30 17:02:33 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_HPP
# define SCOP_HPP

# include "utils.hpp"
# include "shader.hpp"
# include "vbo.hpp"
# include "vao.hpp"
# include "ebo.hpp"

class Scop
{
	private:

		GLFWwindow*		window;
		Shader			shaderProgram;
		VBO VBO;
		VAO VAO;
		EBO EBO;
		// unsigned int	VBO, VAO, EBO;

	public:

		Scop(/* args */);
		void	render(std::vector<Vec3> vertices);
		void	initGlfw();
		void	createWindow();
		void	loadGlad();
		void	compileShaders();
		void	setVertexData(std::vector<Vec3> vertices);
		~Scop();
};

#endif