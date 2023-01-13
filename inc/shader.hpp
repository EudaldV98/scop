/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:13:23 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/13 14:00:22 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
# define SHADER_HPP

# include "utils.hpp"

std::string get_file_contents(const char *filename);

class Shader
{
	public:
		GLuint	id;
		unsigned int	vertexShader;
		unsigned int	fragmentShader;

		Shader();
		void	construct(const char * vertexFile, const char * fragmentFile);
		void	fragment_shader(const char *fragmentSource);
		void	vertex_shader(const char *vertexSource);
		void	link_shaders();
		void	activate_shader();
		void	delete_shader();
		~Shader();
};

#endif