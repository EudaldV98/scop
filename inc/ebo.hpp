/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:02:36 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/13 10:55:22 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EBO_HPP
# define EBO_HPP

# include "utils.hpp"

class EBO
{
	public:
		GLuint	id;

		EBO();
		void	construct(GLuint *indices, GLsizeiptr size);
		void	bind();
		void	unbind();
		void	delete_();
};

#endif