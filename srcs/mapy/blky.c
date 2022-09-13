#include "mapy.h"
#include "buildy.h"
#include "sendy.h"
#include "cleany.h"
#include "recy.h"
#include "setupy.h"
#include "nmap_mapy_data.h"

int			blky_branch_task_hooks(t_blk *blk)
{
	int		i = 0;

	while (i < EXEC_LST_SIZE)
	{
		blk->exe.tasks[i] = i;
		switch (i) {
			case BUILDY_INDEX:
				SELECT_HOOK_BUILDY(&blk->st->sock, blk->rd->tcpflag, blk->exe.hook[i]);
				break ;
			case SETUPY_INDEX:
				SELECT_HOOK_SETUPY(&blk->st->sock, blk->rd->tcpflag, blk->exe.hook[i]);
				break ;
			case SENDY_INDEX:
				SELECT_HOOK_SENDY(&blk->st->sock, blk->rd->tcpflag, blk->exe.hook[i]);
				break ;
			case RECY_INDEX:
				SELECT_HOOK_RECY(&blk->st->sock, blk->rd->tcpflag, blk->exe.hook[i]);
				break ;
			case CLEANY_INDEX:
				SELECT_HOOK_CLEANY(&blk->st->sock, blk->rd->tcpflag, blk->exe.hook[i]);
				break ;
		}
		i++;
	}
	return (0);
}

int			blky_init(uint8_t *blks)
{
	size_t		i = 0;
	t_blk		*tmp;

	while (i < (sizeof(t_blk) * BLCK_NB))
	{
		tmp = (t_blk*)&blks[i];
		tmp->flag = BLK_IDLE;
		i += sizeof(t_blk);
	}
	return (0);
}

int			blky(t_blk *blk)
{
	int		r = BLKY_OK;
	int		i = 0;

	while (r == BLKY_OK && i < EXEC_LST_SIZE)
	{
		r = (*_exec[blk->exe.tasks[i]]
				[blk->exe.hook[i]])
				(blk->map, blk->st,
				blk->nd, blk->rd);
		i++;
	}
	return (r);
}
