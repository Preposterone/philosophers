#include "gtest/gtest.h"

extern "C" {
	#include "philo.h"
}
/* TODO: maybe refactor to parametarized list ? */

//class

TEST(args_list, args_not_digits) {
	char *args[] = {"123", "000-1", "abc", NULL};
	bool ret = ft_is_all_digits(args);
	ASSERT_EQ(ret, false);
}

TEST(are_args_digits, args_are_digits) {
	char *args[] = {"123", "0001", "1234", NULL};
	bool ret = ft_is_all_digits(args);
	ASSERT_EQ(ret, true);
}

TEST(parse_args, is_parsed_correctly) {
	t_philo_config config_tmp = {0};
	char *args[] = {"123", "123", NULL};
	ft_parse_config(args, &config_tmp);
	int i = -1;
	int x;

	while (args[++i] != NULL)
	{
		x = 0;
		x = std::stoi(args[i], nullptr, 10);
		switch (i) {
			case 1:
				ASSERT_EQ(x, config_tmp.count);
				break;
			case 2:
				ASSERT_EQ(x, config_tmp.tt_die);
				break;
			case 3:
				ASSERT_EQ(x, config_tmp.tt_eat);
				break;
			case 4:
				ASSERT_EQ(x, config_tmp.tt_sleep);
				break;
			case 5:
				ASSERT_EQ(x, config_tmp.eat_times);
				break;
		}
	}
}
