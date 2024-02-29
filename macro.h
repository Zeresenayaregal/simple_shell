#ifndef MACRO_H
#define MACRO_H

#define PRINT(cze) (write(STDOUT_FILENO, cze, ze_siz(cze)))
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)
#define SETOWD(M) (M = ze_rep(ze_goev("OLDPWD")))

#endif