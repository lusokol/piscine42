int		ft_cmp(void *data, void *data_ref)
{
	return (data < data_ref);
}

int main()
{
	struct s_list	elem1;
	struct s_list	elem2;
	struct s_list	elem3;
	struct s_list	elem4;
	struct s_list	*begin;
	void			(*cmp)(void *, void *);
	void			*data_ref;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = 0;

	elem1.data = 5;
	elem2.data = 10;
	elem3.data = 25;
	elem4.data = 35;
	data_ref = 25;

	cmp = &ft_cmp;
	begin = ft_list_find(begin, data_ref, cmp);
	printf("%d\n", begin->data);
}
