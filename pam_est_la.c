#include "pam_est_la.h"

int	pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return (PAM_IGNORE);
}

int	pam_sm_close_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return (PAM_IGNORE);
}

int	pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return (PAM_IGNORE);
}

int	pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return (PAM_IGNORE);
}

int	pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  return (PAM_IGNORE);
}
