#include "../../minishell.h"

int	whitespacee(char c)
{
	if (c == ' ')
		return (1);
	else if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	special_char(char c)
{
	if (c == '|' || c == '>')
		return (1);
	else if (c == '<' || c == '\'' || c == '\"')
		return (1);
	return (0);
}

void	skip_spaces(const char *str, int *i)
{
	while (str[*i] && whitespacee(str[*i]))
		(*i)++;
}

void	parse_string(t_lexer **lexer, const char *str)
{
	int		i;
	t_lexer	*new;

	i = 0;
	while (i < (int)ft_strlen(str))
		process_string(lexer, str, &i);
	new = create_new_lexer_node(NULL, TOKEN_EOF, -1, -1);
	lexer_add_back(lexer, new);
	add_index_token(lexer);
}

