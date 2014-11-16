rm -rfv pam_est_la_x64*
rm -rfv /lib/security/pam_est_la_x64*
make
cp -fv pam_est_la_x64* /lib/security/
chown root:root /lib/security/pam_est_la_x64*
chmod 755 /lib/security/pam_est_la_x64*