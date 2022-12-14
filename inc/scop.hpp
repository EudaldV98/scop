/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:27:06 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/10 13:25:55 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_HPP
# define SCOP_HPP

# include "utils.hpp"
# include "shader.hpp"

class Scop
{
	private:

		GLFWwindow*		window;
		Shader			shaderProgram;
		unsigned int	VBO, VAO, EBO;
	
		const	char	*vertexShaderSource;
		const	char	*fragmentShaderSource;

	public:

		Scop(/* args */);
		void	render();
		void	initGlfw();
		void	createWindow();
		void	loadGlad();
		void	compileShaders();
		void	setVertexData();
		~Scop();
};

#endif