CC = gcc
RM = rm -f
SO64 = pam_est_la_x64_0.2.2a.so
LN64 = pam_est_la_x64.so

CFLAGS =  -Wall -Wextra
CFLAGS += -fPIC -dPIC
CFLAGS += -DOPENSSL

LDFLAGS = -shared -rdynamic
LIBFLAGS += -lpcap -lcrypto

SRCS =  open.c
SRCS += close.c
SRCS += unused.c

OBJS = $(SRCS:.c=.o)

build64: $(SO64)

$(SO64): LDFLAGS += -m64
$(SO64): fclean $(OBJS)
	 $(CC) $(OBJS) -o $(SO64) $(LDFLAGS) $(LIBFLAGS)
	 ln -s $(SO64) $(LN64)

all:
	make build64

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(SO64)
	$(RM) $(LN64)

.PHONY: all clean fclean build64