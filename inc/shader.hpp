/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:13:23 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/10 13:38:31 by jvaquer          ###   ########.fr       */
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

		Shader();
		void	construct(const char * vertexFile, const char * fragmentFile);
		void	activate_shader();
		void	delete_shader();
		~Shader();
};

#endif