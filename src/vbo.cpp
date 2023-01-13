/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:40:19 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/13 10:59:38 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vbo.hpp"

VBO::VBO()
{
}

void	VBO::construct(GLfloat *vertices, GLsizeiptr size)
{
	glGenBuffers(1, &this->id);

	glBindBuffer(GL_ARRAY_BUFFER, this->id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void    VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, this->id);
}

void    VBO::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void    VBO::delete_()
{
	glDeleteBuffers(1, &this->id);
}