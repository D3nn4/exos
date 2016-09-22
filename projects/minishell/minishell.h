#ifndef __HEADER_H__
#define __HEADER_H__


#include <stdbool.h>



#define SIZE_MAX  4096

typedef struct  s_env {
	char **raw_env;
	char **paths;
	char *home;
	char *current_directory;
}				t_env;

typedef struct 	s_function {
	char *name;
	char *args;

}				t_function;




void minishell(char **env);
void freeStructEnv (t_env **struct_env);
void getHome (char *string, t_env *env);
void freeStructFunction (t_function **function);
void echo (char *args);
void cd (char *args, t_env *env);
void displayEnv (t_env *env);
void mySetenv (char *data, t_env *env);
void addNewVar(t_env *env, char *var, char *value);
void modifyVar (t_env *env, char *var, char *value);
void myUnsetenv (char *data, t_env *env);
char *addSeparator (char *string);
char *eraseDots (char *str);
char * previousDir (char *str);
char *isDir (char *args, t_env *env);
char **getPaths (char *string);
char *addPath (char *name, char *path);
bool checkVar (char **list, char *var);
bool testLibFunction (t_function *data, t_env *env);
bool applyFunction (char *buffer, int ret, t_env *env);
bool FindBuiltInFunction (t_function *data, t_env *env);
bool findLibFunction (t_function *data, t_env *env);
t_function *getFunction (char *buffer, int ret);
t_env *getEnv (char **env);




#endif