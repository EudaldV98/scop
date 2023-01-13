/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vao.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:17 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/13 10:59:26 by jvaquer          ###   ########.fr       */
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

void	VAO::linkVBO(VBO vbo, GLuint layout)
{
	vbo.bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);
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