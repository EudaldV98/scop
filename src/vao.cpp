/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vao.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:17 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/30 18:08:08 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vao.hpp"

VAO::VAO()
{
}

void	VAO::construct()
{
	glGenVertexArrays(1, &this->id);
}

void	VAO::linkAttrib(VBO vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset)
{
	vbo.bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vbo.unbind();
}

void	VAO::bind()
{
	glBindVertexArray(this->id);
}

void	VAO::unbind()
{
	glBindVertexArray(0);
}

void	VAO::delete_()
{
	glDeleteVertexArrays(1, &this->id);
}