/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vao.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:50:39 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/30 17:46:02 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAO_HPP
# define VAO_HPP

# include "utils.hpp"
# include "vbo.hpp"

class VAO
{
    public:
        GLuint id;

        VAO();
        void    construct();
        void    linkAttrib(VBO vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset);
        void    bind();
        void    unbind();
        void    delete_();
};

#endif