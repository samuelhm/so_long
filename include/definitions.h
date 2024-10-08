/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:14:24 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/23 16:35:33 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

// Game Grid Size
# ifndef GAME_W
#  define GAME_W 32
# endif
# ifndef GAME_H
#  define GAME_H 32
# endif

// Keys (from keysym X11)
# ifndef KEY_ESC
#  define KEY_ESC 0xff1b
# endif
# ifndef KEY_LEFT
#  define KEY_LEFT 0x61
# endif
# ifndef KEY_RIGHT
#  define KEY_RIGHT 0x64
# endif
# ifndef KEY_UP
#  define KEY_UP 0x77
# endif
# ifndef KEY_DOWN
#  define KEY_DOWN 0x73
# endif

// Error Messages
# define ERR_PATH "ERROR\n Error inesperado de memoria (path).\n"
# define ERR_FILE "ERROR\nCannot Open Mapfile, Please check.\n"
# define ERR_MAP2 "ERROR\nMap is not valid\n"
# define ERR_MAP "ERROR\nIntroduce un solo argumento \"mapname\"\n"
# define ERR_INIT "ERROR\nFallo de inicialización!\n"
# define ERR_EXT "ERROR\nEl archivo no tiene la extensión correcta!\n"

//Utils
# define CLR_LN "\033[2K\r"
#endif
