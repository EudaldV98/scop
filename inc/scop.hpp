/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:27:06 by jvaquer           #+#    #+#             */
/*   Updated: 2022/11/17 21:29:24 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_HPP
# define SCOP_HPP

# include "utils.hpp"

class Scop
{
	private:

		GLFWwindow* window;
		unsigned int shaderProgram;
		unsigned int VBO, VAO;
	
		const	char *vertexShaderSource;
		const	char *fragmentShaderSource;

	public:

		Scop(/* args */);
		void	render();
		~Scop();
};

#endif