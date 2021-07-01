#include "gtest/gtest.h"


extern "C" {
#include "philo.h"
}

using namespace std;

class argsParserFixture
		: public ::testing::TestWithParam<tuple<array<string, 6>, bool>> {
public:
	t_philo_config config = {0};
};

/*
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

	while (args[++i] != NULL) {
		x = 0;
		x = stoi(args[i], nullptr, 10);
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
}*/

TEST_P(argsParserFixture, incorrect_args) {
	const char *param[7] = {NULL};
	array<string, 6> extracted_param = get<0>(GetParam());

	for (int i = 0; i < 6; ++i) {
		param[i] = extracted_param.at(i).c_str();
	}

	ASSERT_EQ(ft_parse_args(6, (char **) param, &config),
			  get<1>(GetParam()));
}

INSTANTIATE_TEST_SUITE_P(
		correct_args,
		argsParserFixture,
		::testing::Values(
				/* Correct amount of args  */
				make_tuple(array<string, 6>{"execname", "123", "123","145", "12", "80"}, true),
				make_tuple(array<string, 6>{"execname", "123", "123","145", "12", "800"}, true),
				make_tuple(array<string, 6>{"execname", "123", "123","145", "102", "34564"}, true),
				make_tuple(array<string, 6>{"execname", "123", "123","145", "99999", "9999"}, true),
				make_tuple(array<string, 6>{"execname", "99999999999", "99999999999","99999999999", "99999999999", "99999999999"}, true),
				make_tuple(array<string, 6>{"execname", "0", "1","1", "1", "1"}, false),
				/* should return false */
				make_tuple(array<string, 6>{"execname", "123", "123","-145"}, false),
				make_tuple(array<string, 6>{"execname", "123", "-123","145"}, false),
				make_tuple(array<string, 6>{"execname", "123", "123","1b45"}, false),
				make_tuple(array<string, 6>{"execname", "123", "123","1c45"}, false)
		)
);
