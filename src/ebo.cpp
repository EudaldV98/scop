/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:11:56 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/13 11:02:22 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ebo.hpp"

EBO::EBO()
{
}

void	EBO::construct(GLuint *indices, GLsizeiptr size)
{
	glGenBuffers(1, &this->id);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void	EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
}

void	EBO::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void	EBO::delete_()
{
	glDeleteBuffers(1, &this->id);
}