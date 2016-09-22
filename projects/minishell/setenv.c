#include "ft.h"
#include "minishell.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void addNewVar(t_env *env, char *var, char *value)
{
	int size = 0;
	int i;
	int str_len = 0;
	char **new_env = NULL;
	for(i = 0; env->raw_env[i] != NULL; i++)
		size++;
	new_env = malloc(sizeof(*new_env) * (size + 2));// +2 => newvalue + NULL
	if (new_env == NULL){
		printf("error realloc addVarEnv\n");
		return;
	}
	for (i = 0; env->raw_env[i] != NULL; i++) {
		new_env[i] = env->raw_env[i];
	}
	if (value == NULL)
		str_len = strlen(var);
	else
		str_len = strlen(var) + strlen(value);
	new_env[i] = malloc(sizeof(**new_env) * (str_len + 2)); // +2 => = + '\0'
	if (new_env[i] == NULL) {
		printf("error malloc new var addVarEnv\n");
		return;
	}
	new_env[i] = strcpy(new_env[i], var);
	strcat(new_env[i], "=");
	if (value == NULL)
		strcat(new_env[i], "\0");
	else
		strcat(new_env[i], value);
	new_env[i+1] = NULL;
	env->raw_env = new_env;

}

void modifyVar (t_env *env, char *var, char *value)
{
	int size = strlen(var);
	int i = 0;
	char **list = env->raw_env;
	while (strncmp(list[i], var, size) != 0) 
		i++;
	list[i] = malloc(sizeof(*list[i]) * (strlen(value) + size + 2)); // + 2 for = && \0
	list[i] = strcpy(list[i], var);
	strcat(list[i], "=");
	strcat(list[i], value);
	
}

bool checkVar (char **list, char *var)
{	
	int size = strlen(var);
	int i ;
	for (i = 0; list[i] != NULL; i++) {
		if(strncmp(list[i], var, size) == 0)
			return true;
	}
	return false;
}

void mySetenv (char *data, t_env *env)
{
	
	// si pas d'argument afficher env
	if (data == NULL){
		printf("args null setenv\n");
		displayEnv(env);
		return;
	}
	// separer nom variable et valeur
	t_function *var_to_add = NULL;
	var_to_add = getFunction(data, strlen(data)); 
	printf("%s\n", var_to_add->name);
	// verifier si elle existe
	if (checkVar(env->raw_env, var_to_add->name)) 
		// si oui modifier contenue 
		modifyVar(env, var_to_add->name, var_to_add->args);
	else
	// si non la creer et mettre contenu si pas de vasleur, = null
		addNewVar(env, var_to_add->name, var_to_add->args);
	// exporter vers subshells

}