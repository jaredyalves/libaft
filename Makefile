NAME			:=	libaft.a

SRCDIR			:=	src
OBJDIR			:=	obj
LIBDIR			:=	lib
INCDIR			:=	include

SRCS			:=
SRCS			+=	$(SRCDIR)/ft_atoi.c
SRCS			+=	$(SRCDIR)/ft_atol.c
SRCS			+=	$(SRCDIR)/ft_atoll.c
SRCS			+=	$(SRCDIR)/ft_bzero.c
SRCS			+=	$(SRCDIR)/ft_calloc.c
SRCS			+=	$(SRCDIR)/ft_dprintf.c
SRCS			+=	$(SRCDIR)/ft_isalnum.c
SRCS			+=	$(SRCDIR)/ft_isalpha.c
SRCS			+=	$(SRCDIR)/ft_isascii.c
SRCS			+=	$(SRCDIR)/ft_isblank.c
SRCS			+=	$(SRCDIR)/ft_iscntrl.c
SRCS			+=	$(SRCDIR)/ft_isdigit.c
SRCS			+=	$(SRCDIR)/ft_isgraph.c
SRCS			+=	$(SRCDIR)/ft_islower.c
SRCS			+=	$(SRCDIR)/ft_isprint.c
SRCS			+=	$(SRCDIR)/ft_ispunct.c
SRCS			+=	$(SRCDIR)/ft_isspace.c
SRCS			+=	$(SRCDIR)/ft_isupper.c
SRCS			+=	$(SRCDIR)/ft_isxdigit.c
SRCS			+=	$(SRCDIR)/ft_itoa.c
SRCS			+=	$(SRCDIR)/ft_lstadd_back.c
SRCS			+=	$(SRCDIR)/ft_lstadd_front.c
SRCS			+=	$(SRCDIR)/ft_lstclear.c
SRCS			+=	$(SRCDIR)/ft_lstdelone.c
SRCS			+=	$(SRCDIR)/ft_lstiter.c
SRCS			+=	$(SRCDIR)/ft_lstlast.c
SRCS			+=	$(SRCDIR)/ft_lstmap.c
SRCS			+=	$(SRCDIR)/ft_lstnew.c
SRCS			+=	$(SRCDIR)/ft_lstsize.c
SRCS			+=	$(SRCDIR)/ft_memchr.c
SRCS			+=	$(SRCDIR)/ft_memcmp.c
SRCS			+=	$(SRCDIR)/ft_memcpy.c
SRCS			+=	$(SRCDIR)/ft_memmove.c
SRCS			+=	$(SRCDIR)/ft_memset.c
SRCS			+=	$(SRCDIR)/ft_printf.c
SRCS			+=	$(SRCDIR)/ft_putchar.c
SRCS			+=	$(SRCDIR)/ft_putchar_fd.c
SRCS			+=	$(SRCDIR)/ft_putendl.c
SRCS			+=	$(SRCDIR)/ft_putendl_fd.c
SRCS			+=	$(SRCDIR)/ft_putnbr.c
SRCS			+=	$(SRCDIR)/ft_putnbr_fd.c
SRCS			+=	$(SRCDIR)/ft_putstr.c
SRCS			+=	$(SRCDIR)/ft_putstr_fd.c
SRCS			+=	$(SRCDIR)/ft_split.c
SRCS			+=	$(SRCDIR)/ft_strchr.c
SRCS			+=	$(SRCDIR)/ft_strdup.c
SRCS			+=	$(SRCDIR)/ft_striteri.c
SRCS			+=	$(SRCDIR)/ft_strjoin.c
SRCS			+=	$(SRCDIR)/ft_strlcat.c
SRCS			+=	$(SRCDIR)/ft_strlcpy.c
SRCS			+=	$(SRCDIR)/ft_strlen.c
SRCS			+=	$(SRCDIR)/ft_strmapi.c
SRCS			+=	$(SRCDIR)/ft_strncmp.c
SRCS			+=	$(SRCDIR)/ft_strnstr.c
SRCS			+=	$(SRCDIR)/ft_strrchr.c
SRCS			+=	$(SRCDIR)/ft_strtrim.c
SRCS			+=	$(SRCDIR)/ft_substr.c
SRCS			+=	$(SRCDIR)/ft_tolower.c
SRCS			+=	$(SRCDIR)/ft_toupper.c
SRCS			+=	$(SRCDIR)/ft_vdprintf.c
OBJS			:=	$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
INCS			:=	$(INCDIR)/libaft.h

CC				:=	/bin/cc
INCLUDES		:=	-I$(INCDIR)
CFLAGS			:=	-O3 -Wall -Werror -Wextra $(INCLUDES)
LDFLAGS			:=

AR				:=	/bin/ar
ARFLAGS			:=	-rcs

RM				:=	/bin/rm
RMFLAGS			:=	-rf

COLOR_RESET		:=	\033[0m
COLOR_CLEAN		:=	\033[0;33m
COLOR_COMPILE	:=	\033[0;32m
COLOR_LINK		:=	\033[0;34m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(COLOR_LINK)Creating archive $@...$(COLOR_RESET)\n"
	@$(AR) $(ARFLAGS) $@ $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS) $(INCS_BONUS)
	@mkdir -p $(dir $@)
	@printf "$(COLOR_COMPILE)Compiling $<...$(COLOR_RESET)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@printf "$(COLOR_CLEAN)Cleaning up...$(COLOR_RESET)\n"
	@$(RM) $(RMFLAGS) $(OBJDIR)

fclean:: clean
	@printf "$(COLOR_CLEAN)Removing $(NAME)...$(COLOR_RESET)\n"
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all
