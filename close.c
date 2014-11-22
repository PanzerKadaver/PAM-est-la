#include <stdlib.h>
#include <stdio.h>

#include "pam_est_la.h"

int	pam_sm_close_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  const char	*user = NULL;

  (void)flags;
  (void)argc;
  (void)argv;
  pam_get_item(pamh, PAM_USER, (const void **)&user);
  printf("> User : [%s]\n", user);
  return (PAM_IGNORE);
}
