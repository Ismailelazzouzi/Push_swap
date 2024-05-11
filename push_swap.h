/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:46:55 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:46:58 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack_needs
{
	int						value;
	int						pos;
	int						push_cost;
	bool					up_down;
	bool					priority;
	struct s_stack_needs	*target;
	struct s_stack_needs	*next;
	struct s_stack_needs	*prev;
}	t_stack_needs;

void			check_validity(char **argv, int argc);
void			check_numbers(char **numbers);
static char		**get_numbers(char **argv, int argc);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_strlcpy(char *dst, const char *src, int dstsize);
static int		count_words(const char *s, char c);
static void		ending(int *start, int *end, int c, const char *s);
static char		**freesplit(char **res, int i);
static void		fill(int start, int end, const char *s, char *res);
char			**ft_split(const char *s, char c);
int				ft_atoi(const char *str, char **numbers);
int				ft_strcmp(char *s1, char *s2);
void			check_duplicates(char **numbers);
void			free_numbers(char **numbers, int flag);
void			create_stack(char **numbers, t_stack_needs **stack_a);
void			add_node(t_stack_needs **stack, int nbr);
t_stack_needs	*get_last_node(t_stack_needs *stack);
void			swap(t_stack_needs **stack);
int				stack_len(t_stack_needs *stack);
void			sa(t_stack_needs **a);
void			sb(t_stack_needs **b);
void			ss(t_stack_needs **a, t_stack_needs **b);
void			push(t_stack_needs **dest, t_stack_needs **src);
void			push_a(t_stack_needs **a, t_stack_needs **b);
void			push_b(t_stack_needs **a, t_stack_needs **b);
void			rotate_stack(t_stack_needs **stack);
void			rotate_a(t_stack_needs **a);
void			rotate_b(t_stack_needs **b);
void			rotate_a_b(t_stack_needs **a, t_stack_needs **b);
void			reverse_rotate(t_stack_needs **stack);
void			reverse_rotate_a(t_stack_needs **a);
void			reverse_rotate_b(t_stack_needs **b);
void			reverse_rotate_a_b(t_stack_needs **a, t_stack_needs **b);
int				is_sorted(t_stack_needs *stack);
t_stack_needs	*find_highest(t_stack_needs *stack);
void			sort_three(t_stack_needs **a, t_stack_needs **b);
void			push_swap_magic(t_stack_needs **a, t_stack_needs **b);
void			start_nodes(t_stack_needs *a, t_stack_needs *b);
void			set_targets(t_stack_needs *a, t_stack_needs *b);
t_stack_needs	*get_smallest(t_stack_needs *stack);
void			set_push_cost(t_stack_needs *a, t_stack_needs *b);
void			set_positions(t_stack_needs *stack);
void			set_priority(t_stack_needs *b);
void			insert(t_stack_needs **a, t_stack_needs **b);
t_stack_needs	*get_priority(t_stack_needs *stack);
void			rotate_stacks(t_stack_needs **a, t_stack_needs **b,
					t_stack_needs *priority_node);
void			reverse_rotate_stacks(t_stack_needs **a, t_stack_needs **b,
					t_stack_needs *priority_node);
void			complete(t_stack_needs **stack, t_stack_needs *top, char which);
void			freelist(t_stack_needs *a);
#endif
