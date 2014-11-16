#include "pam_est_la.h"

int	pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  printf("OPEN SESSION\n");
  return (PAM_IGNORE);
}

int	pam_sm_close_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  printf("CLOSE SESSION\n");
  return (PAM_IGNORE);
}

int	pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  printf("ACCOUNT\n");
  return (PAM_IGNORE);
}

int	pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  printf("AUTH\n");
  return (PAM_IGNORE);
}

int	pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  printf("USER\n");
  return (PAM_IGNORE);
}

int	pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  printf("TOKEN\n");
  return (PAM_IGNORE);
}
