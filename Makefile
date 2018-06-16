# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/13 17:49:50 by asiaux       #+#   ##    ##    #+#        #
#    Updated: 2018/06/03 21:25:12 by asiaux      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY = all clean fclean re

# **************************************************************************** #
#																			   #																		   #
#									DIRECTORIES		    					   #
#																			   #																			 #
# **************************************************************************** #

SRCDIR = ./src/
SRCDIRLIBFT = $(SRCDIR)libft/
SRCDIRPRINTF = $(SRCDIR)ft_printf/
SRCALL = $(SRCDIRPRINTF) $(SRCDIRLIBFT)

OBJDIR = ./obj/
OBJDIRLIBFT = $(OBJDIR)libft/
OBJDIRPRINTF = $(OBJDIR)printf/
OBJALL = $(OBJDIR) $(OBJDIRLIBFT) $(OBJDIRPRINTF)

HEADERDIR = ./includes/

# **************************************************************************** #
#																			   #
#		           			    	FILES		    						   #
#																			   #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
HEADERS = $(addprefix $(HEADERDIR), ft_printf.h libft.h)

FILESPRINTF = 	ft_parse ft_printf ft_processing_infos ft_tools p_int\
				ft_process_char ft_process_string p_int2str parser_tools
				
SRCPRINTF = $(addprefix $(SRCDIRPRINTF), $(addsuffix .c, $(FILESPRINTF)))
OBJPRINTF = $(addprefix $(OBJDIRPRINTF), $(addsuffix .o, $(FILESPRINTF)))

FILESLIBFT = ft_atoi ft_lstadd ft_memccpy ft_putchar ft_putstr ft_strcpy\
			ft_strlen ft_strnew ft_swap ft_bzero ft_lstdel ft_memchr\
			ft_putchar_fd ft_putstr_fd ft_strdel ft_strmap ft_strnstr\
			ft_tolower ft_isalnum ft_lstdel_content ft_memcmp ft_putendl\
			ft_realloc ft_strdup ft_strmapi ft_strrchr ft_toupper ft_isalpha\
			ft_lstdelone ft_memcpy ft_putendl_fd ft_sqrt ft_strequ ft_strmod\
			ft_strrev ft_isascii ft_lstiter ft_memdel ft_putnbr ft_strcat\
			ft_striter ft_strncat ft_strsplit ft_isdigit ft_lstmap ft_memmove\
			ft_putnbr_fd ft_strchr ft_striteri ft_strncmp ft_strstr ft_isprint\
			ft_lstnew ft_memset ft_putnstr ft_strclr ft_strjoin ft_strncpy\
			ft_strsub ft_itoa ft_memalloc ft_pow ft_putnstr_fd ft_strcmp\
			ft_strlcat ft_strnequ ft_strtrim ft_itoa_base ft_strjoin_free\
			ft_wcharlen ft_wstrlen ft_str_tolower ft_isspace

SRCLIBFT = $(addprefix $(SRCDIRLIBFT), $(addsuffix .c, $(FILESLIBFT)))
OBJLIBFT = $(addprefix $(OBJDIRLIBFT), $(addsuffix .o, $(FILESLIBFT)))

SRCS = $(SRCPRINTF) $(SRCLIBFT)
OBJS = $(OBJLIBFT) $(OBJPRINTF)

# **************************************************************************** #
#																			   #
#									COMMANDS								   #
#																			   #
# **************************************************************************** #

all : $(NAME)

$(NAME): $(OBJALL) $(OBJS)
#	@printf "Compiling $(NAME)..."
	@ar rcs $(NAME) $(OBJS)
#	@printf "\033[32m[OK]\033[0m\n"

$(OBJALL):
	@mkdir $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
#	@printf "%b" "Compiling $< in $@..."
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADERDIR)
#	@printf "\033[32m[OK]\033[0m\n"

test:
	@gcc main.c libftprintf.a
	@./a.out

clean:
			@rm -rf $(OBJDIR)

fclean: clean
			@rm -f $(NAME)

re: fclean all
