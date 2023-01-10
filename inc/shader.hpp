/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:13:23 by jvaquer           #+#    #+#             */
/*   Updated: 2022/12/05 17:24:36 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
# define SHADER_HPP

# include "utils.hpp"

std::string get_file_contents(const char *filename);

class Shader
{
	public:
		unsigned int	id;

		Shader();
		void	construct(const char * vertexFile, const char * fragmentFile);
		void	activate_shader();
		void	delete_shader();
		~Shader();
};

#endif