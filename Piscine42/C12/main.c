int main()
{
	struct s_list	elem1;
	struct s_list	elem2;
	struct s_list	elem3;
	struct s_list	elem4;
	struct s_list	*begin;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = 0;

	elem1.data = 5;
	elem2.data = 10;
	elem3.data = 25;
	elem4.data = 35;

	ft_list_size(begin);
	printf("\n");
	ft_list_push_front(&begin, 42);
	ft_list_size(begin);
}
