int main(int ac, char **av)
{
	t_list *test;

	test = ft_list_push_strs(ac, av);
	while (test)
	{
		printf("%s\n", test->data);
		test = test->next;
	}
}
