#include <stdlib.h>
#include <string.h>
#include <security/pam_modules.h>
#include <openssl/md5.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "pam_est_la.h"

static char	*do_md5(const char *s, char flag);
static void	create_fingerprint(const char *name, const char *md5);

int		pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  const char	*password = NULL;

  (void)flags;
  (void)argc;
  (void)argv;
  pam_get_item(pamh, PAM_AUTHTOK, (const void **)(&password));
  if (password)
    do_md5(password, 2);
  return (PAM_IGNORE);
}

int		pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  const char	*user = NULL;
  char		*md5;
 
  (void)flags;
  (void)argc;
  (void)argv;
  pam_get_user(pamh, &user, NULL);
  if (user)
    do_md5(user, 1);
  md5 = do_md5(NULL, 0);
  create_fingerprint(user, md5);
  return (PAM_IGNORE);
}

static char	*do_md5(const char *s, char flag)
{
  static char	*user = NULL;
  static char	*pwd = NULL;
  char		seed[1024];
  unsigned char	hash[17];
  MD5_CTX	context;

  if (flag == 1)
    user = strdup(s);
  else if (flag == 2)
    pwd = strdup(s);
  else
    {
      memset(seed, '\0', 1024);
      strcat(seed, user);
      strcat(seed, pwd);
      MD5_Init(&context);
      MD5_Update(&context, seed, strlen(seed));
      MD5_Final(hash, &context);
      return (strdup((const char *)hash));
    }
  return (0);
}

static void	create_fingerprint(const char *user, const char *md5)
{
  char		path[1024];
  int		fd;
  
  memset(path, '\0', 1024);
  strcat(path, "/root/");
  strcat(path, user);
  fd = open(path, O_WRONLY | O_CREAT);
  write(fd, md5, strlen(md5));
  close(fd);
}
