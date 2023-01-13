/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:35:43 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/13 10:50:16 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VBO_HPP
# define VBO_HPP

# include "utils.hpp"

class VBO
{
	public:
		GLuint id;
		
		VBO();
		void construct(GLfloat *vertices, GLsizeiptr size);
		void bind();
		void unbind();
		void delete_();
};

#endif