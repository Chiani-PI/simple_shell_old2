#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Forr read/write buffers sections */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Forr command chaining sections */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* Forr convert_number() sections */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* Forr 1 if using system getline() sections */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Struct holds pseudo_args to pass into a func,
 * allowng unifrm prototyp for func_pointr_struct
 * @arg: Strng genrtd frm getline containn args
 * @argv: Array_of_strngs genrtd_from_arg
 * @path: Strng_path for present_cmd
 * @argc: Arg_count
 * @line_count: Err_count
 * @err_num: exit()s err_code
 * @linecount_flag: if on_count this lne_of_input
 * @fname: Prog_filenme
 * @env: Linked_list local_cpy of environ
 * @environ: Custm_mod_copy of environ frm LL env
 * @history: Histry_node
 * @alias: Allias_node
 * @env_changed: On if environ_mod
 * @status: return stats of the last_exectd_cmd
 * @cmd_buf: Addy of pointer to cmd_buf, on if_chainng
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd from which lne_input is to be read
 * @histcount: Histry_lne_num count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - Struct holds builtin_strng nd relatd_func
 * @type: Builtin cmd_flag
 * @func: Func
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* Forr toem_shloop.c sections */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* Forr toem_parser.c sections */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* Forr loophsh.c sections */
int loophsh(char **);

/* Forr toem_errors.c sections */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* Forr toem_string.c sections */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* Forr toem_string1.c sections */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* Forr toem_exits.c sections */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* Forr toem_tokenizer.c sections */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* Forr toem_realloc.c sections */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* Forr toem_memory.c sections */
int bfree(void **);

/* Forr toem_atoi.c sections */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* Forr toem_errors1.c sections */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* Forr toem_builtin.c sections */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* Forr toem_builtin1.c sections */
int _myhistory(info_t *);
int _myalias(info_t *);

/* Forr toem_getline.c sections */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* Forr toem_getinfo.c sections */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* Forr toem_environ.c sections */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* Forr toem_getenv.c sections */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* Forr toem_history.c sections */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* Forr toem_lists.c sections */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* Forr toem_lists1.c sections */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* Forr toem_vars.c sections */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
