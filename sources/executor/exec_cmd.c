
#include "../../includes/minishell.h"

int	exec_cmd(t_tree *tree, t_minishell *data)
{
	int	pid;
	int	ret_code;

	pid = fork();
	execution_signals(pid);
	if (pid == 0)
	{
		fd_list_close_clear(&data->fd_list);
		if (is_builtin(tree))
			ret_code = builtin_process(tree, data);
		else
			ret_code = exec_cmd_fork(tree, data);
		free_tree(&data->tree);
		env_clear_list(&data->envs);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		exit(ret_code);
	}
	return (pid);
}
