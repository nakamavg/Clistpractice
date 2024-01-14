#include <stdio.h>
#include <stdlib.h> //malloc
typedef struct s_dllist
{
	int			content;//
	struct s_dllist	*next; //puntero a la siguiente estructura
	struct s_dllist	*prev;//puntero a la estructura anterior
}	t_dllist;

typedef struct s_stack
{
	t_dllist	*head;//puntero a la primera estructura
	t_dllist	*tail;//puntero a la ultima estructura
	size_t		list_size;//tamaño de la lista
}	t_stack;

//funciones de la lista

t_stack	*ft_stacktnew(void *content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	new->list_size = 0;
	return (new);

}

t_dllist	*ft_dllstnew(int content)
{
	t_dllist	*new;

	new = (t_dllist *)malloc(sizeof(t_dllist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_push(t_stack *stack, t_dllist *new)
{
	if (!stack || !new)
		return ;
	if (stack->head == NULL)
	//si no hay cabeza en la lista significa que esta vacia
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->next = stack->head;
		stack->head->prev = new;
		stack->head = new;
	}
	stack->list_size++;
}

void	ft_stackadd_back(t_stack *stack, t_dllist *new)
{
	if (!stack || !new)
		return ;
	if (stack->tail == NULL)
	//si no hay cola en la lista significa que esta vacia
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->prev = stack->tail;
		stack->tail->next = new;
		stack->tail = new;
	}
	stack->list_size++;
}

int main()
{
	t_stack *stack;
	t_dllist *new;

	int index;

	stack = ft_stacktnew(NULL);
	index = 0;
	while (index < 10)
	{
		new = ft_dllstnew(index);
		ft_push(stack, new);
		index++;
	}
	while (stack->head)
	{
		printf("%d ", stack->head->content);
		stack->head = stack->head->next;
	}
	printf("\n");
	return (0);
}
