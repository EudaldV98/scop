/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:35:43 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/30 17:14:03 by jvaquer          ###   ########.fr       */
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
		void construct(std::vector<Vec3> *vertices, GLsizeiptr size);
		void bind();
		void unbind();
		void delete_();
};

#endif