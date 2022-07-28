#include <stdio.h>

int	main(int argc,int argv)
{
	int		num;
	char	*cmd;
	int		local_1c;
	__uid_t	uid;
	__gid_t	gid;

  num = atoi(*(char **)(argv + 4));
  if (num == 0x1a7) {					// 423
    cmd = strdup("/bin/sh");
    local_1c = 0;
    gid = getegid();
    uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);
    execv("/bin/sh", &cmd);
  }
  else {
    fwrite("No !\n",1,5,(FILE *)stderr);
  }
  return 0;
}
